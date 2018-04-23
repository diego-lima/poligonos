#ifndef POLIGONO_H
#define POLIGONO_H

#include "headers/ponto.h"
#include "headers/linha.h"

#ifndef QTD_PADRAO_PONTOS_100
#define QTD_PADRAO_PONTOS_100 100
#endif

/**
 * @brief A classe Polígono
 * @details Implementa o objeto Poligono, que pode ter inúmeros pontos
 */

class Poligono{
    private:
        int qtd_pontos; // Indica ate onde percorrer array de pontos (similar ao '\0' da string)
        int qtd_pontos_maxima; // Indica limite superior a partir do qual rejeita-se pontos
        Ponto *pontos; // Array de pontos

    public:

        /**
         * @brief Construtor da classe
         * @param n quantidade de pontos para serem alocados
         */
        Poligono(int n = QTD_PADRAO_PONTOS_100);

        /**
         * @brief destrutor da classe, que desaloca os pontos
         */
        ~Poligono();

        /**
         * @brief resgata a quantidade de pontos já fornecidos
         * @return numero inteiro
         */
        int quantidade_pontos(void);

        /**
         * @brief Recebe um ponto para ser adicionado à lista de pontos.
         * @param p ponto a ser adicionado
         * @return true em caso de sucesso
         */
        bool adicionar_ponto(Ponto p);

        /**
         * @brief printa a sequência de pontos
         */
        void print(void);

        /**
         * @brief Translada todos os pontos do polígono
         * @param a o movimento na coordenada X
         * @param b o movimento na coordenada Y
         */
        void transladar(float a, float b);

        /**
         * @brief Rotaciona todos os pontos do polígono.
         * @details  em relação ao ponto fornecido (por padrão é a origem, sentido anti-horário)
         * @param teta ângulo em graus a se rotacionar no sentido anti-horário
         * @param p ponto de referência para a rotação
         */
        void rotacionar(float teta, Ponto p = Ponto(0,0));

        /**
         * @brief Calcula a área do polígono usando Shoelace.
         * @details Funciona para polígonos côncavos, convexos e até mesmo polígonos
         * que se interceptam em si mesmos. No caso desses últimos, a função recursivamente
         * subdivide o polígono em polígonos menores, que não se interceptam em si mesmos
         * (denominados polígonos simples), e aí retorna a soma das áreas desses subpolígonos.
         * @return a área total do polígono
         */
        float area(void);

        /**
         * @brief Determina se um ponto fornecido está na lista de pontos do poligono
         * @param p o Ponto a ser constatado
         * @return verdadeiro ou falso
         */
        bool contem_ponto(Ponto p);

        /**
         * @brief determina se o poligono se intercepta consigo mesmo
         * @param p um Ponto que servirá apenas para retornar o primeiro ponto
         * de auto-interseção do polígono
         * @return o índice da primeira linha do polígono a se interceptar com outra.
         * Retorna -1 caso não exista interseção (polígono não se intercepta).
         */
        int self_intersect(Ponto *p);

        /**
         * @brief Viabiliza a adição de pontos com o operador <<
         * @details Torna válida a sintaxe "poligono << Ponto(x1,y1) << Ponto(x2,y2);"
         * @param poligono
         * @param ponto
         * @return o polígono com os pontos já adicionados, acumulados.
         */
        friend Poligono& operator<<(Poligono& poligono, Ponto p);

        /**
         * @brief Extra: liberar acesso para classe que mostra polígono na tela
         */
        friend class Mostrador;
};

Poligono& operator<<(Poligono& poligono, Ponto p);

#endif // POLIGONO_H
