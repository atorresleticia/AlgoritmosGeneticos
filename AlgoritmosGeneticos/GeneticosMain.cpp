// AG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <fstream>
#include "GeneticoConfig.h"

using namespace std;

int main()
{
	srand(time(nullptr));
	int indice_qualidade;
	int tamanho_populacao;
	int tamanho_cromossomo;
	float taxa_cruzamento;
	float taxa_mutacao;
	char elitismo;
	int geracoes;

	cout << "Numero de geracoes: ";
	cin >> geracoes;
	cout << "Tamanho da populacao: ";
	cin >> tamanho_populacao;
	cout << "Tamanho do cromossomo: ";
	cin >> tamanho_cromossomo;
	cout << "Taxa de cruzamento: ";
	cin >> taxa_cruzamento;
	cout << "Taxa de mutacao: ";
	cin >> taxa_mutacao;
	//cout << "Qualidade (0 - 100): ";
	//cin >> indice_qualidade;
	cout << "Elitismo? [s/n] ";
	cin >> elitismo;

	int g_count = 0;
	elitismo = elitismo == 's' ? true : false;
	const chrono::high_resolution_clock::time_point init = chrono::high_resolution_clock::now();

	populacao* pop = new populacao(tamanho_populacao, tamanho_cromossomo, true);
	genetico* gen = new genetico(taxa_mutacao / 100.0, taxa_cruzamento / 100.0, elitismo);

	/*while(pop->get_melhor().get_aptidao() < tamanho_cromossomo*(static_cast<float>(indice_qualidade)/100.0))
	{
	pop = gen->evolucao(*pop);
	g_count++;
	}*/
	while (g_count < geracoes)
	{
		srand(time(nullptr));
		pop = gen->evolucao(*pop);
		g_count++;
	}

	const chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

	int aptidao_media = 0;

	for (int i = 0; i < tamanho_populacao; i++)
	{
		aptidao_media += pop->get_individuo_em(i).get_aptidao();
	}

	aptidao_media /= tamanho_populacao;

	cout << "Numero de geracoes: " << g_count << endl;
	cout << "Maior aptidao: " << pop->get_melhor().get_aptidao() << endl;
	cout << "Aptidao Media: " << aptidao_media << endl;
	cout << "Qualidade da Solucao: " << pop->get_melhor().get_aptidao() * 100.0 / tamanho_cromossomo << "%" << endl;
	cout << "Espaco de busca: " << tamanho_populacao * g_count / pow(2, tamanho_cromossomo) << endl;
	cout << "Duracao: " << chrono::duration_cast<chrono::duration<double>>(end - init).count() << "s" << endl;
	cout << endl;

	return 0;
}

