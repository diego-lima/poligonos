#include "headers/retangulo.h"

Retangulo::Retangulo(float x, float y, float largura, float altura){
    // Sentido anti-horario, comecando do ponto inferior esquerdo
    // Considera-se a posicao (x,y) o canto superior esquerdo
    *this << Ponto(x, y-altura) << Ponto(x+largura, y-altura) << Ponto(x+largura, y) << Ponto(x,y);
}
