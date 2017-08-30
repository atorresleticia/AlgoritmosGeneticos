#include "stdafx.h"
#include "GeneticoConfig.h"

#define SIZE_NUVEM 20
#define TX_MUTACAO 3
#define TX_CRUZAMENTO 70

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
	
	for(int i = 0; i < numero_geracoes_; i++)
	{
		cruzamento();
		for(int j = 0; j < pop_->get_tamanho_populacao(); j++)
		{
			const int index = selecao_roleta();

			if(index == pop_->get_melhor())
			{
				continue;
			}

			individuo individuo_selecionado = pop_->get_individuo(index);
			individuo aux = pop_->get_individuo(index);

			for (int k = 0; k < SIZE_NUVEM; k++)
			{
				individuo_selecionado.set_individuo(individuo_selecionado.get_x() + (rand() % 100000000 / 1e8) - 0.1, individuo_selecionado.get_y() + (rand() % 100000000 / 1e8) - 0.1);
				
				if (individuo_selecionado.get_x() >  5) { individuo_selecionado.set_x( 5); }
				if (individuo_selecionado.get_x() < -5) { individuo_selecionado.set_x(-5); }
				if (individuo_selecionado.get_y() >  5) { individuo_selecionado.set_y( 5); }
				if (individuo_selecionado.get_y() < -5) { individuo_selecionado.set_y(-5); }

				individuo_selecionado.set_aptidao(individuo_selecionado.get_x(), individuo_selecionado.get_y());

				if (individuo_selecionado.get_aptidao() > aux.get_aptidao())
				{
					aux = individuo_selecionado;
				}
			}
		
			nova_pop->armazena_individuo(j, aux);

			pop_->armazena_individuo(j, nova_pop->get_individuo(j));
		}
		// aplicar mutação em cada individuo da população
		// mutação -> aplicar perturbação com range maior || gerar novo individuo
		// tx de mutação -> rand entre 0-100, menor que tx de mutação faz mutação
	}
}

void genetico_config::cruzamento()
{
	
}

void genetico_config::mutacao()
{
}

void genetico_config::set_numero_geracoes(int numero_geracoes)
{
	numero_geracoes_ = numero_geracoes;
}

void genetico_config::set_populacao(populacao* pop)
{
	pop_ = pop;
}
