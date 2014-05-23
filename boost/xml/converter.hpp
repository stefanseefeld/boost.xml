#ifndef boost_xml_converter_hpp_
#define boost_xml_converter_hpp_

namespace boost
{
namespace xml
{
// The converter translates a (unicode) string between the
// backend type and the user-visible string type.
template <typename S>
struct converter
{
  // TODO: How can this be decoupled from any backend-specific type ?
  static char const *in(S const &buffer);
  static S out(char const *buffer);
};
}
}


#endif
