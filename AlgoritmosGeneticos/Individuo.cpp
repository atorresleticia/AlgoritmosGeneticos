#include "stdafx.h"
#include "Individuo.h"

void individuo::gera_individuo(int tamanho_individuo)
{
	tamanho_individuo_ = tamanho_individuo;
	cromossomo_ = "";

	for (auto i = 0; i < tamanho_individuo_; i++)
	{
		cromossomo_.append(std::to_string(rand() % 2));
	}
	set_aptidao(cromossomo_);
}

void individuo::set_aptidao(std::string cromossomo)
{
	aptidao_ = 0;

	for (auto i = 0; i < tamanho_individuo_; i++)
	{
		if (cromossomo[i] == '1') { aptidao_++; }
	}
}

void individuo::set_aptidao(int aptidao)
{
	aptidao_ = aptidao;
}

individuo individuo::get_melhor(individuo& a)
{
	individuo melhor = this->get_aptidao() > a.get_aptidao() ? *this : a;
	return melhor;
}

void individuo::set_cromossomo(std::string cromossomo)
{
	cromossomo_ = cromossomo;
	set_aptidao(cromossomo_);
}