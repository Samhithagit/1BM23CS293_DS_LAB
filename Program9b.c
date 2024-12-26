#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
void addEdge(int adj[MAX][MAX], int u, int v) {
adj[u][v] = 1;
adj[v][u] = 1;
}
void dfsUtil(int adj[MAX][MAX], int V, int visited[MAX], int s) {
visited[s] = 1;
printf("%d ", s);
for (int i = 0; i < V; i++) {
if (adj[s][i] == 1 && !visited[i]) {
dfsUtil(adj, V, visited, i);
}
}
}
void dfs(int adj[MAX][MAX], int V, int start) {
int visited[MAX] = {0};
dfsUtil(adj, V, visited, start);
}
int main() {
int V, E, u, v, start;
int adj[MAX][MAX] = {0};
printf("Enter the number of vertices: ");
scanf("%d", &V);
printf("Enter the number of edges: ");
scanf("%d", &E);
printf("Enter the edges (u v):\n");
for (int i = 0; i < E; i++) {
scanf("%d %d", &u, &v);
addEdge(adj, u, v);
}
printf("Enter the starting vertex for DFS: ");
scanf("%d", &start);
printf("DFS starting from %d:\n", start);
dfs(adj, V, start);
return 0;
}
