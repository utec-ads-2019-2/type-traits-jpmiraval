#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;
        int nodes = 0;

    public:
        SelfList(Method method) : head(nullptr) {
                this->method = method;
        };

        void insert(T data) {
            // TODO
            this->nodes++;
            auto temp = new Node<T> (data);
            if(this->head== nullptr)
                    this->head = temp;
            else{
                    temp->next = this->head;
                    this->head = temp;
            }

        }
             
        bool remove(T data) {
            // TODO
                if(this->head == nullptr)
                        return false;
                Node<T> *pointer = this->head;
                if(pointer->data == data){
                        this->head = pointer->next;
                        delete pointer;
                        this->nodes--;
                        return true;
                }


                while(pointer->next!= nullptr){
                        pointer = pointer->next;
                        if(pointer->data == data) {
                                auto temp = pointer->next;
                                pointer->data = pointer->next->data;
                                pointer->next = pointer->next->next;
                                delete temp;
                                this->nodes--;
                                return true;
                        }
                }

                return false;
        }  

        bool find(T data) {
            // TODO
            if(this->method == Move){
                    if(this->head == nullptr)
                            return false;

                    auto temp = this->head;
                    Node<T> *temp2 = this->head;

                    if(temp -> data == data)
                            return true;

                    int counter = 0;


                    while(temp->next != nullptr){
                            temp = temp->next;
                            if(temp->data == data){
                                    temp2->next = temp->next;
                                    temp->next = this->head->next;
                                    this->head = temp;
                                    return true;
                            }
                            temp2 = temp2->next;
                            temp2 = nullptr;
                            temp = nullptr;
                            delete temp;
                            delete temp2;
                    }
                    return false;
            }else if(this->method == Count){

                    auto temp = this->head;
                    Node<T> *temp_previo = nullptr;
                    auto temp2 = this->head;

                    if(temp -> data == data){
                            temp->count++;
                            return true;
                    }

                    while(temp->next != nullptr){
                            counter++;
                            temp = temp->next;
                            if(temp->data == data){
                                    temp->count++;
                                    for(int i = 0; i < counter; i++){
                                            if(temp2->count < temp->count){
                                                    temp_previo->next = temp->next;
                                                    temp->next = temp2;
                                                    if(temp2 == this->head){
                                                            this->head = temp;
                                                    }
                                            }
                                    }
                                    return true;
                            }else
                                    temp_previo = temp;
                    }

                    return false;

            }else if(this->method == Transpose){
                    if(this->head == nullptr)
                            return false;
                    auto temp = this->head;
                    Node<T> *temp_prev = nullptr;
                    // Qué es actual y eturn?? Este código no va a compilar
                    if(actual->data == data)
                            eturn true;

                    while(temp->next != nullptr){
                            temp = temp->next;
                            if(temp->data == data){
                                    if(temp == this->head->next){
                                            this->head = temp;
                                    }
                                    temp_prev->next = temp->next;
                                    temp->next = temp_prev;
                                    return true;
                            }
                            temp_prev = temp;
                    }
                    return false;
            }

        }

        T operator [] (int index) {
            // TODO
                if(index < 0 || index >= size()){
                        throw out_of_range("Error. index out of range!" );
                }
                Node<T>* temp = this->head;
                int i=0;
                while(true){
                        if(i == index){
                                return temp->data;
                        }
                        i++;
                        temp_node = temp->next;
                }
        }
             
        int size() {
            // TODO
            return this->nodes;
        }

        void print() {
                // TODO
                if(size() == 0) return;
                Node<T>* actual = this->head;
                while(actual){
                        cout << actual->data << " ";
                        actual = actual->next;
                }
                cout << "\n";
        }

        ~SelfList() {
            // TODO
        }  
};

#endif