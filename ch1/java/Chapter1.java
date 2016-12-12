//Alex Branciog

import java.util.*;

public class Chapter1 {

public static void checkIsUniq(String str) {
  System.out.println("isUniqueChars(" + str + "): "
                     + isUniqueChars(str));
}

public static boolean isUniqueChars(String str) {
  if (str.length() > 128) return false;
  
  boolean chars[] = new boolean[128];
  for(int i = 0; i < str.length(); i++) {
    int val = str.charAt(i);
    if (chars[val]) return false;
    chars[val] = true;
  }
  return true;
}

public static boolean isUnique(String str) {
  HashMap<Character, Integer> map = new HashMap<>();
  for(char c: str.toCharArray()) {
    if (map.containsKey(c)) return false;
    map.put(c, 1);
  }
  return true;
}

public static boolean isPermutation(String str1, String str2) {
  if (str1.length() != str2.length()) return false;
  int[] letters = new int[128];

  char[] str1_array = str1.toCharArray();
  for(char c: str1_array) {
    letters[c]++;
  }

  for(char c: str2.toCharArray()) {
    letters[c]--;
    if (letters[c] < 0) return false;
  }

  return true;
}

public static int getCharNumber(char c) {
  return (int)c;
}

public static boolean isPermutationOfPalindrome(String phrase) {
  int bitVector = createBitVector(phrase);
  return bitVector == 0 || checkExactlyOneBitSet(bitVector); 
}

public static int createBitVector(String phrase) {
  int bitVector = 0;
  for (char c: phrase.toCharArray()) {
    int x = getCharNumber(c);
    bitVector = toggle(bitVector, x);
  }
  return bitVector;
}

public static int toggle(int bitVector, int index) {
  if (index < 0) return bitVector;
  int mask = 1<<index;
  if ((bitVector & mask) == 0) {
    bitVector |= mask;
  } else {
    bitVector &= ~mask;
  }
  return bitVector;
}

public static boolean checkExactlyOneBitSet(int bitVector) {
  return ((bitVector - 1) & bitVector) == 0;
}




public static void main(String[] args) {
  System.out.println("HashTables, Arrays and Strings");

  System.out.println("");
  System.out.println("");

  checkIsUniq("abcdefg");
  checkIsUniq("abcdefg4esd");
  checkIsUniq("");

  System.out.println(getCharNumber('0'));
}

}
