// groupe GDH
// vim: ai:sw=2:ts=2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

typedef struct BinaryTreeNode* Node;

void affichage_array(long long unsigned* array,int len){
	printf("[");
	for (int i = 0; i<len; i++){
		printf("%llu ", array[i]);
	}
	printf("]\n");
}

void main(int argc, char* argv[]){
	char file[50];
	strcpy(file,argv[1]); // pour pas réécrire à chaque fois argv[1]

  FILE *fptr = fopen("file.txt", "r");
	// On acquiert toutes les valeurs du fichier...
	char N_buffer[50];
	(void)! fgets(N_buffer, 50, fptr); // lit la ligne et la met dans N
	int N = atoi(N_buffer);	// donne le nombre de nombres dans la ligne suivante

	char entries[50*N]; //on fixe la ligne à (50 fois le nb d'entrées) charactères
	(void)! fgets(entries, 50*N, fptr);

	char Q_buffer[50];
	(void)! fgets(Q_buffer, 50, fptr); // lit la ligne et la met dans N
	//Q donne le nombre d'arguments dans les lignes suivantes, 1 par ligne
	int Q = atoi(Q_buffer);	

	long long unsigned *check_IDs = malloc(sizeof(long long unsigned)*Q);
	char check_IDs_buffer[50*Q];
  for(int i = 0; i<Q; i++){
		(void)! fgets(check_IDs_buffer, 50*Q, fptr);
		check_IDs[i] = atoi(check_IDs_buffer); // on profite pour ranger
	};
	fclose(fptr);

	//mnt on traite les données dans le format voulu
  //sauf N et Q car on a du les traiter en priorité, car elles fixent la longueur de entries et check_IDs et check_IDs pour vider le buffer à chaque fois

	long long unsigned *e_IDs = malloc(sizeof(long long unsigned)*N);
	//on la veut en tableau de int
	char* tok_entrees = strtok(entries," ");
	for(int i = 0; i<N; i++){
		e_IDs[i]=atoi(tok_entrees);
		tok_entrees=strtok(NULL," ");
	}
	/*
	printf("Affichage des valeurs récupérées :\n");
	printf("N vaut %i\n",N);
	printf("e_IDs vaut : ");
	affichage_array(e_IDs,N);
	printf("Q vaut %i\n",Q);
	printf("check_IDs vaut : ");
	affichage_array(check_IDs,Q);
	*/
	

	Node root = newNodeCreate(e_IDs[0]); // utilisation du constructeur pour initialiser
	
	for (int i=1; i<N; i++)
	{
		(void)! insertNode(root, e_IDs[i]);
	}
	for (int i=0; i<Q; i++)
	{
		Node returnNode = searchNode(root, check_IDs[i]);
		if (returnNode == NULL)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
