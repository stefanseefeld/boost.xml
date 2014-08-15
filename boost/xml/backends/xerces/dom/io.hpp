#ifndef boost_xml_backends_xerces_dom_io_hpp_
#define boost_xml_backends_xerces_dom_io_hpp_

#include <boost/xml/backends/xerces/dom/document.hpp>
#include <streambuf>
#include <iostream>

namespace boost
{
namespace xml
{
namespace dom
{
template <typename S>
inline void write(document<S> const &document,
                  std::streambuf *sb,
                  std::string const &encoding = std::string())
  throw(std::runtime_error)
{
}

template <typename S>
inline void write_to_file(document<S> const &document,
                          std::string const &filename,
                          std::string const &encoding = std::string())
  throw(std::runtime_error)
{
}

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
