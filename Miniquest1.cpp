#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int keyInventory = 0;

int nearDragon(char Map[10][11], int PosX, int PosY)
{
    if (Map[PosY + 1][PosX] == 'D')
        return 1;
    else if (Map[PosY - 1][PosX] == 'D')
        return 1;
    else if (Map[PosY][PosX + 1] == 'D')
        return 1;
    else if (Map[PosY][PosX - 1] == 'D')
        return 1;
    else
        return 0;
}

void keyGenerator(char Map[10][11])
{
    int PosX, PosY;

    do
    {
        PosX = rand() % 10;
        PosY = rand() % 10;

    }

    while ((Map[PosY][PosX] != ' ') || (nearDragon(Map, PosX, PosY)));

    Map[PosY][PosX] = 'K';
}

int nextMove(char Map[10][11], int *currentX, int *currentY, int nextX, int nextY)

{

    if (Map[nextY][nextX] == 'X')
    {
    }
    else if (Map[nextY][nextX] == 'K')
    {
        Map[*currentY][*currentX] = ' ';
        Map[nextY][nextX] = 'H';
        *currentX = nextX;
        *currentY = nextY;
        keyInventory = 1;
    }
    else if (Map[nextY][nextX] == ' ')
    {
        Map[*currentY][*currentX] = ' ';
        Map[nextY][nextX] = 'H';
        *currentX = nextX;
        *currentY = nextY;
    }
    else if (Map[nextY][nextX] == 'E')
    {
        if (keyInventory == 0)
        {
        }
        else if (keyInventory == 1)
        {
            Map[nextY][nextX] = ' ';
        }
    }
    return 0;
}

int moveHero(char KeyPress, char Map[10][11], int *PosX, int *PosY)
{

    switch (KeyPress)
    {

    case 'w':
    case 'W':
    {
        nextMove(Map, PosX, PosY, *PosX, *PosY - 1);
        break;
    }

    case 'a':
    case 'A':
    {
        nextMove(Map, PosX, PosY, *PosX - 1, *PosY);
        break;
    }

    case 's':
    case 'S':
    {
        nextMove(Map, PosX, PosY, *PosX, *PosY + 1);
        break;
    }

    case 'd':
    case 'D':
    {
        nextMove(Map, PosX, PosY, *PosX + 1, *PosY);
        break;
    }
    }
    return 0;
}

int printMap(char Map[10][11])
{

    for (int i = 0; i < 10; i++)
    {
        for (int x = 0; x < 10; x++)
        {

            cout << Map[i][x];
            cout << " ";
        }

        cout << "\n";
    }

    return 0;
}

int gameOver(char Map[10][11], int PosX, int PosY)
{
    if (nearDragon(Map, PosX, PosY))
    {
        cout << "\n\n\n\n\n\nMorreste\n\n\n\n\n\n\n";
        return 1;
    }

    else if (Map[5][9] == 'H')
    {
        cout << "\n\n\n\n\n\nVitória\n\n\n\n\n\n\n";
        return 1;
    }

    else
        return 0;
}

int main()
{
    srand(time(NULL));

    char KeyPress;

    int PosX = 1;
    int PosY = 1;

    char Map[10][11] = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'},
        {'X', 'H', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '\0'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '\0'},
        {'X', 'D', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '\0'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '\0'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'E', '\0'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '\0'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '\0'},
        {'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', '\0'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'}};

    keyGenerator(Map);
    printMap(Map);

    while (1)
    {   
        
        if(gameOver(Map, PosX, PosY)) break;
        cin >> KeyPress;
        cout << "\n";
        moveHero(KeyPress, Map, &PosX, &PosY);
        printMap(Map);
    }
    return 0;
}