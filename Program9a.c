#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
void addEdge(int adj[MAX][MAX], int u, int v) {
adj[u][v] = 1;
adj[v][u] = 1;
}
void bfs(int adj[MAX][MAX], int V, int s) {
int q[MAX], front = 0, rear = 0;
bool visited[MAX] = { false };
visited[s] = true;
q[rear++] = s;
while (front < rear) {
int curr = q[front++];
printf("%d ", curr);
for (int i = 0; i < V; i++) {
if (adj[curr][i] == 1 && !visited[i]) {
visited[i] = true;
q[rear++] = i;
}
}
}
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
printf("Enter the starting vertex for BFS: ");
scanf("%d", &start);
printf("BFS starting from %d:\n", start);
bfs(adj, V, start);
return 0;
}