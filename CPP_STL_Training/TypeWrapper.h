#pragma once
// Class to check difference between pass by value and pass by reference
#include <iostream>

using namespace std;
namespace stl_training
{
	template <typename T>
	class type_wrapper {
	public:
		// Default constructor
		type_wrapper();

		// Parameterised constructor
		explicit type_wrapper(T s);

		// Copy constructor
		type_wrapper(const type_wrapper<T>& rhs) noexcept;

		// Move constructor
		type_wrapper(type_wrapper<T>&& rhs) noexcept;

		// Assignment operator
		type_wrapper<T>& operator=(const type_wrapper<T>& rhs) noexcept;

		// Move assignment operator
		type_wrapper<T>& operator=(type_wrapper<T>&& rhs) noexcept;		

		bool operator<(const type_wrapper<T>& rhs) const;
		
		operator T();
		
		~type_wrapper();
	private:
		T i_;
	};

	template <typename T>
	type_wrapper<T>::type_wrapper()
	{
		cout << "type_wrapper<T>::type_wrapper()" << endl;
	}

	// Parameterised constructor
	template <typename T>
	type_wrapper<T>::type_wrapper(T s) :
		i_(s)
	{
		cout << "type_wrapper(T s)" << endl;
	}

	// Copy constructor
	template <typename T>
	type_wrapper<T>::type_wrapper(const type_wrapper<T>& rhs) noexcept :
		i_(rhs.i_)
	{
		cout << "type_wrapper::type_wrapper(const type_wrapper<T>& rhs)" << endl;
	}

	// Move constructor
	template <typename T>
	type_wrapper<T>::type_wrapper(type_wrapper<T>&& rhs) noexcept :
		i_(rhs.i_)
	{
		cout << "type_wrapper::type_wrapper(const type_wrapper<T>&& rhs)" << endl;
	}

	// Assignment operator
	template <typename T>
	type_wrapper<T>& type_wrapper<T>::operator=(const type_wrapper<T>& rhs) noexcept
	{
		if (&rhs == this)
		{
			return *this;
		}
		else
		{
			cout << "type_wrapper::operator=(const type_wrapper<T>& rhs)" << endl;
			return *this;
		}
	}

	// Move assignment operator
	template <typename T>
	type_wrapper<T>& type_wrapper<T>::operator=(type_wrapper<T>&& rhs) noexcept
	{
		i_ = rhs.i_;
		cout << "type_wrapper::operator=(type_wrapper<T>&& rhs)" << endl;
		return *this;
	}

	// Less than operator
	template <typename T>
	bool type_wrapper<T>::operator<(const type_wrapper<T>& rhs) const
	{
		return i_ < rhs.i_;
	}

	template <typename T>
	type_wrapper<T>::operator T()
	{
		cout << "type_wrapper::operator T()" << endl;
		return i_;
	}

	template <typename T>
	type_wrapper<T>::~type_wrapper()
	{
		cout << "type_wrapper::~type_wrapper()" << endl;
	}
}