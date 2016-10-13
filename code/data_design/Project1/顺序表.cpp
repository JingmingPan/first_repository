#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define INITSIZE 100
typedef int ElemType;
typedef struct list
{
	int length;
	int listsize;
	ElemType data[INITSIZE];
}sqlist;

//˳����ʼ��
void InitList(sqlist *lst)
{
	lst->length = 0;
	lst->listsize = INITSIZE;
}

//��˳���ı�
int Length(sqlist *lst)
{
	return lst->length;
}

//˳���Ĳ���
bool Insert(sqlist *lst, int i, ElemType e)
{
	int j;
	if (Length(lst) >= INITSIZE)//����
		return false;;
	if (i<0 || i>lst->length)//λ�ó���
		return false;;

	for (j = lst->length - 1; j >= i - 1;j--)
	{
		lst->data[j + 1] = lst->data[j];//����
	}
	lst->data[i - 1] = e;
	lst->length++;
	return true;
}

//˳����ɾ��
bool Delete(sqlist *lst, int i,ElemType *e)
{
	int j;
	if (lst->length <= 0)//���
		return false;
	if (i<0 || i>lst->length)//λ�ó���
		return false;;

	*e = lst->data[i - 1];

	for (j = i; j < Length(lst) - 1;j++)//ǰ��
	{
		lst->data[j - 1] = lst->data[j];
	}
	lst->length--;
	return true;
}

//˳���Ĵ�ӡ���
void PrintList(sqlist *lst)
{
	for (int i = 0;i<lst->length;i++)
	{
		printf("%d", lst->data[i]);
	}
	printf("\n");
}

void main()
{
	ElemType *e = (ElemType *)malloc(sizeof(ElemType));//���ָ��
	sqlist *lst = (sqlist *)malloc(sizeof(sqlist));//˳���ָ��

	InitList(lst);
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &(lst->data[i]));
		lst->length++;
	}

	PrintList(lst);
	Insert(lst, 5, 80);
	PrintList(lst);
	Delete(lst, 6,e);
	PrintList(lst);
	free(e);
	free(lst);
	system("pause");
}