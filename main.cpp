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
#include <filesmanagement.h>
using namespace std;


ControllerNode *server;

void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int mode = 2;
    if (mode==2){



        /*
        FilesManagement *fss;
        fss->escribir("A");
        fss->escribir("B");
        fss->escribir("C");
        fss->escribir("D");

        string path = "Archivos/";
        DIR *dir; struct dirent *diread;
        vector<char *> files;

        if ((dir = opendir(path.c_str())) != nullptr) {
            while ((diread = readdir(dir)) != nullptr) {
                files.push_back(diread->d_name);
            }
            closedir (dir);
        } else {
            perror ("opendir");
            return EXIT_FAILURE;
        }

        for (auto file : files) {
            cout << file << endl;
            //ReadAndDivide(path,file);
        }
        */
        //fss->IndexBooks("Archivos/");




        QApplication a(argc, argv);
        Widget w;
        w.show();


        cout << "SIUU" << endl;

        a.exec();

        return 0;
    } else {
        server = new ControllerNode;
        pthread_t hiloServer;
        pthread_create(&hiloServer,0,serverRun,NULL);
        pthread_detach(hiloServer);

        while (1) {

            string mensaje;
            cin >> mensaje;
            //string a = "sdasn";
            server->setMensaje(mensaje.c_str());
        }

        delete server;
        return 0;
    }

}

