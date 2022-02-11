
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
struct contact
{
    long ph;
    char Name[20],Add[20],email[30];
} list;
char Query[20],Name[20];
FILE *fp, *ft;
int j,n,chr,l,Found;
int main()
{
main:
    system("cls");    /* *****Main menu *******  */
    printf("\n\t  WELCOME TO CONTACT-MANAGEMENT SYSTEM ");
    printf("\n\n\n\t\tMAIN MENU\n\t\t=========\n\t\t1) Add a new Contact\n\t\t2) list all Contacts\n\t\t3) search for contact\n\t\t4) edit a Contact\n\t\t5) delete a Contact\n\t\t0) exit\n\t\t=================\n\t\t");
    printf("enter the choice:");
    scanf("%d",&chr);
    switch(chr)
    {
    case 0:
        printf("\n\n\t\tare you sure you want to exit?");
        break;
    case 1:
        system("cls");
        fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("to exit enter  space in the Name input\nName (Use identical):");
            scanf("%[^\n]",&list.Name);
            if(stricmp(list.Name,"")==0 || stricmp(list.Name," ")==0)
                break;
            fflush(stdin);
            printf("phone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("Address:");
            scanf("%[^\n]",&list.Add);
            fflush(stdin);
            printf("Email Address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
        /* $$$$$$ list of contacts $$$$$$  */
    case 2:
        system("cls");
        printf("\n\t\t=======\n\t\t\tlist of contacts\n\t\t===========\n\nName\t\tphone No\t    Address\t\tE-mail ad.\n======\n\n");
        for(j=97; j<=122; j=j+1)
        {
            fp=fopen("contact.dll","r");
            fflush(stdin);
            Found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.Name[0]==j || list.Name[0]==j-32)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.Name,
                           list.ph,list.Add,list.email);
                    Found++;
                }
            }
            if(Found!=0)
            {
                printf("=========== [%c]-(%d)\n\n",j-32,Found);
                getch();
            }
            fclose(fp);
        }
        break;
        /* $$$$$$$$****search contacts*****$$$$$$$  */
    case 3:
        system("cls");
        do
        {
            Found=0;
            printf("\n\n\t..::contact search\n\t=========\n\t..::Name of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&Query);
            l=strlen(Query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n================\n",Query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(j=0; j<=l; j++)
                    Name[j]=list.Name[j];
                Name[l]='\0';
                if(stricmp(Name,Query)==0)
            {
                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.Name,list.ph,list.Add,list.email);
                    Found++;
                    if (Found%4==0)
                    {
                        printf("..::press any key to continue...");
                        getch();
                    }
                }
            }
            if(Found==0)
                printf("\n..::no match Found!");
            else
                printf("\n..::%d match(s) Found!",Found);
            fclose(fp);
            printf("\n ..::try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&chr);
        }
        while(chr==1);
        break;
        /* $$$$$$$$$$$$*********edit contacts*********$$$$$$$$$$$$ */
    case 4:
        system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::edit contact\n========\n\n\t..::enter the Name of contact to edit:");
        scanf("%[^\n]",Name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(Name,list.Name)!=0)
              fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",Name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.Name);
        fflush(stdin);
        printf("..::phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::Address:");
        scanf("%[^\n]",&list.Add);
        fflush(stdin);
        printf("..::Email Address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
        /* $$$$$$$**********delete contacts********$$$$$$$$ */
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::delete contact\n\t=======\n\t..::enter the Name of contact to delete:");
        scanf("%[^\n]",&Name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(Name,list.Name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    default:
        printf("invalid choice");
        break;
    }
    printf("\n\n\n..::enter the Choice:\n\n\t[1] main menu\t\t[0] exit\n");
    scanf("%d",&chr);
    switch (chr)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("invalid choice");
        break;
    }
    return 0;
}
