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
public:
    FilesManagement();
    void escribir(string path);
    void ReadAndDivide(string path, string fileName);
    void agregar();
    void write(string newPath, string fileName, string textPart,int partNum);
    int IndexBooks(string path);
};

#endif // FILESMANAGEMENT_H
