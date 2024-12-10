#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "admin.h"

Admin::Admin(std::string email, std::string pssw, int curso, TipoU tipo): Usuario(email, pssw, curso, tipo) {}

std::list<Usuario> Admin::getUsuarios()
{

    std::list<Usuario> u;

    std::ifstream file("data/usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);
        
        std::string pssw = dato;
        std::getline(file, dato);
        
        int curso = std::stoi(dato);
        std::getline(file, dato);
        
        TipoU tipo = TipoU::Estudiante;

        if(dato == "Admin")
        {

            tipo = TipoU::Admin;

        }
        else if(dato == "Profesor")
        {

            tipo = TipoU::Profesor;

        }

        Usuario usuario(email, pssw, curso, tipo);

        u.push_back(usuario);

    }

    return u;

}

std::list<Estudiante> Admin::getEstudiantes()
{

    std::list<Estudiante> e;

    std::ifstream file("data/usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);

        std::string pssw = dato;
        std::getline(file, dato);

        int curso = std::stoi(dato);
        std::getline(file, dato);
        
        TipoU tipo;

        if(dato == "Estudiante")
        {

            tipo = TipoU::Estudiante;

        }

        if(tipo == TipoU::Estudiante)
        {

            Estudiante estudiante(email, pssw, curso, tipo);

            e.push_back(estudiante);

        }

    }

    return e;

}

std::list<Profesor> Admin::getProfesores()
{

    std::list<Profesor> p;

    std::ifstream file("data/usuarios.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string email = dato;
        std::getline(file, dato);

        std::string pssw = dato;
        std::getline(file, dato);

        int curso = std::stoi(dato);
        std::getline(file, dato);

        TipoU tipo;

        if(dato == "Profesor")
        {

            tipo = TipoU::Profesor;

        }

        if(tipo == TipoU::Profesor)
        {

            Profesor profesor(email, pssw, curso, tipo);

            p.push_back(profesor);

        }

    }

    return p;

}

std::list<Plan> Admin::getPlanes()
{

    std::list<Plan> p;

    std::ifstream file("data/planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        int id = std::stoi(dato);
        std::getline(file, dato);

        int duracion = std::stoi(dato);
        std::getline(file, dato);

        std::string universidad = dato;
        std::getline(file, dato);

        TipoP tipo = TipoP::convalidacion;

        if(dato == "Intercambio")
        {

            tipo = TipoP::intercambio;

        }

        Plan plan(id, duracion, universidad, tipo);

        p.push_back(plan);

    }

    return p;

}

std::list<Convalidacion> Admin::getConvalidaciones()
{

    std::list<Convalidacion> c;

    std::ifstream file("data/planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string grado = dato;
        std::getline(file, dato);

        int id = std::stoi(dato);
        std::getline(file, dato);

        int duracion = std::stoi(dato);
        std::getline(file, dato);

        std::string universidad = dato;
        std::getline(file, dato);

        TipoP tipo;

        if(dato == "Convalidacion")
        {

            tipo = TipoP::convalidacion;

        }

        else
        {

            continue;

        }

        if(tipo == TipoP::convalidacion)
        {

            Convalidacion convalidacion(grado, id, duracion, universidad, tipo);

            c.push_back(convalidacion);

        }

    }

    return c;

}

std::list<Intercambio> Admin::getIntercambios()
{

    std::list<Intercambio> i;

    std::ifstream file("data/planes.txt");
    std::string dato;

    while(std::getline(file, dato))
    {

        std::string area = dato;
        std::getline(file, dato);

        int id = std::stoi(dato);
        std::getline(file, dato);

        int duracion = std::stoi(dato);
        std::getline(file, dato);

        std::string universidad = dato;
        std::getline(file, dato);

        TipoP tipo;

        if(dato == "Intercambio")
        {

            tipo = TipoP::intercambio;

        }

        if(tipo == TipoP::intercambio)
        {

            Intercambio intercambio(area, id, duracion, universidad, tipo);

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

bool Admin::createUsuario(std::string email, std::string pssw, int curso, TipoU tipo)
{

    Usuario u(email, pssw, curso, tipo);

    std::ofstream file("data/usuarios.txt", std::ios::app);

    if(file.is_open())
    {

        file << u.getEmail() << std::endl;
        file << u.getPssw() << std::endl;
        file << u.getCurso() << std::endl;
        file << static_cast<int>(u.getTipo()) << std::endl;
        file << std::endl;

        file.close();

        return true;

    }

    return false;

}

bool Admin::deleteUsuario(Usuario usuario)
{

    std::list<Usuario> u = getUsuarios();

    u.remove_if([&usuario](Usuario& u) {return u.getEmail() == usuario.getEmail();});

    std::ofstream file("data/usuarios.txt");

    if(file.is_open())
    {

        for(auto it = u.begin(); it != u.end(); it++)
        {

            file << it->getEmail() << std::endl;
            file << it->getPssw() << std::endl;
            file << it->getCurso() << std::endl;
            file << static_cast<int>(it->getTipo()) << std::endl;
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

bool Admin::createPlan(int id, int duracion, std::string universidad, TipoP tipo)
{

    Plan p(id, duracion, universidad, tipo);

    std::ofstream file("data/planes.txt", std::ios::app);

    if(file.is_open())
    {

        file << p.getId() << std::endl;
        file << p.getDuracion() << std::endl;
        file << p.getUniversidad() << std::endl;
        file << static_cast<int>(p.getTipo()) << std::endl;
        file << std::endl;

        file.close();

        return true;

    }

    return false;

}

bool Admin::deletePlan(Plan plan)
{

    std::list<Plan> p = getPlanes();

    p.remove_if([&plan](Plan& p) {return p.getId() == plan.getId();});

    std::ofstream file("data/planes.txt");

    if(file.is_open())
    {

        for(auto it = p.begin(); it != p.end(); it++)
        {

            file << it->getId() << std::endl;
            file << it->getDuracion() << std::endl;
            file << it->getUniversidad() << std::endl;
            file << static_cast<int>(it->getTipo()) << std::endl;
            file << std::endl;

        }

        file.close();

        return true;

    }

    return false;

}