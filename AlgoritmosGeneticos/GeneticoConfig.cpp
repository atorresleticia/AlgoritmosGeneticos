#include "stdafx.h"
#include "GeneticoConfig.h"
#include <ctime>

individuo individuo_selecionado_1;
individuo individuo_selecionado_2;
individuo filho;

int genetico::roleta(populacao &pop)
{
	auto s = 0;
	const auto tamanho_populacao = pop.get_tamanho_populacao();

	for (auto i = 0; i < tamanho_populacao; i++)
	{
		s += pop.get_individuo_em(i).get_aptidao();
	}

	const auto p = rand() % s + 1;
	auto t_parcial = 0;
	auto i = 0;

	while (i < tamanho_populacao && t_parcial < p)
	{
		t_parcial += pop.get_individuo_em(i).get_aptidao();
		i++;
	}

	return i - 1;
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
		int index_1;
		int index_2;

		do
		{
			index_1 = roleta(p);
			index_2 = roleta(p);
		} while (index_1 == index_2);

		individuo_selecionado_1 = p.get_individuo_em(index_1);
		individuo_selecionado_2 = p.get_individuo_em(index_2);
		//filho = individuo_selecionado_1.get_melhor(individuo_selecionado_2);

		const float c = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
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
