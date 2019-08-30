#include <iostream>

using namespace std;

int numero;

struct Nodo{
	int num;
	Nodo *sig;
}*inicio;

class Pila{
	public:
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n->num = valor;
			n->sig = nullptr;
			return n;
		}

	void push(int valor){
		Nodo *n = crearNodo(valor);
		n->sig = inicio;
		inicio=n;
	}

	void pop(){
		Nodo *temp = inicio;
		inicio = inicio->sig;
		free(temp);
	}

	void mostrarPila(){
		Nodo *temp = inicio;
		if(!inicio){
			cout<<"Pila vacia"<<endl;
		}else{
			while(temp){
				cout<<temp->num<<", ";
				temp = temp->sig;
			};
		};
	}

	Pila(){
		inicio=nullptr;
	}

	void insertarDigitos(int entero){
		if(entero == 0) return;
		int digito = entero%10;
		push(digito);
		insertarDigitos(int(entero/10));
	}

};

int main(){
    Pila pila = Pila();

    cout<<"Ingresar datos"<<endl;
    cin>>numero;

    pila.insertarDigitos(numero);

    pila.mostrarPila();

    system("pause");
    return 0;
}
