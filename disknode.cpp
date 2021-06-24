#include "disknode.h"
#include "tecfsdisk.h"
#include <QDebug>
#include <QString>
#include <iostream>
using namespace std;

DiskNode::DiskNode()
{

}

TECFSDisk Aplicacion;

//METODO DONDE SE INSTALA TECFSDisk para cada disco
void DiskNode::crearDisk(){
    int prue;
    for(int a=1 ; a<5 ; a++){
        cout <<"CREANDO DISCO"<< " " << a << endl;
        cout <<"\n"<< endl;
        Aplicacion.ParseXML(a);
        this->puertos.append(Aplicacion.GetPuerto());
        this->IPs.append(Aplicacion.GetIP());
        this->PathD.append(Aplicacion.GetPath());
        prue = a-1;
        qDebug() << puertos[prue] << "" << IPs[prue] << "" << PathD[prue] << endl;
        cout <<"DISCO CREADO"<< endl;
        cout <<"\n"<< endl;

    }
}


int DiskNode::get_tamanoDisk(){
    this->sizeD = 4;
    return sizeD;
}

int DiskNode::get_tamanoBloque(){
    this->sizeB = 2;
    return sizeB;
}

int DiskNode::getpuerto(int i){
    int pos= i-1;
    return puertos[pos];
}

QString DiskNode::getIP(int p){
    int pos= p-1;
    return IPs[pos];
}

QString DiskNode::getpath(int r){
    int pos= r-1;
    return PathD[pos];
}
