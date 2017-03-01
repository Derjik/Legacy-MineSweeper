#include "grid.h"


void affiche(char t[TAILLE_V][TAILLE_H])
{
    int i,j,z;

    char coin_hg=-38, coin_bd=-39, coin_bg=-64, coin_hd=-65;
    char pic=-63, sta=-62, pg=-61, pd=-76, cross=-59;
    char ligne=-60,col=-77;

    printf("\t ");
    for ( i = 0 ; i < TAILLE_H ; i++ )
    {
        printf(" %d", i+1);
    }
    printf("\n");

    printf("\t %c",coin_hg);
    for ( i = 0 ; i < (TAILLE_H*2) - 1 ; i++)
    {
        if(i%2 == 0)
        {
            printf("%c",ligne);
        }
        else
        {
            printf("%c",sta);
        }
    }
    printf("%c\n",coin_hd);

    for ( i = 0 ; i < TAILLE_V ; i++ )
    {

        printf("\t%d%c", i+1, col);
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            printf("%c%c", t[i][j], col);
        }
        printf("\n");
        if(i<TAILLE_V-1)
        {
            printf("\t %c",pg);
            for ( z = 0 ; z < (TAILLE_H*2) - 1 ; z++)
            {
                if(z%2 == 0)
                {
                    printf("%c",ligne);
                }
                else
                {
                    printf("%c",cross);
                }
            }
            printf("%c\n",pd);
        }
        else
        {
            printf("\t %c",coin_bg);
            for ( z = 0 ; z < (TAILLE_H*2) - 1 ; z++)
            {
                if(z%2 == 0)
                {
                    printf("%c",ligne);
                }
                else
                {
                    printf("%c",pic);
                }
            }
            printf("%c\n",coin_bd);
        }
    }
}


void afficheInt(int t[TAILLE_V][TAILLE_H], bool checked[TAILLE_V][TAILLE_H])
{
    int i,j,z;

    char coin_hg=-38, coin_bd=-39, coin_bg=-64, coin_hd=-65;
    char pic=-63, sta=-62, pg=-61, pd=-76, cross=-59;
    char ligne=-60,col=-77, blank=-80;

    printf("\t ");
    for ( i = 0 ; i < TAILLE_H ; i++ )
    {
        printf(" %d", i+1);
    }
    printf("\n");

    printf("\t %c",coin_hg);
    for ( i = 0 ; i < (TAILLE_H*2) - 1 ; i++)
    {
        if(i%2 == 0)
        {
            printf("%c", ligne);
        }
        else
        {
            printf("%c",sta);
        }
    }
    printf("%c\n",coin_hd);

    for ( i = 0 ; i < TAILLE_V ; i++ )
    {
        printf("\t%d%c", i+1, col);
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            if(checked[i][j] == true)
            {
                printf("%d%c", t[i][j], col);
            }
            else
            {
                printf("%c%c",blank, col);
            }
        }
        printf("\n");

        if(i<TAILLE_V-1)
        {
            printf("\t %c",pg);
            for ( z = 0 ; z < (TAILLE_H*2) - 1 ; z++)
            {
                if(z%2 == 0)
                {
                    printf("%c",ligne);
                }
                else
                {
                    printf("%c",cross);
                }
            }
            printf("%c\n",pd);
        }
        else
        {
            printf("\t %c",coin_bg);
            for ( z = 0 ; z < (TAILLE_H*2) - 1 ; z++)
            {
                if(z%2 == 0)
                {
                    printf("%c",ligne);
                }
                else
                {
                    printf("%c",pic);
                }
            }
            printf("%c\n",coin_bd);
        }
    }
}


void zero(char t[TAILLE_V][TAILLE_H], char sym)
{
    int i,j;
    for ( i = 0 ; i < TAILLE_V ; i++ )
    {
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            t[i][j] = sym;
        }
    }
}


void zeroInt(int t[TAILLE_V][TAILLE_H], int sym)
{
    int i,j;
    for ( i = 0 ; i < TAILLE_V ; i++ )
    {
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            t[i][j] = sym;
        }
    }
}


void zeroBool(bool t[TAILLE_V][TAILLE_H], bool sym)
{
    int i,j;
    for ( i = 0 ; i < TAILLE_V ; i++ )
    {
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            t[i][j] = sym;
        }
    }
}


void randomise(char t[TAILLE_V][TAILLE_H])
{
    int i,j;
    for ( i = 0 ; i < TAILLE_V ; i++ )
    {
        for ( j = 0 ; j < TAILLE_H ; j++ )
        {
            t[i][j] = random(0,100);
        }
    }
}


void bomb(char t[TAILLE_V][TAILLE_H])
{
    int i,j,c;
    for ( c = 0 ; c < MINES ; )
    {
        i=random(0,TAILLE_V-1);
        Sleep(50);
        j=random(0,TAILLE_H-1);
        Sleep(50);

        if(t[i][j] != 'X')
        {
            t[i][j] = 'X';
            c++;
        }
    }
}


int random(int min, int max)
{
    return ( ( rand()%(max - min + 1) ) + min );
}


void test(char t[TAILLE_V][TAILLE_H], int y, int x, int f[TAILLE_V][TAILLE_H], bool chk[TAILLE_V][TAILLE_H])
{
    int i, j;

    f[y][x] = lookup(t, y, x);
    chk[y][x] = true;

    if(f[y][x] == 0)
    {
        for ( i = y-1 ; i <= y+1 ; i++ )
        {
            for ( j = x-1 ; j <= x+1 ; j++ )
            {
                if( (i >= 0) && (i < TAILLE_V) && (j>=0) && (j<TAILLE_H) && (t[i][j] != 'X') && (chk[i][j] == false))
                {
                    test(t, i, j, f, chk);
                }
            }
        }
    }
}


int lookup(char t[TAILLE_V][TAILLE_H], int y, int x)
{
    int nb=0, i, j;

    if(t[y][x] == 'X')
    {
        return -1;
    }

    for ( i = y-1 ; i <= y+1 ; i++ )
    {
        for ( j = x-1 ; j <= x+1 ; j++ )
        {
            if((i>=0)&&(i<TAILLE_V)&&(j>=0)&&(j<TAILLE_H)&&(t[i][j] == 'X'))
            {
                nb++;
            }
        }
    }

    return nb;
}
