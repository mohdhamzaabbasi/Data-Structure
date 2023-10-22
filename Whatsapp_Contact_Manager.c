#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
struct node
{
    char name[100];
    long int no;
    struct node* next;
};
struct node* head = NULL;
int add(char name[], long int no) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    strcpy(new_node->name,name);
    new_node->no=no;
    if(head==NULL)
    {
        head=new_node;
        return 1;
    }
    else if(head->next==NULL)
    {
        int c=strcasecmp(new_node->name,head->name);
        if(c>0)
        {
            head->next=new_node;
            return 1;
        }
        else if(c<0)
        {
            new_node->next=head;
            head=new_node;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int i=0;
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            if(i==0)
            {
                i++;
                int cr=strcasecmp(new_node->name,temp->name);
                if(cr<0)
                {
                    new_node->next=head;
                    head=new_node;
                    return 1;
                }
                else if(cr==0)
                {
                    return 0;
                }
            }
            struct node* n=temp->next;
            int c=strcasecmp(n->name,new_node->name);
            if(c>0)
            {
                new_node->next=n;
                temp->next=new_node;
                return 1;
            }
            else if(c<0)
            {
                temp=temp->next;
            }
            else
            {
                return 0;
            }
        }
        temp->next=new_node;
        return 1;
    }
}
int deletena(char name[])
{
    struct node* temp=head;
    if(strcasecmp(temp->name,name)==0)
    {
        head=temp->next;
        free(temp);
        return 1;
    }
    while(temp->next!=NULL)
    {
        struct node* n=temp->next;
        if(strcasecmp(n->name,name)==0)
        {
            temp->next=n->next;
            free(n);
            return 1;
        }
    }
    return 0;
}
int deleteno(long int no)
{
    struct node* temp=head;
    if(temp->no==no)
    {
        head=temp->next;
        free(temp);
        return 1;
    }
    while(temp->next!=NULL)
    {
        struct node* n=temp->next;
        if(n->no==no)
        {
            temp->next=n->next;
            free(n);
            return 1;
        }
    }
    return 0;
}
void searchna(char name[])
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        if(strcasecmp(temp->name,name)==0)
        {
            printf("\nContact Found!!\n");
            printf("%s\t%ld",temp->name,temp->no);
            return;
        }
        temp=temp->next;
    }
    if(strcasecmp(temp->name,name)==0)
    {
        printf("\nContact Found!!\n");
        printf("%s\t%ld",temp->name,temp->no);
        return;
    }
    printf("\nContact not Found!!\n");
}
void searchno(long int no)
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->no==no)
        {
            printf("\nContact Found!!\n");
            printf("%s\t%ld",temp->name,temp->no);
            return;
        }
        temp=temp->next;
    }
    if(temp->no==no)
    {
        printf("\nContact Found!!\n");
        printf("%s\t%ld",temp->name,temp->no);
        return;
    }
    printf("\nContact not Found!!\n");
}
void print()
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        int c=strlen(temp->name);
        printf("%s", temp->name);
        int s=25-c;
        for(int i=0;i<s;i++)
        {
            printf(" ");
        }
        printf("%ld\n",temp->no);
        temp = temp->next;
    }
    int c=strlen(temp->name);
    printf("%s", temp->name);
    int s=25-c;
    for(int i=0;i<s;i++)
    {
        printf(" ");
    }
    printf("%ld\n",temp->no);
}
int count()
{
    struct node* temp = head;
    int count=1;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    add("Abigail Phillips", 8768768769);
	add("Aiden Walker", 7897897890);
	add("Alexander Garcia", 5675675678);
	add("Amelia Brown", 6546546547);
	add("Aria Mitchell", 9129129123);
	add("Aubrey Clark", 4324324325);
	add("Avery Scott", 8908908901);
	add("Benjamin Davis", 7657657658);
	add("Carter White", 1231231234);
	add("Charlotte Rodriguez", 4324324325);
	add("Chloe Wright", 6786786789);
	add("Daniel Turner", 1231231234);
	add("David Lewis", 5435435436);
	add("Ella Davis", 6786786789);
	add("Elijah Anderson", 3213213214);
	add("Elizabeth Foster", 9129129123);
	add("Emily Lewis", 8908908901);
	add("Emma Turner", 3213213214);
	add("Ethan King", 3453453456);
	add("Evelyn Perez", 6546546547);
	add("Grace Smith", 4564564567);
	add("Hannah Scott", 2342342345);
	add("Henry Wilson", 9129129123);
	add("Isabella Baker", 7897897890);
	add("Jackson Butler", 3213213214);
	add("James Mitchell", 5435435436);
	add("Joseph Wilson", 3453453456);
	add("Liam Evans", 9129129123);
	add("Liam Walker", 9129129123);
	add("Lillian Bennett", 9129129123);
	add("Lily Hall", 6786786789);
	add("Lucas Martinez", 9879879870);
	add("Madison Baker", 4324324325);
	add("Mason Rodriguez", 6786786789);
	add("Matthew Martin", 7897897890);
	add("Mia Green", 4564564567);
	add("Michael Moore", 5435435436);
	add("Mila Wood", 4564564567);
	add("Noah Johnson", 3453453456);
	add("Oliver Hall", 7657657658);
	add("Olivia Taylor", 8768768769);
	add("Samuel Mitchell", 9019019012);
	add("Scarlett Adams", 2342342345);
	add("Sebastian Wright", 5675675678);
	add("Sofia Lee", 8908908901);
	add("Sophia Turner", 9129129123);
	add("Sophie Turner", 9129129123);
	add("William Smith", 5675675678);
	add("Zoe Smith", 8768768769);
	add("Mohd Hamza Abbasi", 9336865880);
	add("Aaquib Shaikh", 9336865880);
	add("mohd Humam", 8317003049);
	printf("\n\t\tWHATSAPP CONTACT\n");
	printf("\nTotal Contacts : %d\n\n",count());
	print();
	int choice=0;
	while(choice!=5)
	{
	    printf("\n\nMENU!!\n1-ADD CONTACT\n2-DELETE CONTACT\n3-SEARCH CONTACT\n4-VIEW CONTACT LIST\n5-EXIT\n\nENTER YOUR CHOICE : ");
	    scanf("%d",&choice);
	    printf("\n");
	    switch(choice)
	    {
	        case 1:
	            char name[25];
	            printf("Enter the name followed by a full stop : ");
	            for(int i=0;i<25;i++)
	            {
	                char ch;
	                scanf("%c",&ch);
	                if(ch=='.')
	                {
	                    break;
	                }
	                name[i]=ch;
	            }
	            int k=strlen(name);
	            char arr[25];
	            for(int i=1;i<k;i++)
	            {
	                arr[i-1]=name[i];
	            }
	            strcpy(name,"");
	            long int no;
	            printf("Enter the number:");
	            scanf("%ld",&no);
	            printf("\n");
	            if(add(arr,no)==1)
	            {
	                printf("\nCONTACT ADDED SUCCESSFULLY.\n");
	            }
	            else
	            {
	                printf("\nCONTACT ALREADY EXIST!!");
	            }
	            strcpy(arr,"");
	            break;
	        case 2:
	            printf("\n1-Delete by name.\n2-Delete by number.\nEnter your choice:");
	            int x;
	            scanf("%d",&x);
	            int y=0;
	            int z=0;
	            if(x!=1&&x!=2)
	            {
	                printf("\nWRONG CHOICE!!\n");
	                break;
	            }
	            if(x==1)
	            {
	                char name[25];
    	            printf("Enter the name followed by a full stop : ");
	                for(int i=0;i<25;i++)
	                {
	                    char ch;
	                    scanf("%c",&ch);
	                    if(ch=='.')
    	                {
	                        break;
	                    }
	                    name[i]=ch;
	                }
    	            int k=strlen(name);
	                char arr[25];
	                for(int i=1;i<k;i++)
	                {
	                    arr[i-1]=name[i];
    	            }
    	            y=deletena(arr);
	            }
	            else if(x==2)
	            {
	                long int no;
    	            printf("\nEnter the number:");
	                scanf("%ld",&no);
	                z=deleteno(no);
	            }
	            if(y+z==0)
	            {
	                printf("\nCONTACT NOT FOUND!!\n");
	            }
	            else
	            {
	                printf("\nCONTACT DELETED SUCCESSFULLY.\n");
	            }
	            break;
	        case 3:
	            printf("\n1-Search by name.\n2-Search by number.\nEnter your choice:");
	            scanf("%d",&x);
	            if(x!=1&&x!=2)
	            {
	                printf("\nWRONG CHOICE!!\n");
	                break;
	            }
	            if(x==1)
	            {
	                char name[25];
    	            printf("Enter the name followed by a full stop : ");
	                for(int i=0;i<25;i++)
	                {
	                    char ch;
	                    scanf("%c",&ch);
	                    if(ch=='.')
    	                {
	                        break;
	                    }
	                    name[i]=ch;
	                }
    	            int k=strlen(name);
	                char arr[25];
	                for(int i=1;i<k;i++)
	                {
	                    arr[i-1]=name[i];
    	            }
	                searchna(arr);
	            }
	            else if(x==2)
	            {
	                long int no;
    	            printf("\nEnter the number:");
	                scanf("%ld",&no);
	                searchno(no);
	            }
	            break;
	        case 4:
	            printf("\n--------------------------------------------------------------------------------------------------\n");
	            printf("\n\t\tWHATSAPP CONTACT\n");
	            printf("\nTotal Contacts : %d\n\n",count());
	            print();
	            printf("\n--------------------------------------------------------------------------------------------------\n");
	            break;
	        case 5:
	            printf("\nTHANKYOU!!");
	            return 0;
	            break;
	        default:
	            printf("WRONG CHOICE!!\nTRY AGAIN!!");
	            break;
	    }
	}
    return 0;
}
