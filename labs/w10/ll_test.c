#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *other1 = NULL;
   llnode *other2 = NULL;
   llnode *root = NULL;
   int r=0;
   int i=0;

   /* Fill root linked list */
   r=ll_add_to_head(&root,1300);
   r=ll_add_to_head(&root,1200);
   r=ll_add_to_head(&root,1100);
   for(i=5;i<=9;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }
   for(i=0;i<=4;i=i+1){
      r=ll_add_to_head(&root,i*100);
   }

   /* Fill other1 linked list */
   r=ll_add_to_tail(&other1,-100);

   /* Fill other2 linked list */
   r=ll_add_to_head(&other2,-200);
   r=ll_add_to_head(&other2,400);

   /* Print root list, search for 2000, print outpue */
   r=ll_print(root);
   r=ll_find_by_value(root,2000);
   printf("ll_find_by_value output for 2000: %d\n",r);
   printf("\n");

   /* Print root list, search for 600, print output */
   r=ll_print(root);
   r=ll_find_by_value(root,600);
   printf("ll_find_by_value output for 600: %d\n",r);
   printf("\n");

   /* Print root list, delete last element, print updated list */
   printf("BEFORE DELETING LAST ELEMENT (1)\n");
   r=ll_print(root);
   printf("AFTER DELETING LAST ELEMENT (1)\n");
   r=ll_del_from_tail(&root);
   r=ll_print(root);
   printf("\n");

   /* Print root list, delete last element, print updated list */
   printf("BEFORE DELETING LAST ELEMENT (2)\n");
   r=ll_print(root);
   printf("AFTER DELETING LAST ELEMENT (2)\n");
   r=ll_del_from_tail(&root);
   r=ll_print(root);
   printf("\n");

   /* Print root list, delete first element, print updated list */
   printf("BEFORE DELETING FIRST ELEMENT (1)\n");
   r=ll_print(root);
   printf("AFTER DELETING FIRST ELEMENT (1)\n");
   r=ll_del_from_head(&root);
   r=ll_print(root);
   printf("\n");

   /* Print root list, delete first element, print updated list */
   printf("BEFORE DELETING FIRST ELEMENT (2)\n");
   r=ll_print(root);
   printf("AFTER DELETING FIRST ELEMENT (2)\n");
   r=ll_del_from_head(&root);
   r=ll_print(root);
   printf("\n");

   /* Print root list, delete first instance of 1300, print updated list */
   printf("BEFORE DELETING FIRST INSTANCE OF 1300 (1)\n");
   r=ll_print(root);
   r=ll_del_by_value(&root,1300);
   printf("AFTER DELETING FIRST INSTANCE OF 1300 (1)\n");
   r=ll_print(root);
   printf("\n");

   /* Print root list, delete first instance of 600, print updated list */
   printf("BEFORE DELETING FIRST INSTANCE OF 600 (2)\n");
   r=ll_print(root);
   r=ll_del_by_value(&root,600);
   printf("AFTER DELETING FIRST INSTANCE OF 600 (2)\n");
   r=ll_print(root);
   printf("\n");

   /* Print root list, concat it wih other1 list, print updated list */
   printf("BEFORE CONCATING WITH OTHER1\n");
   r=ll_print(root);
   printf("AFTER CONCATING WITH OTHER1\n");
   r=ll_concat(&root,&other1);
   r=ll_print(root);
   printf("\n");

   /* Print root list, insert number 300, print updated list */
   printf("BEFORE INSERTING 300\n");
   r=ll_print(root);
   r=ll_insert_in_order(&root,300);
   printf("AFTER INSERTING 300\n");
   r=ll_print(root);
   printf("\n");

   /* Print root list, concat it wih other2 list, print updated list */
   printf("BEFORE CONCATING WITH OTHER2\n");
   r=ll_print(root);
   printf("AFTER CONCATING WITH OTHER2\n");
   r=ll_concat(&root,&other2);
   r=ll_print(root);
   printf("\n");

   /* Print root list, insert number 900, print updated list */
   printf("BEFORE INSERTING 900\n");
   r=ll_print(root);
   r=ll_insert_in_order(&root,900);
   printf("AFTER INSERTING 900\n");
   r=ll_print(root);
   printf("\n");
  
   /* Print root list, sort list, print updated list */
   printf("BEFORE SORTING\n");
   r=ll_print(root);
   r=ll_sort(&root);
   printf("AFTER SORTING\n");
   r=ll_print(root);
   printf("\n");

   r=ll_free(root);

   return 0;
}
