#include <stdio.h>
#include <stdlib.h>

float metragem_limpeza();
float metragem_limpeza_b();
float tipo_limpeza();
float adicional_limpeza();

//Programa principal
int main() {
  
  printf("Bem-vindo ao programa de Serviços de Limpeza CleanUp.\n**************************************************************************\n----------------------Menu 1 de 3 - Metragem Limpeza----------------------\n");
  float metragem = metragem_limpeza();
  if (metragem ==0) {
    return 0;
  }
  printf("O valor retornado foi de %g\n", metragem); //Verificar se o valor calculado está correto.

  printf("**************************************************************************\n------------------------Menu 2 de 3 - Tipo Limpeza------------------------\n");
  float tipo = tipo_limpeza();
  printf("O valor retornado foi de %g\n", tipo); //Verificar se o valor calculado está correto.

  printf("**************************************************************************\n-------------------Menu 3 de 3 - Adicional de Limpeza---------------------\n");
  float adicional = adicional_limpeza();
  printf("O valor retornado foi de %g\n", adicional); //Verificar se o valor calculado está correto.

  float resultado=metragem*tipo+adicional;
  printf("O valor final foi de R$%g\n", resultado);

  return 0;

}

//Função que retorna o valor calculado da limpeza pela metragem. Não aceita valores menor do que 30 ou maior do que 700.
float metragem_limpeza() {
  float met;
  
  while(1) {
    printf("Entre com a metragem da casa: \n");
    float ret_scanf = scanf("%f", &met);
    if (ret_scanf != 1) { //Verifica se o valor de scanf deu certo.
      printf("Só são aceitos valores numéricos. Tente novamente.\n");
      while (getchar() != '\n'); //Limpa o buffer do teclado.
      continue;
    }
    
    if (met<30 || met>700) {
      printf("Não aceitamos casas com menos de 30m² ou mais de 700m². Sentimos muito.\n");
      return 0;
    }

    if (met<=300) {
      return 60+0.3*met;
      
    } return 120+0.5*met;

    
  }
    
} 

//Função que retorna o valor do tipo de limpeza. Irá multiplicar o resultado final por 1.0 ou 1.3.
float tipo_limpeza() {
  char tip;
  printf("Entre com o tipo de limpeza:\nBásica (B): Aplicada para sujeira semanais ou quinzenais.\nCompleta (C): (+30 p/ cento): Indicada para sujeiras antigas ou não rotineiras.\n");
  while (1) {
  printf("Entre com o tipo de limpeza:\n");  
  char ret_scanf = scanf(" %c", &tip);
   if (ret_scanf != 1) { //Verifica se o valor de scanf deu certo.
     printf("Entrada de dados inválida. Tente novamente\n");
     while (getchar() != '\n'); //Limpa o buffer do teclado.
     continue;
  }
  if (tip=='B') {
    return 1.0;
  }
  else if (tip=='C') {
    return 1.3;
  }
  else {
    printf("Só são aceitos B ou C. Tente novamente.\n");
    continue; 
  }
  }
}

//Função que retorna o valor dos adicionais da limpeza. Irá somar com o resultado final.
float adicional_limpeza() {
  float adi, add;
  adi=0;
  printf("Deseja mais algum adicional?\n0 - Não desejo mais nada. Encerrar.\n1 - Passar 10 peças de roupas. R$10,00\n2 - Limpeza de 1 Forno/Microondas. R$12,00\n3 - Limpeza de 1 Geladeira/Freezer. R$20,00\n");
  while(1) {
  printf("Digite o valor: \n");
  float ret_scanf = scanf("%f", &add);
    if (ret_scanf != 1) { //Verifica se o valor de scanf deu certo.
      printf("Valor inválido. Tente novamente.");
      while (getchar() != '\n'); //Limpa o buffer do teclado.
      continue;
    }
  if (add==0) {
    adi = adi+0;
    break;
  }
  else if (add==1) {
    adi = adi+10;
    continue;
  }
  else if (add==2) {
    adi = adi+12;
    continue;
  }
  else if (add==3) {
    adi = adi+20;
    continue;
  }
  else {
    printf("Só são aceitos 0, 1, 2 e 3. Tente novamente.\n");
    continue;
  }
    
  }

  return adi;
  

}

