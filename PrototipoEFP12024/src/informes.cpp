//Programa que permite imprimir en un archivo txt los datos de los clientes
#include<iostream> // Incluye la biblioteca estándar para entrada y salida
#include<fstream> // Incluye la biblioteca para manejo de archivos
#include<stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include<cstdlib> // Incluye la biblioteca estándar para funciones de utilidad
#include<iomanip> // Incluye la biblioteca para manipulación de la salida
#include <sstream> // Incluye la biblioteca para operaciones de flujo de cadena
#include <cstring> // Incluye la biblioteca para operaciones de cadena

#include "informes.h"
#include "cliente.h"
#include"Bitacora.h"

using namespace std;

struct Informes{
    string imp_Pkid;
    string imp_nombre;
    string imp_idTipo;
    string imp_apellido;
    string imp_nit;
    string imp_telefono;
    string imp_direccion;
    string imp_correo;
    string imp_status;
};


void informes::imprimirArchivo() {
    //implementacion de variables para bitacora
    string codigoPrograma = "1200";
    Bitacora Auditoria;
    //abrira el archivo de User y contraseñas--------------------------
    ifstream fileU;
    fileU.open("usuarios.txt",ios::in);


    //verificar si se abrio el archivo---------------------------
    if (!fileU)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU.close();
    }
    //busca el usuario en el archivo---------------------------------
    string user,pass;
    while (fileU>>user>>pass)
    {
        //obtener el nombre de usuario
    }
    fileU.close();

    system("cls");
    Informes informes;
    ofstream file("impresion.txt", ios::out); // Abre el archivo txt

    if (!file) {
        cerr << "No se pudo abrir el archivo 'impresion.txt'." << endl;
        return;
    } else {
        Cliente clientes;

        ifstream fileEmp("clientes.dat", ios::binary);
        if (!fileEmp.is_open()) {
            cerr << "Error: No se pudo abrir el archivo 'empleados.dat'." << endl;
            return;
        }
        else
        {
            cout << "\n\t\t\tLa informacion del empleado se ha impreso exitosamente." << endl;
            system("pause");
            Auditoria.ingresoBitacora(user,codigoPrograma,"IMP");//inpresion de archivo

            file <<"-----------------------------------------Tabla Detalles de clientes ----------------------------------------------" << endl;
            while (fileEmp.read(reinterpret_cast<char*>(&clientes), sizeof(Cliente))){
                file << "\t\t\t ID del cliente         : " << clientes.Pkid<< endl;
                file << "\t\t\t Nombre de cliente      : " << clientes.nombre << endl;
                file << "\t\t\t idTipo                 : " << clientes.idTipo << endl;
                file << "\t\t\t Apellido del cliente   : " << clientes.apellido << endl;
                file << "\t\t\t Nit del cliente        : " << clientes.nit << endl;
                file<< "\t\t\t Telfono del cliente    : " << clientes.telefono << endl;
                file<< "\t\t\t direccion del cliente  : " << clientes.direccion << endl;
                file<< "\t\t\t correo del cliente     : " << clientes.correo << endl;
                file << "\t\t\t Status del cliente    : " << clientes.status << endl;
                file << "-----------------------------------------------------------------------------------------------------------------" << endl;
                }
        fileEmp.close();
        file.close();
        }
    }
}
