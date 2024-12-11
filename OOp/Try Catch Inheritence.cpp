# include<iostream>
# include<stdio.h>
# include<string.h>
using namespace std;
class publication                 // declaring class Publication
 {
 protected:
 char title[20];
 float price;
 public:
 void add()
 {
 cout << "\nEnter the Publication information : " << endl;
 cout << "\nEnter Title of the Publication : ";
cin>>title;
cout << "\nEnter Price of Publication : ";
 cin >> price;
 }
 void display()
 {
 cout << "\nTitle of Publication : " << title;
 cout << "\nPublication Price : " << price;
 }
 };
 class book : public publication  // declaring class book which inherits class publication in public mode.
 {
 private:
 	int page_count;
 	public:
	book()
	{
		page_count=0;
	}
		void add_book()
 		{
 			try
 			{
 				add();
				cout << "\nEnter Page Count of Book : ";
 				cin >> page_count;
 				if (page_count <= 0)
 				{
 					throw page_count;
 				}
 			}
 			catch(...)
 			{
 				cout << "\nException is caught for Invalid Page Count!!!";
 				price=0.0;
 				strcpy(title,"NULL");
				 page_count = 0;
				 display();
				 display_book();
 			}
 	}
 
 		void display_book()
 		{   
 			cout << "\nPage Count : " <<page_count;
 		}
 };
 class tape : public publication     // declaring class tape which inherits class publication in public mode
 {
 	private:
 			float play_time;
 	public:
 		void add_tape()
 		{
 			try
 			{
 				cout <<"\nEnter Play Duration of the Tape : ";
 				cin >> play_time;
 				if (play_time <= 0)
 					throw play_time;
 			}
 			catch(...)
 			{
 				cout << "\nException is caught for Invalid Play Time!!!";
 					price=0.0;
 				strcpy(title,"NULL");
 				play_time = 0;
 				display_tape();
 				
 			}
 		}
 		void display_tape()
 		{       cout << "\nPlay Time : " <<
				play_time << " min";
 		}
 };


int main()
{
	book b1;
	tape t1;
	int choice;
	do{
		
			cout<<"\n\n Press 1 to buy a book and  a tape :";
		cout<<"\n\n Press 2 to display book  display tape :";
		cout<<"\n\n Press 3 for exit";
		cout<<"\n\n Enter your choice";
		cin>>choice;
	switch(choice)
	{
		case 1: try
		{
			b1.add_book();
			t1.add_tape();
			break;
		}
		catch(int i){
			cout<<"\nCaught exception in int main()"<<endl;	}	
		
		
		case 2: b1.display();
			    b1.display_book();
				t1.display_tape(); break;
		case 3: exit(0); break;

default:cout<<"\nEntered bad choice!! Try again!!"<<endl;
}
}while(choice<3);
return 0;
}
