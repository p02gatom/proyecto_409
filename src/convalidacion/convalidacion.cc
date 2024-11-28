#include <string>
#include <list>
#include "convalidacion.h"

Convalidacion::Convalidacion(int id, int duracion, std::string universidad, TipoP tipo, std::list<Asignatura> asignaturas, Grado::grado grado): Plan(id, duracion, universidad, tipo) 
{

    asignaturas_ = asignaturas;
    grado_ = grado;

}

std::list<Convalidacion> Convalidacion::filterByCareer(Grado::Grado grado) 
{

    std::list<Convalidacion> convalidaciones;

    for (Convalidacion convalidacion : convalidaciones) 
    {

        if (convalidacion.getGrado() == grado) 
        {

            convalidaciones.push_back(convalidacion);

        }

    }

    return convalidaciones;

}