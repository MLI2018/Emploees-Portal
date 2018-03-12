#include <stdio.h>
#include<stdlib.h>



typedef struct emp
{
    char name[30],dept[10];
    char gender[6];
    int id;
    struct emp *next;
}node;


    
void delete(struct emp *,int);



int main()
{
    int choice,key,choice2;
    node *head=NULL, *new_emp=NULL, *tmp=NULL;
    node *get_node();
    int array1[5];
    
    do
    {
        printf("\nEMPLOYEE INFORMATION");
        printf("\n============================================\n");
        printf("1.Add new employee");
        printf("\n2.Update");
        printf("\n3.Delete");
        printf("\n4.View all");
        printf("\n5.Search");
        printf("\n6.Exit\n");
        printf("============================================\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: new_emp=get_node();
                    printf("Employee ID:");
                    scanf("%d", &new_emp->id);
                    printf("Name:");
                    scanf(" %[^\n]s",new_emp->name);
                    printf("Gender:");
                    scanf("%s", new_emp->gender);
                    printf("Department:");
                    scanf(" %[^\n]s", new_emp->dept);
                    new_emp->next=NULL;
                    if(head==NULL)
                    {
                        head=new_emp;
                        tmp=new_emp;
                        tmp->next=NULL;
                    }
                    else
                    {
                        //while(tmp!=NULL)
                        //{
                        tmp->next=new_emp;
                        tmp=tmp->next;
                        // }
                        tmp->next=NULL;
                    }
                    break;
            case 2: printf("Employee ID:");
                    scanf("%d", &key);
                    printf("Update (1)Name or (2)Department?\n");
                    scanf("%d", &choice2);
                    if(head==NULL)
                    {
                        printf("No details to display.\n");
                        break;
                    }
                    tmp=head;
                    while(tmp->next!=NULL)
                    {
                        if(tmp->id==key)
                            break;
                        tmp=tmp->next;
                        if(tmp->next==NULL && tmp->id!=key)
                        printf("No employee with ID %d.\n", key);
                    }
                    if(choice2==1)
                    {
                        printf("Enter new name:");
                        scanf(" %[^\n]s", tmp->name);
                        
                    }
                    if(choice2==2)
                    {
                        printf("Enter new Department:");
                        scanf(" %[^\n]s", tmp->dept);
                    }
                    break;
            case 3: printf("Enter the IDs to be deleted, press '0' to delete\n");
                    int i,x,k=0, c=0;
                    node *temp3=NULL;
                    for(i=0;i<5;i++)
                    {
                        scanf("%d",&array1[i]);
                        k++;
                        if(array1[i]==0)
                        break;
                    }
                    if(head==NULL)
                    {
                        printf("No details to delete.\n");
                        break;
                    }
                    for(x=0; x<k;x++)
                    {
                        tmp=head;
                        while(tmp!=NULL)
                        {
                            c=0;
                            if(tmp->id==array1[x])
                                {
                                    if(tmp==head)
                                    {
                                        head=head->next;
                                        c++;
                                        printf("Deleting details of employee with ID: %d\n", tmp->id);
                                        free(tmp);
                                        break;
                                    }
                                    else
                                    {
                                        temp3->next=tmp->next;
                                        c++;
                                        printf("Deleting details of employee with ID: %d\n", tmp->id);
                                        free(tmp);
                                        break;
                                    }
                                }
                                temp3=tmp;
                                tmp=tmp->next;
                        }
                        if(c==0&&array1[x]!=0)
                        {
                        //if(tmp==NULL && temp3->id!=array1[x])
                        printf("No employee with ID %d\n",array1[x]);
                        break;
                        }
                    }
                    break;
            case 4: if(head==NULL)
                    {
                      printf("Nothing to display!\n");
                    }
                    else
                    {
                        tmp=head;
                        printf("Employee data\n\n");
                        printf("ID\t\tName\t\tGender\t\tDepartment\n");
                        printf("===========================================================================\n");
                        while(tmp!=NULL)
                        {
                            printf("%d\t\t%s\t\t%s\t\t%s\n",tmp->id,tmp->name,tmp->gender,tmp->dept);
                            tmp=tmp->next;
                        }
                    }
                    break;
            case 5: printf("Employee ID:");
                    scanf("%d", &key);
                    if(head==NULL)
                    {
                        printf("No details to display.\n");
                        break;
                    }
                    tmp=head;
                    while(tmp->next!=NULL)
                    {
                        if(tmp->id==key)
                            break;
                        tmp=tmp->next;
                        if(tmp->next==NULL && tmp->id!=key)
                        printf("No employee with ID %d.\n", key);
                    }
                    printf("%d\t %s\t %s\t %s\t\n ", tmp->id, tmp->name, tmp->gender, tmp->dept);
                    break;
        }
    }while(choice!=6);
    return 0;
}



node *get_node()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    return temp;
}
 /*void delete(struct emp *head,int key)
 {
    struct emp *temp1 = head;    
    int i;
    if(key==temp1->id)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    
    for(i=0;i<;i++)
    {
        temp1=  temp1->next;
    }
    struct emp* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);

 }*/
