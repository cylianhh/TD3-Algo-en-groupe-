#include "kingdom.h"
#include <stdio.h>
#include <stdlib.h>

//fonction qui crée un nouveau sommet
Node* newNode(int v){
    Node* n = malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

//fonction qui ajoute une arete (on doit ajouter dans les deux sens) 
//Ex: arete entre a et b donc a dans les voisins de b et b dans les voisins de a
void addEdge(Graph* g, int src, int dst) {
    Node* n = newNode(dst);
    n->next = g->adj[src];
    g->adj[src] = n;
    n = newNode(src);     
    n->next = g->adj[dst];
    g->adj[dst] = n;
}

//crée un graphe vide (uniquement sommets)
Graph* createGraph(int n){
    Graph* g = malloc(sizeof(Graph));
    g->nbVertices = n;
    g->adj = malloc(n * sizeof(Node*));
    for (int i = 1; i<n; i++) //on exclu le sommet 0
        g->adj[i] = NULL;
    return g;
}

int visited[100];

//parcours profondeur
void dfs(Graph* g, int v){
    visited[v] = 1;
    Node* tmp=g->adj[v];
    while (tmp != NULL) {
        int next=tmp->vertex;
        if (!visited[next]) {
            dfs(g, next);
        }
        tmp=tmp->next;
    }
}

//compte nombre de royaumes en utilisant dfs
int kingdom(Graph* g, int v, int n){
    for (int i = 0; i<n; i++) visited[i] = 0; //rémet visited à 0
    int c=0;
    int i=0;
    for(i;i<n;i++){
        if (!visited[i]){
            dfs(g,i);
            c++;
        }
    }
    return c;
}

//dfs qui calcule les distances depuis un sommet
void dfs_distance(Graph* g, int v, int *d, int *visited) {
    visited[v] = 1;
    Node* tmp = g->adj[v];
    while (tmp != NULL) {
        int next = tmp->vertex;
        if (!visited[next]) {
            d[next] = d[v]+1;
            dfs_distance(g, next, d, visited);
        }
        tmp = tmp->next;
    }
}

// affiche les distances min
int* distance(Graph* g, int start, int n) {
    int* d = malloc((n + 1) * sizeof(int));      
    int* visited = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        d[i] = -1;
        visited[i] = 0;
    }
    d[start] = 0;
    dfs_distance(g, start, d, visited);
    free(visited);
    return d;  
}