#pragma once
#include <iostream>

/**
 * example_specialization templates can be partially specialized, as shown by
 * this template example_specialization that takes two type parameters.
 */
template <typename T, typename U>
struct example_specialization {
	example_specialization() { std::cout << "example_specialization <T, U>\n"; }
};

/**
 * The following are partial specializations of the template
 * example_specialization.
 */
template <typename T>   	//specialize so that both are same datatype
struct example_specialization <T, T> {
	example_specialization() { std::cout << "example_specialization<T, T>\n"; }
};

template <typename T>   	//specialize so that second datatype is int
struct example_specialization <T, int> {
	example_specialization() { std::cout << "example_specialization<T, int>\n"; }
};

template <typename T, typename U>   // both are now pointers
struct example_specialization <T*, U*> {
	example_specialization() { std::cout << "example_specialization<T*, U*>\n"; }
};


template <>
struct example_specialization <int, int> {
  example_specialization () { std::cout << "example_specialization<int, int>\n"; }
}; 

// Driver function
int driver_function() {
	example_specialization<int, double> a;     // prints "example_specialization<T, U>"
	example_specialization<double, double> b;  // prints "example_specialization<T, T>"
	example_specialization<double, int> c;     // prints "example_specialization<T, int>"
	example_specialization<int*, double*> d; // prints "example_specialization<T*, U*>"

	example_specialization <int, int> e;        // prints??

	return 0;
}
