#ifndef _BTREE_H_
#define _BTREE_H_

#define BT_LEFT 0
#define BT_RIGHT 1


typedef void BTree;
typedef unsigned long BTPos;
typedef struct tag_BTreeNode BTreeNode;

struct tag_BTreeNode
{
	char v;
	BTreeNode* left;
	BTreeNode* right;
};

typedef struct tag_BTree_Header BTreeHeader;
struct tag_BTree_Header
{
	int count;
	BTreeNode* root;
};

BTree* BTree_Create();

void BTree_Destroy(BTree* tree);

void BTree_Clear(BTree* tree);

int BTree_Insert(BTree* tree,BTreeNode* node,BTPos pos,int count,int flag);

BTreeNode* BTree_Delete(BTree* tree,BTPos pos,int count);

BTreeNode* BTree_Get(BTree* tree,BTPos pos,int count);

int  BTree_Height(BTree* tree);

typedef void (BTree_Printf)(BTreeNode*);
void BTree_Display(BTree* tree,BTree_Printf* pFunc,int gap,char div);

#endif