#include <iostream>
#include "forward_list.h"


int main()
{

    forward_list<int> stack;

    for (size_t i = 0; i < 1000000; i++)
    {
        stack.push_front(i); 
    }

    if(!stack.empty())
    {
        std::cout << "Top element = " << stack.begin()->data << '\n';
    }

    /* 
    for(auto node = stack.begin(); node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';  
    } 
    */

    return EXIT_SUCCESS;
}
