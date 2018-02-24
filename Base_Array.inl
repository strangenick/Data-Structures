// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


template <typename T>
inline
size_t Base_Array <T>::size (void) const
{
	return cur_size_;
}



template <typename T>
inline
size_t Base_Array <T>::max_size (void) const
{
	return max_size_;
}
