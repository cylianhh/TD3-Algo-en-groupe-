#include "kingdom.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char filename[100];
    printf("Entrez le nom du fichier : ");
    fflush(stdout); // force l’affichage  
    scanf("%s", filename);
    //pour entrer nom du fichier contenant les valeurs (à enregistrer à côté de la fonction)

    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Impossible d'ouvrir le fichier\n");
        return 1;
    }

    int n, m; //nombre sommets, nombre aretes
    fscanf(f, "%d %d", &n, &m);

    Graph* g = createGraph(n+1); //ajout des sommets (n+1 pour exclure sommet d'indice 0)

    int src, dst; //sommets reliés par une arete

    for (int i = 0; i<m; i++) {
        fscanf(f, "%d %d", &src, &dst);
        addEdge(g, src, dst); //ajout des aretes
    }

    int depart, arrivee; // sommets de départ et d'arrivée

    fscanf(f, "%d %d", &depart, &arrivee);
    printf("%d\n", kingdom(g,depart,n+1)); //nb de royaumes

    int* d = distance(g, depart, n+1); //crée tableau de distance de chaque sommet depuis départ  
    printf("%i\n", d[arrivee]); //distance min entre depart et arrivée
    
    free(d);
    return 0;
}