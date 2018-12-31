#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));

      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;

   } else { /* recursively call ll_add_to_tail until we get to the tail
					which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;

   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
      llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value (llnode *pList, int val) {
   /* Make sure pList pointer exists */
   if (pList == NULL) {

      return -1;
   }
   /* If current pointer's val equals inputted val */
   if ((pList) -> val == val) {
      return 0;
   }
   /* Recursively point to the next element in the list */
   else {
      return ll_find_by_value((pList) -> next, val);
   }
}

int ll_del_from_tail(llnode **ppList) {
   /*Make sure ppList double pointer and single pointer exists */
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }
   /* If the list has one element */
   if ((*ppList) -> next == NULL) {
      free(*ppList);
      return 0;
   }
   else {
      /* Else if the list has more than one element */
      llnode *f = (*ppList) -> next; /* Hold next element in pointer f */
      if (f -> next == NULL) { /* If the 'next' pointer in f is NULL, you found the last element */
         free(f);

         (*ppList) -> next = NULL;
         return 0;
      }
      else {

         return ll_del_from_tail (&f);
      }
   }
}

int ll_del_from_head(llnode **ppList) {
   /* Make sure ppList double pointer and single pointer exists */
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   } else {
      /* Save a copy of the address 'next' points to and set it equal to the linked list's starting position */
      llnode *f = (*ppList) -> next;
      free(*ppList);
      *ppList = f;
      return 0;
   }
}

int ll_del_by_value(llnode **ppList, int val) {
   llnode *currP = *ppList, *prevP = NULL;
   
   /* Make sure ppList double pointer exists */
   if (ppList == NULL) {
      return -1;
   }
   /* Make sure ppList pointer exists */
   if (*ppList == NULL) {
      return -1;
   }

   /* While the end of the list has not been reached */
   while (currP != NULL) {
      /* If the desired element has been found */
      if (currP -> val == val) {
         /* If the element is the first one in the list */
         if (prevP == NULL) {
            prevP = *ppList;
            *ppList = currP -> next;
            free(prevP);
         /* Else */
         } else {
            prevP -> next = currP -> next;
            free(currP);
         }

         return 0;
      /* Else */
      } else {
         prevP = currP;
         currP = currP -> next;
      }
   }

   return -1;
}

int ll_insert_in_order(llnode **ppList,int val) {
   llnode *currP = *ppList, *prevP = NULL;
   
   /* Make sure ppList double pointer exists */
   if (ppList == NULL) {
      return -1;
   }
   /* Make sure ppList pointer exists */
   if (*ppList == NULL) {
      return -1;
   }

   /* While the end of the list has not been reached */
   while (currP != NULL) {
      /* If the desired element has been reached */
      if (prevP != NULL) {
         if ((val >= prevP -> val) && (val <= currP -> val)) {
            llnode *newE = (llnode *)malloc(sizeof(llnode));
            newE -> val = val;
            newE -> next = currP;
            prevP -> next = newE;
            return 0;
         }
      }
      prevP = currP;
      currP = currP -> next;
   }   

   return -1;
}

int ll_concat(llnode **pSrcA,llnode **pSrcB) {
   /* Make sure the two linked lists exist */
   if (pSrcA == NULL || pSrcB == NULL) {
      return -1;
   }
  
   /* Make sure linked list pointers exist */
   if (*pSrcA == NULL || *pSrcB == NULL) {
      return -1;
   }
 
   /* If the last element in list pSrcA has been reached */
   if ((*pSrcA) -> next == NULL) {
      (*pSrcA) -> next = *pSrcB;
   } else {
      ll_concat(&((*pSrcA)->next),pSrcB);
   }
}

int ll_sort(llnode **ppList) {
   int swapped = 1;

   /* Make sure ppList double pointer exists */
   if (ppList == NULL) {
      return -1;
   }
   /* Make sure ppList pointer exists */
   if (*ppList == NULL) {
      return -1;
   }

   /* Sorting algorithm - repeat until a swap does not occur */
   while (swapped) {
      llnode *currP = *ppList, *prevP = NULL;
      swapped = 0;
      /* While the end of the list has not been reached */
      while (currP != NULL) {
         if (prevP != NULL) {
            if (prevP -> val > currP -> val) {
               int temp = prevP -> val;
               prevP -> val = currP -> val;
               currP -> val = temp;
               swapped = 1;
            }
         }
         prevP = currP;
         currP = currP -> next;
      }
   }

   return 0;
}
