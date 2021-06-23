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

    // utility function to print characters along with
    // there huffman value
    void printCodes(struct MinHeapNode* root, string str);

    // utility function to store characters along with
    // there huffman value in a hash table, here we
    // have C++ STL map
    void storeCodes(struct MinHeapNode* root, string str);

    // function to build the Huffman tree and store it
    // in minHeap
    void HuffmanCodes(int size);

    // utility function to store map each character with its
    // frequency in input string
    void calcFreq(string str, int n);

    // function iterates through the encoded string s
    // if s[i]=='1' then move to node->right
    // if s[i]=='0' then move to node->left
    // if leaf node append the node->data to our output string
    string decode_file(struct MinHeapNode* root, string s);


};

#endif // HUFFMAN_H
