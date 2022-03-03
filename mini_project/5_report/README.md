
# Requirements
## Introduction

The project is titled as contact-management and developed using C language. It is used to add contact details, view the details, search details,delete contact details and save contacts. This can be used to perform CRUD operations like store contacts with First name, Last name, Phone Number & Email and these details are entered by the user. The features of this contact-management include searching a contact by First name,Last name, Phone number and Email id. User has an option to delete a contact by phone number.



## contact-mangement features::

1) add new contacts with inforamation such as name,phone number,address,email id
2) list all contacts stored in file with their respective contact details
3) search contacts based on name and phone number
4) edit information given while adding the contacts-name,phonr no,address,and email id
5) delete contacts from files


## Advantages

1) Improved data management
2) Easy and faster access
3) Better, longer-lasting customer relationship
4) No hassle of physical maintenance of diaries
5) Backups available in case of unexpected activities

## SWOT ANALYSIS

STRENGTHS
- Easy to use application has all required features capable of storing data to a database faster access to data.

WEAKNESS
- Lack of graphical user interface no option to change default database no scope of integration.

OPPORTUNITIES
- Required by most of the people can add more features develop a gui.

THREATS
- Lot of competitors other better applications available with advanced


## 4 W's and 1 H

 1) Who ?
  - Anyone with an electronic device with a display and has a requirement of a contact management.

 2) What ?
 - A contact management with features like add, delete, search, display and store data to a file.

 3) When ?
- It can be used when there is no access to physical notebook and has lot of data to store.

 4) Where ?
- It can be used in all sectors irrespective of their field of work.

 5) How ?
- This application was developed in C language to avoid hassle of maintaining bulky diaries.
      
      
   
 ##  High Level Requirements
 
|RDI| Description|	Status|
|----|----|----|
|HLR1|  Main Menu| 	Implemented|
|HLR2| Data Storing| Implemented|
|HLR3| Data Retrieval| Implemented|

## Low Level Requirement

|RID| Description|Status|
|----|----|----|
|LLR1| New contact shall be added by providing all the needed information and stored into structure.| Implemented|
|LLR2| Reading contact data is be possible in 5 ways, first being by searching by first name, last name, phone number email id and by printing all the contacts available| Implemented|
|LLR3| All the data should be stored into a file when user wants to do it.| Implemented|
|LLR4| If user searches for an invalid key "Contact not found" message should be displayed| Implemented|
|LLR5| User shall be able to save the files, if file already exists then it should append to file and should not overwrite it and if file does not exists then it should create a new file | Implemented|




# Defineing our contact-management system



![contact management](https://user-images.githubusercontent.com/98831772/154861317-4e041912-c9e1-4223-a20f-007167a7e142.png)



# Project Diagram

![Activity_Diagram](https://user-images.githubusercontent.com/98831772/154861345-a81a8991-79f6-43c8-b7a0-8d965b17d2bd.png)




#   TESTPLAN 



# High level Test Plan

|TEST ID   |DESCRIPTION  	              |EXPECTED I/P |Exp. O/p |Actual O/p |Pass or Fail |
|---- |---- |---- |---- |---- |---- |
|HLT_01	|To Add Contact |Choice 1 |Enter the contact detail |Enter the contact detail |pass |
|HLT_02	|To Delete Contact |Choice 2, Enter the Contact name  |Contact Deleted Successfully |Contact Deleted Successfully|Pass | 
|HLT_04	 |To Search Contacts |Choice 3, Enter Contact name  |Contact information |Contact information |Pass |
|HLT_02	|To Contact Book |Choice 2, |Display of all the Contact details |Display of all the Contact details |Pass | 
|HLT_06	 |To Exit Contact |Choice 5 |Successfully Exited |Successfully Exited |Pass |










# Low Level Test Plan

|TEST ID     	|DESCRIPTION	  |EXPECTED I/P |Exp. O/p |Actual O/p |Pass or Fail |
|---- |---- |---- |---- |---- |----|
|LLT_01 |Enter Contact Name in Add |Eg. Danesh |Move to Next |Move |Pass |
|LLT_02	|Enter the Contact Phone No  in Add |Eg. 7788665544 |Move to Next  |Move  |Pass |
|LLT_03	|Enter the Email id in Add |Eg.spdanu2715@gmail.com |Contac Saved Successfully|Contact Saved Successfully|Pass |





# OUTPUT

## ADD CONTACT
![add contact](https://user-images.githubusercontent.com/98831772/155016149-fb8d315b-9574-4639-adcb-d2484592fe84.PNG)

## SEARCH CONTACT
![search](https://user-images.githubusercontent.com/98831772/155016502-857255ee-4ded-4f03-a55b-97209042e0d5.PNG)


## CONTACT BOOK
![contact book](https://user-images.githubusercontent.com/98831772/155016606-2a5b0e04-b6bf-49dc-8073-016c5c125d70.PNG)


## DELETE CONTACT
![delete](https://user-images.githubusercontent.com/98831772/155016738-54dd3005-57c8-46ce-a8cf-d98b252e6ae6.PNG)


## EXIT
![exit](https://user-images.githubusercontent.com/98831772/155016833-5989a491-3544-44f8-9bcb-18405aff9732.PNG)









