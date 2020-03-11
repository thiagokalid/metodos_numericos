#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 1;
    int n1 = mudanca_base(numero, 10, 2);
    int n2 = mudanca_base_recursiva(numero, 10, 2, 0);
    printf("");
    printf("mudanca_base = %d \n mudanca_base_recursiva = %d", n1, n2);
    return 0;
}

unsigned long int expo(long int base, int exponent){
    unsigned long int result = 1;
    for (exponent; exponent>0; exponent--)
{
        result = result * base;
}
    printf("resultado do expoente = %d \n", result);
    return result;
}

// @param n: numero inteiro a ser convertido de base;
// @param base_inicio: base na qual o numero n esta representado;
// @param: base_destino: base a qual o numero sera convertido para;
// @return: numero int representado na base_destino;
int mudanca_base(int n, int base_inicio, int base_destino){
    unsigned long int numero_base = n; // copia defensiva;
    unsigned long int soma = 0;
    int k = 0;
    unsigned long int resto;
    unsigned long int expoente;

    while(numero_base != 0){
        resto = numero_base % base_destino;
        int quociente = numero_base / base_destino;

        printf("numero base = %d \n quociente = %d \n", numero_base, quociente);

        expoente = expo(base_inicio, k);
        soma = soma + resto * expoente;

        printf("resto = %d \n", resto);


        numero_base = numero_base / base_destino;




        printf("%d * %d ** %d  = %d \n",resto , base_inicio, k, expoente);

        printf("soma = %d \n", soma);
        k++;
        printf("\n\n");

    }

    return soma;
    }


// @param n: numero inteiro a ser convertido de base;
// @param base_inicio: base na qual o numero n esta representado;
// @param: base_destino: base a qual o numero sera convertido para;
// @return: numero int representado na base_destino;
int mudanca_base_recursiva(int n, int base_inicio, int base_destino, int k){
    int numero_base = n; // copia defensiva;
    int soma = 0;
    int resto;
    int expoente;



    resto = numero_base % base_destino;
    expoente = resto * expo(base_inicio, k);
    numero_base = numero_base / base_destino;

    k++;

    if(numero_base == 0){
        return expoente;
    }else{

        return expoente + mudanca_base_recursiva(numero_base, base_inicio, base_destino , k);
    }
    }
