#include <stdio.h>
#include <stdlib.h>

#define v 8  //顶点数
#define e 9  //边数
#define maxvalue 10000
typedef char vextype;  //顶点数据类型
typedef float adjtype; //权值数据类型

typedef struct graph
{
	vextype vexs[v];    //存放顶点数据
	adjtype arcs[v][v]; //存放边数据
}Graph;

//图的邻接表结构设计
typedef struct edgenode
{
	int adjvex;     //邻接点编号
	adjtype weight; //边权值
	struct edgenode *nextarc; //下一个边表节点
}EdgeNode;

typedef struct
{
	vextype data;  //顶点数据
	EdgeNode *link;//边表节点
}VexNode;

//构建邻接矩阵表示的图
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
		printf("分别输入");
		scanf("%d%d%f", &i, &j, &w);
		ga->arcs[i][j] = w;
		ga->arcs[j][i] = w;
	}
}

//构建邻接表表示的图
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