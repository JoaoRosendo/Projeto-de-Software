#include <iostream>
#include <string.h>

using namespace std;

  char Map[10][11] = {
    {'X','X','X','X','X','X','X','X','X','X','\0'},
    {'X','H',' ',' ',' ',' ',' ',' ',' ','X','\0'},
    {'X',' ','X','X',' ','X',' ','X',' ','X','\0'},
    {'X','D','X','X',' ','X',' ','X',' ','X','\0'},
    {'X',' ','X','X',' ','X',' ','X',' ','X','\0'},
    {'X',' ',' ',' ',' ',' ',' ','X',' ','E','\0'},
    {'X',' ','X','X',' ','X',' ','X',' ','X','\0'},
    {'X',' ','X','X',' ','X',' ','X',' ','X','\0'},
    {'X',' ','X','X',' ',' ',' ',' ',' ','X','\0'},
    {'X','X','X','X','X','X','X','X','X','X','\0'}
    };


int moveHero(char KeyPress, char Map[10][11], int *PosX, int *PosY){

    switch(KeyPress) {

        case 'w' :
        case 'W' :
        {   
            if(Map[*PosY-1][*PosX] != 'X')
            {
                Map[*PosY][*PosX]   = ' ';
                Map[*PosY-1][*PosX] = 'H';
                *PosY = *PosY-1;
                
            }

            break;
        }

        case 'a' :
        case 'A' :
        {
            if(Map[*PosY][*PosX-1] != 'X')
            {
                Map[*PosY][*PosX]   = ' ';
                Map[*PosY][*PosX-1] = 'H';
                *PosX = *PosX-1;
            }

            break;
        }

        case 's' :
        case 'S' :
        {
             if(Map[*PosY+1][*PosX] != 'X')
            {
                Map[*PosY][*PosX]   = ' ';
                Map[*PosY+1][*PosX] = 'H';
                *PosY = *PosY+1;
            }
            
            break;
        }
        
        case 'd' :
        case 'D' :
        {   
             if(Map[*PosY][*PosX+1] != 'X')
            {
                Map[*PosY][*PosX]   = ' ';
                Map[*PosY][*PosX+1] = 'H';
                *PosX = *PosX+1;
            }
            break;
        }

    }
    return 0;
}




int printMap(char Map[10][11]){

    for(int i = 0; i<10; i++)
    {
        for(int x = 0; x<10; x++){

            std::cout << Map[i][x];
            std::cout << " ";
        }
    
        std::cout << "\n";
    }

    return 0;
}




int main() {

    char KeyPress;

    int PosX = 1;
    int PosY = 1;

   

    

   while(1){
        //cout << "Press a key";
        cin >> KeyPress;
        //cout << KeyPress;
        cout << "\n";
        moveHero(KeyPress, Map, &PosX, &PosY);
        printMap(Map);
        printf("%d %d",PosX,PosY);
        
   }
    return 0;
}