#ifndef LINHA_H
#define LINHA_H

#include "headers/ponto.h"

/**
 * @brief A classe Linha
 * @details Utilizada para detecção de interseção nos polígonos
 */

class Linha{
    private:
        Ponto pontos[2];

    public:
        Linha();

        /**
         * @brief Construtor da classe
         * @param p1 ponto inicial da linha
         * @param p2 ponto final da linha
         */
        Linha(Ponto p1, Ponto p2);

        /**
         * @brief Determina se a linha é limitada pelo ponto
         * @param p ponto a ser constatado
         * @return verdadeiro ou falso
         */
        bool limitada_por(Ponto p);

        /**
         * @brief Printa as coordenadas da linha
         */
        void print(void);

        /**
         * @brief Determina o ponto de interseção entre duas linhas (segmentos de reta).
         * @param l1 linha 1
         * @param l2 linha 2
         * @param ponto serve apenas para poder retornar o ponto de interseção entre as linhas, se houver
         * @return verdadeiro caso haja interseção entre as linhas
         */
        friend bool intersecao(Linha l1, Linha l2, Ponto *ponto);
};

bool intersecao(Linha l1, Linha l2, Ponto *ponto);

#endif // LINHA_H
