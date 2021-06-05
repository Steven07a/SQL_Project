#ifndef queue_H_
#define queue_H_

#include "./list.h"

template <class T>
class Queue {
public:
    Queue() :_head(NULL), _tail(NULL), count(0) {}

    ~Queue() {
        delete_all(_head);
    }
    Queue(const Queue<T>& other);
    Queue<T>& operator =(const Queue& rhs) {
        _head = copy_list(rhs._head, _head);
        return *this;
    }

    void push(T item) {
        _tail = insert_after(_head, _tail, item);
        count++;
    }

    T pop() {
        assert(!empty());
        count--;
        return delete_head(_head);
    }

    bool empty() {
        if (_head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    T front() {
        return _head->_item;
    }

    int size() {
        return count;
    }

    friend std::ostream& operator <<(std::ostream& outs, const Queue& q) {
        return print_list(q._head, outs);
        return outs;
    }

private:
    node<T>* _head;
    node<T>* _tail;
    int count;
};


#endif // !queue_H_

