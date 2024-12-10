#include <string>
#include <list>
#include "convalidacion.h"


Convalidacion::Convalidacion(std::string grado, int id, int duracion, std::string universidad, TipoP tipo, std::list<Asignatura> asignaturas): Plan(id, duracion, universidad, tipo) 
{

    asignaturas_ = asignaturas;
    grado_ = grado;

}

std::list<Convalidacion> Convalidacion::filterByCareer(std::list<Convalidacion> convalidaciones, std::string grado) 
{

    std::list<Convalidacion> filtradas;

    for (Convalidacion convalidacion : convalidaciones) 
    {

        if (convalidacion.getGrado() == grado) 
        {

            filtradas.push_back(convalidacion);

        }

    }

    return filtradas;

}