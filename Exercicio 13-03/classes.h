typedef struct {
    int r, g, b, a;
}Cor;

typedef struct {
    int x, y, z;
}Posicao;

class Objeto {
protected:
    Cor c;
    Posicao p;
    Objeto();
private:
    void renderizar();
    void redimensionar();
    void rotacionar();
    void realocar();
    void mudarCor();
    void deletar();
}

class Cubo: public Objeto {
private:
    int base, altura, largura
public:
    Cubo(int b, int a, int l){
        renderizar();
    }
};

class Cone: public Objeto {
private:
    int raio, altura;
public:
    Cone(int r, int a){
        renderizar();
    }
};