#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <importaciones.h>
#include <red.h>
#include <algorithm>

void display(int dist[] , int par[], int nodes, red* router, int src);
int getMin(int dist[] , bool visited[]);
void dijkstra(int src, int nodes, int** matriz, red* router);

#endif // DIJKSTRA_H
