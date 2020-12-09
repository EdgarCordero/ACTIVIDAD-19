#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"

#include <vector>
#include <string>

class VideoGame
{
    private:
        std::string userName = "NO EXISTE USUARIO";
        vector<Civilizacion> civi;
        Civilizacion cc;

    public:
        VideoGame();

        void setUserName(const std::string &u);
        std::string getUserName();



        size_t tam();

        void addCivi();
        void insertCivi(const size_t pos, const Civilizacion &c);
        void insertCivi(Civilizacion *pos, const Civilizacion &c);
        void inicializar(const Civilizacion &c, size_t n);
        void getFirst();
        void getLast();
        Civilizacion* buscar(const Civilizacion &c);
        void eliminar(Civilizacion *pos);
        void modificar (Civilizacion *civv, size_t option);
        void ordenarNombre();
        void ordenarX();
        void ordenarY();
        void ordenarPuntuacion();
        void guardar();
        void cargarPartida();

        void menuALdeano(Civilizacion &c);

        void showCivi();

};

#endif // VIDEOGAME_H
