#ifndef PONTO_H
#define PONTO_H


class Ponto{
    private:
        float _x;
        float _y;

    public:
        // Construtor padrão
        Ponto();

        // Construtor com coordenadas
        Ponto(float a, float b);

        // Getter da propriedade _x
        float x();

        // Setter da propriedade _x
        float x(float a);

        // Getter da propriedade _y
        float y();

        // Setter da propriedade _y
        float y(float a);

        // Setter de _x e _y ao mesmo tempo
        float xy(float a, float b);

        // Combina as coordenadas do ponto com as do ponto p.
        // É a operação equivalente a soma e/ou subtração ao mesmo tempo
        void combinar(Ponto p);

        // Retorna o módulo de um vetor que parte da origem até o ponto
        float norma(void);

        // Desloca em _x de a, e em _y de b.
        // Equivalente a combinar com o ponto (a,b)
        void transladar(float a, float b);

        //Printa as coordenadas do ponto e quebra linha
        void print(void);

};

#endif // PONTO_H