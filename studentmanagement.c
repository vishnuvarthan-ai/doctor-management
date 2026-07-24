#include<stdio.h>
#include<string.h>
#define Max 100
typedef struct{
   int id;
   char name[20];
   char dept[30];
   int year;
   int age;
   char phone[11];
   char email[30];
   int m1,m2,m3;
}Student;
Student students[Max];
int count=0;
int findindex(int id){
    for(int i=0;i<count;i++){
        if(students[i].id==id){
            return i;
        }
    }
    return -1;
}
int validphone(char phone[]){
    if(strlen(phone)!=10){
        return 0;
    }
    for(int i=0;i<10;i++){
        if(phone[i]<'0' || phone[i]>'9'){
            return 0;
        }
    }
    return 1;
}
int validemail(char email[]){
   return(strchr(email,'@')!=NULL && strchr(email,'.')!=NULL);
}
void addstudent(){
    Student s;
    printf("Enter student id:");
    scanf("%d",&s.id);
    if(findindex(s.id)!=-1){
        printf("\nDuplicate ID!\n");
        return;
    }
    printf("Enter name:");
    scanf("%s",&s.name);
    printf("Enter Department:");
    scanf("%s",s.dept);
    printf("Enter Year:");
    scanf("%d",&s.year);
    printf("Enter Age:");
    scanf("%d",&s.age);
    if(s.age<18 || s.age>60){
        printf("Invalid Age");
        return;
    }
    printf("Enter Phone:");
    scanf("%s",s.phone);
    if(!validphone(s.phone)){
          printf("\nInvalid Phone!");
          return;
    }
    printf("Enter Email id:");
    scanf("%s",s.email);
    if(!validemail(s.email)){
          printf("\nInvalid Email!");
          return;
    }
    printf("Enter Marks:");
    scanf("%d %d %d",&s.m1,&s.m2,&s.m3);
    if(s.m1<0 || s.m1>100 ||s.m2<0 || s.m2>100 ||s.m3<0 || s.m3>100){
        printf("\nInvalid Marks!");
        return;
    }
    students[count++]=s;
    printf("\nStudent Added Successfully");
}
void viewstudent(){
    if(count==0){
        printf("\nNo Records Found!");
        return;
    }
    printf("\n==Student Details==");
    for(int i=0;i<count;i++){
       printf("\n---------------------\n");
       printf("Id     :%d\n",students[i].id);
       printf("Name   :%s\n",students[i].name);
       printf("Dept   :%s\n",students[i].dept);
       printf("Year   :%d\n",students[i].year);
       printf("Age    :%d\n",students[i].age);
       printf("Phone  :%s\n",students[i].phone);
       printf("Email  :%s\n",students[i].email);
       printf("Marks  :%d %d %d\n",students[i].m1,students[i].m2,students[i].m3);
    }
}
void searchstudent(){
    int id;
    printf("Enter ID to Search:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
       if(students[i].id==id){
       printf("--Student Found--\n");
       printf("Id     :%d\n",students[i].id);
       printf("Name   :%s\n",students[i].name);
       printf("Dept   :%s\n",students[i].dept);
       printf("Year   :%d\n",students[i].year);
       printf("Age    :%d\n",students[i].age);
       printf("Phone  :%s\n",students[i].phone);
       printf("Email  :%s\n",students[i].email);
       printf("Marks  :%d %d %d\n",students[i].m1,students[i].m2,students[i].m3);
       return;
       }
    }
    printf("Student Not Found!");
}
void updatestudent(){
    int id;
    printf("Enter ID to Update:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
       if(students[i].id==id){
        printf("--ID Found--\n");
        printf("--Update the Details--\n");
        printf("Enter name:");
    scanf("%s",&students[i].name);
    printf("Enter Department:");
    scanf("%s",&students[i].dept);
    printf("Enter Year:");
    scanf("%d",&students[i].year);
    printf("Enter Age:");
    scanf("%d",&students[i].age);
    if(students[i].age<18 || students[i].age>60){
        printf("Invalid Age");
        return;
    }
    printf("Enter Phone:");
    scanf("%s",&students[i].phone);
    if(!validphone(students[i].phone)){
          printf("\nInvalid Phone!");
          return;
    }
    printf("Enter Email id:");
    scanf("%s",&students[i].email);
    if(!validemail(students[i].email)){
          printf("\nInvalid Email!");
          return;
    }
    printf("Enter Marks:");
    scanf("%d %d %d",&students[i].m1,&students[i].m2,&students[i].m3);
    if(students[i].m1<0 || students[i].m1>100 ||students[i].m2<0 || students[i].m2>100 ||students[i].m3<0 || students[i].m3>100){
        printf("\nInvalid Marks!");
        return;
    }
    printf("---Updated Successfully---");
    return;
}
    }
    printf("Not found");
}
void deletestudent(){
    int id,choice;
    printf("Enter the Id to Delete:");
    scanf("%d",&id);
    int i=findindex(id);
    printf("Are you sure to Delete!\n1.Yes\n2.No\n");
    scanf("%d",&choice);
    if(choice==1){
    for(int j=i;j<count-1;j++){
           students[j]=students[j+1];
    }
    printf("\n--Deleted Successfully--\n");
    count--;
}
}
int main(){
    int choice;
    while(1){
       printf("\n==============================\n");
       printf(" --Student Management System--\n");
       printf("==============================\n");
       printf("1.Add Student\n");
       printf("2.View Student\n");
       printf("3.Search Student\n");
       printf("4.Update Student\n");
       printf("5.Delete Student\n");
       printf("6.Exit \n");
       printf("Enter your choice:");
       scanf("%d",&choice);
       switch(choice){
        case 1:
        addstudent();
        break;
        case 2:
        viewstudent();
        break;
        case 3:
        searchstudent();
        break;
        case 4:
        updatestudent();
        break;
        case 5:
        deletestudent();
        break;
        case 6:
        printf("\n===Thank You===");
        return 0;
        default :
        printf("\nInvalid choice!");
       }
    }
}