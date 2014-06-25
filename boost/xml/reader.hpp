#ifndef boost_xml_reader_hpp_
#define boost_xml_reader_hpp_

#if USE_LIBXML2
# include <boost/xml/backends/libxml2/reader.hpp>
#elif USE_XERCES
# include <boost/xml/backends/xerces/reader.hpp>
#endif

namespace boost
{
namespace xml
{
namespace reader
{
#if USE_LIBXML2
namespace be = libxml2::reader;
#elif USE_XERCES
namespace be = xerces::reader;
#endif

enum token_type
{
  none = be::none,
  element = be::element,
  attribute = be::attribute,
  text = be::text,
  cdata = be::cdata,
  entity_reference = be::entity_reference,
  type_entity = be::type_entity,
  processing_instruction = be::processing_instruction,
  comment = be::comment,
  document = be::document,
  document_type = be::document_type,
  document_fragment = be::document_fragment,
  notation = be::notation,
  whitespace = be::whitespace,
  significant_whitespace = be::significant_whitespace,
  end_element = be::end_element,
  end_entity = be::end_entity,
  xml_declaration = be::xml_declaration
};

template <typename S> class parser;

template <typename S>
class token
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
  token(be::token<S> const &tb) : tb_(tb) {}

  be::token<S> tb_;
};

template <typename S> 
class parser
{
public:
  parser(std::string const &filename) : impl_(filename) {}
  ~parser() {}
  bool next() { return impl_.next();}
  reader::token<S> token() { return reader::token<S>(impl_.token());}
private:
  be::parser<S> impl_;
};
}
}
}

#endif
