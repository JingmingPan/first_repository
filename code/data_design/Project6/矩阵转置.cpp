#include <stdio.h>
#include <stdlib.h>


#define M 10 //矩阵最大行数
#define N 10 //矩阵最大列数
typedef int ElemType;
typedef struct matrix
{
	ElemType data[M][N];
	int rows;
	int cols;
}Matrix;

//矩阵转置算法
void transport(Matrix m1, Matrix *m2)
{
	int i, j;
	for ( i = 0; i < m1.rows;i++)
	{
		for (j = 0; j < m1.cols;j++)
		{
			m2->data[j][i] = m1.data[i][j];
		}
	}
	m2->cols = m1.rows;
	m2->rows = m1.cols;
}

int main()
{
	int m = 2, n = 3;//分别代表矩阵行列
	Matrix m1, m2;
	m1.rows = 2;
	m1.cols = 3;
	for (int i = 0; i < m1.rows;i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			m1.data[i][j] = i*m1.cols + j;
		}
	}

	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			printf("%d", m1.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	transport(m1, &m2);
	for (int i = 0; i < m2.rows;i++)
	{
		for (int j = 0; j < m2.cols;j++)
		{
			printf("%d", m2.data[i][j]);
		}
		printf("\n");
	}
	system("pause");

}