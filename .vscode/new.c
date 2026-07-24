
\//student management system
#include<stdio.h>
#define MAX 100

typedef struct
{
    int id;
    char name[50];
    char department[50];
    char ph_no[11];
    char email[30];
} student;

student studentlist[MAX];
int count = 0;
void addstudent(){
    student s;
    if(count>= MAX){
        printf("\nStorage full!\n");
        return;
    }
    printf("Id Number: ");
    scanf("%d",&s.id);

    getchar();

    printf("Name: ");
    fgets(s.name,sizeof(s.name),stdin);

    printf("Department: ");
    fgets(s.department,sizeof(s.department),stdin);

    printf("Phone: ");
    scanf("%10s",s.ph_no);

    printf("Email id: ");
    scanf("%29s",s.email);

    studentlist[count] = s;
    count++;

    printf("\nStudent added successfully!\n");

}
void searchstudent(){
    int id,index=-1;
    printf("Enter student ID to search: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(studentlist[i].id == id){
            index = i;
            break;
        }
    }
    student s = studentlist[index];

    if(index == -1){
        printf("Student not found!\n");
        return;
    }

    printf("\nStudent Details:\n");
    printf("ID         : %d\n", s.id);
    printf("Name       : %s", s.name);
    printf("Department : %s", s.department);
    printf("Phone      : %s\n", s.ph_no);
    printf("Email      : %s\n", s.email);
}
int display(){
    int choice;
    printf("\n==========================\n");
    printf("Student Management System\n");
    printf("==========================\n");
    printf("\n");
    printf("1) Add student\n");
    printf("2) Search student\n");
    printf("4) Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        addstudent();
        break;
    case 2:
        searchstudent();
        break;
    case 3:
        printf("\nThank you for using the Student Management System!\n");
        printf("Exit successfully!\n");
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    return choice;
}
int main(){
        while(1){
        if(display() ==3){
            return 0;
        }
        }
}