#include "videogame.h"
#include<algorithm>
#include <fstream>


VideoGame::VideoGame(){}

void VideoGame::setUserName(const std::string &u){
    userName = u;
}

string VideoGame::getUserName(){
    return userName;
}

void VideoGame::addCivi(){
    Civilizacion civ;
    cin >> civ;

    civi.push_back(civ);
}

void VideoGame::showCivi(){
    cout << std::left;
    cout << std::setw(20) << "CIVILIZACION";
    cout << std::setw(20) << "POSICION X";
    cout << std::setw(20) << "POSICION Y";
    cout << std::setw(20) << "PUNTUACION";
    cout << std::endl;

    for(size_t i = 0; i < civi.size(); i++){
        Civilizacion &civ = civi[i];
        cout << civ;
    }

}

void VideoGame::insertCivi(const size_t pos, const Civilizacion &c){
    civi.insert(civi.begin()+pos, c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
    civi = vector<Civilizacion>(n, c);
}

void VideoGame::getFirst(){
    cout << std::left;
    cout << std::setw(20) << "CIVILIZACION";
    cout << std::setw(20) << "POSICION X";
    cout << std::setw(20) << "POSICION Y";
    cout << std::setw(20) << "PUNTUACION";
    cout << std::endl;
    cout << civi.front();
}

void VideoGame::getLast(){
    cout << std::left;
    cout << std::setw(20) << "CIVILIZACION";
    cout << std::setw(20) << "POSICION X";
    cout << std::setw(20) << "POSICION Y";
    cout << std::setw(20) << "PUNTUACION";
    cout << std::endl;
    cout << civi.back();
}

size_t VideoGame::tam(){
    return civi.size();
}

Civilizacion* VideoGame::buscar(const Civilizacion &c){
    auto it = find(civi.begin(), civi.end(), c);

    if (it == civi.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void VideoGame::eliminar(Civilizacion *pos){
    Civilizacion c = *pos;

    for(size_t i =0; i < civi.size(); i++){
        Civilizacion &civ = civi[i];
        if (civ == c){
            civi.erase(civi.begin()+i);
        }

    }

}

void VideoGame::modificar(Civilizacion *civv, size_t option){
    Civilizacion c = *civv;
    string myStr;
    float data;
    if (option == 1){
        for(size_t i =0; i < civi.size(); i++){
            Civilizacion &civ = civi[i];
            if (civ == c){
                cout << "INGRESE NUEVO NOMBRE: ";
                fflush(stdin);
                getline(cin, myStr);
                c.setName(myStr);
                civi.erase(civi.begin()+i);
                civi.insert(civi.begin()+i, c);

            }
        }
    }
    else if (option == 2){
        for(size_t i =0; i < civi.size(); i++){
            Civilizacion &civ = civi[i];
            if (civ == c){
                cout << "INGRESE NUEVA POSICION EN X: ";
                cin >> data;
                cin.ignore();
                c.setXPosition(data);
                civi.erase(civi.begin()+i);
                civi.insert(civi.begin()+i, c);

            }
        }

    }
    else if (option == 3){
        for(size_t i =0; i < civi.size(); i++){
            Civilizacion &civ = civi[i];
            if (civ == c){
                cout << "INGRESE NUEVA POSICION EN Y: ";
                cin >> data;
                cin.ignore();
                c.setYPosition(data);
                civi.erase(civi.begin()+i);
                civi.insert(civi.begin()+i, c);

            }
        }
    }
    else if (option == 4){
            for(size_t i =0; i < civi.size(); i++){
            Civilizacion &civ = civi[i];
            if (civ == c){
                cout << "INGRESE NUEVA POSICION EN X: ";
                cin >> data;
                cin.ignore();
                c.setPuntation(data);
                civi.erase(civi.begin()+i);
                civi.insert(civi.begin()+i, c);

            }
        }

    }
}

void VideoGame::ordenarNombre(){
    sort(civi.begin(), civi.end(),[]( Civilizacion c1,  Civilizacion c2){return c1.getName() < c2.getName();});
}

void VideoGame::ordenarX(){
    sort(civi.begin(), civi.end(),[]( Civilizacion c1,  Civilizacion c2){return c1.getXPosition() < c2.getXPosition();});
}

void VideoGame::ordenarY(){
    sort(civi.begin(), civi.end(),[]( Civilizacion c1,  Civilizacion c2){return c1.getYPosition() < c2.getYPosition();});
}

void VideoGame::ordenarPuntuacion(){
    sort(civi.begin(), civi.end(),[]( Civilizacion c1,  Civilizacion c2){return c1.getPuntation() > c2.getPuntation();});
}

void VideoGame::menuALdeano(Civilizacion &c){
    Aldeano aldi;
    int opa;
    string myStr;

                do{
                    system("cls");
                    cout << std::left;
                    cout << std::setw(20) << "CIVILIZACION";
                    cout << std::setw(20) << "POSICION X";
                    cout << std::setw(20) << "POSICION Y";
                    cout << std::setw(20) << "PUNTUACION";
                    cout << std::endl;
                    cout << c << endl << endl;

                    cout << "MENU ALDEANOS: " << endl;
                    cout << "1.- AGREGAR ALDEANO" << endl;
                    cout << "2.- ELIMINAR ALDEANO" << endl;
                    cout << "3.- CLASIFICAR ALDEANOS" << endl;
                    cout << "4.- BUSCAR ALDEANO" << endl;
                    cout << "5.- MODIFICAR ALDEANO" << endl;
                    cout << "6.- MOSTRAR ALDEANOS" << endl;
                    cout << "0.- salir" << endl;
                    cin >> opa;
                    cin.ignore();

                    if(opa == 1){
                        system("cls");

                        cout << "AGREGAR ALDEANO POR: " << endl;
                        cout << "1.- AL FRENTE" << endl;
                        cout << "2.- AL FINAL" << endl;
                        cin >> opa;
                        cin.ignore();
                        if(opa == 1){
                                    cin >> aldi;
                                    c.setPuntation(c.getPuntation()+100);
                                    c.addAldeanofront(aldi);
                                }

                        else if (opa == 2){

                                    cin >> aldi;
                                    c.setPuntation(c.getPuntation()+100);
                                    c.addAldeanofront(aldi);



                        }
                        system("pause");
                        }

                    else if(opa == 2){ //PENDIENTE SALUD
                        system("cls");
                        cout << "ELIMINAR POR:" << endl;
                        cout << "1.- NOMBRE" << endl;
                        cout << "2.- SALUD MENOR A X" << endl;
                        cout << "3.- MAYORES O IGUALES A 60 AÑOS" << endl;

                        cin >> opa;
                        cin.ignore();

                        if (opa == 1){
                            system("cls");
                            cout << "INTRODUZCA EL NOMBRE" << endl;
                            fflush(stdin);
                            getline(cin, myStr);
                            c.eliminarNombre(myStr);

                        }
                        else if (opa == 2){
                            system("cls");
                            int salud;
                            int tam = c.sizeList();
                            cout << "INTRODUZCA LA SALUD" << endl;
                            cin >> salud;
                            cin.ignore();
                            c.eliminarSalud(salud);
                            for (int i = tam; i > c.sizeList(); i--){
                                c.setPuntation(c.getPuntation()-100);
                            }
                        }
                        else if (opa == 3){
                            system("cls");
                            int tam = c.sizeList();
                            cout << "ELIMNADOS" << endl;
                            c.eliminarEdad();
                            for (int i = tam; i > c.sizeList(); i--){
                                c.setPuntation(c.getPuntation()-100);
                            }
                        }
                    }

                    else if (opa == 3){
                        system("cls");
                        cout << "ORDENAR POR: " << endl;
                        cout << "1.- NOMBRE (ASCENDENTE)" << endl;
                        cout << "2.- EDAD (DESCENDENTE)" << endl;
                        cout << "3.- SALUD (DESCENDENTE)" << endl;
                        cin >> opa;
                        cin.ignore();

                        if (opa == 1){
                            c.ordenarNombre();
                        }
                        else if (opa == 2){
                            c.ordenarEdad();
                        }
                        else if (opa == 3){
                            c.ordenarSalud();
                        }

                    }

                    else if(opa == 4){
                        system("cls");

                        cout << "NOMBRE: ";
                        fflush(stdin);
                        getline(cin, myStr);

                        c.buscarAldeano(myStr);

                        system("pause");


                    }

                   else if (opa == 5){
                        system("cls");
                        c.modificarAldeano();
                   }

                    else if(opa == 6){
                        system("cls");
                        c.printAldeanos();
                        system("pause");

                    }

                    else if(opa == 0){
                        system("cls");
                    }

                } while(opa != 0);

            cout<<endl;

}

void VideoGame::guardar(){

    if(userName == "NO EXISTE USUARIO"){

        cout << "NO HAY USUARIOS, IMPOSIBLE GUARDAR" << endl;

    }

    else{

        if (civi.size() == 0){

            cout << "NO HAY CIVILIZACIONES PARA GUARDAR" << endl;

        }

        string nArchivo = userName + ".txt";
        ofstream archivo(nArchivo);

        if (archivo.is_open()){


            for (size_t i = 0; i < civi.size(); i++){

                Civilizacion &ccc = civi[i];

                archivo << ccc.getName() << endl;
                archivo << to_string(ccc.getXPosition()) << endl;
                archivo << to_string(ccc.getYPosition()) << endl;
                archivo << to_string(ccc.getXPosition()) << endl;
                civi[i].guardarCivilizacion(userName);

            }

            cout << "GUARDADO EXITOSO" << endl;


        }

        archivo.close();

    }

}

void VideoGame::cargarPartida(){

    if(userName == "NO EXISTE USUARIO"){

        cout << "NO HAY USUARIOS, IMPOSIBLE CARGAR PARTIDA" << endl;

    }

    string nArchivo = userName + ".txt";
    ifstream archivo(nArchivo);
    if (archivo.is_open()){

        civi.clear();
        string data;
        Civilizacion ccc;

        while(true){

            getline(archivo, data);
            if (archivo.eof()){
                break;
            }
            ccc.setName(data);

            getline(archivo, data);
            ccc.setXPosition(stoi(data));

            getline(archivo, data);
            ccc.setYPosition(stoi(data));

            getline(archivo, data);
            ccc.setPuntation(stoi(data));

            civi.push_back(ccc);

        }

        for (size_t i = 0; i < civi.size(); i++){

            string nombreArchivoAld = userName + civi[i].getName() + ".txt";

            ifstream archivoAld(nombreArchivoAld);

            if(archivoAld.is_open()){

                civi[i].limpiarAld();

                Aldeano aaa;

                while(true){

                    getline(archivoAld, data);
                    if(archivoAld.eof()){
                        break;
                    }
                    aaa.setName(data);

                    getline(archivoAld, data);
                    aaa.setAge(stoi(data));

                    getline(archivoAld, data);
                    aaa.setGender(data);

                    getline(archivoAld, data);
                    aaa.setHealth(stoi(data));

                    civi[i].addAldeanofront(aaa);

                }

            }

        }
        cout << "PARTIDA ENCONTRADA, CARGADA CON EXITO" << endl;


    }

    archivo.close();

}
