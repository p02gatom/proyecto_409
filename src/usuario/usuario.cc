#include <string>
#include "usuario.h"

Usuario::Usuario(std::string email, std::string pssw, int curso, TipoU tipo)
{

    email_ = email;
    pssw_ = pssw;
    curso_ = curso;
    tipo_ = tipo;

}

bool Usuario::signIn(std::string email, std::string pssw)
{

    const std::string emailAdmin = "admin@uco.es";
    const std::string psswAdmin = "adminPSSW";
    const std::string emailValidator = "@uco.es";

    if(email.size() >= emailValidator.size())
    {

        if(email.substr(email.size() - emailValidator.size()) != emailValidator)
        {

            return false;
            
        }

    }

    else
    {

        return false;

    }

    if(email == emailAdmin && pssw == psswAdmin) 
    {

        setTipo(TipoU::Admin);
        return true;

    }

    else if(email == email_ && pssw == pssw_)
    {

        return true;

    }

    return false;

}

void Usuario::seeInscrip(){}