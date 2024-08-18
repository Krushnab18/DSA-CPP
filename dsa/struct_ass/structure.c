#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20
typedef struct name{
    char first_name[MAX_SIZE];
    char middle_name[MAX_SIZE];
    char last_name[MAX_SIZE];
}Name;

typedef struct date{
    short int day;
    short int month;
    int year;    
}Date;

typedef struct marks{
    double english;
    double mathematics;
    double computer_science;
}Marks;

typedef struct student{
    int roll_no;
    Name name;
    char gender[6];
    Date date;
    Marks marks;
}Student;

void calculate_aggregate(struct student students[], double aggregate[], int n) {
    
    double sum = 0;

    for(int i = 0; i < n; i++) {
        sum = students[i].marks.english + students[i].marks.mathematics + students[i].marks.computer_science;
        aggregate[i] = sum / 3;
    }

    return;

}

void display_student_details(struct student students[], int index) {
    printf("Name: %s %s %s\n", students[index].name.first_name, students[index].name.middle_name, students[index].name.last_name);
    printf("Roll No : %d\n", students[index].roll_no);
    printf("Gender: %s\n", students[index].gender);
    printf("Date of Birth: %d - %d - %d\n", students[index].date.day, students[index].date.month, students[index].date.year);
    printf("Marks:\n\tEnglish-> %.2f\n\tMathematics-> %.2f\n\tComputer Science-> %.2f\n", students[index].marks.english, students[index].marks.mathematics, students[index].marks.computer_science);
    return;
}

void search_student_by_name(Student students[], char first_name[], char middle_name[], char last_name[], int n) {
    
    int found = 0;    

    for(int i = 0; i < n; i++) {

        if(strcmp(first_name, students[i].name.first_name) == 0 && strcmp(middle_name, students[i].name.middle_name) == 0 && strcmp(last_name, students[i].name.last_name) == 0 ){
            found = 1;
            display_student_details(students, i);
            break;
        }
    
    }
    
    if(!found) {
        printf("Not found!");
    }

    return;
}

void print_average_marks(Student students[], int n) {

    double sum = 0;

    for(int i = 0; i < n; i++) {
        sum = students[i].marks.english + students[i].marks.mathematics + students[i].marks.computer_science;
        printf("Name: %s %s %s\t", students[i].name.first_name, students[i].name.middle_name, students[i].name.last_name);
        printf("Average marks are: %.2f \n", sum / 3.0);
    }

    return;
}

int main() {
    //Sample of 10 students
    Student students[10] = {
        {101, {"John", "Alexander", "Doe"}, "Male", {15, 8, 2004}, {85.5, 92.0, 89.75}},
        {102, {"Jane", "Elizabeth", "Smith"}, "Female", {22, 11, 2003}, {90.0, 95.0, 88.5}},
        {103, {"Michael", "James", "Johnson"}, "Male", {5, 3, 2005}, {78.25, 84.5, 80.0}},
        {104, {"Emily", "Grace", "Williams"}, "Female", {19, 7, 2004}, {92.0, 89.75, 91.5}},
        {105, {"David", "Lee", "Brown"}, "Male", {12, 9, 2003}, {30, 44.5, 13.25}},
        {106, {"Emma", "Rose", "Jones"}, "Female", {30, 6, 2004}, {84.5, 87.0, 90.0}},
        {107, {"Daniel", "Andrew", "Garcia"}, "Male", {8, 1, 2005}, {33.75, 23.5, 32.0}},
        {108, {"Olivia", "Marie", "Martinez"}, "Female", {14, 12, 2004}, {91.0, 93.5, 89.25}},
        {109, {"Sophia", "Claire", "Rodriguez"}, "Female", {25, 4, 2003}, {89.5, 94.0, 87.75}},
        {110, {"James", "William", "Wilson"}, "Male", {18, 10, 2004}, {86.5, 90.0, 88.0}}
    };

    double aggregate[10], n = 10;
    //Function to calculate aggreagate marks of all the students and stores in tbe array aggregate
    calculate_aggregate(students, aggregate, n);

    printf("Names of students who secured less than 40 percent aggregate marks\n");
    printf("\n");
    
    for(int i = 0; i < n; i++) {
        if(aggregate[i] < 40) {
            printf("%s %s %s %.2f\n", students[i].name.first_name, students[i].name.middle_name, students[i].name.last_name, aggregate[i]);
        }
    }
    
    printf("\n");

    char first_name[MAX_SIZE], middle_name[MAX_SIZE], last_name[MAX_SIZE];
   
    printf("Enter first name: \n");
    scanf("%[^\n]", first_name);
    printf("Enter middle_name: \n");
    scanf(" %[^\n]", middle_name);
    printf("Enter last name: \n");
    scanf(" %[^\n]", last_name);

    //Function to search student by name
    search_student_by_name(students, first_name, middle_name, last_name, n);
    //Function to print average marks of all the students
    print_average_marks(students, n);

    return 0;
}
