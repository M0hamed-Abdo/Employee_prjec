#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[15];
    float salary;
    char location[30];
};

struct employee *emp=NULL;
int count =0;
int found=0;
int employee_count;
int id_for_update;
int id_for_delete;
int serch_by_id;
void add_employee() {

    found =0;
    emp = realloc(emp,(count +1)* sizeof(struct employee));
    printf("----RECORD EMPLOYEE #%d----\n",count+1);
    printf("Enter Employee Id: ");
    scanf("%d",&emp[count].id);
    for(int i=0;i<count;i++){
        if(emp[i].id == emp[count].id){
            found=1;
        }
    }
    if(found==1){
       printf("\nThis ID Already Use.\n");
        return;
    }
    printf("Enter Employee Name: ");
    scanf("%s",&emp[count].name);
    printf("Enter Employee salary: ");
    scanf("%f",&emp[count].salary);
    printf("Enter Employee location: ");
    scanf("%s",&emp[count].location);
    printf("\n");
    printf("----DONE RECORD----\n");
    count++;
    return;


}

void add_multiple_employee() {

    found =0;
    printf("enter employee count:");
    scanf("%d",&employee_count);
    emp = realloc(emp, (count +employee_count) *sizeof(struct employee));
    for (int i=0;i<employee_count;i++){
        printf("----RECORD EMPLOYEE #%d----\n",count+1);
        printf("\nEnter Employee Id: ");
        scanf("%d",&emp[count].id);
        for(int i=0;i<count;i++){
        if(emp[i].id == emp[count].id){
            found=1;
        }
    }
    if(found==1){
        printf("This ID Already Use.\n");
        break;
    }
        printf("Enter Employee Name: ");
        scanf("%s",&emp[count].name);
        printf("Enter Employee salary: ");
        scanf("%f",&emp[count].salary);
        printf("Enter Employee location: ");
        scanf("%s",&emp[count].location);
        printf("\n");
        printf("----DONE RECORD----\n");
        printf("\n");
        count++;
    }
}

void update_employee() {
    found=0;
    if(count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
       printf("Enter id for update:");
       scanf("%d",&id_for_update);
       for(int i=0;i<count;i++){
        if(emp[i].id == id_for_update){
            printf("Enter New Name: ");
            scanf("%s",&emp[i].name);
            printf("Enter New salary: ");
            scanf("%f",&emp[i].salary);
            printf("Enter New Location: ");
            scanf("%s",&emp[i].location);
            found =1;
            }
       }
       if(found == 0){
             printf("Employee not found!!!\n");
       }
}

void delete_employee() {
    found=0;
    if(count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
        printf("Enter id for Delete: ");
        scanf("%d",&id_for_delete);
        for(int i=0;i<count;i++) {
            if(emp[i].id == id_for_delete) {
                for(int j=i;j<count-1;j++) {
                     emp[j]=emp[j+1];
                }
                count--;
                found=1;
                printf("Done Delete\n");
            }
        }
        if(found == 0) {
            printf("No found Employee\n");
        }
}

void serch_employee() {
    found=0;
    if(count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
    printf("Enter id for serch:");
    scanf("%d",&serch_by_id);
    for(int i=0;i<count;i++) {
        if(serch_by_id == emp[i].id) {
            printf("ID: %d\n",emp[i].id);
            printf("NAME: %s\n",emp[i].name);
            printf("SALARY: %3.2f\n",emp[i].salary);
            printf("LOCATION: %s\n",emp[i].location);
            found =1;
        }
    }
    if(found == 0){
         printf("employee not found!!!\n");
    }
    return;
}

void get_all() {
    if(count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       printf("\n");
    }else{
       printf("-----All Employee-----\n");
       for(int i=0;i<count;i++) {
        printf("EMPLOYEE NO:%d\n",i+1);
        printf("ID: %d\n", emp[i].id);
        printf("NAME: %s\n",emp[i].name);
        printf("SALARY: %3.2f\n", emp[i].salary);
        printf("LOCATION: %s\n", emp[i].location);
        printf("----------------------\n");
       }
    }
    return;
}

void minue() {
    int choice;
    while (1){
    printf("\n");
    printf("====main minue====\n");
    printf("[1]Add Employee\n");
    printf("[2]Add Multiple Employee\n");
    printf("[3]Update Employee\n");
    printf("[4]Delete Employee\n");
    printf("[5]Get Employee by ID\n");
    printf("[6]Get All Employee\n");
    printf("[0]Exit\n");
    printf("\n");

    printf("Enter Choice:");
    scanf("%d",&choice);

    switch(choice) {
    case 1:
        add_employee();
        break;
    case 2:
        add_multiple_employee();
        break;
    case 3:
        update_employee();
        break;
    case 4:
        delete_employee();
        break;
    case 5:
        serch_employee();
        break;
    case 6:
        get_all();
        break;
    case 0:
        printf("Exiting...\n");
        free(emp);
        exit(0);
    default :
        printf("\n");
        printf("Please Enter a Number From The List\n");
        }
    }
}


int main() {

    minue();


}
