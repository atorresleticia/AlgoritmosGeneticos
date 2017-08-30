#ifndef POPULACAO_H
#define POPULACAO_H

#include "Individuo.h"

class populacao
{
private:
	individuo* x_;
	int tamanho_;

public:
	populacao();
	populacao(int tamanho_populacao, bool gera_individuos);
	~populacao();

	void armazena_individuo(int i, individuo x_i) const;
	int get_tamanho_populacao() const { return tamanho_; };
	individuo get_individuo(int i) const { return x_[i]; }

};

#endif
