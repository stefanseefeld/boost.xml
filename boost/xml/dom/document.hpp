#ifndef boost_xml_dom_document_hpp_
#define boost_xml_dom_document_hpp_

#if USE_LIBXML2
#include <boost/xml/backends/libxml2/dom/document.hpp>
#elif USE_XERCES
#include <boost/xml/backends/xerces/dom/document.hpp>
#endif

#endif
