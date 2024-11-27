#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include "../usuario/usuario.h"

class Estudiante: public Usuario
{

    public:

        Estudiante
        (

            std::string email,
            std::string pssw,
            int curso,
            TipoU tipo

        );

};

#endif