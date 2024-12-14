#include <stdio.h>
#include "btree.h"
main()
{
    NODE *root;
    int choice;
    root = NULL;

    do
    {
       printf("1)Create\n");
       printf("2)Inorder\n");
       printf("3)Preorder\n");
       printf("4)Postorder\n");
       printf("5)Exit\n");
       printf("Enter choice ");
       scanf("%d",&choice);
       switch(choice)
       {
	  case 1 : root = create(root);
		   break;
	  case 2 : printf("\nInorder Traversal :\n");
		   inorder(root);
		   break;
	  case 3 : printf("\nPreorder Traversal :\n");
		   preorder(root);
		   break;
	  case 4 : printf("Postorder Traversal :\n");
		   postorder(root);
		   break;
	  case 5 : exit(0);
       }
     }while(choice != 5);
return 0;
}



