#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            // TODO
        }
              
    public:
        TraitsList() : head(nullptr) {};
             
        bool insert(T data) {
            // TODO
            return true;
        }
             
        bool remove(T data) {
            // TODO
                return true;
        }  

        bool find(T data) {
            // TODO
                return true;
        }

        T operator [] (int index) {
            // TODO
            return 0;
        }
             
        int size() {
            // TODO
            return 0;
        }

        void print() {
            // TODO
        }

        ~TraitsList() {
            // TODO
        }         
};

#endif