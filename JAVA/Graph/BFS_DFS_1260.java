package JAVA.Graph;

import java.util.*;

public class BFS_DFS_1260 {
    static ArrayList<Integer>[] graph;

    static boolean visited[];

    static void bfs(int startNode) {
        Queue<Integer> q = new LinkedList<>();
        q.add(startNode);
        visited[startNode] = true;
        while (q.size() > 0) {
            int nowNode = q.peek();
            q.remove();
            System.out.print(nowNode + " ");
            for (int i = 0; i < graph[nowNode].size(); i++) {
                int nextNode = graph[nowNode].get(i);
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    q.add(nextNode);
                }
            }
        }
    }

    static void dfs(int startNode) {
        System.out.print(startNode + " ");
        visited[startNode] = true;

        for (int i = 0; i < graph[startNode].size(); i++) {
            int nextNode = graph[startNode].get(i);
            if (!visited[nextNode]) {
                dfs(nextNode);
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int nodeNum = sc.nextInt();
        int edgeNum = sc.nextInt();
        int startNode = sc.nextInt();
        graph = new ArrayList[nodeNum + 1];
        visited = new boolean[nodeNum + 1];

        for (int i = 1; i <= nodeNum; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < edgeNum; i++) {
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            graph[node1].add(node2);
            graph[node2].add(node1);
        }
        for (int i = 1; i <= nodeNum; i++) {
            Collections.sort(graph[i]);
        }

        Arrays.fill(visited, false);
        dfs(startNode);

        Arrays.fill(visited, false);
        System.out.println();
        bfs(startNode);
        sc.close();
    }
}
