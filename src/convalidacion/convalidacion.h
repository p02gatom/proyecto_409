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
        std::string grado_;

    public:

        Convalidacion
        (

            std::string grado,
            int id,
            int duracion,
            std::string universidad,
            TipoP tipo = TipoP::convalidacion,
            std::list<Asignatura> asignaturas = {}
            

        );

        inline std::list<Asignatura> getAsignaturas() {return asignaturas_;}
        inline std::string getGrado() {return grado_;}

        inline void setAsignaturas(std::list<Asignatura> asignaturas) {asignaturas_ = asignaturas;}
        inline void setGrado(std::string grado) {grado_ = grado;}

        std::list<Convalidacion> filterByCareer(std::list<Convalidacion> convalidaciones, std::string grado);

};  

#endif