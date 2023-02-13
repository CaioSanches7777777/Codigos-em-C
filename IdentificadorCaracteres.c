#include <stdio.h>
#define SIZE 100



//prototipo
void classificar(char imp, int *classe);


int main(void) {
  char imp; //imput
  int opcao = 1;
  int VZS = 1;
  int classe;
  
  do{
    printf("\nDigite um caractere: ");
    scanf("\n%c", &imp);
    
    classificar(imp, &classe);
    
    if(classe == 1){
      printf("\nEsse caractere é uma vogal minúscula");
    }else if(classe == 2){
      printf("\nEsse caractere é uma vogal maiúscula");
    }else if(classe == 3){
      printf("\nEsse caractere é uma consoante minúscula");
    }else if(classe == 4){
      printf("\nEsse caractere é uma consoante maiúscula");
    }else if(classe == 5){
      printf("\nEsse caractere é um símbolo especial"); // tipo ("%&$&<>") ou ("123!?.,") ? 
    }
    
    VZS++;
    
    if(VZS >= SIZE){//TRATAMENTO DE ERRO (Nº de vezes que pode repetir)
      printf("\n\nFim do programa.\n");
      opcao = 0;
    }else{  //MODELO MENU
      printf("\n\n\nMENU\n [1]: Para digitar o próximo caractere\n [ ]: Qualquer numero para sair\n");
    
      printf("Sua opção: ");
      scanf("%i", &opcao);
      }
    
    if(opcao != 1){//TRATAMENTO DE ERRO
      printf("Fim do programa.\n");
      opcao = 0;
    }
    
  }while(opcao == 1 && VZS <= SIZE);
  
  return 0;
}


//abcdefghijklmnopqrstuvwxyz = 26
//ABCDEFGHIJKLMNOPQRSTUVWXYZ = 26

//função
void classificar(char imp, int * classe){
  char alfab[] = "aeioubcdfghjklmnpqrstvwxyz";
  char Alfab[] = "AEIOUBCDFGHJKLMNPQRSTVWXYZ";
  int index = 0;
  int Q = 0; //contador para ver se imp for igual a algum em alfab ou Alfab

  for (index = 0 ; index <= 5-1; index++){
    if(imp == alfab[index] || imp == Alfab[index]){
      Q++;
    }
    if (Q == 0) {
      *classe = 5;
    }
  }
  for (index = 0 ; index <= 5-1; index++){
    if(imp == alfab[index]){
      *classe = 1;
    }
    if(imp == Alfab[index]){
      *classe = 2;
    }
  }
  for (index = 5 ; index <= 26-1; index++){
    if(imp == alfab[index]){
      *classe = 3;
    }
    if(imp == Alfab[index]){
      *classe = 4;
    }
  }
  //terminar de fazer a classe 5
  
  
}
