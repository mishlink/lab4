#ifndef _MYMAP_H_
#define _MYMAP_H_
#include <iostream>
#include <exception>
#include "Habitation.h"

using namespace Habitations;

namespace Prog4 {

	template <class IND>
	struct Pair {
		Adress first;
		IND second;
		Pair(Adress indx, IND val) :first(indx), second(val) {}

	};

	template <class IND>
	class Assoc {

	private:

		static const int QUOTA = 10;
		int cnt, cur;
		Pair<IND>* arr;
		int getPos(const Adress&) const;
	public:

		Assoc() :cnt(QUOTA), cur(0), arr(new Pair<IND>[QUOTA]) { }
		Assoc(const Assoc<IND>&);
		~Assoc() { delete[] arr; }
		Assoc<IND>& operator = (const Assoc<IND>&);
		bool insert(const Adress&, const IND*);
		IND* find(const Adress&) const;
	};
}
#endif

