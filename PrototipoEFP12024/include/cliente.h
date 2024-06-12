#ifndef CLIENTE_H
#define CLIENTE_H


class cliente
{
    private:
        char Pkid[15];
        char nombre[30];
        char idTipo[15];
        char apellido[30];
        char nit[15];
        char telefono[15];
        char direccion[50];
        char correo[50];
        char status[5];
    public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void borrar();
};

#endif // CLIENTE_H
