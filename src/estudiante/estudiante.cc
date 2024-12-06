#include <string>
#include "estudiante.h"

Estudiante::Estudiante(std::string email, std::string pssw, int curso, TipoU tipo): Usuario(email, pssw, curso, tipo) {}