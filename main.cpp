#include <iostream>
#include <string>
#include <fstream>
#include "Massiv.h"

int main() {
    Massiv<Element2> for_file;
    std::ifstream fin("/Users/h/dssdsdsdsd/dssdsdsdsd/second_file.txt");
    for_file.ReadTextData(fin);
    std::cout << "Second elements read from file: " << for_file <<std::endl <<std::endl;
    Massiv<double> double_arr = {2.4 , 3.4 , 1.45 , 0 , 1.45};
    Massiv<double> double_arr2 = { 3.4 , 1.45 , 3.67 ,0};
    std::cout << double_arr << std::endl << double_arr2 <<std::endl;
    std::cout << "double_arr[1]: " << double_arr[1] << std::endl;
    std::cout << "double_arr.FindStuds(1.45): " <<double_arr.FindStuds(1.45) << std::endl <<std::endl;
    double_arr.Sort();
    std::cout << double_arr << std::endl << std::endl;
    Massiv<double> double_arr3;
    std::cout << double_arr3.Substraction<double , double , double>(double_arr, double_arr2) << std::endl;
    Massiv<Element2> second;
    second.push_back({"Masha" ,"Mogilev"});
    second.push_back({"Misha", "Brest"});
    second.push_back({"Dima" , "Rome"});
    second.push_back({"Lena" , "Warsaw"});
    second.Sort();
    std::cout <<"Sorted array of second elements: " <<second << std::endl << std::endl;
    Massiv<Element1> first;
    first.push_back({"Masha" , 23 , "Mogilev"});
    first.push_back({"Katya" , 12 , "Pinsk"});
    first.push_back({"Misha" , 13 , "Brest"});
    first.push_back({"MIsha" , 2, "aaa"});
    std::cout << "First element array: " << first <<std::endl;
    std::cout << "First with amount of 12 or more: "<< first.FindStuds(13) << std::endl << std::endl;
    Massiv<Element3> third = {{"Misha" , 13 , "Brest" , 23.5},{"Katya" , 12 , "Pinsk", 12.3} , { "Andrey" , 23 ,"Moscow" , 5.05} };
    std::cout << "Third element array: " << third << std::endl;
    Massiv<Element3> third_final;
    std::cout <<"Third function output: " <<third_final.Substraction<Element1, Element2, Element3>(first , second) << std::endl << std::endl;;
    std::ofstream out("output.txt" );
    out << third;
    system("open output.txt");
    
    third.WriteBinary("binary.txt");
    
    return 0;
}


GIT_AUTHOR_DATE="2025-11-15T14:27:19" GIT_COMMITTER_DATE="2025-11-15T14:27:19" git commit -m "feat: add basic Qt application"
