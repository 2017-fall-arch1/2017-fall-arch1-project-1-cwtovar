#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "bst.h"		/* for list operations */

/* fill current names from file*/
BSTRoot* populate(BSTRoot *rp,FILE *f){
  char *s;
  
  printf("reading from file", s);
  while(fscanf(f,"%s", &s) != EOF){
    // fgets(s,100, f);
    printf("Inserting",s);
    rp = add(rp, s);
    }
    fclose(f);
    return rp;
}

/* write tree contents to file in preorder to maintain tree structure*/
void write(BSTRoot *rp, FILE *f){
  if(rp == NULL) return;
  fputs(rp->str, f);
  write(rp->left,f);
  write(rp->right,f);
}

int main(){
  char buf[100];
  BSTRoot *rp = bstAlloc();	/* make empty list */
  FILE *f = fopen("test.txt", "w");
  rp = populate(rp, f);

  printf("Intitial Tree Contents.\n");
  
  bstPrint(rp);
  printf("\nEnter operation you would like to perform. Use proper letter casing.\n 1-Insert\n 2-Search\n 3-Remove\n");
  printf("Enter \"End\" to quit.\n");
  
  scanf("%s", buf);
 
  while(strcmp("End", buf)!=0){
    if(strcmp("Insert",buf)==0){
      printf("Enter Insertee: ");
      scanf("%s", buf);
      rp =  add(rp,buf);      
    }
    else if(strcmp(buf, "Search")==0){
      printf("Enter Searchee: ");
      scanf("%s",buf);
      search(rp, buf);
    }
    else if(strcmp(buf, "Remove") ==0){
      printf("Enter Employee to be Fired: ");
      scanf("%s", buf);
      rp = removeEmp(rp, buf);
    }
    else{
      printf("Invalid Menu Option Entered.");
    }   
    printf("Enter Next Command: ");
    scanf("%s", buf);
  }
  printf("Tree contents after some operations. \n");
  bstPrint(rp);
  
  FILE *out = fopen("result.txt","w");
  write(rp,out);
  fclose(out);
  bstMakeEmpty(rp);

  return 0;
}
