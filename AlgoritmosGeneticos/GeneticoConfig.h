#ifndef GENETICOCONFIG_H
#define GENETICOCONFIG_H

#include "Populacao.h"

class genetico_config
{
private:
	int numero_geracoes_;
	populacao* pop_;

public:

	genetico_config(int numero_geracoes, populacao* pop);
	static int selecao_roleta(populacao* pop, int soma_aptidao);
	void evolucao() const;
	void set_numero_geracoes(int numero_geracoes);
	void set_populacao(populacao* pop);
	int get_numero_geracoes() const { return numero_geracoes_; }
};

#endif
