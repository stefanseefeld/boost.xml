#ifndef boost_xml_dom_xinclude_hpp_
#define boost_xml_dom_xinclude_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/xinclude.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/xinclude.hpp>
#endif

#endif
