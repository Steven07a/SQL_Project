#ifndef stack_H_
#define stack_H_

#include "list.h"

template <class T>
class Stack {
public:
    Stack() :_top(NULL) {}

    ~Stack() {
        delete_all(_top);
    }
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs) {
       _top = copy_list(rhs._top, _top);
       return _top;
    }

    void push(T item) {
        insert_head(_top, item);
    }
    T pop() {
        return delete_head(_top);
    }
    T top() {
        return _top->_item;
    }
    bool empty() {
        return empty_node(this->_top);
    }
    friend std::ostream& operator << (std::ostream& outs, const Stack& s) {
        return print_list(s._top, outs);
    }
private:
    node<T>* _top;
};

#endif // !stack_H_
