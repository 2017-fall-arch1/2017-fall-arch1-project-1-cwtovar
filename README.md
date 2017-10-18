# arch1-binary-search-tree-demo

This directory contains:
* code that implements a binary search tree of strings 
* a demo program that uses it
* a text file that can have multiple lines of 1 string per line

The demo creates a preliminary BSTree from what it reads from 'test.txt'
    -(file may be empty to initialize empty BSTree at begining of program).
    
Each line is inserted into tree via 'add' into BSTree
After end-of-file is read, the lines are printed out.
Next, User Interface is displayed giving options to perform operations  with tree
When operations have been completed the resulting tree is written to a file called 'result.txt'

This demo contains the following files:
 bst.h: header file of bst structure & "public" interface functions
 llist.c: implementation of linked list
 listDemo.c: a demonstration program that uses the linked list
 

To compile:
~~~
$ make bstDemo
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~
