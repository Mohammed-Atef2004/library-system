#include<iostream>
# include<algorithm>
# include<vector>
using namespace std;
int counter_book = 0;
int counter_user = 0;
int totalco = 0;
struct Book
{
	int id = 0;
	string name;
	int total_quanity = 0;
	int borrow = 0;
	int remain = 0;
}; vector<Book>book;
struct User {
	string name;
	int id = 0;
}user[100];
struct borrowed
{
	string who;
	string which;
}bo[100];
void add_book();
void search();
void add_user();
void print_all_users();
void print_library_by_id();
void print_library_by_name();
void return_a_book();
void borrow_a_book();
void print_who_borrow();
int main()
{
	Book b;
	b.id = 0;
	b.borrow = 0;
	b.name = "ahmed";
	book.push_back(b);

	while (true)
	{
		cout << "\t\t\t\t\t\t\twelcome to the library system\n";
		cout << "enter your choice\n1-add a book\n2-search book by name\n3-print who porrowed book by name\n";
		cout << "4-print library by name\n5-print library by id\n6-add user\n7-user borrow a book\n8-user return a book\n";
		cout << "9-print all users\n10-exit\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			add_book();
		}
		else if (choice == 2)
		{
			search();
		}
		else if (choice == 3)
		{
			print_who_borrow();
		}
		else if (choice == 4)
		{
			print_library_by_name();
		}
		else if (choice == 5)
		{
			print_library_by_id();
		}

		else if (choice == 6)
		{
			add_user();
		}
		else if (choice == 7)
		{
			borrow_a_book();
		}
		else if (choice == 8)
		{
			return_a_book();
		}
		else if (choice == 9)
		{
			print_all_users();
		}
		else if (choice == 10)
		{
			cout << "thanks for using our system\n";
			break;
		}
	}
}
void add_book()
{
	cout << "enter the id of the book and the name of the book and the quantity of the book in the library\n";
	cin >> book[counter_book].id >> book[counter_book].name >> book[counter_book].total_quanity;
	counter_book++;
	main();
}
void search()
{
	cout << "enter the name of the book\n";
	string ans;
	cin >> ans;
	bool ch = 0;
	for (int i = 0; i < counter_book; i++)
	{
		if (book[i].name.find(ans) != book[i].name.npos)
		{
			ch = 1;
			cout << book[i].name << endl;
		}

	}
	if (ch == 0)cout << "we can't find a book with this name\n";
	main();
}
void add_user()
{
	cout << "enter the name of the user and the id\n";
	cin >> user[counter_user].name >> user[counter_user].id;
	counter_user++;
	main();

}
void print_all_users()
{
	if (counter_user == 0)
		cout << "there are no users at the system now\n";
	else
	{
		cout << "the number of users in the system  ( " << counter_user << " ) " << endl;
		for (int i = 0; i < counter_user; i++)
		{
			cout << "the name of the user is ( " << user[i].name << " ) the id of the user is ( " << user[i].id << " ) \n";
		}
	}
	main();
}
void print_library_by_id()
{
	if (counter_book == 0)
	{
		cout << "the library is empty\n";
	}
	else
	{
		for (int i = 0; i < counter_book - 1; i++)
		{
			for (int j = i + 1; j < counter_book; j++)
			{
				if (book[i].id > book[j].id)
					swap(book[i], book[j]);
			}
		}
		for (int i = 0; i < counter_book; i++)
		{
			book[i].remain = book[i].total_quanity - book[i].borrow;
			cout << "the id of the book ( " << book[i].id << " ) " << "the name of the book ( " << book[i].name << " ) the total quantity ( " << book[i].total_quanity << " ) borrowed ( " << book[i].borrow << " ) remaining ( " << book[i].remain << " ) " << endl;
		}
	}
	main();
}
void print_library_by_name()
{
	if (counter_book == 0)
	{
		cout << "the library is empty\n";
	}
	else
	{
		for (int i = 0; i < counter_book - 1; i++)
		{
			for (int j = i + 1; j < counter_book; j++)
			{
				if (book[i].name > book[j].name)
					swap(book[i], book[j]);
			}
		}
		for (int i = 0; i < counter_book; i++)
		{
			book[i].remain = book[i].total_quanity - book[i].borrow;
			cout << "the id of the book ( " << book[i].id << " ) " << "the name of the book ( " << book[i].name << " ) the total quantity ( " << book[i].total_quanity << " ) borrowed ( " << book[i].borrow << " ) remaining ( " << book[i].remain << " ) " << endl;
		}
	}
	main();
}
void borrow_a_book()
{
	cout << "enter the name of the user\n";
flag:
	string ans;
	cin >> ans;
	int curentind = 0;
	bool ch = 0;
	for (int i = 0; i < counter_user; i++)
	{
		if (ans == user[i].name)
		{
			ch = 1;
			curentind = i;
		}
	}
	if (ch == 0)
	{
		cout << "there is no user with this name ,please try again\n";
		goto flag;
	}
	cout << "enter the book name\n";
flag1:
	string s;
	cin >> s;
	int cur = 0;
	bool c = 0;
	bool remaining = 0;
	for (int i = 0; i < counter_book; i++)
	{
		if (s == book[i].name)
		{
			c = 1;
			cur = i;
		}
		if (book[i].remain > 0)
		{
			remaining = 1;
		}
	}
	if (c == 0)
	{
		cout << "invlaid book name please try again\n";
		goto flag1;
	}
	else if (remaining == 0)
	{
		cout << "all the amount of the book are borrowed\n";
		main();
	}

	else {
		bo[totalco].who = user[curentind].name;
		bo[totalco].which = book[cur].name;
		book[cur].borrow++;
		book[cur].remain = book[cur].total_quanity - book[cur].borrow;
		totalco++;
	}
	main();
}
void return_a_book()
{
	cout << "enter the name of the user \n";
flag:
	string name;
	cin >> name;
	bool c = 0;
	for (int i = 0; i < totalco; i++)
	{
		if (name == bo[i].who)
		{
			c = 1;
		}
	}
	if (c == 0)
	{
		cout << "there is no user with this name\n";
		goto flag;
	}
	cout << "enter the name of the book\n";
flag1:
	string sss;
	cin >> sss;
	bool ch = 0;
	for (int i = 0; i < totalco; i++)
	{
		if (sss == bo[i].which)
		{

			ch = 1;
		}
	}
	if (ch == 0)
	{
		cout << "there is no book with this name,please try again\n";
		goto flag1;
	}
	else if (c == 1 && ch == 1)
	{
		int curr = 0;
		for (int i = 0; i < totalco; i++)
		{

			if (sss == bo[i].which && name == bo[i].who)
			{
				curr = i;
			}
		}
		for (int i = 0; i < counter_book; i++)
		{
			if (bo[curr].which == book[i].name)
			{
				book[i].borrow--;
				book[i].remain++;
			}
		}
	}
	for (int i = 0; i < totalco; i++)
	{

		if (sss == bo[i].which && name == bo[i].who)
		{
			bo[i].who = "empty";
			bo[i].which = "empty";
			cout << "thanks for using our library system\n";
		}
	}
	main();
}
void print_who_borrow()
{
	if (totalco == 0)
	{
		cout << "there is no one borrow any book yet\n";
		main();
	}
	else
	{
		for (int i = 0; i < totalco - 1; i++)
		{
			for (int j = i + 1; j < totalco; j++)
			{
				if (bo[i].who > bo[j].who)
				{
					swap(bo[i].who, bo[j].who);
				}
			}
		}
		bool b = 0;
		for (int i = 0; i < totalco; i++)
		{
			if (bo[i].who == "empty")
			{
				continue;
			}
			else
			{
				b = 1;
				if (bo[i].who != bo[i - 1].who)
				{
					cout << "the user ( " << bo[i].who << " ) has borrowed the book/books ";
					for (int j = i; j < totalco; j++)
					{
						if (bo[i].who == bo[j].who)
						{
							cout << ": ( " << bo[j].which << " ) ";
						}

					}cout << endl;
				}
				else continue;
			}
		}
		if (b == 0)
		{
			cout << "there is no one borrow any book yet\n";
			main();
		}
	}
	main();
}
