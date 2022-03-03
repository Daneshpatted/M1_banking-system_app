<<<<<<< HEAD
/**
 * @file cm.h
 * @author Daneshpatted
 * @brief 
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CONTACT_H
#define _CONTACT_H


//include declaration
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure declaration
struct contact
{
	char name[100];
	char mobileno[100];
	char email[200];
};
int search_contact(char temp_name[100],int i,int j,struct contact s[100]);
int delete_contact(char temp_name[100],int i,int j,struct contact s[100],char empty[100],int c);
=======
/**
 * @file cm.h
 * @author Daneshpatted
 * @brief 
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CONTACT_H
#define _CONTACT_H


//include declaration
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure declaration
struct contact
{
	char name[100];
	char mobileno[100];
	char email[200];
};
int search_contact(char temp_name[100],int i,int j,struct contact s[100]);
int delete_contact(char temp_name[100],int i,int j,struct contact s[100],char empty[100],int c);
>>>>>>> d347b54734bbaafec768272f61f3ede1712735a7
#endif