#include "stdafx.h"
#include "Individuos.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

individuos::individuos(): individuo_(0), aptidao_(0)
{
}

individuos::~individuos()
{
}

float individuos::get_aptidao() const
{
	return aptidao_;
}

float individuos::get_individuo() const
{
	return individuo_;
}

void individuos::set_individuo(float individuo)
{
	individuo_ = individuo;
}

void individuos::set_aptidao(float aptidao)
{
	aptidao_ = aptidao;
}

void individuos::gera_individuo()
{
	individuo_ = (rand()) / (RAND_MAX / 4.0);
	aptidao_ = individuo_ * sin(10 * M_PI * individuo_) + 5;
}
