#include <stdio.h>

#define SIZE 100



//prototipo
void calcular(int segIN, int *hor, int *min, int *seg);


int main(void) {
  int segIN;
  int hor = 0, min = 0, seg = 0 ;
  int VLR = 1;
  int opcao = 1;
  
  do{        
    
    printf("\n\nDigite o total de segundos de realização do teste: "); // Imput do Nº "segIN"
    scanf("%i", &segIN);
    
  calcular(segIN, &hor, &min, &seg);
  
  printf("\nO tempo gasto na realização do teste foi de: (%i:%i:%i) \n%i HORA(S) \n%i MINUTO(S) \n%i SEGUNDO(S)\n", hor, min, seg, hor ,min, seg);
  
    VLR++;
    
    if(VLR >= SIZE + 1){//TRATAMENTO DE ERRO (Nº de vezes que pode repetir)
      printf("Fim do programa.\n");
      opcao = 0;
    }else{  //MODELO MENU
      printf("\n\nMENU\n [1]: Continuar a converter\n [ ]: qualquer tecla para sair\n");
    
      printf("Sua opção: ");
      scanf("%i", &opcao);      
      if(opcao != 1){//TRATAMENTO DE ERRO
        printf("\n\nFim do programa.\n");
        opcao = 0;
      }
    }
    
  }while(opcao == 1 && VLR <= SIZE);
  return 0;
}




//função
void calcular(int segIN, int *hor, int *min, int *seg){
  
  *hor = 0;
  *min = 0;
  *seg = 0;
  
  while(segIN - 3600 >= 0){
    
    *hor = *hor + 1;
    segIN = segIN - 3600;
  }  
  while(segIN - 60 >= 0){
    
    *min = *min + 1; 
    segIN = segIN - 60;
  }
  *seg = segIN;
}
