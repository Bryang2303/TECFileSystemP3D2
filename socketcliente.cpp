#include "socketcliente.h"


//
// to map each character its huffman value
map<char, string> codes3;

// to store the frequency of character of the input data
map<char, int> freq3;

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
    info.sin_port = ntohs(4050);
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
            if(bytes < 10)
                break;
        }
        emit padre->NewMensaje(QString::fromStdString(mensaje));
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}


void SocketCliente::setMensaje(const char *msn)
{
   // char *mensaje = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: keep-alive\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.94 Safari/537.36\r\nX-Client-Data: CIm2yQEIorbJAQiptskBCLiIygEI3pbKAQ==\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: es-419,es;q=0.8,en;q=0.6\r\n\n";

    cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;
    DecodeMsg2(msn);

}
