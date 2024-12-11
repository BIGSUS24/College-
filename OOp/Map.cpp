#include <iostream>
#include <map>
using namespace std;
int main()
{   map<string, int> mp;
    mp["mh"] = 1001;
    mp["up"] = 2025;
    mp["bhihar"] = 5643;
    map<string, int>::iterator it;
	for(it=mp.begin();it != mp.end();it++)
	 { cout<<"Key ==> "<<it->first<<" \t value:==> " <<it->second<<endl;
      }
    return 0;
}
