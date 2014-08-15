#ifndef boost_xml_dom_node_hpp_
#define boost_xml_dom_node_hpp_

#include <boost/xml/dom/nodefwd.hpp>
#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/node.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/node.hpp>
#endif

#endif
