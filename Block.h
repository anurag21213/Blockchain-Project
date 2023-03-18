#ifndef Block_h
#define Block_h
#include "TransactionData.h"
#include<vector>
class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

public:
    Block(int ind, TransactionData d, size_t prevHash);

    size_t getHash();
    int getindex();
    size_t getpreviousHash();

    TransactionData data;

    bool isHashValid();
};
#endif