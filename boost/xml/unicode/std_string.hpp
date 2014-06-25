#ifndef boost_xml_unicode_std_string_hpp_
#define boost_xml_unicode_std_string_hpp_

#include <boost/xml/converter.hpp>
#include <string>

namespace boost
{
namespace xml
{
template <>
struct converter<std::string>
{
#if USE_LIBXML2
  typedef xmlChar char_type;
#elif USE_XERCES
  typedef XMLCh char_type;
#endif

  static char_type const *in(std::string const &buffer)
  {
#if USE_LIBXML2
    return (xmlChar const *)buffer.c_str();
#elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    return XMLString::transcode(buffer.c_str());
#endif
  }
  static std::string out(char_type const *buffer)
  {
#if USE_LIBXML2
    return buffer ? std::string((char *)buffer) : std::string();
#elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    char *txt = XMLString::transcode(buffer);
    std::string retn = txt ? txt : "";
    delete txt;
    return retn;
#endif
  }
};

}
}


#endif
