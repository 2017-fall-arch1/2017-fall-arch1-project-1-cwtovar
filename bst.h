#ifndef bst_included		/* prevent multiple inclusion */
#define bst_included

/* a tree of BST Nodes */
typedef struct BSTRoot{
  struct BSTRoot *left, *right;
  char *str;
} BSTRoot;

/*create a new tree */
BSTRoot* bstAlloc();

/* free memory associated with a bst, discarding all items it contains */
void bstFree(BSTRoot *rp);

/* insert a str into BinarySearchTree */
BSTRoot* add(BSTRoot *rp, char *s);

/* Delete all elements of the tree */
void bstMakeEmpty(BSTRoot *rp);

/* print tree data.  Prints in default format if message is NULL */
void bstPrint(BSTRoot *rp);

/* retrieves the smallest node in a subtree */
BSTRoot* findMin(BSTRoot *rp);

/*retrieves the largest node in subtree */
BSTRoot* findMax(BSTRoot *rp);

/* removes an item from tree*/
BSTRoot* removeEmp(BSTRoot *rp, char *s);

/* search for a string within tree*/
void search(BSTRoot *rp, char *s);

#endif	/* included */
