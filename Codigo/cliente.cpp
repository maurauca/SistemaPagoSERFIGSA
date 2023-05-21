// Sistema de pago crediticio SERFIGSA
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 80
using namespace std;

typedef struct
{
    int dia;
    int mes;
    int ano;
} fechaTransaccion;

typedef struct
{
    char nombre[30];
    char apellido[30];
    char cedula[15];
    char estadoCiv[30];
    char email[100];
    int telef[8];
} cliente;

cliente client[MAX];
int lastReg = 0;

// Funciones CRUD

// CREATE
void addClient(cliente cl);
// READ
void showClient(int pos);
void showClients();
int isClient(char id[]);
void startClient(int pos);
cliente getClient(int pos);
// UPDATE
void updateClient(cliente cl, int pos);
// DELETE
void deleteClient(int pos);

// OPCIONES
int menu();
void start();

// FICHEROS
FILE *registroCliente;
void saveClientes();
void readClientes();
int calcLastReg(FILE *archivo);

void addClient(cliente cl)
{
    client[lastReg] = cl;
    lastReg++;
}

void showClient(int pos)
{
    cout << "Nombre: " << client[pos].nombre << endl;
    cout << "apellidos: " << client[pos].apellido << endl;
    cout << "Cedula: " << client[pos].cedula << endl;
    cout << "Estado civil: " << client[pos].estadoCiv << endl;
    cout << "Email: " << client[pos].email << endl;
    cout << "Num de telefono: " << client[pos].telef << endl;
}

void updateClient(cliente cl, int pos)
{
    client[pos] = cl;
}

void deleteClient(int pos)
{
    if (pos == lastReg)
    {
        cout << " No hay registro \n";
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        client[i] = client[i + 1];
    }
    lastReg--;
    startClient(lastReg);
}