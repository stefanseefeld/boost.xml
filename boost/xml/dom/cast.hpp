#ifndef boost_xml_dom_cast_hpp_
#define boost_xml_dom_cast_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/cast.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/cast.hpp>
#endif

#endif
