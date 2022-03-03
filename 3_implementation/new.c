#include "cm.h"
// int i,j=0;

// struct contact s[100],temp;

int search_contact(char temp_name[100], int i, int j, struct contact s[100])
{
	// printf("Enter the Name\t");
	// scanf("%s",temp_name);
	
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			// printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
            return 1;
		}	
	}
	if(i==j)
	{
		// printf("\n Contact Not Found\n");	
        return 0;
	}
}

int delete_contact(char temp_name[100], int i,int j,struct contact s[100],char empty[100],int c)
{
	// printf("Enter the Name\t");
	// scanf("%s",temp_name);
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			strcpy(s[i].name,empty);
			strcpy(s[i].mobileno,empty);
			strcpy(s[i].email,empty);
			// printf("\nContact Successfully Deleted!\n");
			c--;
			return 1;
		}
	}
	if(i==j)
	{
		// printf("\nContact Not found!\n");
        return 0;
	}
}