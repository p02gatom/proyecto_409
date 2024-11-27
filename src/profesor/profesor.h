#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include "../usuario/usuario.h"

class Profesor: public Usuario
{

    public:

        Profesor
        (

            std::string email,
            std::string pssw,
            int curso,
            TipoU tipo

        );

};

#endif