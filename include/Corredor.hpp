#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

#include <iostream>

using namespace std;

class Corredor : public Dibujo, public Actualizable
{
private:
public:
    Corredor() : Dibujo("Corredor") {}
    Corredor(int x, int y) : Dibujo(x, y, "Corredor") {}
    void Actualizar()
    {
        this->x = x;
        this->y = y;
    }
    void CarrilArriba()
    {
        this->y -= 15;
    }
    void CarrilAbajo()
    {
        this->y += 15;
    }
    void SaltarRampa(int z)
    {
        this->y = z + 8;
    }
    ~Corredor() {}
};