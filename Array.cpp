// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include "Base_Array.h"
#include <cstring>
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10


//Default ctor
template <typename T>
Array <T>::Array (void)
	: Base_Array <T> ()
	{}



//length ctor	
template <typename T>
Array <T>::Array (size_t length)
	: Base_Array <T> (length)
	{}



//fill ctor; sets the length of the Array and fills it with 'fill'
template <typename T>
Array <T>::Array (size_t length, T fill)
	: Base_Array <T> (length, fill)
	{}


//copy constructor
template <typename T>
Array <T>::Array (const Array & array)
	: Base_Array <T> (array)
	{}


//Destructor
template <typename T>
Array <T>::~Array (void)
	{}



//Assignment operator; rhs's data_ is copied into this Array's data_
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//Check for self-assignment:
	if (this == &rhs) {
		return *this;
	}
	
	//If this condition it true, a new allocation is needed:
	if (this->max_size_ < rhs.cur_size_) {
		delete this->data_;
		this->data_ = new T[rhs.cur_size_];
	}
	
	this->cur_size_ = rhs.cur_size_;
	
	for (int index = 0; index < this->cur_size_; index++) {
		this->data_[index] = rhs.data_[index];
	}

	return *this;
}



//resize; if the new size is smaller than the current size, the current size is simply set to the new size.
//Otherwise, a new allocation is made, the current data_ is copied into it, and the old data_ is deleted.
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size <= this->cur_size_) {
		this->cur_size_ = new_size;
	}
	else {
		T * new_data_ = new T[new_size];

		for (int index = 0; index < this->cur_size_; index++) {
			new_data_[index] = this->data_[index];
		}
		
		T * temp = this->data_;
		this->data_ = new_data_;
		delete [] temp;

		this->cur_size_ = this->max_size_ = new_size;
		
	}
}


template <typename T>
void Array <T>::shrink (void)
{
	/* If an Array has been resized to a smaller size
	 * using the resize method, this shrink method
	 * reclaims the unused space by copying the
	 * current contents into a new character array,
	 * calling 'delete' on the old allocation, and
	 * setting the pointer to the new array.
	 */
	
	if (this->max_size_ > this->cur_size_) {
		char * new_data_ = new char[this->cur_size_];

		for (int index = 0; index < this->cur_size_; index++) {
			new_data_[index] = this->data_[index];
		}

		delete [] this->data_;
		this->data_ = new_data_;
	}
}



//Method used by Stack and Queue to resize its Array member
template <typename T>
void Array <T>::set_size (size_t new_size) {
	
	this->cur_size_ = new_size;
}
