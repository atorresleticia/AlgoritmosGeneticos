#include "stdafx.h"
#include "Populacao.h"
#include <ctime>

populacao::populacao(int tamanho, bool gera_individuos, bool elitismo, int string_size)
{
	tamanho_ = tamanho;
	x_ = new individuo[tamanho_];

	if (gera_individuos)
	{
		int melhor_aptidao = 0;

		for (int i = 0; i < tamanho_; i++)
		{
			individuo novo_individuo;
			novo_individuo.gera_individuo(string_size);
			armazena_individuo(i, novo_individuo);
			if (novo_individuo.get_aptidao() > melhor_aptidao && elitismo)
			{
				posicao_melhor_ = i;
				melhor_aptidao = novo_individuo.get_aptidao();
			}
		}
	}
}

populacao::~populacao()
{
}

void populacao::armazena_individuo(int i, individuo x_i) const
{
	x_[i] = x_i;
}