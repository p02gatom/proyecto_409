#include <string>
#include "intercambio.h"

Intercambio::Intercambio(std::string area, int id, int duracion, std::string universidad, TipoP tipo): Plan(id, duracion, universidad, tipo) 
{

    area_ = area;

}