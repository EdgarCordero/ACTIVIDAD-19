#include <iostream>
#include "videogame.h"

using namespace std;

int main()
{
    string myStr;
    size_t op;
    size_t opa;
    VideoGame game;
    Aldeano aldeano;
    Civilizacion cc;



    do{
        system("cls");
        cout << "SID MEIER'S CIVILIZATIONS" << endl << endl;
        cout << "USUARIO: "<<game.getUserName() << endl << endl;

        cout << "<<< MENU >>>" << endl;
        cout << "1.- NOMBRE DE USUARIO" << endl;
        cout << "2.- AGREGAR CIVILIZACION" << endl;
        cout << "3.- INSERTAR CIVILIZACION" << endl;
        cout << "4.- CREAR CIVILIZACIONES" << endl;
        cout << "5.- PRIMERA CIVILIZACION" << endl;
        cout << "6.- ULTIMA CIVILIZACION" << endl;
        cout << "7.- ORDENAR" << endl;
        cout << "8.- ELIMINAR CIVILIZACION" << endl;
        cout << "9.- BUSCAR" << endl;
        cout << "10.- MODIFICAR" << endl;
        cout << "11.- RESUMEN" << endl;
        cout << "12.- GUARDAR" << endl;
        cout << "13.- CARGAR" << endl;
        cout << "0.- salir" << endl;

        cin >> op;


            if (op == 1){
                system("cls");
                cout << "INGRESE NOMBRE DE USUARIO: ";
                fflush(stdin);
                getline(cin, myStr);

                game.setUserName(myStr);
            }

            else if (op == 2){
                system("cls");
                game.addCivi();
            }

            else if (op == 3){
                system("cls");
                size_t pos;
                Civilizacion c;
                cin >> c;
                cout << "INGRESE LA POSICION: ";
                cin >> pos;
                if(pos < game.tam()){
                    game.insertCivi(pos, c);
                }else{
                    cout << "POSICION NO VALIDA" << endl;
                }
                system("pause");
            }

            else if(op == 4){
                system("cls");
                size_t n;
                Civilizacion c;
                cin >> c;
                cout << "INGRESE N: ";
                cin >> n;
                cin.ignore();
                game.inicializar(c, n);
            }

            else if(op == 5){
                system("cls");
                game.getFirst();
                system("pause");
            }

            else if(op == 6){
                system("cls");
                game.getLast();
                system("pause");
            }

            else if(op == 7){
                system("cls");
                cout << "COMO DESEA ORDENAR? (se ordenara de forma descendente)" << endl;
                cout << "1.- NOMBRE" << endl;
                cout << "2.- POSICION EN X" << endl;
                cout << "3.- POSICION EN Y " << endl;
                cout << "4.- PUNTUACION" << endl;
                cin >> op;
                cin.ignore();

                if (op == 1){
                    game.ordenarNombre();
                }
                else if (op == 2){
                    game.ordenarX();
                }
                else if (op == 3){
                    game.ordenarY();
                }
                else if (op == 4){
                    game.ordenarPuntuacion();
                }
                system("pause");
            }

            else if (op == 8){
                system("cls");
                size_t opp;
                Civilizacion c;
                cout << "NOMBRE: ";
                fflush(stdin);
                getline(cin, myStr);
                c.setName(myStr);

                Civilizacion *ptr = game.buscar(c);

                if (ptr == nullptr){
                system("cls");
                cout << "LA CIVILIZACION " << myStr << " NO SE ENCUENTRA" << endl;
            }
            else {
                system("cls");
                cout << "LA CIVILIZACION ENCONTRADA ES: " << endl << endl;
                system("cls");
                cout << std::left;
                cout << std::setw(20) << "CIVILIZACION";
                cout << std::setw(20) << "POSICION X";
                cout << std::setw(20) << "POSICION Y";
                cout << std::setw(20) << "PUNTUACION";
                cout << std::endl;
                cout << *ptr << endl;

                cout << "DESEA ELIMINAR LA CIVILIZACION? (1.-si; 2.-no): ";
                cin >> opp;
                cin.ignore();
                if(opp == 1){
                    game.eliminar(ptr);
                }



            }
            cout<<endl;

                system("pause");
            }

            else if (op == 9){
                system("cls");
                Civilizacion c;
                cout << "NOMBRE: ";
                fflush(stdin);
                getline(cin, myStr);
                c.setName(myStr);

                Civilizacion *ptr = game.buscar(c);

                if (ptr == nullptr){
                system("cls");
                cout << "LA CIVILIZACION " << myStr << " NO SE ENCUENTRA" << endl;
            }
            else {

                Civilizacion &c = *ptr;
                system("cls");

                game.menuALdeano(c);
            }
            cout<<endl;
                system("pause");
            }

            else if(op == 10){
                system("cls");
                size_t opp;
                Civilizacion c;
                cout << "NOMBRE: ";
                fflush(stdin);
                getline(cin, myStr);
                c.setName(myStr);

                Civilizacion *ptr = game.buscar(c);

                if (ptr == nullptr){
                system("cls");
                cout << "LA CIVILIZACION " << myStr << " NO SE ENCUENTRA" << endl;
            }
            else {
                system("cls");
                cout << "LA CIVILIZACION ENCONTRADA ES: " << endl << endl;
                system("cls");
                cout << std::left;
                cout << std::setw(20) << "CIVILIZACION";
                cout << std::setw(20) << "POSICION X";
                cout << std::setw(20) << "POSICION Y";
                cout << std::setw(20) << "PUNTUACION";
                cout << std::endl;
                cout << *ptr << endl;

                cout << "DESEA MODIFICAR LA CIVILIZACION? (1.-si; 2.-no): ";
                cin >> opp;
                cin.ignore();
                if(opp == 1){
                    system("cls");
                    cout << "QUE DESEAS MODIFICAR?"<< endl;
                    cout << "1.- NOMBRE CIVILIZACION" << endl;
                    cout << "2.- POSICION X" << endl;
                    cout << "3.- POSICION Y" << endl;
                    cout << "4.- PUNTUACION" << endl;
                    cin >> opp;
                    cin.ignore();
                    game.modificar(ptr, opp);
                }



            }
            cout<<endl;

                system("pause");

            }

            else if (op == 11){
                system("cls");
                game.showCivi();
                system("pause");
            }
            else if (op == 12){
                system("cls");
                game.guardar();
                system("pause");
            }
            else if (op == 13){
                system("cls");
                game.cargarPartida();
                system("pause");
            }

            else if (op == 0){
                system("cls");
            }



    }while(op != 0);


}
