#ifndef INFORMES_H
#define INFORMES_H

#include <iostream>

using namespace std;

class informes
{
    private:
        string imp_Pkid, imp_nombre, imp_idTipo, imp_apellido, imp_nit, imp_telefono, imp_direccion, imp_correo, imp_status;

    public:
        void imprimirArchivo();

        struct Cliente {
            char Pkid[15];
            char nombre[30];
            char idTipo[15];
            char apellido[30];
            char nit[15];
            char telefono[15];
            char direccion[50];
            char correo[50];
            char status[5];
            };
};


#endif // INFORMES_H
