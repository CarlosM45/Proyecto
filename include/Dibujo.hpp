#pragma once
#include <iostream>
#include <fstream>
#include <curses.h>
#include <ncurses.h>
#include <string>

using namespace std;

class Dibujo
{
private:
    fstream archivo;

protected:
    int x, y;

public:
    Dibujo()
    {
        this->x = 0;
        this->y = 0;
    }
    Dibujo(int x, int y, string recurso)
    {
        archivo.open("./data/" + recurso + ".txt");
        this->x = x;
        this->y = y;
    }
    Dibujo(string recurso)
    {
        archivo.open("./data/" + recurso + ".txt");
        this->x = 0;
        this->y = 0;
    }
    void Dibujar()
    {
        string linea;
        move(this->y, this->x);
        while (getline(archivo, linea))
        {
            int y = getcury(stdscr);
            mvaddstr(y + 1, this->x, linea.c_str());
        }
        archivo.clear();
        archivo.seekg(0);
    }
    ~Dibujo()
    {
        archivo.close();
    }
};