#include<stdio.h>
#include<ctime>
#include "Block.h"
#include "Blockchain.h"
#include "TransactionData.h"
#include<vector>
#include<string>
using namespace std;
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

std::vector<Block>Blockchain::getchain(){
    return chain;
}
Block Blockchain::createGenesisBlock()
{
    time_t current;
    TransactionData d(0,"NONE","NONE",time(&current));
    std::string tohash=std::to_string(d.amount)+d.senderKey+d.receiverKey+std::to_string(d.timestamp);
    std::hash<std::string>tdatahash;
    std::hash<std::string>prevhash;
    size_t hash=tdatahash(tohash)^(prevhash(std::to_string(0))<<1);
    Block genesis(0, d, hash);

    return genesis;
}
Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}
void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size() ;
     size_t previousHash=((int)chain.size()>0 ? getLatestBlock()->getHash() :0);
     Block newBlock(index, d, previousHash);
     chain.clear();
     chain.push_back(newBlock);
}
bool Blockchain::isChainValid()
{
    vector<Block>::iterator it;
    int chainLen = (int)chain.size()-1;

    for (it = chain.begin(); it != chain.end(); it++)
    {
        Block currentBlock = *it;

        if (!currentBlock.isHashValid())
        {
            // invalid
            return false;
        }

        if (chainLen>1)
        {
            Block previousBlock = *(it - 1);
            if (previousBlock.getpreviousHash() != previousBlock.getHash())
            {
                // invalid
                return false;
            }
        }
    }

    return true;
}
void Blockchain::printchain(){
    vector<Block>::iterator it;
    for(it=chain.begin();it!=chain.end();it++){
        Block currentBlock=*it;
        cout<<endl;
        cout<<"NEW BLOCK"<<endl;
        cout<<"Block id ***** "<<endl;
        cout<<"Id of the current block is: "<<currentBlock.getindex()<<endl;
        cout<<"HASH of the current block is: "<<currentBlock.getHash()<<endl;
        cout<<"Hash of the previous block is : "<<currentBlock.getpreviousHash()<<endl;
        cout<<"Is the current hash valid: "<<currentBlock.isHashValid()<<endl;
        cout<<"Amount :"<<currentBlock.data.amount<<endl;
        cout<<"Senders key is: "<<currentBlock.data.senderKey.c_str()<<endl;
        cout<<"Receivers key is: "<<currentBlock.data.receiverKey.c_str()<<endl;
        cout<<"Time stamp :"<<currentBlock.data.timestamp<<endl;
        cout<<endl;
        cout<<endl;
    }
}