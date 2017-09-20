#include "stdafx.h"
#include "Individuo.h"

individuo::~individuo()
{
}

int individuo::get_aptidao() const
{
	return aptidao_;
}

string individuo::get_x() const
{
	return gene_x_;
}

string individuo::get_y() const
{
	return gene_y_;
}

void individuo::set_individuo(string x, string y)
{
	gene_x_ = x;
	gene_y_ = y;
}

void individuo::set_x(string x)
{
	gene_x_ = x;
}

void individuo::set_y(string y)
{
	gene_y_ = y;
}

/* 
 * A aptidão é definida pela contagem de 1's no cromossomo do individuo
 */
void individuo::set_aptidao(string x, string y)
{
	int count = 0;

	for (int i = 0; i < x.length(); i++) 
	{
		if (x[i] == '1')
		{
			count++;
		}
		if (y[i] == '1')
		{
			count++;
		}
	}

	aptidao_ = count;
}

void individuo::set_aptidao(string x)
{
	int count = 0;

	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == '1')
		{
			count++;
		}
	}

	aptidao_ = count;
}

/*
 * A geração dos genes do individuo é feita aplicando um rand para 0 ou 1 em cada alelo
 */
void individuo::gera_individuo(int tamanho)
{
	gene_x_ = gene_y_ = "";
	int t = tamanho / 2;

	for (auto i = 0; i < t; i++)
	{
		gene_x_.append(to_string(rand() % 2));
		gene_y_.append(to_string(rand() % 2));
	}

	set_aptidao(gene_x_, gene_y_);
}