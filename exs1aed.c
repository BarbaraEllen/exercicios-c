#include <stdio.h>
#include <malloc.h>

// comparando implementações estáticas e dinâmicas dos mesmos algoritmos
// busca (OK) , inicializa (OK) , imprime (OK) , insere, exclui (lista lig, lista seq)

#define MAX 10

typedef struct {
    int id;
    int chave;
    int prox;
}ALUNO;

typedef struct s{
    int id;
    int chave;
    struct s*prox;
}NO;

typedef struct {
    ALUNO a[MAX];
    int qtd;
}LISTA_SEQ;

typedef struct {
    ALUNO* a;
    int qtd;
}LISTA_SEQ_DIN;

typedef struct {
    ALUNO a[MAX];
    int inicio;
    int dispo;
}LISTA_LIG;

typedef struct {
    NO* inicio;
}LISTA_LIG_DIN;



int main(){
    LISTA_SEQ s;
    LISTA_LIG l;
}

void inicializar_listaseq_est (LISTA_SEQ* s){
    s -> qtd = 0;
}

void inicializar_listaseq_din (LISTA_SEQ_DIN* s){
    s -> qtd = 0;
    s -> a = (ALUNO*) malloc (sizeof(ALUNO)*MAX);
}

void inicializar_listalig_est (LISTA_LIG* l){
    l -> inicio = -1;
    l -> dispo = 0;
    for (int i=0; i < MAX; i++){
        l -> a[i].prox = i+1;
    }
    l -> a[MAX-1].prox = -1;
}

void inicializar_listalig_din (LISTA_LIG* l){
    // não precisa;
}

void imprime_listaseq_est (LISTA_SEQ* s){
    for (int i=0; i < s -> qtd ; i++){
        printf ("%d", s -> a[i].id);
        printf ("\n");
        printf ("%d", s -> a[i].chave);
        printf ("\n");
    }
    printf ("%d\n", s -> qtd);
}

void imprime_listaseq_din (LISTA_SEQ_DIN* s){
    for (int i=0; i < s -> qtd ; i++){
        printf ("%d", s -> a[i].id);
        printf ("\n");
        printf ("%d", s -> a[i].chave);
        printf ("\n");
    }
    printf ("%d\n", s -> qtd);
}

void imprime_listalig_est (LISTA_LIG* l){
    int aux = l -> inicio;
    while (aux!= -1){
        printf ("%d", l -> a[aux].id);
        printf ("\n");
        printf ("%d", l -> a[aux].chave);
        aux = l -> a[aux].prox;
    }
}

void imprime_listalig_din (NO ** inicio){
    NO * p = *inicio;
    while (p){
        printf ("%d", p -> id);
        printf ("\n");
        printf ("%d", p -> chave);
        printf ("\n");
        p = p -> prox;
    }
}

int busca_listaseq_est (LISTA_SEQ* s, int ch, int inicio, int fim){ // lista ordenada crescente
    int meio = (fim + inicio)/2;
    if (s -> a[meio].chave == ch){
        return meio;
    }else if (inicio == fim){
        return -1;
    }else if (s -> a[meio].chave < ch){
        return busca_listaseq_est (s, ch, meio+1, fim);
    }else{
        return busca_listaseq_est (s, ch, inicio, meio-1);
    }
}

int busca_listaseq_din (LISTA_SEQ_DIN* s, int ch, int* pos){ // atualizamos para uma lista ordenada
    * pos = -1;
    for (int i=0; i < s -> qtd; i++){
        if (ch == s -> a[i].chave){
            return i;
        }else if (ch < s -> a[i].chave){
            return -1;
        }
    * pos = i;
    }
return -1;
}

int busca_listalig_est (LISTA_LIG* l, int ident){
    p = l -> inicio;
    while(p >= 0){
        if (ident == l -> a[p].id){
            return l -> a[p].chave;
        }else{
            p = l -> a[p].prox;
        }
    }
return -1;
}

NO* busca_listalig_din (LISTA_LIG_DIN* l, int ident){ // Normalmente retornamos o ponteiro na lista ligada dinamica
    NO *p = l-> inicio;
    while(p){
        if (ident == p -> id){
            return p;
        }else{
            p = p -> prox;
        }
    }
return NULL;
}

bool insere_listaseq_est (LISTA_SEQ* s, ALUNO novo){ // Inserção em lista não ordenada
    if (s -> qtd == MAX){
        return false;
    }
    s -> a[s -> qtd] = novo;
    s -> qtd++;
    return true;
}

bool insere_listaseq_din (LISTA_SEQ_DIN* s, ALUNO novo){
    int anterior;
    int result = busca_listaseq_din(s, novo.chave, &anterior);
    if (result != -1){
        return false;
    }else{
        for (int i = s -> qtd; i > anterior + 1; i--){
            s -> a[i] = s -> a[i-1];
        }
        s -> a[anterior + 1] = novo;
        return true;
    }
}



