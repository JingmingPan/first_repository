#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *Lchild, *Rchild;
}Node,BitTree;

//构建不带数据的节点
Node* NewNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->Lchild = NULL;
	p->Rchild = NULL;
	return p;
}

//构建带数据的结点
Node *NewNode(ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->Lchild = NULL;
	p->Rchild = NULL;
	return p;
}

//由一个根节点数据和左右子树构建二叉树
void MakeBT(BitTree **bt, ElemType e, BitTree *lbt, BitTree *rbt)
{
	Node *p = NewNode(e);
	p->Lchild = lbt;
	p->Rchild = rbt;
	*bt = p;
}

//先序遍历二叉树
void preorder(BitTree *root)
{
	if (root!=NULL)
	{
		printf("%d ", root->data); //访问根
		preorder(root->Lchild);   //先序遍历根的左子树
		preorder(root->Rchild);   //先序遍历根的右子树
	}
}

//中序遍历二叉树
void inorder(BitTree *root)
{
	if (root!=NULL)
	{
		inorder(root->Lchild);    //中序遍历树的左子树
		printf("%d ", root->data); //访问根
		inorder(root->Rchild);    //中序遍历树的右子数
	}
}

//后序遍历二叉树
void postorder(BitTree *root)
{
	if (root!=NULL)
	{
		postorder(root->Lchild);
		postorder(root->Rchild);
		printf("%d ", root->data);
	}
}

void main()
{
	int h = 0;
	BitTree *bt = NULL,*bt1=NULL,*bt2=NULL,*bt3=NULL;

	MakeBT(&bt2, 10, bt1, bt1);
	MakeBT(&bt3, 20, bt1, bt1);
	MakeBT(&bt, 30, bt2, bt3);
	MakeBT(&bt, 40, bt, bt2);
	MakeBT(&bt, 50, bt2, bt);

	preorder(bt);
	printf("\n");
	inorder(bt);
	printf("\n");
	postorder(bt);
	printf("\n");

	system("pause");
}
