#ifndef boost_xml_backends_xerces_dom_dtd_hpp_
#define boost_xml_backends_xerces_dom_dtd_hpp_

#include <xercesc/dom/DOM.hpp>
#include <string>

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

template <typename S> class document;
template <typename S> class dtd_ptr;

template <typename S>
class dtd
{
  friend class document<S>;
  friend class dtd_ptr<S>;
public:
  std::string name() const { return detail::XMLString::transcode(impl_->getName());}
  std::string external_id() const { return detail::XMLString::transcode(impl_->getPublicId());}
  std::string system_id() const { return detail::XMLString::transcode(impl_->getSystemId());}
  
private:
  dtd(detail::DOMDocumentType *dtd) : impl_(dtd) {}
  ~dtd() {}

  detail::DOMDocumentType *impl_;
};

template <typename S>
class dtd_ptr
{
public:
  dtd_ptr() : dtd_(0) {}
  dtd_ptr(dtd<S> const &d) : dtd_(d) {}
  dtd<S> &operator*() { return this->dtd_;}
  dtd<S> *operator->() { return &this->dtd_;}
  dtd<S> *get() { return &this->dtd_;}
  operator bool() const { return this->dtd_.impl_;}

private:
  dtd<S> dtd_;
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
