#include "funciones.h"
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>

Admin admin("admin@uco.es", "admin", 0, TipoU::Admin);

void consultaPlanes(const Usuario& u)
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

        //std::cout << "Planes filtrados: " << planesFiltrados.size() << std::endl;

        if(planesFiltrados.empty())
        {

            std::cout << "No se han encontrado planes de convalidación para el grado introducido." << std::endl;
            std::cout << "¿Desea intenetarlo de nuevo? (s/n)" << std::endl;
            std::cin >> respuesta;
            std::cout << std::endl;

            if(respuesta == "s" || respuesta == "S")
            {

                consultaPlanes(u);
                return;

            }

            else
            {

                std::cout << "Saliendo del programa.\n" << std::endl;
                exit(EXIT_SUCCESS);

            }

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

    std::cout << "Desea consultar las asignaturas de algún plan? (s/n)" << std::endl;
    std::cin >> respuesta;
    std::cout << std::endl;

    if(respuesta == "s" || respuesta == "S")
    {

        std::cout << "Introduzca el ID del plan del que desea consultar las asignaturas: " << std::endl;
        int id;
        std::cin >> id;
        std::cout << std::endl;

        for(auto& p : planes)
        {

            if(p.getId() == id)
            {

                std::list<std::string> asignaturas = p.getAsignaturas();

                for(auto& a : asignaturas)
                {

                    std::cout << a << std::endl;

                }

                std::cout << std::endl;

            }

        }

    }

    std::cout << "¿Desea inscribirse en algún plan de convalidación? (s/n)" << std::endl;
    std::cin >> respuesta;
    std::cout << std::endl;

    if(respuesta == "s" || respuesta == "S")
    {

        std::cout << "Introduzca el ID del plan de convalidación en el que desea inscribirse: " << std::endl;
        int id;
        std::cin >> id;
        std::cout << std::endl;

        if(inscripcion(id, u))
        {

            std::cout << "Inscripción realizada con éxito." << std::endl;

        }

        else
        {

            std::cout << "No se ha podido realizar la inscripción." << std::endl;

        }

    }

    std::cout << "¿Desea hacer algo más? (s/n)" << std::endl;
    std::cin >> respuesta;
    std::cout << std::endl;

    if(respuesta == "s" || respuesta == "S")
    {

        menuEstudiante(u);

    }

    else
    {

        std::cout << "Saliendo del programa.\n" << std::endl;
        exit(EXIT_SUCCESS);

    }

}

void menuEstudiante(const Usuario& u)
{

    std::cout << "Presione la tecla correspondiente a la acción que desea realizar: \n" << std::endl;

    std::cout << "\t1. Ver planes de convalidación." << std::endl;
    std::cout << "\t2. Ver perfil." << std::endl;
    std::cout << "\t3. Generar certificadi." << std::endl;
    std::cout << "\t4. Cerrar sesión." << std::endl;
    std::cout << "\tPresione otra tecla para salir." << std::endl;
    std::cout << std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion)
    {

    case 1:

        consultaPlanes(u);

        break;
    
    case 2:

        std::cout << "Perfil del estudiante." << std::endl;
        std::cout << "Funcionalidad no disponible." << std::endl;
        std::cout << std::endl;

        menuEstudiante(u);

        break;

    case 3:
    {

        Usuario us = u;

        std::string nombreCert = "certificado" + us.getEmail() + ".txt";
        std::ofstream cert(nombreCert);

        if(!cert)
        {

            std::cerr << "Error al crear el certificado." << std::endl;
            exit(0);

        }

        cert << "=======================================\n";
        cert << "      CERTIFICADO DE ASISTENCIA        \n";
        cert << "=======================================\n";
        cert << "Se certifica que el usuario " << us.getEmail() << " ha sido acepatado en el plan de convalidación correspondiente.";
        cert.close();

        std::cout << "Certificado '" << nombreCert <<"' generado con exito.\n" << std::endl;

        menuEstudiante(u);

        break;
    }   

    case 4: 

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

bool inscripcion(int id, Usuario u)
{

    if(estaInscrito(u))
    {

        std::cout << "Ya está inscrito en un plan de convalidación." << std::endl;
        return false;

    }

    std::list<Convalidacion> planes = admin.getConvalidaciones();

    for(auto& p : planes)
    {

        if(p.getId() == id)
        {

            std::ofstream file("data/inscripciones.txt", std::ios::app);

            if(file.is_open())
            {

                file << u.getEmail() << std::endl;
                file << p.getGrado() << ", "  << p.getId() << std::endl;

                file.close();

                return true;

            }


        }

    }

    return false;

}

bool estaInscrito(Usuario u)
{

    std::ifstream file("data/inscripciones.txt");

    if(file.is_open())
    {

        std::string line;

        while(std::getline(file, line))
        {

            if(line == u.getEmail())
            {

                return true;

            }

        }

    }

    return false;   

}