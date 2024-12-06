#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "usuario.h"

//prueba

Usuario::Usuario(std::string email, std::string pssw, int curso, TipoU tipo)
{

    email_ = email;
    pssw_ = pssw;
    curso_ = curso;
    tipo_ = tipo;

}

bool Usuario::signIn(std::string email, std::string pssw)
{
    const std::string emailValidator = "@uco.es";

    // Validar que el email termina con "@uco.es"
    if (email.size() < emailValidator.size() || email.substr(email.size() - emailValidator.size()) != emailValidator)
    {
        return false;
    }

    // Abrir el archivo
    std::ifstream file("data/usuarios.txt");
    if (!file.is_open())
    {
        std::cerr << "No se pudo abrir el archivo de usuarios." << std::endl;
        return false;
    }

    std::string fileEmail, filePssw, fileCurso, fileTipo;

    // Leer el archivo en bloques de 4 líneas
    while (std::getline(file, fileEmail))
    {
        if (!std::getline(file, filePssw) || 
            !std::getline(file, fileCurso) || 
            !std::getline(file, fileTipo))
        {
            std::cerr << "Formato incorrecto en el archivo de usuarios." << std::endl;
            return false;
        }

        // Comparar el email y la contraseña
        if (fileEmail == email && filePssw == pssw)
        {
            return true;
        }
    }

    std::cerr << "Email o contraseña incorrectos." << std::endl;
    return false;
}


void Usuario::seeInscrip(){}