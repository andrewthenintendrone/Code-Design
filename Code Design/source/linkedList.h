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
    class Iterator
    {
    public:
        // constructors
        Iterator() {};
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
        ListNode<T>* m_node = nullptr;
    };
    // first and last ListNode access
    ListNode first() { return m_first };
    ListNode last() { return m_last };

    // Iterators
    Iterator begin() { return Iterator(m_first); }
    Iterator end() { return Iterator(nullptr); }

    // dummy insert methods
    void pushFront(T value)
    {
        ListNode<T>* n = new ListNode<T>(value);
        n->next = m_first;
        n->prev = nullptr;

        if (m_last == nullptr) m_last = n;
        if (m_first != nullptr) m_first->prev = n;
    }
    void pushBack(T value) {};
    void insert(ListNode node, T value) {};

    // dummy remove methods
    void popFront()
    {
        ListNode<T> *temp = m_first;
        
        if (m_first->next)
        {
            m_first->next->prev = m_first->prev;
        }
        m_first = m_first->next;

        delete temp;
    }
    void popBack() {};
    void erase(ListNode node) {};
    void remove(T value) {};

    bool isEmpty() { return (begin() == end()); }
private:
    ListNode<T>* m_first;
    ListNode<T>* m_last;
};