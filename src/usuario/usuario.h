#ifndef USUARIO_H
#define USUARIO_H

#include <string>

enum class TipoU
{

    Admin,
    Estudiante,
    Profesor

};

class Usuario
{

    private:

        std::string email_, pssw_;
        int curso_;
        TipoU tipo_;

    public:

        Usuario
        (

            std::string email = "",
            std::string pssw = "",
            int curso = 0,
            TipoU tipo = TipoU::Estudiante

        );

    inline std::string getEmail() {return email_;}
    inline std::string getPssw() {return pssw_;}
    inline int getCurso() {return curso_;}
    inline TipoU getTipo() {return tipo_;}

    inline void setEmail(std::string email) {email_ = email;}
    inline void setPssw(std::string pssw) {pssw_ = pssw;}
    inline void setCurso(int curso) {curso_ = curso;}
    inline void setTipo(TipoU tipo) {tipo_ = tipo;}

    bool signIn(std::string email, std::string pssw);

};

#endif 