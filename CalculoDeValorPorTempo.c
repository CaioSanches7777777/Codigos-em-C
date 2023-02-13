#include <stdio.h>
#include <time.h>
#define preco 3.55
#define SIZE 10
//total de vagas no estacionamento



//prototipo
void calcular(int horEN, int minEN, int horSA, int minSA, int * horTO, int * minTO, float *val);


int main(void) {
  time_t timer;
  struct tm y2k = {0};
  time(&timer);
  float val = 0;
  int horEN = 0, minEN = 0;
  int horSA, minSA;
  int horTO = 0, minTO = 0;
  int VLR = 1;
  int opcao = 0;
  
  while(timer - 3600 >= 0){
    
    horSA = horSA + 1;
    timer = timer - 3600;
  }  
  while(timer - 60 >= 0){
    
    minSA = minSA + 1; 
    timer = timer - 60;
  }
  

  do{
    printf("\n\nDigite as horas (HH:MM) de quando entrou no estacionamento: "); // Imput dos numeros "horEN" e "minEN" ("horEN":"minEN")
    scanf("%i:%i", &horEN, &minEN);
    
    
    VLR++;
    
    if(VLR > SIZE + 1){//TRATAMENTO DE ERRO (Nº de vezes que pode repetir / total de vagas)
      printf("\n\nFim do programa.\n");
      opcao = 1;
    }else{  //MODELO MENU
      printf("\n\nMENU\n [1]: Exibir tempo gasto e total a pagar\n [ ]: qualquer tecla para tentar novamente\n");
    
      printf("Sua opção: ");
      scanf("%i", &opcao);      
      if(opcao != 1){//tentar novamente (não pode sair sem pagar)
        VLR--;
        opcao = 0;
        
      }if(opcao == 1){//visualizar o tempo e o preço
        
        calcular(horEN, minEN, horSA, minSA, &horTO, &minTO, &val);
        
        printf("\n\nO tempo total gasto no estacionamento foi(%.2i:%.2i).\nO total a pagar é $%.2f",horTO, minTO, val);
        printf("\n\nVolte Sempre!\n");

        opcao = 0;
      }
    }
    
  }while(opcao == 0 && VLR <= SIZE);
  
  return 0;
}



//função
void calcular(int horEN, int minEN, int horSA, int minSA, int * horTO, int * minTO, float *val){
  
  while(minEN - 60 >= 0){//acerta o tempo de entrada
    
    horEN = horEN + 1; 
    minEN = minEN - 60;
  }while(minSA - 60 >= 0){//acerta o tempo de saida
    
    horSA = horSA + 1; 
    minSA = minSA - 60;
    }
  
  
  *horTO = horSA - horEN; //calcula as horas totais
  *minTO = minSA - minEN; //calcula os minutos totais
  
  if(*minTO < 0){         //CORREÇÃO DE ERRO (evita/corrige minutos negativos)
    *horTO = *horTO - 1;
    *minTO = *minTO + 60;
  }
  while(*minTO - 60 >= 0){
    
    *horTO = *horTO + 1; 
    *minTO = *minTO - 60;
    
  }
  if(*horTO < 0){//SUGESTÃO DE CORREÇÃO DE ERRO (evita/corrige horas negativas)
    *horTO = *horTO + 24;
    
  }
  
  *val = *horTO * preco;
}
