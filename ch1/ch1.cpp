// Chapter 1 - Arrays and Strings

#include<iostream>

// helpers

// Mergesort
// TODO implement mergesort for strings
void merge(std::string str, int low, int middle, int high);
void mergesort(std::string str, int low, int high) {
    int middle; /* index of middle element */

    if (low < high) {
        middle = (low+high)/2;
        mergesort(str, low, middle);
        mergesort(str, middle+1, high);
        merge(str, low, middle, high);
    }
}

void merge(std::string str, int low, int middle, int high) {
    //int i;                  /* counter */
    //std::queue buffer1, buffer2; /* buffers to hold elements for merging */ 

    //init_queue(&buffer1);
    //init_queue(&buffer2);
}
    


// 1.1 Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?
bool uniq(std::string str) {
    for(size_t i=1; i<str.length(); i++) 
        for(size_t j=0; j<i; j++) 
            if (str[i] == str[j]) return false;
    return true;
}

// 1.2 Implement a function void reverse(char* str) in C or C++ which reverses a null-
// terminated string.
void reverse(char* str) {
    size_t len, i;
    char tmp;
    for(i=0;;i++)
        if (str[i] == '\0') {
            len = i;
            break;
        }
    for(i=0; i<len/2; i++) {
        tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
}

// 1.3 Given two strings, write a method to decide if one is a permutation of the other.

bool is_permutation(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) return false;
    size_t i,j,len;
    for(i=0; i<str1.length(); i++) {
        len = str2.length();
        for(j=0; j<len; j++) {
            if (str1[i] == str2[j]) {
                str2.erase(j,1);
                break;
            }
        }
        if (j == len) return false;
    }
    return true;
}

int main() {
    std::cout << "Exercise 1.1" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << "Hello World!: " << uniq("Hello World!") << std::endl;
    std::cout << "Helo Wrd!: " << uniq("Helo Wrd!") << std::endl;
    std::cout << ": " << uniq("") << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Exercise 1.2" << std::endl;
    std::cout << "______________________________________" << std::endl;
    char str1[] = "a"; reverse(str1);
    std::cout << "a: " << str1 << std::endl;
    char str2[] = "abcd"; reverse(str2);
    std::cout << "abcd: " << str2 << std::endl;
    char str3[] = "abcde"; reverse(str3);
    std::cout << "abcde: " << str3 << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Exercise 1.3" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << "Strings |unu| and |unu|: " << is_permutation("unu", "unu") << std::endl;
    std::cout << "Strings |unu| and |uun|: " << is_permutation("unu", "uun") << std::endl;
    std::cout << "Strings |unu| and |una|: " << is_permutation("unu", "una") << std::endl;
    std::cout << "Strings |123456| and |352416|: " << is_permutation("123456", "352416") << std::endl;
    std::cout << "Strings |123456| and |353416|: " << is_permutation("123456", "353416") << std::endl;
    std::cout << "______________________________________" << std::endl;
}
