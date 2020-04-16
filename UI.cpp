#include "UI.h"

//Desc: creeaza un obiect de tip UI
//In: -
//Out: o instanta a clasei UI
UI::UI()
{
}

//Desc: creeaza un obiect de tip UI
//In: un obiect de tip Service
//Out: o instanta a clasei UI
UI::UI(Service& s) {
	this->serv = s;
}

//Desc: distruge un obiect de tip UI
//In: obiectul curent
//Out: -
UI::~UI()
{
}

//Desc: functie pentru afisarea meniului principal al functiei
//In: -
//Out: -
void UI::meniuPrincipal() {
	cout << "Optiunile sunt:\n";
	cout << "\t1. Adaugare prajitura.\n";
	cout << "\t2. Stergere prajitura.\n";
	cout << "\t3. Modificare prajitura.\n";
	cout << "\t4. Afisare prajituri.\n";
	cout << "\t5. Afisare medie pret pentru fiecare ingredient.\n";
	cout << "\tx. Inchidere aplicatie.\n";
}

//Desc: functie pentru gestionarea adaugarii unei prajituri
//In: -
//Out: -
void UI::adaugare() {
	int id;
	string nume, ingrediente;
	double pret;

	cout << "ID = ";
	cin >> id;
	cin.get();
	cout << "nume = ";
	getline(cin, nume);
	cout << "ingrediente = ";
	getline(cin, ingrediente);
	cout << "pret = ";
	cin >> pret;
	cin.get();

	bool reusit = this->serv.addPrajitura(id, nume, ingrediente, pret);
	if (reusit == false)
		cout << "ID-ul exista deja!\n";
}

//Desc: functie pentru gestionarea stergerii unei prajituri
//In: -
//Out: -
void UI::stergere() {
	int id;
	cout << "ID-ul prajiturii de sters: ";
	cin >> id;
	cin.get();

	bool reusit = this->serv.delPrajitura(id);
	if (reusit == false)
		cout << "Id-ul nu exista!\n";
}

//Desc: functie pentru gestionarea modificarii unei prajituri
//In: -
//Out: -
void UI::modificare() {
	int idVechi;
	string numeNou, ingredienteNoi, pretNou;

	cout << "Id-ul prajiturii de modificat: ";
	cin >> idVechi;
	cin.get();
	cout << "Noul nume sau enter pentru a nu modifica: ";
	getline(cin, numeNou);
	cout << "Noile ingrediente sau enter pentru a nu modifica: ";
	getline(cin, ingredienteNoi);
	cout << "Noul pret sau spatiu pentru a nu modifica: ";
	getline(cin, pretNou);

	double pret;
	if (pretNou.empty())
		pret = -1;
	else
		pret = stod(pretNou);

	bool reusit = this->serv.updatePrajitura(idVechi, numeNou, ingredienteNoi, pret);
	if (reusit == false)
		cout << "Id-ul nu exista!\n";
}

//Desc: functie pentru gestionarea adaugarii listei de prajituri
//In: -
//Out: -
void UI::afisare() {
	vector<Prajitura> v = this->serv.getAll();

	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it;
}

//Desc:afiseaza media preturilor prajiturilor pentru fiecare ingredient 
//In: -
//Out: -
void UI::afisare_medie_ingrediente() {
	map<string, pair<double, int> > lista = this->serv.getNrPraj_Pret_perIngredient();
	for (auto it = lista.begin(); it != lista.end(); it++)
		cout << it->first << ": " << it->second.first / it->second.second << '\n';
}

void UI::runUI() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuPrincipal();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);

		if (comanda == "1")
			this->adaugare();
		else if (comanda == "2")
			this->stergere();
		else if (comanda == "3")
			this->modificare();
		else if (comanda == "4")
			this->afisare();
		else if (comanda == "5") {
			this->afisare_medie_ingrediente();
		}
		else if (comanda == "x") {
			cout << "Ati parasit aplicatia.\n";
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}