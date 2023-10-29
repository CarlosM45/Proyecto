#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

#include <iostream>

using namespace std;

class Rampa : public Dibujo, public Actualizable
{
private:
public:
    Rampa() : Dibujo("Rampa") {}
    Rampa(int x, int y) : Dibujo(x, y, "Rampa") {}
    void Actualizar()
    {
        this->x = x;
    }
    void Avanzar()
    {
        this->x -= 1;
    }
    ~Rampa() {}
};