#include "stdafx.h"
#include "Individuo.h"

#define MIN -5
#define MAX 5

individuo::individuo(): x_(0), y_(0), aptidao_(0)
{
}

individuo::~individuo()
{
}

float individuo::get_aptidao() const
{
	return aptidao_;
}

float individuo::get_x() const
{
	return x_;
}

float individuo::get_y() const
{
	return y_;
}

void individuo::set_individuo(float x, float y)
{
	x_ = x;
	y_ = y;
}

void individuo::set_x(float x)
{
	x_ = x;
}

void individuo::set_y(float y)
{
	y_ = y;
}

void individuo::set_aptidao(float x, float y)
{
	aptidao_ = 0.97 * exp(-(pow((x + 3), 2) + pow((y + 3), 2)) / 5)
		+ 0.98 * exp(-(pow((x + 3), 2) + pow((y - 3), 2)) / 5)
		+ 0.99 * exp(-(pow((x - 3), 2) + pow((y + 3), 2)) / 5)
		+ 1.0 * exp(-(pow((x - 3), 2) + pow((y - 3), 2)) / 5);
}

void individuo::gera_individuo()
{
	x_ = (float(rand()) / float(RAND_MAX)) * (MAX - MIN) + MIN;
	y_ = (float(rand()) / float(RAND_MAX)) * (MAX - MIN) + MIN;

	set_aptidao(x_, y_);
}
