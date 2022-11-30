#include "../includes/Veiculo.hpp"

// Construtores e Destrutores
Veiculo::Veiculo(
  int capacidade, Turno* turno, std::vector<Funcionario*> funcionarios
) {
  funcionarios.erase(funcionarios.begin());
  this->capacidade = capacidade;
  this->turno = turno;
  this->funcionarios = funcionarios;
  verificaTurno();
  defineRota();
}
Veiculo::Veiculo() { this->capacidade = 0; }
Veiculo::~Veiculo() {}

// Getters

int Veiculo::getCapacidade() { return this->capacidade; }

Turno* Veiculo::getTurno() { return this->turno; }

float Veiculo::getHorarioPartida() { return this->horarioPartida; } 


// Setters

void Veiculo::setCapacidade(int capacidade) { this->capacidade = capacidade; }

void Veiculo::setTurno(Turno* turno) {
  this->turno = turno;
  verificaTurno();
  defineRota();
}

void Veiculo::setHorarioPartida(float horarioPartida){

  this->horarioPartida = horarioPartida;

}

// Métodos

void Veiculo::verificaTurno() {
  std::vector<Funcionario*> aux;
  for (int i = 0; i < this->funcionarios.size(); i++) {
    if (this->funcionarios[i]->getTurno()->getPeriodo() != this->turno->getPeriodo()) {   
        std::string periodoTurno;
  if(getTurno()->getPeriodo() == 0){
      periodoTurno = "Manhã";
  }
  if(getTurno()->getPeriodo() == 1){
      periodoTurno = "Tarde";
  }
  if(getTurno()->getPeriodo() == 2){
      periodoTurno = "Noite";
  }

      std::cout << "--------------------------------------------"<< std::endl << this->funcionarios[i]->getNome() << " não pertence a este turno do Veiculo, turno: " << periodoTurno << std::endl <<
     "--------------------------------------------" << std::endl ;
    } else
      aux.push_back(this->funcionarios[i]);
  }
  this->funcionarios = aux;
}

float Veiculo::calculaDistancia(float x1, float y1, float x2, float y2){

  float distancia = 110.57 * sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2));
  return distancia;
}

void Veiculo::defineRota(){
  
std::ostringstream outHoras;
std::ostringstream outMinutos; 
float distancia = 0;
float auxDistancia = 0;
unsigned int i = 0;
unsigned int j = 0;
std::vector<Funcionario*> auxVector = this->funcionarios;
Funcionario* funcionario;
auto prev = std::prev(this->funcionarios.end(),1);

  
  for(auto it = this->funcionarios.begin(); it != this->funcionarios.end(); it++){    
   
    auxDistancia = calculaDistancia((*it)->getCordenada().first, (*it)->getCordenada().second, -19.870576040926498,-43.96774663137842);

    
    if(auxDistancia > distancia){
    funcionario = (*it);
    distancia = auxDistancia;
    
   
    j = i;
   
    }
  
    if(prev == it){
    funcionario->setDistancia(distancia);
    this->rotasFuncionarios.push_back(funcionario);
    auxVector.erase(auxVector.begin()+j);
   
    }
     i++;
    
    
  }

  

  int auxSize = auxVector.size();
  for(int i = 0; i < auxSize; i++){
   auxDefineRota(&auxVector, this->rotasFuncionarios[i]->getCordenada());
   
  }
 
  float distanciaTotal;
    
  funcionario = this->rotasFuncionarios.back();
  distanciaTotal = calculaDistancia(funcionario->getCordenada().first, funcionario->getCordenada().second, -19.870576040926498,-43.96774663137842);

  
  
  for(auto it = this->rotasFuncionarios.begin(); it != this->rotasFuncionarios.end(); it++){
   
      distanciaTotal += (*it)->getDistancia();
      
    }

  float tempo = distanciaTotal/18;
  tempo += 0.16;
 
  setHorarioPartida(this->turno->getHorarioEntradaCompleto() - tempo);
  
  for(auto it = this->rotasFuncionarios.begin(); it != this->rotasFuncionarios.end(); it++){
    
    this->rotasFuncionarios.begin() == it ? tempo = (*it)->getDistancia()/18 + getHorarioPartida() : tempo += (*it)->getDistancia()/18;
   
    float horas, minutos;
    minutos  = std::modf(tempo, &horas);
    minutos *= 60;
    
    std::stringstream  horarioEmbarque;
    horarioEmbarque << std::fixed << std::setprecision(0) << horas << ":" << minutos;
     
   (*it)->setHorarioEmbarque(horarioEmbarque.str());
    
   

  }


   
}




void Veiculo::auxDefineRota(std::vector<Funcionario*>* auxVector, std::pair<float,float> cordenada){
 
float distancia = 100000.0;
float auxDistancia = 0;
int i = 0;
int j = 0;
bool condicao = false;
Funcionario* funcionario;




    for(auto it = this->funcionarios.begin(); it != this->funcionarios.end(); 
      it++)      {
        condicao = false;
        for(auto itRota = this->rotasFuncionarios.begin(); itRota !=this->rotasFuncionarios.end(); itRota++){ 
         if((*itRota)->getCordenada().first  == (*it)->getCordenada().first){
              condicao = true;
           }
         
        }
      
      if(condicao == false){
   
        
          auxDistancia = calculaDistancia((*it)->getCordenada().first, (*it)->getCordenada().second, cordenada.first, cordenada.second);
          
      
        if(auxDistancia < distancia){
           
          funcionario = (*it);
          distancia = auxDistancia;
          
          j=i;
          
        }
        
         
       
         i++;
         
        }
      }

   
          
          funcionario->setDistancia(distancia);
          this->rotasFuncionarios.push_back(funcionario);
          auxVector->erase(auxVector->begin()+j);
         
          

  
}
  


void Veiculo::exibeRota(){
  
  std::string periodoTurno;
  if(getTurno()->getPeriodo() == 0){
      periodoTurno = "Manhã";
  }
  if(getTurno()->getPeriodo() == 1){
      periodoTurno = "Tarde";
  }
  if(getTurno()->getPeriodo() == 2){
      periodoTurno = "Noite";
  }

  
  for(auto it = this->rotasFuncionarios.begin(); it != this->rotasFuncionarios.end(); it++){
    std::cout << "|" << "Rotas de embarque dos Funcionarios     "  << "        |"<< std::endl;

    std::cout <<"|"<< " Nome do Funcionario:           " << (*it)->getNome() << "\n| " << "Turno:                         " << (*it)->getTurno()->getNomeTurno()  <<  "\n|"
       << " Horario de entrada do turno:   " << (*it)->getTurno()->getHorarioEntrada().first <<":" << (*it)->getTurno()->getHorarioEntrada().second <<  "\n|"<<
                " Periodo do turno:              " << periodoTurno << "\n|"<< " Horario de Embarque:           " << (*it)->getHorarioEmbarque() <<"\n" <<"\n";
              
               
    
  }
}


