// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.


template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->data_->size();
}



//Returns the element at the top of the Stack:
template <typename T>
inline
T Stack <T>::top (void) const
{
	return data_->get(data_->size() - 1);
}



template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (this->data_->size() == 0);
}
