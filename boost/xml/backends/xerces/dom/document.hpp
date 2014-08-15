#ifndef boost_xml_backends_xerces_dom_document_hpp_
#define boost_xml_backends_xerces_dom_document_hpp_

#include <boost/xml/backends/xerces/dom/element.hpp>
#include <boost/xml/backends/xerces/dom/dtd.hpp>
#include <boost/xml/backends/xerces/dom/io.hpp>
#include <xercesc/dom/DOM.hpp>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

namespace boost
{
namespace xml
{
namespace dom
{
namespace detail
{
XERCES_CPP_NAMESPACE_USE
}


template <typename S> void process_xinclude(document<S> &);

template <typename S>
class document : public detail::wrapper<detail::DOMDocument*>
{
  friend std::auto_ptr<document<S> > detail::factory<S>(detail::DOMDocument *);
  friend void process_xinclude<>(document<S> &);
public:
  document(std::string const &version = "1.0")
    : detail::wrapper<detail::DOMDocument*>(0) {}
  ~document() { this->impl()->release(); }
  //  std::string encoding() const;
  dtd_ptr<S> internal_subset() const { return dtd<S>(doctype_);}
  dtd_ptr<S> create_internal_subset(std::string const &name,
				    std::string const &external_id,
				    std::string const &system_id)
  {
    doctype_ = dom_impl_->createDocumentType(detail::XMLString::transcode(name.c_str()),
					     detail::XMLString::transcode(external_id.c_str()),
					     detail::XMLString::transcode(system_id.c_str()));
    return internal_subset();
  }

  node_ptr<element<S> const> root() const
  {
    return detail::ptr_factory<element<S> const>(this->impl()->getDocumentElement());
  }
  node_ptr<element<S> > root()
  {
    return detail::ptr_factory<element<S> >(this->impl()->getDocumentElement());
  }
  node_ptr<element<S> > create_root(std::string const &name,
				    std::string const &ns = std::string(),
				    std::string const &ns_prefix = std::string())
  {
    // FIXME: Xerces doesn't allow explicit root creation.
    //        Rather, this is part of the document construction.
    // TODO: Revise API appropriately.
    this->impl() = dom_impl_->createDocument(0, detail::XMLString::transcode(name.c_str()),
					     doctype_, detail::XMLPlatformUtils::fgMemoryManager);
    return root();
  }
private:
  document(detail::DOMDocument *doc) : detail::wrapper<detail::DOMDocument*>(doc) {}
  
  detail::DOMImplementation *dom_impl_;
  detail::DOMDocumentType *doctype_;
};

// template <typename S>
// inline std::string document<S>::encoding() const
// {
//   std::string e;
//   if(this->impl()->encoding) e = static_cast<char *>(this->impl()->encoding);
//   return e;
// }

// template <typename S>
// inline node_ptr<element<S> > 
// document<S>::create_root(std::string const &name,
// 			 std::string const &ns_href,
// 			 std::string const &ns_prefix)
// {
//   xmlNode *node = xmlNewDocNode(this->impl(), 0, (xmlChar *)name.c_str(), 0);
//   if(!ns_prefix.empty())
//     xmlNewNs(node,
// 	     (xmlChar *)(ns_href.empty() ? 0 : ns_href.c_str()),
// 	     (xmlChar *) ns_prefix.c_str());

//   xmlDocSetRootElement(this->impl(), node);

//   return root();
// }

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
