#ifndef boost_xml_backends_xerces_dom_parser_hpp_
#define boost_xml_backends_xerces_dom_parser_hpp_

#include <boost/xml/backends/xerces/dom/document.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>
#include <iostream>

namespace boost
{
namespace xml
{
namespace dom
{

//. A catch-all error type for not-yet classified errors.
class internal_error : public std::runtime_error
{
public:
  internal_error(std::string const &msg) : std::runtime_error(msg) {}
};

//. An error indicating the input not containing well-formed XML.
class parse_error : public std::invalid_argument
{
public:
  parse_error(std::string const &msg) : std::invalid_argument(msg) {}
};

class validation_error : public std::runtime_error
{
public:
  validation_error(std::string const &msg) : std::runtime_error(msg) {}
};

namespace detail
{
XERCES_CPP_NAMESPACE_USE
}

//. A parser encapsulates parse-related parameters, such as non-fatal
//. errors encountered during the parse process. Other parameters might
//. be added, such as for catalog handling (See XML Catalog), or some
//. other form of caching, if possible.
class parser
{
public:
  parser() {}
  ~parser() {}
  template <typename S>
  std::auto_ptr<document<S> > parse_file(std::string const &filename,
					 bool validate)
  {
    parser_.parse(filename.c_str());
    return detail::factory<S>(parser_.adoptDocument());
  }
private:
  detail::XercesDOMParser parser_;
};

//. Parse the given file and create a document containing the new infoset.
//. For a richer interface to the parser, use the parser class directly.
template <typename S>
std::auto_ptr<document<S> > parse_file(std::string const &filename,
				       bool validate)
{
  parser p;
  return p.parse_file<S>(filename, validate);}

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
