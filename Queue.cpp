// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//
//
#include "Queue.h"


//Default ctor
template <typename T>
Queue <T>::Queue (void)
	: data_ (new Array<T>)
	 // size_ (0)
	{}



//Copy ctor
template <typename T>
Queue <T>::Queue (const Queue & q)
	: data_ (new Array <T> (q.data_->size()))
	  //size_(q.size_)
{
	//data_ = ;
	
	for (int index = 0; index < data_->size(); index++) {
		data_->set(index, q.data_->get(index));
	}
}



//Destructor
template <typename T>
Queue <T>::~Queue (void)
{
	delete data_;
}



//Assignment operator
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//Check for self-assignment:
	if (this = &rhs) {
		return *this;
	}
	
	//Make new allocation if needed:
	if (rhs.data_->size() > this->data_->max_size()) {
		delete data_;
		data_ = new Array <T> (rhs.data_->size());
	}
	else {
		this->data_->set_size(rhs.data_->size());
	}
	//Copy all elements of rhs into this Queue:
	
	for (int index = 0; index < data_->size(); index++) {
		data_->set(index, rhs.data_->get(index));
	}

	return *this;

}



//Add element to the next spot in the queue:
template <typename T>
void Queue <T>::enqueue (T element) 
{
	//Resize the data_ Array if there is no room for the new element
	if (data_->size() == data_->max_size()) {
		data_->resize(data_->size() + 1);
	}
	//Prevent the check in the Array's set method from failing:
	else {
		data_->set_size(data_->size() + 1);
	}
	//Add the new element to the end of the queue:
	data_->set(data_->size() - 1, element);
	//this->size_ += 1;

}



//Remove the element at the front of the queue:
template <typename T>
T Queue <T>::dequeue (void)
{
	if (is_empty()) {
		
		std::cout << "The stack is empty." << std::endl;
		throw empty_exception("The stack is empty.");
	}
	else {
		//Store the current front element, shift all other elements up, and then return the former front element:
		//
		T temp = data_->get(0);
		
		for (int index = 0; index < (data_->size() - 1); index++) {
			data_->set(index, data_->get(index+1));
		}
		
		data_->resize(data_->size() - 1);

		return temp;
	}
	
}



//is_empty check
template <typename T>
bool Queue <T>::is_empty (void) const
{
	return (this->data_->size() == 0);
}



//Return current Queue size
template <typename T>
size_t Queue <T>::size (void) const
{
	return this->data_->size();
}



//Isolate all elements of the Queue, effectively clearing it for future enqueues
template <typename T>
void Queue <T>::clear (void)
{
	this->data_->size() = 0;
}


