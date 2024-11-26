#include <string>
#include "plan.h"

Plan::Plan(int id, int duracion, std::string universidad, TipoP tipo)
{

    id_ = id;
    duracion_ = duracion;
    universidad_ = universidad;
    tipo_ = tipo;

}

bool Plan::isRegistered(Usuario usuario) {}