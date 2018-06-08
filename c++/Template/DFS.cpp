/*
DFS-深度优先搜索，原理不再赘述，代码实现上：
1.用邻接矩阵来存储了一个无向图
2.DFS要利用递归，因为有了一个回溯的过程。
3.需要一个数组，储存已经访问过的顶点。
*/

#include <iostream>
#define MAX_VERTEX_NUM 10

using namespace std;

int traversed[MAX_VERTEX_NUM]; // 存放已经访问过的顶点

// 邻接矩阵
typedef struct ArcCell {
    int info; // 无向图，用0、1来表示是否存在边
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    AdjMatrix arcs;
} MGroup;

// 这里直接给了一个图，不再再赘述
void CreatGroup(MGroup* G)
{
    G->arcs[1][2].info = 1;
    G->arcs[2][1].info = 1;
    G->arcs[1][3].info = 1;
    G->arcs[3][1].info = 1;
    G->arcs[1][4].info = 1;
    G->arcs[4][1].info = 1;
    G->arcs[2][5].info = 1;
    G->arcs[5][2].info = 1;
    G->arcs[5][7].info = 1;
    G->arcs[7][5].info = 1;
    G->arcs[4][6].info = 1;
    G->arcs[6][4].info = 1;
}

/* 
DFS递归算法，for循环遍历vex行的所有元素，即寻找vex顶点的所有边，if
语句判断，必须满足存在边（arcs值为1），同时改边的头不能是已经访问过
的顶点。全部满足，说明遍历了一个新顶点。将该顶点加入traversed数组，
再进行下一轮递归。
*/
void DFS(MGroup G, int vex)
{
    for (int i = 1; i < MAX_VERTEX_NUM; i++) {
        if (G.arcs[vex][i].info == 1 && traversed[i] != 1) {
            cout << "vex is " << i << endl;
            traversed[i] = 1;
            DFS(G, i);
        }
    }
}

int main()
{
    MGroup G;
    CreatGroup(&G);
    traversed[1] = 1;
    cout << "vex is 1" << endl;
    DFS(G, 1);

    system("pause");
    return 0;
}