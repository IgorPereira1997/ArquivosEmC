#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#define MAXCOLS 100

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * PILHA_ENC;

void cria_pilha(PILHA_ENC *pp){
    *pp=NULL;
}

int eh_vazia(PILHA_ENC p){
    return(p==NULL);
}

void push(PILHA_ENC *pp, int v){
    NODO *new=(NODO*)calloc(1,sizeof(NODO));
    if(!new){
    	printf("\nERRO! Memoria Insuficiente!\n");
    	exit(1);
    }
    new->inf=v;
    new->next=(*pp);
    (*pp)=new;
}

int top(PILHA_ENC p){
    if(eh_vazia(p)){
    	printf("\nERRO! Pilha vazia!");
    	exit(2);
    }
    return(p->inf);
}

void pop(PILHA_ENC *pp){
    if(eh_vazia(*pp)){
	printf("\nERRO! Pilha vazia!");
	exit(3);
    }
    NODO *aux=*pp;
    (*pp)=(*pp)->next;
    free(aux);
}

int top_pop(PILHA_ENC *pp){
    if(eh_vazia(*pp)){
	printf("\nERRO! Pilha vazia!");
	exit(4);
    }
    NODO *aux=*pp;
    int v=(*pp)->inf;
    (*pp)=(*pp)->next;
    free(aux);
    return (v);
}

int aplicar(int op1, char op, int op2){
    switch(op){
	case '+': return(op1+op2);
	case '-': return(op1-op2);
	case '*': return(op1*op2);
	case '/': return((int)op1/op2);
	case '^': return((int)pow(op1,op2));
    }
}

int prcd(char op1, char op2){
    if ((op1=='+' || op1=='-') && (op2=='+' || op2=='-'))
	return (1);
    if ((op1=='*' || op1=='/') && (op2=='+' || op2=='-' || op2=='*' || op2=='/'))
	return (1);
    if (op1=='^' && (op2=='^' || op2=='+' || op2=='-' || op2=='*' || op2=='/'))
	return (1);
    if ((op1=='^' && (op2=='^' || op2=='+' || op2=='-' || op2=='*' || op2=='/'))&&op2==')')
	return (1);
    return (0);
}

int eh_operando(char op){
    return (op!='+'&&op!='-'&&op!='*'&&op!='/'&&op!='^'&&op!='('&&op!=')');
}

int avaliar(char *e){
    char symbol;
    int i=0, op1, op2;
    PILHA_ENC pilha_operandos;
    cria_pilha(&pilha_operandos);
    while(symbol=e[i++])
        if(eh_operando(symbol))
            push(&pilha_operandos,symbol-'0');
        else{
            op1=top_pop(&pilha_operandos);
            op2=top_pop(&pilha_operandos);
            push(&pilha_operandos,aplicar(op1,symbol,op2));
        }
    return(top_pop(&pilha_operandos));
}

void converter_s_p(char *o, char *d){
    char symbol;
    int i1=0, i2=0;
    PILHA_ENC opstack;
    cria_pilha(&opstack);
    while(symbol=o[i1++])
        if(eh_operando(symbol))
            d[i2++]=symbol;
        else{
            while(!eh_vazia(opstack)&&prcd(top(opstack), symbol))
                d[i2++]=top_pop(&opstack);
            if (symbol==')')
                pop(&opstack);
            else
		push(&opstack, symbol);
        }
    while(!eh_vazia(opstack))
    	d[i2++]=top_pop(&opstack);
    d[i2]='\0';
}

int main(int argc, char** argv) {
    char expr [MAXCOLS]; /*# define MAXCOLS ?*/
    int position = 0;
    while ((expr[position++] = getchar ()) != '\n');
    expr[--position]='\0';
    printf ("%s%s","a expressão original eh ",expr);
    printf (" = %d\n", avaliar(expr));
    return (EXIT_SUCCESS);
}