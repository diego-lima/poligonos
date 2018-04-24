#include <iostream>
#include <math.h>

#include "headers/ponto.h"
#include "headers/linha.h"
#include "headers/poligono.h"
#include "headers/retangulo.h"
#include "headers/mostrador.h"

#define NENHUMA -1

int main(int argc, char *argv[]){
    //Crie um pequeno exemplo para testar sua implementação da classe Retangulo
    //No exemplo, defina um novo retângulo na posição (x,y)=(0,0)(x,y)=(0,0)
    //com altura e largura iguais a 3 e 4, respectivamente.
    Retangulo retan(0,0,4,3);

    //Imprima a estrutura poligonal gerada para o retângulo.
    retan.print();

    //Calcule a sua área usando a função já implementada na classe Poligono
    printf("Area do retangulo: %.1f\n", retan.area());

    //Mude a posição do retângulo usando a função translada(float,float)
    // para (x,y)=(−3,4) e recalcule a área do retângulo.
    // Compare-a com a área calculada antes da transformação geométrica.
    retan.transladar(-3,4);
    retan.print();
    printf("Area do retangulo depois do translado: %.1f--->SÃO IGUAIS!\n", retan.area());

    //Rotacione o Retângulo de +30o em relação ao seu centro de massa
    //e recalcule a sua área. Compare-a com a área calculada antes da
    //transformação geométrica.
    retan.rotacionar(30, Ponto(2,-1.5) );
    retan.print();
    printf("Area do retangulo depois da rotação: %.1f--->SÃO IGUAIS!\n", retan.area());

    printf("\n\n\n");
    return 0;
}
