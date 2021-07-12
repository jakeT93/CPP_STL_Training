#include "StreamIteratorAdaptor.h"

#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

void Stream_iterator_adaptor_driver_code()
{
	list<string> my_list;

	copy(istream_iterator<string>(cin),
		istream_iterator<string>(),
		inserter(my_list, my_list.end()));

	// Enter Ctrl+D to terminate input
	
	my_list.sort();

	copy(my_list.begin(),
		my_list.end(),
		ostream_iterator<string>(cout, "\n"));
}

