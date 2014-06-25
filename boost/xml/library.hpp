#ifndef boost_xml_libray_hpp_
#define boost_xml_library_hpp_

#ifdef USE_XERCES
# include <xercesc/util/PlatformUtils.hpp>
#endif

namespace boost
{
namespace xml
{
class library
{
public:
  library()
  {
#ifdef USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    XMLPlatformUtils::Initialize();
#endif
  }
  ~library()
  {
#ifdef USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    XMLPlatformUtils::Terminate();
#endif
  }
};

}
}

#endif
