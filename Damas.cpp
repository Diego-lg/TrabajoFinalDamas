#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <windows.h> // prob not needed

struct Jugador {
    /*
    * Estructura del jugador
    */
    std::string nombre;
    int resultado;
};

struct Ficha {
    /*
    * Estructura de las fichas
    */
    char forma;
    int color;
};

struct Tablero {
    /*
    * POSIBLE Estructura de un tablero
    */
    int filas;
    int columnas;
    int colorPar;
    int colorImpar;
};

void Limpiar_Pantalla() {
    // Limpiar pantalla
    system("cls");
}

// Pantalla de Inicio
void Pantalla_Inicio() {
    /*
    * Pantalla principal de titulo y para entrar o salir del juego.
    */
    std::cout << "\n\t`7MM\"\"\"Yb.                                                "
        << "\n\t  MM    `Yb.                                                 "
        << "\n\t  MM     `Mb  ,6\"Yb.  `7MMpMMMb.pMMMb.   ,6\"Yb.  ,pP\"Ybd  "
        << "\n\t  MM      MM 8)   MM    MM    MM    MM  8)   MM  8I   `\"    "
        << "\n\t  MM     ,MP  ,pm9MM    MM    MM    MM   ,pm9MM  `YMMMa.     "
        << "\n\t  MM    ,dP' 8M   MM    MM    MM    MM  8M   MM  L.   I8     "
        << "\n\t .JMMmmmdP'   `Moo9^Yo..JMML  JMML  JMML.`Moo9^Yo.M9mmmP'    "
        << "\n\n";

    std::cout << "\n\t\t||         Presentado por:          ||"
        << "\n\t\t||         Cristina Vidal           ||"
        << "\n\t\t||         Diego Li                 ||"
        << "\n\t\t||         Gabriela Estrada         ||"
        << "\n\n\n";

    std::cout << "\n\t\t\tPresiona ESPACIO para jugar\t"
        << "\n\t\t\tPresiona Q para salir\t\t"
        << "\n\n\n";

    bool opt = true;
    int tecla;
    while(opt) { 
		if(_kbhit()) {
			tecla = _getch();
            
			switch(tecla) {
				// Presionar ESPACIO para entrar al juego
                case 32:
                    opt = false;
                    break;
				// Presionar tecla 'q'
				case 113:
					exit(0);
                    break;
			}
		}
    }
    
    Limpiar_Pantalla();
}

void Pantalla_Registro(Jugador j, int num) {

    std::cout << "\n\t\t\tColoque del jugador " << num 
              << ": " << "\n\t\t\t";
    std::cin >> j.nombre;
}

void Pantalla_Instrucciones() {
    std::cout << "\nCada jugador dispone de 12 fichas."
              << "\n\nLas finchas del Jugador 1 son ";
    System::Console::BackgroundColor = System::ConsoleColor(6);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << " blancas ";
    System::Console::BackgroundColor = System::ConsoleColor(0);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << "\nLas fichas del Jugador 2 son ";
    System::Console::BackgroundColor = System::ConsoleColor(6);
    System::Console::ForegroundColor = System::ConsoleColor(0);
    std::cout << " negras ";
    
    System::Console::BackgroundColor = System::ConsoleColor(0);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << "\n\nLa ficha solo se podra desplazar hacia adelante en diagonal."
        << "\nSe podra comer las fichas del adversario de igual manera."
        << "\nSe pueden comer varias fichas de forma encadenada en un solo movimiento."
        << "\nEs obligatorio comer. Si no se hace, \nel jugador adversario le comera la ficha que debia moverse."
        << "\n\nSi la ficha del jugador llega al otro extremo del tablero,\nesta ficha sera coronada reina. O -> @"
        << "\nLas reinas podran moverse diagonalmente a su antojo a su antojo si hay "
        << "\nespacio y comer diagonalmente a varias casillas de distancia."
		<< "\n\nEl jugador gana si come todas las fichas del adversario."
		<< "\nSi los dos jugadores no se pueden mover o se quedan con una ficha y \npasan tres turnos, se termina la partida como empate."
		<< "\n\nPresione ESPACIO para continuar" 
        << std::endl;

    bool opt = true;
    int tecla;
    while (opt) {
        if (_kbhit()) {
            tecla = _getch();
            switch (tecla) {
                // Presionar ESPACIO para entrar al juego
            case 32:
                opt = false;
                break;
            }
        }
    }
    
    Limpiar_Pantalla();
}

void Pantalla_Principal(Jugador &j1) {
   /*
   * Pantalla del juego
   */
    bool partida = true;
    do {
		// Pintar pantalla
        int tablero[24][24] = {
            {1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{1,1,1,2,4,2,1,1,1,2,4,2,1,1,1,2,4,2,1,1,1,2,4,2},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{2,4,2,1,1,1,2,4,2,1,1,1,2,4,2,1,1,1,2,4,2,1,1,1},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{1,1,1,2,4,2,1,1,1,2,4,2,1,1,1,2,4,2,1,1,1,2,4,2},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{2,3,2,1,1,1,2,3,2,1,1,1,2,3,2,1,1,1,2,3,2,1,1,1},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{1,1,1,2,3,2,1,1,1,2,3,2,1,1,1,2,3,2,1,1,1,2,3,2},
			{1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1},
			{2,3,2,1,1,1,2,3,2,1,1,1,2,3,2,1,1,1,2,3,2,1,1,1},
			{2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1,2,2,2,1,1,1}
        };
        
		// Indice 1 : ffffffcc  // Ver como cambiar color // bg: blanco
		// Indice 2 : ffc48300  // Ver como cambiar color // bg: ocre
        // Indice 3 : Pieza1 // bg: ocre    fg: blanco 
        // Indice 4 : Pieza2 // bg: ocre    fg: negro
        // Indice 5 : Pieza1 Reina // bg: ocre    fg: blanco 
        // Indice 6 : Pieza2 Reina // bg: ocre    fg: negro

        for (int f = 0; f <= 23; f++) {
			for (int c = 0; c <= 23; c++) {
                if (tablero[f][c] == 1) {
					System::Console::BackgroundColor = System::ConsoleColor(15);
                    std::cout << "   ";
                } else if (tablero[f][c] == 2) {
					System::Console::BackgroundColor = System::ConsoleColor(6);
                    std::cout << "   ";
                } else if (tablero[f][c] == 3) {
					System::Console::BackgroundColor = System::ConsoleColor(6);
					System::Console::ForegroundColor = System::ConsoleColor(15);
                    std::cout << " O ";
                } else if (tablero[f][c] == 4) {
					System::Console::BackgroundColor = System::ConsoleColor(6);
					System::Console::ForegroundColor = System::ConsoleColor(0);
                    std::cout << " O ";
                }
			}
            std::cout << "\n";
        }
        
        // Turno Jugador 1
        
        // Turno Jugador 2

        // Evaluar si aun se pueden hacer jugadas
        bool hayMovimientos = false;
        if(hayMovimientos == false)
			partida = false;

        // Limpiar_Pantalla();
    } while (partida);

}

void Pantalla_Ganador(bool g, std::string j) {
    if (g == true) {
        std::cout << "\n\t\t\tHaz ganado JUGADOR 1!!!\t"
            << "\n\t\t\t";
    }
}

int main() {
    bool hay_ganador = true;
    Jugador j1;
    Jugador j2;

    System::Console::SetWindowSize(74, 30);
    Pantalla_Inicio();

    Pantalla_Registro(j1, 1);
    std::cout << "\n\n";
    Pantalla_Registro(j2, 2);
    
    Limpiar_Pantalla();

    Pantalla_Instrucciones();

    Pantalla_Principal(j1);
    //Pantalla_Ganador(hay_ganador, j1);

    system("pause > NULL");
}