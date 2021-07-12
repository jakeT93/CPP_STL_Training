// CPP_STL_Training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TypeWrapper.h"
#include "StreamIteratorAdaptor.h"

using namespace stl_training;
int main()
{
    type_wrapper<int> p1(10);
    type_wrapper<int> p2(10);
    std::cout << "Hello World!\n";

    Stream_iterator_adaptor_driver_code();
}