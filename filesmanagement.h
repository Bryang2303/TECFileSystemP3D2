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


class FilesManagement
{
private:
    int contBookPart;
    int order[4];
    int numFile;
    int numBlockD1;
    int numBlockD2;
    int numBlockD3;
    int numBlockD4;
public:
    FilesManagement();
    string ParityXnor(string p1, string p2, string p3);
    void OddParityBit(string bitChain);
    string GenerateParityInfo(string data);
    int IndexBooks(string path);
    void write(string newPath, string fileName, string textPart,int partNum, int nDisk);
    void writeParity(string fileName, string textData,int nDisk);
    void escribir(string fileName);
    void ReadAndDivide(string path, string fileName);
    void agregar();
};

#endif // FILESMANAGEMENT_H
