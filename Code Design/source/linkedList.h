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
    ListNode<T>* first() { return m_front; }
    ListNode<T>* last() { return m_back; }

    // Iterators
    Iterator begin() { return Iterator(m_front); }
    Iterator end() { return Iterator(nullptr); }

    // adds a node to the front of the list
    void pushFront(T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        n->next = m_front;
        n->prev = nullptr;

        if (empty())
        {
            m_back = n;
        }
        if (m_front != nullptr)
        {
            m_front->prev = n;
        }

        m_front = n;
    }

    // adds a node to the back of the list
    void pushBack(T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        n->next = nullptr;
        n->prev = m_back;

        if (empty())
        {
            m_front = n;
        }
        if (m_back != nullptr)
        {
            m_back->next = n;
        }

        m_back = n;
    }

    // adds a node after the specified iterator
    void insert(Iterator& iter, T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        ListNode<T> *current = iter.getNode();

        n->next = current->next;
        n->prev = current;
        current->next = n;

        if (n->next != nullptr)
        {
            n->next->prev = n;
        }
        else
        {
            m_back = n;
        }
    };

    // removes a node from the front of the list
    void popFront()
    {
        ListNode<T> *temp = m_front;
        
        if (empty())
        {
            aieTHROW("Cannot use popFront on an empty list");
        }
        if (m_front->next)
        {
            m_front->next->prev = m_front->prev;
        }
        m_front = m_front->next;

        delete temp;
    }

    // // removes a node from the back of the list
    void popBack()
    {
        ListNode<T> *temp = m_back;

        if (empty())
        {
            aieTHROW("Cannot use popBack on an empty list");
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

    // removes a node 
    void eraseNode(ListNode<T>* node)
    {
        // unlink surrounding nodes
        if (node->next)
        {
            node->next->prev = node->prev;
            if (node == m_front)
            {
                m_front = node->next;
            }
        }
        if (node->prev)
        {
            node->prev->next = node->next;
            if (node == m_back)
            {
                m_back = node->prev;
            }
        }
        if (!node->next && !node->prev)
        {
            m_front = nullptr;
            m_back = nullptr;
        }
        delete node;
    };

    void remove(T value) {};

    // removes all elements from the list
    void clear()
    {
        while (!empty())
        {
            popBack();
        }
    }

    bool empty() { return m_front == nullptr; }

    // overloads


private:
    ListNode<T>* m_front;
    ListNode<T>* m_back;
};