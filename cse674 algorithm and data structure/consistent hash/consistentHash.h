#include<map>
using namespace std;

class ConsistentHash{
public:
   ConsistentHash( int nodeNum, int virtualNodeNum);
   ~ConsistentHash();
   
   void Initialize();
   size_t GetServerIndex(const char* key);
   
   void DeleteNode(const int index);
   void AddNewNOde(const int index);
private:
  map<uint32_t, size_t> serverNodes;
  int nodeNum;
  int virtualNodeNum;

};