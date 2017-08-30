#include "stdafx.h"
#include "Individuo.h"

individuo::individuo(): individuo_(0), aptidao_(0)
{
}

individuo::~individuo()
{
}

float individuo::get_aptidao() const
{
	return aptidao_;
}

float individuo::get_individuo() const
{
	return individuo_;
}

void individuo::set_individuo(float individuo)
{
	individuo_ = individuo;
}

void individuo::set_aptidao(float aptidao)
{
	aptidao_ = aptidao;
}

void individuo::gera_individuo()
{
	individuo_ = (rand()) / (RAND_MAX / 4.0);
	aptidao_ = individuo_ * sin(10 * M_PI * individuo_) + 5;
}
