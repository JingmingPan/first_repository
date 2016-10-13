#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *Lchild, *Rchild;
}Node,BitTree;

//�����������ݵĽڵ�
Node* NewNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->Lchild = NULL;
	p->Rchild = NULL;
	return p;
}

//���������ݵĽ��
Node *NewNode(ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->Lchild = NULL;
	p->Rchild = NULL;
	return p;
}

//��һ�����ڵ����ݺ�������������������
void MakeBT(BitTree **bt, ElemType e, BitTree *lbt, BitTree *rbt)
{
	Node *p = NewNode(e);
	p->Lchild = lbt;
	p->Rchild = rbt;
	*bt = p;
}

//�������������
void preorder(BitTree *root)
{
	if (root!=NULL)
	{
		printf("%d ", root->data); //���ʸ�
		preorder(root->Lchild);   //�����������������
		preorder(root->Rchild);   //�����������������
	}
}

//�������������
void inorder(BitTree *root)
{
	if (root!=NULL)
	{
		inorder(root->Lchild);    //�����������������
		printf("%d ", root->data); //���ʸ�
		inorder(root->Rchild);    //�����������������
	}
}

//�������������
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
