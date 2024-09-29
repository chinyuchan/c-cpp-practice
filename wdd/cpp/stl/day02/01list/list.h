#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class List {
public:
    List() : _head(nullptr), _tail(nullptr) {}

    template<typename IT>
    List(IT beg, IT end) : _head(nullptr), _tail(nullptr) {
        for(; beg !=end; ++beg) {
            push_back(*beg);
        }
    }

    List(initializer_list<T> container) : _head(nullptr), _tail(nullptr) {
        for(const T& data: container) {
            push_back(data);
        }
    }

    List(const List& list) {
        for(Node* node = list._head; node != nullptr; node = node->_next) {
            push_back(node->_data);
        }
    }

    List& operator=(const List& list) {
        if (this != &list) {
            List l(list);
            swap(_head, l._head);
            swap(_tail, l._tail);
        }
        return *this;
    }

    List(List&& list) noexcept {
        _head = list._head;
        _tail = list._tail;
        list._head = nullptr;
        list._tail = nullptr;
    }

    List& operator=(List&& list) noexcept {
        if (this != &list) {
            clear();
            _head = list._head;
            _tail = list._tail;
            list._head = nullptr;
            list._tail = nullptr;
        }
        return *this;
    }

    ~List() {
        clear();
    }

    void push_back(const T& data) {
        Node* node = new Node(data, nullptr, _tail);
        if (_tail != nullptr) {
            _tail->_next = node;
        }
        else {
            _head = node;
        }

        _tail = node;
    }

    void clear() {
        for(Node* node; _head != nullptr;) {
            node = _head;
            _head = _head->_next;
            delete node;
        }
        _tail = nullptr;
    }

    [[nodiscard]] bool empty() const { return _head == nullptr && _tail == nullptr; }

    [[nodiscard]] size_t size() const {
        size_t cnt = 0;
        for(Node* node = _head; node != nullptr; node = node->_next) {
            ++cnt;
        }
        return cnt;
    }

    void push_front(const T& data) {
        Node* node = new Node(data, _head, nullptr);
        if (_head != nullptr) {
            _head->_prev = node;
        }
        else {
            _tail = node;
        }
        _head = node;
    }

    void pop_front() {
        if (empty()) {
            throw underflow_error("empty");
        }
        Node* node = _head;
        _head = _head->_next;
        if (_head ==nullptr) {
            _tail = nullptr;
        }
        delete node;
    }

    void pop_back() {
        if (empty()) {
            throw underflow_error("empty");
        }
        Node* node = _tail;
        _tail = _tail->_prev;
        if (_tail == nullptr) {
            _head = nullptr;
        }
        delete node;
    }

    T& front() {
        if (empty()) {
            throw underflow_error("empty");
        }
        return _head->data;
    }

    const T& front() const {
        if (empty()) {
            throw underflow_error("empty");
        }
        return _head->data;
    }

    T& back() {
        if (empty()) {
            throw underflow_error("empty");
        }
        return _tail->data;
    }

    const T& back() const {
        if (empty()) {
            throw underflow_error("empty");
        }
        return _tail->data;
    }

    template<typename F>
    void print(F f) {
        for(Node* node = _head; node != nullptr; node = node->_next) {
            f(node->_data);
        }
    }

private:
    class Node {
    public:
        explicit Node(const T& data, Node* next=nullptr, Node* prev=nullptr) : _data(data), _next(next), _prev(prev) {}
        Node() : _next(nullptr), _prev(nullptr) {}

        T _data;
        Node* _next;
        Node* _prev;
    };

public:
    class Iterator {
    public:
        bool operator==(const Iterator& it) const {
            return _it_cur == it._it_cur;
        }

        bool operator!=(const Iterator& it) const {
            return _it_cur != it._it_cur;
        }

        Iterator& operator++() {
            _it_cur = _it_cur->_next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            if (_it_cur == nullptr) {
                _it_cur = _it_tail;
            }
            else {
                _it_cur = _it_cur->_prev;
            }

            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp(*this);
            --(*this);
            return tmp;
        }

        T& operator*() {
            return _it_cur->_data;
        }

        const T& operator*() const {
            return _it_cur->_data;
        }

        T* operator->() {
            return &_it_cur->_data; // return &**this;
        }

    private:
        explicit Iterator(Node* head = nullptr, Node* tail = nullptr, Node* cur = nullptr)
            : _it_cur(cur), _it_head(head), _it_tail(tail) {}

        Node* _it_cur;
        Node* _it_head;
        Node* _it_tail;

        friend class List;
    };

    class ReverseIterator {
    public:
        bool operator==(const ReverseIterator& it) const {
            return _rit_cur == it._rit_cur;
        }

        bool operator!=(const ReverseIterator& it) const {
            return _rit_cur != it._rit_cur;
        }
        ReverseIterator& operator++() {
            _rit_cur = _rit_cur->_prev;
            return *this;
        }
        ReverseIterator operator++(int) {
            ReverseIterator tmp(*this);
            ++(*this);
            return tmp;
        }
        ReverseIterator& operator--() {
            if (_rit_cur == nullptr) {
                _rit_cur = _rit_head;
            }
            else {
                _rit_cur = _rit_cur->_next;
            }
            return *this;
        }
        ReverseIterator operator--(int) {
            Iterator tmp(*this);
            --(*this);
            return tmp;
        }
        T& operator*() {
            return _rit_cur->_data;
        }

        const T& operator*() const {
            return _rit_cur->_data;
        }

        T* operator->() {
            return &_rit_cur->_data; // return &**this;
        }
    private:
        explicit ReverseIterator(Node* head = nullptr, Node* tail = nullptr, Node* cur = nullptr)
            :  _rit_cur(cur), _rit_head(head), _rit_tail(tail) {}

        Node* _rit_cur;
        Node* _rit_head;
        Node* _rit_tail;

        friend class List;
    };

    ReverseIterator rbegin() {
        return ReverseIterator(_head, _tail, _tail);
    }

    ReverseIterator rend() {
        return ReverseIterator(_head, _tail, nullptr);
    }

    Iterator begin() {
        return Iterator(_head, _tail, _head);
    }

    // 最后一个节点的下一个位置
    Iterator end() {
        return Iterator(_head, _tail, nullptr);
    }

    // 在it前插入
    Iterator insert(Iterator it, const T& data) {
        if (it._it_cur == nullptr) {
            push_back(data);
            return Iterator(_head, _tail, _tail);
        }

        Node* node = new Node(data, it._it_cur, it._it_cur->_prev);
        if (it._it_cur->_prev != nullptr) {
            it._it_cur->_prev->_next = node;
        }
        else {
            _head = node;
        }

        it._it_cur->_prev = node;

        return Iterator(_head, _tail, node);
    }

    // 在it前插入[beg,end)区间的元素
    template<typename IT> void insert(Iterator it, IT beg, IT end) {
        for(; beg != end; ++beg) {
            insert(it, *beg);
        }
    }

    void insert(Iterator it, initializer_list<T> initList) {
        for (const T& data : initList) {
            // cout << "<<: " << data << endl;
            insert(it, data);
        }
    }

    // 删除it指向的元素
    // 返回删除元素的下一个迭代器
    Iterator erase(Iterator it) {
        if (it._it_cur == nullptr) {
            throw overflow_error("list overflow");
        }

        if(it._it_cur->_prev != nullptr) {
            it._it_cur->_prev->_next = it._it_cur->_next;
        }
        else {
            _head = it._it_cur->_next;
        }

        if (it._it_cur->_next != nullptr) {
            it._it_cur->_next->_prev = it._it_cur->_prev;
        }
        else {
            _tail = it._it_cur->_prev;
        }

        Iterator next(_head, _tail, it._it_cur->_next);

        delete it._it_cur;

        return next;
    }

    // 删除[beg,end)区间的元素
    Iterator erase(Iterator beg, Iterator end) {
        for (; beg != end;) { // 不能使用++beg
            beg = erase(beg);
        }
        return end;
    }

private:
    Node* _head;
    Node* _tail;
};



#endif //LIST_H
