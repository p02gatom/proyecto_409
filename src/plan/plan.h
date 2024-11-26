#ifndef PLAN_H
#define PLAN_H

#include <string>
#include "../usuario/usuario.h"

enum class TipoP
{

    convalidacion,
    intercambio

};

class Plan
{

    private:

        int id_, duracion_;
        std::string universidad_;
        TipoP tipo_;

    public:

        Plan
        (

            int id,
            int duracion,
            std::string universidad,
            TipoP tipo

        );

    inline int getId() {return id_;}
    inline int getDuracion() {return duracion_;}
    inline std::string getUniversidad() {return universidad_;}
    inline TipoP getTipo() {return tipo_;}

    inline void setId(int id) {id_ = id;}
    inline void setDuracion(int duracion) {duracion_ = duracion;}
    inline void setUniversidad(std::string universidad) {universidad_ = universidad;}
    inline void setTipo(TipoP tipo) {tipo_ = tipo;}

    bool isRegistered(Usuario usuario);

};

#endif