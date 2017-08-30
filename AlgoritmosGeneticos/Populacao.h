#ifndef POPULATION_H
#define POPULATION_H
#include "Individuos.h"

class populacao
{

private:
	individuos* x_;
	int tamanho_;

public:
	populacao();
	populacao(int tamanho_populacao, bool gera_individuos);
	void armazena_individuo(int i, individuos x_i) const;
	int get_tamanho_populacao() const;
	individuos get_individuo(int i) const { return x_[i]; }

};

#endif
