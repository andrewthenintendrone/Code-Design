#pragma once
#include <aieException.h>

//################################################//
//  List Node Class                               //
//################################################//
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

//################################################//
//  Linked List Class                             //
//################################################//
template<typename T>
class List
{
public:
    //################################################//
    //  Iterator Class                                //
    //################################################//
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

        // public access to ListNode
        ListNode<T>* getNode() { return m_node; }

    private:
        ListNode<T>* m_node;
    };

    // constructor
    List() : m_front(nullptr), m_back(nullptr), size(0) { }

    // adds a ListNode to the front of the List
    void pushFront(T value)
    {
        insertBefore(Iterator(m_front), value);
    }

    // adds a ListNode to the back of the List
    void pushBack(T value)
    {
        insertAfter(Iterator(m_back), value);
    }

    // inserts a ListNode before the specified Iterators ListNode
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

    // inserts a ListNode after the specified Iterators ListNode
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

    // removes a ListNode from the front of the List
    void popFront()
    {
        erase(m_front);
    }

    // removes a ListNode from the back of the List
    void popBack()
    {
        erase(m_back);
    }

    // removes the specified Iterators ListNode 
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

    // removes ListNodes containing values matching the input
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

    // removes ListNodes that satisfy a predicate
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

    // removes all ListNodes from the List
    void clear()
    {
        while (!empty())
        {
            popBack();
        }
    }

    // returns true if the List is has no ListNodes
    bool empty()
    {
        return m_front == nullptr;
    }

    // returns the number of ListNodes in the List
    unsigned int count()
    {
        return size;
    }

    // overloaded = operator
    void operator = (List* newList)
    {
        clear();
        for (auto iter = newList->begin(); iter != newList->end(); iter++)
        {
            pushBack(iter.getNode()->value);
        }
    }

    // public access to private ListNodes
    ListNode<T>* first() { return m_front; }
    ListNode<T>* last() { return m_back; }

    // Iterators
    Iterator begin() { return Iterator(m_front); }
    Iterator end() { return Iterator(nullptr); }

private:
    ListNode<T>* m_front;
    ListNode<T>* m_back;
    unsigned int size;
};