#include<stdio.h>
#include <stdlib.h>

//ֱ�Ӳ�������
void InsertSort(int x[],int n)
{
	int sentinel = 0;  //�ڱ�
	int i, j, k;
	for (i = 1; i < n;i++)  //�����е�һ��Ԫ�ؿ��������
	{
		if (x[i]<=x[i-1])
		{
			sentinel = x[i];
			for (j = i - 1; j > 0 && (sentinel <= x[j]); j--)
				x[j + 1] = x[j];
			x[j + 1] = sentinel;
		}
		printf("��%d���������: ", i);
		for (k = 0; k < n;k++)
			printf("%d ", x[k]);
		printf("\n");
	}
}

//ð������
void BubbleSort(int x[],int n)
{
	int temp, exchange;
	int i, j, k;
	for (i = n - 1; i>0;i--)
	{
		exchange = 0;
		for (j = 0; j < i; j++)
		{
			if (x[j + 1] <= x[j])
			{
				temp = x[j + 1];
				x[j + 1] = x[j];
				x[j] = temp;
				exchange = 1;
			}
		}
		if (!exchange)
			break;
		printf("��%d����������� ", n - i);
		for (k = 0; k < n; k++)
			printf("%d ", x[k]);
		printf("\n");
	}


}

//��������
int Partition(int x[], int low, int high)
{
	int sentinel = x[low];
	int pivotkey = x[low];
	//49, 38, 65, 97, 76, 13, 27, 49
	while (low < high)
	{
		while (low < high && (pivotkey <= x[high]))
			high--;
		x[low] = x[high];
		while (low < high && (x[low] <= pivotkey))
			low++;
		x[high] = x[low];
	}
	x[low] = sentinel;
	return low;
}

void QuickSort(int x[], int low, int high)
{
	int pivotloc, k;
	if (low<high)
	{
		pivotloc = Partition(x, low, high);
			printf("�������: ");
		for (k = 0; k < 8; k++)
			printf("%d ", x[k]);

		printf("\n");
		QuickSort(x, low, pivotloc - 1);
		QuickSort(x, pivotloc + 1, high);
	}
}


void main()
{
	int x[10] = { 10, 35, 19, 23, 17, 18, 5, 3, 12, 5 }, i;
	printf("\nֱ�Ӳ�����������: ");
	for (i = 0; i < 10; i++)
		printf("%d ", x[i]);
	printf("\n\n");
	InsertSort(x, 10);
	printf("\n\n");

	int y[10] = { 88, 29, 48, 37, 16, 5, 14, 32, -2, 11 };
	printf("ð����������: ");
	for (i = 0; i < 10; i++)
		printf("%d ", y[i]);
	printf("\n\n");
	BubbleSort(y, 10);
	printf("\n\n");

	int z[8] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	printf("������������: ");
	for (i = 0; i < 8; i++)
		printf("%d ", z[i]);
	printf("\n\n");
	QuickSort(z, 0, 7);
	printf("\n\n");

	system("pause");
}