#include <iostream>
#include <stdlib.h>

using namespace std;
struct nodo{
	int key;
	struct nodo *next;
};
typedef struct nodo *Tipo_lista;


//funcion para insertar al inicio de lista 
void insert_inicio(Tipo_lista &cabeza,int x){
	Tipo_lista q;
	
	q = new(struct nodo);
	q->key = x;
	q->next = cabeza;
	
	cabeza = q;
	
}
//funcion para insertar al final de una lista
void insert_final(Tipo_lista &cabeza,int x){
	Tipo_lista t,q;
	q=new(struct nodo);
	
	q->key = x;
	q->next = NULL;
	
	if(cabeza==NULL){
		
		cabeza = q;
		
	}
	else{
		t = cabeza;
		
		while(t->next != NULL){
			t=t->next;
		}
		t->next = q;
		
	}
	
}
	
	
//funcion para insertar en una posicion n
void insert_posicion(Tipo_lista &cabeza,int x,int pos){
	Tipo_lista q,t;
	q = new(struct nodo);
	q -> key = x;
	
	//q-> next = NULL;
	
	if(pos == 1){
		q->next = cabeza;
		cabeza = q;
		
	}else {
		
		t = cabeza;
		
		for(int i=1; t!=NULL ;i++){
			
			if(i==pos-1){
				q->next = t->next;
				t->next = q;
				return;
				
			}
			t = t->next;
			
		}
	
		
	}
	
}
// calcula el tamaño de una lista
int tamanio(Tipo_lista cabeza){
	int cont=0;
	Tipo_lista q = cabeza;
	while(q != NULL){
		cont++;
		q=q->next;
	}
	return cont;
}

// funcion que elimina el primer elemnto de una lista
void delete_primer(Tipo_lista &cabeza){
	Tipo_lista t;
	
	t = cabeza;
	t = t->next;
	cabeza=t;
	
}
//funcion que elimina el ultimo elemto de una lista
void delete_ultimo(Tipo_lista &cabeza){
	Tipo_lista q;
	
	q = cabeza;
	
	while(q->next->next != NULL){
		q=q->next;
	}
	q->next = NULL;
	
	//cout<<q->key;

	
}
	
void delete_position(Tipo_lista &cabeza,int pos){
	Tipo_lista q,t;
	q=cabeza;
	
	
	if(pos==1){
		q = cabeza;
		q = q->next;
		cabeza=q;
	} else {
		t = cabeza;
		
		for(int i=1 ; t!=NULL ;i++){
			if(i==pos-1){
				q->next = t->next;
				t->next = q;
				return;
			}
			t = t->next;
		}
		
	}
}
//buscar elemto de una lista 
int buscar_elemnto(Tipo_lista cabeza,int x){
	int cont=1;
	Tipo_lista q = cabeza;
	while(q != NULL && q->key != x){
		q=q->next;
		cont++;
	}
	if(cont < tamanio(cabeza)){
		return cont;
	}else {
		return NULL;
	}
	
	
}

//imprimir lista 
void imprimir(Tipo_lista cabeza){
	
	Tipo_lista q = cabeza;
	
	while(q != NULL){
		cout<<q->key<<"->";
		q = q->next;
		
	}
	
}
	

int main(int argc, char *argv[]) {
	Tipo_lista lista = NULL;
	
	insert_inicio(lista,2);
	insert_inicio(lista,3);
	insert_inicio(lista,4);
	
	insert_final(lista,1);
	
	insert_posicion(lista,10,2);
	insert_posicion(lista,0,3);
	
	
	imprimir(lista);
	
	cout<<endl;
	delete_primer(lista);

	imprimir(lista);
	cout<<endl;
	delete_ultimo(lista);
	imprimir(lista);
	cout<<"elemto a uscar : "<<endl;
	cout<<"econtrado pos :"<<buscar_elemnto(lista,3);
	cout<<endl;
	imprimir(lista);
	
	
	
	return 0;
}

