#include "filesmanagement.h"

FilesManagement::FilesManagement()
{
    this->contBookPart = 1;

    this->numFile;
    this->numBlockD1 = 2;
    this->numBlockD2 = 2;
    this->numBlockD3 = 2;
    this->numBlockD4 = 2;

}

string FilesManagement::ParityXnor(string p1, string p2, string p3){
    string xnor;
    string xnorF;
    for (int i = 0;i<16;i++){
        if (p1[i]==p2[i]){
            xnor+="1";
        } else {
            xnor+="0";
        }
    }
    for (int j = 0;j<16;j++){
        if (xnor[j]==p3[j]){
            xnorF+="1";
        } else {
            xnorF+="0";
        }
    }
    cout << "Parity Xnor: " << xnorF << endl;
    return xnorF;
}

void FilesManagement::OddParityBit(string bitChain){
    int contOnes = 0;
    for (int q = 0;q<48;q++){
        //cout <<  bitChain[q] << endl;
        if (bitChain[q] == '1'){
            contOnes++;
        }
    }
    if (contOnes%2==0){
        cout << "Amount of 1s : " << contOnes << endl;
        bitChain+="1";
        cout << "Odd Parity: Odd " << bitChain << endl;
    } else {
        cout << "Amount of 1s : " << contOnes << endl;
        bitChain+="0";
        cout << "Odd Parity: Even " << bitChain << endl;
    }
}

string FilesManagement::GenerateParityInfo(string data){
  //string data = "ABCDEF";

  int contBytes = 1;
  string ptemp,p1,p2,p3;
  for (std::size_t i = 0; i < data.size(); ++i)
  {
      //cout << bitset<8>(myString.c_str()[i]) << endl;
      string binChar = bitset<8>(data.c_str()[i]).to_string();
      cout << binChar << endl;
      ptemp+=binChar;
      if (contBytes==2){
          p1 = ptemp;
          ptemp = "";
      } else if (contBytes == 4) {
          p2 = ptemp;
          ptemp = "";
      } else if (contBytes == 6) {
          p3 = ptemp;
          ptemp = "";
      }
      contBytes++;
  }
  cout << "PART1 " << p1 << " PART2 " << p2 << " PART3 " << p3 << endl;

  OddParityBit(p1+p2+p3);
  return ParityXnor(p1,p2,p3);

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

    for (auto file : files) {
        cout << file << endl;
        ReadAndDivide(path,file);
    }


    //return EXIT_SUCCESS;
}

void FilesManagement::write(string newPath, string fileName, string textPart,int partNum, int nDisk){

    ofstream file;
    ofstream metaFile;

    string fileName2 = fileName;
    fileName = "";
    for (int z=0;z<fileName2.length();z++){
        if (fileName2[z]=='.'){
            break;
        } else {
            fileName+=fileName2[z];
        }
    }
    int numBlock = 0;

    switch (nDisk) {
    case 1:
        numBlock = this->numBlockD1;
        cout << "El block numero " << numBlock << endl;
        this->numBlockD1++;
        break;
    case 2:
        numBlock = this->numBlockD2;
        this->numBlockD2++;
        break;
    case 3:
        numBlock = this->numBlockD3;
        this->numBlockD3++;
        break;
    case 4:
        numBlock = this->numBlockD4;
        this->numBlockD4++;
        break;
    }
    /*
    ofstream file2;
    file2.open("DISK 1/Block 2/Z.text",ios::out);// Abre archivo

    if (file2.fail()){
        cout << "Error al intentar abrir el archivo m" << endl;
        exit(1);
    }
    ofstream file3;
    file3.open("DISK 1/Block 5/Z.text",ios::out);// Abre archivo

    if (file3.fail()){
        cout << "Error al intentar abrir el archivo l" << endl;
        exit(1);
    }*/

    cout << "El block num " << numBlock << endl;
    file.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+to_string(partNum)+".text",ios::out);// Abre archivo

    if (file.fail()){
        cout << "Error al intentar abrir el archivo n" << endl;
        exit(1);
    }
    string binChar2;
    for (std::size_t i = 0; i < textPart.size(); ++i)
    {
        //cout << bitset<8>(myString.c_str()[i]) << endl;
        string binChar = bitset<8>(textPart.c_str()[i]).to_string();
        //cout << binChar << endl;
        binChar2+=binChar;
    }


    file << binChar2;

    file.close();

    metaFile.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+to_string(partNum)+"_Metadata.text",ios::out);// Abre archivo
    metaFile << "Part "+to_string(partNum)+" from book: "+fileName+"\n";
    metaFile.close();
}

void FilesManagement::writeParity(string fileName, string textData,int nDisk){

    ofstream file;
    ofstream metaFile;

    string fileName2 = fileName;
    fileName = "";
    for (int z=0;z<fileName2.length();z++){
        if (fileName2[z]=='.'){
            break;
        } else {
            fileName+=fileName2[z];
        }
    }

    int numBlock = 0;

    switch (nDisk) {
    case 1:
        numBlock = this->numBlockD1;
        cout << "El block numero " << numBlock << endl;
        this->numBlockD1++;
        break;
    case 2:
        numBlock = this->numBlockD2;
        this->numBlockD2++;
        break;
    case 3:
        numBlock = this->numBlockD3;
        this->numBlockD3++;
        break;
    case 4:
        numBlock = this->numBlockD4;
        this->numBlockD4++;
        break;
    }

    file.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+"p.text",ios::out);// Abre archivo

    if (file.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    file << GenerateParityInfo(textData);

    file.close();

    metaFile.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+"p_Metadata.text",ios::out);// Abre archivo
    metaFile << "Parity info from book: "+fileName+"\n";
    metaFile.close();
}


void FilesManagement::escribir(string fileName){

    ofstream archivo;

    archivo.open("./Archivos/"+fileName+".text",ios::out);// Abre archivo

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }

    archivo << "ABCDEF";

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

    switch (this->contBookPart) {
    case 4:
        order[0] = 1;
        order[1] = 2;
        order[2] = 3;
        order[3] = 4;
        this->numFile = 1;
        break;
    case 5:
        order[0] = 1;
        order[1] = 2;
        order[2] = 4;
        order[3] = 3;
        this->numFile = 2;
        break;
    case 7:
        order[0] = 1;
        order[1] = 4;
        order[2] = 2;
        order[3] = 3;
        this->numFile = 3;
        break;
    case 8:
        order[0] = 4;
        order[1] = 1;
        order[2] = 2;
        order[3] = 3;
        this->numFile = 4;
        break;
    }
    //cout << "ES EL DISKO NUM > > > " << contBookPart << endl;
    for (int l = 0;l<4;l++){
        cout << order[l] << endl;
    }

    int contDisk = 1;
    if (this->numFile>0 && this->numFile<=4){
        while (content<texto.length()+1) {// mientras no sea el final del archivo
            if (content == texto.length()){

                for (int s = 0;s<4;s++){
                    if (order[s] == contDisk){
                        cout << "Parte " << contDisk << " va para el disk " << s+1 << endl;
                        write(path,fileName,part,partNum,s+1);
                        contDisk++;
                        break;
                    }
                }

                part="";
                partNum++;
                break;
            }
            if (content!=0 && content % separate == 0){
                for (int r = 0;r<4;r++){
                    if (order[r] == contDisk){
                        cout << "Parte " << contDisk << " va para el disk " << r+1 << endl;
                        write(path,fileName,part,partNum,r+1);
                        contDisk++;
                        break;
                    }
                }
                //write(path,fileName,part,partNum);
                part="";
                partNum++;
            }

            cout << texto[content] << endl;
            part+=texto[content];
            content++;

        }
        for (int u = 0;u<4;u++){
            if (order[u] == 4){
                cout << "Info Paridad va para el disk " << u+1 << endl;
                writeParity(fileName,texto,u+1);
                //contDisk++;
                break;
            }
        }
    }
    this->contBookPart++;
    this->numFile = 0;
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

