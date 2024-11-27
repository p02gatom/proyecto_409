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

    list<Usuario> getUsuarios();
    list<Estudiante> getEstudiantes();
    list<Profesor> getProfesores();
    list<Plan> getPlanes();
    list<Convalidacion> getConvalidaciones();
    list<Intercambio> getIntercambios();

    bool modifyUsuario(Usuario usuario);
    bool createUsuario(email, pssw, curso, tipo);
    bool deleteUsuario(Usuario usuario);

    bool modifyPlan(Plan plan);
    bool createPlan(id, duracion, universidad, tipo);
    bool deletePlan(Plan plan);

};

#endif