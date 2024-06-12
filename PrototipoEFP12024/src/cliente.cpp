//Programa que permite insertar, desplegar, modificar y borrar clientes
#include<iostream> // Incluye la biblioteca estándar para entrada y salida
#include<fstream> // Incluye la biblioteca para manejo de archivos
#include<stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include<cstdlib> // Incluye la biblioteca estándar para funciones de utilidad
#include<iomanip> // Incluye la biblioteca para manipulación de la salida
#include <sstream> // Incluye la biblioteca para operaciones de flujo de cadena
#include <cstring> // Incluye la biblioteca para operaciones de cadena
#include "cliente.h" // Incluye el archivo de cabecera Sedes.h que contiene la declaración de la clase
#include"Bitacora.h"

using namespace std; // Usa el espacio de nombres estándar

// Definición de la estructura Sede que contiene los datos de una sede
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


// Definición de las funciones miembro de la clase
void cliente::menu()
{
    //implementacion de variables para bitacora
    string codigoPrograma = "1100";
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

    int choice; // Variable para almacenar la opción seleccionada por el usuario
    char x; // Variable para almacenar la respuesta de agregar otra sede

    // Ciclo para mostrar el menú y procesar las opciones del usuario
    do
    {
        system("cls"); // Limpia la pantalla

        // Imprime el encabezado del menú
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t| SISTEMA DE GESTION EMPLEADOS -  1100  |"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso clientes"<<endl;
        cout<<"\t\t\t 2. Despliegue clientes"<<endl;
        cout<<"\t\t\t 3. Modifica clientes"<<endl;
        cout<<"\t\t\t 4. Borra clientes"<<endl;
        cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice; // Lee la opción del usuario

        switch(choice) // Evalúa la opción seleccionada por el usuario
        {
        case 1:
            // Agregar sede
            do
            {
                insertar(); // Llama a la función para agregar una sede
                //registro de bitacora ingreso
                Auditoria.ingresoBitacora(user,codigoPrograma,"INS");//ingreso matricula
                cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
                cin>>x; // Pregunta al usuario si quiere agregar otra sede
            } while(x=='y'||x=='Y'); // Repite el proceso si el usuario responde 'y' o 'Y'
            break;
        case 2:
            desplegar(); // Llama a la función para mostrar las sedes
            //registro de bitacora
            Auditoria.ingresoBitacora(user,codigoPrograma,"CON");//ingreso matricula
            break;
        case 3:
            modificar(); // Llama a la función para modificar una sede
            //registro de bitacora
            Auditoria.ingresoBitacora(user,codigoPrograma,"MOD");//ingreso matricula
            break;
        case 4:
            borrar(); // Llama a la función para borrar una sede
            //registro de bitacora ingreso
            Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");//ingreso matricula
            break;
        case 5:
            break; // Salir del menú
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get(); // Espera a que el usuario presione Enter
        }
    } while(choice!= 5); // Repite el menú hasta que el usuario seleccione la opción 5
}

// Función para agregar una sede
void cliente::insertar() {
    system("cls"); // Limpia la pantalla
    Cliente clientes; // Crea una instancia de la estructura Empleado para almacenar los datos del empleado
    ofstream file("clientes.dat", ios::binary | ios::app);

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    // Solicita al usuario ingresar los datos de la sede
    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Clientes---------------------------------------------------" << endl;
    cout << "\t\t\tIngrese codigo del cliente   : ";
    cin.ignore();//limpia el buffer de entrada del flujo de entrada estándar
    cin.getline(clientes.Pkid, sizeof(clientes.Pkid));//guarda el id en la instancia que se creo de la estructura empleado
    cout << "\t\t\tIngrese nombre del cliente   : ";
    cin.getline(clientes.nombre, sizeof(clientes.nombre));
    cout << "\t\t\tIngrese id tipo              : ";
    cin.getline(clientes.idTipo, sizeof(clientes.idTipo));
    cout << "\t\t\tIngrese apellido del cliente : ";
    cin.getline(clientes.apellido, sizeof(clientes.apellido));
    cout << "\t\t\tIngrese el nit del cliente  : ";
    cin.getline(clientes.nit, sizeof(clientes.nit));
    cout << "\t\t\tIngrese el telefono del cliente: ";
    cin.getline(clientes.telefono, sizeof(clientes.telefono));
    cout << "\t\t\tIngrese la direccion del cliente: ";
    cin.getline(clientes.direccion, sizeof(clientes.direccion));
    cout << "\t\t\tIngrese el correo del cliente: ";
    cin.getline(clientes.correo, sizeof(clientes.correo));
    cout << "\t\t\tIngrese status del cliente (solvente=1 | pendiente=0): ";
    cin.getline(clientes.status, sizeof(clientes.status));
    // Escribe los datos del empleado en el archivo
    file.write(reinterpret_cast<const char*>(&clientes), sizeof(Cliente));
    file.close(); // Cierra el archivo
}

// Función para mostrar todas las sedes
void cliente::desplegar(){
    system("cls"); // Limpia la pantalla
    ifstream file("clientes.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    int total = 0; // Contador para el total de sedes

    // Muestra la tabla de detalles de sedes
    cout << "\n-----------------------------------------Tabla Detalles de Clientes ----------------------------------------------" << endl;
    Cliente clientes; // Crea una instancia de la estructura empleado para almacenar los datos de cada empleado
    while (file.read(reinterpret_cast<char*>(&clientes), sizeof(Cliente))) { // Lee los datos de los empleados del archivo
        cout << "\t\t\t ID del cliente         : " << clientes.Pkid<< endl;
        cout << "\t\t\t Nombre de cliente      : " << clientes.nombre << endl;
        cout << "\t\t\t idTipo                 : " << clientes.idTipo << endl;
        cout << "\t\t\t Apellido del cliente   : " << clientes.apellido << endl;
        cout << "\t\t\t Nit del cliente        : " << clientes.nit << endl;
        cout << "\t\t\t Telfono del cliente    : " << clientes.telefono << endl;
        cout << "\t\t\t direccion del cliente  : " << clientes.direccion << endl;
        cout << "\t\t\t correo del cliente     : " << clientes.correo << endl;
        cout << "\t\t\t Status del cliente    : " << clientes.status << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++; // Incrementa el contador de sedes
    }

    if (total == 0) { // Verifica si no hay sedes en el archivo
        cout << "\n\t\t\tNo hay informacion..." << endl; // Muestra un mensaje indicando que no hay información
    }

    file.close(); // Cierra el archivo
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver la información
}

// Función para modificar los detalles de una sede
void cliente::modificar() {
    system("cls"); // Limpia la pantalla
    fstream file("clientes.dat", ios::in | ios::out | ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura/escritura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay información..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    string id_modificar; // Variable para almacenar el ID del emplead que se desea modificar
    int found = 0; // Variable para indicar si se encontró la sede a modificar

    cout << "\n-------------------------------------Modificar Detalles de clientes----------------------------------------------" << endl;
    cout << "\t\t\tIngrese id del cliente que desea modificar: ";
    cin >> id_modificar; // Lee el ID del empleado que se desea modificar

    Cliente clientes; // Crea una instancia de la estructura Empleado para almacenar los datos del empleado
    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    // Lee los empleado del archivo y modifica los detalles de la sede con el ID proporcionado
    while (file.read(reinterpret_cast<char*>(&clientes), sizeof(Cliente))) {
        if (strcmp(clientes.Pkid, id_modificar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\t\t\tIngrese nuevo id del empleado: ";
            cin >> clientes.Pkid; // Solicita al usuario ingresar el nuevo ID de la sede
            cout << "\t\t\tIngrese nuevo nombre del cliente: ";
            cin.ignore();
            cin.getline(clientes.nombre, sizeof(clientes.nombre)); // Solicita al usuario ingresar el nuevo nombre de la sede
            cout << "\t\t\tIngrese id tipo              : ";
            cin.getline(clientes.idTipo, sizeof(clientes.idTipo));
            cout << "\t\t\tIngrese apellido del cliente : ";
            cin.getline(clientes.apellido, sizeof(clientes.apellido));
            cout << "\t\t\tIngrese el nit del cliente  : ";
            cin.getline(clientes.nit, sizeof(clientes.nit));
            cout << "\t\t\tIngrese el telefono del cliente: ";
            cin.getline(clientes.telefono, sizeof(clientes.telefono));
            cout << "\t\t\tIngrese la direccion del cliente: ";
            cin.getline(clientes.direccion, sizeof(clientes.direccion));
            cout << "\t\t\tIngrese el correo del cliente: ";
            cin.getline(clientes.correo, sizeof(clientes.correo));
            cout << "\t\t\tIngrese status del cliente (solvente=1 | pendiente=0): ";
            cin.getline(clientes.status, sizeof(clientes.status));

            file1.write(reinterpret_cast<const char*>(&clientes), sizeof(Cliente)); // Escribe los datos de la sede modificada en el archivo temporal

            cout << "\n\t\t\tClites modificado correctamente!!!" << endl; // Muestra un mensaje indicando que la sede se modificó correctamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&clientes), sizeof(Cliente)); // Escribe los datos de la sede sin modificar en el archivo temporal
        }
    }

    if (!found) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\tNo se encontro el empleado con el codigo proporcionado." << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file.close(); // Cierra el archivo original
    file1.close(); // Cierra el archivo temporal
    remove("clientes.dat"); // Elimina el archivo original
    rename("temporal.dat", "clientes.dat"); // Renombra el archivo temporal como "Sedes.dat"
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
}

// Función para borrar una sede
void cliente::borrar() {
    system("cls"); // Limpia la pantalla
    string id_borrar; // Variable para almacenar el ID de la sede que se desea borrar
    int found = 0; // Variable para indicar si se encontró la sede a borrar

    cout << "\n------------------------------------------Detalles del cliente a Borrar-----------------------------------------------" << endl;

    ifstream file("clientes.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    cout << "\n-----------------------------------------Sistema Busqueda de empleados---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese el id del cliente que quiere Borrar: ";
    cin >> id_borrar; // Lee el ID de la sede que se desea borrar

    Cliente clientes; // Crea una instancia de la estructura Sede para almacenar los datos de la sede
    while (file.read(reinterpret_cast<char*>(&clientes), sizeof(Cliente))) { // Lee las sedes del archivo
        if (strcmp(clientes.Pkid, id_borrar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl; // Muestra un mensaje indicando que la sede se borró exitosamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&clientes), sizeof(Cliente)); // Escribe los datos de la sede sin borrar en el archivo temporal
        }
    }

    if (found == 0) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\t Codigo del empleado no encontrado...." << "\n" << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file1.close(); // Cierra el archivo temporal
    file.close(); // Cierra el archivo original

    remove("clientes.dat"); // Elimina el archivo original
    rename("temporal.dat", "clientes.dat"); // Renombra el archivo temporal como "Sedes.dat"

    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
}
