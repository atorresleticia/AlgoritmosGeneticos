#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <string>

using namespace std;

class individuo
{
private:

	string gene_x_;	//gene1
	string gene_y_;	//gene2
	int aptidao_;
	string cromossomo_;

public:

	individuo() = default;

	individuo(const string& gene_x, const string& gene_y, int aptidao)
		: gene_x_(gene_x),
		  gene_y_(gene_y),
		  aptidao_(aptidao)
	{
	}


	individuo(int aptidao, const string& cromossomo)
		: aptidao_(aptidao),
		  cromossomo_(cromossomo)
	{
	}

	~individuo();

	int get_aptidao() const;
	string get_x() const;
	string get_y() const;
	void set_x(string gene_x);
	void set_y(string gene_y);
	void set_cromossomo(string cromossomo);
	string get_cromossomo() const { return cromossomo_; };
	void set_individuo(string gene_x, string gene_y);
	void set_aptidao(string cromossomo);
	void set_aptidao(int aptidao);
	void gera_individuo(int tamanho);
};

#endif

