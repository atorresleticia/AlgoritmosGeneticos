#include "stdafx.h"
#include "Populacao.h"
#include <ostream>
#include <iostream>

populacao::populacao(): x_(nullptr), tamanho_(0)
{
}

populacao::populacao(int tamanho_populacao, bool gera_individuos)
{
	x_ = new individuos[tamanho_populacao];

	if (gera_individuos)
	{
		for (int i = 0; i < tamanho_populacao; i++)
		{
			individuos novo_individuo;
			novo_individuo.gera_individuo();
			armazena_individuo(i, novo_individuo);
		}
	}
}

populacao::~populacao()
{
}

void populacao::armazena_individuo(int i, individuos x_i) const
{
	x_[i] = x_i;
}

int populacao::get_tamanho_populacao() const
{
	return sizeof(x_) / sizeof(x_[0]);
}