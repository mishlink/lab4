#include "Table.h"

using namespace Habitations;

namespace Prog4 {

	/// \brief Output Table
	/// \param os Ostream
	/// \param t Table

	std::ostream& operator << (std::ostream& os, const Table& t)
	{
		std::map <const Adress, Habitation*>::const_iterator p = t.arr.begin();
		for (; p != t.arr.end(); p++)
		{
			std::cout << p->second;
		}
		return os;
	}
	Table::Table(const Table& a)
	{
		std::map<const Adress, Habitation*>::const_iterator p;
		for (p = a.arr.begin(); p != a.arr.end(); ++p)
		{
			arr.insert(std::make_pair(p->first, p->second->clone()));
		}
	}
	Table::~Table()
	{
		std::map<const Adress, Habitation*>::iterator p;
		for (p = arr.begin(); p != arr.end(); ++p) {
			delete p->second;
			p->second = nullptr;
		}
	}

	/// \brief Overloaded assignment operator
	/// \param t1 first Table
	/// \return t2 second Table
	Table& Table::operator = (const Table& a)
	{
		std::map<const Adress, Habitation*>::iterator p;
		if (this != &a) {
			for (p = arr.begin(); p != arr.end(); ++p)
				delete p->second;
			arr.clear();

			std::map<const Adress, Habitation*>::const_iterator pp;
			for (pp = a.arr.begin(); pp != a.arr.end(); ++pp)
				arr.insert(std::make_pair(pp->first, pp->second->clone()));
		}
		return *this;
	}

	/// \brief The method that use the Adress to find the Habitation's info
	/// \param Adress
	/// \return Habitation

	Habitation* Table::find(const Adress& s) const
	{
		if (arr.count(s) == 0)
		{
			return nullptr;
		}
		else
		{
			std::map<const Adress, Habitation*>::const_iterator p = arr.find(s);
			return p->second;
		}
	}
	/// \brief The method that add Habitation to Table
	/// \param Adress This is the key for searching the table
	/// \param Habitation The element that is inserted into the table


	bool Table::insert(const Adress& s, const Habitation* f)
	{
		bool res = false;
		std::map<const Adress, Habitation*>::iterator p = arr.find(s);
		if (p == arr.end()) {
			std::pair<std::map<const Adress, Habitation*>::iterator, bool> pp =	arr.insert(std::make_pair(s, f->clone()));
			if (!pp.second)
				throw std::exception("can't insert new item into map");
			res = true;
		}
		return res;
	}

}