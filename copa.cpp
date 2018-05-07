#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include<fstream>

using namespace std;

/** SESSÃO Figura **/

class Figura{
    protected:
        Figura* ant;
        int numero;
        int qtd;
        Figura* prox;
    public:
    
    Figura(int numero){
		this -> numero = numero;
		ant = NULL;
		prox = NULL;
    }
    
    void toString(){
		cout << numero << "(" << qtd << ")";
    }
    
    void setAnt(Figura* ant){
    	this -> ant = ant;  
    }
    
    void setNumero(int numero){
       this -> numero = numero;  
    }
    
    void setQtd(int qtd){
       this -> qtd = qtd;  
    }
    
    void setProx(Figura* prox){
       this -> prox = prox;  
    }
    
    Figura* getAnt(){
       return ant;
    }
    
    int getNumero(){
       return numero;
    }
    
    int getQtd(){
       return qtd;
    }
    
    Figura* getProx(){
       return prox;
    }
};

class ListaFigura{
   private:
		Figura* inicio;
		Figura* fim;
   public:
//-------------------------------------------------------------
   ListaFigura() : inicio(NULL), fim(NULL)
	{  }
//-------------------------------------------------------------
   ~ListaFigura(){
      Figura* atual = inicio;
      while(atual != NULL){
         Figura* aux = atual;
         atual = atual -> getProx();
         delete aux;
      }
   }
//-------------------------------------------------------------
   Figura* getInicio(){
        return inicio;
   }

   bool isEmpty(){
       return (inicio==NULL);
   }

   void insere(Figura* pFigura){
   	  pFigura -> setQtd(1);
   	  
      if(isEmpty()){
         inicio = pFigura;
         fim = pFigura;
		}
		else{
              if(pFigura -> getNumero() > fim -> getNumero()){
	              pFigura -> setAnt(fim);
	              fim -> setProx(pFigura);
	              fim = pFigura;
	          }
	          else{
			  	  Figura* atual = inicio;
	              while(atual != NULL && atual -> getNumero() < pFigura->getNumero()){
	                 atual = atual->getProx();
	              }
	              
	              if(atual -> getNumero() == pFigura->getNumero()){
	              	atual -> setQtd( atual -> getQtd() + 1 );
				  }else{
				  	Figura* anterior = atual -> getAnt();
				  	if(anterior != NULL){
	                  pFigura -> setAnt(anterior);
	                  pFigura -> setProx(atual);
	                  atual -> setAnt(pFigura);
	                  anterior -> setProx(pFigura);
	                }
	                else{
	                  inicio -> setAnt(pFigura);
	                  pFigura -> setProx( inicio);
	                  inicio = pFigura;
					}
				  }
	              
          	  }
        }
   }

    void displayList(){
      cout << "Figuras:";
      Figura* atual = inicio;
      while(atual != NULL){
         atual->toString();
         atual = atual->getProx();
         cout << ", ";
      }
   }

   int getTam(){
      int cont = 0;
      Figura* atual = inicio;
      while(atual != NULL){
         cont++;
         atual = atual->getProx();
      }
      return cont;
   }
};

/** SESSÃO Membro **/

class Membro{
    protected:
       Membro* ant;
       string nome;
       string telefone;
       ListaFigura* Figuras;
       Membro* prox;
    
    public:
           
    Membro(){
       ant = NULL;
       prox = NULL;      
       Figuras = new ListaFigura();
    }
    
    void toString(){
         cout << "\nNome:" << nome;
         cout << "\nTelefone:" << telefone;
         cout << "\n";
         Figuras -> displayList();
    }
    
    void setAnt(Membro* ant){
       this -> ant = ant;  
    }
    
    void setNome(string nome){
       this -> nome = nome;  
    }
    
    void setTelefone(string telefone){
       this -> telefone = telefone;
    }
    
    void setProx(Membro* prox){
       this -> prox = prox;  
    }
    
    Membro* getAnt(){
       return ant;
    }
    
    string getNome(){
       return nome;
    }

    string getTelefone(){
       return telefone;
    }
    
    Membro* getProx(){
       return prox;
    }
        
    void addFigura(int pFigura){
        Figura* lFigura = new Figura(pFigura);
        Figuras -> insere(lFigura);
    }
    
    Figura* getFigura(){
        return Figuras -> getInicio();
    } 
    
    bool possuo(int numero){
    	Figura* atual = Figuras -> getInicio();
    	while(atual != NULL){
    	   if(atual -> getNumero() == numero){
    		   return true;
		   }
		   atual = atual -> getProx();
    	}
    	return false;
	}
    
    void trocar(Membro* daVez){
    	Figura* atual = daVez -> getFigura();
    	while(atual != NULL){
    		bool troca = false;
    		if(atual -> getQtd() > 1){
    			if(!possuo(atual -> getNumero())){
    				Figura* atualMinha = getFigura();
    				while(atualMinha != NULL && !troca){
    					if(atualMinha -> getQtd() > 1){
    						if(!daVez -> possuo( atualMinha -> getNumero() ) ){
    							atual-> setQtd( atual -> getQtd() - 1);
    							addFigura(atual -> getNumero());
    							
    							atualMinha-> setQtd( atualMinha -> getQtd() - 1);
    							daVez -> addFigura(atualMinha -> getNumero());
    							
    							troca = true;
    							
    							cout << daVez -> getNome() << "trocou figurinha " << atual -> getNumero() << " com a figurinha " << atualMinha -> getNumero() << " de " << getNome() << "\n";  
							}
    					}
    					
    					atualMinha = atualMinha -> getProx();
    				}
				}
			}
    		atual = atual -> getProx();
		}
	}
};

class ListaMembro{
   private:
      Membro* inicio;
      Membro* fim;
   public:
//-------------------------------------------------------------
   ListaMembro() : inicio(NULL), fim(NULL)
      {  }
//-------------------------------------------------------------
   ~ListaMembro(){
      Membro* atual = inicio;
      while(atual != NULL){
         Membro* aux = atual;
         atual = atual -> getProx();
         delete aux;
      }
   }
//-------------------------------------------------------------
   Membro* getInicio(){
        return inicio;
   }

   bool isEmpty(){
       return (inicio==NULL);
   }

   void insere(Membro* pMembro){ 
      if(isEmpty()){
			inicio = pMembro;
			fim = pMembro;
      }
      else{
      		fim -> setProx(pMembro);
      		pMembro -> setAnt(fim);
      		fim = pMembro;
      }
   }
   
   Membro* get(int indice){
	  if(indice == 0){
	  	return inicio;
	  }
	  else{
	  	Membro* atual = inicio;
	  	int cont = 0;
	  	while(cont < indice){
	  		cont++;
	  	    atual = atual -> getProx();
		}
		return atual;
	  }
   }
   
   Membro* getByName(string pNome){
      Membro* atual = inicio;
      
      std::string strNomeBusca = pNome;
      const char* cNome = strNomeBusca.c_str();
      
      if(atual != NULL){
          while(atual != NULL){
               std::string strAtualNome = atual -> getNome();
               const char* cAtual = strAtualNome.c_str();

               if(strcmp(cAtual, cNome) == 0){
                   return atual;
               }
               atual = atual->getProx();
          }
      }
      return NULL;
   }

    void displayList(){
      if(isEmpty()){
          cout << "Nenhum Membro cadastrado";
      }else{
          cout << "Membros: \n\n";
          Membro* atual = inicio;
          while(atual != NULL){
             atual->toString();
             atual = atual->getProx();
             cout << "\n\n";
          }
          cout << endl;
      }
   }

   int getTam(){
      int cont = 0;
      Membro* atual = inicio;
      while(atual != NULL){
         cont++;
         atual = atual->getProx();
      }
      return cont;
   }
};

/** Fim das classes **/

void menu(){
    cout << "\t\tMENU\n";
    cout << "1 - Inserir Membro\n";
    cout << "2 - Inserir Figura para Membro\n";
    cout << "3 - Trocar\n";
    cout << "4 - Listar\n";
    cout << "0 - Sair\n\n";
}

//Converte teclas para evitar bug no menu
int converteTecla(int option){
    switch(option){
        case 48:
             return 0;
        case 49:
             return 1;
        case 50:
             return 2;
        case 51:
             return 3;
        case 52:
             return 4;
        case 53:
             return 5;
        default:
             return 9;
    }
}

Membro* leMembro(){
    string nome, telefone;
    
    system("cls");
    cout << "Inserindo novo Membro:\n\nNome:";
    cin >> nome;
    
    fflush(stdin);
    
    cout << "\nTelefone:";
    cin >> telefone;
    
    fflush(stdin);
    
    Membro* lMembro = new Membro();
    lMembro -> setNome(nome);
    lMembro -> setTelefone(telefone);
            
    return lMembro;
}

ListaMembro* gListaMembro = new ListaMembro();

int main(){
    int option = -1, lNumero;
    string message, lNome;
    Membro* lMembro = new Membro();
    
    
    //Lê o arquivo da mesma pasta onde esta o EXE
	std::ifstream input( "db.txt" );
	int cont = 0;
	
	//Passa linha por linha e monta os membros e suas respectivas figurinhas
	for( std::string linha; getline( input, linha ); )
	{
		std::size_t found = linha.find("Membro_");
	
		if (found != std::string::npos) {
			cout << found << " - " <<  linha << "\n";
            cont = 1;
            
            lMembro = new Membro();
            gListaMembro -> insere(lMembro);
        }
		else{
            if (cont == 1) {
                lMembro -> setNome(linha);
                cont++;
            }else if(cont == 2){
                lMembro -> setTelefone(linha);
                cont++;
            }else if(cont == 3){
                cont++;
            }else if(cont > 3){
            	lMembro -> addFigura(atoi( linha.c_str() ));
            }
        }
	}
    //system("pause");
    
    while(option != 0){
        system("cls");
        menu();

        if(message != ""){
            cout << "\n\n" << message << "\n";
            message = "";
        }
        
        option = getch();
        fflush(stdin);

        option = converteTecla(option);

        switch(option){
            case 1:
                 lMembro = leMembro();
                 gListaMembro -> insere(lMembro);
                 break;
            case 2:
                 system("cls");
                 cout << "Informe o nome do Membro:";
                 cin >> lNome;
                 
                 lMembro = gListaMembro -> getByName(lNome);
                 
                 if(lMembro == NULL){
                    cout << "Membro não encontrado"; 
                 }else{
                    cout << "Informe o numero da Figura:";
                    cin >> lNumero;
                    
                    lMembro -> addFigura(lNumero); 
                    
                    cout << lNumero << " inserida com sucesso para " << lMembro -> getNome();
                 } 
                 getch();
                 break;
            case 3:
                 system("cls");
                 
                 for(int i =0; i < gListaMembro -> getTam(); i++){
                 	Membro* trocador = gListaMembro -> get(i);
                 	//cout <<  trocador -> getNome() << " ira realizar trocas com: \n";
                 	
                 	for(int j = i + 1;j < gListaMembro -> getTam(); j++){
                 		Membro* daVez = gListaMembro -> get(j);
                 		
                 		//cout <<  daVez -> getNome() << "\n";
                 		
                 		trocador -> trocar(daVez);
					}
				 }
                 
                 getch();
                 break;
            case 4:
                 system("cls");
                 gListaMembro -> displayList();
                 
                 getch();
                 break;
            case 0:
                break;
            default:
                message = "Opcao invalida! Por favor digite uma nova opcao!";
                break;
        }
    }

    return 0;
}

