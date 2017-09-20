#include "stdafx.h"
#include "GeneticoConfig.h";
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	const int max_pop = atoi(argv[1]);
	const int max_gen = atoi(argv[2]);
	const int max_crm = atoi(argv[3]);

	chrono::high_resolution_clock::time_point init = chrono::high_resolution_clock::now();

	populacao* p = new populacao(max_pop, true, true, max_crm);
	genetico_config* g = new genetico_config(max_gen, p);
	g->evolucao();

	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

	ofstream saida("dados_AG.txt", ios::app);

	chrono::duration<double> elaps = chrono::duration_cast<chrono::duration<double>>(end - init);

	int aptidao_media = 0;
	int aptidao_maxima = 0;

	for (int i = 0; i < max_pop; i++)
	{
		//saida << "It: " << i;
		//saida << "Nova Populacao: (" << p->get_individuo(i).get_x() << ", " << p->get_individuo(i).get_y() << ")" << endl;
		if (p->get_individuo(i).get_aptidao() > aptidao_maxima)
		{
			aptidao_maxima = p->get_individuo(i).get_aptidao();
		}
		//saida << "\tAptidao: " << p->get_individuo(i).get_aptidao() << endl << endl;
		aptidao_media += p->get_individuo(i).get_aptidao();
	}

	saida << "Maior aptidao: " << aptidao_maxima << endl;
	saida << "Aptidao Media: " << aptidao_media / max_pop << endl;
	saida << "Qualidade da Solucao: " << (aptidao_media / max_pop) * 100.0 / max_crm << endl;
	saida << "Espaco de busca: " << (max_pop * max_gen) / pow(2, max_crm) << endl;
	saida << "Duracao: " << chrono::duration_cast<chrono::duration<double>>(end - init).count() << "s" << endl;
	saida << endl;

	saida.close();

	return 0;
}

