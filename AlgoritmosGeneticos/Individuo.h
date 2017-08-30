#ifndef INDIVIDUO_H
#define INDIVIDUO_H

class individuo
{
private:
	float individuo_;
	float aptidao_;

public:
	individuo();
	~individuo();

	float get_aptidao() const;
	float get_individuo() const;
	void set_individuo(float individuo);
	void set_aptidao(float aptidao);
	void gera_individuo();
};


#endif

