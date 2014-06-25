#ifndef boost_xml_backends_xerces_reader_hpp_
#define boost_xml_backends_xerces_reader_hpp_

#include <boost/xml/converter.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <stdexcept>
#include <iostream>

namespace boost
{
namespace xml
{
namespace xerces
{
namespace reader
{
enum token_type
{
  none,
  element,
  attribute,
  text,
  cdata,
  entity_reference,
  type_entity,
  processing_instruction,
  comment,
  document,
  document_type,
  document_fragment,
  notation,
  whitespace,
  significant_whitespace,
  end_element,
  end_entity,
  xml_declaration,
};

XERCES_CPP_NAMESPACE_USE

template <typename S>
class handler : public HandlerBase
{
public :
  handler() : type_(none), depth_(0) {}
  ~handler() {}

  int depth() const { return depth_;}
  token_type type() const { return type_;}
  XMLCh const *name() const { return name_;}
  XMLCh const *value() const { return value_;}

  void resetDocType()
  {
    type_ = document_type;
  }
  void notationDecl(XMLCh const *const name, XMLCh const *const publicId, XMLCh const *const systemId)
  {
    type_ = document_type;
    name_ = name;
  }
  void startElement(XMLCh const *const name, AttributeList &attributes)
  {
    type_ = element;
    ++depth_;
    name_ = name;
  }
  void endElement(XMLCh const *const name) { --depth_;}
  void characters(XMLCh const *const chars, XMLSize_t length)
  {
    type_ = text;
    name_ = converter<S>::in("#text");
    value_ = chars;
    length_ = length;
  }
  void ignorableWhitespace(XMLCh const *const chars, XMLSize_t length)
  {
    type_ = whitespace;
    value_ = chars;
    length_ = length;
  }
  void processingInstruction(XMLCh const *target, XMLCh const *data)
  {
    type_ = processing_instruction;
    name_ = target;
    value_ = data;
  }
  void resetDocument()
  {
  }


#if 0
  void warning(SAXParseException const &e)
  {
    std::cerr << "\nWarning at file " << converter<S>::out(e.getSystemId())
	      << ", line " << e.getLineNumber()
	      << ", char " << e.getColumnNumber()
	      << "\n  Message: " << converter<S>::out(e.getMessage()) << std::endl;
  }
  void error(SAXParseException const &e)
  {
    std::cerr << "\nError at file " << converter<S>::out(e.getSystemId())
	      << ", line " << e.getLineNumber()
	      << ", char " << e.getColumnNumber()
	      << "\n  Message: " << converter<S>::out(e.getMessage()) << std::endl;
  }
  void fatalError(SAXParseException const &e)
  {
    std::cerr << "\nFatal Error at file " << converter<S>::out(e.getSystemId())
	      << ", line " << e.getLineNumber()
	      << ", char " << e.getColumnNumber()
	      << "\n  Message: " << converter<S>::out(e.getMessage()) << std::endl;
  }
#endif

private:
  token_type type_;
  int depth_;
  XMLCh const *name_;
  XMLCh const *value_;
  XMLSize_t length_;
};

template <typename S> class parser;

template <typename S>
class token
{
  friend class parser<S>;
public:
  size_t depth() const { return handler_.depth();}
  S name() const { return converter<S>::out(handler_.name());}
  S value() const { return converter<S>::out(handler_.value());}
  bool is_empty_element() const { return handler_.is_empty_element();}
  bool has_value() const { return handler_.value() != 0;}
  token_type type() const { return handler_.type();}
protected:
  token(handler<S> &h) : handler_(h) {}

  handler<S> &handler_;
};

template <typename S> 
class parser
{
public:
  parser(std::string const &filename)
    : first_(true)
  {
    parser_.setDTDHandler(&handler_);
    parser_.setDocumentHandler(&handler_);
    if (!parser_.parseFirst(filename.c_str(), token_))
      throw std::runtime_error("unable to open file");
  }
  ~parser() {}
  bool next()
  {
    if (first_)
    {
      first_ = false;
      return true;
    }
    else
      return parser_.parseNext(token_);
  }
  reader::token<S> token()
  {
    reader::token<S> t(handler_);
    return t;
  }
private:
  handler<S> handler_;
  SAXParser parser_;
  XMLPScanToken token_;
  bool first_;
};
}
}
}
}

#endif
