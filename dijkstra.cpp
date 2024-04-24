#include<bits/stdc++.h>
#include <dijkstra.h>

int getMin(int dist[] , bool visited[], int nodes){
    int key = 0 ;
    int min = 999 ;
    for(int i=0;i < nodes ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ;
            key = i ;
        }
    }
    return key ;
}

void display(int dist[] , int par[], int nodes, red *router, int src){
    string camino = "";
    map<char,map<char, string>*, less<char>> *caminos = router->getCaminos();
    auto *aux = new map<char, string>;
    for(int i = 0 ;i < nodes ;i++){
        int temp = par[i] ;
        camino += router->getStrNodos().at(i);
        while(temp!=-1)
        {
            camino += router->getStrNodos().at(temp);
            temp = par[temp] ;
        }
        reverse(camino.begin(), camino.end());
        aux->insert(pair<char,string>(router->getStrNodos().at(i), camino));
        camino = "";
        router->getMatriz()[src][i] = dist[i];
    }
    char nodo = router->getStrNodos().at(src);
    caminos->insert(pair<char, map<char, string>*>(nodo, aux));
}


void dijkstra(int src, int nodes, int** matriz, red* router){
    int *par = new int[nodes];
    int *dist = new int[nodes];
    bool *visited = new bool[nodes];
    fill(visited, visited + nodes, false);
    fill(dist ,dist+nodes, 999) ;

    dist[src] =0 ;
    par[src] =-1 ;

    for(int g = 0  ;g<nodes-1 ; g++){
        int u = getMin(dist, visited, nodes)  ;
        visited[u] = true ;
        for(int v =0 ; v< nodes ;v++){
            if(!visited[v] && (dist[u]+matriz[u][v]) <  dist[v] && matriz[u][v]!=9999)
            {
                par[v] = u ;
                dist[v] = dist[u] + matriz[u][v] ;
            }
        }
    }
    display(dist , par, nodes, router, src) ;
    delete [] par;
    delete [] visited;
    delete [] dist;
}
