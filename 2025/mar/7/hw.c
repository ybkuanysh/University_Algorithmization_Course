//
// Created by ybkuanysh on 2025/03/13.
//
#include <stdio.h>
#include <string.h>

int main() {

  printf("9.16: ");
  {
    char str[] = "Word";
    if (str[1] == str[3]) printf("Second and fourth elements of string are equal\n");
    else printf("Second and fourth elements of string are different\n");
  }

  printf("9.17: ");
  {
    char str[] = "Word";
    if (str[0] == str[strlen(str)-1]) printf("yes\n");
    else printf("no\n");
  }

  printf("9.18: ");
  {
    char word1[] = "Word";
    char word2[] = "Something";
    if (word1[0] == word2[strlen(word2)-1]) printf("yes\n");
    else printf("no\n");
  }

  printf("9.19: ");
  {
    char word[] = "Word";
    printf("%c%c\n", word[1], word[3]);
  }

  printf("9.20: ");
  {
    char word[] = "Word";
    printf("%c%c\n", word[2], word[strlen(word)-1]);
  }

  printf("9.21: ");
  {
    char word[] = "Word";
    for (int i = 1; i < 4; i++) {
      printf("%c", word[i]);
    }
    printf("\n");
  }

  printf("9.22: ");
  {
    char word2[] = "abcdefghijklmnopqrst";
    char word[strlen(word2)/2+1];
    strncpy(word, word2, strlen(word2)/2);
    word[strlen(word2)/2] = '\0';
    printf("%s\n", word);
  }


  printf("Glazunova p108 ex15: \n");
  { // Глазунова стр. 108 задача 15
    char str[] = ":H:e:l:l:o :W:o:r:l:d";
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
      if (str[i] != ':') {
        str[i-count] = str[i];
      }
      else {count++;}
    }

    if (count != 0) {
      str[strlen(str) - count] = '\0';
    }

    printf("  String after: %s\n", str);
    printf("  String length: %zu\n", strlen(str));
    printf("  Found (:) %d\n", count);
  }
  return 0;
}
