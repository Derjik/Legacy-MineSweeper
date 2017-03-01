#include "grid.h"

typedef
struct grille
{
    char mines[TAILLE_V][TAILLE_H];
    int flags[TAILLE_V][TAILLE_H];
    bool checked[TAILLE_V][TAILLE_H];
}
    grille;


int main(void)
{
    int x,y;

    srand(time(NULL));
    grille demineur;

    zero(demineur.mines, ' ');
    bomb(demineur.mines);
    zeroInt(demineur.flags, 9);
    zeroBool(demineur.checked, false);

    do
    {
        printf("  Demineur v0.3 (dediMath!) - by Derjik\n");
        printf("\t\t\t\t\t(NB: insecure build!)\n");
        afficheInt(demineur.flags, demineur.checked);
        // affiche(demineur.mines); // Pour faire du débug, décomenter cette ligne.
        printf("Coordonnees a checker (x,y): ");
        scanf("%d%d", &x, &y);
        test(demineur.mines, y-1, x-1, demineur.flags, demineur.checked);
        system("CLS");
    }while(demineur.flags[y-1][x-1] != -1);

    printf("  Demineur v0.3 (dediMath!) - by Derjik\n");
    printf("\t\t\t\t\t<u have mail:> KOM T NUL !\n");
    affiche(demineur.mines);
    printf("Perdu. <build: %s, %s>\n", __DATE__, __TIME__);
    system("PAUSE");
    return 0;
}
