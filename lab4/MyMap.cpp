//#include "MyMap.h"
//namespace Prog4 {
//	template <class IND>
//	Assoc<IND>::Assoc(const Assoc<IND>& a):cnt(a.cnt), cur(a.cur), arr(new Pair[a.cnt])
//	{
//		for (int i = 0; i < cnt; ++i)
//			arr[i] = a.arr[i];
//
//	}
//
//	/// \brief Overloaded assignment operator
//	/// \param t1 first Table
//	/// \return t2 second Table
//
//	template <class IND>
//	Assoc<IND>& Assoc<IND>::operator = (const Assoc<IND>& a) {
//		if (this != &a) {
//			delete[] arr;
//			arr = new Pair<IND>[cnt = a.cnt];
//			cur = a.cur;
//			for (int i = 0; i < cnt; ++i)
//				arr[i] = a.arr[i];
//
//		}
//		return *this;
//	}
//
//	/// \brief The method that use adress to return index of table
//	/// \param Adress
//	/// \return Index
//
//	template <class IND>
//	int Assoc<IND>::getPos(const Adress& s) const
//	{
//		for (int i = 0; i < cur; ++i)
//			if (arr[i].first == s)
//				return i;
//
//		return -1;
//	}
//
//	/// \brief The method that use the Adress to find the Habitation's info
//	/// \param Adress
//	/// \return Habitation
//
//	template <class IND>
//	IND* Assoc<IND>::find(const Adress& s) const
//	{
//		int i = getPos(s);
//		if (i < 0)
//			return nullptr;
//		return &arr[i];
//	}
//
//	/// \brief The method that add Habitation to Table
//	/// \param Adress This is the key for searching the table
//	/// \param Habitation The element that is inserted into the table
//
//	template <class IND>
//	bool Assoc<IND>::insert(const Adress& s, const IND* f)
//	{
//		bool res = false;
//		IND* p = arr.find(s);
//		if (p == nullptr) {
//			Pair<IND> pa(s, f->clone());
//			cur += 1;
//			if (cur > cnt)
//			{
//				cnt += QUOTA;
//				Pair<IND>* newarr = new Pair<IND>[cnt];
//				for (int i = 0; i < cnt - 1; i++)
//				{
//					newarr[i] = arr[i];
//				}
//				delete[] arr;
//				arr = newarr;
//			}
//			arr[cur - 1] = pa;
//			res = true;
//		}
//		return res;
//	}
//}