#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 1000

int n;  // number of nodes
int e;  // number of edges
int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
int flow[MAX_NODES][MAX_NODES];     // flow matrix
int color[MAX_NODES]; // needed for breadth-first search
int pred[MAX_NODES];  // array to store augmenting path

int min (int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}
int head,tail;
int q[MAX_NODES+2];

void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}
int bfs (int start, int target) {
    int u,v;
    for (u=0; u<n; u++) {
	color[u] = WHITE;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
	u = dequeue();
        // Search all adjacent white nodes v. If the capacity
        // from u to v in the residual network is positive,
        // enqueue v.
	for (v=0; v<n; v++) {
	    if (color[v]==WHITE && capacity[u][v]-flow[u][v]>0) {
		enqueue(v);
		pred[v] = u;
	    }
	}
    }
    // If the color of the target node is black now,
    // it means that we reached it.
    if(color[target]==BLACK)
        return 1;
    else
        return 0;
}

int max_flow (int source, int sink) {
    int i,j,u;
    // Initialize empty flow.
    int max_flow = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            flow[i][j] = 0;
        }
    }
    int increment=100000000;
    // While there exists an augmenting path,
    // increment the flow along this path.
    while (bfs(source,sink)==1) {
        // Determine the amount by which we can increment the flow.

	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    increment = min(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
	}
        // Now increment the flow.
	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    flow[pred[u]][u] += increment;
	    flow[u][pred[u]] -= increment;
	}
	max_flow += increment;
    }
    // No augmenting path anymore. We are done.
    return max_flow;
}


int main () {

   int i,j,a,b,c;
    printf("Enter number of edges: ");
    scanf("%d",&e);

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            capacity[i][j] = 0;
        }
    }

    printf("Write edge with capacity:");
    for (i=0; i<e; i++) {
	scanf("%d %d %d",&a,&b,&c);
	capacity[a][b] = c;
    }


    printf("\nPlease enter Source(s) and Sink(t) :\n");
    int s=0,t=n-1;
    scanf("%d %d",&s,&t);
    printf("\nMax Flow : %d\n",max_flow(s,t));
    return 0;
}
