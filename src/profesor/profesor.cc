#include <string>
#include "profesor.h"

Profesor::Profesor(std::string email, std::string pssw, int curso, TipoU tipo): Usuario(email, pssw, curso, tipo) {}