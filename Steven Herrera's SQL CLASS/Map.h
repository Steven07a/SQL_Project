#ifndef MAP_H_
#define MAP_H_

#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BPlusTree\BPlusTree\BPlusTree\BPlusTree.h"
#include <string>
using namespace std;

template <typename K, typename V>
struct Pair {
    K key;
    V value;

    Pair(const K& k = K(), const V& v = V()) {
        key = k;
        value = v;
    }
    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me) {
        outs << print_me.key << " " << print_me.value;
        return outs;
    }
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key == rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator !=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key != rhs.key) {
            return true;
        } else {
            return false;
        }
    }

    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key < rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key > rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key <= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator >= (const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
        if (lhs.key >= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
};


template <typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator {
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it) {
            this->_it = it;
        }

        Iterator operator ++(int unused) {
            _it++;
            return _it;
        }

        Iterator operator ++() {
            _it++;
            return _it;
        }

        Pair<K, V> operator *() {
            return *_it;
        }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) {
            if (&lhs._it == &rhs._it) {
                return true;
            } else {
                return false;
            }
        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) {
            if (lhs._it != rhs._it) {
                return true;
            } else {
                return false;
            }
        }

        bool is_null() { return _it.is_null(); }
    private:
        typename map_base::Iterator _it;

    };

    Map();
    //  Iterators
    Iterator begin() {
        return map.begin();
    }

    Iterator end() {
        return map.end();
    }

    Iterator lower_bound(const K& key) {
        Iterator temp = this->begin();
        while (temp != end()) {
            if (*temp >= key) {
                return temp;
            } else {
                temp++;
            }
        }
        return Iterator(NULL);
    }

    Iterator upper_bound(const K& key) {
        Iterator temp = this->begin();
        while (temp != end()) {
            if (*temp > key) {
                return temp;
            } else {
                temp++;
            }
        }
        return Iterator(NULL);
    }

    //  Capacity
    int size() const;
    bool empty() const;

    //  Element Access
    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;


    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V get(const K& key);

    //  Operations:
    Iterator find(const K& key) {
        return map.find_Iterator(key);
    }

    bool contains(const Pair<K, V>& target) const;

    void print_table();

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me) {
        print_me.map.print_tree();
        return outs;
    }
private:
    int key_count;
    BPlusTree<Pair<K, V> > map;
};

template <typename K, typename V>
void Map<K, V>::print_table() {
    for (Iterator it = this->begin(); it != this->end(); it++) {
        cout << *(it) << endl;
    }
}

template <typename K, typename V>
int Map<K, V>::size() const {
    return map.size();
}

template <typename K, typename V>
bool Map<K, V>::empty() const {
    return map.size();
}

template <typename K, typename V>
void Map<K, V>::insert(const K& k, const V& v) {
    Pair<K, V> temp(k, v);
    if (map.insert(temp)) {
        key_count++;
    }
}

template <typename K, typename V>
void Map<K, V>::erase(const K& key) {
    if (map.remove(key)) {
        key_count--;
    }
}

template <typename K, typename V>
void Map<K, V>::clear() {
    map.clear_tree();
    key_count = 0;
}

template <typename K, typename V>
V Map<K, V>::get(const K& key) {
    return map.get(key).value;
}

template <typename K, typename V>
V& Map<K, V>::operator[](const K& key) {
    return map.get(key).value;
}

template <typename K, typename V>
Map<K, V>::Map() {
    key_count = 0;
    map;
}

template <typename K, typename V>
V& Map<K, V>::at(const K& key) {
    return map.get(key).value;
}

template <typename K,typename V>
bool Map<K, V>::contains(const Pair<K, V>& target) const {
    return map.contains(target);
}

template <typename K, typename V>
const V& Map<K, V>::at(const K& key) const {
    return map.get(key).value;
}
#endif // !MAP_H_
