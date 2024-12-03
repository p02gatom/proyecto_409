#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include "../grado/grado.h"

class Asignatura
{

    private: 

        std::string codigo_, nombre_;
        int curso_, creditos_;
        Grado grado_;

    public:

        Asignatura
        (

            std::string codigo,
            std::string nombre,
            int curso,
            int creditos,
            Grado grado

        );

    inline std::string getCodigo() {return codigo_;}
    inline std::string getNombre() {return nombre_;}
    inline int getCurso() {return curso_;}
    inline int getCreditos() {return creditos_;}
    inline Grado getGrado() {return grado_;}

    inline void setCodigo(std::string codigo) {codigo_ = codigo;}
    inline void setNombre(std::string nombre) {nombre_ = nombre;}
    inline void setCurso(int curso) {curso_ = curso;}
    inline void setCreditos(int creditos) {creditos_ = creditos;}
    inline void setGrado(Grado grado) {grado_ = grado;}

};

#endif