#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <string>
#include <list>
#include "../plan/plan.h"

class Intercambio: public Plan
{

    private:

        std::string area_;

    public:

        Intercambio
        (

            std::string area,
            int id,
            int duracion,
            std::string universidad,
            TipoP tipo = TipoP::intercambio

        );


};

#endif