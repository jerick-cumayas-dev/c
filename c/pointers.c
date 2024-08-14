#include <stdio.h>

int main() {
  int number = 100;
  int *intPointer = &number;
  int **ptr = &intPointer;
  int ***ptrr = &ptr;
  printf("number: %d\n", number);
  printf("&number: %p\n", &number);
  printf("intpointer: %p\n", intPointer);
  printf("&intpointer: %p\n", &intPointer);
  printf("ptr: %p\n", ptr);
  printf("*ptr: %p\n", *ptr);
  printf("**ptr: %d\n", **ptr);
  printf("\n&ptr: %p\n", &ptr);
  printf("&ptrr: %p\n", &ptrr);
  printf("ptrr: %p\n", ptrr);
  printf("*ptrr: %p\n", *ptrr);
  printf("**ptrr: %p\n", **ptrr);
  printf("***ptrr: %d\n", ***ptrr);

  return 0;
}
