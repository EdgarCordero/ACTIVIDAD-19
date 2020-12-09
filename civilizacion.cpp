#include "civilizacion.h"
#include <fstream>

using namespace std;

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const Civilizacion& c) : name(c.name), xPosition(c.xPosition), yPosition(c.yPosition), puntation(c.puntation){}

void Civilizacion::setName(const string &n){
    name = n;
}

void Civilizacion::setXPosition(const float &x){
    xPosition = x;
}

void Civilizacion::setYPosition(const float &y){
    yPosition = y;
}

void Civilizacion::setPuntation(const float &p){
    puntation = p;
}

string Civilizacion::getName(){
    return name;
}

float Civilizacion::getXPosition(){
    return xPosition;
}

float Civilizacion::getYPosition(){
    return yPosition;
}

float Civilizacion::getPuntation(){
    return puntation;
}


///ALDEANO


void Civilizacion::printAldeanos(){

    cout << std::left;
    cout << std::setw(20) << "NOMBRE";
    cout << std::setw(20) << "EDAD";
    cout << std::setw(20) << "GENERO";
    cout << std::setw(20) << "SALUD";
    cout << std::endl;
    for(auto it = ald.begin(); it != ald.end(); it++){

        cout << *it << endl;

    }
}

void Civilizacion::addAldeanofront(const Aldeano &a){
    ald.push_front(a);
}

void Civilizacion::addAldeanoback(const Aldeano &a){
    ald.push_back(a);
}

void Civilizacion::eliminarNombre(const string &name){
    for(auto it = ald.begin(); it != ald.end(); it++){
        Aldeano &a = *it;

        if(name == a.getName()){
            ald.erase(it);
            setPuntation(getPuntation()-100);
            break;
        }

    }
}

bool comparador(const Aldeano &a){
    return a.getAge() >= 60;
}

void Civilizacion::eliminarEdad(){
    ald.remove_if(comparador);
}



void Civilizacion::eliminarSalud(int salud)
{
    ald.remove_if([salud](const Aldeano &j){ return j.getHealth() < salud;});
}

void Civilizacion::ordenarNombre(){
    ald.sort();
}

bool comparadorEdad(const Aldeano &j1, const Aldeano &j2){
    return j1.getAge() > j2.getAge();
}

void Civilizacion::ordenarEdad(){
    ald.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud(){
    ald.sort([](const Aldeano &j1, const Aldeano &j2){return j1.getHealth() > j2.getHealth();});
}

int Civilizacion::sizeList(){
    return ald.size();
}


void Civilizacion::buscarAldeano(const string &name){
    for(auto it = ald.begin(); it != ald.end(); it++){
        Aldeano &a = *it;

        if(name == a.getName()){
            cout << std::left;
            cout << std::setw(20) << "NOMBRE";
            cout << std::setw(20) << "EDAD";
            cout << std::setw(20) << "GENERO";
            cout << std::setw(20) << "SALUD";
            cout << std::endl;
            cout << *it << endl;
            break;
        }
    }
}

void Civilizacion::modificarAldeano(){
        string data, nombre;
        int op;
        int iData;
        cout << "Nombre: ";
        fflush(stdin);
        getline(cin, nombre);

        for(auto it = ald.begin(); it != ald.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getName()){
            cout << std::left;
            cout << std::setw(20) << "NOMBRE";
            cout << std::setw(20) << "EDAD";
            cout << std::setw(20) << "GENERO";
            cout << std::setw(20) << "SALUD";
            cout << std::endl;
            cout << *it << endl << endl;

            cout << "MODIFICAR: " << endl;
            cout << "1.- NOMBRE" << endl;
            cout << "2.- EDAD " << endl;
            cout << "3.- GENERO" << endl;
            cout << "4.- SALUD" << endl;
            cin >> op;
            cin.ignore();

            switch(op){
                case 1:
                    cout << "NOMBRE NUEVO: ";
                    fflush(stdin);
                    getline(cin, data);
                    it->setName(data);
                    break;
                case 2:
                    cout << "EDAD NUEVA: ";
                    cin >> iData;
                    cin.ignore();
                    it->setAge(iData);
                    break;
                case 3:
                    cout << "GENERO NUEVO: ";
                    fflush(stdin);
                    getline(cin, data);
                    it->setGender(data);
                    break;
                case 4:
                    cout << "SALUD NUEVA: ";
                    cin >> iData;
                    cin.ignore();
                    it->setHealth(iData);
                    break;
            }


        }
    }
}

void Civilizacion::guardarCivilizacion(const string &n){
    if(ald.size() > 0){

    string archivoCivi = n + name + ".txt";
    ofstream archivoAldCiv(archivoCivi);

    for (auto it = ald.begin(); it != ald.end(); it++){

        Aldeano &aaa = *it;

        archivoAldCiv << aaa.getName() << endl;
        archivoAldCiv << to_string(aaa.getAge()) << endl;
        archivoAldCiv << aaa.getGender() << endl;
        archivoAldCiv << to_string(aaa.getHealth()) << endl;

    }
    archivoAldCiv.close();

    }
}

void Civilizacion::limpiarAld(){
    ald.clear();
}
