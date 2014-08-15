#ifndef boost_xml_dom_io_hpp_
#define boost_xml_dom_io_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/io.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/io.hpp>
#endif

#endif
