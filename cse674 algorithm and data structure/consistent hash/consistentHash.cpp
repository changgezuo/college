#include<consistentHash.h>
#include<string>
#include<sstream>
#include"murmurhash3.h"
using namespace std;
ConsistenetHash::ConsistenetHash(int nodeNumInput, int virtualNodeNumInput){
    nodeNum = nodeNumInput;
	virtualNodeNum = virtualNodeNumInput;
}

ConsistenetHash::~ConsistenetHash(){
    serverNodes.clear();
}

void ConsistenetHash::Initialize(){
   for( int i = 0; i < nodeNum; ++i ) {
       for(int j = 0; j < virtualNodeNum; ++j ) {
	       stringstream nodeKey;
		   nodeKey<<"SHARD-"<<i<<"-NODE-"<<j;
		   uint32_t partition = murmur3_32(nodeKey.str().c_str(), strlen(nodeKey.str().c_str()));
		   serverNodes.insert(pair<uint32_t, size_t>(partition, i));  
	   }
   }
}

size_t ConsistenetHash::GetServerIndex(const char* key){
    uint32_t partition = murmur3_32(key, stelen(key));
	map<uint32_t, size_t>::iterotor it = serverNodes.lower_bound(partition));
	
	if(it ==serverNodes.end()){
	    return serverNodes.begin()->second;
	}
	return it->second;
}

void ConsistenetHash::DeleteNode(const int index){
   for(int j = 0; j < virtualNodeNum; ++j){
       stringstream nodeKey;
	   nodeKey<<"SHARD-"<<index<<"-NODE-"<<j;
	   uint32_t partition = murmur3_32(nodeKey.str().cstr(), strlen(nodeKey.str().cstr());
	   map<uint32_t, size_t>::iterotor it = serverNodes.lower_bound(partition));
	
	   if(it !=serverNodes.end()){
	       serverNodes.erase(it);
	   }
   }
}
void ConsistenetHash::AddNewNode(const int index){
   for(int j = 0; j < virtualNodeNum; ++j){
       stringstream nodeKey;
	   nodeKey<<"SHARD-"<<i<<"-NODE-"<<j;
	   uint32_t partition = murmur3_32(nodeKey.str().c_str(), strlen(nodeKey.str().c_str()));
	   serverNodes.insert(pair<uint32_t, size_t>(partition, i)); 
   }
}

int main(){
	
	ConsistenetHash ch(4, 1000);
	ch.init();
	for(int i =0; i < 10; ++i){
		stringstream ss;
		ss<<"test"<<i<<".txt";
		size_t size = ch.GetServerIndex(ss.str());
		cout<<ss.str()<<"===>";
		cout<<size<<endl;	
		
	}
	return 0;
	
}