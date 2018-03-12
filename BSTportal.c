# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
#include <time.h>

 
typedef struct BST
{
    int data;
    char name[50];
    char position[50];
    int age;
    struct BST *lchild,*rchild;
}node;
 
 

void insert(node *,node *);
void display(node *);
void search(node *,int);
node *find(node *, int);
void update(node *, int);
node *delete(node *, int);
node *inorderSuccessor(node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void DFS(node *);
int continuity();
int checkAgeNum(int);
int checkChar(char[]);
node *deleteTree(node *);
int checkYN(char[]);

 
void main()
{
    static int ID=0;
    clock_t start, end;
    int choice,x,res;
    char garbage[10], cont[10];
    int key,sc,len;
    node *new_node=NULL,*root=NULL,*tmp=NULL,*parent=NULL;
    node *get_node();

      choice =continuity();  
    do{ 
        

        switch(choice)
        {
            case 1: new_node=get_node();
                    new_node->data=++ID;
                    if(ID<=9)
                        printf("ID:ML00%d\n", new_node->data);
                    if(ID>9)
                        printf("ID:ML0%d\n", new_node->data);
                    if(ID>99)
                        printf("ID:ML%d\n", new_node->data);
                    printf("Name:");
                    scanf(" %[^\n]s",new_node->name);
                    res=checkChar(new_node->name);
                    if(res!=1)
                    {
                        while(res!=1)
                        {
                            printf("Error! Name should contain only letters. Numbers/special characters are not allowed.\nRe-enter name:");
                            scanf(" %[^\n]s", new_node->name);
                            res=checkChar(new_node->name);
                        }
                    }
                    len=strlen(new_node->name);
                    while(len<0 || len>=50)
                    {
                        printf("Error!Name should between 0-50 characters.\nTry again\n");
                        printf("Enter Name again:");
                        scanf("%s",new_node->name);
                        len=strlen(new_node->name);
                        //scanf(" %[^\n]s",new_node->name);
                    }
                    printf("Department:");
                    scanf(" %[^\n]s",new_node->position);
                    res=checkChar(new_node->position);
                    if(res!=1)
                    {
                        while(res!=1)
                        {
                            printf("Error! Department should contain only letters. Numbers/special characters are not allowed.\nRe-enter Department:");
                            scanf(" %[^\n]s", new_node->position);
                            res=checkChar(new_node->position);
                        }
                    }
                    len=strlen(new_node->position);
                    while(len<0 || len>=50)
                    {
                        printf("Error!Department name should between 0-10 characters.\n");
                        printf("Enter Department name again:");
                        scanf("%s",new_node->position);
                        len=strlen(new_node->position);
                        //scanf(" %[^\n]s",new_node->name);
                        
                    }
                    
                    printf("Age:");
                    sc=scanf("%d", &new_node->age);
                    res=checkAgeNum(new_node->age);
                    while(sc!=1 || res==-1)
                    {
                        if(sc!=1)
                            scanf("%s", garbage);
                        printf("Error while entering age. Please enter a number between 16 and 100\nAge:");
                        sc=scanf("%d", &new_node->age);
                        res=checkAgeNum(new_node->age);
                    }
                    
                    
                    if(root==NULL)   /* Tree is not Created */
                        root=new_node;
                    else
                        insert(root,new_node);
                    printf("Employee details added successfully!\n");
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;
            case 3: if(root==NULL)
                    {
                        printf("No details to display!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }
                        break;
                    }    
                    printf("Enter ID(last 3 digits):");
                    scanf("%d",&key);
                    search(root,key);
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;    
            case 5: if(root==NULL)
                    {
                        printf("No details to display!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }   
                        break;
                    }    
                    else
                    {
                        printf("\nEMPLOYEES' DETAILS\n");
                        printf("==============================================\n");
                        display(root);
                    }
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;
            case 2: if(root==NULL)
                    {
                        printf("No details to display!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }
                        break;
                    }
                    printf("Enter ID(last 3 digits):");
                    scanf("%d",&key);
                    //printf("%d\n", key);
                    update(root,key);
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;    
            case 4: if(root==NULL)
                    {
                        printf("No details to display!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }
                        break;
                    }
                    printf("Enter ID(last 3 digits):");
                    scanf("%d",&key);
                    root=delete(root,key);
                    printf("Deletion Successful!\n");
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;
            case 6: if(root==NULL)
                    {
                        printf("No details to display!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }
                        break;
                    }
                    else
                    {
                        printf("\nThe Inorder display:\n");
                        inorder(root);
                        printf("\nThe Preorder display:\n");
                        preorder(root);
                        printf("\nThe Postorder display:\n");
                        postorder(root);
                    }
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;
            case 9: printf("Exiting...\n");
                    exit(0);
            case 8: if(root==NULL)
                    {
                        printf("No details to delete!(Tree is empty)\n");
                        printf("Would you like to continue?(Y/N)\n");
                        scanf("%s", cont);
                        res=checkYN(cont);
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                        if(res==2||res==3)
                        {
                            while(res==2 || res==3)
                            {
                                printf("Please enter only letters Y/N\n"); 
                                printf("Would you like to continue?(Y/N)\n");
                                scanf("%s", cont);
                                res=checkYN(cont);
                            }
                            if(res==1)
                            {
                                choice= continuity();
                                break;
                            }
                            if(res==0)
                            {
                                printf("Exiting...\n");
                                exit(0);
                            }
                        }
                        break;
                    }
                    root=deleteTree(root);  
                    root = NULL;
                    printf("\n Tree deleted\n ");
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    printf("Would you like to continue?(Y/N)\n");
                    scanf("%s", cont);
                    res=checkYN(cont);
                    if(res==1)
                    {
                        choice= continuity();
                        break;
                    }
                    if(res==0)
                    {
                        printf("Exiting...\n");
                        exit(0);
                    }
                    if(res==2||res==3)
                    {
                        while(res==2 || res==3)
                        {
                            printf("Please enter only letters Y/N\n"); 
                            printf("Would you like to continue?(Y/N)\n");
                            scanf("%s", cont);
                            res=checkYN(cont);
                        }
                        if(res==1)
                        {
                            choice= continuity();
                            break;
                        }
                        if(res==0)
                        {
                            printf("Exiting...\n");
                            exit(0);
                        }
                    }
                    break;
        } 
    }while(choice>0);
}



/*
  Get new Node
*/
node *get_node()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
 
 
 
/*
  This function is for creating a binary search tree
*/
void insert(node *root,node *new_node)
{
    if(new_node->data < root->data)
    {
        if(root->lchild==NULL)
            root->lchild = new_node;
        else
            insert(root->lchild,new_node);
    }
    if(new_node->data > root->data)
    {
        if(root->rchild==NULL)
            root->rchild=new_node;
        else
            insert(root->rchild,new_node);
    }
}



/*
This function is for searching the 

node from binary Search Tree
*/
void search(node *root,int key)
{
    node *temp=root;
    int c=0;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
            c++;
        }
        if(temp->data>key)
        {
         temp=temp->lchild;
         //printf("x");
        }
        else
        {
         temp=temp->rchild;
          //printf("rx");
        }
    }
    if(c==0)
        printf("No employee with ID %d.\n", key);
}



/*
This function displays the tree in display fashion
*/
void display(node *temp)
{
    if(temp!=NULL)
    {
        display(temp->lchild);
        printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
        display(temp->rchild);
    }
}



/*
This function is similar to the search function, the only difference 

is the return type.
*/
node *find(node *root,int X)
{
    node *temp=root;
    while(temp!=NULL)
    {
        if(temp->data==X)
        {
            return temp;
        }
        if(temp->data>X)
        {
            temp=temp->lchild;
            //printf("x");
        }
        else
        {
            temp=temp->rchild;
            //printf("rx");
        }
    }
}



/*
This function is used to update the name and Department
*/
void update(node *root, int x)
{
    int ch;
    char newname[50], newdept[50];
    node *t=find(root,x);
    if(t==NULL)
    {
        printf("No employee with ID %d.\n", x);
    }
    else
    {
        printf("Update (1)Name or (2)Department?\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter new name:");
                    scanf(" %[^\n]s",newname);
                    strcpy(t->name, newname);
                    printf("Updated details:\n");
                    printf("==============================================\n");
                    printf("%d\t%s\t%s\t%d\n",t->data,t->name,t->position,t->age);
                    break;
       case 2: printf("Enter new Department:");
                    scanf(" %[^\n]s",newdept);
                    strcpy(t->position, newdept);
                    printf("Updated details:\n");
                    printf("==============================================\n");
                    printf("%d\t%s\t%s\t%d\n",t->data,t->name,t->position,t->age);
                    break;
            default: printf("Enter either '1' or '2'.\n");
        }
    }
}



/*
This function is used to delete a node and return the new root
*/
node *delete(node *root,int i)
{
    if (root==NULL) 
        return NULL;
    if(i<root->data)
        root->lchild=delete(root->lchild, i);
    else if(i>root->data)
        root->rchild=delete(root->rchild, i);
    else
    {   //node with one or no child
        if(root->lchild==NULL)
        {
            node *temp=root->rchild;
            free(root);
            return temp;
        }
    else if(root->rchild==NULL)
        {
             node *temp=root->lchild;
            free(root);
            return temp;
        }
        //node with two children
        //find the inorder successor(minimum node in the right sub-tree)
        node *temp=inorderSuccessor(root->rchild);
        root->data=temp->data;
        root->rchild=delete(root->rchild, i);
    }
    return root;
}



/*
This function is used to find the inorder successor of a node(used for deleting a node with 2 children)
*/
node *inorderSuccessor(node *main)
{
    node *current=main;
    while(current->lchild!=NULL)
        current=current->lchild;
    return current;
}



/*
This function is used to find the inorder Traversal
*/
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
        inorder(temp->rchild);
    }
}



/*
This function is used to find the preorder Traversal
*/
void preorder(node *temp)
{
  if(temp!=NULL)
    {
        preorder(temp->lchild);
        preorder(temp->rchild);
        printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
        
    }
}



/*
This function is used to find the preorder Traversal
*/
void postorder(node *temp)
{
    if(temp!=NULL)
    {
       
        printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
        postorder(temp->lchild);
        postorder(temp->rchild);
    }
}



/*
This function implements depth-first search on the BST
*/
void DFS(node *temp)
{
    if (temp)
    {
        if (temp->rchild)
        {
            DFS(temp->rchild);
        }
        if (temp->lchild)
        {
            DFS(temp->lchild);
        }
        printf("%d\t%s\t%s\t%d\n",temp->data,temp->name,temp->position,temp->age);
    }
}



int continuity()
{
   int choice,sc;
   char c[10];
   printf("\nEMPLOYEES' PORTAL \n");
        printf("==============================================\n");
        printf("1.Create");
        printf("\n2.Update");
        printf("\n3.Search");
        printf("\n4.Delete");
        printf("\n5.Display All");
        printf("\n6.Traversal");
        printf("\n7.Clear screen\n8.Delete All\n9.Exit\nWhat action do you want to perform?\n");
        printf("==============================================\n");
        sc=scanf("%d",&choice); 
        if(sc!=1)
        {
            printf("Please enter a number between 1-8\n");
            scanf("%s", c);
            choice=continuity();
        }
        else
        {
            if(choice==7)
            {
                printf("\e[1;1H\e[2J");
                choice=continuity();
            }
            else
            {
                while(choice<=0||choice>9)
                {
                    printf("Please enter a number from 1-9\nEnter choice:");
                    scanf("%d", &choice);
                }
            }
        }
        return choice;
}



/* 
This function is used to check the value constraints of numbers
*/
int checkAgeNum(int x)
{
    if(x<16||x>100)
        return -1;
    else
        return 0;
}



/*
This function is us


ed to check the strings entered
*/
int checkChar(char name[])
{
    int i=0, c;
    for(i=0; i<strlen(name); i++)
    {
        //printf("%c\n",name[i] );
        if(isalpha(name[i])|| name[i]==' ')
            c=0;
        else
            return -1;
    }
    return 1;
}



node *deleteTree(node *n) 
{
   node *root=NULL;
    if (n == NULL) 
        
        return NULL;
 
    /* first delete both subtrees */
    deleteTree(n->lchild);
    deleteTree(n->rchild);
   
    /* then delete the node */
    printf("\n Deleting node: %d", n->data);
    free(n);
    root=NULL;
    return root;
    
} 

int checkYN(char x[])
{
    if(strcmp(x,"y")==0||strcmp(x,"Y")==0||strcmp(x,"yes")==0||strcmp(x,"Yes")==0||strcmp(x,"YES")==0)
        return 1;
    if(strcmp(x,"n")==0||strcmp(x,"N")==0||strcmp(x,"no")==0||strcmp(x,"No")==0||strcmp(x,"NO")==0)
        return 0;
    if((strcmp(x,"y")!=0&strcmp(x,"Y")!=0&strcmp(x,"yes")!=0&strcmp(x,"Yes")!=0&strcmp(x,"YES")!=0)&(strcmp(x,"n")!=0&strcmp(x,"N")!=0&strcmp(x,"no")!=0&strcmp(x,"No")!=0&strcmp(x,"NO")!=0))
            return 2;

    
}