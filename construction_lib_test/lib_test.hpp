#include <iostream>
#include<string>

class lib_test
{
public:
	lib_test();
	~lib_test();
	void expect_equ(int,int,std::string);
	void test_OK();
	void test_FAIL();
private:
	int nombre_tests;
	int requis;
	int resultat;
	int nb_tests_OK;
	std::string ligne_code_test;
};
