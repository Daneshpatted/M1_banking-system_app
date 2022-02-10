
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
struct contact
{
    long ph;
    char name[20],add[20],email[30];
} list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
main:
    system("cls");    /* *****Main menu *******  */
    printf("\n\t  WELCOME TO CONTACT-MANAGEMENT SYSTEM ");
    printf("\n\n\n\t\tMAIN MENU\n\t\t=========\n\t\t1) add a new Contact\n\t\t2) list all Contacts\n\t\t3) search for contact\n\t\t4) edit a Contact\n\t\t5) delete a Contact\n\t\t0) exit\n\t\t=================\n\t\t");
    printf("enter the choice:");
    scanf("%d",&ch);
    switch(ch)
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
            printf("to exit enter  space in the name input\nName (Use identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("phone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("Address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("Email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
        /* $$$$$$ list of contacts $$$$$$  */
    case 2:
        system("cls");
        printf("\n\t\t=======\n\t\t\tlist of contacts\n\t\t===========\n\nname\t\tphone No\t    Address\t\tE-mail ad.\n======\n\n");
        for(i=97; i<=122; i=i+1)
        {
            fp=fopen("contact.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,
                           list.ph,list.add,list.email);
                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========== [%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
        }
        break;
        /* *******************search contacts**********************  */
    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\n\t..::contact search\n\t=========\n\t..::name of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
            {
                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("..::press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\n..::no match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n ..::try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;
        /* ********************edit contacts************************/
    case 4:
        system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::edit contact\n========\n\n\t..::enter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
              fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::Address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::Email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
        /* ********************delete contacts**********************/
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::delete contact\n\t=======\n\t..::enter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
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
    scanf("%d",&ch);
    switch (ch)
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
