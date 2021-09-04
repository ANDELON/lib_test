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
	
	std::cout<<" \n--------------------------------------------- \n";
	std::cout<<"Nombre de tests total   : " << nombre_tests << " \n";
	std::cout<<"Nombre de tests reussis : " << nb_tests_OK << " \n";
	std::cout<<"Nombre de tests echoues : " << nombre_tests-nb_tests_OK << " \n";
	std::cout<<" \n--------------------------------------------- \n";
	std::cout<<" \n--------------------------------------------- \n";
	std::cout<<" \n--------------------------------------------- \n";
	std::cout<<"Taux de reussite de " << tx_reussite << " %\n";
	std::cout<<" \n--------------------------------------------- \n";
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

void lib_test::expect_equ(int requis[], int resultat[], int N, std::string str)
{
	this->t_requis = requis;
	this->t_resultat = resultat;
	this->ligne_code_test = str;
	this->N = N;
	bool test_OK = true;
	int indice_fault[N];
	int compteur = 0;
	for(int i = 0; i < N; i++)
	{
		if(requis[i] != resultat[i])
		{
			test_OK = false;
			indice_fault[compteur] = i;
			compteur++;
		}
	}
	
	if(test_OK)
	{
		this->test_OK();
		nb_tests_OK++;
	}
	else
	{
		this->test_FAIL_tab(compteur, indice_fault);
	}
	nombre_tests ++;
	
}

void lib_test::test_OK()
{
	//std::cout<<"test "<< nombre_tests << " REUSSI.\n";
	//std::cout<<"Execute "<< ligne_code_test <<" \n";
	//std::cout<<"Attendu "<< requis <<" \n";
	//std::cout<<"Resultat "<< resultat <<" \n";
	//std::cout<<" \n";
}

void lib_test::test_FAIL()
{
	std::cout<<"test "<< nombre_tests << " ECHOUE.\n";
	std::cout<<"Execute "<< ligne_code_test <<" \n";
	std::cout<<"Attendu "<< requis <<" \n";
	std::cout<<"Resultat "<< resultat <<" \n";
	std::cout<<" \n";
}

void lib_test::test_FAIL_tab(int nb_indices, int tab_def[])
{
	std::cout<<"test "<< nombre_tests << " ECHOUE.\n";
	std::cout<<"Execute "<< ligne_code_test <<" \n";
	std::cout<<"Attendu  :";
	for(int i = 0; i < this->N; i++)
	{
		std::cout<< t_requis[i] << ", ";
	}
	std::cout<<"\n";
	std::cout<<"Resultat :";
		for(int i = 0; i < this->N; i++)
	{
		std::cout<< t_resultat[i] << ", ";
	}
	std::cout<<"\n";
	std::cout<<"Indices fautifs: ";
	for(int i = 0; i < nb_indices; i++)
	{
		std::cout<< tab_def[i] << ", ";
	}
	
	std::cout<<" \n";
}
