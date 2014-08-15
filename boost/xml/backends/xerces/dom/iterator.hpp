#ifndef boost_xml_backends_xerces_dom_iterator_hpp_
#define boost_xml_backends_xerces_dom_iterator_hpp_

#include <xercesc/dom/DOM.hpp>
#include <memory>

namespace boost
{
namespace xml
{
namespace dom
{
namespace detail
{
XERCES_CPP_NAMESPACE_USE

template <typename T> class wrapper;
template <typename T> T impl_cast(wrapper<T> *);
template <typename T> T impl_cast(wrapper<T> const *);

//. 
class accessor
{
protected:
  template <typename T>
  static T &impl(wrapper<T> &w) { return w.impl_;}
  template <typename T>
  static T impl(wrapper<T> const &w) { return w.impl_;}
};

//. wrapper helper class to encapsulate access to private
//. data among wrappers. This defines mutual access to the backend
//. data in an extensible way.
template <typename T>
class wrapper : public accessor
{
  friend class accessor;
  template <typename T1> friend T1 impl_cast(wrapper<T1> *);
  template <typename T1> friend T1 impl_cast(wrapper<T1> const *);
public:
  wrapper(T t) : impl_(t) {}

protected:
  using accessor::impl;
  T &impl() { return this->impl_;}
  T const impl() const { return this->impl_;}
  T release() 
  {
    T tmp = impl_; 
    impl_ = 0; 
    return tmp;
  }
private:
  T impl_;
};

template <typename T>
T impl_cast(wrapper<T> *w) { return w->impl();}
template <typename T>
T impl_cast(wrapper<T> const *w) { return w->impl();}

template <typename N>
node_ptr<N> ptr_factory(DOMNode *n) { return N(n);}

template <typename S>
std::auto_ptr<document<S> > factory(DOMDocument *d)
{
  return std::auto_ptr<document<S> >(new document<S>(d));
}

} // namespace boost::xml::dom::detail

template <typename N>
class iterator : public detail::wrapper<detail::DOMNode*>
{
public:
  typedef iterator<N> self;
  typedef node_ptr<N> value_type;
  typedef value_type &reference;
  typedef value_type *pointer;

  iterator(detail::DOMNode *current = 0) : detail::wrapper<detail::DOMNode*>(current) {}
  bool operator == (self i) { return impl() == impl(i);}
  bool operator != (self i) { return !operator==(i);}
  value_type operator *() { return detail::ptr_factory<N>(impl());}
  pointer operator ->() { return &(operator *());}
  self operator ++(int) { increment(); return *this;}
  self operator ++() { self tmp = *this; increment(); return tmp;}
  self operator --(int) { decrement(); return *this;}
  self operator --() { self tmp = *this; decrement(); return tmp;}

private:
  void increment() { impl() = impl()->getNextSibling();}
  void decrement() { impl() = impl()->getPreviousSibling();}
};

// specialization for attribute iteration
template <typename S>
class iterator<attribute<S> >
{
  typedef attribute<S> N;
public:
  typedef iterator<N> self;
  typedef node_ptr<N> value_type;
  typedef value_type &reference;
  typedef value_type *pointer;

  iterator(detail::DOMNamedNodeMap *map)
    : map_(map), idx_(0)
  {
    if (map_->getLength() == 0) map_ = 0;
  }
  iterator() // the end iterator
    : map_(0), idx_(0) {}
  bool operator == (self i)
  { return map_ == i.map_ && idx_ == i.idx_;}
  bool operator != (self i) { return !operator==(i);}
  value_type operator *()
  {
    return detail::ptr_factory<N>(map_->item(idx_));
  }
  pointer operator ->() { return &(operator *());}
  self operator ++(int) { increment(); return *this;}
  self operator ++() { self tmp = *this; increment(); return tmp;}

private:
  void increment()
  {
    if (map_)
    {
      if (++idx_ == map_->getLength())
      {
	// invalidate
	map_ = 0;
	idx_ = 0;
      }
    }
  }

  detail::DOMNamedNodeMap *map_;
  XMLSize_t idx_;
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
