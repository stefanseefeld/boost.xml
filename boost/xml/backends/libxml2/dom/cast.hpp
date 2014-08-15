#ifndef boost_xml_backends_libxml2_dom_cast_hpp_
#define boost_xml_backends_libxml2_dom_cast_hpp_

#include <boost/xml/backends/libxml2/dom/node.hpp>
#include <stdexcept>

namespace boost
{
namespace xml
{
namespace dom
{
namespace detail
{
//. Helper types used for cast<>()
template <typename N> struct target {};
template <typename S>
struct target<node_ptr<element<S> > > { static node_type const type = ELEMENT;};
template <typename S>
struct target<node_ptr<attribute<S> > > { static node_type const type = ATTRIBUTE;};
template <typename S>
struct target<node_ptr<text<S> > > { static node_type const type = TEXT;};
template <typename S>
struct target<node_ptr<cdata<S> > > { static node_type const type = CDATA;};
template <typename S>
struct target<node_ptr<pi<S> > > { static node_type const type = PI;};
template <typename S>
struct target<node_ptr<comment<S> > > { static node_type const type = COMMENT;};

template <typename P> struct pointee {};
template <typename N>
struct pointee<node_ptr<N> > { typedef N type;};

}

class invalid_cast : public std::invalid_argument
{
public:
  invalid_cast(std::string const &msg) 
    : std::invalid_argument("invalid cast from " + msg) {}
};

template <typename T, typename N> 
inline T cast(node_ptr<N> n)
{
  if (n->impl() && 
      N::types[n->impl()->type] != detail::target<T>::type)
  {
    node_type type = N::types[n->impl()->type];
    throw invalid_cast(N::names[type]);
  }
  return detail::ptr_factory<typename detail::pointee<T>::type>(n->impl());
}


} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
