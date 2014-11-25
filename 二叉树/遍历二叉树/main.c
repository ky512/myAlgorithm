#include <stdio.h>
#include "BTree.h"


void printf_data(BTreeNode* node)
{
	if(node!=NULL)
	printf("%c",node->v);
}

//±éÀú¶þ²æÊ÷
void preOrder_traversal(BTreeNode* root)
{
	if(root!=NULL)
	{
		printf("%c ",root->v);
		preOrder_traversal(root->left);
		preOrder_traversal(root->right);
	}
}


void midOrder_traversal(BTreeNode* root)
{
	if(root!=NULL)
	{
		midOrder_traversal(root->left);
		printf("%c ",root->v);
		midOrder_traversal(root->right);
	}
}

void postOrder_traversal(BTreeNode* root)
{
	if(root!=NULL)
	{
		postOrder_traversal(root->left);
		midOrder_traversal(root->right);
		printf("%c ",root->v);

	}
}
int main(int argc,char* argv[])
{
	int i=0;
	BTree* tree=BTree_Create();
	BTreeNode n1={'A',NULL,NULL};
	BTreeNode n2={'B',NULL,NULL};
	BTreeNode n3={'C',NULL,NULL};
	BTreeNode n4={'D',NULL,NULL};
	BTreeNode n5={'E',NULL,NULL};
	BTreeNode n6={'F',NULL,NULL};

	BTree_Insert(tree,&n1,0x0,0,0);
	BTree_Insert(tree,&n2,0x0,1,0);
	BTree_Insert(tree,&n3,0x1,1,0);
	BTree_Insert(tree,&n4,0x00,2,0);
	BTree_Insert(tree,&n5,0x2,2,0);
	BTree_Insert(tree,&n6,0x2,3,0);


	printf("The Height of Tree: %d \n",BTree_Height(tree));

	BTree_Display(tree,printf_data,4,'-');

	//BTreeNode* node=((BTreeHeader*)tree)->root; 
	printf("\nPreOrder_traversal:\n");
	preOrder_traversal(((BTreeHeader*)tree)->root);

	printf("\nMidOrder_traversal:\n");
	midOrder_traversal(((BTreeHeader*)tree)->root);

	printf("\nPostOrder_traversal:\n");
	postOrder_traversal(((BTreeHeader*)tree)->root);
	return 0;
}