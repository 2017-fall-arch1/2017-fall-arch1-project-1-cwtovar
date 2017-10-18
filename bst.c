#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include <string.h>		/* for strcmp */ 
#include "bst.h"		/* header file*/

/* create a new tree root */
BSTRoot* bstAlloc(){
  BSTRoot *rp = (BSTRoot *)malloc(sizeof(struct BSTRoot));
  rp->left = rp->right = 0;
  rp->str = 0;
 
  return rp;
}

/* recycle a tree, discarding all items it contains */
void bstFree(BSTRoot *rp){
  bstMakeEmpty(rp);
  free(rp);
}

/* Clear tree and delete all members*/
void bstMakeEmpty(BSTRoot *rp){
  if(rp == NULL) return;
  
  bstMakeEmpty(rp->left);
  bstMakeEmpty(rp->right);
  
  free(rp->str);
  free(rp);
  
  rp->right = rp->left = 0;	/* tree is empty */
  
}
  
/* insert string s into tree */
BSTRoot* add(BSTRoot *rp, char *s){

  /* n = new item containing s */
  BSTRoot *new = (BSTRoot *)malloc(sizeof(struct BSTRoot));
  new->str = s;
  new->left = 0;
  new->right = 0;

  /* insert into tree */
  if(rp== NULL) return new;
  
  else {               /* tree not empty */
    BSTRoot *parent = rp;
    char dir = 0;
    while(dir==0){
      if(strcmp(parent->str, new->str) > 0 ){
	if(parent->left==0){
	  parent->left = new;
	  dir = 0;
	}
	else{
	  parent  = parent->left;
	}
      }
      else{
	if(parent->right==NULL){
	  parent->right = new;
	  dir = 0;
	}
	else{
	  parent =  parent->right;
	}
      }
    }
  }
  return rp;
}

/* remove a member of a tree */
BSTRoot* removeEmp(BSTRoot *rp, char *s){
  if(rp==NULL){			/* not contained within tree*/
    printf(s, " not found in tree. Removal failed.\n");
    return rp;
  }
  if(strcmp(rp->str,s) > 0){		/* if in left side of tree*/
    rp->left = removeEmp(rp->left, s);
  }
  else if(strcmp(rp->str,s) < 0){	/* if in right side of tree*/
    rp->right = removeEmp(rp->right,s);
  }
  else{					/* if found at root*/
    if(rp->left ==NULL){		//removee only has right child
      BSTRoot *temp = rp->right;
      free(rp);
      return temp;
    }
    else if(rp->right == NULL){		//remove only has left child
      BSTRoot *temp = rp->left;
      free(rp);
      return temp;
    }
    BSTRoot *temp = findMin(rp->right);	/*take leftmost value of right subtre*/
    rp->str = temp->str;
    rp->right = removeEmp(rp->right, temp->str);
  }
  return rp;
  
}

/* returns minimum  of a subtree*/
BSTRoot* findMin(BSTRoot *rp){
  while(rp->left != NULL){
    rp = rp->left;
  }
  return rp;
}
/* returns the maximum of a subtree */
BSTRoot* findMax(BSTRoot *rp){
  while(rp->right != NULL){
    rp = rp->right;
  }
  return rp;
}
/* searches for file within tree. Prints "found" if found. returns 0 if not found */
void search(BSTRoot *rp, char *s){
  if(rp == 0){
    printf("Employee not found.\n");
    return;
  }
  if(strcmp(rp->str,s)==0){
      printf("Found: <%s>\n", rp->str);
      return;
    }
    else if(strcmp(rp->str, s) > 0){
	search(rp->left, s); 
     }
    else {
      search(rp->right, s);
    }
     
}

/* print tree with preorder printage */
void bstPrint(BSTRoot *rp){
  if(rp==NULL) return;
  //  bstPrint(rp->left);
  printf(rp->str, "\n ");
  bstPrint(rp->left);
  bstPrint(rp->right);
}

