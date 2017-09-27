#ifndef GENETICOCONFIG_H
#define GENETICOCONFIG_H
#pragma once
#include "Populacao.h"

class genetico
{
public:

	genetico(float tx_mutacao, float tx_cruzamento, bool elitismo)
		: tx_mutacao_(tx_mutacao),
		tx_cruzamento_(tx_cruzamento),
		elitismo_(elitismo)
	{
	}

	genetico() = default;
	~genetico() = default;

	int roleta(populacao& p) const;
	individuo cruzamento(individuo& a, individuo& b);
	void mutacao(individuo& a);
	void evolucao(populacao& p, populacao& nova_p);

private:
	float tx_mutacao_;
	float tx_cruzamento_;
	bool elitismo_;
};

#endif
