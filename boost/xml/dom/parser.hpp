#ifndef boost_xml_dom_parser_hpp_
#define boost_xml_dom_parser_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/parser.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/parser.hpp>
#endif

#endif
