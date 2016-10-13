#include <stdio.h>
#include <stdlib.h>

#define v 8  //������
#define e 9  //����
#define maxvalue 10000
typedef char vextype;  //������������
typedef float adjtype; //Ȩֵ��������

typedef struct graph
{
	vextype vexs[v];    //��Ŷ�������
	adjtype arcs[v][v]; //��ű�����
}Graph;

//ͼ���ڽӱ�ṹ���
typedef struct edgenode
{
	int adjvex;     //�ڽӵ���
	adjtype weight; //��Ȩֵ
	struct edgenode *nextarc; //��һ���߱�ڵ�
}EdgeNode;

typedef struct
{
	vextype data;  //��������
	EdgeNode *link;//�߱�ڵ�
}VexNode;

//�����ڽӾ����ʾ��ͼ
void CreateGraph(Graph *ga)
{
	int i, j, k;
	float w;
	for (i = 0; i < v; i++)
		ga->vexs[i] = getchar();
	for (i = 0; i < v;i++)
		for (j = 0; j < v;i++)
			ga->arcs[i][j] = maxvalue;

	for (k = 0; k < e;k++)
	{
		printf("�ֱ�����");
		scanf("%d%d%f", &i, &j, &w);
		ga->arcs[i][j] = w;
		ga->arcs[j][i] = w;
	}
}

//�����ڽӱ��ʾ��ͼ
void CreateGraph(VexNode ga[])
{
	int i, j, k;
	adjtype w;
	EdgeNode *s;
	for (i = 0; i < v;i++)
	{
		ga[i].data = getchar();
		ga[i].link = NULL;
	}
	for (k = 0; k < e;k++)
	{

	}

}