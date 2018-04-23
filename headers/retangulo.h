#ifndef RETANGULO_H
#define RETANGULO_H

#include "headers/poligono.h"

/**
 * @brief A classe Retangulo (herda Poligono)
 * @details Implementa o objeto Retangulo que é mais facil de ser criado
 * que um poligono
 */

class Retangulo : public Poligono{

    public:
    /**
         * @brief Construtor da classe
         * @details O padrão de todos argumentos é 1
         * @param x coordenada X do canto superior esquerdo
         * @param y coordenada Y do canto superior esquerdo
         * @param largura
         * @param altura
         */
        Retangulo(float x=1, float y=1, float largura=1, float altura=1);
};

#endif // RETANGULO_H
