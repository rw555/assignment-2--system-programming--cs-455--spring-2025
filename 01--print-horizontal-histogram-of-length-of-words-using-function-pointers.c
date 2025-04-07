# include <stdio.h>

#define SIZE 10

void swap(int* firstPtr, int* secondPtr);
void ascending(int * const array, const int ARRAY_BOUNDS);
void descending(int * const array, const int ARRAY_BOUNDS);
void bubbleSort(void (*functionChoice) (int * const array, const int ARRAY_BOUNDS), int * const array, const int ARRAY_BOUNDS);

int main() {
  int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
  int selection = -1; // variable to store the user's selection for descending or ascending

  // If the selection is neither 1 nor 2, the user will be prompted again
  while (selection != '1' && selection != '2') {
    printf("\nEnter 1 to sort in ascending order,\nEnter 2 to sort in descending order: ");
    selection = getchar();
  }

  printf("\nData items in original order\n");

  // print each item in the array
  for (int i = 0; i < SIZE; i++) {
    printf("%4d", a[i]);
  }

  // call bubbleSort with function decided by prior user input
  switch (selection)
  {
    case '1':
      bubbleSort(ascending, a, SIZE);
    break;

    case '2':
      bubbleSort(descending, a, SIZE);
    break;
  }

  return 0;
}

void swap(int* firstPtr, int* secondPtr) {
  const int TEMP_HOLDER = *firstPtr;

  *firstPtr = *secondPtr;
  *secondPtr = TEMP_HOLDER;
}

void ascending(int * const array, const int ARRAY_BOUNDS) {

  // ascending bubble sort algorithm
  for (int i = 0; i < ARRAY_BOUNDS - 1; i++) {

    for (int j = 0; j < ARRAY_BOUNDS - 1; j++) {

      if (array[j] > array[j+1]) {
        swap(&array[j], &array[j+1]);
      }
    }
  }

  printf("\nData items in ascending order\n");

  // print each item in the array
  for (int i = 0; i < ARRAY_BOUNDS; i++) {
    printf("%4d", array[i]);
  }
}

void descending(int * const array, const int ARRAY_BOUNDS) {

  // descending bubble sort algorithm
  for (int i = 0; i < ARRAY_BOUNDS - 1; i++) {

    for (int j = 0; j < ARRAY_BOUNDS - 1; j++) {

      if (array[j] < array[j+1]) {
        swap(&array[j], &array[j+1]);
      }
    }
  }

  printf("\nData items in descending order\n");

  // print each item in the array
  for (int i = 0; i < ARRAY_BOUNDS; i++) {
    printf("%4d", array[i]);
  }
}

void bubbleSort(void (*functionChoice) (int * const array, const int ARRAY_BOUNDS), int * const array, const int ARRAY_BOUNDS) {
  (functionChoice)(array, ARRAY_BOUNDS);
}
