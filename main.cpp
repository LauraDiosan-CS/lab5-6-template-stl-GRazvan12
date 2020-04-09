#include <iostream>
#include "Teste.h"
#include "UI.h"

using namespace std;

int main()
{
	teste();

	Repo<Prajitura>* repo;
	repo = new RepoFile<Prajitura>("Fisier.txt");
	Service serv(repo);
	UI ui(serv);

	ui.runUI();

	delete repo;

	return 0;
}