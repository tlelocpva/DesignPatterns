/* PizzaHut */

#include <iostream>
#include <string.h>

/* partes de um pedido */
class Massa{
	public:
		std::string TipoMassa;
};

class Borda{
	public:
		std::string recheada;
};

class Sabor{
	public:
		std::string sabor;
};

class Bebida{
	public:
		std::string nomeBebida;
};

/* produto final: pedido */
class Pedido{
	public:
		Massa* massa = NULL;
		Borda* borda = NULL;
		Sabor* sabor;
		Bebida* bebida = NULL;

	void imprimePedido( void ){
		std::cout << "Pizza: " << sabor->sabor << " com massa ";
		massa != NULL ? std::cout  << massa->TipoMassa : std::cout << " padrao" <<std::endl;

		borda != NULL ? std::cout << "\nborda recheada de " << borda->recheada << std::endl : \
		 std::cout << std::endl;

		bebida != NULL ? std::cout << "Refrigerante: " << bebida->nomeBebida << std::endl : \
		 std::cout << "Sem refrigerante" << std::endl;
	}
};

/* Construi as partes */
class Builder{
	public:
		virtual Pedido* buildPedido() {return NULL;};
	private:
		virtual void setMassa() {};
		virtual void setBorda() {};
		virtual void setSabor() = 0;
		virtual void setBebida() {};
};

/* Resposável por chamar o builder */
class Director{
	Builder* builder = NULL;

	public:
		void setBuilder( Builder* newBuilder ){
			builder = newBuilder;
		}

		Pedido* getPedido(){
			return builder == NULL ? NULL : builder->buildPedido();
		}
};

/* Concrete Builder Pizza Padrao */
class PizzaBuilder_Padrao : public Builder{
	private:
		Pedido m_pedido;

		void setSabor(){
			Sabor *sabor = new Sabor();
			sabor->sabor = "Calabresa";
			m_pedido.sabor = sabor;
		}	
	public:
		Pedido* buildPedido(){
			setSabor();
			return &m_pedido;
		}
};

/* Concrete Builder Pedido1 */
class PromocaoBuilder_Refri : public Builder{
	private:
		Pedido m_pedido;

		void setMassa(){
			Massa *massa = new Massa();
			massa->TipoMassa = "PAN";
			m_pedido.massa = massa;
		}
		void setSabor(){
			Sabor *sabor = new Sabor();
			sabor->sabor = "4 Queijos";
			m_pedido.sabor = sabor;
		}
		void setBebida(){
			Bebida *bebida = new Bebida();
			bebida->nomeBebida = "Coca-Cola";
			m_pedido.bebida = bebida;
		}
	
	public:
		Pedido* buildPedido(){
			setMassa();
			setSabor();
			setBebida();
			return &m_pedido;
		}
};

/* Concrete Builder Pedido2 */
class PromocaoBuilder_Borda : public Builder{
	private:
		Pedido m_pedido;

		void setMassa(){
			Massa *massa = new Massa();
			massa->TipoMassa = "Super Fina";
			m_pedido.massa = massa;
		}
		void setBorda(){
			Borda *borda = new Borda();
			borda->recheada = "Catupiry";
			m_pedido.borda = borda;
		}
		void setSabor(){
			Sabor *sabor = new Sabor();
			sabor->sabor = "Portuguesa";
			m_pedido.sabor = sabor;
		}	
	public:
		Pedido* buildPedido(){
			setMassa();
			setBorda();
			setSabor();
			return &m_pedido;
		}
};

#define N_PROMOCOES 3

int main(void){
	int opt;
	Pedido* pedido;
	Director diretor;

	PizzaBuilder_Padrao padraoBuilder;
	PromocaoBuilder_Borda bordaBuilder;
	PromocaoBuilder_Refri refriBuilder;

	while( 1 ){

		std::cout << "Insere o numero do Pedido:\t";
		std::cin >> opt;
		std::cout << std::endl;

		if(opt > N_PROMOCOES || opt <= 0)
			break;

		switch (opt){
			case 1: 
				diretor.setBuilder(&padraoBuilder);
				break;
			case 2:
				diretor.setBuilder(&bordaBuilder);
				break;
			case 3:
				diretor.setBuilder(&refriBuilder);
				break;
			default:
				break;
		}

		//opt == 1 ? diretor.setBuilder(&bordaBuilder) : diretor.setBuilder(&refriBuilder);
		pedido = diretor.getPedido();
		pedido->imprimePedido();
		std::cout << std::endl;
	}

	return 0;
}