#ifndef boost_xml_dom_validate_dtd_hpp_
#define boost_xml_dom_validate_dtd_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/validate_dtd.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/validate_dtd.hpp>
#endif

#endif
