#include<stdio.h>
#define MAX 100

typedef struct{
    int id;
    char department[50];
    char name[10];
    char ph_no[11];
    char email[50];
} student ;
student studentlist[100];
int count=0;
void addstudent(){
    student s;
    if(count>= MAX){
        printf("\nstorage full");
        return;
    }
    printf("ID number:");
    scanf("%d",&s.id);

    getchar();

    printf("department:");
    fgets(s.department,sizeof(s.department),stdin);

    printf("name:");
    fgets(s.name,sizeof(s.name),stdin);

    printf("ph_no:");
    fgets(s.ph_no,sizeof(s.ph_no),stdin);
    getchar();

    printf("email:");
    fgets(s.email,sizeof(s.email),stdin);

    studentlist[count]=s;
    count++;


    printf("\n addstuent complete");


}
void searchstudent(){
    int id,index=-1;
    printf("Enter your id :");
    scanf("%d",id);
    for(int i=0;i<count;i++){
        (studentlist[i].id==id);
        index=i;
        break;
    }
    student s= studentlist[index];
    if(index==-1){
        printf("id  isnot found");
    }
    printf("\nid is found\n ");
    printf("\n id:%d",s.id);
    printf("\n department:%s ",s.department);
    printf("\n name:%s",s.name);
    printf("\n ph_n0:%d",s.ph_no);
    printf("\n email:%d",s.email);

}
int  display(){
    int choice;
    
    printf("\n student management system \n");
    printf("1.addstudent\n");
    printf("2.searchstudent\n");
    printf("3.exit\n");
    printf("choice:\n");
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
            printf("\n exit successfully\n");
            printf("thankyou for using\n");
            break;
         default :
         printf("\n incorrect choise");   
         
    }   

    }
        
        
        



int main(){
    while(1){
        display();
        return 0;

    }
}
