#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& _data, Node<T>* _next = nullptr);
};

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const Queue<T>& other);
    void erase();
public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue<T>& other);
    ~Queue();

    const T& front()const;
    const T& back()const;
    size_t getSize()const;
    bool empty()const;

    void push(const T& dt);
    void pop();
};

template <typename T>
Node<T>::Node(const T& _data, Node<T>* _next) : data(_data), next(_next){}

template <typename T>
void Queue<T>::copy(const Queue<T>& other)
{
    Node<T>* tmp = other.first;
    for(size_t i = 0; i < other.getSize(); i++)
    {
        push(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
void Queue<T>::erase()
{
    while(!empty())
        pop();
}

template <typename T>
Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
    copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if(this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    erase();
}

template <typename T>
const T& Queue<T>::front()const
{
    if(empty())
        throw logic_error("Empty queue");
    else
        return first->data;
}

template <typename T>
const T& Queue<T>::back()const
{
    if(empty())
        throw logic_error("Empty queue");
    else
        return last->data;
}

template <typename T>
size_t Queue<T>::getSize()const
{
    return size;
}

template <typename T>
bool Queue<T>::empty()const
{
    return size == 0;
}

template <typename T>
void Queue<T>::push(const T& dt)
{
    Node<T>* newnode = new Node<T>(dt);
    if(empty())
    {
        first = newnode;
        last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
    size++;
}

template <typename T>
void Queue<T>::pop()
{
    if(empty())
        throw logic_error("Empty queue");
    else
    {
        Node<T>* fst = first;
        first = first->next;
        delete fst;
        size--;
    }
}
