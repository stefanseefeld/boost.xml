#include <boost/xml/library.hpp>
#include <boost/xml/dom/document.hpp>
#include <boost/xml/dom/parser.hpp>
#if !defined(USE_XERCES)
#include <boost/xml/dom/xpath.hpp>
#include <boost/xml/dom/xinclude.hpp>
#include <boost/xml/dom/validate_dtd.hpp>
#endif
#include <boost/xml/dom/cast.hpp>
