#include <Dibujo.hpp>
#include <Ventana.hpp>
#include <Corredor.hpp>

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
    Corredor* corredor1 = new Corredor(0, 15);

    list<Dibujo *> dibujos;
    dibujos.push_back(corredor1);

    list<Actualizable *> Actualizables;
    Actualizables.push_back(corredor1);

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
        if (ascii=='d'||ascii=='D'||ascii==KEY_RIGHT)
        {
            corredor1->Derecha();
        }
        if (ascii=='a'||ascii=='A'||ascii==KEY_LEFT)
        {
            corredor1->Izquierda();
        }
        
        refresh();

        ventana.Actualizar(Actualizables);
        ventana.Dibujar(dibujos);
    }
    return 0;
}