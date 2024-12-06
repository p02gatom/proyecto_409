#ifndef GRADO_H
#define GRADO_H

#include <string>

class Grado
{

    private:

        int codigo_, creditos_;
        std::string nombre_, facultad_;

    public:

        Grado
        (

            int codigo = 0,
            int creditos = 0,
            std::string nombre = "",
            std::string facultad = ""

        );

    inline int getCodigo() {return codigo_;}
    inline int getCreditos() {return creditos_;}
    inline std::string getNombre() {return nombre_;}
    inline std::string getFacultad() {return facultad_;}

    inline void setCodigo(int codigo) {codigo_ = codigo;}
    inline void setCreditos(int creditos) {creditos_ = creditos;}
    inline void setNombre(std::string nombre) {nombre_ = nombre;}
    inline void setFacultad(std::string facultad) {facultad_ = facultad;}

    bool operator == (Grado &grado);

};

#endif