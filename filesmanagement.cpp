#include "filesmanagement.h"

FilesManagement::FilesManagement()
{

}


int FilesManagement::IndexBooks(string path) {
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

    for (auto file : files) ReadAndDivide(path,file);


    //return EXIT_SUCCESS;
}


/*
int main2()
{
    escribir("A");
    escribir("B");
    string path;
    cin >> path;
    IndexBooks(path); // Path del directorio a indexar


    //agregar();
    return 0;
}*/

void FilesManagement::write(string newPath, string fileName, string textPart,int partNum){

    ofstream file;
    string fileName2 = fileName;
    fileName = "";
    for (int z=0;z<fileName2.length();z++){
        if (fileName2[z]=='.'){
            break;
        } else {
            fileName+=fileName2[z];
        }
    }

    file.open(newPath+fileName+to_string(partNum)+".text",ios::out);// Abre archivo

    if (file.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    file << textPart;

    file.close();
}

void FilesManagement::escribir(string fileName){

    ofstream archivo;

    archivo.open("Archivos/"+fileName+".text",ios::out);// Abre archivo

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    archivo << "Parte1Parte2Parte3";

    archivo.close();
}
void FilesManagement::ReadAndDivide(string path, string fileName){
    ifstream archivo;
    string texto;

    archivo.open(path+fileName,ios::in);

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    /*
    while (!archivo.eof()) {// mientras no sea el final del archivo
        getline(archivo,texto);
        cout << texto << endl;

    }*/
    getline(archivo,texto);
    cout << texto << endl;
    int content = 0;
    int separate = texto.length()/3;
    string part;
    int partNum = 1;

    while (content<texto.length()+1) {// mientras no sea el final del archivo
        if (content == texto.length()){
            write(path,fileName,part,partNum);
            part="";
            partNum++;
            break;
        }
        if (content!=0 && content % separate == 0){
            write(path,fileName,part,partNum);
            part="";
            partNum++;
        }

        cout << texto[content] << endl;
        part+=texto[content];
        content++;

    }

    archivo.close();

}
void FilesManagement::agregar(){
    ofstream archivo;

    archivo.open("Archivos/p1.text",ios::app);

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    archivo << "Bien";

    archivo.close();

}
