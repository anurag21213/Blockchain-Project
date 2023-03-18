//#include<iostream>
//#include<mysql.h>
//#include<mysqld_error.h>
//#include<bits/stdc++.h>
////#include<ctime>
//#include "TransactionData.h" 
//#include "Block.h"
//#include "Blockchain.h"
//#include "Blockchain.cpp"
//#include "Block.cpp"
//#include "TransactionData.cpp"
//char HOST[]="localhost";
//char USER[]="root";
//char PASS[]="#blockguru";
//int main() {
//	MYSQL* obj;
//    Blockchain Awesomecoin;
//    Awesomecoin.printchain();
//    time_t data1Time;
//	TransactionData data1;
//	int Block_Id;
//	int Amount;
//	char Sender[25];
//	char Receiver[25];
//	bool programisopened=true;
//	int ans;
//	char* consult;
//	char* sentence;
//	string sentence_aux;
//	
//	if(!(obj=mysql_init(0))){
//		cout<<"Error My sql Object could not be crated"<<endl;
//	}
//	else{
//		if(!mysql_real_connect(obj,HOST,USER,PASS,"block",3306,NULL,0)){
//			cout<<"Error some database info is wrong or do not exist"<<endl;
//			cout<<mysql_error(obj)<<endl;
//		}
//		else{
//			cout<<"Logged In"<<endl;
//			while(programisopened){
//				cout<<"Block_ID"<<endl;
//				cin>>Block_Id;
//				cin.ignore(100,'\n');
//				cout<<"Amount is:"<<endl;
//				cin>>Amount;
//			    data1.amount=Amount;
//				cin.ignore(100,'\n');
//				cout<<"Senders key:"<<endl;
//				cin.getline(Sender,25,'\n');
//			     data1.senderKey=Sender;
//				cout<<"Receivers key:"<<endl;
//				cin.getline(Receiver,25,'\n');
//			     data1.receiverKey=Receiver;
//				 data1.timestamp=time(&data1Time);
//				sentence_aux="INSERT INTO DATA(Block_Id,Amount,Sender,Receiver) VALUES('%d','%d','%s','%s')" ;
//				sentence=new char [sentence_aux.length()+1];
//				strcpy(sentence,sentence_aux.c_str());
//				
//				
//				consult=new char[strlen(sentence)+sizeof(int)+sizeof(int)+strlen(Sender)+strlen(Receiver)];
//				sprintf(consult,sentence,Block_Id,Amount,Sender,Receiver);
//      			Awesomecoin.addBlock(data1);
//				if(Awesomecoin.isChainValid()){
//     				Awesomecoin.printchain();		
//				}
////				else{
////					cout<<"Chain is not valid: "<<endl;
////				}
////			    Block *hackBlock=Awesomecoin.getLatestBlock();
////	       		hackBlock->data.amount=56;
////    			hackBlock->data.receiverKey="Johhny";
////    			if(Awesomecoin.isChainValid()){
////    				Awesomecoin.printchain();
////				}
////				else{
////					cout<<"Chain is not valid"<<endl;
////				}
//				if(mysql_ping(obj)){
//					cout<<"Error impossible to connect"<<endl;
//					cout<<mysql_error(obj)<<endl;
//				}
//				if(mysql_query(obj,consult)){
//					cout<<"Error:"<<mysql_error(obj)<<endl;
//					rewind(stdin);
//					getchar();
//				}
//				else{
//					cout<<"Info added correctly"<<endl;
//				}
//				
//				mysql_store_result(obj);
//				
//				cout<<endl<<"Another?"<<endl;
//				cout<<"[1]:Yes"<<endl;
//				cout<<"[0]:No"<<endl;
//				cout<<"Answer: ";
//				
//				cin>>ans;
//				
//				cin.ignore(100,'\n');
//				
//				if(ans==0){
//					programisopened=false;
//				}
//				
//				cout<<endl;
//				
//			}
//		}
//	}
//	
//	cout<<"Bye"<<endl;
//	
//	return 0;
//}
