// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <cstring>
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10

//Default ctor
template <typename T>
Base_Array <T>::Base_Array (void)
	: data_ (new T[DEFAULT_SIZE]),
	  cur_size_ (0),
	  max_size_ (DEFAULT_SIZE)
	{}

//length ctor	
template <typename T>
Base_Array <T>::Base_Array (size_t length)
	: data_ (new T[length]),
	  cur_size_ (length),
	  max_size_ (length)
	{}

	
//fill ctor; sets the length of the Array and fills it with 'fill'
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill)
	: data_ (new T[length]),
	  cur_size_ (length),
	  max_size_ (length)
{
	for (int index = 0; index < length; index++) {
		data_[index] = fill;
	}
}


//copy constructor
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array)
	: data_ (nullptr),
	  cur_size_ (array.cur_size_),
	  max_size_ (array.cur_size_)
{
	data_ = new T[cur_size_];

	for (int index = 0; index < cur_size_; index++) {
		data_[index] = array.data_[index];
	}
}

//Destructor
template <typename T>
Base_Array <T>::~Base_Array (void)
{
	delete [] data_;
}



// [] operator
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
	if (index >= cur_size_) {
		throw std::out_of_range("That index does not exist for this array!");
	}
	else {
		return data_[index];
	}
}



//const version of [] operator
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	if (index >= cur_size_) {
		throw std::out_of_range("That index does not exist for this array!");
	}
	else {
		return data_[index];
	}
}



//Gets the value of the Array at the specified index
template <typename T>
T Base_Array <T>::get (size_t index) const
{
	if (index >= cur_size_) {
		throw std::out_of_range("That index does not exist for this array!");
	}
	else {
		return data_[index];
	}
}



//Sets the value of index 'index' to 'value'
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
	if (index >= cur_size_) {
		throw std::out_of_range("That index does not exist for this array!");
	}
	else {
		data_[index] = value;
	}
}



//Calls the other version of 'find' that takes a starting index parameter
template  <typename T>
int Base_Array <T>::find (T value) const
{
	return this->find(value, 0);
}



//Returns the index at which 'value' first occurs, with the search beginning at the specified 'start' index
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
	int found_index_ = -1;

	if (start >= cur_size_) {
		throw std::out_of_range("That index does not exist for this array!");
	}
	else {
		for (int index = 0; index < cur_size_; index++) {
			if (data_[index] == val) {
				found_index_ = index;
				index = cur_size_;
			}
		}
	}

	return found_index_;
}

//Returns true if this Array and rhs have the same data_ values. If their current sizes are not equal,
//they cannot possibly have all the same values, and false is immediately returned. Otherwise, each index
//is checked for equality.
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
	if (this == &rhs) {
		return true;
	}

	bool is_equal_ = true;

	if (rhs.cur_size_ != this->cur_size_) {
		is_equal_ = false;
	}
	else {
		for (int index = 0; index < cur_size_; index++) {
			if (rhs.data_[index] != this->data_[index]) {
				is_equal_ = false;
				index = cur_size_;
			}
		}
	}

	return is_equal_;
}



//Returns the opposite of the above == method
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
	return !(this->operator == (rhs));
}



//Loop through entire Array, setting each index to 'value'
template <typename T>
void Base_Array <T>::fill (T value)
{
	for (int index = 0; index < cur_size_; index++) {
		data_[index] = value;
	}
}


template <typename T>
void Base_Array <T>::reverse (void)
{
	/* The Array is reversed by swapping the 0th element
	 * with the last element, the 1st element with the 
	 * second to last element, and so on until the middle
	 * of the array is reached.
	 */
	
	for (int index = 0; index < cur_size_/2; index++) {
		T temp = data_[index];
		data_[index] = data_[cur_size_ - index - 1];
		data_[cur_size_ - index - 1] = temp;

	} 
}


template <typename T>
Base_Array <T> Base_Array <T>::slice (size_t begin) const
{
	/*Calls overloaded version below
	 */ 
	return this->slice(begin, cur_size_-1);

}

template <typename T>
Base_Array <T> Base_Array <T>::slice (size_t begin, size_t end) const
{
	/* This method returns the portion of this Array
	 * from 'begin' to 'end' by creating a new Array 
	 * of the corresponding size and filling it with
	 * the corresponding elements of this Array.
	 */
	
	Base_Array <T> small_array_(end - begin);
	
	for (int index = 0; index < small_array_.cur_size_; index++) {
		small_array_.data_[index] = this->data_[index + begin];
	}
	
	return small_array_; 
}