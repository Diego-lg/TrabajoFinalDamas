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
   
    for (int w = 0; w < 8; w++)
    {
        int x = board[0][w];

        cout << x << " ";
    }
    cout <<"\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[1][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[2][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[3][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[4][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[5][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[6][w];

        cout << x << " ";
    }
    cout << "\n";
    for (int w = 0; w < 8; w++)
    {
        int x = board[7][w];

        cout << x << " ";
    }
    cout << "\n";
    }


int main()
{
    //Pantalla_Inicio();
    Tablero();
    _getch();
}
