# sLinkedList_SharedLib_inC
Singly linked list is written in c language and can be used as shared library.

libsLList.dylib is a shared library written in C for creating a singly linked list. It has the following functions for pushing, popping and printing a singly linked list.
1. To push a value as the first node
int push_first(llist **, int );

2. To push a value as the last node
int push_last(llist **, int );

3. To push a node in the existing linked list, after a node with the passed value
int push_value(llist **, int value, int data);

4. To push a node in the linked list to the given index
int push_index(llist **, int index, int data);

5. To print the nodes in the linked list 
void print_list(llist*);

6. To pop the first node
int pop_first(llist **);

7. To pop the last node
int pop_last(llist **);

8. To pop a node after the node with the passed value
int pop_value(llist **, int );

9. To pop a node with the given index in the linked list
int pop_index(llist **, int );

(The linked list only works with integers.)
All the push and print functions are in the sLListPush.c and the pop functions are in the sLListPop.c.
The header sLList.h has the declarations of the linked list structure and all the function declarations.

Creating shared library on mac
-------------------------------
To create the shared library in the mac os, the following commands are used.

gcc -dynamiclib -o libsLList.dylib sLListPop.c sLListPush.c
This command is used to create a shared library instead of executable. This shared library is prefixed with lib and ends with an extension .dylib. 

A snippet of the commands used to create the shared library in mac os in this project 
$ ls                                                            //lists the files in the directory
sLList.c	sLList.h	sLListPop.c	sLListPush.c

$ gcc -dynamiclib -o libsLList.dylib sLListPop.c sLListPush.c   //create shared library libsLList.dylib from                                                                       //sLListPush.c and sLListPop.c

$ file libsLList.dylib                                          //verifying the shared library created
libsLList.dylib: Mach-O 64-bit dynamically linked shared library x86_64

$ ls                                                            //lists the files in the directory
libsLList.dylib	sLList.c	sLList.h	sLListPop.c	sLListPush.c

$ sudo mv sLList.h /usr/include                                 // copy header file to /usr/include

$ sudo mv libsLList.dylib /usr/lib                              //copy the shared library to /usr/lib
$ sudo chmod 755 /usr/lib/libsLList.dylib                       //change mode to make the library an executable

$ gcc -L. -lsLList -o sLListdl sLList.c                         //compile the sLList.c by linking to the shared                                                                    //library libsLList.dylib which is in /usr/lib

$ ls                                                            //lists the files in the directory
sLList.c	sLListdl

$ ./sLListdl                                                    //run the program

$ otool -L sLListdl                                             //check the library dependencies of the                                                                            // application program (sLListdl)
sLListdl:
	libsLList.dylib (compatibility version 0.0.0, current version 0.0.0)
