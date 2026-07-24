#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
    int id;
    char name[30];
    char dep[10];
    char ph[11];
    char email[20];
}student;
student studentlist[MAX];

int count=0;
void addstudent(){
    student s;
    if(count>=MAX){
        printf("storage full");
        return;
    }
   printf("\n id number:");
   scanf("%d",&s.id);
   getchar();

   printf("\n name:");
   fgets(s.name,sizeof(s.name),stdin);

   printf("\n dep:");
   fgets(s.dep,sizeof(s.dep),stdin);

   printf("\n ph:");
   fgets(s.ph,sizeof(s.ph),stdin);
   getchar();

   printf("\n email");
   scanf("%s",&s.email);
   if(strchr(s.email,'@')&&(s.email,'.')){
    printf("%s",s.email);
   }

   studentlist[count]=s;
   count++;



    
}
void searchstudent(){
    int id,index=-1;
    printf("Enter your id");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(studentlist[i].id==id){
            index=i;
            break;
        }
    }
    if(index=-1){
        printf("id not vaild");
        return;

    }
    student s=studentlist[index];
    printf("\n id is vaild");
    printf("\n id:%d",s.id);
    printf("\n name:%s",s.name);
    printf("\n dep:%s",s.dep);
    printf("\n ph:%s",s.ph);
    printf("\n email:%s",s.email);

}
void updatestudent(){
    student s;
    int id;
    printf("\nEnter your id\n");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(studentlist[i].id==id){
            printf("id is found\n");
             printf("\n id number:");
   scanf("%d",&s.id);
   getchar();

   printf("\n name:");
   fgets(s.name,sizeof(s.name),stdin);

   printf("\n dep:");
   fgets(s.dep,sizeof(s.dep),stdin);

   printf("\n ph:");
   fgets(s.ph,sizeof(s.ph),stdin);
   getchar();

   printf("\n email");
   scanf("%s",&s.email);
   if(strchr(s.email,'@')&&(s.email,'.')){
    printf("%s",s.email);

        }
    }
}
}


int display(){
    int choice;
    printf("\n=====================\n");
    printf("student management\n");
    printf("=======================\n");
    printf("1.addstudent\n");
    printf("2.searchstudent\n");
    printf("3.exit\n");
    printf("4.updatestudent\n");
    printf("\nenter choice:");
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
           printf("\n exit complete");
           printf("thank you for using");
           break;
        case 4:
            updatestudent();
            break;   
        default: 
           printf("error") ;
               
    }
}


int main(){
    while(1){
        if(display()==4){
            return 0;
        }
    }
}