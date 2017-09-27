#include "stdafx.h"
#include "GeneticoConfig.h"
#include <ctime>

individuo individuo_selecionado_1;
individuo individuo_selecionado_2;
individuo filho;

int genetico::roleta(populacao &pop) const
{
	int s = 0;
	const int tamanho_populacao = pop.get_tamanho_populacao();

	for (int i = 0; i < tamanho_populacao; i++)
	{
		s += pop.get_individuo_em(i).get_aptidao();
	}

	const int p = rand() % s + 1;
	int t_parcial = 0;
	int i = 0;

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

	const int p_corte = rand() % a.get_tamanho_individuo();

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

void genetico::mutacao(individuo& a)
{
	std::string c = a.get_cromossomo();
	const int tamanho_individuo = a.get_tamanho_individuo();

	for (int i = 0; i < tamanho_individuo; i++)
	{
		const float m = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		//std::cout << m << " ";
		if (m < tx_mutacao_)
		{
			if (c[i] == '0')
			{
				c[i] = '1';
			}
			else if (c[i] == '1')
			{
				c[i] = '0';
			}
		}
	}

	a.set_cromossomo(c);
}

populacao* genetico::evolucao(populacao& p)
{
	populacao* nova_p = new populacao(p.get_tamanho_populacao(), p.get_individuo_em(0).get_tamanho_individuo(), false);
	int j = 0;

	if (elitismo_)
	{
		nova_p->armazena_individuo(0, p.get_melhor());
		auto aux = nova_p->get_individuo_em(0);
		j = 1;
	}

	for (int i = j; i < p.get_tamanho_populacao(); i++)
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
		filho = individuo_selecionado_1.get_melhor(individuo_selecionado_2);

		const float c = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		//std::cout << c << std::endl;
		if (c < tx_cruzamento_)
		{
			filho = cruzamento(individuo_selecionado_1, individuo_selecionado_2);
		}
		nova_p->armazena_individuo(i, filho);
		auto aux = nova_p->get_individuo_em(i);
	}

	for (int i = j; i < nova_p->get_tamanho_populacao(); i++)
	{
		auto aux = nova_p->get_individuo_em(i);
		mutacao(aux);
	}

	return nova_p;
}
