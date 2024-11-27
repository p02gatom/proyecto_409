#include <string>
#include <list>
#include <fstream>
#include "Admin.h"

list<Usuario> Admin::getUsuarios()
{

    list<Usuario> u;

    std::ifstream file("usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);
        std::string pssw = dato;
        std::getline(file, dato);
        int curso = std::stoi(dato);
        std::getline(file, dato);
        TipoU tipo = static_cast<TipoU>(std::stoi(dato));

        Usuario usuario(email, pssw, curso, tipo);

        u.push_back(usuario);

    }

    return u;

}

list<Estudiante> Admin::getEstudiantes()
{

    list<Estudiante> e;

    std:ifstream file("usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);
        std::string pssw = dato;
        std::getline(file, dato);
        int curso = std::stoi(dato);
        std::getline(file, dato);
        TipoU tipo = static_cast<TipoU>(std::stoi(dato));

        if(tipo == TipoU::Estudiante)
        {

            Estudiante estudiante(email, pssw, curso, tipo);

            e.push_back(estudiante);

        }

    }

    return e;

}

list<Profesor> Admin::getProfesores()
{

    list<Profesor> p;

    std::ifstream file("usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);
        std::string pssw = dato;
        std::getline(file, dato);
        int curso = std::stoi(dato);
        std::getline(file, dato);
        TipoU tipo = static_cast<TipoU>(std::stoi(dato));

        if(tipo == TipoU::Profesor)
        {

            Profesor profesor(email, pssw, curso, tipo);

            p.push_back(profesor);

        }

    }

    return p;

}

list<Plan> Admin::getPlanes()
{

    list<Plan> p;

    std::ifstream file("planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        int id = std::stoi(dato);
        std::getline(file, dato);
        int duracion = std::stoi(dato);
        std::getline(file, dato);
        std::string universidad = dato;
        std::getline(file, dato);
        TipoP tipo = static_cast<TipoP>(std::stoi(dato));

        Plan plan(id, duracion, universidad, tipo);

        p.push_back(plan);

    }

    return p;

}

list<Convalidacion> Admin::getConvalidaciones()
{

    list<Convalidacion> c;

    std::ifstream file("planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        int id = std::stoi(dato);
        std::getline(file, dato);
        int duracion = std::stoi(dato);
        std::getline(file, dato);
        std::string universidad = dato;
        std::getline(file, dato);
        TipoP tipo = static_cast<TipoP>(std::stoi(dato));

        if(tipo == TipoP::Convalidacion)
        {

            Convalidacion convalidacion(id, duracion, universidad, tipo);

            c.push_back(convalidacion);

        }

    }

    return c;

}

list<Intercambio> Admin::getIntercambios()
{

    list<Intercambio> i;

    std::ifstream file("planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        int id = std::stoi(dato);
        std::getline(file, dato);
        int duracion = std::stoi(dato);
        std::getline(file, dato);
        std::string universidad = dato;
        std::getline(file, dato);
        TipoP tipo = static_cast<TipoP>(std::stoi(dato));

        if(tipo == TipoP::Intercambio)
        {

            Intercambio intercambio(id, duracion, universidad, tipo);

            i.push_back(intercambio);

        }

    }

    return i;

}

bool Admin::modifyUsuario(Usuario usuario)
{

    std::list<Usuario> u = getUsuarios();

    for(auto it = u.begin(); it != u.end(); it++)
    {

        if(it->getEmail() == usuario.getEmail())
        {

            it->setPssw(usuario.getPssw());
            it->setCurso(usuario.getCurso());
            it->setTipo(usuario.getTipo());

            return true;

        }

    }

    return false;

}

bool Admin::createUsuario(email, pssw, curso, tipo)
{

    Usuario u(email, pssw, curso, tipo);

    std::ofstream file("usuarios.txt", std::ios::app);

    if(file.is_open())
    {

        file << u.getEmail() << std::endl;
        file << u.getPssw() << std::endl;
        file << u.getCurso() << std::endl;
        file << u.getTipo() << std::endl;
        file << std::endl;

        file.close();

        return true;

    }

    return false;

}

bool Admin::deleteUsuario(Usuario usuario)
{

    std::list<Usuario> u = getUsuarios();

    u.remove_if([&usuario](const Usuario& u) {return u.getEmail() == usuario.getEmail();});

    std::ofstream file("usuarios.txt");

    if(file.is_open())
    {

        for(auto it = u.begin(); it != u.end(); it++)
        {

            file << it->getEmail() << std::endl;
            file << it->getPssw() << std::endl;
            file << it->getCurso() << std::endl;
            file << it->getTipo() << std::endl;
            file << std::endl;

        }

        file.close();

        return true;

    }

    return false;

}

bool Admin::modifyPlan(Plan plan)
{

    std::list<Plan> p = getPlanes();

    for(auto it = p.begin(); it != p.end(); it++)
    {

        if(it->getId() == plan.getId())
        {

            it->setDuracion(plan.getDuracion());
            it->setUniversidad(plan.getUniversidad());
            it->setTipo(plan.getTipo());

            return true;

        }

    }

    return false;

}

bool Admin::createPlan(id, duracion, universidad, tipo)
{

    Plan p(id, duracion, universidad, tipo);

    std::ofstream file("planes.txt", std::ios::app);

    if(file.is_open())
    {

        file << p.getId() << std::endl;
        file << p.getDuracion() << std::endl;
        file << p.getUniversidad() << std::endl;
        file << p.getTipo() << std::endl;
        file << std::endl;

        file.close();

        return true;

    }

    return false;

}

bool Admin::deletePlan(Plan plan)
{

    std::list<Plan> p = getPlanes();

    p.remove_if([&plan](const Plan& p) {return p.getId() == plan.getId();});

    std::ofstream file("planes.txt");

    if(file.is_open())
    {

        for(auto it = p.begin(); it != p.end(); it++)
        {

            file << it->getId() << std::endl;
            file << it->getDuracion() << std::endl;
            file << it->getUniversidad() << std::endl;
            file << it->getTipo() << std::endl;
            file << std::endl;

        }

        file.close();

        return true;

    }

    return false;

}