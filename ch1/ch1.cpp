// Chapter 1 - Arrays and Strings

#include<iostream>
#include<cstdlib>

// helpers

// Mergesort
// TODO implement mergesort for strings
void merge(char **str, int low, int middle, int high);
void mergesort(char **str, int low, int high) {
    int middle; /* index of middle element */

    if (low < high) {
        middle = (low+high)/2;
        mergesort(str, low, middle);
        mergesort(str, middle+1, high);
        merge(str, low, middle, high);
    }
}

void merge(char **str, int low, int middle, int high) {
    int i, j;                  /* counter */
   
    std::cout << "low: " << low << std::endl;  
    std::cout << "middle: " << low << std::endl;  
    std::cout << "high: " << low << std::endl;  
    
    char *buffer1 = (char*) malloc(50);
    char *buffer2 = (char*) malloc(50); /* buffers to hold elements for merging */ 
    for (j=0; j<middle-low+1; j++) buffer1[j] = *str[low+j];
    buffer1[j] = 0;
    for (j=0; j<high-middle; j++) buffer2[j] = *str[middle+j];
    buffer2[j] = 0;

    std::cout << buffer1 << std::endl;
    std::cout << buffer2 << std::endl;
    std::cout << *str << std::endl;

    i = low;
    while (*buffer1 && *buffer2) {
        if (*buffer1 < *buffer2) {
            (*str)[i++] = *(buffer1++);
        } else {
            (*str)[i++] = *(buffer2++);
        }

    }

    while (*buffer1) (*str)[i++] = *(buffer1++);
    while (*buffer2) (*str)[i++] = *(buffer2++);
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

    int i, n = 6;
    const char *s ="126456";
    char *str = (char*) malloc(100);
    for (i=0;i<n;i++) {
        str[i] = s[i];
    }
    str[i] = 0;
    std::cout << std::endl << std::endl;
    mergesort(&str, 0, 5);
    std::cout << "mergesort |" << s << "|:" << str; 
    /*const char s1 = "cdagfdfg";
    std::cout << "mergesort |" << s1 << "|:"; 
    mergesort(&s1, 0, 8);
    std::cout << s1 << std::endl;*/
    //std::cout << "Strings |123456| and |353416|: " << is_permutation("123456", "353416") << std::endl;
    //std::cout << "Strings |123456| and |353416|: " << is_permutation("123456", "353416") << std::endl;
    //std::cout << "Strings |123456| and |353416|: " << is_permutation("123456", "353416") << std::endl;
    std::cout << "______________________________________" << std::endl;
}
