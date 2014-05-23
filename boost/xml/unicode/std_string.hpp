#ifndef boost_xml_unicode_std_string_hpp_
#define boost_xml_unicode_std_string_hpp_

#include <boost/xml/converter.hpp>
#include <libxml/xmlstring.h>
#include <string>

namespace boost
{
namespace xml
{
template <>
struct converter<std::string>
{
  static xmlChar const *in(std::string const &buffer)
  {
    return (xmlChar const *)buffer.c_str();
  }
  static std::string out(xmlChar const *buffer)
  {
    return buffer ? std::string((char *)buffer) : std::string();
  }
};

}
}


#endif
