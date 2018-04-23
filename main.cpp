#include <iostream>
#include <math.h>

#include "headers/ponto.h"
#include "headers/linha.h"
#include "headers/poligono.h"
#include "headers/retangulo.h"
#include "headers/mostrador.h"

#define NENHUMA -1

int main(int argc, char *argv[]){
    Poligono poli;
    poli << Ponto(0,0) << Ponto(1,0) << Ponto(0.5,1);
    poli.print();


    return 0;
}
