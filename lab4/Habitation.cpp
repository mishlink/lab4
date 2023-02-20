#include "Habitation.h"


namespace Habitations {

	//Room

	std::ostream& operator <<(std::ostream& os, const Room& r)
	{
		return os << "It is room. Called: " << r.name << ". Area: " << r.area << ". Comments: " << r.comments << std::endl;
	}

	double Room::getArea() const
	{
		return area;
	}

	//Habitation

	Habitation::Habitation()
	{
		Adress ad;
		a = ad;
		cost = 1;
		set = false;
	}

	std::ostream& operator << (std::ostream& os, const Habitation& h)
	{
		return h.show(os);
	}
	bool Habitation::getSettled() const
	{
		return set;
	}

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
	Adress Habitation::getAdress() const
	{
		return a;
	}
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

	double Flat::getArea() const {
		double s = 0.0;
		for (int i = 0; i < 4; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

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
	double Apartment::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

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
	double Building::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += r[i].getArea();
		}
		return s;
	}

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
	double Cottage::getArea() const
	{
		double s = 0;
		for (int i = 0; i < cnt; i++)
		{
			s += b[i].getArea();
		}
		return s;
	}

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
		os << cnt << " rooms:" << std::endl;
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