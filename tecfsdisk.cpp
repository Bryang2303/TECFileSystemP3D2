#include "tecfsdisk.h"

#include <QDir>
#include <iostream>
#include <QDebug>
#include <vector>
#include <QFile>
#include <QIODevice>
#include <QJsonArray>
#include <QTextStream>
#include <QtXml>
#include <QDomProcessingInstruction>
#include <QString>
using namespace std;
TECFSDisk::TECFSDisk()
{

}
// Funcion para el nodo hijo del archivo
void TECFSDisk::listNodeChild(QDomElement inElem,int lv){
    QDomNode node = inElem.firstChild();
    int level = lv;
    int mPos = level +1;
    int count = 1;
    while(!node.isNull()){
        QDomElement myElem = node.toElement();
        if(!myElem.isNull()){
            //  Obtener el puerto
            if(count == 1){
                this->ip = QString::fromLatin1("%1").arg(myElem.text());

                count ++;
            }//End if

            //Obtener la ip
            else if(count ==2){
                QString a;
                a =QString::fromLatin1("%1").arg(myElem.text());
                this->puerto = a.toInt();

                count ++;
            }//End else if
            //Obtener el path
            else{
                this->Path = QString::fromLatin1("%1").arg(myElem.text());
                break;
            }//End else
        } //End if
        node = node.nextSibling();
    } //End while

}//End funcion

void TECFSDisk::ParseXML(int i){
    int disco;
    disco = i -1;
    //Arreglo de direcciones
    QString Discos[4] = {"DiskA.xml","DiskB.xml","DiskC.xml","DiskD.xml"};

    QString fileName = Discos[disco];
    QFile myFile(fileName);

    if (myFile.exists()){
        //Condicional para leer el archivo
        if(myFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QDomDocument myDoc;
            myDoc.setContent(&myFile);
            QDomElement myDocElem = myDoc.documentElement();
            QDomNode myNode = myDocElem.firstChild();
            while(!myNode.isNull())
            {
                QDomElement nodeElem = myNode.toElement();
                if (myNode.hasChildNodes())
                {
                    //ChildNode
                    this->listNodeChild(nodeElem,1);
                }//End if
                myNode = myNode.nextSibling();

            }//End While
        }//End if
    }//End if
    else{
        cout<<"Archivo no existe"<<endl;
    }
}

//Retornar el puerto
int TECFSDisk::GetPuerto(){
    return this->puerto;
}
//Retornar la ip
QString TECFSDisk::GetIP(){
    return this->ip;
}
//Retornar el path
QString TECFSDisk::GetPath(){
    return this->Path;
}
