#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

Banco::Banco()
{
    cantidadClientes = 0;
    Clientes = new Cliente[cantidadClientes]; //
};

Banco::Banco(int cantidadClientes2)
{
    cantidadClientes = cantidadClientes2;
    Clientes = new Cliente[cantidadClientes];
};

void Banco::cargaclientes()
{
    ifstream fclientes("fclientes.txt");
    string nombre, estado, nivel, auxPesos, auxDolares, aux, apellido;
    int ingreso, numero_cuenta, dni;
    int i = 0;
    try
    {
        if (fclientes.is_open())
        {
            getline(fclientes, aux);
            getline(fclientes, aux);
            while (fclientes)
            {

                if (fclientes.eof())
                {
                    break;
                }

                fclientes >> dni;
                fclientes >> nombre;
                fclientes >> apellido;
                nombre = nombre + " ";
                nombre = nombre + apellido;
                fclientes >> ingreso;
                fclientes >> nivel;
                fclientes >> estado;
                fclientes >> numero_cuenta;
                fclientes >> auxPesos;
                fclientes >> auxDolares;

                Clientes[i].set_DNI(dni);
                Clientes[i].set_nombre(nombre);
                Clientes[i].set_ingreso(ingreso);
                Clientes[i].set_nivel(nivel);
                Clientes[i].set_estado(estado);
                Clientes[i].set_numcuenta(numero_cuenta);
                Clientes[i].set_saldo_Pesos(stold(auxPesos));
                Clientes[i].set_saldoDolares(stold(auxDolares));
                i++;
            }
        }
        else
        {
            throw "No se pudo abrir el archivo";
        }
        fclientes.close();
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
    }
    catch (bad_alloc &)
    {
        cerr << "Error de memomoria" << endl;
    }
    catch (...)
    {
        cerr << "Error desconocido" << endl;
    }
}

void Banco::detalleCliente(int numCuenta)
{
    bool encontrado = false;
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {
            if (numCuenta == Clientes[i].get_numCuenta())
            {
                cout << "DNI: " << Clientes[i].get_DNI() << endl;
                cout << "Nombre: " << Clientes[i].get_nombre() << endl;
                cout << "Ingreso: " << Clientes[i].get_ingreso() << endl;
                cout << "Nivel: " << Clientes[i].get_nivel() << endl;
                cout << "Estado: " << Clientes[i].get_estado() << endl;
                cout << "Numero de cuenta: " << Clientes[i].get_numCuenta() << endl;
                cout << "Saldo en pesos: " << Clientes[i].get_saldoPesos() << endl;
                cout << "Saldo en dolares: " << Clientes[i].get_saldoDolares() << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            throw "No se encontro el cliente";
        }
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
    }
    catch (bad_alloc &)
    {
        cerr << "Error de memoria" << endl;
    }
}

void Banco::listadoClientes()
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << "DNI: " << Clientes[i].get_DNI() << endl;
        cout << "Nombre: " << Clientes[i].get_nombre() << endl;
        cout << "Ingreso: " << Clientes[i].get_ingreso() << endl;
        cout << "Nivel: " << Clientes[i].get_nivel() << endl;
        cout << "Estado: " << Clientes[i].get_estado() << endl;
        cout << "Numero de cuenta: " << Clientes[i].get_numCuenta() << endl;
        cout << "Saldo en pesos: " << Clientes[i].get_saldoPesos() << endl;
        cout << "Saldo en dolares: " << Clientes[i].get_saldoDolares() << endl;
        cout << "------------------------------------------------------------------" << endl;
    }
}

int Banco::get_cantidadClientes()
{
    return cantidadClientes;
}

Cliente Banco::get_Cliente(int pos)
{
    return Clientes[pos];
}

int Banco::calcularClientes()
{
    ifstream fclientes("fclientes.txt");
    fclientes.open("fclientes.txt");
    int cantidad;
    try
    {
        if (fclientes.is_open())
        {
            fclientes >> cantidad;
            fclientes >> cantidad;
            fclientes >> cantidad;
            fclientes >> cantidad;
        }
        else
        {
            throw "No se pudo abrir el archivo";
        }
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
        return -1;
    }
    fclientes.close();
    return cantidad;
}
void Banco::deposito(long double monto, double numero, char moneda)
{
    bool encontrado = false;
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {
            if (Clientes[i].get_numCuenta() == numero)
            {
                if (moneda == 'P' || moneda == 'p')
                {
                    Clientes[i].depositar_pesos(monto);
                    cout << "Saldo: " << Clientes[i].get_saldoPesos() << endl;
                
                }
                else if (moneda == 'D' || moneda == 'd')
                {
                    Clientes[i].depositar_dolares(monto);
                    cout << "Saldo: " << Clientes[i].get_saldoDolares() << endl;
                    
                }
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            throw "No se encontro el cliente";
        }
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
    }
}
void Banco::extraer(long double monto, double numero, char moneda)
{
    bool encontrado = false;
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {

            if (Clientes[i].get_numCuenta() == numero)
            {
                if (moneda == 'p' || moneda == 'P')
                {
                    Clientes[i].retirar_pesos(monto);
                    cout << "Saldo: " << Clientes[i].get_saldoPesos() << endl;
                }
                else if (moneda == 'd' || moneda == 'D')
                {
                    Clientes[i].retirar_dolares(monto);
                    cout << "Saldo: " << Clientes[i].get_saldoDolares() << endl;
                }
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            throw "No se encontro el cliente";
        }
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
    }
}

void Banco::agregarCliente(string nom, int dni, string lvl)
{
    Cliente *aux = new Cliente[cantidadClientes + 1];
    for (int i = 0; i < cantidadClientes; i++)
    {
        aux[i] = Clientes[i];
    }
    aux[cantidadClientes].set_nombre(nom);
    aux[cantidadClientes].set_DNI(dni);
    aux[cantidadClientes].set_nivel(lvl);
    time_t t = time(0);
    tm *ahora = localtime(&t);
    aux[cantidadClientes].set_ingreso(ahora->tm_year + 1900);
    cantidadClientes += 1;
    delete[] Clientes;
    Clientes = new Cliente[cantidadClientes];
    for (int i = 0; i < cantidadClientes; i++)
    {
        Clientes[i] = aux[i];
    }
    delete[] aux;
    
}

void Banco::credito(int numC, double monto)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        if (Clientes[i].get_numCuenta() == numC)
        {
            Clientes[i].gastarlimite(monto);
        }
    }
}
void Banco::baja(int numC,string estado){
    bool encontrado = false;
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {

            if (Clientes[i].get_numCuenta() == numC)
            {
                if (estado=="a")
                {
                    Clientes[i].set_estado("ACTIVO");
                }
                else if (estado=="b")
                {
                    Clientes[i].set_estado("BAJA");
                }
                else
                {
                    cout<<"ingreso incorrecto"<<endl;
                }
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            throw "No se encontro el cliente";
        }
    }
    catch (const char *exception)
    {
        cerr << "Error: " << exception << endl;
    }





}
