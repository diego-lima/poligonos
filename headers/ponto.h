#ifndef PONTO_H
#define PONTO_H


/**
 * @brief A classe Ponto
 * @details Implementa o objeto Ponto para ser usado pelos polígonos
 */

class Ponto{
    private:
        float _x;
        float _y;

    public:
        /**
         * @brief construtor da classe
         * @param a coordenada X do ponto sendo instanciado
         * @param b coordenada Y do ponto sendo instanciado
         */
        Ponto(float a=0, float b=0);

        /**
         * @brief getter da coordenada X
         * @return valor float de X
         */
        float x();

        /**
         * @brief setter da coordenada X
         * @param a o novo valor a ser setado para o X do ponto
         */
        void x(float a);

        /**
         * @brief getter da coordenada Y
         * @return valor float de Y
         */
        float y();

        /**
         * @brief setter da coordenada Y
         * @param a o novo valor a ser setado para o Y do ponto
         */
        void y(float a);

        /**
         * @brief setter das coordenadas X e Y na mesma função
         * @param a o novo valor a ser setado para o X do ponto
         * @param b o novo valor a ser setado para o Y do ponto
         */
        void xy(float a, float b);

        /**
         * @brief realiza soma vetorial dos pontos
         * @details a operação de soma não modifica a instância da classe
         * @param p o ponto a ser somado vetorialmente com a instância da classe
         * @return o ponto (da classe Ponto) resultado da operação
         */
        Ponto add(Ponto p);

        /**
         * @brief realiza a chamada da função add()
         * @param p o ponto a ser somado vetorialmente com a instância da classe
         * @return o ponto (da classe Ponto) resultado da operação
         */
        Ponto operator +(Ponto p);

        /**
         * @brief realiza subtração vetorial dos pontos
         * @details a operação não modifica a instância da classe
         * @param p o ponto a ser subtraído vetorialmente com a instância da classe
         * @return o ponto (da classe Ponto) resultado da operação
         */
        Ponto sub(Ponto p);

        /**
         * @brief realiza a chamada da função sub()
         * @param p o ponto a ser subtraído vetorialmente com a instância da classe
         * @return o ponto (da classe Ponto) resultado da operação
         */
        Ponto operator -(Ponto p);

        /**
         * @brief Inverte o ponto.
         * @details o equivalente a multiplicar as coordenadas do ponto por -1
         * @return um ponto
         */
        Ponto operator-();

        /**
         * @brief calcula a norma ou módulo de um vetor que parte da origem até o ponto
         * @return o valor numérico da norma
         */
        float norma(void);

        /**
         * @brief realiza a movimentação (translado) do ponto
         * @details altera as coordenadas X e Y do ponto somando com os valores passados
         * @param a é o valor para movimentar a coordenada X
         * @param b é o valor para movimentar a coordenada Y
         */
        void transladar(float a, float b);

        /**
         * @brief Rotaciona o vetor equivalente às coordenadas do ponto em relação à origem (sentido anti-horário).
         * @param teta o angulo em graus a ser rotacionado
         */
        void rotacionar(float teta);

        /**
         * @brief Printa as coordenadas do ponto
         */
        void print(void);

        /**
         * @brief Extra: determina se um ponto é igual a outro
         * @param p ponto a ser comparado
         * @return verdadeiro ou falso
         */
        bool igual(Ponto p);

};

#endif // PONTO_H
