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

//顺序表初始化
void InitList(sqlist *lst)
{
	lst->length = 0;
	lst->listsize = INITSIZE;
}

//求顺序表的表长
int Length(sqlist *lst)
{
	return lst->length;
}

//顺序表的插入
bool Insert(sqlist *lst, int i, ElemType e)
{
	int j;
	if (Length(lst) >= INITSIZE)//表满
		return false;;
	if (i<0 || i>lst->length)//位置出错
		return false;;

	for (j = lst->length - 1; j >= i - 1;j--)
	{
		lst->data[j + 1] = lst->data[j];//后移
	}
	lst->data[i - 1] = e;
	lst->length++;
	return true;
}

//顺序表的删除
bool Delete(sqlist *lst, int i,ElemType *e)
{
	int j;
	if (lst->length <= 0)//表空
		return false;
	if (i<0 || i>lst->length)//位置出错
		return false;;

	*e = lst->data[i - 1];

	for (j = i; j < Length(lst) - 1;j++)//前移
	{
		lst->data[j - 1] = lst->data[j];
	}
	lst->length--;
	return true;
}

//顺序表的打印输出
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
	ElemType *e = (ElemType *)malloc(sizeof(ElemType));//结点指针
	sqlist *lst = (sqlist *)malloc(sizeof(sqlist));//顺序表指针

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