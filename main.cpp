#include <string>
#include <iostream>
#include <set.hpp>

int main(){

    mycontainer::set myset;

    myset.add(std::string("Some data"));

    // check some data 
    std::cout << (myset.contains(std::string("Some data")) ? "yes" : "no") << std::endl; 
    std::cout << (myset.contains(std::string("some data")) ? "yes" : "no") << std::endl;

    std::cout << (myset.remove(std::string("Some data")) ? "contained" : "did not contain") << std::endl; 
    std::cout << (myset.remove(std::string("some data")) ? "contained" : "did not contain") << std::endl;
    return 0;
}