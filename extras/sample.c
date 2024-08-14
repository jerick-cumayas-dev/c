#include <stdio.h>
#include <stdlib.h>

int main() {
  char *input = NULL;
  size_t len = 10;

  input = (char *)malloc(len * sizeof(char));

  printf("Enter some text: ");
  scanf_s("%s", input);

  printf("Text inputted: %s", input);

  free(input);
  return 0;
}
