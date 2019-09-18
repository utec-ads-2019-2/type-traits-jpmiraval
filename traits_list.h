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
        unsigned int nodes = 0;

        bool find(T data, Node<T> **&pointer) {
            // TODO
            pointer = &head;
            while(*pointer != nullptr) {
                if (cmp((*pointer)->data, data)) {
                    if ((*pointer)->data == data)
                        return true;
                }
                else
                    return false;
                pointer = &((*pointer)->next);
            }
            return false;
        }

    public:
        TraitsList() : head(nullptr) {};

        bool insert(T data) {
            // TODO
            Node<T> **temp = nullptr;
            if(!find(data,temp)){
                auto node = new Node<T>(data);
                node->next = *temp;
                *temp = node;
                nodes++;
                return true;
            }
            return false;
        }

        bool remove(T data) {
            // TODO
            Node<T> **temp = &head;
            if (find(data, temp)){
                Node<T>* node = *temp;
                *temp = (*temp)->next;
                delete node;
                nodes--;
                return true;
            }
            return false;
        }

        bool find(T data) {
            // TODO
            Node<T> **pointer;
            return find(data, pointer);
        }

        T operator [] (int index) {
            // TODO
            if (size() >= 0 && index < size()){
                auto temp = head;
                for (int i = 0; i < index; ++i)
                    temp = temp->next;
                return temp->data;
            }
            throw out_of_range("Index out of range.");
        }

        int size() {
            // TODO
            return nodes;
        }

        void print() {
            // TODO
            Node<T> *temp = this->head;
            while (temp != nullptr) {
                std::cout << temp->data << ' ';
                temp = temp->next;
            }
        }

        ~TraitsList() {
            // TODO
            if (head != nullptr)
                head->killSelf();
        }
};

#endif