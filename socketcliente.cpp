#include "socketcliente.h"
#include "widget.h"
string ParityXnor2(string p1, string p2, string p3){
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
    cout << "Parity XNOR: " << xnorF << endl;
    return xnorF;
}

string ParityXor(string p1, string p2, string p3){
    string xnor;
    string xnorF;
    for (int i = 0;i<16;i++){
        if (p1[i]==p2[i]){
            xnor+="0";
        } else {
            xnor+="1";
        }
    }
    for (int j = 0;j<16;j++){
        if (xnor[j]==p3[j]){
            xnorF+="0";
        } else {
            xnorF+="1";
        }
    }
    cout << "Restored By XOR: " << xnorF << endl;
    //string *parts3[3];
    //string * test = new string[6];
    //*parts3[0] = p1;
    //*parts3[1] = p2;
    //*parts3[2] = xnorF;
    cout << " La suma " << p1+p2+xnorF << endl;
    string final = p1+p2+xnorF;
    return final;
}

void OddParityBit2(string bitChain){
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

string GenerateParityInfo2(string data){
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

  OddParityBit2(p1+p2+p3);
  return ParityXnor2(p1,p2,p3);

}




void escribir3(string path);
void ReadAndDivide2(string path, string fileName);
void agregar();
void write2(string newPath, string fileName, string textPart,int partNum,int nDisk);


int contBookPart2 = 1;
int order2[4];
int numFile2;
int numBlockD12 = 2;
int numBlockD22 = 2;
int numBlockD32 = 2;
int numBlockD42 = 2;


int IndexBooks2(string path) {
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

    for (string file : files) {
        cout << file << endl;
        ReadAndDivide2(path,file);
    }



    //return EXIT_SUCCESS;
}
void write2(string newPath, string fileName, string textPart,int partNum, int nDisk){

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
        numBlock = numBlockD12;
        cout << "El block numero " << numBlock << endl;
        numBlockD12++;
        break;
    case 2:
        numBlock = numBlockD22;
        numBlockD22++;
        break;
    case 3:
        numBlock = numBlockD32;
        numBlockD32++;
        break;
    case 4:
        numBlock = numBlockD42;
        numBlockD42++;
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

void writeParity2(string fileName, string textData,int nDisk){

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
        numBlock = numBlockD12;
        cout << "El block numero " << numBlock << endl;
        numBlockD12++;
        break;
    case 2:
        numBlock = numBlockD22;
        numBlockD22++;
        break;
    case 3:
        numBlock = numBlockD32;
        numBlockD32++;
        break;
    case 4:
        numBlock = numBlockD42;
        numBlockD42++;
        break;
    }

    file.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+"p.text",ios::out);// Abre archivo

    if (file.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    file << GenerateParityInfo2(textData);

    file.close();

    metaFile.open("DISK "+to_string(nDisk)+"/Block "+to_string(numBlock)+"/"+fileName+"p_Metadata.text",ios::out);// Abre archivo
    metaFile << "Parity info from book: "+fileName+"\n";
    metaFile.close();
}


void escribir3(string fileName){

    ofstream archivo;

    archivo.open("./Archivos/"+fileName+".text",ios::out);// Abre archivo

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    archivo << "ABCDEF";

    archivo.close();
}

void escribir10(string c1,string c2,string c3,string c){

    ofstream archivo;

    archivo.open("Cc1.text",ios::out);// Abre archivo

    archivo << c1;

    archivo.close();

    archivo.open("Cc2.text",ios::out);// Abre archivo

    archivo << c2;

    archivo.close();

    archivo.open("Cc3.text",ios::out);// Abre archivo

    archivo << c3;

    archivo.close();

    archivo.open("Cc.text",ios::out);// Abre archivo

    archivo << c;

    archivo.close();

}
void ReadAndDivide2(string path, string fileName){
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

    switch (contBookPart2) {
    case 4:
        order2[0] = 1;
        order2[1] = 2;
        order2[2] = 3;
        order2[3] = 4;
        numFile2 = 1;
        break;
    case 5:
        order2[0] = 1;
        order2[1] = 2;
        order2[2] = 4;
        order2[3] = 3;
        numFile2 = 2;
        break;
    case 7:
        order2[0] = 1;
        order2[1] = 4;
        order2[2] = 2;
        order2[3] = 3;
        numFile2 = 3;
        break;
    case 8:
        order2[0] = 4;
        order2[1] = 1;
        order2[2] = 2;
        order2[3] = 3;
        numFile2 = 4;
        break;
    }
    //cout << "ES EL DISKO NUM > > > " << contBookPart << endl;
    for (int l = 0;l<4;l++){
        cout << order2[l] << endl;
    }

    int contDisk = 1;
    if (numFile2>0 && numFile2<=4){
        while (content<texto.length()+1) {// mientras no sea el final del archivo
            if (content == texto.length()){

                for (int s = 0;s<4;s++){
                    if (order2[s] == contDisk){
                        cout << "Parte " << contDisk << " va para el disk " << s+1 << endl;
                        write2(path,fileName,part,partNum,s+1);
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
                    if (order2[r] == contDisk){
                        cout << "Parte " << contDisk << " va para el disk " << r+1 << endl;
                        write2(path,fileName,part,partNum,r+1);
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
            if (order2[u] == 4){
                cout << "Info Paridad va para el disk " << u+1 << endl;
                writeParity2(fileName,texto,u+1);
                //contDisk++;
                break;
            }
        }
    }
    contBookPart2++;
    numFile2 = 0;
    archivo.close();

}
void agregar(){
    ofstream archivo;

    archivo.open("Archivos/p1.text",ios::app);

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    archivo << "Bien";

    archivo.close();

}
//
// to map each character its huffman value
map<char, string> codes3;

// to store the frequency of character of the input data
map<char, int> freq3;

string Search2(string Book){
    string Found;

    for (int nD = 1;nD<5;nD++){
        //cout << "num disco " << nD << endl;
        for (int nB = 2;nB<6;nB++){
            //cout << "num Bloque " << nB << endl;
            ifstream archivo;
            string texto;
            string Book2;
            for (int nF = 0;nF<2;nF++) {

                for (int nP = 1;nP<4;nP++) {
                    archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nP)+"_Metadata.text",ios::in);
                    if (!archivo.fail()){
                        //cout << "PASO 2" << endl;
                        ifstream archivo2;
                        string texto2;

                        archivo2.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nP)+".text",ios::in);
                        getline(archivo2,texto2);

                        for (int nC = 0;nC<texto2.length();nC++){
                            Found+=texto2[nC];
                        }
                        break;
                    }
                }
                //archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nF)+"_Metadata.text",ios::in);

            }
            /*
            for (int nF = 1;nF<4;nF++){
                //cout << "numero" << endl;
                cout <<
                archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nF)+"_Metadata.text",ios::in);
                if (!archivo.fail()){
                    //cout << "PASO 2" << endl;
                    ifstream archivo2;
                    string texto2;

                    archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nF)+".text",ios::in);
                    getline(archivo2,texto2);

                    for (int nC = 0;nC<texto2.length();nC++){
                        Found+=texto2[nC];
                    }
                }
            }*/


        }
    }
    cout << "EL COMPILADO ES " << Found << endl;
    return Found;
}
QStringList parts;
string Restore(string Book){
    string Found;
    string Fp1;
    string Fp2;
    string Fp3;
    string Fpp;
    for (int nD = 1;nD<5;nD++){
        //cout << "num disco " << nD << endl;
        for (int nB = 2;nB<6;nB++){
            //cout << "num Bloque " << nB << endl;
            ifstream archivo;
            ifstream archivo3;
            string texto;
            string Book2;
            for (int nF = 0;nF<2;nF++) {

                for (int nP = 1;nP<4;nP++) {
                    archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nP)+"_Metadata.text",ios::in);
                    if (!archivo.fail()){
                        //cout << "PASO 2" << endl;
                        ifstream archivo2;
                        string texto2;

                        archivo2.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nP)+".text",ios::in);
                        getline(archivo2,texto2);
                        if (nP==1){
                            for (int nC = 0;nC<texto2.length();nC++){
                                Fp1+=texto2[nC];
                            }
                            cout << "Fp" << nP << Fp1 << endl;
                            break;

                        }
                        if (nP==2){
                            for (int nC = 0;nC<texto2.length();nC++){
                                Fp2+=texto2[nC];
                            }
                            cout << "Fp" << nP << Fp2 << endl;
                            break;
                        }
                        if (nP==3){
                            for (int nC = 0;nC<texto2.length();nC++){
                                Fp3+=texto2[nC];
                            }
                            cout << "Fp" << nP << Fp3 << endl;
                            break;
                        }
                    }
                }
                archivo3.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+"p_Metadata.text",ios::in);
                if (!archivo3.fail()){
                    //cout << "PASO 2" << endl;
                    ifstream archivo4;
                    string texto4;

                    archivo4.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+"p_.text",ios::in);
                    getline(archivo4,texto4);

                    for (int nC = 0;nC<texto4.length();nC++){
                        Fpp+=texto4[nC];
                    }
                    cout << "Fpp" << Fpp << endl;
                    break;
                }
                //archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nF)+"_Metadata.text",ios::in);

            }

        }
    }
    //cout << Fp1 << " " << Fp2 << " " << Fp3 << " " << Fpp << endl;
    for (int nD = 1;nD<5;nD++){
        //cout << "num disco " << nD << endl;
        for (int nB = 2;nB<6;nB++){
            //cout << "num Bloque " << nB << endl;
            ifstream archivo;
            ifstream archivo3;
            string texto;
            string Book2;
            for (int nF = 0;nF<2;nF++) {

                for (int nP = 1;nP<4;nP++) {
                    archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+"p_Metadata.text",ios::in);
                    if (!archivo.fail()){
                        //cout << "PASO 2" << endl;
                        ifstream archivo2;
                        string texto2;

                        archivo2.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+"p.text",ios::in);
                        getline(archivo2,texto2);
                        for (int nC = 0;nC<texto2.length();nC++){
                            Fpp+=texto2[nC];
                        }
                        cout << "Fpp" << Fpp << endl;
                        break;
                    }
                }

                //archivo.open("DISK "+to_string(nD)+"/Block "+to_string(nB)+"/"+Book+to_string(nF)+"_Metadata.text",ios::in);
            }

        }
    }
    string bytes[4];
    bytes[0]=Fp1;
    bytes[1]=Fp2;
    bytes[2]=Fp3;
    bytes[3]=Fpp;
    string parts2[3];
    int cont = 0;
    for (int v = 0;v<4;v++){
        if (bytes[v]!=""){
            parts2[cont]=bytes[v];
            cont++;
        }
    }
    cout << parts2[0] << " " << parts2[1] << " " << parts2[2] << " end" << endl;
    return ParityXor(parts2[0], parts2[1], parts2[2]);
    //return "1";
}
// A Huffman tree node
struct MinHeapNode
{
    char data;             // One of the input characters
    int freq;             // Frequency of the character
    MinHeapNode *left, *right; // Left and right child

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// utility function for the priority queue
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

// utility function to print characters along with
// there huffman value
void printCodes3(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes3(root->left, str + "0");
    printCodes3(root->right, str + "1");
}

// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void storeCodes2(struct MinHeapNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes3[root->data]=str;
    storeCodes2(root->left, str + "0");
    storeCodes2(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap3;

// function to build the Huffman tree and store it
// in minHeap
void HuffmanCodes2(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq3.begin(); v!=freq3.end(); v++) {

        minHeap3.push(new MinHeapNode(v->first, v->second));
        cout << "FIRST " << v->first << " SECOND " << v->second << endl;
    }
    while (minHeap3.size() != 1)
    {
        left = minHeap3.top();
        minHeap3.pop();
        right = minHeap3.top();
        minHeap3.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap3.push(top);
    }
    storeCodes2(minHeap3.top(), "");
}

// utility function to store map each character with its
// frequency in input string
void calcFreq2(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq3[str[i]]++;
}

// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string decode_file2(struct MinHeapNode* root, string s)
{
    //cout << minHeap. << endl;
    string ans = "";
    struct MinHeapNode* curr = root;
    cout << root->left->left->right->data << " <<< " << endl;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;

        // reached leaf node
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans+'\0';
}
string SocketCliente::DecodeMsg2(string msg){
    string str = msg;
    string encodedString, decodedString;
    calcFreq2(str, str.length());
    HuffmanCodes2(str.length());
    cout << "Character With there Frequencies:\n";
    for (auto v=codes3.begin(); v!=codes3.end(); v++)
        cout << v->first <<' ' << v->second << endl;

    for (auto i: str)
        encodedString+=codes3[i];

    decodedString = decode_file2(minHeap3.top(), encodedString);
    cout << "\To Code:\n" << decodedString << endl;

    cout << "\nSended coded:\n" << encodedString << endl;


    return decodedString;
//
}

SocketCliente::SocketCliente()
{

}

bool SocketCliente::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = ntohs(8000);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
     return false;

    pthread_t hilo;
    pthread_create(&hilo,0,SocketCliente::controlador,(void *)this);
    pthread_detach(hilo);
    return true;
}


void * SocketCliente::controlador(void *obj)
{
    SocketCliente *padre = (SocketCliente*)obj;

    while (true) {
        string mensaje;
        while (1) {
            char buffer[10] = {0};
            int bytes = recv(padre->descriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(bytes <= 0)
            {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 1)
                break;
        }
        emit padre->NewMensaje(QString::fromStdString(mensaje));
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}

char strToChar(const char* str) {
    char parsed = 0;
    char parsed2 = 0;
    for (int i = 0; i < 48; i++) {
        if (str[i] == '1') {
            parsed |= 1 << (47 - i);
        }
        parsed2+=parsed;
    }
    return parsed2;
}

void SocketCliente::setMensaje(const char *msn)
{
   // char *mensaje = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: keep-alive\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.94 Safari/537.36\r\nX-Client-Data: CIm2yQEIorbJAQiptskBCLiIygEI3pbKAQ==\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: es-419,es;q=0.8,en;q=0.6\r\n\n";


    string message = DecodeMsg2(msn);
    string msnn = msn;

    if (msnn[msnn.length()-1] == '/'){
        IndexBooks2(msn);
    } else if (msnn[msnn.length()-1] == 'R') {
        string msn2;
        string msn3;
        for (int g = 0;g<msnn.length();g++){
            if (msn[g] != 's'){
                msn2+=msn[g];
            } else {

                msn3 = Restore(msn2);
                break;
            }
        }
        cout << "EL msn " << msn3 << endl;
        //cout << m2 << endl;

        cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;

        string m1,m2,m3,temp;


        for (int s = 0;s<48;s++){
            if (s==15){
                temp+=msn3[s];
                m1+=temp;
                temp="";
            } else if (s==31){
                temp+=msn3[s];
                m2+=temp;
                temp="";
            } else if (s==47){
                temp+=msn3[s];
                m3+=temp;
                temp="";
            } else {
                temp+=msn3[s];
            }
        }

        string data = m1+m2+m3;
        stringstream sstream(data);
        string output;
        while(sstream.good())
        {
            std::bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }
        cout << m1 << endl;
        cout << m2 << endl;

        cout << m3 << endl;
        cout << output << endl;

        escribir10(m1,m2,m3,output);
        cout << "llega aqui2" << endl;



    } else {
        //Search2("A");

        string msn2;
        string msn3;
        for (int g = 0;g<msnn.length();g++){
            if (msn[g] != 's'){
                msn2+=msn[g];
            } else {

                msn3 = Search2(msn2);
                break;
            }
        }
        cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;

        string m1,m2,m3,temp;


        for (int s = 0;s<48;s++){
            if (s==15){
                temp+=msn3[s];
                m1+=temp;
                temp="";
            } else if (s==31){
                temp+=msn3[s];
                m2+=temp;
                temp="";
            } else if (s==47){
                temp+=msn3[s];
                m3+=temp;
                temp="";
            } else {
                temp+=msn3[s];
            }
        }

        string data = m1+m2+m3;
        stringstream sstream(data);
        string output;
        while(sstream.good())
        {
            std::bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }

        cout << output << endl;

        escribir10(m1,m2,m3,output);
        cout << "llega aqui" << endl;
    }
    //IndexBooks2(msn);


}
