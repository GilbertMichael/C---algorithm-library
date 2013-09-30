/***************************************************************************** 
 *  Michael James Gilbert
 *  michael.james.gilbert@gmail.com
 *  Created on    09/30/2013 12:28:29 AM MDT
 *  Last Updated: 09/30/2013 04:03:45 PM MDT
 *
 *  A resizing array implementation of a LIFO stack. This implementation 
 *  currently doesn't support iteration. I have to take some serious design 
 *  issues into account in order to get the iteration implementation I am 
 *  working on to work. I hope to have it updated soon, as I really like this 
 *  resizing array version of the stack class. 
 *  
 *  At this point, all of the allocations are freed and no leaks are possible
 * 
 ******************************************************************************/

#include <iostream>
#include <stdlib.h>

template <class Item>
class Stack {
  
  // private members
private:
  
  int N;                 // size of the stack
  Item ** a;             // an array of items
  int length;            // keeps track of the length of the internal array
  
  // resize the underlying array
  void resize(int capacity) {
    Item ** temp = new Item*[capacity];
    for (int i = 0; i < N; i++) 
      temp[i] = a[i];
    delete [] a;
    a = temp;
    length = capacity;
  } 

  // public members
public: 
  
  /*
   * Initializes an empty stack
   */
  Stack() : N(0), length(2) {
    a = new Item*[2];
  }

  // frees up memory
  ~Stack() {
    for (int i = 0; i < N; i++)
      delete a[i];
    delete [] a;
  }

  /*
   * Is this stack empty?? 
   * @return true if so, false if otherwise
   */
  int is_empty() {
    return N == 0;
  }

  /*
   * @return the number of items on the stack
   */
  int size() {
    return N;
  }

  /*
   * Adds items to the stack
   * @param item is the item to add
   */
  void push(Item item) {
    if (N == length) resize(2 * length);  // double array size if necessary
    
    // store an extra copy of the item to the Pointer member item
    Item * temp = new Item;
    *temp = item;
    a[N++] = temp;                        // add item
  }

  /*
   * Removes and returns the item most recently added to the stack
   * @return the item most recently added
   */
  Item pop() {
    if (is_empty()) {
      std::cout << "Stack underflow" << std::endl;
      exit(1);
    }
    Item * item = a[N - 1];
    a[N - 1] = NULL;
    N--;
    
    Item temp = *item;               // delete item 
    delete item;
    
    // shrink the array size if necessary
    if (N > 0 && N == length / 4) resize(length/2);

    return temp;
  }

  /*
   *@return (but do not remove) the item most recently added to the stack
   */
  Item peek() {
    if (is_empty()) {
      std::cout << "Stack underflow" << std::endl;
      exit(1);
    }
    return *a[N - 1];
  }

}; // end of Stack class

