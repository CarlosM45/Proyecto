#include <iostream>
#include <string>
using namespace std;
class personaje
{
private:
    string color;
public:
    personaje(string color):color("rojo") {
        cout<<"controlando corredor..."<<endl;
    }
    ~personaje() {
        cout<<"regresar al menu..."<<endl;
    }
    void moto (){
        char mov;
        do
        {
            cout<<"Esperando instruccion..."<<endl;
        cin>>mov;
        switch (mov){
            case 'W':
            case 'w':
                cout<<"arriba"<<endl;
                break;
            case 'A':
            case 'a':
                cout<<"inclinar izquierda"<<endl;
                break;
            case 'S':
            case 's':
                cout<<"abajo"<<endl;
                break;
            case 'D':
            case 'd':
                cout<<"inclinar derecha"<<endl;
                break;
            case 'Z':
            case 'z':
                cout<<"acelerar"<<endl;
                break;
            case 'X':
            case 'x':
                cout<<"acelerar rapido"<<endl;
                break;
            case 'P':
            case 'p':
                cout<<"el juego esta en pausa"<<endl;
                break;
        }
        } while (mov!='P'||mov!='p');
    }
    void caer (){
        
    }
};