#ifndef boost_xml_backends_xerces_dom_element_hpp_
#define boost_xml_backends_xerces_dom_element_hpp_

#include <boost/xml/backends/xerces/dom/node.hpp>
#include <boost/xml/backends/xerces/dom/attribute.hpp>
#include <boost/xml/backends/xerces/dom/text.hpp>
#include <boost/xml/backends/xerces/dom/comment.hpp>
#include <boost/xml/backends/xerces/dom/pi.hpp>
#include <boost/xml/backends/xerces/dom/cdata.hpp>

namespace boost
{
namespace xml
{
namespace dom
{
namespace detail
{
XERCES_CPP_NAMESPACE_USE
}

template <typename S>
class element : public node<S>
{
  friend class document<S>;
  friend node_ptr<element<S> > detail::ptr_factory<element<S> >(DOMNode *);
public:
  typedef iterator<node<S> > child_iterator;
  typedef iterator<node<S> const> const_child_iterator;

  typedef iterator<dom::attribute<S> > attribute_iterator;
  typedef iterator<dom::attribute<S> const> const_attribute_iterator;

  //. Return the attribute for the given name, if it exists.
  node_ptr<dom::attribute<S> const> attribute(S const &name) const;
  //. Return the attribute for the given name, if it exists.
  node_ptr<dom::attribute<S> > attribute(S const &name);
  //. Set an attribute with the given name and value.
  node_ptr<dom::attribute<S> > set_attribute(S const &name, S const &value);
  //. Remove the attribute with the given name and value, if it exists.
  void unset_attribute(S const &name);

  attribute_iterator begin_attributes() 
  {
    return attribute_iterator(this->impl()->getAttributes());
  }
  const_attribute_iterator begin_attributes() const 
  {
    return const_attribute_iterator(this->impl()->getAttributes());
  }
  attribute_iterator end_attributes() 
  {
    return attribute_iterator();
  }
  const_attribute_iterator end_attributes() const 
  {
    return const_attribute_iterator();
  }

  //. Append a new child element to this element.
  node_ptr<element<S> > append_element(S const &name);
  //. Insert a new child element.
  node_ptr<element<S> > insert_element(child_iterator, S const &name);

  //. Append text to this element.
  node_ptr<text<S> > append_text(S const &content);
  //. Insert text.
  node_ptr<text<S> > insert_text(child_iterator, S const &content);

  //. Append a new comment to this element.
  node_ptr<comment<S> > append_comment(S const &content);
  //. Insert a new comment.
  node_ptr<comment<S> > insert_comment(child_iterator, S const &content);

  //. Append a new processing instruction to this element.
  node_ptr<pi<S> > append_pi(S const &name, S const &content);
  //. Insert a new processing instruction.
  node_ptr<pi<S> > insert_pi(child_iterator, S const &name, S const &content);

  //. Append a new CDATA block to this element.
  node_ptr<cdata<S> > append_cdata(S const &content);
  //. Insert a new CDATA block.
  node_ptr<cdata<S> > insert_cdata(child_iterator, S const &content);

  //. Move the given node from its present location into this element.
  node_ptr<node<S> > insert(child_iterator, node_ptr<node<S> > node);
  void remove(child_iterator);

  // FIXME: the implementation of has_content needs a full traversal
  //        of the subtree. 
  // bool has_content() const;
  S content() const;
  void set_content(S const &content);
  void append_content(S const &content);

  child_iterator begin_children() 
  { return child_iterator(this->impl()->getFirstChild());}
  const_child_iterator begin_children() const 
  { return const_child_iterator(this->impl()->getFirstChild());}
  child_iterator end_children() 
  { return child_iterator();}
  const_child_iterator end_children() const 
  { return const_child_iterator();}

  //. Declare the namespace prefix to be an alias for uri.
  void declare_namespace(S const &prefix, S const &uri);

  //. Lookup the declaration of the namespace prefix, and return its uri.
  S lookup_namespace(S const &prefix) const;

  const_child_iterator find(node_ptr<node<S> const>) const;
  child_iterator find(node_ptr<node<S> const>);

protected:
  element(detail::DOMNode *e) : node<S>(e) {}
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
