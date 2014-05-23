// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xml/dom.hpp>
#include "string.hpp"
#include <iostream>

namespace dom = boost::xml::dom;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: example <xml-file>" << std::endl;
    return -1;
  }
  try
  {
    // create a document from a file
    document_ptr document = dom::parse_file<S>(argv[1], true);
    const_element_ptr root = document->root();
    std::vector<S> children = dom::valid_elements(root, root->begin_children());
    std::cout << "root may have these children:" << std::endl;
    for (std::vector<S>::iterator i = children.begin();
	 i != children.end();
	 ++i)
      std::cout << ' ' << *i << std::endl;
  }
  catch (std::exception const &e)
  {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}
