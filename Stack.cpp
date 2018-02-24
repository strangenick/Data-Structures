// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"

//Default ctor
template <typename T>
Stack <T>::Stack (void)
	: data_ (new Array<T>)
	{}



//Copy ctor
template <typename T>
Stack <T>::Stack (const Stack & stack)
	: data_ (new Array <T> (stack.data_->size() ))
	
{
	//Dynamically allocate new Array and copy the parameter stack's data into it.
	//This way, this Stack's data and parameter stack's data don't point to the same memory location. 
	
	for (int index = 0; index < data_->size(); index++) {
		this->data_->set(index, stack.data_->get(index));
	}
}



//destructor
template <typename T>
Stack <T>::~Stack (void)
{
	delete data_;
}



//Add element to the top of the Stack:
template <typename T>
void Stack <T>::push (T element)
{
	//If the data_ Array has used all available space, a new allocation is needed:
	if (data_->size() == data_->max_size()) {
		
		data_->resize(data_->size() + 1);
	}
	//Otherwise, if the current size of the Array and the Stack size are equal,
	//the Array's current size needs to be incremented to prevent check in set method from failing
	
	else {

		data_->set_size(data_->size() + 1);
	}
	
	//element is then set to its proper location at the end of the Array
	data_->set(data_->size() - 1, element);

}



//Remove element from the top of the Stack:
template <typename T>
void Stack <T>::pop (void)
{
	if (is_empty()) {
		throw empty_exception("The stack is empty.");
	}
	else {
		//Decrement the size of the data_ Array and Stack, effectively cutting out the top element.
		//If push is then called, the new element will overwrite the previous top that was popped.
		data_->resize(data_->size() - 1);

	}
}



//Assignment operator
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//Check for self-assignment:
	if (this = &rhs) {
		return *this;
	}
	
	//Make new allocation if needed:
	if (rhs.data_->size() > data_->max_size()) {
		delete data_;
		data_ = new Array <T> (rhs.data_->size());
	}
	else {
		this->data_->set_size(rhs.data_->size());
	}
	
	//Copy rhs's data_ into this Stack's data_:
	for (int index = 0; index < data_->size(); index++) {
		data_->set(index, rhs.data_->get(index));
	}

	return *this;

}



//Clears the Stack by setting the data_ Array and Stack to size 0.
//The previous elements are then inaccessible, and new pushes will overwrite them.
template <typename T>
void Stack <T>::clear (void)
{
	data_->resize(0);
}
