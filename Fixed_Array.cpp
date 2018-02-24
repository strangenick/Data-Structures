// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Base_Array.h"
#include "Fixed_Array.h"
#include <cstring>

//Calls parent class' size ctor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	: Base_Array<T> (N)
 	{}



//Calls parent class' copy ctor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	: Base_Array<T> (arr)
	{}




//Calls parent class' fill ctor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	: Base_Array<T> (N, fill)
	{}



//Calls parent class' destructor
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{}



//Assignment operator for Fixed_Arrays of the same size; copies all N elements of rhs.
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{	
	//Check for self-assignment:
	if (this == &rhs) {
		return *this;
	}
	
	//Since *this and rhs are the same size, :
	for (int index = 0; index < N; index++) {
		this->set(index, rhs.get(index));
	}

	return *this;
}
