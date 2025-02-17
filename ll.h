#include <string.h>
// self-referential structure
struct Node
{
   struct Node *prePtr;
   int data;
   char name[15];             // each listNode contains a character
   struct Node *nextPtr; // pointer to next node
}; // end structure listNode

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode *LLPtr;      // synonym for ListNode*

// prototypes

int deletes(LLPtr *sPtr, int value);
int isEmpty(LLPtr sPtr);
void insert(LLPtr *sPtr, int value, char name[]);
void printList(LLPtr currentPtr);
void printListR(LLPtr currentPtr);
void instructions(void);
void deleteall(LLPtr *sPtr);

// display program instructions to user
void instructions(void)
{
   puts("Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to end.");
} // end function instructions

// insert a new value into the list in sorted order
void insert(LLPtr *sPtr, int value, char name[])
{
   LLPtr newPtr;      // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr;  // pointer to current node in list

   newPtr = (LLPtr)malloc(sizeof(LLnode)); // create node

   if (newPtr != NULL)
   { // is space available

      newPtr->data = value;   // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node
      strcpy(newPtr->name,name);
      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && value > currentPtr->data)
      {
         previousPtr = currentPtr;         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if (previousPtr == NULL)
      {
         newPtr->nextPtr = *sPtr;
         if (*sPtr)
            (*sPtr)->prePtr = newPtr;
         *sPtr = newPtr;

      } // end if
      else
      { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->prePtr = previousPtr;

         newPtr->nextPtr = currentPtr;
         if (currentPtr != NULL)
            currentPtr->prePtr = newPtr;
      } // end else
   } // end if
   else
   {
      printf("%d not inserted. No memory available.\n", value);
   } // end else
} // end function insert

// delete a list element
int deletes(LLPtr *sPtr, int value)
{
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr;  // pointer to current node in list
   LLPtr tempPtr;     // temporary node pointer

   // delete first node
   if (value == (*sPtr)->data)
   {
      tempPtr = *sPtr;          // hold onto node being removed
      *sPtr = (*sPtr)->nextPtr; // de-thread the node
      if(*sPtr) (*sPtr)->prePtr= NULL;
      
      
      
      free(tempPtr);            // free the de-threaded node
      return value;
   } // end if
   else
   {
      previousPtr = *sPtr;
      currentPtr = (*sPtr)->nextPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value)
      {
         previousPtr = currentPtr;         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if (currentPtr != NULL)
      {
         tempPtr = currentPtr;
         if(previousPtr)previousPtr->nextPtr = currentPtr->nextPtr;
         if(currentPtr->nextPtr)currentPtr->nextPtr->prePtr = previousPtr;
         free(tempPtr);
         return value;
      } // end if
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty(LLPtr sPtr)
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList(LLPtr currentPtr)
{
   // if list is empty
   if (isEmpty(currentPtr))
   {
      puts("List is empty.\n");
   } // end if
   else
   {
      puts("The list is:");

      // while not the end of the list
      while (currentPtr->nextPtr != NULL)
      {
         printf("%d %s --> ", currentPtr->data,currentPtr->name);
         currentPtr = currentPtr->nextPtr;
      } // end while
       
      printf("%d %s --> NULL\n", currentPtr->data,currentPtr->name);

   } // end else
} // end function printList
void printListR(LLPtr currentPtr)
{

   if (isEmpty(currentPtr))
   {
      puts("List is Empty so cant ptint reverse");
   }
   else
   {
      while (currentPtr->nextPtr != NULL)
      {
         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      }
      puts("The reversed list is:"); 
      while (currentPtr->prePtr != NULL)
      {
         printf("%d %s --> ", currentPtr->data,currentPtr->name);
         if(currentPtr->prePtr)currentPtr = currentPtr->prePtr;
      }
      if(currentPtr)printf("%d %s --> ", currentPtr->data,currentPtr->name);
      printf("NULL\n");
   }
}
void deleteall(LLPtr *sPtr){
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr = *sPtr;  // pointer to current node in list
   LLPtr tempPtr; 
tempPtr = currentPtr;
while(currentPtr){
   tempPtr = currentPtr;
   currentPtr = currentPtr->nextPtr;
   printf("delete %d \n",tempPtr->data);
   free(tempPtr);


}
}