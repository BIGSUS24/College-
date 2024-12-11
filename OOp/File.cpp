#include<iostream>
#include<fstream>
using namespace std;

class test
{
public:
	void writedata()
{  fstream fp;
 char ch;
 fp.open("it.txt",ios::out);
 cin>>ch;
 while (ch!='.')
 {
 fp.put(ch);
 cin>>ch;
 }
fp.close();
}
void readdata()
{
	fstream fp;
	char ch;
	fp.open("it.txt",ios::in);
ch=fp.get();
while(!fp.eof())
{
cout<<ch;
ch=fp.get(); 
}
fp.close();
}
};
int main()
{
  test ob;
  int ch;
  do
  {
   cout<<"\n1.Write\n2.Read";
   cout<<"\nEnter your choice= ";
   cin>>ch;
   switch(ch)
   {
    case 1:
	ob.writedata();
    break;
    case 2:
	ob.readdata();
    break;
   }
  }while(ch<3);
}
