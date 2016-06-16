// Chapter 1 - Arrays and Strings

#include<iostream>
#include<cstdlib>


#define M 10
#define N 7
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

/*
bool isUniqueChars(std::string str) {
  int checker;
  for (int i=0; i < str.length(); i++) {
    int val = str[i] - 'a';
    if (((checker & (1 << val)) > 0) {
      return false;
    }
}
}
*/   


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

void reverse2(char* str) {
  char *end = str;
  char tmp;
  if (str) {
    while (*end) { /* find end of the string */
      ++end;
    }
    --end; /* set one char back, since last char is null */

    /* swap characters from start of string with the end of the  
     * string, until the pointers meet in middle.  */
    while (str < end) {
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
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


/* 1.6 Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/

void rotate_image(int image[][N], int n) {
    int tmp;
    for (int i=0; i<n/2; i++)
        for (int j=i; j<n-i-1; j++) {
            tmp = image[n-j-1][i];
            image[n-j-1][i] = image[n-i-1][n-j-1];
            image[n-i-1][n-j-1] = image[j][n-i-1];
            image[j][n-i-1] = image[i][j];
            image[i][j] = tmp;
        }
}

void print_matrix(int a[][N], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            std::cout << a[i][j] << "  ";
        std::cout << std::endl;
    }
}


/* 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0.
*/

void zero_matrix(int a[M][N]) {
    int ii[M], jj[N], iin=0, jjn=0;
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            if (a[i][j] == 0) {
                ii[iin++] = i;
                jj[jjn++] = j;
            }
    for (int i=0; i<iin; i++)
        for (int j=0; j<N; j++)
            a[ii[i]][j] = 0;
    for (int j=0; j<jjn; j++)
        for (int i=0; i<M; i++)
            a[i][jj[j]] = 0;
}

/* 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0.
*/
bool isSubstring(std::string s1, std::string s2) {
  return (s1.find(s2) != std::string::npos);
}

bool isRotation(std::string s1, std::string s2) {
  unsigned int len = s1.length();
  /* check if s1 and s2 have the same length and are not empty */
  if (len == s2.length() && len > 0) {
    std::string s1s1 = s1 + s1;
    return isSubstring(s1s1, s2);
  }
  return false;
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
    char str1[] = "a"; reverse2(str1);
    std::cout << "a: " << str1 << std::endl;
    char str2[] = "abcd"; reverse2(str2);
    std::cout << "abcd: " << str2 << std::endl;
    char str3[] = "abcde"; reverse2(str3);
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


    std::cout << "Exercise 1.6" << std::endl;
    std::cout << "______________________________________" << std::endl;
    n = N;
    int img[N][N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            img[i][j] = n*i+j;

    std::cout << "Original:" << std::endl;
    print_matrix(img, n, n);
    rotate_image(img, n);
    std::cout << "Rotated:" << std::endl;
    print_matrix(img, n, n);
    
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << "Exercise 1.7" << std::endl;
    std::cout << "______________________________________" << std::endl;
    n = N;
    int matrix[M][N];
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            matrix[i][j] = 1;
    matrix[3][4] = 0; matrix[6][6] = 0; matrix[9][2] = 0;
    matrix[5][5] = 0;

    std::cout << "Original:" << std::endl;
    print_matrix(matrix, M, N);
    zero_matrix(matrix);
    std::cout << "Zeroed:" << std::endl;
    print_matrix(matrix, M, N);
    
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Exercise 1.8" << std::endl;
    std::cout << "______________________________________" << std::endl;
    std::string s1 ("waterbottle");
    std::string s2 ("erbottlewat");
    std::string s3 ("erbotllewat");
    std::cout << "isRotation(" << s1 << ", " << s2 << "): " << isRotation(s1,s2) << std::endl;
    std::cout << "isRotation(" << s1 << ", " << s3 << "): " << isRotation(s1,s3) << std::endl;
    
    std::cout << "______________________________________" << std::endl;
    std::cout << std::endl << std::endl;
}
