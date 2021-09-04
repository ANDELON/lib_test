#include <iostream>
using namespace std;
#include "counter.hpp"
#include "lib_test.hpp"


//TEST(Counter, Increment) {
//  Counter c;
//  EXPECT_EQ(0, c.Incr());
//  EXPECT_EQ(1, c.Incr());
//  EXPECT_EQ(2, c.Incr());
//}
//
//
//TEST(Counter2, value) {
//  Counter c;
//  c.Incr();
//
//  EXPECT_EQ(1, c.value());
//  EXPECT_EQ(2, c.value()); //This test should fail
//}


int main() 
{
  //::testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();
	lib_test test;
	Counter compteur;
	
	test.expect_equ(0, compteur.value(),"test.expect_equ(0, compteur.value()");
	test.expect_equ(1, compteur.Incr(),"test.expect_equ(1, compteur.Incr()");
	test.expect_equ(2, compteur.Incr(),"test.expect_equ(2, compteur.Incr()");
	test.expect_equ(4, compteur.Incr(),"test.expect_equ(4, compteur.Incr(), valeur precedente 2");
	
	return 0;
}

