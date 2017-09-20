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

public:

	individuo() = default;

	individuo(const string& gene_x, const string& gene_y, int aptidao)
		: gene_x_(gene_x),
		  gene_y_(gene_y),
		  aptidao_(aptidao)
	{
	}
	~individuo();

	int get_aptidao() const;
	string get_x() const;
	string get_y() const;
	void set_x(string gene_x);
	void set_y(string gene_y);
	void set_individuo(string gene_x, string gene_y);
	void set_aptidao(string gene_x, string gene_y);
	void gera_individuo(int tamanho);
};

#endif

