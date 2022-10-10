#include <iostream>
using namespace std;

class Nodo {
public:
	Nodo(int,Nodo * =NULL);
	friend class Lista;
private:
	int valor;
	Nodo *sig;
};

Nodo::Nodo(int v,Nodo *s)
{
	valor = v;
	sig =s;
}
class Lista {
public:
	Lista();
	~Lista();
	void insertarPrimero(int);
	void imprimir();
private:
	Nodo* cabeza;
};

Lista::Lista() {
	cabeza = NULL;
}

Lista::~Lista()
{
	Nodo *temp = cabeza;
	Nodo *borrar;
	while(temp != NULL)
	{
		borrar = temp;
		temp = temp->sig;
		delete borrar;
	}
	cabeza = NULL;
}
void Lista::insertarPrimero(int v)
{
	Nodo *nuevo = new Nodo(v);
	if (cabeza == NULL)
	{
		nuevo->sig =NULL;
		cabeza = nuevo;
	}
	else
	{
		nuevo->sig = cabeza;
		cabeza = nuevo;
	}
	
	
}
void Lista::imprimir()
{
	Nodo *temp = cabeza;
	while(temp!=NULL)
	{
		cout << temp->valor << "-";
		temp = temp->sig;
	}
	cout << "\n";
}

int main(int argc, char *argv[])
{
	
	Lista *listaA;
	Lista *listaB;
	Lista *listaC;
	Lista *listaD;
	
	listaA = new Lista();
	listaB = new Lista();
	listaC = new Lista();
	listaD = new Lista();
	
	listaA->insertarPrimero(5);
	listaA->insertarPrimero(8);
	listaA->insertarPrimero(9);
	listaA->insertarPrimero(10);
	listaA->imprimir();
	
	
	listaB->insertarPrimero(7);
	listaB->insertarPrimero(8);
	listaB->insertarPrimero(9);
	listaB->imprimir();
	
	listaC->insertarPrimero(4);
	listaC->insertarPrimero(5);
	listaC->insertarPrimero(6);
	listaA->insertarPrimero(10);
	listaC->imprimir();
	
	listaD->insertarPrimero(10);
	listaD->insertarPrimero(1);
	
	listaD->imprimir();
	
	delete listaA;
	delete listaB;
	delete listaC;
	delete listaD;
	
	return 0;
}
