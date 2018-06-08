/*
BFS-广度优先搜索，原理不再赘述。代码实现上：
1.利用了邻接矩阵来储存一个无向图
2.BFS没有使用递归，但是使用了一个队列来实现BFS的操作。
3.仍然需要数组来储存已经访问过的点
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

// 队列，这里没有使用STL的queue
typedef struct Queue {
    int traversed[MAX_VERTEX_NUM + 5];
    int front;
} Queue;

void push(Queue* queue, int vex)
{
    queue->traversed[queue->front] = vex;
    queue->front++;
}

int pop(Queue* queue)
{
    queue->front--;
    return queue->traversed[queue->front];
}

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
广搜的重点在于队列的应用，为什么使用队列，画一下广搜的过程即可
明白，这里不再赘述。注意仍然是需要储存已经访问过的顶点的。
*/
void BFS(MGroup G, Queue* queue)
{
    while (queue->front != 0) {
        int vex = pop(queue);
        for (int i = 1; i < MAX_VERTEX_NUM; i++) {
            if (G.arcs[vex][i].info == 1 && traversed[i] != 1) {
                cout << "vex is " << i << endl;
                traversed[i] = 1;
                push(queue, i);
            }
        }
    }
}

int main()
{
    MGroup G;
    Queue queue;
    queue.front = 0;
    CreatGroup(&G);
    traversed[1] = 1;
    push(&queue, 1);
    cout << "vex is 1" << endl;
    BFS(G, &queue);

    system("pause");
    return 0;
}