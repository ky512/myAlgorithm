#include <stdio.h>
#include "BTree.h"

/*
struct tag_BTreeNode
{
	char v;
	BTreeNode* left;
	BTreeNode* right;
};
*/

void printf_data(BTreeNode* node)
{
	if(node!=NULL)
	printf("%c",node->v);
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

	printf("%c ",BTree_Get(tree,0x0,0)->v);
	/*
	BTree_Get(tree,0x0,0);
	BTree_Get(tree,0x0,1);
	BTree_Get(tree,0x1,1);
	BTree_Get(tree,0x00,2);
	BTree_Get(tree,0x2,2);
	BTree_Get(tree,0x2,3);
	*/
	printf("%c ",BTree_Get(tree,0x2,3)->v);

	printf("The Height of Tree: %d \n",BTree_Height(tree));

	BTree_Display(tree,printf_data,4,'-');
	return 0;
}