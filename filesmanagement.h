#ifndef FILESMANAGEMENT_H
#define FILESMANAGEMENT_H
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <dirent.h>

#include <bitset>
using namespace std;
/**
 * @brief The FilesManagement class En esta clase es donde se realiza el manejo de archivos
 */

class FilesManagement
{
private:
    /**
     * @brief contBookPart se utiliza para saber la cantidad de partes del libro
     */
    int contBookPart;
    /**
     * @brief order Es un array donde se almacenan las partes
     */
    int order[4];
    /**
     * @brief numFile Se utiliza para saber el numero de archivo que se esta generando
     */
    int numFile;
    /**
     * @brief numBlockD1 Se utiliza para el almacenamiento de los Bloques del Disco 1
     */
    int numBlockD1;
    /**
     * @brief numBlockD2 Se utiliza para el almacenamiento de los Bloques del Disco 2
     */
    int numBlockD2;
    /**
     * @brief numBlockD3 Se utiliza para el almacenamiento de los Bloques del Disco 3
     */
    int numBlockD3;
    /**
     * @brief numBlockD4 Se utiliza para el almacenamiento de los Bloques del Disco 4
     */
    int numBlockD4;
public:
    /**
     * @brief FilesManagement Es el contructor de la clase
     */
    FilesManagement();
    /**
     * @brief ParityXnor Con esta funcion se calcula la paridad del libro
     * @param p1 Parte 1 del libro
     * @param p2 Parte 2 del libro
     * @param p3 Parte 3 del libro
     * @return
     */
    string ParityXnor(string p1, string p2, string p3);
    /**
     * @brief OddParityBit En esta funcion se aplica la paridad par
     * @param bitChain Cadena de paridad
     */
    void OddParityBit(string bitChain);
    /**
     * @brief GenerateParityInfo Esta funcion unifica el dato de la paridad generada por Xnor y la del bit de paridad
     * @param data Datos a unificar
     * @return la paridad final del libro
     */
    string GenerateParityInfo(string data);
    /**
     * @brief IndexBooks Funcion para indexar todos los libros de las carpetas
     * @param path el path de la carpeta a indexar
     * @return 0
     */
    int IndexBooks(string path);
    /**
     * @brief write Esta funcion se utiliza para escribir cada parte del libro que se genero
     * @param newPath Path del la nueva carpeta
     * @param fileName Nombre del nuevo archivo
     * @param textPart Datos a escribir en el archivo
     * @param partNum Numero de la parte
     * @param nDisk Numero del Disco
     */
    void write(string newPath, string fileName, string textPart,int partNum, int nDisk);
    /**
     * @brief writeParity Escribe la paridad de cada libro en un archivo
     * @param fileName Nombre del archivo a generar
     * @param textData Dato a escribir en el archivo
     * @param nDisk Numero del disco
     */
    void writeParity(string fileName, string textData,int nDisk);
    /**
     * @brief escribir Se utiliza para escribir el archivo seleccionado
     * @param fileName Nombre del archivo a escribir
     */
    void escribir(string fileName);
    /**
     * @brief ReadAndDivide Esta funcion es la que se utiliza para la lectura del libro y su división
     * @param path dirección del libro
     * @param fileName nombre del archivo
     */
    void ReadAndDivide(string path, string fileName);
    /**
     * @brief agregar Esta funcion se utliza para agregar las partes de forma correspondiente
     */
    void agregar();
};

#endif // FILESMANAGEMENT_H
