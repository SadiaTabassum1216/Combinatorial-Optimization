// Prim's Algorithm in C

#include<stdio.h>

#define INF 9999999

// number of vertices in graph
//#define V 5
//
//int G[V][V] = {
//  {0, 9, 75, 0, 0},
//  {9, 0, 95, 19, 42},
//  {75, 95, 0, 51, 66},
//  {0, 19, 51, 0, 31},
//  {0, 42, 66, 31, 0}};

int main() {
    int i,j,V;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    int G[V][V];
    printf("Enter the adjacent matrix: \n")
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&G[i][j]);
        }
    }
  int edgeNum;  // number of edge
  int selected[1000]={0};
  edgeNum = 0;
  selected[0]=1;

  int x;  //  row number
  int y;  //  col number

  printf("Edge : Weight\n");

  while (edgeNum < V-1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = 1;
    edgeNum++;
  }

  return 0;
}
