#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

class individuos
{
private:
	float individuo_;
	float aptidao_;

public:
	individuos();
	~individuos();
	float get_aptidao() const;
	float get_individuo() const;
	void set_individuo(float individuo);
	void set_aptidao(float aptidao);
	void gera_individuo();
};


#endif

