#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
void Pantalla_Inicio() {
    std::cout << "\n\t`7MM\"\"\"Yb.                                                "
        << "\n\t  MM    `Yb.                                                 "
        << "\n\t  MM     `Mb  ,6\"Yb.  `7MMpMMMb.pMMMb.   ,6\"Yb.  ,pP\"Ybd  "
        << "\n\t  MM      MM 8)   MM    MM    MM    MM  8)   MM  8I   `\"    "
        << "\n\t  MM     ,MP  ,pm9MM    MM    MM    MM   ,pm9MM  `YMMMa.     "
        << "\n\t  MM    ,dP' 8M   MM    MM    MM    MM  8M   MM  L.   I8     "
        << "\n\t .JMMmmmdP'   `Moo9^Yo..JMML  JMML  JMML.`Moo9^Yo.M9mmmP'    "
        << "\n\n";

    std::cout << "\n\t\t||\tPresentado por:\t\t||"
        << "\n\t\t||\tCristina Vidal\t\t||"
        << "\n\t\t||\tDiego Li\t\t||"
        << "\n\t\t||\tGabriela Estrada\t||"
        << "\n\n";

}
void Tablero()
{
    int board[8][8] =
    {           -1, 0,-1, 0,-1, 0,-1, 0,
                0,-1, 0,-1, 0,-1, 0,-1,
               -1, 0,-1, 0,-1, 0,-1, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 0, 1, 0, 1, 0, 1,
                1, 0, 1, 0, 1, 0, 1, 0,
                0, 1, 0, 1, 0, 1, 0, 1 };
    int y = board[8][8];
    cout << y;
    for (int w = 0; w < 8; w++)
    {
        int x = board[w-1][8];
        cout << x << "\n";
        
        
        cout << "\n";
    }
    /*int filas = 0, columnas = 0, ubicacion = 0;
    for (int x = 0; x < 64; x++)
    {
        cout << board[x] << " ";
        if ((x + 1) % 8 == 0)
        {
            cout << endl;
        }
    }*/

}
void Pantalla_Principal()
{

int contador_fichas1 = 12, contador_fichas2 = 12;
char matriz[8][8];
for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 ;j++)
        {
            std::cout << matriz[8][j] << "\t" ;
        }
        cout << "\n";
    }


}



int main()
{
    //Pantalla_Inicio();
    Pantalla_Principal();
    Tablero();
    _getch();
}