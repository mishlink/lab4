#include "pch.h"
#include "gtest\gtest.h"
#include "../lab4/Habitation.h"
#include "../lab4/Habitation.cpp"

//#include "../lab4/table.h"
//#include "../lab4/table.cpp"
TEST(Adress, AdressConstructors)
{
	Habitations::Adress a1;
	ASSERT_EQ("Default", a1.street);
	ASSERT_EQ(1, a1.house);
	ASSERT_EQ(0, a1.flat);

	Habitations::Adress a2("Hello");
	ASSERT_EQ("Hello", a2.street);
	ASSERT_EQ(1, a2.house);
	ASSERT_EQ(0, a2.flat);

	Habitations::Adress a3("Hello", 2);
	ASSERT_EQ("Hello", a3.street);
	ASSERT_EQ(2, a3.house);
	ASSERT_EQ(0, a3.flat);

	Habitations::Adress a4("Hello", 2, 1);
	ASSERT_EQ("Hello", a4.street);
	ASSERT_EQ(2, a4.house);
	ASSERT_EQ(1, a4.flat);
}

TEST(Room, RoomMethods)
{
	Habitations::Room r1;
	ASSERT_EQ(1, r1.getArea());
	Habitations::Room r2("Kitchen", 2);
	ASSERT_EQ(2, r2.getArea());
}

TEST(Flat, FlatConstructor)
{
	Habitations::Flat f1;
	Habitations::Adress a;
	Habitations::Room r[4];
	ASSERT_EQ(a.flat, f1.getAdress().flat);
	ASSERT_EQ(a.street, f1.getAdress().street);
	ASSERT_EQ(a.house, f1.getAdress().house);
	ASSERT_EQ(1, f1.getCost());
	ASSERT_EQ(false, f1.getSettled());
	ASSERT_EQ(0, f1.getType());
	Habitations::Flat f2(a, 2.0, true, r);
	ASSERT_EQ(a.flat, f2.getAdress().flat);
	ASSERT_EQ(a.street, f2.getAdress().street);
	ASSERT_EQ(a.house, f2.getAdress().house);
	ASSERT_EQ(2, f2.getCost());
	ASSERT_EQ(true, f2.getSettled());
	ASSERT_EQ(0, f2.getType());
}
TEST(Flat, FlatGetArea)
{
	Habitations::Flat f1;
	ASSERT_EQ(4.0, f1.getArea());
	Habitations::Adress a;
	Habitations::Room r1("kitchen", 4);
	Habitations::Room r2("room", 6);
	Habitations::Room r3("bathroom", 5);
	Habitations::Room r4("hallway", 7);
	Habitations::Room r[4] = { r1, r2, r3, r4 };
	Habitations::Flat f2(a, 1.0, false, r);
	ASSERT_EQ(22, f2.getArea());
}

TEST(Apartment, ApartmentConstructor)
{
	int k;
	Habitations::Apartment ap1;
	Habitations::Adress a;
	Habitations::Room r[4];
	ASSERT_EQ(a.flat, ap1.getAdress().flat);
	ASSERT_EQ(a.street, ap1.getAdress().street);
	ASSERT_EQ(a.house, ap1.getAdress().house);
	ASSERT_EQ(1, ap1.getCost());
	ASSERT_EQ(false, ap1.getSettled());
	ASSERT_EQ(1, ap1.getType());
	Habitations::Apartment ap2(a, 2.0, true, 4, r);
	ASSERT_EQ(a.flat, ap2.getAdress().flat);
	ASSERT_EQ(a.street, ap2.getAdress().street);
	ASSERT_EQ(a.house, ap2.getAdress().house);
	ASSERT_EQ(2, ap2.getCost());
	ASSERT_EQ(true, ap2.getSettled());
	ASSERT_EQ(1, ap2.getType());
}

TEST(Apartment, ApartmentGetArea)
{
	Habitations::Apartment ap1;
	ASSERT_EQ(4.0, ap1.getArea());
	Habitations::Adress a;
	Habitations::Room r1("cool_kitchen", 4);
	Habitations::Room r2("cool_room", 6);
	Habitations::Room r3("cool_bathroom", 5);
	Habitations::Room r4("cool_hallway", 7);
	Habitations::Room r[4] = { r1, r2, r3, r4 };
	Habitations::Apartment ap2(a, 1.0, false, 4, r);
	ASSERT_EQ(22, ap2.getArea());
}

TEST(Cottage, BuildingGetArea)
{
	Habitations::Building b1;
	ASSERT_EQ(4.0, b1.getArea());
	Habitations::Adress a;
	Habitations::Room r1("cool_kitchen", 4);
	Habitations::Room r2("cool_room", 6);
	Habitations::Room r3("cool_bathroom", 5);
	Habitations::Room r4("cool_hallway", 7);
	Habitations::Room r[4] = { r1, r2, r3, r4 };
	Habitations::Building b2(2, 4, r);
	ASSERT_EQ(22, b2.getArea());
}

TEST(Cottage, CottageConstructor)
{
	int k;
	Habitations::Cottage cot1;
	Habitations::Adress a;
	Habitations::Building b[4];
	ASSERT_EQ(a.flat, cot1.getAdress().flat);
	ASSERT_EQ(a.street, cot1.getAdress().street);
	ASSERT_EQ(a.house, cot1.getAdress().house);
	ASSERT_EQ(1, cot1.getCost());
	ASSERT_EQ(false, cot1.getSettled());
	ASSERT_EQ(2, cot1.getType());
	Habitations::Cottage cot2(a, 2.0, true, 4, b);
	ASSERT_EQ(a.flat, cot2.getAdress().flat);
	ASSERT_EQ(a.street, cot2.getAdress().street);
	ASSERT_EQ(a.house, cot2.getAdress().house);
	ASSERT_EQ(2, cot2.getCost());
	ASSERT_EQ(true, cot2.getSettled());
	ASSERT_EQ(2, cot2.getType());
}

TEST(Cottage, CottageGetArea)
{
	Habitations::Cottage ap1;
	ASSERT_EQ(16.0, ap1.getArea());
}