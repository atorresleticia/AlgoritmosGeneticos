#include "stdafx.h"
#include "GeneticoConfig.h"
#include <ctime>

individuo individuo_selecionado_1;
individuo individuo_selecionado_2;
individuo filho;

individuo s1;
individuo s2;
individuo filho_s;

individuo genetico::torneio(populacao& p)
{
	const int tamanhoTorneio = 4;
	populacao* aux = new populacao(tamanhoTorneio, p.get_individuo_em(0).get_tamanho_individuo(), false);
	for (int i = 0; i < tamanhoTorneio; i++)
	{
		aux->armazena_individuo(i, p.get_individuo_em(rand() % p.get_tamanho_populacao()));
	}
	return aux->get_melhor();
}

individuo genetico::cruzamento(individuo& a, individuo& b)
{
	std::string c1 = a.get_cromossomo();
	std::string c2 = b.get_cromossomo();

	const int p_corte = rand() % (c1.length() - 1);
	for (int i = p_corte + 1; i < a.get_tamanho_individuo(); i++)
	{
		const char aux = c1[i];
		c1[i] = c2[i];
		c2[i] = aux;
	}

	a.set_cromossomo(c1);
	b.set_cromossomo(c2);

	return a.get_melhor(b);
}

void genetico::mutacao(individuo& a) const
{
	std::string c = a.get_cromossomo();
	const auto tamanho_individuo = a.get_tamanho_individuo();

	for (auto i = 0; i < tamanho_individuo; i++)
	{
		const float m = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		//std::cout <<"tx m: " << m << " ";
		if (m < tx_mutacao_)
		{
			if (c[i] == '0')
			{
				c[i] = '1';
			}
			else
			{
				c[i] = '0';
			}
		}
	}

	a.set_cromossomo(c);
}

void genetico::evolucao(populacao& p, populacao& nova_p)
{
	auto j = 0;

	if (elitismo_)
	{
		nova_p.armazena_individuo(0, p.get_melhor());
		j = 1;
	}

	for (auto i = j; i < p.get_tamanho_populacao(); i++)
	{

		individuo_selecionado_1 = torneio(p);
		individuo_selecionado_2 = torneio(p);

		float c = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		if (c < tx_cruzamento_)
		{
			filho = cruzamento(individuo_selecionado_1, individuo_selecionado_2);
		}

		mutacao(filho);

		nova_p.armazena_individuo(i, filho);
	}
	for(auto i = 0; i < p.get_tamanho_populacao(); i++)
	{
		p.armazena_individuo(i, nova_p.get_individuo_em(i));
		p.get_individuo_em(i).set_tamanho_individuo(nova_p.get_individuo_em(i).get_tamanho_individuo());
	}
}
