#include <string>
#include <list>
#include <iostream>
#include "usuario/usuario.h"
#include "plan/plan.h"
#include "admin/admin.h"
#include "estudiante/estudiante.h"
#include "profesor/profesor.h"
#include "convalidacion/convalidacion.h"
#include "intercambio/intercambio.h"
#include "asignatura/asignatura.h"
#include "grado/grado.h"

Admin admin("admin@uco.es", "admin", 0, TipoU::Admin);

int main()
{

    std::list<Usuario> usuarios = admin.getUsuarios();
    Usuario user;

    std::string email;
    std::string pssw;

    std::cout << "Introduzca su email y contraseña para iniciar sesión: " << std::endl;
    std::cin >> email >> pssw;

    if(user.signIn(email, pssw))
    {

        for(auto& u : usuarios)
        {

            if(u.getEmail() == email && u.getPssw() == pssw)
            {

                user = u;

                switch (u.getTipo())
                {
                    
                    case TipoU::Admin:

                        std::cout << "Bienvenido administrador." << std::endl;
                        break;

                    case TipoU::Estudiante:

                        std::cout << "Bienvenido estudiante." << std::endl;
                        break;

                    case TipoU::Profesor:
                        
                        std::cout << "Bienvenido profesor." << std::endl;
                        break;
                        
                    default:

                        std::cout << "Tipo de usuario no válido." << std::endl;
                        exit(EXIT_FAILURE);

                }

                break;

            }

        }

    }

    else
    {

        std::cout << "Email o contraseña incorrectos." << std::endl;
        exit(EXIT_FAILURE);

    }

}