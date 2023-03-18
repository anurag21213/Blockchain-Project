#ifndef Blockchain_h
#define Blockchain_h
#include "Block.h"
#include<vector>
class Blockchain
{
private:
    Block createGenesisBlock();
     std::vector<Block>chain;
public:
    // constructor
    Blockchain();
    std::vector<Block>getchain();
    // public functions

    void addBlock(TransactionData data);
    bool isChainValid();
    Block *getLatestBlock();
    void printchain();

};

#endif