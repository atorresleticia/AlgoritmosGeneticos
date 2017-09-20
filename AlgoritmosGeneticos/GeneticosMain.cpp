#include "stdafx.h"
#include "GeneticoConfig.h";
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	const int max_pop = atoi(argv[1]);
	const int max_gen = atoi(argv[2]);

	populacao* p = new populacao(max_pop, true, true, atoi(argv[3]));
	genetico_config* g = new genetico_config(max_gen, p);
	g->evolucao();

	int aptidao_media = 0;

	for (int i = 0; i < max_pop; i++)
	{
		cout << "It: " << i;
		//cout << "Nova Populacao: (" << p->get_individuo(i).get_x() << ", " << p->get_individuo(i).get_y() << ")" << endl;
		cout << "\tAptidao: " << p->get_individuo(i).get_aptidao() << endl << endl;
		aptidao_media += p->get_individuo(i).get_aptidao();
	}

	cout << "Aptidao Media: " << aptidao_media / max_pop << endl;
}

