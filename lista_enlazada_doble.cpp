#include <iostream>
using namespace std;
struct nodo{
	int key;
	struct nodo *pre;
	struct nodo	*next;
	
};
typedef struct nodo *Tipo_lista;

void insertar_final(Tipo_lista &cabeza,int x){
	Tipo_lista q,t;
	q = new(struct nodo);
	
	q->key = x;
	q->pre = NULL;
	q->next = NULL;
	
	if(cabeza == NULL){
		cabeza = q;
	} else {
		t = cabeza;
		while(t->next != NULL){
			t=t->next;
		}
		t->next = q;
		q->pre = t;
	}
}

void insertar_inicio(Tipo_lista &cabeza,int x){
	
	
	Tipo_lista q;
	
	q = new(struct nodo);
	q->key = x;
	q->next = cabeza;
	q->pre = NULL;
	
	cabeza = q;
	
}
void insertar_posicion(Tipo_lista &cabeza,int x,int pos){
	
	
}
		
void imprimir(Tipo_lista cabeza){
	Tipo_lista q;
	q = cabeza;
	while(q!= NULL){
		cout<<q->key<<"->";
		q=q->next;
	}
}

int main(int argc, char *argv[]) {
	Tipo_lista lista = NULL;
	//insertar_final(lista,1);
	//insertar_final(lista,2);
	//insertar_final(lista,3);
	
	insertar_inicio(lista,0);
	insertar_inicio(lista,1);
	
	imprimir(lista);
	
	return 0;
}

