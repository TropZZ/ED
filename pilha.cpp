#include <iostream>
using namespace std;

class noh{
	friend class pilha;

	private:
		int dado;
		noh* proximo;
	public: 
		noh(int num = 0);
	
};

noh::noh(int num){
	dado = num;
	proximo = NULL;
}

class pilha{
	private:
		noh* topo;
		int _tamanho;
	public:
		pilha();
		void empilha(int valor);
		int desempilha();
		int espia();
		void imprime();
		void reempilha(int vetor[], int tam);
		void xCy();
		void ex4(int num);
		void ex5(int n,int m);
		
};

pilha::pilha(){
	topo = NULL;
	_tamanho = 0;
}

void pilha::empilha(int valor){
	noh* aux = new noh;
	
	aux->dado = valor;
	aux->proximo = topo;
	topo = aux;
	_tamanho++;
	
}

int pilha::desempilha(){
	noh* aux;
	int removido;
	
	removido = topo->dado;
	aux = topo;
	topo = topo->proximo;
	delete aux;
	_tamanho--;
	
	return removido;
	
}

int pilha::espia(){
	return topo->dado;
}


void pilha::imprime(){
	int i = 0, tam = _tamanho;
	int aux, vetor[tam];
	while(_tamanho != 0){
		cout << topo->dado << endl;
		aux = desempilha();
		vetor[i] = aux;
		i++;
	}
	
	reempilha(vetor, tam);
	
}

void pilha::reempilha(int vetor[], int tam){
	for (int i = tam-1; i >= 0; i--)
	{
		empilha(vetor[i]);
	}
}

void pilha::xCy(){
	
	pilha umaPilha;
	
	bool resposta = true;
	
	while(topo->dado != 3){
		umaPilha.empilha(desempilha());
	}
	
	desempilha();
	
	while(resposta and topo != NULL){
		cout << topo->dado << " " << umaPilha.topo->dado << endl;
		
		if(topo->dado == umaPilha.topo->dado){
			resposta = true;
		}
		else{
			resposta = false;
		}
		
		desempilha();
		umaPilha.desempilha();
	}
	
	if(resposta){
		cout << "VERDADEIRO" <<	endl;
	}
	else{
		cout << "FALSO" <<	endl;
	}
	
}




int main()
{
    pilha novaPilha;
    
    int valor, tam, n, m;
    
    //cin >> n >> m;
    
    
    
    for (int i = 0; i < 5; i++)
	{
		cin >> valor;
		novaPilha.empilha(valor);
	}
	
	cout << endl;
	
	novaPilha.imprime();
	
	cout << endl;
	
	novaPilha.xCy();
	//novaPilha.ex4(num);
	
    return 0;
}

