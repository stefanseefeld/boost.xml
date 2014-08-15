#ifndef boost_xml_backends_xerces_dom_attribute_hpp_
#define boost_xml_backends_xerces_dom_attribute_hpp_

#include <boost/xml/backends/xerces/dom/node.hpp>

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

template <typename S> class element;

template <typename S>
class attribute : public node<S>
{
  friend node_ptr<attribute<S> > detail::ptr_factory<attribute<S> >(detail::DOMNode *);
  friend class element<S>;
public:
  S name() const { return converter<S>::out(this->impl()->getNodeName());}
  S value() const { return converter<S>::out(this->impl()->getNodeValue());}
  void set_value(S const &value) { this->impl()->setNodeValue(converter<S>::in(value));}

private:
  attribute(detail::DOMNode *a) : node<S>(a) {}
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
