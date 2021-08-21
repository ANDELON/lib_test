#include "lib_test.hpp"

lib_test::lib_test()
{
	nombre_tests = 0;
	nb_tests_OK = 0;
}

lib_test::~lib_test()
{
	double tx_reussite = 0;
	if(nombre_tests > 0)
	{
		tx_reussite = 100*nb_tests_OK/nombre_tests;
	}
	else
	{
		tx_reussite = 0;
	}
	
	std::cout<<" \n";
	std::cout<<"Taux de reussite de " << tx_reussite << " %\n";
}


void lib_test::expect_equ(int requis, int resultat, std::string str)
{
	this->requis = requis;
	this->resultat = resultat;
	this->ligne_code_test = str;
	if(requis == resultat)
	{
		this->test_OK();
		nb_tests_OK++;
	}
	else
	{
		this->test_FAIL();
	}
	nombre_tests ++;
	
}

void lib_test::test_OK()
{
	std::cout<<"test "<< nombre_tests << " REUSSI.\n";
	std::cout<<"Execute "<< ligne_code_test <<" \n";
	std::cout<<"Attendu "<< requis <<" \n";
	std::cout<<"Resultat "<< resultat <<" \n";
	std::cout<<" \n";
}

void lib_test::test_FAIL()
{
	std::cout<<"test "<< nombre_tests << " ECHOUE.\n";
	std::cout<<"Execute "<< ligne_code_test <<" \n";
	std::cout<<"Attendu "<< requis <<" \n";
	std::cout<<"Resultat "<< resultat <<" \n";
	std::cout<<" \n";
}
