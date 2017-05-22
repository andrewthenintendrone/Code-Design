#pragma once
#include <aieException.h>

template<typename T>
class ListNode
{
public:
    // constructor
    ListNode() : next(nullptr), prev(nullptr) {};
    ListNode(T newValue) : value(newValue), next(nullptr), prev(nullptr) {};

    ListNode* next;
    ListNode* prev;
    T value;
};

template<typename T>
class List
{
public:
    List() : m_front(nullptr), m_back(nullptr), size(0) { }
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
        insertBefore(Iterator(m_front), value);
    }

    // adds a node to the back of the list
    void pushBack(T value)
    {
        insertAfter(Iterator(m_back), value);
    }

    // adds a node before the specified iterator
    void insertBefore(Iterator iter, T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        ListNode<T> *currentNode = iter.getNode();
        size++;

        if (currentNode == nullptr)
        {
            currentNode = n;
            m_front = n;
            m_back = n;
            return;
        }

        n->prev = currentNode->prev;
        n->next = currentNode;
        currentNode->prev = n;

        if (n->prev)
        {
            n->prev->next = n;
        }
        else
        {
            m_front = n;
        }
    };

    // adds a node after the specified iterator
    void insertAfter(Iterator iter, T value)
    {
        ListNode<T> *n = new ListNode<T>(value);
        ListNode<T> *currentNode = iter.getNode();
        size++;

        if (currentNode == nullptr)
        {
            currentNode = n;
            m_front = n;
            m_back = n;
            return;
        }

        n->next = currentNode->next;
        n->prev = currentNode;
        currentNode->next = n;

        if (n->next)
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
        erase(m_front);
    }

    // // removes a node from the back of the list
    void popBack()
    {
        erase(m_back);
    }

    // removes a node 
    void erase(Iterator iter)
    {
        ListNode<T>* node = iter.getNode();

        // if there is a next node
        if (node->next)
        {
            node->next->prev = node->prev;
            // set new front if necessary
            if (node == m_front)
            {
                m_front = node->next;
            }
        }
        // if there is a previous node
        if (node->prev)
        {
            node->prev->next = node->next;
            // set new back if necessary
            if (node == m_back)
            {
                m_back = node->prev;
            }
        }
        // if there are no other nodes
        if (!node->next && !node->prev)
        {
            // set front and back to nullptr
            m_front = nullptr;
            m_back = nullptr;
        }

        size--;

        delete node;
    };

    // removes values that match the input
    void remove(T input)
    {
        List<T> temp;

        for (auto iter = begin(); iter != end(); iter++)
        {
            if (iter.getNode()->value != input)
            {
                temp.pushBack(iter.getNode()->value);
            }
        }

        *this = temp;
    };

    // remove with predicate
    void remove(bool(*predicate)(T input))
    {
        List<T> temp;

        for (auto iter = begin(); iter != end(); iter++)
        {
            if (!predicate(iter.getNode()->value))
            {
                temp.pushBack(iter.getNode()->value);
            }
        }

        *this = temp;
    }

    // removes all elements from the list
    void clear()
    {
        while (!empty())
        {
            popBack();
        }
    }

    bool empty() { return m_front == nullptr; }

    // returns the number of nodes in the List
    unsigned int count()
    {
        return size;
    }

    // overloads

    // sets the list to another list
    void operator = (List* newList)
    {
        clear();
        for (auto iter = newList->begin(); iter != newList->end(); iter++)
        {
            pushBack(iter.getNode()->value);
        }
    }

private:
    ListNode<T>* m_front;
    ListNode<T>* m_back;
    unsigned int size;
};