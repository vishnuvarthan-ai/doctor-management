#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
    int id;
    char name[10];
    char special[30];
    char ph[11];
    char email[20];
    int experience;
}doctor;
doctor doctorlist[MAX];
int count=0;
void adddoctor(){
    doctor s;
    if(count>=MAX){
        printf("storage full!");
    }
    printf("id number:\n");
    scanf("%d",&s.id);

    getchar();

    printf("name:\n");
    fgets(s.name,sizeof(s.name),stdin);

    printf("special:\n");
    fgets(s.special,sizeof(s.special),stdin);

    printf("phone number:\n");
    fgets(s.ph,sizeof(s.ph),stdin);

    printf("email:\n");
    scanf("%s",&s.email);
    if(strchr(s.email,'@')&&strchr(s.email,'.')){
        printf("%s\n",s.email);
    }

    printf("experience:\n");
    scanf("%d",&s.experience);

    printf("sucessfully add doctor\n");

    doctorlist[count]=s;
    count++;

}
void searchdoctor(){
    int id,index=-1;
    printf("Enter your id:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(doctorlist[i].id==id){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("id is not valid");
    }
    doctor s=doctorlist[index];

    printf("id:%d\n",s.id);
    printf("name:%s\n",s.name);
    printf("special:%s\n",s.special);
    printf("phone numbeer:%s\n",s.ph);
    printf("email:%s\n",s.email);
    printf("experience:%d\n",s.experience);
    printf("\n sucessfully searchdoctor complete");
}
void updatedoctor(){
    doctor s;
    int id;
    printf("\nEnter your vaild id\n");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(doctorlist[i].id==id){
            printf("found the doctor successfully");
             printf("\nid number:\n");
           scanf("%d",&s.id) ;

    getchar();

    printf("name:\n");
    fgets(s.name,sizeof(s.name),stdin);

    printf("special:\n");
    fgets(s.special,sizeof(s.special),stdin);

    printf("phone number:\n");
    scanf("%10s",&s.ph);

    getchar();

    printf("email:\n");
    scanf("%s",&s.email);
    if(strchr(s.email,'@')&&(s.email,'.')){
        printf("%s\n",s.email);
    }

    printf("\nexperience:\n");
    scanf("%d",&s.experience);

    printf("\n sucessfully complete update doctor\n");

    

        }
    }

}
void bookappoinment(){
    printf("Enter your timeing:");
    char time[10];
    scanf("%s",&time);
    printf("successfully book the appoinment on: %s",time);
    printf("\n sucessfully complete book appoinment\n");
}

int display(){
    int choice;
    printf("\n(-_-)=================(-_-)\n");
    printf("\ndoctor management\n");
    printf("\n(-_-)=================(-_-)\n");
    printf("1.adddoctor\n");
    printf("2.searchdoctor\n");
    printf("3.updatedoctor\n");
    printf("4.bookappoinment\n");
    printf("5.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
          adddoctor();
          break;
        case 2:
          searchdoctor();
          break;
        case 3:
          updatedoctor();
          break;
        case 4:
          bookappoinment();
          break;
        case 5:
          printf("\nexit successfully\n");
          printf("thank you for using\n");
        default:
           printf("error");          
    }
}
int main(){
    while(1){
        if(display()==5){
            return 0;
        }
    }
}