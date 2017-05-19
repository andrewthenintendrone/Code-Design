#pragma once
#include <aieException.h>

template<typename T>
class ListNode
{
public:
    // constructor
    ListNode() { next = nullptr; prev = nullptr; };
    ListNode(T newValue) : value(newValue), next(nullptr), prev(nullptr) {};

    ListNode* next;
    ListNode* prev;
    T value;
};

template<typename T>
class List
{
public:
    List() : m_front(nullptr), m_back(nullptr) { }
    class Iterator
    {
    public:
        // constructors
        Iterator() : m_node(nullptr) {};
        Iterator(ListNode<T>* node) : m_node(node) { }

        // Iterator methods
        void operator ++ () { m_node = m_node->next; }
        void operator ++ (int) { m_node = m_node->next; }

        void operator -- () { m_node = m_node->prev; }
        void operator -- (int) { m_node = m_node->prev; }

        T& operator * () { return m_node->value; }
        T* operator -> () { return &m_node->value; }

        bool operator == (const Iterator& rhs) { return (m_node == rhs.m_node); }
        bool operator != (const Iterator& rhs) { return (m_node != rhs.m_node); }

        ListNode<T>* getNode() { return m_node; }

    private:
        // pointer to node
        ListNode<T>* m_node;
    };

    // first and last ListNode access
    ListNode<T>* first() { return m_front };
    ListNode<T>* last() { return m_back };

    // Iterators
    Iterator begin() { return Iterator(m_front); }
    Iterator end() { return Iterator(nullptr); }

    // dummy insert methods
    void pushFront(T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        n->next = m_front;
        n->prev = nullptr;

        if (isEmpty())
        {
            m_back = n;
        }
        if (m_front != nullptr)
        {
            m_front->prev = n;
        }

        m_front = n;
    }

    void pushBack(T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        n->next = nullptr;
        n->prev = m_back;

        if (isEmpty())
        {
            m_front = n;
        }
        if (m_back != nullptr)
        {
            m_back->next = n;
        }

        m_back = n;
    }
    void insert(ListNode<T>* node, T value) {};

    // dummy remove methods
    void popFront()
    {
        ListNode<T> *temp = m_front;
        
        if (isEmpty())
        {
            aieTHROW("Cannot POP FRONT when list is empty");
        }
        if (m_front->next)
        {
            m_front->next->prev = m_front->prev;
        }
        m_front = m_front->next;

        delete temp;
    }

    void popBack()
    {
        ListNode<T> *temp = m_back;

        if (isEmpty())
        {
            aieTHROW("Cannot POP BACK when list is empty");
        }
        if (m_back->prev)
        {
            m_back->prev->next = nullptr;
        }
        else
        {
            // list only had one element so clear the list
            m_front = nullptr;
        }
        m_back = m_back->prev;

        delete temp;
    }
    void erase(ListNode<T>* node) {};
    void remove(T value) {};

    bool isEmpty() { return m_front == nullptr; }
private:
    ListNode<T>* m_front;
    ListNode<T>* m_back;
};