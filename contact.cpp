#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

string finame,laname,phoneNumber,address;

void addcontact();
void searchcontact();
void help();
void selfexit();
bool check_digits(string);
bool check_number(string);

void addcontact()
{
  ofstream phone("number.txt", ios::app);
  system("cls");
  cout<<"\n\n\tEnter First Name:";
  cin>>finame;
  cout<<"\n\n\tEnter Last Name:";
  cin>>laname;
  cout<<"\n\n\tEnter Full Address:";
  cin>>address;
  cout<<"\n\n\tEnter 11-Digit Phone Number:";
  cin>>phoneNumber;

  if(check_digits(phoneNumber)==true)
  {
    if(check_number(phoneNumber)==true)
	{
	if(phone.is_open())
    {
        phone<<finame<<" "<<laname<<" "<<address<<" "<<phoneNumber<<" "<<endl;
        cout<<"\n\tContact Saved Successfully!";
    }
}
    else
    {
        cout<<"\n\tError Opening File!";
    }
  }
  else
  {
    cout<<"\n\tPhone Number Must Contain 11 Digits.";
  }
 phone.close();
}

void searchcontact()
{
	bool found=false;
   ifstream myfile("number.txt");
   string keyword;
   cout<< " \n\tEnter Name To Search:";
   cin>> keyword;
   while(myfile >> finame >> laname >> address >> phoneNumber)
   {
   	if(keyword==finame || keyword==laname) 
   	{
   		system("cls");
   		cout<<"\n\n\n\t\tContact Details...";
   		cout<<"\n\n\tFirst Name: "<< finame;
   		cout<<"\n\tLast Name: "<<laname;
   		cout<<"\n\tAddress: "<<address;
   		cout<<"\n\tPhone Number :"<<phoneNumber;
   		found=true;
   		break;
 }
}
        if(found==false)
        {
        cout<<"\n\tNo Such Contact Found";
		}
}

void help()
{
  cout<<"This displays help";
}

void selfexit()
{
  system("cls");
  cout<<"\n\n\n\t\tThank You For Using!";
  exit(1);
}

bool check_digits(string a)
{
    if(a.length()==11)
        return true;
    else
        return false;
}

bool check_number(string x)
{
	bool check=true;
	
	for(int i=0;i<x.length();i++)
	{
		if(!(int(x[i])>=48&&int(x[i])<=57))
		{
			check=false;
			break;
		}
	}
	if(check==true)
	return true;
	if(check==false)
	return false;
}
int main()
{
    short int choice;
	system("cls");
	system("color 0B");
	cout << "\n\n\t\tContact Management";
	cout<< "\n\t__________________________________";
	cout << "\n\n\t 1. Add Contact\n\t 2. Search Contact\n\t 3. Help\n\t 4. Exit\n\t>";
	cin >> choice;

	switch (choice)
	{
	case 1:
		addcontact();
		break;
	case 2:
		searchcontact();
		break;
	case 3:
		help();
		break;
	case 4:
		selfexit();
		break;
	default:
		cout << "\n\n\tInvalid Input!";
		cout << "\n\tPress Any Key To Continue..";
		getch();
		main();
	}
   return 0;
}

