#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#define MAX_STUDENTS 100

typedef struct
{
    char CourseName[50];
    int rating;
    bool registration;
}Course;

typedef struct
{
    char TeacherName[50];
    int rating;
}Teacher;

typedef struct
{
    char studentID[7];
    char password[50];
}Student;

void registerStudent(Student students[], int *numStudents);
void saveStudentToFile(Student student);
void registerCourses(Course courses[]);
void viewRegisteredCourses(Course courses[]);
void courseFeedback(Course courses[]);
void teacherFeedback(Teacher teachers[], Course courses[]);
void printFeedback(Course courses[], Teacher teachers[]);
bool signInUser(Student students[], int *numStudents);
bool isNumeric(const char *str);

int main()
{
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    bool Login = false;
    bool registered = false;

    do
    {
        Login = signInUser(students, &numStudents);

        if (!Login)
        {
            printf("\nInvalid Student ID or Password, Please Try Again!\n\n");
        }
        else
        {
            system("cls");
            break;
        }
    } while (!Login);

    Course courses[9];
    Teacher teachers[9];

    for(int i=0; i<9; i++)
    {
        strcpy(courses[i].CourseName," ");
        courses[i].rating = 0;
        courses[i].registration = false;
    }

    //Assigning names of courses
    strcpy(courses[0].CourseName,"Fundamentals Of Programming");
    strcpy(courses[1].CourseName,"Applied Physics");
    strcpy(courses[2].CourseName,"Calculus and Analytical Geometry");
    strcpy(courses[3].CourseName,"Introduction to Computer Science");
    strcpy(courses[4].CourseName,"Pakistan Studies");
    strcpy(courses[5].CourseName,"English");
    strcpy(courses[6].CourseName,"Lab, Fundamentals Of Programming");
    strcpy(courses[7].CourseName,"Lab, Introduction to Computer Science");
    strcpy(courses[8].CourseName,"Lab, Applied Physics");

    //Assigning names of course instructors
    strcpy(teachers[0].TeacherName,"Sheikh-Usama-Khalid");
    strcpy(teachers[1].TeacherName,"Naveed Ghani");
    strcpy(teachers[2].TeacherName,"Tahir Abbasi");
    strcpy(teachers[3].TeacherName,"Khalil-ur-Rehman");
    strcpy(teachers[4].TeacherName,"Koonj-Altaf");
    strcpy(teachers[5].TeacherName,"Laila-Rizwan");
    strcpy(teachers[6].TeacherName,"Qambar Ali");
    strcpy(teachers[7].TeacherName,"Shehzad Abbasi");
    strcpy(teachers[8].TeacherName,"Ashar Tariq");

    int option;
    do
        {
            printf("\n--- Menu ---\n");
            printf("1. Register Courses\n");
            printf("2. View Registered Courses\n");
            printf("3. Evaluate courses\n");
            printf("4. Evaluate teachers\n");
            printf("5. Print evaluation\n");
            printf("6. Exit\n");
            printf("Enter your choice(1-6): ");
            scanf("%d", &option);

        switch(option)
        {
            case 1:
                registerCourses(courses);
                registered=true;
                break;
            case 2:
                if(registered)
                {
                    viewRegisteredCourses(courses);
                }
                else
                {
                    printf("\nNo Courses have been Registered Yet!\n");
                }
                break;
            case 3:
                if(registered)
                {
                    printf("\nEnter Course Rating(1-5): \n");
                    courseFeedback(courses);
                }
                else
                {
                    printf("\nYou need to Register for Courses First!\n");
                }
                break;
            case 4:
                if(registered)
                {
                    printf("\nEnter Course Instructor Rating(1-5): \n");
                    teacherFeedback(teachers, courses);
                }
                else
                {
                    printf("\nYou need to Register for Courses First!\n");
                }
                break;
            case 5:
                if(registered)
                {
                    printFeedback(courses, teachers);
                }
                else
                {
                    printf("\nYou need to Register for Courses First!\n");
                }
                break;
            case 6:
                printf("You chose to Exit the Program! \n");
                break;
            default:
                printf("Invalid option! Should be(1-6).\n");
                break;
        }
    }

    while (option != 6);

    return 0;
}

void registerStudent(Student students[], int *numStudents)
{
    Student newStudent;

    printf("\nEnter Student ID (6 digits): ");
    while (scanf("%6s", newStudent.studentID) != 1 || strlen(newStudent.studentID) != 6 || !isNumeric(newStudent.studentID))
    {
        printf("Invalid input. Please enter a valid 6-digit number: ");
        while (getchar() != '\n');
    }

    printf("Enter Password (at least 8 characters): ");
    while (scanf("%s", newStudent.password) != 1 || strlen(newStudent.password)<8)
    {
        printf("Invalid input. Please enter a password with at least 8 characters: ");
        while (getchar() != '\n');
    }

    students[*numStudents] = newStudent;
    (*numStudents)++;
    saveStudentToFile(newStudent);

    printf("\nRegistration successful!\n");
    system("cls");
}

bool isNumeric(const char *str)
{
    while(*str)
    {
        if(!isdigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}


void saveStudentToFile(Student student)
{
    FILE *file = fopen("students.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s %s\n", student.studentID, student.password);
        fclose(file);
    }
}

bool signInUser(Student students[], int *numStudents)
{
    char studentID[7];
    char password[50];

    printf("Enter Student ID: ");
    scanf("%s", studentID);

    for (int i=0; i<*numStudents; ++i)
    {
        if (strcmp(studentID, students[i].studentID)==0)
        {
            printf("Enter Password: ");
            scanf("%s", password);

            if (strcmp(password, students[i].password)==0)
            {
                return true;
            }
            else
            {
                printf("Invalid Password! Please Try Again.\n");
                return false;
            }
        }
    }

    if(*numStudents<MAX_STUDENTS)
    {
        printf("Student ID not found. Create a new account? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            registerStudent(students, numStudents);
            return true;
        }
    }

    return false;
}

void registerCourses(Course courses[])
{
    printf("\nAvailable Courses:\n");
    for (int i=0; i<9; i++)
    {
        printf("%d. %s\n", i+1, courses[i].CourseName);
    }
    printf("\nEnter the numbers of the courses you want to register (up to 9, enter 0 to finish): ");
    int courseNumber;
    int count = 0;

    while(count<9)
    {
        if(scanf("%d", &courseNumber)==1)
        {
            if(courseNumber==0)
            {
                break;
            }
            else if(courseNumber>=1 && courseNumber<=9 && !courses[courseNumber-1].registration)
            {
                courses[courseNumber-1].registration=true;
                count++;
                printf("%s has been registered.\n", courses[courseNumber-1].CourseName);
            }
            else
            {
                printf("Invalid course number or course already registered.\n");
            }
        }
        else
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }
    }
    system("cls");
}

void viewRegisteredCourses(Course courses[])
{
    printf("\nRegistered Courses:\n");
    int count = 0;
    for (int i=0; i<9; i++)
    {
        if (courses[i].registration)
        {
            printf("%s\n", courses[i].CourseName);
            count++;
        }
    }
    if (count==0)
    {
        printf("None.\n");
    }
}

void courseFeedback(Course courses[])
{
    for(int i=0; i<9; i++)
        {
            if(courses[i].registration)
            {
                printf("%s: ", courses[i].CourseName);
                scanf("%d", &courses[i].rating);

                while(courses[i].rating<1 || courses[i].rating>5)
                    {
                        printf("Invalid Rating! Should be (1-5)\n");
                        printf("%s: ", courses[i].CourseName);
                        scanf("%d", &courses[i].rating);
                    }
            }

        }
    system("cls");
}

void teacherFeedback(Teacher teachers[], Course courses[])
{
    for(int i=0; i<9; i++)
        {
            if(courses[i].registration)
            {
                printf("%s: ", teachers[i].TeacherName);
                scanf("%d", &teachers[i].rating);

                while(teachers[i].rating<1 || teachers[i].rating>5)
                    {
                        printf("Invalid Rating! Should be (1-5)\n");
                        printf("%s: ", teachers[i].TeacherName);
                        scanf("%d", &teachers[i].rating);
                    }
            }

        }
    system("cls");
}

void printFeedback(Course courses[],Teacher teachers[])
{
    int coursesRating = 0;
    int teachersRating = 0;

    printf("\nCourse Evaluation: \n");
    for(int i=0; i<9; i++)
    {
        if(courses[i].registration && courses[i].rating >=1 && courses[i].rating<=5)
        {
            printf("%s: %d\n", courses[i].CourseName, courses[i].rating);
            coursesRating = 1;
        }
    }
    if(!coursesRating)
    {
        printf("\nCourses have not been Evaluated therefore, Can not be Printed! \n");
    }

    printf("\nTeachers' Evaluation: \n");
    for(int i=0; i<9; i++)
        {
           if(courses[i].registration && teachers[i].rating >=1 && teachers[i].rating<=5)
            {
                printf("%s: %d\n", teachers[i].TeacherName, teachers[i].rating);
                teachersRating = 1;
            }
        }
    if(!teachersRating)
    {
        printf("\nTeachers have not been Evaluated therefore, Can not be Printed! \n");
    }
}


