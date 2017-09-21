#ifndef POPULACAO_H
#define POPULACAO_H

#include "Individuo.h"

class populacao
{
private:
	individuo* x_;
	int tamanho_;
	int posicao_melhor_;

public:
	/*
	 * Construtor quando se quer definir uma população
	 * gera_individuos = true, quando se quer gerar um individuo
	 * gera_individuos = false, quando é pra gerar um individuo vazio
	 */
	populacao(int tamanho, bool gera_individuos, bool elitismo, int string_size);
	populacao() = default;
	~populacao();


	populacao(individuo* x, int tamanho, int posicao_melhor)
		: x_(x),
		  tamanho_(tamanho),
		  posicao_melhor_(posicao_melhor)
	{
	}

	void armazena_individuo(int i, individuo x_i) const;
	int get_tamanho_populacao() const { return tamanho_; };
	individuo get_individuo(int i) const { return x_[i]; }
	int get_melhor() const { return posicao_melhor_; };

};

#endif
