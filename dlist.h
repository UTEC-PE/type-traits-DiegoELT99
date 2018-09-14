#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++()
                {
                    if (this -> current)
                    {
                        this -> current = this -> current -> next; // Y si current es null no retornas nada?
                        return *this;
                    }
                };
        DListIterator<T> operator--()
        {
            if (this -> current)
            {
                this -> current = this -> current -> prev; // Y si current es null no retornas nada?
                return *this;
            }
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
              
    public:
        DList() {
            head = tail = nullptr;
            nodes = 0;
        };

        void push_front(T data)
        {
            Node<T>* NewStart = new Node<T>(data); //Creamos el puntero a Nodo que sera nuevo start

            if (head == nullptr || !head) //Si la lista esta vacia
                {
                    NewStart -> next = nullptr;
                    tail = NewStart;
                }

            else //Si la lista tiene elementos
            {
                NewStart -> next = head; //El nuevo nodo tiene como next al start actual
                head -> prev = NewStart;
            }

            head = NewStart; //Pasa a convertirse en el nuevo start
            NewStart -> prev = nullptr;
            (this -> nodes)++; //Aumenta el numero de nodos en 1
        }

        void push_back(T data)
        {
            Node<T>* NewEnd = new Node<T>(data); //Creamos el puntero al nuevo Nodo

            if (head == nullptr || !head) //Si la lista esta vacia
            {
                NewEnd -> prev = nullptr;
                head = NewEnd;
            }

            else
            {
                tail -> next = NewEnd;
                NewEnd -> prev = tail;
            }

            NewEnd -> next = nullptr;
            tail = NewEnd;
            (this -> nodes)++; //Aumenta el numero de nodos en 1
        }
             
        void pop_front()
        {
            if (head == nullptr || !head) //Si la lista esta vacia
                throw "Lista Vacía.";
            if ((this -> nodes) == 1)
            {
                delete head;
                delete tail;
            }
            else
                {
                    Node<T>* ByeNode = head;
                    head = head -> next;
                    delete ByeNode;
                }
            (this -> nodes)--;
        }
             
        void pop_back()
        {
            if (head = nullptr || !head) //Si la lista esta vacia
                throw "Lista Vacía.";
            if ((this -> nodes) == 1)
            {
                delete head;
                delete tail;
            }
            else
                {
                    Node<T>* ByeNode = tail;
                    tail = tail -> prev;
                    delete ByeNode;
                }
            (this -> nodes)--;
        }
             
        iterator begin()
        {
            return iterator(this -> head);
        }
             
        iterator end()
        {
            return iterator(this -> tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif