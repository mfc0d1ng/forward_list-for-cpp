#include <iostream>
#include "forward_list.h"


int main()
{

    forward_list<int> Stack;

    for (size_t i = 0; i < 1000000; i++)
    {
        Stack.push_front(i); 
    }

    if(!Stack.empty())
    {
        std::cout << "Top element = " << Stack.begin()->data << '\n';
    }

    /* 
    for(auto node = Stack.begin(); node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';  
    } 
    */

    return EXIT_SUCCESS;
}
