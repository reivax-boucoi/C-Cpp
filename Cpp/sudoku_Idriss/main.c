#include <stdio.h>
#include <stdlib.h>

typedef struct cellule cellule;
struct cellule {
    char posb[10];
    int valeur;
    char sourceDir[10];
    int choice;
    int nbrChoice;
};
typedef struct check check;
struct check {
    int poY[9][9];
    int poX[9][9];
    int nbr[9];
};

int    count_posb(char posb[10])
{
    int index = 0;
    int count = 0;

    while(index < 9)
    {
        if(posb[index] != '0')
            count++;
        index++;
    }
    return(count);
}

void    init_xy(int posX, int posY, int *x, int *y)
{
    if(posX % 3 == 0)
        *x = posX;
    else if(posX % 3 == 1)
        *x = posX - 1;
    else if(posX % 3 == 2)
        *x = posX - 2;

    if(posY % 3 == 0)
        *y = posY;
    else if(posY % 3 == 1)
        *y = posY - 1;
    else if(posY % 3 == 2)
        *y = posY - 2;
}

void    print_grid(cellule grid[9][9])
{
    int y = 0;
    int x = 0;

    while(y < 9)
    {
        if(y == 0)
            printf(" =========================================\n");
        else if(y % 3 == 0)
        {
            printf(" ||===========||===========||===========||\n");
        }
        else
            printf(" ||---|---|---||---|---|---||---|---|---||\n");
        while(x < 9)
        {
            if(x % 3 == 0 || x == 0)
                printf(" || ");
            else
                printf(" | ");
            if(grid[y][x].valeur == 0)
                printf(" ");
            else
                printf("%d", grid[y][x].valeur);
            x++;
        }
        x = 0;
        y++;
        printf(" || ");
        printf("\n");
    }
    printf(" =========================================\n");
    while(x < 4)
    {
        printf("\n");
        x++;
    }
}

void    add_nbr(cellule grid[9][9])
{
    check mem;
    check last;
    int count = 0;
    int countMem = 0;
    int index = 0;
    int i = 0;
    int y = 0;
    int x = 0;
    int minX = 0;
    int minY = 0;
    int memY = 0;
    int memX = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            mem.poX[y][x] = 0;
            mem.poY[y][x] = 0;
            last.poX[y][x] = 0;
            last.poY[y][x] = 0;
            x++;
        }
        mem.nbr[y] = 0;
        last.nbr[y] = 0;
        x = 0;
        y++;
    }
    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur == 0)
                {
                    while(index < 9)
                    {
                        if(grid[y][x].posb[index] != '0')
                        {
                            count++;
                            countMem = index;
                        }
                        index++;
                    }
                    index = 0;
                    if(count == 1)
                    {
                        grid[y][x].valeur = countMem + 1;
                        grid[y][x].posb[countMem] = '0';
                        minX = memX;
                        minY = memY;
                        while(minY < memY + 3)
                        {
                            while(minX < memX + 3)
                            {
                                grid[minY][minX].posb[countMem] = '0';
                                minX++;
                            }
                            minX = memX;
                            minY++;
                        }
                    }
                    index = 0;
                    count = 0;
                }
                if(grid[y][x].valeur != 0)
                {
                    last.nbr[grid[y][x].valeur - 1] = grid[y][x].valeur;
                }
                else
                {
                    last.poX[0][0] = x;
                    last.poY[0][0] = y;
                }
                x++;
            }
            x = memX;
            y++;
        }
        y = 0;
        x = 0;
        minY = memY;
        minX = memX;
        while(minY < memY + 3)
        {
            while(minX < memX + 3)
            {
                if(grid[minY][minX].valeur == 0)
                {
                    while(index < 9)
                    {
                        if(grid[minY][minX].posb[index] != '0')
                        {
                            mem.nbr[index]++;
                            mem.poX[index][mem.nbr[index] - 1] = minX;
                            mem.poY[index][mem.nbr[index] - 1] = minY;
                        }
                        index++;
                    }
                    index = 0;
                }
                minX++;
            }
            minX = memX;
            minY++;
        }
        while(index < 9)
        {
            if(mem.nbr[index] == 1)
            {
                minX = memX;
                minY = memY;
                while(minY < memY + 3)
                {
                    while(minX < memX + 3)
                    {
                        grid[minY][minX].posb[index] = '0';
                        minX++;
                    }
                    minX = memX;
                    minY++;
                }


                grid[mem.poY[index][0]][mem.poX[index][0]].valeur = index + 1;
                while(x < 9)
                {
                    grid[mem.poY[index][0]][mem.poX[index][0]].posb[x] = '0';
                    x++;
                }
            }
            index++;
        }
        index = 0;
        x = 0;
        while(index < 9)
        {
            if(last.nbr[index] == 0)
            {
                count++;
                countMem = index;
            }
            index++;
        }
        if(count == 1)
        {
            grid[last.poY[0][0]][last.poX[0][0]].valeur = countMem + 1;
            while(x < 9)
            {
                grid[last.poY[0][0]][last.poX[0][0]].posb[x] = '0';
                x++;
            }
            x = 0;
        }
        index = 0;
        count = 0;
        countMem = 0;
        while(y < 9)
        {
            while(x < 9)
            {
                mem.poX[y][x] = 0;
                mem.poY[y][x] = 0;
                last.poX[y][x] = 0;
                last.poY[y][x] = 0;
                x++;
            }
            mem.nbr[y] = 0;
            last.nbr[y] = 0;
            x = 0;
            y++;
        }
        i++;
    }
}

void    update_poss(cellule grid[9][9], char ligneH[9][10], char ligneV[9][10])
{
    check value;
    int index = 0;
    int i = 0;
    int y = 0;
    int x = 0;
    int memY = 0;
    int memX = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            value.poX[y][x] = 0;
            value.poY[y][x] = 0;
            x++;
        }
        value.nbr[y] = 0;
        x = 0;
        y++;
    }

    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur != 0)
                    value.nbr[grid[y][x].valeur - 1] = grid[y][x].valeur;
                x++;
            }
            x = memX;
            y++;
        }
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur == 0)
                {
                    while(index < 9)
                    {
                        if(value.nbr[index] != 0)
                        {
                            grid[y][x].posb[index] = '0';
                        }
                        if(ligneH[y][index] != '0' && grid[y][x].sourceDir[index] != 'H')
                        {
                            grid[y][x].posb[index] = '0';
                        }
                        if(ligneV[x][index] != '0' && grid[y][x].sourceDir[index] != 'V')
                        {
                            grid[y][x].posb[index] = '0';
                        }
                        index++;
                    }
                    index = 0;
                }
                x++;
            }
            x = memX;
            y++;
        }
        x = 0;
        y = 0;
        while(y < 9)
        {
            while(x < 9)
            {
                value.poX[y][x] = 0;
                value.poY[y][x] = 0;
                x++;
            }
            value.nbr[y] = 0;
            x = 0;
            y++;
        }
        i++;
    }
}

void    supposition(cellule grid[9][9], char ligneH[9][10], char ligneV[9][10])
{
    check align;
    int memXbis = 0;
    int memYbis = 0;
    int index = 0;
    int i = 0;
    int y = 0;
    int x = 0;
    int memY = 0;
    int memX = 0;
    while(y < 9)
    {
        while(x < 9)
        {
            align.poX[y][x] = 0;
            align.poY[y][x] = 0;
            x++;
        }
        align.nbr[y] = 0;
        x = 0;
        y++;
    }
    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur == 0)
                {
                    while(index < 9)
                    {
                        if(grid[y][x].posb[index] != '0')
                        {
                            align.nbr[index]++;
                            align.poX[index][align.nbr[index] - 1] = x;
                            align.poY[index][align.nbr[index] - 1] = y;
                        }
                        index++;
                    }
                    index = 0;
                }
                x++;
            }
            x = memX;
            y++;
        }
        x = 0;
        y = 0;
        while(index < 9)
        {
            if(align.nbr[index] > 1 && align.nbr[index] < 4)
            {
                while(x < align.nbr[index])
                {
                    if(align.poX[index][x] != align.poX[index][0])
                        memXbis = -1;
                    if(align.poY[index][x] != align.poY[index][0])
                        memYbis = -1;
                    x++;
                }
                x = 0;
                if(memXbis != -1)
                {
                    while(x < align.nbr[index])
                    {
                        grid[align.poY[index][x]][align.poX[index][x]].sourceDir[index] = 'V';
                        x++;
                    }
                    x = 0;
                    ligneV[align.poX[index][x]][index] = (index + 1) + 48;
                }
                x = 0;
                if(memYbis != -1)
                {
                    while(x < align.nbr[index])
                    {
                        grid[align.poY[index][x]][align.poX[index][x]].sourceDir[index] = 'H';
                        x++;
                    }
                    x = 0;
                    ligneH[align.poY[index][x]][index] = (index + 1) + 48;
                }
                memXbis = 0;
                memYbis = 0;
                x = 0;
            }
            index++;
        }
        index = 0;
        while(y < 9)
        {
            while(x < 9)
            {
                align.poX[y][x] = 0;
                align.poY[y][x] = 0;
                x++;
            }
            align.nbr[y] = 0;
            x = 0;
            y++;
        }
        i++;
    }
}

void    update_ligne(cellule grid[9][9], char ligneH[9][10], char ligneV[9][10])
{
    int x = 0;
    int y = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            if(grid[y][x].valeur != 0)
            {
                ligneH[y][grid[y][x].valeur - 1] = grid[y][x].valeur + 48;
                ligneV[x][grid[y][x].valeur - 1] = grid[y][x].valeur + 48;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

int    choice(cellule grid[9][9], int etape)
{
    check choix;
    int count = 0;
    int countMem = 0;
    int index = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    int memX = 0;
    int memY = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            choix.poX[y][x] = 0;
            choix.poY[y][x] = 0;
            x++;
        }
        choix.nbr[y] = 0;
        x = 0;
        y++;
    }

    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(etape == 0)
                {
                    if(grid[y][x].nbrChoice > 2)
                        grid[y][x].choice = -1;
                    if(grid[y][x].valeur == 0 && grid[y][x].choice != -1)
                    {
                        while(index < 9)
                        {
                            if(grid[y][x].posb[index] != '0')
                            {
                                choix.nbr[index]++;
                                choix.poX[index][choix.nbr[index] - 1] = x;
                                choix.poY[index][choix.nbr[index] - 1] = y;
                            }
                            index++;
                        }
                        index = 0;
                    }
                }
                else
                {
                    if(grid[y][x].choice > 0)
                    {
                        if(choix.nbr[0] != 0)
                        {
                            grid[choix.poY[0][0]][choix.poX[0][0]].valeur = grid[choix.poY[0][0]][choix.poX[0][0]].choice;
                            grid[y][x].valeur = grid[y][x].choice;
                            while(index < 9)
                            {
                                grid[choix.poY[0][0]][choix.poX[0][0]].posb[index] = '0';
                                grid[y][x].posb[index] = '0';
                                index++;
                            }
                            return(0);
                        }
                        else
                        {
                            choix.nbr[0] = 1;
                            choix.poY[0][0] = y;
                            choix.poX[0][0] = x;
                        }
                    }
                }
                x++;
            }
            x = memX;
            y++;
        }
        if(etape == 0)
        {
            while(index < 9)
            {
                if(choix.nbr[index] == 2)
                {
                    count++;
                    if(count == 2)
                    {
                        if(grid[choix.poY[countMem][choix.nbr[countMem] - 1]][choix.poX[countMem][choix.nbr[countMem] - 1]].choice != 0)
                        {
                            grid[choix.poY[countMem][choix.nbr[countMem] - 1]][choix.poX[countMem][choix.nbr[countMem] - 1]].choice = index + 1;
                            grid[choix.poY[index][choix.nbr[index] - 1]][choix.poX[index][choix.nbr[index] - 1]].choice = countMem + 1;
                            grid[choix.poY[countMem][choix.nbr[countMem] - 1]][choix.poX[countMem][choix.nbr[countMem] - 1]].nbrChoice++;
                            grid[choix.poY[index][choix.nbr[index] - 1]][choix.poX[index][choix.nbr[index] - 1]].nbrChoice++;
                            return(0);
                        }
                        else
                        {
                            grid[choix.poY[countMem][choix.nbr[countMem] - 1]][choix.poX[countMem][choix.nbr[countMem] - 1]].choice = countMem + 1;
                            grid[choix.poY[index][choix.nbr[index] - 1]][choix.poX[index][choix.nbr[index] - 1]].choice = index + 1;
                            grid[choix.poY[countMem][choix.nbr[countMem] - 1]][choix.poX[countMem][choix.nbr[countMem] - 1]].nbrChoice++;
                            grid[choix.poY[index][choix.nbr[index] - 1]][choix.poX[index][choix.nbr[index] - 1]].nbrChoice++;
                            return(0);
                        }
                    }
                    else
                        countMem = index;
                }
                index++;
            }
            index = 0;
        }
        y = 0;
        x = 0;
        while(y < 9)
        {
            while(x < 9)
            {
                choix.poX[y][x] = 0;
                choix.poY[y][x] = 0;
                x++;
            }
            choix.nbr[y] = 0;
            x = 0;
            y++;
        }
        i++;
    }
    return(0);
}

int     check_error(cellule grid[9][9])
{
    char indexMem[10];
    int index = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    int memX = 0;
    int memY = 0;

    while(index < 9)
    {
        indexMem[index] = '0';
        index++;
    }
    indexMem[9] = '\0';
    index = 0;

    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur == 0 && count_posb(grid[y][x].posb) == 0)
                    return(1);
                if(grid[y][x].valeur != 0 && count_posb(grid[y][x].posb) != 0)
                    return(1);
                while(index < 9)
                {
                    if(grid[index][x].valeur == grid[y][x].valeur && index != y)
                        return(1);
                    if(grid[y][index].valeur == grid[y][x].valeur && index != x)
                        return(1);
                    index++;
                }
                index = 0;
                if(grid[y][x].valeur != 0)
                {
                    if(indexMem[grid[y][x].valeur - 1] != '0')
                        return(1);
                    else
                        indexMem[grid[y][x].valeur - 1] = grid[y][x].valeur + 48;
                }
                x++;
            }
            x = memX;
            y++;
        }
        while(index < 9)
        {
            indexMem[index] = '0';
            index++;
        }
        indexMem[9] = '\0';
        index = 0;
        i++;
    }
    return(0);
}

void    copy_grid(cellule gridA[9][9], cellule gridVers[9][9])
{
    int index = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    int memX = 0;
    int memY = 0;

    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                gridVers[y][x].valeur = 0;
                gridVers[y][x].choice = 0;
                gridVers[y][x].nbrChoice = 0;
                while(index < 9)
                {
                    gridVers[y][x].sourceDir[index] = '0';
                    gridVers[y][x].posb[index] = '0';
                    index++;
                }
                index = 0;
                x++;
            }
            x = memX;
            y++;
        }
        i++;
    }
    i = 0;
    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                gridVers[y][x].valeur = gridA[y][x].valeur;
                gridVers[y][x].choice = gridA[y][x].choice;
                gridVers[y][x].nbrChoice = gridA[y][x].nbrChoice;
                while(index < 9)
                {
                    gridVers[y][x].sourceDir[index] = gridA[y][x].sourceDir[index];
                    gridVers[y][x].posb[index] = gridA[y][x].posb[index];
                    index++;
                }
                index = 0;
                x++;
            }
            x = memX;
            y++;
        }
        i++;
    }
}

int    compare_grid(cellule grid[9][9], cellule gridBis[9][9])
{
    int index = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    int memX = 0;
    int memY = 0;

    while(i < 9)
    {
        if(i == 0 || i % 3 == 0)
            memY = i;
        memX = (i % 3) * 3;
        x = memX;
        y = memY;
        while(y < memY + 3)
        {
            while(x < memX + 3)
            {
                if(grid[y][x].valeur != gridBis[y][x].valeur)
                    return(0);
                while(index < 9)
                {
                    if(grid[y][x].sourceDir[index] != gridBis[y][x].sourceDir[index])
                        return(0);
                    if(grid[y][x].posb[index] != gridBis[y][x].posb[index])
                        return(0);
                        index++;
                }
                index = 0;
                x++;
            }
            x = memX;
            y++;
        }
        i++;
    }
    return(1);
}

void    init_ligne(char ligneH[9][10], char ligneV[9][10], cellule grid[9][9])
{
    int i = 0;
    int x = 0;
    int y = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            ligneH[y][x] = '0';
            ligneV[x][y] = '0';
            x++;
        }
        x = 0;
        y++;
    }
    y = 0;
    while(i < 9)
    {
        ligneH[i][9] = '\0';
        ligneV[i][9] = '\0';
        i++;
    }

    while(y < 9)
    {
        while(x < 9)
        {
            if(grid[y][x].valeur != 0)
            {
                ligneH[y][grid[y][x].valeur - 1] = grid[y][x].valeur + 48;
                ligneV[x][grid[y][x].valeur - 1] = grid[y][x].valeur + 48;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void    init_grid(cellule grid[9][9], char input[9][11])
{
    int i = 0;
    int x = 0;
    int y = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            if(input[y][x] == '.')
            {
                grid[y][x].valeur = 0;
                while(i < 9)
                {
                    grid[y][x].posb[i] = (i + 1) + 48;
                    i++;
                }
                i = 0;
            }
            else
            {
                grid[y][x].valeur = input[y][x] - 48;
                while(i < 9)
                {
                    grid[y][x].posb[i] = '0';
                    i++;
                }
                i = 0;
            }
            while(i < 9)
            {
                grid[y][x].sourceDir[i] = '0';
                i++;
            }
            i = 0;
            grid[y][x].nbrChoice = 0;
            grid[y][x].choice = 0;
            grid[y][x].sourceDir[9] = '\0';
            grid[y][x].posb[9] = '\0';

            x++;
        }
        x = 0;
        y++;
    }

}

int     finish_test(cellule grid[9][9])
{
    int y = 0;
    int x = 0;

    while(y < 9)
    {
        while(x < 9)
        {
            if(grid[y][x].valeur == 0)
                return(0);
            x++;
        }
        x = 0;
        y++;
    }
    return(1);
}

void    ft_resolve(char input[9][11])
{
    cellule grid[9][9];
    cellule gridTem[9][9];
    cellule gridMem[9][9];
    int done = 0;
    int count = 1;
    char ligneV[9][10];
    char ligneH[9][10];
    int y = 0;
    int x = 0;
    int memX = 0;
    int memY = 0;
    int i = 0;
    int countMem = 0;

    init_grid(grid, input);
    init_ligne(ligneH, ligneV, grid);
    update_poss(grid, ligneH, ligneV);
    copy_grid(grid, gridMem);
    copy_grid(grid, gridTem);
    print_grid(grid);

    while(!done)
    {
        if(countMem == 1)
        {
            //exit(EXIT_SUCCESS);
        }
        if(count == 0)
        {
            countMem = 1;
            if(compare_grid(grid, gridTem) == 1)
            {
                done = 1;
                if(check_error(grid) == 1)
                {

                    copy_grid(gridMem, grid);
                }
                choice(grid, 0);
                copy_grid(grid, gridMem);
                choice(grid, 1);
            }
            copy_grid(grid, gridTem);
        }
        update_ligne(grid, ligneH, ligneV);
        update_poss(grid, ligneH, ligneV);

        supposition(grid, ligneH, ligneV);
        update_poss(grid, ligneH, ligneV);

        add_nbr(grid);
        update_poss(grid, ligneH, ligneV);

        done = finish_test(grid);
        if(y > 81)
            done = 2;
        y++;
        count++;
        if(count > 4)
            count = 0;
    }
    printf("Grille resolue en %d iterations.\n\n", y);
    print_grid(grid);
}

int main()
{
    char argv[9][11];
    int i = 0;
    FILE *grille = NULL;

    grille = fopen("grille.txt", "r");
    if(grille == NULL)
        return(0);
    else
    {
        while(i < 9)
        {
            fgets(argv[i], 11, grille);
            argv[i][9] = '\0';
            i++;
        }
    }
    fclose(grille);
    ft_resolve(argv);
    return 0;
}
