package JAVA.Graph;

import java.util.*;

public class Virus_2606 {
    static ArrayList<Integer>[] graph;
    static boolean visited[];

    static int bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true;
        q.add(start);
        int count = -1;
        while (q.size() > 0) {
            int now = q.peek();
            q.remove();
            count++;
            for (int i = 0; i < graph[now].size(); i++) {
                if (!visited[graph[now].get(i)]) {
                    q.add(graph[now].get(i));
                    visited[graph[now].get(i)] = true;
                }
            }

        }
        return count;
    }

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int computerNum = sc.nextInt();
        graph = new ArrayList[computerNum];
        for (int i = 0; i < computerNum; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        int edgeNum = sc.nextInt();
        for (int i = 0; i < edgeNum; i++) {
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            graph[node1 - 1].add(node2 - 1);
            graph[node2 - 1].add(node1 - 1);
        }
        visited = new boolean[computerNum];
        Arrays.fill(visited, false);
        int answer = bfs(0);
        System.out.println(answer);
        sc.close();
    }
}
