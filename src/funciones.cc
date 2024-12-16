#include "funciones.h"
#include <string>
#include <list>
#include <iostream>

Admin admin("admin@uco.es", "admin", 0, TipoU::Admin);

void consultaPlanes()
{

    std::cout << "Planes de convalidación disponibles: \n" << std::endl;

    std::list<Convalidacion> planes = admin.getConvalidaciones();

    for(auto& p : planes)
    {

        std::cout << "Grado: " << p.getGrado() << std::endl;
        std::cout << "ID: " << p.getId() << std::endl;
        std::cout << "Duración: " << p.getDuracion() << std::endl;
        std::cout << "Universidad: " << p.getUniversidad() << std::endl;
        std::cout << std::endl;

    }

    std::cout << "Desea filtrar los planes por grado? (s/n)" << std::endl;
    std::string respuesta;
    std::cin >> respuesta;
    std::cout << std::endl;

    if(respuesta == "s" || respuesta == "S")
    {

        std::string grado;
        std::cout << "Introduzca el grado por el que desea filtrar: " << std::endl;
        std::cin >> grado;
        std::cout << std::endl;

        Convalidacion c("", 0, 0, "", TipoP::convalidacion);
        std::list<Convalidacion> planesFiltrados = c.filterByCareer(admin.getConvalidaciones(), grado);

        if(planesFiltrados.empty())
        {

            std::cout << "No se han encontrado planes de convalidación para el grado introducido." << std::endl;
            return;

        }

        for(auto& p : planesFiltrados)
        {

            std::cout << "Grado: " << p.getGrado() << std::endl;
            std::cout << "ID: " << p.getId() << std::endl;
            std::cout << "Duración: " << p.getDuracion() << std::endl;
            std::cout << "Universidad: " << p.getUniversidad() << std::endl;
            std::cout << std::endl;

        }

    }

}

void menuEstudiante()
{

    std::cout << "Presione la tecla correspondiente a la acción que desea realizar: \n" << std::endl;

    std::cout << "\t1. Ver planes de convalidación." << std::endl;
    std::cout << "\t2. Ver perfil." << std::endl;
    std::cout << "\t3. Cerrar sesión." << std::endl;
    std::cout << "\tPresione otra tecla para salir." << std::endl;
    std::cout << std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion)
    {

    case 1:

        consultaPlanes();

        break;
    
    case 2:

        std::cout << "Perfil del estudiante." << std::endl;
        break;

    case 3: 

        std::cout << "Sesión cerrada.\n" << std::endl;
        return;

        break;

    default:

        std::cout << "Saliendo del programa.\n" << std::endl;
        exit(EXIT_SUCCESS);

        break;

    }

}

void menuAdmin()
{

    std::cout << "No hay funciones de momento. Disculpe las molestias." << std::endl;
    return;

}

void menuProfesor()
{

    std::cout << "No hay funciones de momento. Disculpe las molestias." << std::endl;
    return;

}