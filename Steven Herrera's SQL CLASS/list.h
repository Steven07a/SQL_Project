#ifndef list_H_
#define list_H_

#include <iostream>
#include <cassert>
#include <cstdlib>

template <class T>
struct node {
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = NULL) :_item(item), _next(next) {}
    friend std::ostream& operator << (std::ostream& outs, const node<T>& print_me) {
        outs << "[" << print_me._item << "]->";
        return outs;
    }
};

//initializes head to NULL
template<class T> node<T>* init_head(node<T>*& head);
//deletes all the nodes in the list then sets head to null
template<class T> void delete_all(node<T>*& head);
//insert_after: if after is NULL, inserts at head
template <class T> node<T>* insert_after(node<T>*& head, node<T>* after, const T& item);
//makes a copy of the list, returns a pointer to the copys head
template <class T> node<T>* copy_list(const node<T>* head, node<T>*& cpy);
//insert at the beginning of the list:
template <class T> node<T>* insert_head(node<T>*& head, T item);
//delete the node at the head of the list, reuturn the item:
template <class T> T delete_head(node<T>*& head);
//print the list and return outs
template<class T> std::ostream& print_list(const node<T>* head, std::ostream& outs =std::cout);
//true if head is NULL, false otherwise.
template <class T> bool empty_node(const node<T>* head);

template<class T>
node<T>* init_head(node<T>*& head) {
    head = NULL;
    return head;
}

template<class T> void delete_all(node<T>*& head) {
    while (head) {
        delete_head(head);
    }
}

template <class T>
node<T>* insert_after(node<T>*& head, node<T>* after, const T& item) {
    node<T>* temp = new node<T>(item);
    if (empty_node(head)) {
        head = temp;
    } else if (after == NULL) {
        head->_next = temp;
    }
    else {
        //loops through the nodes seaching for after. sets itr = to after then 
        //it sets our new node->next =  to afters->next then sets afters->next to
        //temp. 
        for (node<T>* itr = head; itr != NULL; itr = itr->_next) {
            if (itr == after) {
                temp->_next = itr->_next;
                itr->_next = temp;
            }
        }
    }

    return temp;
}

template <class T>
node<T>* copy_list(const node<T>* head, node<T>*& cpy) {
    node<T>* temp = cpy;

    for (const node<T>* itr = head; itr != NULL; itr = itr->_next) {
        temp = insert_after(cpy, temp, itr->_item);
    }

    return cpy;
}

template <class T>
node<T>* insert_head(node<T>*& head, T item) {
    node<T>* temp = new node<T>{ item };

    if (head) {
        temp->_next = head;
        head = temp;
    }
    else {
        head = temp;
    }

    return temp;
}

template <class T>
T delete_head(node<T>*& head) {
    T item = head->_item;
    node<T>* del = head;
    head = head->_next;
    delete del;
    del = NULL;
    return item;
}

template<class T>
std::ostream& print_list(const node<T>* head, std::ostream& outs) {
    while (head) {
        outs << *head;
        head = head->_next;
    }
    outs << "||";

    return outs;
}

template <class T>
bool empty_node(const node<T>* head) {
    if (head == NULL) {
        return true;
    }

    return false;
}

#endif //list_H_