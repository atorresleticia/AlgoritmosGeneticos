#ifndef POPULACAO_H
#define POPULACAO_H
#pragma once

#include "Individuo.h"

class populacao
{
public:

	populacao(int tamanho_populacao, int tamanho_cromossomo, bool gera_individuos);
	populacao(int tamanho_populacao);
	populacao() = default;

	individuo* get_individuos() const
	{
		return individuos_;
	}

	individuo get_individuo_em(int i) const
	{
		return individuos_[i];
	}

	int get_tamanho_populacao() const
	{
		return tamanho_populacao_;
	}

	individuo get_melhor();
	individuo get_melhor(individuo& a, individuo& b);
	void armazena_individuo(int i, individuo x_i) const;

private:
	individuo* individuos_;
	individuo melhor_;
	int tamanho_populacao_;
};


#endif
