#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <string>
#include <list>
#include "../plan/plan.h"

class Intercambio: public Plan
{

    public:

        Intercambio
        (

            int id,
            int duracion,
            std::string universidad,
            TipoP tipo = TipoP::intercambio

        );


};

#endif