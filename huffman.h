#ifndef HUFFMAN_H
#define HUFFMAN_H
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

class Huffman
{
public:
    Huffman();

    /**
     * @brief printCodes Esta funcion se utiliza para imprimir los caracteresque se generan del Huffman
     * @param root Es la raiz del arbol utilizado
     * @param str Dato que se quiere obtener
     */
    void printCodes(struct MinHeapNode* root, string str);

    /**
     * @brief storeCodes funcion de utilidad para almacenar caracteres junto  ya que hay valor huffman en una tabla hash
     * @param root Es la raiz del arbol utilizado
     * @param str Dato que se quiere obtener
     */
    void storeCodes(struct MinHeapNode* root, string str);

    /**
     * @brief HuffmanCodes Funcion para crear el arbol del algoritmo Huffman
     * @param size Tamano del arbol
     */
    void HuffmanCodes(int size);

    /**
     * @brief calcFreq Función de utilidad para almacenar el mapa de cada carácter con su frecuencia en la cadena de entrada
     * @param str Cadena de entrada
     * @param n contador
     */
    void calcFreq(string str, int n);


    // if s[i]=='1' then move to node->right
    // if s[i]=='0' then move to node->left
    // if leaf node append the node->data to our output string
    /**
     * @brief decode_file la función itera a través de la cadena codificada en el string s
     * @param root Raiz del arbol
     * @param s cadena codificada
     * @return dato codificado
     */
    string decode_file(struct MinHeapNode* root, string s);


};

#endif // HUFFMAN_H
