#pragma once
#include <aieException.h>

template<typename T>
class ListNode
{
public:
    // constructor
    ListNode() { next = nullptr; prev = nullptr; };
    ListNode(T newValue) : value(newValue) { next = nullptr; prev = nullptr; };

    ListNode<T>* next;
    ListNode<T>* prev;
    T value;
};

template<typename T>
class List
{
public:
    List() : m_first(nullptr), m_last(nullptr) { }
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
    ListNode<T>* first() { return m_first };
    ListNode<T>* last() { return m_last };

    // Iterators
    Iterator begin() { return Iterator(m_first); }
    Iterator end() { return Iterator(nullptr); }

    // dummy insert methods
    void pushFront(T value)
    {
        ListNode<T>* n = new ListNode<T>(value);
        n->next = m_first;
        n->prev = nullptr;

        if (m_last == nullptr)
        {
            m_last = n;
        }
        if (m_first != nullptr)
        {
            m_first->prev = n;
        }

        m_first = n;
    }

    void pushBack(T value)
    {
        ListNode<T>* n = new ListNode<T>(value);
        n->next = nullptr;
        n->prev = m_last;

        if (m_first == nullptr)
        {
            m_first = n;
        }
        if (m_last != nullptr)
        {
            m_last->next = n;
        }

        m_last = n;
    }
    void insert(ListNode<T>* node, T value) {};

    // dummy remove methods
    void popFront()
    {
        
        ListNode<T> *temp = m_first;
        
        if (first == nullptr)
        {
            aieTHROW("Cannot POP FRONT when list is empty");
        }
        if (m_first->next)
        {
            m_first->next->prev = m_first->prev;
        }
        m_first = m_first->next;

        delete temp;
    }

    void popBack()
    {
        ListNode<T> *temp = m_last;
        // aieASSERT(m_last);
        if (m_last == nullptr)
        {
            aieTHROW("Cannot POP BACK when list is empty");
        }
        if (m_last->prev)
        {
            m_last->prev->next = nullptr;
        }
        m_last = m_last->prev;

        delete temp;
    }
    void erase(ListNode<T>* node) {};
    void remove(T value) {};

    bool isEmpty() { return (begin() == end()); }
private:
    ListNode<T>* m_first;
    ListNode<T>* m_last;
};