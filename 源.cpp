#include<stdio.h>
#include<stdlib.h>
/*图的定义*/
typedef struct enode* Edge;
typedef struct mgraph* MGraph;
struct enode {
	int v1, v2, weight;
};
struct mgraph {
	int nv, ne, G[100][100];
};
MGraph creat(int n) {
	MGraph Graph = (MGraph)malloc(sizeof(struct mgraph));
	Graph->nv = n;
	Graph->ne = 0;
	for (int i = 0; i < Graph->nv; i++) {
		for (int j = 0; j < Graph->nv; j++) {
			Graph->G[i][j] = 10000;
		}
	}
	return Graph;
}
MGraph build() {
	int n, e;
	scanf_s("%d %d", &n, &e);
	MGraph Graph = creat(n);
	Graph->ne = e;
	if (Graph->ne != 0) {
		for (int i = 0; i < Graph->ne; i++) {
			Edge E = (Edge)malloc(sizeof(struct enode));
			scanf_s("%d %d %d", &E->v1, &E->v2, &E->weight);
			Graph->G[E->v1][E->v2] = E->weight;
		}
	}
	return Graph;
}
bool Floyd(MGraph Graph,int D[][100],int path[][100]) {
	int i, j, k;
	/*初始化*/
for (i = 0; i < Graph->nv; i++) {
		for (j = 0; j < Graph->nv; j++) {
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}
	}
	for (k = 0; k < Graph->nv; k++) {
		for (i = 0; i < Graph->nv; i++) {
			for (j = 0; j < Graph->nv; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0)return false;
					path[i][j] = k;
				}

			}
		}
	}
	return true;
}
int main() {
	int x, y;
	int D[100][100],path[100][100];
	MGraph Graph = build();
	if (Floyd(Graph, D, path)) {
		for (int i = 0; i <Graph->nv; i++) {
			for (int j = 0; j <Graph->nv; j++) {
				if (i == j) {
					D[i][j] = 0;
				}
				printf("%d ", D[i][j]);
			}
			printf("\n");
		}
	}
	
}