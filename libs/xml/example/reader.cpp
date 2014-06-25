// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xml/library.hpp>
#include <boost/xml/reader.hpp>
#include <boost/xml/unicode/std_string.hpp>
#include <iostream>

using namespace boost::xml::reader;

int main(int, char **)
{
  try
  {
    boost::xml::library library;
    parser<std::string> parser("article.xml");
    while (parser.next())
    {
      token<std::string> const &current = parser.token();
      std::cout << current.depth() << ' '
		<< current.name() << " (" << current.type() << ')';
      if (current.has_value())
	std::cout << "  \"" << current.value() << '"';
      std::cout << std::endl;
    }
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
