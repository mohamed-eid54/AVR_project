#include <stdio.h>
#include <stdlib.h>
#include "type.h"
typedef struct node
{
    char Name[100];
    int age;
    char gender[100];
    long long ID;
    struct node * next;
}Node;

Node * head;
Node * last;
int size;

void createnode(void)
{
    head=NULL;
    last=NULL;
    size=0;
}

void insertfirst()
{
    int n=0;
    Node*newnode=(Node*)malloc(sizeof(Node));

    if(newnode==NULL)
    {
        printf("Memory was not allocated");
    }
    else
    {
        if(head==NULL)
        {
            last=newnode;
            newnode->next = head;
            printf("please enter the patient name : ");
            scanf("%s",&newnode->Name);
    
            printf("please enter the patient age: ");
            scanf("%d",&newnode->age);
    
            printf("please enter the patient gender: ");
            scanf("%s",&newnode->gender);
    
            printf("please enter the patient ID: ");
            scanf("%lld",&newnode->ID);
            head = newnode;
            size++;
            printf("***********the patient is added successfully************\n");
        }
        else if(head!=NULL)
        {
            newnode->next = head;
            printf("please enter the patient name : ");
            scanf("%s",&newnode->Name);
    
            printf("please enter the patient age: ");
            scanf("%d",&newnode->age);
    
            printf("please enter the patient gender: ");
            scanf("%s",&newnode->gender);
    
            printf("please enter the patient ID: ");
            scanf("%lld",&newnode->ID);

            Node*ptr2=newnode;
            Node*ptr=head;
            for(int i=0;i<size;i++)
            {
                if(ptr->ID==ptr2->ID)
                {
                    printf("the ID is not allowed\n");
                    free(ptr2);
                    ++n;
                    break;
                }
                else if(ptr->ID!=newnode->ID)
                {
                    ptr=ptr->next;
                }
            } 
            if(n==0)
            {
                head = newnode;
                size++;
                printf("***********the patient is added successfully************\n");
            }
        }
    }
}
void editdata()
{
    int z=0;
    long long id;
    printf("please enter the patient ID :");
    scanf("%lld",&id);
    Node*ptr=head;
    for(int i=0;i<size;i++)
    {
        if(ptr->ID!=id)
        {
            ptr=ptr->next;
        }
        else if(ptr->ID==id)
        {
            z++;
            break;
        }
    }
    if(z==0)
    {
        printf("ID is not found\n");
    }
    else
    {
        printf("Enter your new name :");
        scanf("%s",&ptr->Name);
    
        printf("Enter your new age :");
        scanf("%d",&ptr->age);
    
        printf("Enter your new gender :");
        scanf("%s",&ptr->gender);

        printf("Enter your new ID :");
        scanf("%lld",&ptr->ID);
        printf("******the patient record is edited successfully*********\n");
        /*printf("%s\n",ptr->Name);
        printf("%d\n",ptr->age);
        printf("%s\n",ptr->gender);
        printf("%lld",ptr->ID);*/
    }
}
int arr[5]={0,0,0,0,0},r=0;
void reverseslot()
{

int idd=0,z=0;
printf("there are the availance slots :\n");
if(arr[0]==0)
printf("Enter [1] for reserved date from 2pm to 2,30pm\n");

if(arr[1]==0)
printf("Enter [2] for reserved date from 2,30pm to 3pm\n");

if(arr[2]==0)
printf("Enter [3] for reserved date from 3pm to 3,30pm\n");

if(arr[3]==0)
printf("Enter [4] for reserved date from 4pm to 4,30pm\n");

if(arr[4]==0)
printf("Enter [5] for reserved date from 4,30pm to 5pm\n");

printf("Enter your choice: ");
scanf("%d",&r);

printf("please enter the ID :");
scanf("%d",&idd);

Node *ptr=head;
for(int j=0;j<size;j++)
{
    if(ptr->ID==idd)
    {
        ++z;
        break;
    }
    ptr=ptr->next;
}

if(z==0)
{
    printf("*****ID id is not found******\n");
}
else
{
    printf("****the slot is reserved successfully****\n");
    r=r-1;
    arr[r]=idd;
}        
}
void cancelreservation()
{
    int id=0,v=0;
    printf("Enter the ID :");
    scanf("%d",&id);
    for(int i=0;i<5;i++)
    {
        if(arr[i]==id)
        {
            arr[i]=0;
            printf("****success cancel reservation process*****\n");
            ++v;
            //break;
        }
    }
    if(v==0)
    {
        printf("id is wrong\n");
    }
}
void viewpatientrecord()
{
    int id=0,m=-1,t=0;
    printf("please enter patient id :");
    scanf("%d",&id);
    Node*ptr=head;
    for(int i=0;i<size;i++)
    {
        if(ptr->ID==id)
        {
            t=1;
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }

    for(int j=0;j<5;j++)
    {
        if(arr[j]==id)
        {
            m=j;
            break;
        }
        else
        {
            continue;
        }
    }
    if(t==1)
    {
        printf("****************patient record******************\n");
        printf("                **************                  \n");
        printf("Name : %s\n",ptr->Name);
        printf("Age : %d\n",ptr->age);
        printf("gender : %s\n",ptr->gender);
        printf("ID : %lld\n",ptr->ID);
        switch(m)
        {
            case -1:
            {
                printf("this patient did not reserve any slots\n");
                break;
            }
            case 0:
            {
                printf("from 2pm to 2,30pm is reserved ID num :%d\n",arr[m]);
                break;
            }
            case 1:
            {
                printf("from 2,30pm to 3pm is reserved by ID num:%d\n",arr[m]);
                break;
            }
            case 2:
            {
                printf("from 3,30pm to 4pm is reserved ID num :%d\n",arr[m]);
                break;
            }
            case 3:
            {
                printf("from 4pm to 4,30pm is reserved ID num :%d\n",arr[m]);
                break;
            }
            case 4:
            {
                printf("from 4,30pm to 5pm is reserved ID num : %d\n",arr[m]);
                break;
            }
        }
    }
    else if(t==0)
    {
        printf("ID is not found\n");
    }
}
void viewreservation()
{
    printf("********Today reservations*********\n");
    printf("        *******************        \n");
    int h=0;
    for(int i=0 ;i<5;i++)
    {
        if(arr[i]!=0)
        {
            h=1;
            switch(i)
        {
            case 0:
            {
                printf("from 2pm to 2,30pm is reserved by ID num :%d\n",arr[i]);
                break;
            }
            case 1:
            {
                printf("from 2,30pm to 3pm is reserved by ID num:%d\n",arr[i]);
                break;
            }
            case 2:
            {
                printf("from 3,30pm to 4pm is reserved by ID num :%d\n",arr[i]);
                break;
            }
            case 3:
            {
                printf("from 4pm to 4,30pm is reserved by ID num :%d\n",arr[i]);
                break;
            }
            case 4:
            {
                printf("from 4,30pm to 5pm is reserved by ID num : %d\n",arr[i]);
                break;
            }
        }
        }
    }
    if(h==0)
    printf("There is no appoinntments reserved\n");
}
int main(void)
{
    int k=0,pass=0,ch1=0,ch2=0;
    while(1)
    {
        printf("************************************************************************************\n");
        printf("*******************************welcome to life clinic*******************************\n");
        printf("************************************************************************************\n");
        printf("To enter admin mode enter number [1]\nto enter user mode enter number [2]\nto exit the program enter number [3]\n");
        printf("your choice :");
        scanf("%d",&k);
        if(k==1)
        {
            printf("******************************************************************************************\n");
            printf("***********************************Admin mode***********************************************\n");
            printf("******************************************************************************************\n");
            printf("please enter the password :");
            
            for(int i=0;i<3;i++)
            {
                scanf("%d",&pass);
                if(pass==1234)
                {
                    break;
                }
                else
                {
                    if(i!=2)
                    printf("wrong password try again\n");
                    else if(i==2)
                    printf("wrong password\n");
                    continue;
                }
            }
            if(pass==1234)
            {
                printf("******************************************************************************************\n");
                printf("******************************welcome in admin mode*************************************\n");
                printf("******************************************************************************************\n");
                printf("to add new patient enter 1\nto edit patient record enter 2\nto reverse aslot with the doctor enter 3\n");
                printf("to cancel resevation enter 4\nto exit the program enter 0\nyour choice :");
                
                scanf("%d",&ch1);
                if(ch1==1)
                {
                    insertfirst();
                    continue;
                }
                else if(ch1==2)
                {
                    editdata();
                    continue;
                }
                else if(ch1==3)
                {
                    reverseslot();
                    continue;
                }
                else if(ch1==4)
                {
                    cancelreservation();
                    continue;
                }
                else if(ch1==0)
                {
                    continue;
                }
                
            }

        }
        else if(k==2)
        {
            printf("******************************************************************************************\n");
            printf("***********************************User mode***********************************************\n");
            printf("******************************************************************************************\n");
            printf("To display patient file enter[1]\nTo view today reservations enter[2]\nto exit program enter[0]\nyour choice: ");
            scanf("%d",&ch2);
            if(ch2==1)
            {
                viewpatientrecord();
                continue;
            }
            else if(ch2==2)
            {
                viewreservation();
                continue;
            }
            else if(ch2==0)
            {
                continue;
            }
        }
        else if(k==3)
        {
            printf("***************************************************\n");
            printf("*******************Good Bye************************\n");
            printf("***************************************************\n");
            break;
        }
    }
        
    return 0;
}
