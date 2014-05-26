#ifndef boost_xml_reader_parser_hpp_
#define boost_xml_reader_parser_hpp_

#include <boost/xml/backends/libxml2/reader/parser.hpp>

namespace boost
{
namespace xml
{
namespace reader
{
enum token_type
{
  none = libxml2::reader::none,
  element = libxml2::reader::element,
  attribute = libxml2::reader::attribute,
  text = libxml2::reader::text,
  cdata = libxml2::reader::cdata,
  entity_reference = libxml2::reader::entity_reference,
  type_entity = libxml2::reader::type_entity,
  processing_instruction = libxml2::reader::processing_instruction,
  comment = libxml2::reader::comment,
  document = libxml2::reader::document,
  document_type = libxml2::reader::document_type,
  document_fragment = libxml2::reader::document_fragment,
  notation = libxml2::reader::notation,
  whitespace = libxml2::reader::whitespace,
  significant_whitespace = libxml2::reader::significant_whitespace,
  end_element = libxml2::reader::end_element,
  end_entity = libxml2::reader::end_entity,
  xml_declaration = libxml2::reader::xml_declaration
};

template <typename S> class parser;

template <typename S>
class token_base
{
  friend class parser<S>;
public:
  size_t depth() const { return tb_.depth();}
  S name() const { return tb_.name();}
  S value() const { return tb_.value();}
  bool is_empty_element() const { return tb_.is_empty_element();}
  bool has_value() const { return tb_.has_value();}
  token_type type() const { return (token_type)tb_.type();}
protected:
  token_base(libxml2::reader::token_base<S> const &tb) : tb_(tb) {}

  libxml2::reader::token_base<S> tb_;
};

template <typename S> 
class parser
{
public:
  parser(std::string const &filename) : impl_(filename) {}
  ~parser() {}
  bool next() { return impl_.next();}
  token_base<S> get_token() { return token_base<S>(impl_.get_token());}
private:
  libxml2::reader::parser<S> impl_;
};
}
}
}


#endif
