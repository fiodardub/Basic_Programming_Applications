#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<initializer_list>
#include<fstream>

struct owner{
    short number;
    std::string name;
    double price;
    
    owner() = default;
    owner(short a, std::string b, double c)
    {
        number = a; name = b; price = c;
    }
    
    owner(const owner& rv){
        number = rv.number; name = rv.name; price = rv.price;
    }
    
    owner& operator=(const owner& rv){
        number = rv.number; name = rv.name; price = rv.price;
        return *this;
    }
    
    bool operator<(const owner& rv){
        if(name[0] < rv.name[0])
            return 1;
        return 0;
    }
    
    bool operator>(const owner& rv){
        if(name[0] > rv.name[0])
            return 1;
        return 0;
    }
    
};

inline std::ostream& operator<<(std::ostream& os , const owner& value){
    os << "User's number: " << value.number<< " " << "User's name: " << value.name << "Product's price: " << value.price;
    return os;
}

inline std::istream& operator>>(std::istream& is, owner& value){
    std::cout << "Input user's number: "; is >> value.number; std::cout <<std::endl;
    std::cout << "Input user's name: "; is >> value.name; std::cout <<std::endl;
    std::cout << "Input product's price: "; is >> value.price; std::cout <<std::endl;
    
    return is;
}


inline std::ifstream& operator>>(std::ifstream& fis, owner& value){
    fis >> value.number; fis >> value.name; fis >> value.price;
    return fis;
}

inline std::ofstream& operator<<(std::ofstream& os , const owner& value){
    os << "User's number: " << value.number<< " " << "User's name: " << value.name << "Product's price: " << value.price;
    return os;
}

struct Node {
    owner data;
    Node* next;
    Node(const owner& d, Node* n = nullptr) : data(d), next(n) {}
};

class list{
private:
    Node* head = nullptr;
    size_t size = 0;
    
public:
    list() = default;
    list(std::initializer_list<owner>);
    size_t get_size();
    size_t get_size() const ;
    list(const list&);
    void push_back(const owner&);
    owner& operator[](size_t);
    owner& operator[](size_t) const;
    void pop_back();
    void pop_front();
    void push_front(const owner& );
    void pop_index(size_t);
    void push_index(size_t , const owner&);
    friend std::ostream& operator<<(std::ostream& , const list&);
    friend std::ofstream& operator<<(std::ofstream&, const list&);
    friend std::ifstream& operator>>(std::ifstream& , list&);
    friend std::istream& operator>>(std::istream& , list& );
    void AddFromFile(std::ifstream&);
    void Sort();
    void clear();
};
