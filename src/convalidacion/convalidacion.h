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

        inline std::string getGrado() {return grado_;}

        inline void setGrado(std::string grado) {grado_ = grado;}

        std::list<Convalidacion> filterByCareer(std::list<Convalidacion> convalidaciones, std::string grado);

        std::list<std::string> getAsignaturas();

};  

#endif