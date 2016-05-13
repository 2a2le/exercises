// Chapter 1 - Arrays and Strings

#include<iostream>


// 1.1 Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?
bool uniq(std::string str) {
    for(size_t i=1; i<str.length(); i++) 
        for(size_t j=0; j<i; j++) 
            if (str[i] == str[j]) return false;
    return true;
}


int main() {
    std::cout << "Exercise 1.1" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << "Hello World!: " << uniq("Hello World!") << std::endl;
    std::cout << "Helo Wrd!: " << uniq("Helo Wrd!") << std::endl;
    std::cout << ": " << uniq("") << std::endl;
    std::cout << "______________________________________" << std::endl;
}
