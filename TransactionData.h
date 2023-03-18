#ifndef TransactionData_h
#define TransactionData_h
#include<bits/stdc++.h>
struct TransactionData
{
    int amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;

    TransactionData(){};
    TransactionData(int amt,std::string senders,std::string receiver,time_t time){
        amount=amt;
        senderKey=senders;
        receiverKey=receiver;
        timestamp=time;
};
};
#endif
