#ifndef string_hpp_
#define string_hpp_

#include <boost/xml/dom.hpp>
#ifdef USE_STD_STRING
# include <boost/xml/unicode/std_string.hpp>
typedef std::string S;
#elif USE_QSTRING
# include <boost/xml/unicode/qstring.hpp>
typedef QString S;
#elif USE_GSTRING
# include <boost/xml/unicode/gstring.hpp>
typedef Glib::ustring S;
#else
# error "no string type defined"
#endif

typedef boost::xml::dom::node_ptr<boost::xml::dom::node<S> > node_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::node<S> const> const_node_ptr;
typedef boost::xml::dom::element<S> element;
typedef boost::xml::dom::node_ptr<element> element_ptr;
typedef boost::xml::dom::node_ptr<element const> const_element_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<S> > attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<S> const> const_attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<S> > text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<S> const> const_text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<S> > pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<S> const> const_pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<S> > comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<S> const> const_comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<S> > cdata_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<S> const> const_cdata_ptr;
typedef std::auto_ptr<boost::xml::dom::document<S> > document_ptr;
typedef boost::xml::dom::dtd_ptr<S> dtd_ptr;
typedef boost::xml::dom::node_set<S> node_set;
typedef boost::xml::dom::xpath<S> xpath;

#endif
