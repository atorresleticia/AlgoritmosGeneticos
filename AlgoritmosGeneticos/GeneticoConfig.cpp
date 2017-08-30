#include "stdafx.h"
#include "GeneticoConfig.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

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

void genetico_config::evolucao()
{	
	populacao* nova_pop = new populacao(pop_->get_tamanho_populacao(), false);

	float S = 0;

	for(int i = 0; i < numero_geracoes_; i++)
	{
		for(int j = 0; j < pop_->get_tamanho_populacao(); j++)
		{
			int index = selecao_roleta();

			individuo individuo_selecionado = pop_->get_individuo(index);

			individuo_selecionado.set_individuo(individuo_selecionado
			.get_individuo() + (rand() % 100000000 / 1e8) - 0.5);
			
			if (individuo_selecionado.get_individuo() > 4) { individuo_selecionado.set_individuo(4); }
			if (individuo_selecionado.get_individuo() < 0) { individuo_selecionado.set_individuo(0); }

			individuo_selecionado.set_aptidao(individuo_selecionado.get_individuo() * sin(10 * M_PI * individuo_selecionado.get_individuo()) + 5);

			if (individuo_selecionado.get_aptidao() >= pop_->get_individuo(index).get_aptidao())
			{
				nova_pop->armazena_individuo(j, individuo_selecionado);
			}
			else
			{
				nova_pop->armazena_individuo(j, pop_->get_individuo(index));
			}

			pop_->armazena_individuo(j, nova_pop->get_individuo(j));
		}
	}
}

void genetico_config::set_numero_geracoes(int numero_geracoes)
{
	numero_geracoes_ = numero_geracoes;
}

void genetico_config::set_populacao(populacao* pop)
{
	pop_ = pop;
}
