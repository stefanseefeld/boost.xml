#ifndef boost_xml_converter_hpp_
#define boost_xml_converter_hpp_

#if USE_LIBXML2
# include <libxml/xmlstring.h>
#elif USE_XERCES
# include <xercesc/util/XMLString.hpp>
#endif

namespace boost
{
namespace xml
{

#if USE_LIBXML2
// libxml2 uses 'typedef char xmlChar'
typedef xmlChar const *be_const_string_type;
typedef xmlChar *be_string_type;
#elif USE_XERCES
// xerces uses 'typedef short unsigned int XMLCh'
typedef short unsigned int const *be_const_string_type;
typedef short unsigned int *be_string_type;
#endif

// The converter translates a (unicode) string between the
// backend type and the user-visible string type.
template <typename S>
struct converter
{
  static be_const_string_type in(S const &buffer);
  static S out(be_const_string_type buffer);
};
}
}


#endif
