#ifndef CONVALIDACION_H
#define CONVALIDACION_H

#include <string>
#include <list>
#include "../plan/plan.h"
#include "../asignatura/asignatura.h"
#include "../grado/grado.h"

class Convalidacion: public Plan
{

    private:

        std::list<Asignatura> asignaturas_;
        Grado grado_;

    public:

        Convalidacion
        (

            int id,
            int duracion,
            std::string universidad,
            TipoP tipo = TipoP::convalidacion,
            std::list<Asignatura> asignaturas = {},
            Grado grado = Grado()

        );

        inline std::list<Asignatura> getAsignaturas() {return asignaturas_;}
        inline Grado getGrado() {return grado_;}

        inline void setAsignaturas(std::list<Asignatura> asignaturas) {asignaturas_ = asignaturas;}
        inline void setGrado(Grado grado) {grado_ = grado;}

        std::list<Convalidacion> filterByCareer(Grado grado);

};  

#endif