/***************************************************************************** 
 *  Michael James Gilbert
 *  michael.james.gilbert@gmail.com
 *  Created on    09/29/2013 02:40:15 PM MDT
 *  Last Updated: 09/29/2013 11:16:34 PM MDT 
 *
 *  A test client for stack classes
 * 
 ******************************************************************************/

// system includes
#include <iostream>
#include <string>
// user includes (put your stack header here) 
#include "linked_stack.hpp"

int main() {
  LinkedStack<std::string> s;
  while (std::cin) {
    std::string item;
    std::cin >> item;
    if (item != "-") s.push(item);
    else std::cout << s.pop() << " ";
  }
  std::cout << "(" << s.size() << " left on stack)" << std::endl;
  LinkedStack<std::string>::iterator iter;
  for (iter = s.begin(); iter != s.end(); iter++)
    std::cout << *iter << std::endl;
}

