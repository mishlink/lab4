#ifndef _TABLE_1_H_
#define _TABLE_1_H_
#include <iostream>
#include <map>
#include <string>
#include "Habitation.h"

using namespace Habitations;

namespace Prog4 {
	class Table {
	private:
		std::map<const Adress, Habitation*> arr;
	public:
		Table() {}
		Table(const Table&);
		~Table();
		Table& operator = (const Table&);
		Habitation* find(const Adress&) const;
		bool insert(const Adress&, const Habitation*);
		friend std::ostream& operator << (std::ostream& os, const Table&);
	};
};
#endif
