//
// Created by ybkuanysh on 2025/03/16.
//
#include <stdio.h>
#include <string.h>

int main() {
  char text[] = "Lorem ipsum odor amet, consectetuer adipiscing elit. Diam nam velit ante cubilia vel natoque pulvinar magnis. Quam platea libero congue dis risus proin urna enim. Parturient finibus faucibus augue placerat, vehicula leo. Ac conubia augue finibus massa torquent metus luctus arcu. Ac dictum imperdiet cras mi sodales accumsan.";
  const int MAX_LENGTH = 5;

  int counter = 0;
  char last_word[100];

  for (int i = 0; i < strlen(text); i++) {
    while (text[i] != ' ') {
      last_word[counter] = text[i];
      counter++;
      i++;
    }
    last_word[counter] = '\0';
    if (counter <= MAX_LENGTH) printf("%s ",last_word);
    last_word[0] = '\0';
    counter = 0;
  }
  return 0;
}
