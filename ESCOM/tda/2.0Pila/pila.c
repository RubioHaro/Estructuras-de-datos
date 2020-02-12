struct Pila
{
    int sp;  
    int arreglo[4]; 
};

void push(struct Pila* P, int valor);
void pop(struct Pila* P);
int pilaVacia(struct Pila* P);
int pilaLlena(struct Pila* P);
void iniciarPila(struct Pila* P);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void iniciarPila(struct Pila* p){
    for (int i = 0; i < 4; i++)
    {
        p->arreglo[i] = 0;
        p->sp = 3;
    }
}

void push(struct Pila* P, int valor){
    P->arreglo[P->sp] = valor;
    P->sp;
}



void pop(struct Pila* P){};
int pilaVacia(struct Pila* P);
int pilaLlena(struct Pila* P);
