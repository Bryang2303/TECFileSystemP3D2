#include "controllernode.h"
#include "filesmanagement.h"

string ParityXnor(string p1, string p2, string p3){
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

void OddParityBit(string bitChain){
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

string GenerateParityInfo(string data){
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




void escribir(string path);
void ReadAndDivide(string path, string fileName);
void agregar();
void write(string newPath, string fileName, string textPart,int partNum,int nDisk);


int contBookPart = 1;
int order[4];
int numFile;
int numBlockD1 = 2;
int numBlockD2 = 2;
int numBlockD3 = 2;
int numBlockD4 = 2;


int IndexBooks(string path) {
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
void write(string newPath, string fileName, string textPart,int partNum, int nDisk){

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
        numBlock = numBlockD1;
        cout << "El block numero " << numBlock << endl;
        numBlockD1++;
        break;
    case 2:
        numBlock = numBlockD2;
        numBlockD2++;
        break;
    case 3:
        numBlock = numBlockD3;
        numBlockD3++;
        break;
    case 4:
        numBlock = numBlockD4;
        numBlockD4++;
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

void writeParity(string fileName, string textData,int nDisk){

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
        numBlock = numBlockD1;
        cout << "El block numero " << numBlock << endl;
        numBlockD1++;
        break;
    case 2:
        numBlock = numBlockD2;
        numBlockD2++;
        break;
    case 3:
        numBlock = numBlockD3;
        numBlockD3++;
        break;
    case 4:
        numBlock = numBlockD4;
        numBlockD4++;
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


void escribir(string fileName){

    ofstream archivo;

    archivo.open("./Archivos/"+fileName+".text",ios::out);// Abre archivo

    if (archivo.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
    archivo << "ABCDEF";

    archivo.close();
}
void ReadAndDivide(string path, string fileName){
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

    switch (contBookPart) {
    case 4:
        order[0] = 1;
        order[1] = 2;
        order[2] = 3;
        order[3] = 4;
        numFile = 1;
        break;
    case 5:
        order[0] = 1;
        order[1] = 2;
        order[2] = 4;
        order[3] = 3;
        numFile = 2;
        break;
    case 7:
        order[0] = 1;
        order[1] = 4;
        order[2] = 2;
        order[3] = 3;
        numFile = 3;
        break;
    case 8:
        order[0] = 4;
        order[1] = 1;
        order[2] = 2;
        order[3] = 3;
        numFile = 4;
        break;
    }
    //cout << "ES EL DISKO NUM > > > " << contBookPart << endl;
    for (int l = 0;l<4;l++){
        cout << order[l] << endl;
    }

    int contDisk = 1;
    if (numFile>0 && numFile<=4){
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
    contBookPart++;
    numFile = 0;
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
map<char, string> codes;

// to store the frequency of character of the input data
map<char, int> freq;

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
void printCodes2(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes2(root->left, str + "0");
    printCodes2(root->right, str + "1");
}

// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void storeCodes(struct MinHeapNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// function to build the Huffman tree and store it
// in minHeap
void HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) {

        minHeap.push(new MinHeapNode(v->first, v->second));
        cout << "FIRST " << v->first << " SECOND " << v->second << endl;
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

// utility function to store map each character with its
// frequency in input string
void calcFreq(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}

// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string decode_file(struct MinHeapNode* root, string s)
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
string ControllerNode::DecodeMsg(string msg){
    string str = msg;
    string encodedString, decodedString;
    calcFreq(str, str.length());
    HuffmanCodes(str.length());
    cout << "Character With there Frequencies:\n";
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;

    for (auto i: str)
        encodedString+=codes[i];

    cout << "\nReceived:\n" << encodedString << endl;

    decodedString = decode_file(minHeap.top(), encodedString);
    cout << "\nDecoded:\n" << decodedString << endl;
    return decodedString;
//
}
ControllerNode::ControllerNode()
{
    IndexBooks("./Archivos/");
}


bool ControllerNode::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool ControllerNode::ligar_kernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,5);
    return true;
}


void ControllerNode::run()
{
    if(!crear_Socket())
        throw string("Error al crear el socket");
    if(!ligar_kernel())
        throw string("Error al  ligar kernel");

    while (true) {
        cout << "Esperando nuevo cliente"<<endl;
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor < 0)
            cout << "Error al acceptar al cliente"<<endl;
        else
        {
            clientes.push_back(data.descriptor);
            pthread_t hilo;
            pthread_create(&hilo,0,ControllerNode::controladorCliente,(void *)&data);
            pthread_detach(hilo);
        }
    }
    close(descriptor);
}



void * ControllerNode::controladorCliente(void *obj)
{
    dataSocket *data = (dataSocket*)obj;
    while (true) {
        string mensaje;
        while (1) {
            char buffer[100] = {0};
            int bytes = recv(data->descriptor,buffer,100,0);
            mensaje.append(buffer,bytes);
            if(bytes < 100)
                break;
        }
        if (mensaje!=""){
            string msgDecoded = DecodeMsg(mensaje);
            cout << msgDecoded << endl;

            if (msgDecoded[msgDecoded.length()-2] == '/'){
                FilesManagement *fm;
                IndexBooks(msgDecoded);
            }
        }
        //cout << mensaje << endl;


    }

    close(data->descriptor);
    pthread_exit(NULL);
}


void ControllerNode::setMensaje(const char *msn)
{
    for(unsigned int i = 0 ; i < clientes.size() ; i++)
        cout << "bytes enviados, el msn es : " << msn << " >>> " << send(clientes[i],msn,strlen(msn),0);
}
