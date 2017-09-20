#ifndef POPULACAO_H
#define POPULACAO_H

#include "Individuo.h"

class populacao
{
private:
	individuo* x_;
	int tamanho_;
	int posicao_melhor_;
	bool elitismo_;

public:
	/*
	 * Construtor quando se quer definir uma população
	 * gera_individuos = true, quando se quer gerar um individuo
	 * gera_individuos = false, quando é pra gerar um individuo vazio
	 */
	populacao(int tamanho_populacao, bool gera_individuos, bool elitismo, int string_size);
	populacao();
	~populacao();

	void armazena_individuo(int i, individuo x_i) const;
	int get_tamanho_populacao() const { return tamanho_; };
	individuo get_individuo(int i) const { return x_[i]; }
	int get_melhor() const { return posicao_melhor_; };
	bool elitismo() const { return elitismo_; }

};

#endif
