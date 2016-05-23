// Chapter 1 - Arrays and Strings

#include<iostream>
#include<cstdlib>

// helpers

// Mergesort
// TODO implement mergesort for strings
void merge(std::string *str, int low, int middle, int high);
void mergesort(std::string *str, int low, int high) {
    int middle; /* index of middle element */

    if (low < high) {
        middle = (low+high)/2;
        mergesort(str, low, middle);
        mergesort(str, middle+1, high);
        merge(str, low, middle, high);
    }
}

void merge(std::string *str, int low, int middle, int high) {
    int i, j;                  /* counter */

    char *buffer1 = (char*) malloc(50);
    char *buffer2 = (char*) malloc(50); /* buffers to hold elements for merging */
    for (j=0; j<=middle-low; j++) {
        buffer1[j] = (*str)[low+j];
    }
    buffer1[j] = 0;
    for (j=0; j<=high-middle-1; j++) {
        buffer2[j] = (*str)[middle+1+j];
    }
    buffer2[j] = 0;

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
bool uniq2(std::string str) {
    mergesort(&str, 0, str.length());
    for(size_t i=1; i<str.length(); i++)
        if (str[i] == str[i-1]) return false;
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
// second implementation would be to sort both strings and compare them


/* 1.4 Write a method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end of the string to hold the additional
characters, and that you are given the "true" length of the string. (Note: if imple-
menting in Java, please use a character array so that you can perform this opera-
tion in place.)
EXAMPLE
Input:
"Mr John Smith  "
Output: "Mr%20John%20Smith"
*/

void replace_space(std::string *str, int len) {
    int i, spaces=0, j;
    for (i=0; i<len; i++) {
        if ((*str)[i] == ' ') {
            spaces++;
        }
    }
    j = len+2*spaces-1;
    for (i=len-1; i>=0; i--) {
        if ((*str)[i] == ' ') {
            (*str)[j--] = '0'; (*str)[j--] = '2'; (*str)[j--] = '%';
        }
        else {
            (*str)[j--] = (*str)[i];
        }
    }
}

/* 1.5 Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the orig-
inal string, your method should return the original string. */
//helpers
/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


std::string compress_string(std::string str) {
    std::string s ("");
    char buffer[11];
    int count=1;
    for (size_t i=1; i<str.size(); i++) {
        if (str[i] == str[i-1]) {
            count++;
            if (i==str.size()-1) {
                s += str[i];
                itoa(count, buffer);
                s += buffer;
            }
        } else {
            s += str[i-1];
            itoa(count, buffer);
            s += buffer;
            count=1;
        }
    }
    if (s.size() < str.size()) return s;
    return str;
}

int main() {
    std::cout << "Exercise 1.1" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << "Hello World!: " << uniq("Hello World!") << std::endl;
    std::cout << "Helo Wrd!: " << uniq("Helo Wrd!") << std::endl;
    std::cout << ": " << uniq("") << std::endl;
    std::cout << "Hello World!: " << uniq2("Hello World!") << std::endl;
    std::cout << "Helo Wrd!: " << uniq2("Helo Wrd!") << std::endl;
    std::cout << ": " << uniq2("") << std::endl;
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

    int n = 17;
    const char *s ="126456bdfgswigwwd";
    std::string strr ("126456bdfgswigwwd");
    std::cout << std::endl << std::endl;
    mergesort(&strr, 0, n-1);
    std::cout << "mergesort |" << s << "|:" << strr << std::endl;
    std::cout << "______________________________________" << std::endl;

    std::cout << "Exercise 1.4" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::string str14 ("Mr John Smith    ");
    n = 13;
    std::cout << "Replace: |" << str14 << "| - |";
    replace_space(&str14, n);
    std::cout << str14 << "|" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << "Exercise 1.5" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::string str15 ("aabcccccaaa");
    std::cout << "Compress: |" << str15 << "| - |" << compress_string(str15) << "|" << std::endl;
    std::cout << "Compress: |" << "abcd" << "| - |" << compress_string("abcd") << "|" << std::endl;
    std::cout << "Compress: |" << "" << "| - |" << compress_string("") << "|" << std::endl;
    std::cout << "Compress: |" << "aabbb" << "| - |" << compress_string("aabbb") << "|" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;
}
