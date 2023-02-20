#include "Table.h"

using namespace Habitations;

namespace Prog4 {
	std::ostream& operator << (std::ostream& os, const Table& t)
	{
		std::map <const std::string, Habitation*>::const_iterator p = t.arr.begin();
		for (; p != t.arr.end(); p++)
		{
			std::cout << p->second;
		}
	}
	Table::Table(const Table& a)
	{
		std::map<const std::string, Habitation*>::const_iterator p;
		for (p = a.arr.begin(); p != a.arr.end(); ++p)
		{
			arr.insert(std::make_pair(p->first, p->second->clone()));
		}
	}
	Table::~Table()
	{
		std::map<const std::string, Habitation*>::iterator p;
		for (p = arr.begin(); p != arr.end(); ++p) {
			delete p->second;
			p->second = nullptr;
		}
	}
	Table& Table::operator = (const Table& a)
	{
		std::map<const std::string, Habitation*>::iterator p;
		if (this != &a) {
			for (p = arr.begin(); p != arr.end(); ++p)
				delete p->second;
			arr.clear();

			std::map<const std::string, Habitation*>::const_iterator pp;
			for (pp = a.arr.begin(); pp != a.arr.end(); ++pp)
				arr.insert(std::make_pair(pp->first, pp->second->clone()));
		}
		return *this;
	}

	Habitation* Table::find(const std::string& s) const
	{
		if (arr.count(s) == 0)
		{
			return nullptr;
		}
		else
		{
			std::map<const std::string, Habitation*>::const_iterator p = arr.find(s);
			return p->second;
		}
	}

	bool Table::insert(const std::string& s, const Habitation* f)
	{
		bool res = false;
		std::map<const std::string, Habitation*>::iterator p = arr.find(s);
		if (p == arr.end()) {
			std::pair<std::map<const std::string, Habitation*>::iterator, bool> pp =
				arr.insert(std::make_pair(s, f->clone()));
			if (!pp.second)
				throw std::exception("can't insert new item into map");
			res = true;
		}
		return res;
	}

}