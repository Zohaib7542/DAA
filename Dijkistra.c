#include <stdio.h>
#define infinity 999

// Function to implement Dijkstra's algorithm
void dijkstra(int n, int v, int cost[20][20], int dist[]) {
	int i, u, count, w, flag[20], min;
	
	// Initialize flag and dist arrays
	for (i = 0; i < n; i++)
		flag[i] = 0, dist[i] = cost[v][i]; // Initialize distances from source

	count = 1;
	while (count < n) {
		min = infinity;
		
		// Find node with minimum distance among unvisited nodes
		for (w = 0; w < n; w++)
			if (dist[w] < min && !flag[w]) {
				min = dist[w];
				u = w; // Update u with the node having minimum distance
			}
		flag[u] = 1; // Mark node u as visited
		count++;
		
		// Update distances of unvisited neighbors
		for (w = 0; w < n; w++)
			if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
				dist[w] = dist[u] + cost[u][w]; // Update distance if shorter path found
	}
}

int main(int argc, char *argv[]) {
	int n, v, i, j, cost[20][20], dist[20];
	
	// Input number of nodes
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("\nEnter the cost matrix:\n");
	// Input cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = infinity; // Set non-connected nodes to infinity
		}

	// Input source node
	printf("\nEnter the source node: ");
	scanf("%d", &v);

	// Call Dijkstra's algorithm function
	dijkstra(n, v, cost, dist);

	// Print shortest paths
	printf("\nShortest paths:\n");
	for (i = 0; i < n; i++) {
		if (i != v) {
			printf("%d -> %d, cost = %d\n", v, i, dist[i]);
		}
	}

	return 0;
}
