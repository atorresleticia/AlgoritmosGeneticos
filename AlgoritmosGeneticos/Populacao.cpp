#include "stdafx.h"
#include "Populacao.h"

populacao::populacao(): x_(nullptr), tamanho_(0)
{
}

populacao::populacao(int tamanho_populacao, bool gera_individuos)
{
	tamanho_ = tamanho_populacao;

	x_ = new individuo[tamanho_];

	if (gera_individuos)
	{
		const float melhor_aptidao = 0;

		for (int i = 0; i < tamanho_; i++)
		{
			individuo novo_individuo;
			novo_individuo.gera_individuo();
			armazena_individuo(i, novo_individuo);
			if (novo_individuo.get_aptidao() > melhor_aptidao) { posicao_melhor_ = i; }
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