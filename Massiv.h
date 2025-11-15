#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <initializer_list>


struct Element1
{
    std::string Name;
    size_t Count;
    std::string Addr;
    
    Element1() = default;
    Element1(std::string a, size_t b , std::string c){
        Name = a;
        Count = b;
        Addr = c;
    }
    
    Element1(const Element1& rv){
        Name = rv.Name;
        Count = rv.Count;
        Addr = rv.Addr;
    }
    
    ~Element1() = default;
    
    Element1& operator=(const Element1& rv){
        Name = rv.Name; Count = rv.Count; Addr = rv.Addr;
        return *this;
    }
    
    bool operator<( const Element1& rv) const {
        return Count < rv.Count;
    }
    bool operator==(const Element1& other) const{
        return Name == other.Name && Count == other.Count && Addr == other.Addr;
    }
    bool operator<=(const Element1& other){
        return Count <= other.Count;
    }
    
    bool operator>=(const Element1& other){
        return Count >= other.Count;
    }
    
    
};

std::ostream& operator<<(std::ostream& os , const Element1& other){
    os << other.Name << " " << other.Count << " " << other.Addr << ".";
    return os;
}

std::istream& operator>>(std::istream& is , Element1& other){
    std::cout << "Input student's name: "; is >> other.Name;
    std::cout << std::endl << "Input amount of books taken: "; is >> other.Count;
    std::cout << std::endl << "Input student's adress: "; is >> other.Addr;

    return is;
}

std::ifstream& operator>>(std::ifstream& is, Element1& other){
    is >> other.Name >> other.Count >> other.Addr;
    return is;
}

struct Element2
{
    std::string Name;
    std::string Addr;
    
    Element2() = default;
    
    Element2(std::string a, std::string c){
        Name = a;
        Addr = c;
    }
    
    Element2(const Element2& rv){
        Name = rv.Name;
        Addr = rv.Addr;
    }
    
    ~Element2() = default;
    
    Element2& operator=(const Element2& rv){
        this -> Name = rv.Name;
        this -> Addr = rv.Addr;
        return *this;
    }
    
    bool operator<(const Element2& rv){
        return Addr[0] < rv.Addr[0];
    }
    
    //bool operator<( const Element2& rv) const {
        //return Count < rv.Count;
    //}
    bool operator==(const Element2& other) const{
        return Name == other.Name && Addr == other.Addr;
    }
};

std::ostream& operator<<(std::ostream& os , const Element2& other){
    os << other.Name << " " << other.Addr << ".";
    return os;
}

std::istream& operator>>(std::istream& is , Element2& other){
    std::cout << std::endl <<"Input student's name: "; is >> other.Name;
    std::cout << std::endl << "Input student's adress: "; is >> other.Addr;

    return is;
}

std::ifstream& operator>>(std::ifstream& is, Element2& other){
    is >> other.Name >> other.Addr;
    return is;
}

struct Element3
{
    std::string Name;
    std::string Addr;
    double Price;
    size_t Count;
    
    Element3() : Name("None") , Addr("None") , Price(0) , Count(0) {};
    
    Element3(std::string a, size_t b , std::string c , double d){
        Name = a;
        Count = b;
        Addr = c;
        Price = d;
    }
    
    Element3 (const Element3& rv){
        this -> Name = rv.Name;
        this -> Count = rv.Count;
        this ->Addr = rv.Addr;
        this -> Price = rv.Price;
    }
    
    ~Element3() = default;
    
    Element3& operator=(const Element3& rv){
        this -> Name = rv.Name;this -> Count = rv.Count;this-> Price = rv.Price;this-> Addr = rv.Addr;
        return *this;
    }
    
    bool operator<( const Element3& rv) const {
        return Count < rv.Count;
    }
    bool operator==(const Element3& other) const{
        return Name == other.Name && Count == other.Count && Addr == other.Addr && Price == other.Price;
    }
    
    Element3& operator=(const Element1& src){
        this->Name = src.Name;
        this->Addr = src.Addr;
        this->Price = 0;
        this->Count = src.Count;
        return *this;
    }
    
};

std::ostream& operator<<(std::ostream& os , const Element3& other){
    os << other.Name << " " << other.Count << " " << other.Price << " " << other.Addr << ".";
    return os;
}

std::istream& operator>>(std::istream& is , Element3& other){
    std::cout << "Input student's name: "; is >> other.Name;
    std::cout << std::endl << "Input amount of books taken: "; is >> other.Count;
    std::cout << std::endl << "Input prices of all books: "; is >> other.Price;
    std::cout << std::endl << "Input student's adress: "; is >> other.Addr;

    return is;
}

std::ifstream& operator>>(std::ifstream& is, Element3& other){
    is >> other.Name >> other.Count >> other.Price >> other.Addr;
    return is;
}

bool operator==(const Element1& lv_1 , const Element2& rv){
    return lv_1.Name == rv.Name && lv_1.Addr == rv.Addr;
}

template <typename T>
class Massiv{
private:
    size_t amount;
    T* arr;
public:
    Massiv() : arr(nullptr) , amount(0) {};
    Massiv(size_t );
    Massiv(std::initializer_list<T> other){
        amount = other.size();
        arr = new T[amount];
        size_t i{};
        for(const auto& x : other){
            arr[i] = x;
            ++i;
        }
    }
    Massiv(const Massiv<T>& other){
        amount = other.amount;
        arr = new T[amount];
        for(size_t i{}; i < amount; ++i){
            arr[i] = other.arr[i];
        }
    }
    
    size_t get_size(){
        return amount;
    }
    
    size_t get_size() const{
        return amount;
    }
    
    void push_back(const T& arg){
        T* temp = new T[amount + 1];
        for(size_t i{}; i < amount; ++i){
            temp[i] = arr[i];
        }
        temp[amount] = arg;
        delete[] arr;
        arr = new T[amount + 1];
        for(size_t i{}; i < amount+1; ++i){
            arr[i] = temp[i];
        }
        ++amount;
        delete[] temp;
    }
    friend std::ostream& operator<<(std::ostream& os, const Massiv<T>& other){
        for(size_t i{}; i < other.amount; ++i){
            os << other.arr[i] << " ";
        }
        return os;
    }
    
    template <typename U>
    friend std::istream& operator>>(std::istream& , Massiv<U>& );
    
    void WriteTextData(char* s){
        std::ofstream out(s);
        if(!out.is_open()){
            std::cout << "Cannot write into this file.\n";
        }
        size_t i{};
        while(i < amount){
            out << arr[i] << " ";
            ++i;
        }
        
        out.close();
    }
    
    void ReadTextData(std::ifstream& fin){
        if(!fin.is_open()){
            std::cout << " Cannot read from this file.\n";
        }
        T* temp =  new T[100];
        size_t i{};
        while(fin >> temp[i]){
            ++i;
        }
        
        amount = i;
        arr = new T[amount];
        for(size_t j{}; j < amount; ++j){
            arr[j] = temp[j];
        }
        delete[] temp;
        fin.close();
        
    }
    
    ~Massiv(){
        if((*this).get_size() != 0)
            delete[] arr;
    }
    
    void WriteBinary(const std::string& filename) {
            std::ofstream out(filename, std::ios::binary);
            if (!out.is_open()) {
                std::cerr << "Error: Could not open file for writing.\n";
                return;
            }

            out.write(reinterpret_cast<char*>(&amount), sizeof(amount));

            if (amount > 0 && arr != nullptr) {
                out.write(reinterpret_cast<char*>(arr), sizeof(T) * amount);
            }

            out.close();
        }
    
    void ReadBinary(const std::string& filename) {
            std::ifstream in(filename, std::ios::binary);
            if (!in.is_open()) {
                std::cerr << "Error: Could not open file for reading.\n";
                return;
            }

            delete[] arr;
            arr = nullptr;
            amount = 0;

            in.read(reinterpret_cast<char*>(&amount), sizeof(amount));

            if (amount > 0) {
                arr = new T[amount];
                in.read(reinterpret_cast<char*>(arr), sizeof(T) * amount);
            }

            in.close();
        }
    
    Massiv operator=(const Massiv& other){
        amount = other.amount;
        arr = new T[amount];
        for(size_t i{}; i < amount; ++i){
            arr[i] = other.arr[i];
        }
        return *this;
    }
    
    T& operator[](size_t i){
        return arr[i];
    }
    
    T& operator[](size_t i) const {
        return arr[i];
    }
    
    template <typename T1, typename T2, typename T3>
    Massiv<T3> Substraction( Massiv<T1>& arr1, Massiv<T2>& arr2){
        Massiv<T3> temp;
        for (size_t i{}; i < arr1.get_size(); ++i) {
            bool found = false;
            
            for (size_t j{}; j < arr2.get_size(); ++j) {
                if (arr1[i] == arr2[j]) {
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                T3 newElement;
                
                newElement = arr1[i];
                
                temp.push_back(newElement);
            }
        }
        return temp;
    }
    
    size_t FindStuds(T);
    
    size_t FindStuds(size_t);
    
    void Sort();
    
    template <typename U>
    void WriteData(char* s)
    {
        std::fstream out;
        out.open(s, std::ofstream::out | std::ofstream::binary); if (!out.is_open())
        {
            std::cout << "Open file failed.\n";
        }
        else
        {
            int ind_z;
            std::cin>> ind_z;
            
            int i = 0;
            int k = 0;
            out.seekp(k, std::ios::end);
            while (i < amount)
            {
                out.write((char*)&arr[i], sizeof(T));
                i++;
            }
            out.write((char*)&arr, sizeof(arr));
            out.close();
        }
    }
};
template<typename T>
Massiv<T>::Massiv(size_t a){
    delete[] arr;
    amount = a;
    T* arr = new T[a];
}

template <typename T>
std::istream& operator>>(std::istream& is, Massiv<T>& other){
    size_t n;
    std::cout << "How many elements do u want to fill in: "; std::cin >> n;
    other.arr = new T[n];
    other.amount = n;
    for(size_t i{}; i < other.amount; ++i){
        std::cout << "Input element: "; is >> other.arr[i]; std::cout << std::endl;
    }
    return is;
}

template <typename F>
size_t Massiv<F>::FindStuds( F k){
    size_t f{};
    for(size_t i{}; i < (*this).amount; ++i){
        if((*this).arr[i]  ==  k){
            ++f;
        }
    }
    return f;
}
    
template <>
size_t Massiv<Element1>::FindStuds( size_t k){
    size_t f{};
    for(size_t i{}; i < (*this).amount; ++i){
        if((*this).arr[i].Count  >=  k){
            std::cout << arr[i] <<std::endl;
            ++f;
        }
    }
    return f;
}

template<typename U>
void Massiv<U>::Sort(){
    for(size_t i{}; i < (*this).amount - 1;++i){
        size_t min_index = i;
        for(size_t j = i + 1; j < (*this).amount; ++j){
            if((*this).arr[j] < (*this).arr[min_index]){
                min_index = j;
            }
        }
        std::swap((*this).arr[i], (*this).arr[min_index]);
    }
}

