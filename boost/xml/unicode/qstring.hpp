#ifndef boost_xml_unicode_qstring_hpp_
#define boost_xml_unicode_qstring_hpp_

#include <boost/xml/converter.hpp>
#include <QtCore/qstring.h>
#include <QtCore/qbytearray.h>
#include <ostream>

namespace boost
{
namespace xml
{
template <>
struct converter<QString>
{
  static xmlChar const *in(QString const &buffer)
  {
    QByteArray array=buffer.toLocal8Bit();
    return reinterpret_cast<xmlChar const *>(array.data());
  }
  static QString out(xmlChar const *buffer)
  {
    return QString::fromLocal8Bit(reinterpret_cast<char const*>(buffer));
  }
};

}
}

// Just a temporary helper to get examples working
std::ostream &operator<<(std::ostream &os, QString const &str)
{
  return os << str.toLocal8Bit().constData();
}

#endif
