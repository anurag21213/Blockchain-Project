#include<vector>
#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include "Block.h"
#include "TransactionData.h"
#include "Block.h"
using namespace std;
Block::Block(int ind, TransactionData d, size_t prevHash)
{
    index = ind;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}
int i=0;
int Block::getindex(){
    return i++;
}
size_t Block::generateHash()
{   
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey +to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
}

size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getpreviousHash()
{
    return previousHash;
}
bool Block::isHashValid()
{
    return generateHash() == getHash();
}