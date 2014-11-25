#include <stdio.h>
#include <malloc.h>
#include "BTree.h"

typedef struct tag_BTree_Header BTreeHeader;
struct tag_BTree_Header
{
	int count;
	BTreeNode* root;
};

//递归查找以root为父节点的整个二叉树节点的数目
static int recursive_count(BTreeNode* root)
{
	int ret=0;
	if(root!=NULL)
	{
		ret=1+recursive_count(root->left)+recursive_count(root->right);
	}
	return ret;
}

//递归查找以root为父节点的整个二叉树的高度
static int recursive_height(BTreeNode* root)
{
	int ret=0;
	//int leftH=0;
	//int rightH=0;

	if(root!=NULL)
	{
		int leftH=recursive_height(root->left);
		int rightH=recursive_height(root->right);
		
		ret=(leftH>rightH?leftH:rightH)+1;
	}
	return ret;
}


BTree* BTree_Create()
{
	BTreeHeader* ret=(BTreeHeader*)malloc(sizeof(BTreeHeader));
	if(ret!=NULL)
	{
		ret->count=0;
		ret->root=NULL;
	}
	return ret;
	
}


void BTree_Destroy(BTree* tree)
{
	free(tree);
}

void BTree_Clear(BTree* tree)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	if(tree!=NULL)
	{
		btree->count=0;
		btree->root=NULL;
	}
}
										
int BTree_Insert(BTree* tree,BTreeNode* node,BTPos pos,int count,int flag)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	int ret=(btree!=NULL)&&(node!=NULL)&&((flag==BT_LEFT)||(flag==BT_RIGHT));
	int bit;
	int i;
	if(ret)
	{
		BTreeNode* current=btree->root;
		BTreeNode* parent=NULL;

		node->left=NULL;
		node->right=NULL;

		for( i=0;(i<count)&&(current!=NULL);i++)
		{
			bit=pos&1;
			pos=pos>>1;
			parent=current;
			if(bit==BT_LEFT)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}

		}

		if(current!=NULL)
		{
			if(flag==BT_LEFT)
			{
				node->left=current;
			}
			else
			{
				node->right=current;
			}
		}
		if(parent!=NULL)
		{
			if(bit==BT_LEFT)
			{
				parent->left=node;
			}
			else
			{
				parent->right=node;
			}
		}
		else
		{
			btree->root=node;
		}
		
		btree->count++;
	}
	return ret;
}

BTreeNode* BTree_Delete(BTree* tree,BTPos pos,int count)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	BTreeNode* ret=NULL;
	int bit;
	int i;
	if(btree!=NULL)
	{
		BTreeNode* current=btree->root;
		BTreeNode* parent=NULL;

		for( i=0;(i<count)&&(current!=NULL);i++)
		{
			bit=pos&1;
			pos=pos>>1;
			parent=current;
			if(bit==BT_LEFT)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}

		}

		if(parent!=NULL)
		{
			if(bit==BT_LEFT)
			{
				parent->left=NULL;
			}
			else
			{
				parent->right=NULL;
			}
		}
		else
		{
			btree->root=NULL;
		}
		
		ret=current;
		btree->count=btree->count-recursive_count(current);

	}
	return ret;
}

BTreeNode* BTree_Get(BTree* tree,BTPos pos,int count)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	BTreeNode* ret=NULL;
	int bit;
	int i;
	if(btree!=NULL)
	{
		BTreeNode* current=btree->root;
		//BTreeNode* parent=NULL;

		for( i=0;(i<count)&&(current!=NULL);i++)
		{
			bit=pos&1;
			pos=pos>>1;
			//parent=current;
			if(bit==BT_LEFT)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}

		}
		ret=current;
		//btree->count=btree->count-recursive_count(current);
	}
	return ret;
}

int  BTree_Height(BTree* tree)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	int ret=0;
	if(btree!=NULL)
	{
		ret=recursive_height(btree->root);
	}
	return ret;
}

void recursive_display(BTreeNode* node,BTree_Printf* pFunc,int format,int gap,int div)
{
	int i=0;
	if((node!=NULL)&&(pFunc!=NULL))
	{
		for(i=0;i<format;i++)
		{
			printf("%c",div);
		}
		pFunc(node);
		printf("\n");
		recursive_display(node->left,pFunc,format+gap,gap,div);
		recursive_display(node->right,pFunc,format+gap,gap,div);
	}
	else
	{
		for(i=0;i<format;i++)
		{
			printf("%c",div);
		}
		printf("\n");  
	}
}
void BTree_Display(BTree* tree,BTree_Printf* pFunc,int gap,char div)
{
	BTreeHeader* btree=(BTreeHeader*)tree;
	if(btree!=NULL)
	{
		recursive_display(btree->root,pFunc,0,4,div);
	}
}
