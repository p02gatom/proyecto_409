#ifndef FUNCIONES_H
#define FUNCIONES_H

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

extern Admin admin;

void menuEstudiante(const Usuario& u);
void consultaPlanes(const Usuario& u);
void menuAdmin();
void menuProfesor();
bool inscripcion(int id, Usuario u);
bool estaInscrito(Usuario u);

#endif