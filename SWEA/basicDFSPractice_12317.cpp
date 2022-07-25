/*
    작성자: 김지수
    작성일: 2022/07/26
    SWEA -- 기초 DFS 연습 (12317번)
*/

#define MAX 100
int graph[MAX][5];
bool visited[MAX];

void dfs_init(int N, int path[100][2])
{
   for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < 5; j++) {
         graph[i][j] = 0;
      }
   }

   for (int i = 0; i < N; i++) {
      int parent = path[i][0];
      int child = path[i][1];
      int idx = 0;
      while (graph[parent][idx] != 0) {
         idx++;
      }
      graph[parent][idx] = child;
   }
   
}

int dfs(int n)
{
   for (int i = 0; i < MAX; i++) {
      visited[i] = false;
   }
   int top = -1; 
   int stack[MAX];
   stack[++top] = n;
   bool found = false;
   int ans = 0;
   while (true) {
      if (top == -1) {
         break;
      }
      int now = stack[top];
      if (now > n) {
         found = true;
         ans = now;
         break;
      }
      visited[now] = true;
      stack[top--];
      for (int i = 4; i >=0; i--) {
         if (!visited[graph[now][i]] && graph[now][i] !=0) {
            stack[++top] = graph[now][i];
         }
      }
   }
   if (!found) {
      return -1;
   }
   else {
      return ans;
   }
}