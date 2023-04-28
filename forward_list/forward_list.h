#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H


template <typename T>
class forward_list
{
private:
    struct node
    {
        T data;
        struct node *next;
    };

    node *head; 

public:
    /* Constructors */
    forward_list() : head(nullptr) {}  

    forward_list(std::initializer_list<T> elements) : head(nullptr)
    {
        for(auto __start = elements.end(), __end = elements.begin(); __start != __end; )
        {
            push_front(*--__start);  
        }
    }
    
    /* Destructor. */
    ~forward_list(){ }

    
    /* Add data to the front of the %forward_list. */
    void push_front(T data)
    {
        node *new_node = (node *) std::malloc(sizeof(node)); 
        if(!new_node)
        {
            puts("Out of memory...program terminated.");
            exit(EXIT_FAILURE); 
        }
        new_node->data = data;
        new_node->next = head;
        head = new_node; 
    }


    /* Remove first element. This is a typical %stack operation.  
     * It shrinks the %forward_list by one. */
    void pop_front(void)
    {
        if(!head)
        {
            puts("List is empty.");
            return;
        }
        node *tmp = head;
        head = head->next;
        std::free((void *) tmp);
    }


    /* Reverse the %forward_list. */
    void reverse(void)
    {
        if(!head)
        {
            return;
        }
        node *prev = NULL;
        node *next = NULL;
        while (head) 
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }


    /**
      *  Returns a read/write iterator that points to the first node
      *  in the %forward_list.
      */
    node *begin(void)
    {
        return head;
    }


    /**
      *  Returns a read-only iterator that points to the first node
      *  in the %forward_list.
      */
    const node *begin(void) const
    {
        return head; 
    }


    /* Return true if the %forward_list is empty. */
    bool empty(void)
    {
        if(!head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


     /* Return true if the %forward_list is empty. */
    const bool empty(void) const
    {
        if(!head)
        {
            return true;
        }
        else
        {
            return false; 
        }
    }


    /* Swap contents of two %forward_lists. */
    void swap(forward_list<T> *other)
    {
        node *tmp = other->head; 
        other->head = head;
        head = tmp;
    }


    /* Free the memory allocated for the %forward_list. */
    void erase(void)
    {
        if(!head)
        {
            puts("List is empty."); 
            return;
        }
        node *tmp = NULL;
        for (node *it = head; it; )
        {
            tmp = it;
            it = it->next; 
            free(tmp);
        }
        head = NULL;  
    }

};

#endif

