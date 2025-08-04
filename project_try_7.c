#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[15];
    float salary;
    char location[30];
};
void add_employee(struct employee **emp,int *count) {
    *emp = realloc(*emp,(*count +1)* sizeof(struct employee));
    printf("----RECORD EMPLOYEE #%d----\n",*count+1);
    printf("Enter Employee Id: ");
    scanf("%d",&(*emp)[*count].id);
    for(int i=0;i<*count;i++){
        if((*emp)[i].id == (*emp)[*count].id){
           printf("This ID Already Use.\n");
           return;
        }
    }
    printf("Enter Employee Name: ");
    scanf("%s",&(*emp)[*count].name);
    printf("Enter Employee salary: ");
    scanf("%f",&(*emp)[*count].salary);
    printf("Enter Employee location: ");
    scanf("%s",&(*emp)[*count].location);
    printf("\n");
    printf("----DONE RECORD----\n");
    (*count)++;
    return;


}

void add_multiple_employee(struct employee **emp,int *count) {
    int count_multiple_employee;
    printf("enter employee count:");
    scanf("%d",&count_multiple_employee);
    for(int i=0;i<count_multiple_employee;i++){
            add_employee(emp,count);
    }
}

void update_employee(struct employee *emp,int *count) {
    int id_for_update;
    if(*count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
       printf("Enter id for update:");
       scanf("%d",&id_for_update);
       for(int i=0;i<*count;i++){
        if(emp[i].id == id_for_update){
            printf("Enter New Name: ");
            scanf("%s",&emp[i].name);
            printf("Enter New salary: ");
            scanf("%f",&emp[i].salary);
            printf("Enter New Location: ");
            scanf("%s",&emp[i].location);
            printf("Done update\n");
            return;
            }
       }
             printf("Employee not found!!!\n");
}

void delete_employee(struct employee *emp,int *count) {
    int id_for_delete;
    if(*count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
        printf("Enter id for Delete: ");
        scanf("%d",&id_for_delete);
        for(int i=0;i<*count;i++) {
            if(emp[i].id == id_for_delete) {
                for(int j=i;j<*count-1;j++) {
                     emp[j]=emp[j+1];
                }
                (*count)--;
                printf("Done Delete\n");
                return;
            }
        }
            printf("No found Employee\n");
}

void serch_employee(struct employee *emp,int *count) {
    int serch_by_id;
    if(*count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       return;
    }
    printf("Enter id for serch:");
    scanf("%d",&serch_by_id);
    for(int i=0;i<*count;i++) {
        if(serch_by_id == emp[i].id) {
            printf("ID: %d\n",emp[i].id);
            printf("NAME: %s\n",emp[i].name);
            printf("SALARY: %3.2f\n",emp[i].salary);
            printf("LOCATION: %s\n",emp[i].location);
            return;
        }
    }
         printf("employee not found!!!\n");
}

void get_all(struct employee *emp,int *count) {
    if(*count == 0){
       printf("----NO EMPLOYEE RECORD---\n");
       printf("\n");
       return;
    }
       printf("-----All Employee-----\n");
       for(int i=0;i<*count;i++) {
        printf("EMPLOYEE NO:%d\n",i+1);
        printf("ID: %d\n", emp[i].id);
        printf("NAME: %s\n",emp[i].name);
        printf("SALARY: %3.2f\n", emp[i].salary);
        printf("LOCATION: %s\n", emp[i].location);
        printf("----------------------\n");
       }
    }

void minue() {
    struct employee *emp=NULL;
    int count =0;
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
        add_employee(&emp,&count);
        break;
    case 2:
        add_multiple_employee(&emp,&count);
        break;
    case 3:
        update_employee(emp,&count);
        break;
    case 4:
        delete_employee(emp,&count);
        break;
    case 5:
        serch_employee(emp,&count);
        break;
    case 6:
        get_all(emp,&count);
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
