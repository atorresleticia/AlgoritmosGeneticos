#include "stdafx.h"
#include "GeneticoConfig.h"
#include <ctime>

#define TX_MUTACAO 0.5
#define TX_CRUZAMENTO 80

genetico_config::genetico_config(int numero_geracoes, populacao* pop)
{
	numero_geracoes_ = numero_geracoes;
	pop_ = pop;
}

genetico_config::~genetico_config()
{
}

int genetico_config::selecao_roleta() const
{
	int s = 0;
	const int tamanho = pop_->get_tamanho_populacao();

	for (int i = 0; i < tamanho; i++)
	{
		s += pop_->get_individuo(i).get_aptidao();
	}

	const int p = rand() % s + 1;
	int t_parcial = 0;
	int i = 0;

	while (i < pop_->get_tamanho_populacao() && t_parcial < p)
	{
		t_parcial += pop_->get_individuo(i).get_aptidao();
		i++;
	}

	return i - 1;
}

void genetico_config::evolucao(bool elitismo) const
{		
	const int nro_geracoes = numero_geracoes_;
	const int tamanho_pop = pop_->get_tamanho_populacao();

	srand(time(NULL));

	populacao* nova_pop = new populacao(tamanho_pop, false, elitismo, pop_->get_individuo(0).get_cromossomo().length());
	for(int i = 0; i < nro_geracoes; i++)
	{	
		int j = 0;
		_memccpy(nova_pop, pop_, 0, sizeof(populacao));
		if (elitismo)
		{
			nova_pop->armazena_individuo(0, pop_->get_individuo(pop_->get_melhor()));
			j = 1;
		}

		for(; j < tamanho_pop; j++)
		{
			int index_1;
			int index_2;

			do {
				index_1 = selecao_roleta();
				index_2 = selecao_roleta();
			} while (index_1 == index_2);
		
			individuo individuo_selecionado_1 = pop_->get_individuo(index_1);
			individuo individuo_selecionado_2 = pop_->get_individuo(index_2);

			if ((rand() % 100 + 1) < TX_CRUZAMENTO)
			{
				cruzamento(individuo_selecionado_1, individuo_selecionado_2);
			}

			mutacao(individuo_selecionado_1);
			mutacao(individuo_selecionado_2);

			nova_pop->armazena_individuo(index_1, individuo_selecionado_1);
			nova_pop->armazena_individuo(index_2, individuo_selecionado_2);
		}
		_memccpy(pop_, nova_pop, 0, tamanho_pop * sizeof(individuo));
	}
}

void genetico_config::cruzamento(individuo &x, individuo &y)
{
	string cromossomo_1 = x.get_cromossomo();
	string cromossomo_2 = y.get_cromossomo();

	int corte = rand() % x.get_cromossomo().length();

	for (int i = corte + 1; i < cromossomo_1.length(); i++)
	{
		char aux = cromossomo_1[i];
		cromossomo_1[i] = cromossomo_2[i];
		cromossomo_2[i] = aux;
	}

	x.set_cromossomo(cromossomo_1);
	y.set_cromossomo(cromossomo_2);
}

void genetico_config::mutacao(individuo &j)
{
	string cromossomo = j.get_cromossomo();
	const int tamanho = cromossomo.length();

	for (int i = 0; i < tamanho; i++)
	{
		if (rand() % 100 < TX_MUTACAO)
		{
 			if (cromossomo[i] == '0')
			{
				cromossomo[i] = '1';
			}
			else if (cromossomo[i] == '1')
			{
				cromossomo[i] = '0';
			}
		}
	}

	j.set_cromossomo(cromossomo);
}

void genetico_config::set_numero_geracoes(int numero_geracoes)
{
	numero_geracoes_ = numero_geracoes;
}

void genetico_config::set_populacao(populacao* pop)
{
	pop_ = pop;
}
