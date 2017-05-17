#pragma once

template<typename T>
class ListNode
{
public:
    ListNode* next;
    ListNode* prev;
    T value;
};

template<typename T>
class List
{
public:
    // dummy insert methods
    void pushFront(T value) {};
    void pushBack(T value) {};
    void insert(ListNode node, T value) {};

    // dummy remove methods
    void popFront() {};
    void popBack() {};
    void erase(ListNode node) {};
    void remove(T value) {};
    void remove(func)
private:
    ListNode<T>* m_first;
    ListNode<T>* m_last;
};