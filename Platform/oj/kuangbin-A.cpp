// #include <cstring>
// #include <iostream>
// using namespace std;
// char map[9][9];
// int visited[9];
// int N, K; //棋盘规格  棋子数目
// int way; //当前步数
// int count; //最终结果
// void dfs(int k)
// {
//     if (way == K) //棋子个数达到要求，方案数+1，返回
//     {
//         //cout<<"棋子个数达到要求，方案数+1，返回  "<<endl;
//         count++;
//         return;
//     }
//     if (k >= N) //若搜出棋盘外，返回
//         return;
//     for (int j = 0; j < N; j++) {
//         if (!visited[j] && map[k][j] == '#') {
//             //cout<<"if进入第"<<k+1<<"行，并且找到了棋子++落棋数+?"<<endl;
//             visited[j] = 1; //标记为1
//             way++;
//             dfs(k + 1);
//             //遍历失败或者棋子数满足了
//             visited[j] = 0; //清除标记
//             way--;
//             //cout<<k+1<<"行清除标记"<<endl;
//         }
//     }
//     //cout<<k+1<<"行算入方案!遍历下一行"<<endl;
//     //cout<<"最后进入第"<<k+1<<"行，并且找到了棋子++落棋数+?"<<endl;
//     dfs(k + 1); //该行已经满足棋子总数，所以K行不放棋子
// }
// int main()
// {
//     // ios::sync_with_stdio(false); //关闭C语言的io  增加输出速度---注意放在main（）开头
//     int i, num;
//     while (cin >> N >> K) {
//         if (N == -1 && K == -1)
//             break;
//         memset(map, 0, sizeof(map));
//         memset(visited, 0, sizeof(visited));
//         for (i = 0; i < N; i++) {
//             cin >> map[i];
//         }
//         count = way = 0;
//         dfs(0);
//         cout << count << endl;
//         /*  for(int i=0;i<N;i++)
//         {
//             for(int j=0;j<N;j++)
//                 cout<<map[i][j];
//             cout<<endl;
//         }
//         */
//     }
//     return 0;
// }