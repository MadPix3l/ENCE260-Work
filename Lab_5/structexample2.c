/* 
 * structexample2.c
 * A development from structexample1 (q.v. for explanations),
 * this time using a typedef for the student structure.
 * The global variables have been moved into "main", too,
 * and have been given initialisers.
 * Otherwise it's the same as the previous example.
 *
 * Author: Richard Lobb
 * Date: August 2014
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct student_s Student;

struct student_s {
    char* name;
    int age;
    Student* next;  // Pointer to next student in a list
};


void printOneStudent(Student student)
{
    printf("%s (%d)\n", student.name, student.age);
}   


void printStudents(const Student* student)
{
    while (student != NULL) {
        printOneStudent(*student);
        student = student->next;
    }
}


int main(void)
{
    // Declare and initialise the students and the list
    Student student = {"Agnes McGurkinshaw", 97, NULL};
    Student anotherStudent = {"Jingwu Xiao", 21, NULL};
    Student* studentList = NULL;

    // Set up the linked list structure
    student.next = &anotherStudent;
    studentList = &student;
    printStudents(studentList);
    return EXIT_SUCCESS;
}
