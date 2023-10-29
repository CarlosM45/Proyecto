#pragma once
#include <Actualizable.hpp>
#include <Dibujo.hpp>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <string>
#include <list>

using namespace std;

class Ventana
{
private:
public:
    Ventana()
    {
        initscr();
        noecho();
        curs_set(FALSE);
        cbreak();
        keypad(stdscr, TRUE);
        timeout(10);
    }
    void Actualizar(list<Actualizable *> Actualizables)
    {
        for (auto &&Actualizable : Actualizables)
        {
            Actualizable->Actualizar();
        }
        usleep(1000 / 24);
    }
    void Dibujar(list<Dibujo *> dibujos)
    {
        clear();
        for (auto &&dibujo : dibujos)
        {
            dibujo->Dibujar();
        }
        box(stdscr, '=', '?');
        refresh();
    }

    ~Ventana()
    {
        keypad(stdscr, FALSE);
        endwin();
    }
};