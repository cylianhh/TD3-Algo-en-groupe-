typedef struct Node {
    int vertex;           
    struct Node* next; 
} Node;

typedef struct Graph {
    int nbVertices; 
    Node** adj;    //tableau de listes
} Graph;

Node* newNode(int v);
void addEdge(Graph* g, int src, int dst);
Graph* createGraph(int n);
void dfs(Graph* g, int v);
int kingdom(Graph* g, int v, int n);
void dfs_distance(Graph* g, int v, int *d, int *visited);
int* distance(Graph* g, int start, int n);