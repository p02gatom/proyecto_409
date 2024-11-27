#ifndef ADMIN_H 
#define ADMIN_H

#include <string>
#include <list>
#include "../usuario/usuario.h"
#include "../estudiante/estudiante.h"
#include "../profesor/profesor.h"
#include "../plan/plan.h"
#include "../convalidacion/convalidacion.h"
#include "../intercambio/intercambio.h" 

class Admin: public Usuario
{

    public:

        Admin
        (

            std::string email,
            std::string pssw,
            int curso,
            TipoU tipo

        );

    std::list<Usuario> getUsuarios();
    std::list<Estudiante> getEstudiantes();
    std::list<Profesor> getProfesores();
    std::list<Plan> getPlanes();
    std::list<Convalidacion> getConvalidaciones();
    std::list<Intercambio> getIntercambios();

    bool modifyUsuario(Usuario usuario);
    bool createUsuario(std::string email, std::string pssw, int curso, TipoU tipo);
    bool deleteUsuario(Usuario usuario);

    bool modifyPlan(Plan plan);
    bool createPlan(int id, int duracion, std::string universidad, TipoP tipo);
    bool deletePlan(Plan plan);

};

#endif