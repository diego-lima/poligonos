#include <iostream>
#include <math.h>
#include "headers/ponto.h"

using namespace std;

float grau(float radianos){
    // Converte de radianos pra graus
    return radianos * M_PI / 180;
}

float trunc(float a, int places=1000){
    //Trunca alguns dígitos de a, de acordo com places
    return (float)((int)a*places)/places;
}

Ponto::Ponto(float a, float b){
    _x = a;
    _y = b;
}

float Ponto::x(){
    return _x;
}

void Ponto::x(float a){
    _x = a;
}

float Ponto::y(){
    return _y;
}

void Ponto::y(float a){
    _y = a;
}

void Ponto::xy(float a, float b){
    _x = a;
    _y = b;
}

Ponto Ponto::add(Ponto p){
    Ponto ret(_x, _y);
    ret.transladar(p.x(), p.y());
    return ret;
}

Ponto Ponto::operator + (Ponto v){
  Ponto ret(_x, _y);
  ret = ret.add(v);
  return(ret);
}

Ponto Ponto::sub(Ponto p){
    Ponto p_aux(_x, _y);
    p_aux.transladar(-1 * p.x(), -1 * p.y());
    return p_aux;
}

Ponto Ponto::operator - (Ponto v){
  Ponto ret(_x, _y);
  ret = ret.sub(v);
  return(ret);
}

Ponto Ponto::operator - (){
  Ponto ret(-1*_x,-1* _y);
  return(ret);
}

float Ponto::norma(void){
    return sqrt(pow(_x,2) + pow(_y,2));
}

void Ponto::transladar(float a, float b){
    _x = _x + a;
    _y = _y + b;
}

void Ponto::rotacionar(float teta){
    float novo_x, novo_y;
    novo_x = cos(grau(teta)) * _x - sin(grau(teta)) * _y;
    novo_y = sin(grau(teta)) * _x + cos(grau(teta)) * _y;
    xy(novo_x, novo_y);

}

void Ponto::print(void){
    printf("(%.1f,%.1f)", _x, _y);
}

bool Ponto::igual(Ponto p){
    //O que acontece abaixo é que estamos comparando X e Y dos pontos.
    //A função trunc(truncar) é porque queremos considerar que pontos são iguais, mesmo
    //se houver diferença depois da quarta casa decimal.
    // int pl é de (decimal) places.
    int pl=10000;
    if (trunc(_x, pl) == trunc(p.x(), pl) && trunc(_y, pl) == trunc(p.y(), pl))
        return true;
    return false;
}
