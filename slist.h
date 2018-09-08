#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++()
                {
                    if (this -> current)
                    {
                        this -> current = this -> current -> next;
                        return *this;
                    }
                };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
        int nodes;
              
    public:
        SList()
        {
            head = nullptr;
            nodes = 0;
        };

        bool find(T search, Node<T> **&pointer)
        {
            pointer = &head;
            if(head == nullptr)
                return false;
            for(int i = 0; i < nodes; i++)
            {
                if (cmp((*pointer) -> data,search))
                    break;
                else
                    pointer = &((*pointer) -> next);
            }
            return ((*pointer) -> data == search);
        }
             
        bool insert(T data)
        {
                Node<T> **pointer;
                if(find(data,pointer))
                    return false;
                else
                {
                    Node<T>* NewNode = new Node<T>(data);
                    NewNode -> next = (*pointer);
                    (*pointer) = NewNode;
                }
                nodes++;
                return true;
        }
             
        bool remove(T item)
        {
            Node<T> **pointer = &head;
            if(!(find(item,pointer)))
                return false;
            else
                {
                    Node<T>* ByeNode = (*pointer);
                    (*pointer) = (*pointer) -> next;
                    delete ByeNode;
                }
                nodes--;
            return true;
        }  
             
        iterator begin() {
            return iterator(this -> head);
        }
             
        iterator end()
        {
            return iterator(nullptr);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif