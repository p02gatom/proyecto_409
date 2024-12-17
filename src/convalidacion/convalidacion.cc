#include <string>
#include <list>
#include <fstream>
#include <sstream>
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

std::list<std::string>  Convalidacion::getAsignaturas()
{

    std::list<std::string> asignaturas;
    std::ifstream archivo("data/asignaturas.txt");
    std::string dato;
    bool encontrado = false;

    if(archivo.is_open())
    {

        while(getline(archivo, dato))
        {

            if(dato == std::to_string(this->getId()))
            {

                encontrado = true;
                continue;

            }

            if(encontrado && !dato.empty() && isdigit(dato[0]))
            {

                break;

            }

            if(encontrado)
            {

                asignaturas.push_back(dato);

            }

        }

        archivo.close();

    }

    return asignaturas;

}