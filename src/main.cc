#include <string>
#include <list>
#include <iostream>
#include "funciones.h"

int main()
{

    std::list<Usuario> usuarios = admin.getUsuarios();

    while(true)
    {

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

                            std::cout << "\nBienvenido administrador." << std::endl;
                            menuAdmin();
                            break;

                        case TipoU::Estudiante:

                            std::cout << "\nBienvenido estudiante." << std::endl;
                            menuEstudiante();
                            break;

                        case TipoU::Profesor:
                            
                            std::cout << "\nBienvenido profesor." << std::endl;
                            menuProfesor();
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

    return 0;

}