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
    System::Console::ForegroundColor = System::ConsoleColor(0);
    std::cout << " negras ";
    System::Console::BackgroundColor = System::ConsoleColor(0);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << "\nLas fichas del Jugador 2 son ";
    System::Console::BackgroundColor = System::ConsoleColor(6);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << " blancas ";

    System::Console::BackgroundColor = System::ConsoleColor(0);
    System::Console::ForegroundColor = System::ConsoleColor(15);
    std::cout << "\n\nLa ficha solo se podra desplazar ficha hacia adelante una casilla."
		<< "\nSe podra comer las fichas del adversario diagonalmente por casilla."
		<< "\n\nSi la ficha del jugador llega al otro extremo del tablero,\nesta ficha sera coronada reina."
		<< "\nLas reinas podran moverse verticalmente y comer diagonalmente a su antojo."
		<< "\n\nEl jugador gana si come todas las fichas del adversario."
		<< "\nSi los dos jugadores se quedan con una ficha y pasan tres turnos,\nse termina la partida como empate."
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

    // Pantalla_Principal(j1);
    //Pantalla_Ganador(hay_ganador, j1);

    system("pause > NULL");
}