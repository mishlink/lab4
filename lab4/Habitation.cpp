#include "Habitation.h"


namespace Habitations {

	//Adress

	

	//Room

	/// \brief Output Room's name, area, comments
	/// \param os Ostream
	/// \param r Room
	std::ostream& operator <<(std::ostream& os, const Room& r)
	{
		return os << "It is room. Called: " << r.name << ". Area: " << r.area << ". Comments: " << r.comments << std::endl;
	}


	/// \brief The method that return room's area
	/// \return Room's area
	double Room::getArea() const
	{
		return area;
	}

	/// \brief Input Room's parameters: area, comments
	/// \param is Istream
	/// \param s Name of room

	Room InRoom(std::istream& is, std::string s)
	{
		std::cout << s;
		std::cout << "Enter Area: ";
		double area;
		is >> area;
		if (std::cin.good())
			throw std::exception("Error when area room were entered");
		std::cout << "Enter comments: ";
		std::string com;
		is >> com;
		Room r(s, area, com);
		return r;
	}

	//Habitation

	Habitation::Habitation()
	{
		Adress ad;
		a = ad;
		cost = 1;
		set = false;
	}


	/// \brief Output Habitation's parameters
	/// \param os Ostream
	/// \param h Habitation
	std::ostream& operator << (std::ostream& os, const Habitation& h)
	{
		return h.show(os);
	}
	/// \brief The method that return true if the room is occupied, otherwise false
	/// \return the state of occupancy
	bool Habitation::getSettled() const
	{
		return set;
	}

	/// \brief The method that change the state of occupancy
	void Habitation::changeSettled()
	{
		if (set)
		{
			set = false;
		}
		else
		{
			set = true;
		}
	}
	/// \brief The method that return Habitation's adress
	/// \return Habitation's adress
	Adress Habitation::getAdress() const
	{
		return a;
	}
	/// \brief The method that return Habitation's cost of 1 sq m
	/// \return Habitation's cost of 1 sq m
	double Habitation::getCost() const
	{
		return cost;
	}

	//Flat

	Flat::Flat(): Habitation()
	{
		std::string n[4] = {"kitchen", "room", "bathroom", "hallway"};
		for (int i = 0; i < 4; i++)
		{
			Room ro(n[i]);
			r[i] = ro;
		}
	}

	Flat::Flat(Adress ad, double c, bool s, Room ro[4]): Habitation(ad, c, s)
	{
		for (int i = 0; i < 4; i++)
		{
			r[i] = ro[i];
		}
	}

	/// \brief Input Flat's parameters: cost, info about Room
	/// \param is Istream
	/// \param ad Adress

	std::istream& Flat::input(std::istream& is, Adress ad)
	{
		std::cout << "Enter a cost of 1 sq m: ";
		int c;
		is >> c;
		if (!std::cin.good())
			throw std::exception("Error when a cost was entered");
		std::string n[4] = { "kitchen", "room", "bathroom", "hallway" };
		for (int i = 0; i < 4; i++)
		{
			r[i] = InRoom(is, n[i]);
		}
		a = ad;
		cost = c;
		set = true;
	}

	/// \brief The method that return Flat's area
	/// \return Flat's area

	double Flat::getArea() const {
		double s = 0.0;
		for (int i = 0; i < 4; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

	/// \brief Output Flat's parameters: Adress, cost, occupancy, area
	/// \param os Ostream

	std::ostream& Flat::show(std::ostream& os) const
	{
		os << "Flat: " << std::endl;
		os << "Adress: street - " << getAdress().street << "; house - " << getAdress().house << "; flat - " << getAdress().flat << std::endl;
		os << "Cost: " << getCost() << std::endl;
		if (getSettled())
		{
			os << "Occupied";
		}
		else
		{
			os << "Available";
		}
		os << std::endl << "Area: " << getArea() << std::endl;
		for (int i = 0; i < 4; i++)
		{
			os << r[i];
		}
		return os;
	}

	//Apartment

	Apartment::Apartment(): Habitation()
	{
		SZ = QUOTA;
		std::string n[4] = { "cool_kitchen", "cool_room", "cool_bathroom", "cool_hallway" };
		cnt = 4;
		r = new Room[SZ];
		for (int i = 0; i < 4; i++)
		{
			Room ro(n[i]);
			r[i] = ro;
		}
	}

	Apartment::Apartment(Adress ad, double c, bool s, int cn, Room *ro) : Habitation(ad, c, s)
	{
		SZ = QUOTA;
		cnt = cn;
		while (SZ < cn)
		{
			SZ += QUOTA;
		}

		r = new Room[SZ];

		for (int i = 0; i < cnt; i++)
		{
			r[i] = ro[i];
		}
	}

	/// \brief Input Apartment's parameters: cost, info about Room
	/// \param is Istream
	/// \param ad Adress

	std::istream& Apartment::input(std::istream& is, Adress ad)
	{
		std::cout << "Enter a cost of 1 sq m: ";
		int c;
		is >> c;
		if (!std::cin.good())
			throw std::exception("Error when a cost was entered");
		std::cout << "Enter a count of room: ";
		int cn;
		is >> cn;
		cnt = cn;
		if (!std::cin.good())
			throw std::exception("Error when a count was entered");
		while (cn > SZ)
		{
			SZ += QUOTA;
		}
		delete[] r;
		r = new Room[SZ];
		for (int i = 0; i < cn; i++)
		{
			std::cout << "Enter name of room: ";
			std::string na;
			is >> na;
			r[i] = InRoom(is, na);
		}
		a = ad;
		cost = c;
		set = true;
	}

	/// \brief The method that return Apartment's area
	/// \return Apartment's area

	double Apartment::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

	/// \brief Output Apartment's parameters: Adress, cost, occupancy, area, info of each Room
	/// \param os Ostream

	std::ostream& Apartment::show(std::ostream& os) const
	{
		os << "Apartment: " << std::endl;
		os << "Adress: street - " << getAdress().street << "; house - " << getAdress().house << "; flat - " << getAdress().flat << std::endl;
		os << "Cost: " << getCost() << std::endl;
		if (getSettled())
		{
			os << "Occupied";
		}
		else
		{
			os << "Available";
		}
		os << std::endl << "Area: " << getArea() << std::endl;
		os << cnt << " rooms:" << std::endl;
		for (int i = 0; i < cnt; i++)
		{
			os << r[i];
		}
		return os;
	}

	//Building

	Building::Building(int nu)
	{
		num = nu;
		SZ = QUOTA;
		std::string n[4] = { "excellent_kitchen", "excellent_room", "excellent_bathroom", "excellent_hallway"};
		cnt = 4;
		r = new Room[SZ];
		for (int i = 0; i < 4; i++)
		{
			Room ro(n[i]);
			r[i] = ro;
		}
	}

	Building::Building(int nu, int cn, Room* ro)
	{
		SZ = QUOTA;
		num = nu;
		cnt = cn;
		while (SZ < cn)
		{
			SZ += QUOTA;
		}

		r = new Room[SZ];

		for (int i = 0; i < cnt; i++)
		{
			r[i] = ro[i];
		}
	}
	/// \brief Input Building's parameters: info about Room
	/// \param is Istream
	/// \param number Building number

	Building Building::input(std::istream& is, int number)
	{
		num = number;
		std::cout << "Enter a count of room: ";
		int cn;
		std::cin >> cn;
		cnt = cn;
		if (!std::cin.good())
			throw std::exception("Error when a count was entered");
		while (cn > SZ)
		{
			SZ += QUOTA;
		}
		delete[] r;
		r = new Room[SZ];
		for (int i = 0; i < cn; i++)
		{
			std::cout << "Enter name of room: ";
			std::string na;
			is >> na;
			r[i] = InRoom(is, na);
		}
	}

	/// \brief The method that return Building's area
	/// \return Building's area

	double Building::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

	/// \brief Output Building's parameters: building number, area, info of each Room
	/// \param os Ostream
	/// \param b Building

	std::ostream& operator << (std::ostream& os, const Building& b)
	{
		os << "Building number " << b.num << std::endl;
		os << "Area: " << b.getArea() << std::endl;
		os << b.cnt << " rooms:" << std::endl;
		for (int i = 0; i < b.cnt; i++)
		{
			os << b.r[i];
		}
		return os;
	}

	//Cottage

	Cottage::Cottage() : Habitation()
	{
		SZ = QUOTA;
		cnt = 4;
		b = new Building[SZ];
		for (int i = 0; i < 4; i++)
		{
			Building bi(i + 1);
			b[i] = bi;
		}
	}

	Cottage::Cottage(Adress ad, double c, bool s, int cn, Building* bi) : Habitation(ad, c, s)
	{
		SZ = QUOTA;
		cnt = cn;
		while (SZ < cn)
		{
			SZ += QUOTA;
		}

		b = new Building[SZ];

		for (int i = 0; i < cnt; i++)
		{
			b[i] = bi[i];
		}
	}

	/// \brief Input Apartment's parameters: cost, info about Building
	/// \param is Istream
	/// \param ad Adress

	std::istream& Cottage::input(std::istream& is, Adress ad)
	{
		std::cout << "Enter a cost of 1 sq m: ";
		int c;
		is >> c;
		if (!std::cin.good())
			throw std::exception("Error when a cost was entered");
		std::cout << "Enter a count of building: ";
		int cn;
		is >> cn;
		cnt = cn;
		if (!std::cin.good())
			throw std::exception("Error when a count was entered");
		while (cn > SZ)
		{
			SZ += QUOTA;
		}
		delete[] b;
		b = new Building[SZ];
		for (int i = 0; i < cn; i++)
		{
			std::cout << "Enter name of room: ";
			std::string na;
			b[i].input(is, i + 1);
		}
		a = ad;
		cost = c;
		set = true;
	}

	/// \brief The method that return Cottage's area
	/// \return Cottage's area

	double Cottage::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += b[i].getArea();
		}
		return s;
	}

	/// \brief Output Cottage's parameters: Adress, cost, occupancy, area, info of each Building
	/// \param os Ostream

	std::ostream& Cottage::show(std::ostream& os) const
	{
		os << "Cottage: " << std::endl;
		os << "Adress: street - " << getAdress().street << "; house - " << getAdress().house << std::endl;
		os << "Cost: " << getCost() << std::endl;
		if (getSettled())
		{
			os << "Occupied";
		}
		else
		{
			os << "Available";
		}
		os << std::endl << "Area: " << getArea() << std::endl;
		os << cnt << " buildings:" << std::endl;
		for (int i = 0; i < cnt; i++)
		{
			os << b[i];
		}
		return os;
	}

	Cottage::~Cottage()
	{
			delete[] b;
	}

}