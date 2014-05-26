#ifndef boost_xml_backends_libxml2_reader_parser_hpp_
#define boost_xml_backends_libxml2_reader_parser_hpp_

#include <boost/xml/converter.hpp>
#include <libxml/xmlreader.h>
#include <string>
#include <stdexcept>

namespace boost
{
namespace xml
{
namespace libxml2
{
namespace reader
{
enum token_type
{
  none = XML_READER_TYPE_NONE,
  element = XML_READER_TYPE_ELEMENT,
  attribute = XML_READER_TYPE_ATTRIBUTE,
  text = XML_READER_TYPE_TEXT,
  cdata = XML_READER_TYPE_CDATA,
  entity_reference = XML_READER_TYPE_ENTITY_REFERENCE,
  type_entity = XML_READER_TYPE_ENTITY,
  processing_instruction = XML_READER_TYPE_PROCESSING_INSTRUCTION,
  comment = XML_READER_TYPE_COMMENT,
  document = XML_READER_TYPE_DOCUMENT,
  document_type = XML_READER_TYPE_DOCUMENT_TYPE,
  document_fragment = XML_READER_TYPE_DOCUMENT_FRAGMENT,
  notation = XML_READER_TYPE_NOTATION,
  whitespace = XML_READER_TYPE_WHITESPACE,
  significant_whitespace = XML_READER_TYPE_SIGNIFICANT_WHITESPACE,
  end_element = XML_READER_TYPE_END_ELEMENT,
  end_entity = XML_READER_TYPE_END_ENTITY,
  xml_declaration = XML_READER_TYPE_XML_DECLARATION
};

template <typename S> class parser;

template <typename S>
class token_base
{
  friend class parser<S>;
public:
  size_t depth() const { return xmlTextReaderDepth(reader_);}
  S name() const { return converter<S>::out(xmlTextReaderConstName(reader_));}
  S value() const { return converter<S>::out(xmlTextReaderConstValue(reader_));}
  bool is_empty_element() const { return xmlTextReaderIsEmptyElement(reader_);}
  bool has_value() const { return xmlTextReaderHasValue(reader_);}
  token_type type() const { return (token_type)xmlTextReaderNodeType(reader_);}
protected:
  token_base(xmlTextReader *reader) : reader_(reader) {}

  xmlTextReader *reader_;
};

template <typename S> 
class parser
{
public:
  parser(std::string const &filename)
    : impl_(xmlReaderForFile(filename.c_str(), 0, 0)),
      status_(0)
  {
    if (!impl_) throw std::runtime_error("unable to open file");
  }
  ~parser() { xmlFreeTextReader(impl_);}
  bool next() { status_ = xmlTextReaderRead(impl_); return status_ == 1;}
  token_base<S> get_token()
  {
    token_base<S> token(impl_);
    return token;
  }
private:
  xmlTextReader *impl_;
  int status_;
};
}
}
}
}

#endif
