#include "stdafx.h"
#include "GeneticoConfig.h"

#define TX_MUTACAO 2
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
	float S = 0;

	for (int i = 0; i < pop_->get_tamanho_populacao(); i++)
	{
		S += pop_->get_individuo(i).get_aptidao();
	}

	float p = (rand()) / (static_cast<float>(RAND_MAX / S));
	float t_parcial = 0;
	int i = 0;

	while (i < pop_->get_tamanho_populacao() && t_parcial < p)
	{
		t_parcial += pop_->get_individuo(i).get_aptidao();
		i++;
	}

	return i - 1;
}

void genetico_config::evolucao() const
{		
	for(int i = 0; i < numero_geracoes_; i++)
	{
		for(int j = 0; j < pop_->get_tamanho_populacao(); j++)
		{
			const int index_1 = selecao_roleta();
			int index_2;

			do {
				index_2 = selecao_roleta();
			} while (index_1 == index_2);
			
			if(pop_->elitismo() && (index_1 == pop_->get_melhor() || index_2 == pop_->get_melhor()))
			{
				continue;
			}

			const individuo individuo_selecionado_1 = pop_->get_individuo(index_1);
			const individuo individuo_selecionado_2 = pop_->get_individuo(index_2);
			
			
			if ((rand() % 100 + 1) >= TX_CRUZAMENTO)
			{
				cruzamento(individuo_selecionado_1, individuo_selecionado_2);
			}

			mutacao(individuo_selecionado_1);
			mutacao(individuo_selecionado_2);

			pop_->armazena_individuo(index_1, individuo_selecionado_1);
			pop_->armazena_individuo(index_2, individuo_selecionado_2);
		}
	}
}

void genetico_config::cruzamento(individuo x, individuo y)
{
	string cromossomo_1 = x.get_x().append(x.get_y());
	string cromossomo_2 = y.get_x().append(y.get_y());

	const int corte = rand() % 18;

	for (int i = corte + 1; i < cromossomo_1.length(); i++)
	{
		char aux = cromossomo_1[i];
		cromossomo_1[i] = cromossomo_2[i];
		cromossomo_2[i] = aux;
	}

	x.set_individuo(cromossomo_1.substr(0, corte), cromossomo_1.substr(corte + 1, cromossomo_1.length() - corte - 1));
	y.set_individuo(cromossomo_2.substr(0, corte), cromossomo_2.substr(corte + 1, cromossomo_2.length() - corte - 1));
}

void genetico_config::mutacao(individuo j)
{
	string cromossomo = j.get_x().append(j.get_y());

	for (int i = 0; i < cromossomo.length(); i++)
	{
		if ((rand() % 100) < TX_MUTACAO)
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

	j.set_individuo(cromossomo.substr(0, cromossomo.length() / 2), cromossomo.substr(cromossomo.length() / 2, cromossomo.length() / 2));
}

void genetico_config::set_numero_geracoes(int numero_geracoes)
{
	numero_geracoes_ = numero_geracoes;
}

void genetico_config::set_populacao(populacao* pop)
{
	pop_ = pop;
}
