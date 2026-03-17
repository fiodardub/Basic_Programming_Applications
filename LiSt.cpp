#include<iostream>
#include<initializer_list>
#include<fstream>
#include "LiSt.h"

list::list(std::initializer_list<owner> lv){
    for (const auto& item : lv) {
                push_back(item);
            }
}

size_t list::get_size(){
    return size;
}

size_t list::get_size() const{
    return size;
}

list::list(const list& other){
    Node* temp = other.head;
            while (temp) {
                push_back(temp->data);
                temp = temp->next;
        }
    }

owner& list::operator[](size_t index) {
        Node* temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->next;
        return temp->data;
    }

owner& list::operator[](size_t index) const {
    Node* temp = head;
    for (size_t i = 0; i < index; ++i) temp = temp->next;
    return temp->data;
}

void list::push_back(const owner& val) {
        if (!head) {
            head = new Node(val);
                }
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = new Node(val);
        }
        size++;
    }


void list::push_front(const owner& val) {
        head = new Node(val, head);
        size++;
    }

void list::push_index(size_t index, const owner& val) {
        --index;
        if (index == 0) return push_front(val);
        if (index >= size) return push_back(val);

        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) temp = temp->next;
        temp->next = new Node(val, temp->next);
        size++;
    }

void list::pop_back() {
        if (!head) return;
        if (!head->next) return pop_front();

        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        size--;
    }

void list::pop_front() {
        if (!head) return;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
    }

void list::pop_index(size_t index) {
        --index;
        if (index == 0) return pop_front();
        if (index >= size) return;

        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) temp = temp->next;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        size--;
    }


std::ostream& operator<<(std::ostream& os , const list& item){
    for(size_t i{}; i < item.get_size(); ++i){
        os << item[i] << std::endl;
    }
    return os;
}

std::ofstream& operator<<(std::ofstream& fos , const list& item){
    for(size_t i{}; i < item.get_size(); ++i){
        fos << item[i] << std::endl;
    }
    return fos;
}

std::ifstream& operator>>(std::ifstream& is, list& item) {
    if (!is.is_open()) {
        std::cerr << "Cannot read from this file.\n";
        return is;
    }

    item.clear(); 

    owner temp_val;
    while (is >> temp_val) {
        item.push_back(temp_val);
    }

    return is;
}


std::istream& operator>>(std::istream& is, list& item) {
    size_t count;
    std::cout << "How many elements: ";
    if (!(is >> count)) return is;

    item.clear();

    for (size_t i = 0; i < count; ++i) {
        owner temp_val;
        std::cout << "Input " << (i + 1) << " element: ";
        if (is >> temp_val) {
            item.push_back(temp_val);         }
        std::cout << std::endl;
    }
    return is;
}

void list::AddFromFile(std::ifstream& ifs) {
        owner val;
        while (ifs >> val) push_back(val);
    }


void list::Sort() {
        if (!head || !head->next) return;
        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data)
                    std::swap(i->data, j->data);
            }
        }
    }

void list::clear(){
    while (head) pop_front();
}
