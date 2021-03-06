Purpose of the library
======================

This is a proposed boost::xml API. It is modular to allow implementations
only to provide subsets of the full set of specs, and let users only choose
the features they need. (E.g. dom vs reader)

The entire library is parametrized for the (unicode) character type. Proper
unicode handling is outside the scope of this library.

This implementation uses libxml2 (http://xmlsoft.org/).


Primary author
==============

Stefan Seefeld (stefan at seefeld dot name)


Structure of the library
========================

boost::dom
----------

This provides (or aims to provide) a DOM-like API to create and manipulate
an in-memory representation of XML documents. Documents can be created either
by parsing xml files, or by building a DOM tree 'manually'.
Instantiated documents can then be traversed, queried (XPATH), and written
out to a file.

boost::reader
-------------

This provides a stream-based interface to XML, where a document is accessed
one token at a time.

Structure of the source tree
============================

boost/xml/dom
boost/xml/dom.hpp : the DOM API

boost/xml/reader
boost/xml/reader.hpp : the Reader API

doc/ : Reference Manual (generated using Synopsis)

tests/ : Sample applets and tests


TODO
====

general
-------

* Think about ways to let users 'plug in' their own unicode type, together
  with conversion traits.

dom
---

* Set up test suite.
* Clarify and cleanup access to 'private' libxml2 references.
* Fix node iterators to skip internal nodes (such as xinclude markers).
* Let xpath::find return variant or some other tool to access multiple
  types. (Right now only node_set is supported.)
* Complete tree manipulation API.
* Add validation modules (dtd, relaxng, schema (?) )

reader
------

* Use boost::variant and static_visitor for typed callbacks ?
* Etc.
