#ifndef _HABITATION_H_
#define _HABITATION_H_
#include <iostream>

namespace Habitations {
	struct Adress {
		std::string street;
		int house;
		int flat;
		Adress(std::string s = "Default", int h = 1, int f = 0) : street(s), house(h), flat(f) {}
		bool operator<(const Adress& rhs) const noexcept
		{
			return this->street < rhs.street;

		}
	};

	class Room {
	private:
		std::string name;
		double area;
		std::string comments;
	public:
		Room(std::string n = "Room", double a = 1, std::string c = "") : name(n), area(a), comments(c) {}

		friend std::ostream& operator << (std::ostream& os, const Room&);
		double getArea() const;
	};

	class Habitation {
	protected:
		Adress a;
		double cost;
		bool set;
		virtual std::ostream& show(std::ostream&) const = 0;
	public:
		Habitation();
		Habitation(Adress ad, double c, bool s) : a(ad), cost(c), set(s) {}
		virtual Habitation* clone() const = 0;
		friend std::ostream& operator << (std::ostream&, const Habitation&);
		virtual std::istream& input(std::istream&, Adress ad) = 0;
		virtual int getType() const = 0;
		bool getSettled() const;
		void changeSettled();
		Adress getAdress() const;
		double getCost() const;
		virtual double getArea() const = 0;
		virtual ~Habitation() {}
	};

	class Flat : public Habitation{
	private:
		Room r[4];
	protected:
		std::ostream& show(std::ostream&) const;
	public:
		Flat();
		Flat(Adress ad, double c, bool s, Room ro[4]);
		std::istream& input(std::istream&, Adress ad);
		Habitation* clone() const {
			return new Flat(*this);
		}
		int getType() const {
			return 0;
		}
		double getArea() const;
	};


	class Apartment : public Habitation {
	private:
		static const int QUOTA = 10;
		int SZ;
		int cnt;
		Room *r;
	protected:
		std::ostream& show(std::ostream&) const;
	public:
		Apartment();
		Apartment(Adress ad, double c, bool s, int cnt, Room *ro);
		std::istream& input(std::istream&, Adress ad);
		Habitation* clone() const {
			return new Apartment(*this);
		}
		int getType() const {
			return 1;
		}
		double getArea() const;
		~Apartment() { delete[] r; }
	};

	class Building {
	private:
		int num;
		static const int QUOTA = 10;
		int SZ;
		int cnt;
		Room* r;
	public:
		Building(int nu = 1);
		Building(int nu, int cn, Room *ro);
		friend std::ostream& operator << (std::ostream& os, const Building&);
		Building input(std::istream&, int number);
		double getArea() const;
	};

	class Cottage : public Habitation {
	private:
		static const int QUOTA = 10;
		int SZ;
		int cnt;
		Building* b;
	protected:
		std::ostream& show(std::ostream&) const;
	public:
		Cottage();
		Cottage(Adress ad, double c, bool s, int cnt, Building* b);
		std::istream& input(std::istream&, Adress ad);
		Habitation* clone() const {
			return new Cottage(*this);
		}
		int getType() const {
			return 2;
		}
		double getArea() const;
		~Cottage();
	};

	//wrewrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
};
#endif

