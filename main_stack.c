/*
@date Octubre 2016
@author Carlos Almeraz, Edgar Ortiz

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern int push(int *stack, int pos, float Val);
extern int pop(int *stack, int pos);

int main(void){
  int stack[10], pos = -1, opt = -1, val = 0, in = 0, asc = 0, j = 0, k = 0, l = 0, m = 0;
  char n[4];
  float Val = 0, V1 = 0, V2 = 0, s = 0, v = 0;
  
  printf("***BIENVENIDO AL STACK***\n");
  printf("Este programa es una calculadora que Suma, Resta, Multiplica, Divide y\nobtiene el Módulo de una División. Para que funcione, por favor ingresa\nmínimo dos números y después de esto pon el símbolo de la opeación\nque deseas realizar.\n\n");

  //Este cíclo sirve para que se mantenga el programa en funcionamiento hasta que se ingrese un valor distinto
  //a los permitidos.
  while (in == 0){
    printf(">> ");
    scanf("%s", n);
    Val = atof(n);
    j = n[0];
    
    //Este cíclo sirve para que se acepten los valores en codigo ASCII del 0 al 9
    if((j>=48) && (j<=57)){
      pos++;
      push(stack, pos, Val);
      printf("Se ingreso el valor -> %.2f\n", Val);
    }//if
    
    //Si no se ingresa un valor de los permitidos, quiere decir que es un símbolo de alguna
    //operación.
    else {
      if (pos > 0){
	V1=pop(stack, pos);
        pos--;
	
	V2=pop(stack, pos);
        pos--;
        
	printf("\nSe saco el valor-> %.2f\n", V1);
	printf("\nSe saco el valor-> %.2f\n", V2);

	//Menú para saber que operación esta requiriendo el usuario
	switch(j){

	case 43:
	  s = V2 + V1;
	  printf("Resultado: %.2f\n", s);
	  pos ++;
	  v = push(stack, pos, s);
	  printf("\nSe ingreso el valor -> %.2f\n", v);
	  break;

	case 45:
          s = V2 - V1;
          printf("Resultado: %.2f\n", s);
	  pos ++;
	  v = push(stack, pos, s);
          printf("\nSe ingreso el valor -> %.2f\n", v);
          break;

	case 47:
          s = V2 / V1;
          printf("Resultado: %.2f\n", s);
          pos ++;
	  v = push(stack, pos, s);
          printf("\nSe ingreso el valor -> %.2f\n", v);
          break;

	case 120:
          s = V2 * V1;
          printf("Resultado: %.2f\n", s);
          pos ++;
	  v = push(stack, pos, s);
          printf("\nSe ingreso el valor -> %.2f\n", v);
          break;

	case 37:
	  k = V2;
	  l = V1;
          m = k % l;
          printf("Resultado: %i\n", m);
          pos ++;
	  v = push(stack, pos, m);
          printf("\nSe ingreso el valor -> %.2f\n", v);
          break;

	  //Si el valor es distinto a todos los permitidos, el programa se cierra y se manda
	  //un mensaje de error.
	default:
	  printf("\nERROR... opcion invalida, vuelva a intentar...\n");
	  in = 1;
	  break;


	}//Switch

      }//if
    }//else
      
  }//while
        return 0;
}//main
