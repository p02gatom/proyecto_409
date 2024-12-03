#include <string>
#include "asignatura.h"
#include "../grado/grado.h"

Asignatura::Asignatura(std::string codigo, std::string nombre, int curso, int creditos, Grado grado)
{

    codigo_ = codigo;
    nombre_ = nombre;
    curso_ = curso;
    creditos_ = creditos;
    grado_ = grado;

}