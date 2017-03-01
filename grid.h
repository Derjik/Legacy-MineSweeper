#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>

#define TAILLE_V 9
#define TAILLE_H 9
#define MINES 10


void affiche(char t[TAILLE_V][TAILLE_H]); // Affichage d'une grille avec les cellules "propres"

void zero(char t[TAILLE_V][TAILLE_H], char sym); // Mise à zéro du tableau avec le caractère 'sym'

void randomise(char t[TAILLE_V][TAILLE_H]); // Met des cases au hasard des cases du tableau

int random(int min, int max); // Génération d'un nombre aléatoire entre min et max compris (enfin je crois?)

void bomb(char t[TAILLE_V][TAILLE_H]); // Place le bon nombre de mines dans le tableau (réglage via la constante MINES)

void test(char t[TAILLE_V][TAILLE_H], int y, int x, int f[TAILLE_V][TAILLE_H], bool chk[TAILLE_V][TAILLE_H]);
// Teste le nombre de mines autour d'une case donnée, et place ce nombre dans la grille des drapeaux correspondante

void afficheInt(int t[TAILLE_V][TAILLE_H], bool checked[TAILLE_V][TAILLE_H]); //

void zeroInt(int t[TAILLE_V][TAILLE_H], int sym);

void zeroBool(bool t[TAILLE_V][TAILLE_H], bool sym);

int lookup(char t[TAILLE_V][TAILLE_H], int y, int x);
