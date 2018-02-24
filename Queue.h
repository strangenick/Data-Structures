//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_


#include "Array.h"

template <typename T>
class Queue
{
public:

  class empty_exception : public std::logic_error
  {
  public:
   
    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::logic_error (msg) { }
  };

  //Default constructor		
  Queue(void);


  //Copy constructor
  Queue(const Queue & q);


  //Destructor
  ~Queue(void);


  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);
  
  /**
   * Add a new \a element to the end of the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue(T element);
  


  /**
   * Remove the top-most element from the queue.
   *
   * @return         top-most element 
   *
   * @exception      empty_exception    The stack is empty.
   */
  T dequeue(void);
  

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty(void) const;
  

  /**
   * Number of elements in the queue.
   *
   * @return         Size of the queue.
   */
  size_t size(void) const;


 /// Remove all elements from the stack.
  void clear(void);

private:
  Array <T> * data_;
  //size_t size_;
	
};

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _QUEUE_H_
