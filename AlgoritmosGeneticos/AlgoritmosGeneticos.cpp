// AlgoritmosGeneticos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneticoConfig.h";
#include "Populacao.h";
#include "Individuos.h";
#include <iostream>
#include <ctime>

using namespace std;

#define MAX_POP 10
#define MAX_GEN 1000

int main()
{
	srand(time(NULL));

	populacao* p = new populacao(MAX_POP, true);
	genetico_config* g = new genetico_config(MAX_GEN, p);
	g->evolucao();

	float aptidao_media = 0;

	for (int i = 0; i < MAX_POP; i++)
	{
		cout << "Numero da iteracao: " << i << endl;
		cout << "Nova Populacao: " << p->get_individuo(i).get_individuo() << endl;
		cout << "Nova Aptidao: " << p->get_individuo(i).get_aptidao() << endl << endl;
		aptidao_media += p->get_individuo(i).get_aptidao();
	}

	cout << "Aptidao Media: " << aptidao_media / MAX_POP << endl;
}

