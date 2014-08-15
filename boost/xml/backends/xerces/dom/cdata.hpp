#ifndef boost_xml_backends_xerces_dom_cdata_hpp_
#define boost_xml_backends_xerces_dom_cdata_hpp_

#include <boost/xml/backends/xerces/dom/node.hpp>

namespace boost
{
namespace xml
{
namespace dom
{

template <typename S> class element;

template <typename S>
class cdata : public text<S> 
{
  friend class element<S>;
public:
// private:
  cdata(detail::DOMNode *a) : text<S>(a) {}
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
