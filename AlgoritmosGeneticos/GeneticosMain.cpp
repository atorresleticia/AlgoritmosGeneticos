// AG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <fstream>
#include "GeneticoConfig.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(nullptr));

	const auto tamanho_cromossomo = atoi(argv[1]);
	const auto tamanho_populacao = atoi(argv[2]);
	const float taxa_cruzamento = atof(argv[3]);
	const float taxa_mutacao = atof(argv[4]);
	const auto elitismo = atoi(argv[5]) == 1 ? true : false;

	cout << "PARAMETROS: " << endl;
	cout << "Tamanho cromossomo: " << tamanho_cromossomo << endl;
	cout << "Tamanho populacao: " << tamanho_populacao << endl;
	cout << "Taxa cruzamento: " << taxa_cruzamento << endl;
	cout << "Taxa mutacao: " << taxa_mutacao << endl;
	cout << (elitismo ? "Com elitismo" : "Sem elitismo") << endl;

	unsigned long g_count = 1;
	const auto init = chrono::high_resolution_clock::now();

	populacao* pop = new populacao(tamanho_populacao, tamanho_cromossomo, true);
	populacao* nova_p = new populacao(tamanho_populacao, tamanho_cromossomo, true);
	genetico* gen = new genetico(taxa_mutacao / 100.0, taxa_cruzamento / 100.0, elitismo);

	while(pop->get_melhor().get_aptidao() < tamanho_cromossomo)
	{
		gen->evolucao(*pop, *nova_p);
		g_count++;
		if (g_count % 10 == 0)
		{
			cout << pop->get_melhor().get_aptidao() * 100.0 / tamanho_cromossomo << "%" << "\b\b\b\b\b\b\b\b\b";
		}
	}

	const auto end = chrono::high_resolution_clock::now();

	auto aptidao_media = 0;

	for (auto i = 0; i < tamanho_populacao; i++)
	{
		aptidao_media += pop->get_individuo_em(i).get_aptidao();
	}

	aptidao_media /= tamanho_populacao;
	
	ofstream info("INFO.txt", ios::app);

	cout << "RESULTADOS: " << endl;
	cout << "Numero de geracoes: " << g_count << endl;
	cout << "Maior aptidao: " << pop->get_melhor().get_aptidao() << endl;
	cout << "Aptidao Media: " << aptidao_media << endl;
	cout << "Qualidade da Solucao: " << pop->get_melhor().get_aptidao() * 100.0 / tamanho_cromossomo << "%" << endl;
	cout << "Espaco de busca: " << tamanho_populacao * g_count / pow(2, tamanho_cromossomo) << endl;
	cout << "Duracao: " << chrono::duration_cast<chrono::duration<double>>(end - init).count() << "s" << endl;
	cout << endl;


	info << "PARAMETROS: " << endl;
	info << "Tamanho cromossomo: " << tamanho_cromossomo << endl;
	info << "Tamanho populacao: " << tamanho_populacao << endl;
	info << "Taxa cruzamento: " << taxa_cruzamento << endl;
	info << "Taxa mutacao: " << taxa_mutacao << endl;
	info << (elitismo ? "Com elitismo" : "Sem elitismo") << endl << endl;

	info << "RESULTADOS: " << endl;
	info << "Numero de geracoes: " << g_count << endl;
	info << "Maior aptidao encontrada: " << pop->get_melhor().get_aptidao() << endl;
	info << "Aptidao media: " << aptidao_media << endl;
	info << "Qualidade da solucao: " << pop->get_melhor().get_aptidao() * 100.0 / tamanho_cromossomo << "%" << endl;
	info << "Espaco de busca: " << tamanho_populacao * g_count / pow(2, tamanho_cromossomo) << endl;
	info << "Duracao: " << chrono::duration_cast<chrono::duration<double>>(end - init).count() << "s" << endl;
	info << "-------------------------------" << endl << endl;

	info.close();

	return 0;
}

