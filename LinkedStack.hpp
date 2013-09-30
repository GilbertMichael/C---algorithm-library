/***************************************************************************** 
 *  Michael James Gilbert
 *  michael.james.gilbert@gmail.com
 *  Created on    09/28/2013 07:15:49 PM MDT
 *  Last Updated: 09/29/2013 11:16:34 PM MDT
 *
 *  Linked-list implementation of a stack. 
 * 
 ******************************************************************************/

#include <iostream>
#include <stdlib.h>

template <class Item>
class LinkedStack {
private:

  // helper linked list class
  class Node {
  public:
    Item item;
    Node * next;
    
    // @returns the item stored in the node. For use with the iterator.  
    Item& get_val() {
      return item;
    }
    
  };

  int N;
  Node * first;
  
// public members	  
public:
  
  /*
   *initializes an empty stack
   */
  LinkedStack() : N(0), first(NULL) { }

  // frees up memory from stack
  ~LinkedStack() {
    while (first != NULL) {
      Node * temp = first;
      first = temp->next;
      delete temp;
    }
    delete first;
  }

  /*
   * is this stack empty? @return true if stack is empty; false otherwise
   */
  bool is_empty() {
    return first == NULL;
  }

  /*
   * @returns the number of items in the stack
   */
  int size() {
    return N;
  }

  /*
   * Adds items to the stack. @param item is the item to add
   */
  void push(Item item) {
    Node * oldfirst = first;
    first = new Node;
    first->item = item;
    first->next = oldfirst;
    N++;
  }

  /*
   * Removes and returns the item most recently added to this stack
   * @returns the item most recently added
   */
  Item pop() {
    if (is_empty()) {
      std::cout << "Stack underflow" << std::endl;
      exit(1);
    }
    
    // save item to return
    Item item = first->item;
    
    // delete first node
    Node * temp = first;
    first = temp->next;
    delete temp;
    N--;

    // return the item
    return item;
  }

  /*
   * @returns the value of the item on the top of the stack
   */
  Item peak() {
    return first->item;
  }

  /*
   * Returns an iterator to this stack that iterates through the 
   * items in LIFO order. 
   */
  
  // an iterator
  class iterator {
  private:
    Node * current;
  public:
    iterator() {}
    iterator(Node * x) : current(x) {}
    ~iterator() {}

    // assignment and relational operators are straightforward
    iterator& operator=(const iterator& that) {
      current = that.current;
      return(*this);
    }

    bool operator==(const iterator& that) {
      return (current == that.current);
    }

    bool operator!=(const iterator& that) {
      return (current != that.current);
    }

    // Update the state such that I refer to the next element in the stack
    iterator& operator++() {
      if (current != NULL) 
	current = current->next;
      return (*this);
    }
    
    iterator operator++(int) {
      iterator temp(*this);
      ++(*this);
      return temp;
    }
    
    // Return a reference to the value in the node. 
    Item& operator*() {
      return (current->get_val());
    }

    // Return the address of the value referred to.
    Item * operator->() {
      return &*(LinkedStack<Item>::iterator)*this;
    }
    
  }; // end of ListIterator class

  iterator begin() {
    return iterator(first);
  }

  iterator end() {
    return iterator(NULL);
  }

}; // end of LinkedStack class prototype

