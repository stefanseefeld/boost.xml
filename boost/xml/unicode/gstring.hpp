#ifndef boost_xml_unicode_gstring_hpp_
#define boost_xml_unicode_gstring_hpp_

#include <boost/xml/converter.hpp>
#include <glibmm/ustring.h>

namespace boost
{
namespace xml
{
template <>
struct converter<Glib::ustring>
{
  static xmlChar const *in(Glib::ustring const &buffer)
  {
    return (xmlChar const *)buffer.collate_key().c_str();
  }
  static Glib::ustring out(xmlChar const *buffer)
  {
    return buffer ? Glib::ustring((char const *)buffer) : Glib::ustring("");
  }
};

}
}


#endif
