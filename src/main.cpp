#include <Dibujo.hpp>
#include <Ventana.hpp>
#include <Corredor.hpp>
#include <Rampa.hpp>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <string>
#include <list>

using namespace std;

int main()
{
    Ventana ventana;
    Corredor corredor;
    Rampa rampa;
    Corredor *corredor1 = new Corredor(30, 15);
    Rampa *rampa1 = new Rampa(225, 15);
    Rampa *rampa2 = new Rampa(450, 0);
    Rampa *rampa3 = new Rampa(100, 30);

    list<Dibujo *> dibujos;
    dibujos.push_back(corredor1);
    dibujos.push_back(rampa1);
    dibujos.push_back(rampa2);
    dibujos.push_back(rampa3);

    list<Actualizable *> Actualizables;
    Actualizables.push_back(corredor1);
    Actualizables.push_back(rampa1);
    Actualizables.push_back(rampa2);
    Actualizables.push_back(rampa3);

    getch();

    while (true)
    {
        int ascii = getch();
        if (ascii == 'q' || ascii == 'Q')
            break;
        if (ascii == 'w' || ascii == 'W' || ascii == KEY_UP)
        {
            corredor1->CarrilArriba();
        }
        if (ascii == 's' || ascii == 'S' || ascii == KEY_DOWN)
        {
            corredor1->CarrilAbajo();
        }
        if (ascii == 'z' || ascii == 'Z' || ascii == KEY_RIGHT)
        {
            rampa1->Avanzar();
            rampa2->Avanzar();
            rampa3->Avanzar();
        }

        refresh();

        ventana.Actualizar(Actualizables);
        ventana.Dibujar(dibujos);
    }
    return 0;
}