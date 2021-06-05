#ifndef MultiMap_H_
#define MultiMap_H_

#include <string>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BPlusTree\BPlusTree\BPlusTree\BPlusTree.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BTree-Functions\BTree-Functions\BTree-Functions\bTreeFunctions.h"

using namespace std;

template <typename K, typename V>
struct MPair {
    K key;
    Vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
     //--------------------------------------------------------------------------------
    MPair(const K& k = K()) {
        key = k;
        value_list += V();
    }
    MPair(const K& k, const V& v) {
        key = k;
        value_list += v;
    }
    MPair(const K& k, const Vector<V>& vlist) {
        k = key;
        value_list = vlist;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me) {
        outs << print_me.key << " " << print_me.value_list;
        return outs;
    }

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key == rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator !=(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key != rhs.key) {
            return true;
        } else {
            return false;
        }
    }

    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key < rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key <= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key > rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator >= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key >= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs == rhs) {
            lhs.value_list += rhs.value_list;
        }
    }
};


template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator {
    public:
        friend class MMap;
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

        MPair<K, V> operator *() {
            return *_it;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) {
            if (&lhs._it == &rhs._it /*&& lhs.key_ptr == rhs.key_ptr*/) {
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

    MMap();

    //  Iterators
    Iterator begin() {
        return mmap.begin();
    }

    Iterator end() {
        return mmap.end();
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
    const Vector<V>& operator[](const K& key) const;
    Vector<V>& operator[](const K& key);

    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

    //  Operations:
    bool contains(const K& key) const;
    bool has(const K& key);
    Vector<V>& get(const K& key);

    //finds the key we are looking for and returns an iterator to it
    Iterator find(const K& key) {
        return mmap.find_Iterator(key);
    }
    
    //prints the multimap like a table
    void print_table();

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me) {
        outs << print_me.mmap << endl;
        return outs;
    }

private:
    BPlusTree<MPair<K, V> > mmap;
};

template <typename K, typename V>
void MMap<K, V>::print_table() {
    for (Iterator it = this->begin(); it != this->end(); it++) {
        cout << *(it) << endl;
    }
}

template <typename K, typename V>
Vector<V>& MMap<K, V>::get(const K& key) {
    return mmap[key];
}

template <typename K, typename V>
int MMap<K, V>::size() const {
    return mmap.size();
}

template <typename K, typename V>
bool MMap<K, V>::empty() const {
    if (mmap.size() == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V>
void MMap<K, V>::insert(const K& k, const V& v) {
    if (mmap.contains(k)) {
        mmap.get(k).value_list += v;
    } else {
        MPair<K, V> temp(k, v);
        mmap.insert(temp);
    }
}

template <typename K, typename V>
void MMap<K, V>::erase(const K& key) {
    mmap.remove(key);
}

template <typename K, typename V>
void MMap<K, V>::clear() {
    mmap.clear_tree();
    
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::operator[](const K& key) {
    return mmap.get(key).value_list;
}

template <typename K, typename V>
const Vector<V>& MMap<K, V>::operator[](const K& key) const {
    return mmap.get(key).value_list;
}

template <typename K, typename V>
MMap<K, V>::MMap() {
    mmap;
}

template <typename K, typename V>
bool MMap<K, V>::contains(const K& key) const {
    return mmap.contains(key);
}

template <typename K, typename V>
bool MMap<K,V>::has(const K& key) {
    if (mmap.contains(key)) {
        return true;
    } else {
        return false;
    }
}

#endif // !MultiMap_H_