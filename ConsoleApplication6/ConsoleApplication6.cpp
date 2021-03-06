// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<vector>
#include<conio.h>
using namespace std;
struct market
{
	string name;
	float price, discount, amount;
	int id, q;
}Variable;
vector <market> Product;
bool Filter_Of_String(string &str)
{
	bool b = 0;
	while (str[0] == ' ')
		str.erase(str.begin());
	if (!str.empty())
		while (str[str.size() - 1] == ' ')
			str.pop_back();
	int str_size = str.size();
	for (int i = 0; i < str_size; i++)
	{
		if (str[i] == ' '&&b == 1)
		{
			str.erase(str.begin() + i);
			i--;
			str_size--;
		}
		else if (str[i] == ' ')
			b = 1;
		else
			b = 0;
	}
	if (!str.empty())
		return 1;
	return 0;
}
void Print_String(string Text, int Time)
{
	int Text_size = Text.size();
	for (int i = 0; i < Text_size; i++)
	{
		Sleep(Time);
		cout << Text[i];
	}
}
void Ready()
{
	cout << "\n\n\tSTART";
	cin.get();
	system("cls");
	//Light Red
	system("color 0C");
	cout << "\n\n\t" << 3;
	Sleep(1000);
	system("cls");
	//Light Yellow
	system("color 0E");
	cout << "\n\n\t" << 2;
	Sleep(1000);
	system("cls");
	//Light Green
	system("color 0A");
	cout << "\n\n\t" << 1;
	Sleep(1000);
	system("cls");
	cout << "\n\n\n\n\t ";
	Print_String("....", 200);
	system("color 07");
	system("cls");
	Print_String("\n\n\n\n\t SUPER MARKET BILLING PROJECT HAS BEEN LOADED SUCCESSFULLY", 80);
	for (int i = 0; i < 3; ++i)
	{
		//white
		system("color 07");
		Sleep(500);
		//green
		system("color 0A");
		Sleep(500);
	}
	system("cls");
}
void Team_Programmers()
{
	cout << "\n\n\t\t\t\t\tSUPER MARKET";
	cout << "\n\n\t\t\t\t\t   BILLING";
	cout << "\n\n\t\t\t\t\t   PROJECT";
	cout << "\n\n\t\t\t\t     BY:Team<Programmers>";
	cout << "\n\n\t       Mai Essam";
	cout << "\n\n\n\t\t\t Marwan Mahmoud";
	cout << "\n\n\t\t\t\t\tMerna Mahmoud";
	cout << "\n\n\t\t\t\t\t\t      Nader Sayed";
	cout << "\n\n\t\t\t\t\t\t\t\t  Nourhan Osama";
	//Light_Aqua
	system("color 0B");
	Sleep(1000);
	//Aqua
	system("color 03");
	Sleep(1000);
	//Green
	system("color 02");
	Sleep(1000);
	//Red
	system("color 04");
	Sleep(1000);
	//Light_Yellow
	system("color 0E");
	Sleep(1000);
	//Light_Purple
	system("color 0D");
	Sleep(1000);
	system("cls");
	system("color 70");
	cout << "\n\n\t";
	Print_String("LOADING", 80);
	for (int i = 0; i < 2; ++i)
	{
		//Black
		system("color 70");
		cout << ".";
		Sleep(500);
		//Green
		system("color 72");
		cout << ".";
		Sleep(500);
	}
	system("cls");
}
void Load()
{
	system("color 70");
	ifstream myfile("Super_Market.txt", ios::in);
	int Products_Number = -1;
	do
	{
		Product.push_back(Variable);
		Products_Number++;
	} while (getline(myfile, Product[Products_Number].name), myfile >> Product[Products_Number]
		.id >> Product[Products_Number].price >> Product[Products_Number].discount, myfile.ignore());
	Product.pop_back();
}
void Save()
{
	int Products_Number = Product.size();
	ofstream myfile("Super_Market.txt", ios::out);
	for (int i = 0; i < Products_Number; i++)
		myfile << Product[i].name << "\n" << Product[i].id << "\t"
		<< Product[i].price << "\t" << Product[i].discount << "\n";
}
void Sorting()
{
	int Products_Number = Product.size();
	//Let's sort by the product id
	for (int i = 0; i < Products_Number; i++)
	{
		for (int j = i + 1; j < Products_Number; j++)
		{
			if (Product[i].id > Product[j].id)
			{
				int temp1 = Product[i].id;
				Product[i].id = Product[j].id;
				Product[j].id = temp1;
				float temp2 = Product[i].price;
				Product[i].price = Product[j].price;
				Product[j].price = temp2;
				float temp3 = Product[i].discount;
				Product[i].discount = Product[j].discount;
				Product[j].discount = temp3;
				string temp4 = Product[i].name;
				Product[i].name = Product[j].name;
				Product[j].name = temp4;
			}
		}
	}
}
void Add()
{
	int Products_Number = Product.size(), x;
	while (true)
	{
		bool b = 1;
		cout << "\nPlease Enter The Product No. of The Product ";
		cin >> x;
		for (int i = 0; i < Products_Number; i++)
		{
			if (x == Product[i].id)
			{
				b = 0;
				cout << "\a";
				Print_String("\n\n\tInvalid Input", 80);
				Sleep(1500);
				system("cls");
				break;
			}
		}
		if (b == 1)
			break;
	}
	cin.ignore();
	string s;
	while (true)
	{
		bool b = 1;
		cout << "\nPlease Enter The Name of The Product ";
		getline(cin, s);
		for (int i = 0; i < Products_Number; i++)
		{
			if (s == Product[i].name || !Filter_Of_String(s))
			{
				b = 0;
				cout << "\a";
				Print_String("\n\n\tInvalid Input", 80);
				Sleep(1500);
				system("cls");
				cout << "\nPlease Enter The Product No. of The Product " << x << endl;
				break;
			}
		}
		if (b == 1)
			break;
	}
	Product.push_back(Variable);
	Product[Products_Number].id = x;
	Product[Products_Number].name = s;
	cout << "\nPlease Enter The price of The Product ";
	cin >> Product[Products_Number].price;
	cout << "\nPlease Enter The Discount (%) ";
	cin >> Product[Products_Number].discount;
	Print_String("\n\nThe Product Has Been Created", 80);
	Sleep(2500);
	Sorting();
	Save();
}
void Delete()
{
	int Products_Number = Product.size();
	cout << "\n\tDelete Record\n";
	cout << "\nPlease Enter The product no. of The Product You Want to Delete ";
	int x;
	cin >> x;
	bool b = 0;
	for (int i = 0; i < Products_Number; i++)
	{
		if (x == Product[i].id)
		{
			b = 1;
			Product.erase(Product.begin() + i);
			Print_String("\n\n\tRecord Deleted ..", 80);
			Sleep(2500);
			Products_Number--;
			Save();
			break;
		}
	}
	if (b == 0)
	{
		cout << "\a";
		Print_String("\n\n\tInvalid Input", 80);
		Sleep(1500);
		system("cls");
		Delete();
	}
}
void Modify()
{
	int Products_Number = Product.size();
	cout << "\n\n\tTo Modify\n\n";
	cout << "\tPlease Enter The Product No. To Modify ";
	int x;
	cin >> x;
	bool b = 0;
	for (int i = 0; i < Products_Number; i++)
	{
		if (x == Product[i].id)
		{
			b = 1;
			cout << "\nThe Product No. of The Product : " << Product[i].id;
			cout << "\nThe Name of The Product : " << Product[i].name;
			cout << "\n\nThe Price of The Product :" << Product[i].price;
			cout << "\nDiscount:" << Product[i].discount;
			cout << "\nPlease Enter The New Details of Product";
			cout << "\n\nPlease Enter The Product No. of The Product ";
			while (true)
			{
				bool b2 = 1;
				int x2;
				cin >> x2;
				for (int j = 0; j < Products_Number; j++)
				{
					if (x2 == Product[j].id&&i != j)
					{
						b2 = 0;
						cout << "\a";
						Print_String("\n\n\tInvalid Input", 80);
						Sleep(1500);
						system("cls");
						cout << "\n\n\tTo Modify\n\n";
						cout << "\tPlease Enter The Product No. To Modify " << Product[i].id;
						cout << "\n\nThe Product No. of The Product : " << Product[i].id;
						cout << "\nThe Name of The Product : " << Product[i].name;
						cout << "\n\nThe Price of The Product :" << Product[i].price;
						cout << "\nDiscount:" << Product[i].discount;
						cout << "\nPlease Enter The New Details of Product";
						cout << "\n\nPlease Enter The Product No. of The Product ";
						break;
					}
				}
				if (b2 == 1)
				{
					Product[i].id = x2;
					break;
				}
			}
			cin.ignore();
			cout << "\n\nPlease Enter The Name Of The Product :";
			while (true)
			{
				bool b2 = 1;
				string s;
				getline(cin, s);
				for (int j = 0; j < Products_Number; j++)
				{
					if ((s == Product[j].name&&i != j) || !Filter_Of_String(s))
					{
						b2 = 0;
						cout << "\a";
						Print_String("\n\n\tInvalid Input", 80);
						Sleep(1500);
						system("cls");
						cout << "\n\n\tTo Modify\n\n";
						cout << "\tPlease Enter The Product No. To Modify " << Product[i].id;
						cout << "\n\nThe Product No. of The Product : " << Product[i].id;
						cout << "\nThe Name of The Product : " << Product[i].name;
						cout << "\n\nThe Price of The Product :" << Product[i].price;
						cout << "\nDiscount:" << Product[i].discount;
						cout << "\nPlease Enter The New Details of Product";
						cout << "\n\nPlease Enter The Product No. of The Product " << Product[i].id;
						cout << "\n\n\nPlease Enter The Name Of The Product :";
						break;
					}
				}
				if (b2 == 1)
				{
					Product[i].name = s;
					break;
				}
			}
			cout << "\nPlease Enter The Price Of The Product :";
			cin >> Product[i].price;
			cout << "\nPlease Enter The Discount (%) :";
			cin >> Product[i].discount;
			Print_String("\nProduct Modified ..", 80);
			Sleep(2500);
			Sorting();
			Save();
		}
	}
	if (b == 0)
	{
		cout << "\a";
		Print_String("\n\n\tInvalid Input", 80);
		Sleep(1500);
		system("cls");
		Modify();
	}
}
void Query()
{
START:cout << "\n\n\tQUERY MENU";
	cout << "\n\n\t01. QUERY BY No.";
	cout << "\n\n\t02. QUERY BY Name";
	cout << "\n\n\tPlease Select Your Option (1-2) ";
	string ch;
	cin >> ch;
	system("cls");
	switch (atoi(ch.c_str()))
	{
	case 1:
	{
		int Products_Number = Product.size();
		cout << "\n\n\tPlease Enter The Product No. ";
		int x;
		cin >> x;
		bool b = 0;
		for (int i = 0; i < Products_Number; i++)
		{
			if (x == Product[i].id)
			{
				b = 1;
				system("cls");
				cout << "\nThe Product No. of The Product : " << Product[i].id;
				cout << "\nThe Name of The Product : " << Product[i].name;
				cout << "\n\nThe Price of The Product : " << Product[i].price;
				cout << "\nDiscount : " << Product[i].discount;
				Sleep(3000);
			}
		}
		if (b == 0)
		{
			cout << "\a";
			Print_String("\n\n\tInvalid Input", 80);
			Sleep(1500);
			system("cls");
			Query();
		}
		break;
	}
	case 2:
	{
		int Products_Number = Product.size();
		cout << "\n\n\tPlease Enter The Product Name ";
		string s;
		cin.ignore();
		getline(cin, s);
		bool b = 0;
		for (int i = 0; i < Products_Number; i++)
		{
			if (s == Product[i].name)
			{
				b = 1;
				system("cls");
				cout << "\nThe Product No. of The Product : " << Product[i].id;
				cout << "\nThe Name of The Product : " << Product[i].name;
				cout << "\n\nThe Price of The Product : " << Product[i].price;
				cout << "\nDiscount : " << Product[i].discount;
				Sleep(3000);
			}
		}
		if (b == 0)
		{
			cout << "\a";
			Print_String("\n\n\tInvalid Input", 80);
			Sleep(1500);
			system("cls");
			Query();
		}
		break;
	}
	default:cout << "\a"; goto START;
	}
}
void Display()
{
	int Products_Number = Product.size();
	cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n\n";
	for (int i = 0; i < Products_Number; i++)
	{
		cout << "The Product No. of The Product : " << Product[i].id;
		cout << "\nThe Name of The Product : " << Product[i].name;
		cout << "\n\nThe Price of The Product : " << Product[i].price;
		cout << "\nDiscount : " << Product[i].discount;
		cout << "\n\n==============================================\n\n";
		Sleep(2000);
	}
}
void View()
{
	int Products_Number = Product.size();
	cout << "\n\n\t\tProduct MENU\n\n";
	cout << "====================================================\n";
	cout << "P.NO.\t\tNAME\t\t\tPRICE\n";
	cout << "====================================================\n";
	for (int i = 0; i < Products_Number; i++)
	{
		cout << Product[i].id << "\t\t" << Product[i].name;
		if (Product[i].name.size() < 8)
			cout << "\t\t\t" << Product[i].price;
		else if (Product[i].name.size() >= 8 && Product[i].name.size() < 16)
			cout << "\t\t" << Product[i].price;
		else
			cout << "\t" << Product[i].price;
		cout << "\n";
	}
}
void Welcome();
void Welcome_Customer()
{
	vector <market> Customer_Order;
	int Products_Number = Product.size();
	float money = 0;
	View();
	cout << "================================\n";
	cout << "\tPLACE YOUR ORDER\n================================";
	while (true)
	{
		bool b = 0;
		cout << "\n\nEnter The Product No. Of The Product : ";
		int x;
		cin >> x;
		for (int i = 0; i < Products_Number; i++)
		{
			if (x == Product[i].id)
			{
				b = 1;
				break;
			}
		}
		if (b == 0)
			cout << "\a";
		else
		{
			cout << "\nQuantity in Numbers : ";
			int q;
			cin >> q;
			for (int i = 0; i < Products_Number; i++)
			{
				if (x == Product[i].id)
				{
					Customer_Order.push_back(Variable);
					float temp;
					temp = ((Product[i].price) - (Product[i].price*(Product[i].discount / 100)));
					Customer_Order[Customer_Order.size() - 1].id = x;
					Customer_Order[Customer_Order.size() - 1].discount = q * temp;
					money += Customer_Order[Customer_Order.size() - 1].discount;
					Customer_Order[Customer_Order.size() - 1].q = q;
					Customer_Order[Customer_Order.size() - 1].amount = q * Product[i].price;
					Customer_Order[Customer_Order.size() - 1].price = Product[i].price;
					Customer_Order[Customer_Order.size() - 1].name = Product[i].name;
					break;
				}
			}
		CHOOSE:cout << "\nDo You Want To Add Another Product? (y/n) ";
			char ch;
			cin >> ch;
			if (ch == 'y')
				continue;
			else if (ch == 'n')
				break;
			else
			{
				cout << "\a";
				goto CHOOSE;
			}
		}
	}
	Print_String("\nThank You For Placing The Order", 80);
	Sleep(2500);
	system("cls");
	cout << "\n\n****************************************";
	cout << "Invoice****************************************\n\n";
	cout << "Pr No.\tPr Name \t\tQuantity \tPrice \tAmount \tAmount after discount\n\n";
	int Orders_Number = Customer_Order.size();
	market *Invoise = new market[Orders_Number];
	for (int i = 0; i < Orders_Number; i++)
		Invoise[i] = Customer_Order[i];
	for (int i = 0; i < Orders_Number; i++)
	{
		cout << Invoise[i].id << "\t" << Invoise[i].name;
		if (Invoise[i].name.size() < 8)
			cout << "\t\t\t" << Invoise[i].q;
		else if (Invoise[i].name.size() >= 8 && Invoise[i].name.size() < 16)
			cout << "\t\t" << Invoise[i].q;
		else
			cout << "\t" << Invoise[i].q;
		cout << "\t\t" << Invoise[i].price << "\t" <<
			Invoise[i].amount << "\t\t" << Invoise[i].discount << "\n";
	}
	cout << "\n\t\t\t\t\t\t\tTOTAL = " << money;
	Sleep(5000);
	system("cls");
	Welcome();
}
void Welcome_Admin()
{
	cout << "\n\n\tADMIN MENU\n\n";
	cout << "\t1.CREATE PRODUCT\n\n";       //   Nader	=>	***DONE***
	cout << "\t2.DISPLAY ALL PRODUCTS\n\n"; //   Merna	=>	** DONE **
	cout << "\t3.QUERY\n\n";                //   Mai	=>	** DONE **	
	cout << "\t4.MODIFY PRODUCT\n\n";       //   Nour	=>	***DONE***
	cout << "\t5.DELETE PRODUCT\n\n";       //   Nader	=>	***DONE***
	cout << "\t6.VIEW PRODUCT MENU\n\n";    //   Marwan =>	--------->	Nader
	cout << "\t7.BACK TO MENU\n\n";         //   Nader	=>	***DONE***
	cout << "\tPlease Enter Your Choise (1-7) ";
	string ch;
	cin >> ch;
	system("cls");
	switch (atoi(ch.c_str()))
	{
	case 1:Add(); system("cls"); Welcome(); break;
	case 2:Display(); system("cls"); Welcome(); break;
	case 3:Query(); system("cls"); Welcome(); break;
	case 4:Modify(); system("cls"); Welcome(); break;
	case 5:Delete(); system("cls"); Welcome(); break;
	case 6:View(); Sleep(5000); system("cls"); Welcome(); break;
	case 7:Welcome(); break;
	default:cout << "\a"; Welcome_Admin();
	}
}
void Verify()
{
	cout << "\n\n\tEnter the (USER-NAME & PASSWORD)\n\n\tUSER-NAME : ";
	string user_name; cin.ignore(); getline(cin, user_name);
	cout << "\n\tPASSWORD : ";
	string password;
	while (true)
	{
		char a;
		a = _getch();
		if (isalpha(a) || isdigit(a))
		{
			cout << "*";
			password += a;
		}
		else if (a == '\b' && !password.empty())
		{
			cout << "\b \b";
			password.pop_back();
		}
		else if (a == '\r')
			break;
	}
	if (user_name == "mn"&&password == "216")
	{
		system("color 72");
		Print_String("\n\n\tCorrect USER-NAME & PASSWORD ...", 80);
		Sleep(2000);
		system("cls");
		system("color 70");
		Welcome_Admin();
	}
	else
	{
		system("color 7C");
		Print_String("\n\n\t\aInvalid USER-NAME / PASSWORD ...", 80);
		Sleep(2000);
		system("cls");
		system("color 70");
		Welcome();
	}
}
void Exit()
{
	cout << "\n\n\t";
	Print_String("You have been exited", 80);
	for (int i = 0; i < 2; ++i)
	{
		//Red
		system("color 7C");
		cout << ".";
		Sleep(500);
		//Black
		system("color 70");
		cout << ".";
		Sleep(500);
	}
	Print_String("\n\n\n\tTHANK YOU :)", 80);
	Sleep(1000);
	cout << "\n\n\n\n\t";
}
void Welcome()
{
	cout << "\n\n\tMAIN MENU";
	cout << "\n\n\t01. CUSTOMER";
	cout << "\n\n\t02. ADMINISTRATOR";
	cout << "\n\n\t03. EXIT";
	cout << "\n\n\tPlease Select Your Option (1-3) ";
	string ch;
	cin >> ch;
	system("cls");
	switch (atoi(ch.c_str()))
	{
	case 1:Welcome_Customer(); break;
	case 2:Verify(); break;
	case 3:Exit(); break;
	default:cout << "\a"; Welcome();
	}
}
void main()
{
	Ready();
	Team_Programmers();
	Load();
	Welcome();
}