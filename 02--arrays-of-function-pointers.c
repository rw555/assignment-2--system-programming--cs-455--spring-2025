#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

void minimum(int studentGrades[][EXAMS], size_t students, size_t exams);
void maximum(int studentGrades[][EXAMS], size_t students, size_t exams);
void average(int studentGrades[][EXAMS], size_t students, size_t exams);
void printArray(int studentGrades[][EXAMS], size_t students, size_t exams);

int main() {
  int studentGrades[STUDENTS][EXAMS] = {
    {77, 68, 86, 73},
    {96, 87, 89, 78},
    {70, 90, 86, 81}};
  void (*processGrades[4])(int [][EXAMS], size_t, size_t) =
    {printArray, minimum, maximum, average};
  int selection = -1; // variable to hold the user's selection

  while (selection != 4) {
    /*
    * Take in a selection and call the associated function
    * by using the array index. Only do something if
    * within the bounds of the array. Otherwise, exit
    */
    printf("\nEnter a choice:\n"
      "  0  Print the array of grades\n"
      "  1  Find the minimum grade\n"
      "  2  Find the maximum grade\n"
      "  3  Print the average on all tests for each student\n"
      "  4  End program\n? ");
    scanf("%d", &selection);
    printf("\n");

    if (selection >= 0 && selection < 4) {
      (processGrades[selection])(studentGrades, STUDENTS, EXAMS);
    }
    else {
      selection = 4; // change selection to 4 in case of an improper input
    }
  }

  return 0;
}

void minimum(int studentGrades[][EXAMS], size_t students, size_t exams) {
  int lowestGrade = studentGrades[0][0];

  for (size_t curStudent = 0; curStudent < students; curStudent++) {

    for (size_t curExam = 0; curExam < exams; curExam++) {

      if (lowestGrade > studentGrades[curStudent][curExam]) {
        lowestGrade = studentGrades[curStudent][curExam];
      }
    }
  }

  printf("The lowest grade is %d\n", lowestGrade);
}

void maximum(int studentGrades[][EXAMS], size_t students, size_t exams) {
  int highestGrade = studentGrades[0][0];

  for (size_t curStudent = 0; curStudent < students; curStudent++) {

    for (size_t curExam = 0; curExam < exams; curExam++) {

      if (highestGrade < studentGrades[curStudent][curExam]) {
        highestGrade = studentGrades[curStudent][curExam];
    }}
  }

  printf("The highest grade is %d\n", highestGrade);
}

void average(int studentGrades[][EXAMS], size_t students, size_t exams) {

  for (size_t curStudent = 0; curStudent < students; curStudent++) {
    float curSum = 0.0;

    for (size_t curExam = 0; curExam < exams; curExam++) {
      curSum += (float) studentGrades[curStudent][curExam];
    }

    printf("The average for student %d is %2.1f\n", ((int) curStudent + 1), (curSum / (float) exams));
  }
}

void printArray(int studentGrades[][EXAMS], size_t students, size_t exams) {
  printf("\t\t");

  for (size_t i = 0; i < exams; i++) {
    printf("[%d]\t", (int) i);
  }

  printf("\n");

  for (size_t i = 0; i < students; i++) {
    printf("studentGrades[%d] ", (int) i);

    for (size_t j = 0; j < exams; j++) {
      printf("%d\t", ((int) studentGrades[i][j]));
    }

    printf("\n");
  }
}
