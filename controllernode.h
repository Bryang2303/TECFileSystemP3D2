#ifndef CONTROLLERNODE_H
#define CONTROLLERNODE_H
#include "widget.h"
#include <QApplication>
#include "iostream"
#include "controllernode.h"

#include <iomanip>

#include <sstream>
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <dirent.h>

#include <bitset>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>


using namespace std;
/**
 * @brief The dataSocket struct Una estructura con los datos del socket servidor
 */
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};
/**
 * @brief The ControllerNode class La clase que permite la creacion del Servidor, asi como su conexion con el Cliente y todo el flujo de datos con este
 */
class ControllerNode
{
public:
    /**
     * @brief ControllerNode Es el constructor
     */
    ControllerNode();
    /**
     * @brief run Ejecucion del servidor
     */
    void run();
    /**
     * @brief setMensaje Permite definir el mensaje enviado por el servidor
     * @param msn El contenido del mensaje
     */
    void setMensaje(const char *msn);
private:
    int descriptor;
    /**
     * @brief info Direccion del socket de entrada.
     */
    sockaddr_in info;
    /**
     * @brief crear_Socket Permite saber si es posible la creacion de un socket.
     * @return Si fue posible la creacion del socket o no.
     */
    bool crear_Socket();
    /**
     * @brief ligar_kernel Permite saber si es posible ligar el kernel.
     * @return Si fue ligar el kernel posible o no.
     */
    bool ligar_kernel();
    /**
     * @brief controladorCliente Permite el control de cada cliente que contacta con el servidor. Esto lo realiza por medio de hilo. Para esta asignacion solo se utiliza un cliente.
     * @param obj Cada cliente
     * @return Nada en especifico
     */
    static void * controladorCliente(void *obj);
    /**
     * @brief clientes Array con cada cliente contactado
     */
    vector<int> clientes;

    static string DecodeMsg(string msg);



};


#endif //MS2_MSERVER_H
