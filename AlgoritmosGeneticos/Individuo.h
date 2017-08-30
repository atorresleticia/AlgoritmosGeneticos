#ifndef INDIVIDUO_H
#define INDIVIDUO_H

class individuo
{
private:
	float x_;
	float y_;
	float aptidao_;

public:
	individuo();
	~individuo();

	float get_aptidao() const;
	float get_x() const;
	float get_y() const;
	void set_x(float x);
	void set_y(float y);
	void set_individuo(float x, float y);
	void set_aptidao(float x, float y);
	void gera_individuo();
};


#endif

