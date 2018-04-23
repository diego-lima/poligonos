#ifndef MOSTRADOR_H
#define MOSTRADOR_H

#include "headers/poligono.h"

/**
 * @brief A classe Mostrador
 * @details Serve para exibição de um gráfico de área na tela que mostra o contorno
 * do polígono.
 */

class Mostrador{
    public:
        Mostrador();

        /**
         * @brief Recebe o poligono a ser mostrado através de um Area Chart do QT.
         * @details os parâmetros argc e argv devem ser os mesmos passados na função main.
         * "int main(int argc, char *argv[])".
         *
         * A exibição é feita com o area chart do QT. Como o area chart não é o mais adequado
         * para exibição de polígonos quaisquer, essa exibição é defeituosa.
         * @param argc da main
         * @param argv da main
         * @param poligono o poligono a ser mostrado
         * @param enquadrar se deseja arrastar o polígono para a origem
         */
        Mostrador(int argc, char *argv[], Poligono poligono, bool enquadrar=false);

        /**
         * @brief Enquadra o poligono perto da origem e ajusta o alcance do gráfico
         * para o desenho do polígono ficar grande
         * @param poligono sendo exibido
         * @param a alcance da horizontal do gráfico
         * @param b alcance da vertical do gráfico
         * @param enquadrar se a função deve puxar o polígono para perto da origem ou não
         */
        void setar_limites (Poligono* poligono, float * a, float* b, bool enquadrar);
};

#endif // MOSTRADOR_H
