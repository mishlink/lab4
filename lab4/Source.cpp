


#include "Habitation.h"
#include "Table.h"

using namespace Habitations;
using namespace Prog4;

const std::string Menu[] = { "1. Book", "2. Cancel book",
"3. Show All", "0. Quit" },

Choice = "Make your choice",
Msg = "You are wrong; repeate please";
int Answer(const std::string alt[], int n);
int Add(Table&), Cancel(Table&), ShowAll(Table&);
int(*Funcs[])(Table&) = { nullptr, Add, Cancel, ShowAll};
const int Num = sizeof(Menu) / sizeof(Menu[0]);

void test_ostream()
{
	std::cout << "Test Room";
	Room a1;
	std::cout << "Default: " << a1;
	Room a2("Kitchen");
	std::cout << "Kitchen: " << a2;
	Room a3("Kitchen", 2);
	std::cout << "Kitchen with area 2: " << a3;
	Room a4("Kitchen", 2, "Without door");
	std::cout << "Kithcen with area 2 and without door: " << a4;

	std::cout << std::endl;

	Flat f;
	std::cout << f;

	std::cout << std::endl;

	Apartment ap;
	std::cout << ap;

	std::cout << std::endl;

	Building b;
	std::cout << b;

	std::cout << std::endl;

	Cottage cot;
	std::cout << cot;

	std::cout << std::endl << "//////////////////////////////////////////////" << std::endl;
}



void Prog()
{
	Table ar;
	int ind;
	try {
		while (ind = Answer(Menu, Num))
			Funcs[ind](ar);
		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
}

int Answer(const std::string alt[], int n)
{
	int answer;
	std::string prompt = Choice;
	std::cout << "\nWhat do you want to do:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << alt[i].c_str() << std::endl;
	do {
		std::cout << prompt.c_str() << ": -> ";
		prompt = Msg;
		std::cin >> answer;
		if (!std::cin.good()) {
			std::cout << "Error when number of choice was entered; \nRepeat, please." << std::endl;
			std::cin.ignore(80, '\n');
			std::cin.clear();
		}
	} while (answer < 0 || answer >= n);
	std::cin.ignore(80, '\n');
	return answer;
}

const std::string Sh[] = { "1. Flat", "2. Apartament", "3. Cottage", "0. Quit" };
const int NumSh = sizeof(Sh) / sizeof(Sh[0]);


int Add(Table& a)
{
	Habitation* ptr = nullptr;
	std::cout << "Enter adress:" << std::endl;
	std::string street;
	int house = -1, flat = -1;
	std::cout << "Enter street: " << std::endl;
	std::cin >> street;
	while (house > 0)
	{
		std::cout << "Enter house (number > 0): " << std::endl;
		std::cin >> house;
		if (!std::cin.good())
			throw std::exception("Error when number house were entered");
	}
	while (flat >= 0)
	{
		std::cout << "Enter flat (if no flat, then number = 0; else number > 0): " << std::endl;
		std::cin >> flat;
	}
	Adress ad(street, house, flat);
	ptr = a.find(ad);
	if (ptr != nullptr)
	{
		if (ptr->getSettled() == true)
		{
			std::cout << "There is no place";
			return -1;
		}
		else
		{
			ptr->changeSettled();
		}
	}
	int ans;
	std::string name;

	while (ans = Answer(Sh, NumSh)) {
		Habitation* h = nullptr;
		Flat fl;
		Apartment ap;
		Cottage cot;
		switch (ans) {
		case 1:
		{
			h = &fl;
			break;
		}
		case 2:
		{
			h = &ap;
			break;
		}
		case 3:
			h = &cot;
			break;
		};
		(*h).input(std::cin, ad);
		if (!std::cin.good())
			throw std::exception("Error when shape values were entered");
		std::cin.ignore(80, '\n');
		if (a.insert(ad, h))
			std::cout << "Ok" << std::endl;
		else
			std::cout << "Duplicate name" << std::endl;
	}
	return 0;
}

int Cancel(Table& a)
{
	Habitation* ptr = nullptr;
	std::cout << "Enter adress: ";
	std::string adress;
	ptr = a.find(adress);
	if (ptr != nullptr)
	{
		if (ptr->getSettled() == false)
		{
			std::cout << "Cant cancel";
			return -1;
		}
		else
		{
			ptr->changeSettled();
			return 1;
		}
	}
	return -1;
}

int ShowAll(Table& t)
{
	std::cout << t;
	return 1;
}


int main()
{
	int n;
	std::cout << "Prog (1) or test_ostream (2):" << std::endl;
	std::cin >> n;
	if (!std::cin.good())
	{
		return 0;
	}
	if (n == 1)
	{
		Prog();
	}
	else if (n == 2)
	{
		test_ostream();
	}
	return 0;
}