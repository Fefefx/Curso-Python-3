#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

//Definição da estrutura dos elementos da lista
typedef struct chain
{
    int data;
    struct chain *next;
    struct chain *previous;
} list;

//Definição do escopo das funções
list *insert(list *l, int data);
list *initialize();
bool isEmpty(list *l);
bool hasOneElement(list *l);
bool isBigger(list *l, int data);
bool isSmaller(list *l, int data);
list *insertFirst(list *element);
list *insertSecond(list *element, list *l);
list *insertThreeOrMore(list *element, list *l);
list *lastElement(list *l);
list *previousElement(list *l, int data);
list *removeLastElement(list *l);
list *removeFirstElement(list *l);
bool validate(list *l);
void print(list *l);
void printDescending(list *l);
list *input(list *l);
list *cleanList(list *l);

/*
    @description Insere um elemento na lista
    @param *l Um ponteiro para o início da lista
    @param data O número que será inserido na lista
    @return A lista com o valor inserido
*/
list *insert(list *l, int data)
{
    list *element = malloc(sizeof(list));
    element->data = data;
    if (isEmpty(l))
        l = insertFirst(element);
    else if (hasOneElement(l))
        l = insertSecond(element, l);
    else
        l = insertThreeOrMore(element, l);
    return l;
}

/*
    @description Inicializa o ponteiro de um lista
    @return Retorna valor NULL
*/
list *initialize()
{
    return NULL;
}

/*
    @description Verifica se a lista está vazia
    @param *l Um ponteiro para o início da lista
    @return Um booleano indicando se a lista está vazia
*/
bool isEmpty(list *l)
{
    if (l == NULL)
        return true;
    else
        return false;
}

/*
    @description Verifica se a lista possui apenas um elemento
    @param *l Um ponteiro para o início da lista
    @return Um booleano indicicando se a lista possui somente um elemento
*/
bool hasOneElement(list *l)
{
    if (l->next == NULL && l->previous == NULL)
        return true;
    else
        return false;
}

/*
    @description Verifica se o dado a ser inserido será o maior elemento da lista
    @param *l Um ponteiro para o início da lista
    @param data O número que será inserido na lista
    @return Um booleano indicando se o elemento a ser inserido será o maior item da lista
*/
bool isBigger(list *l, int data)
{
    list *i;
    bool test = true;
    for (i = l; i != NULL; i = i->next)
    {
        if (data <= i->data)
        {
            test = false;
            break;
        }
    }
    return test;
}

/*
    @description Verifica se o dado a ser inserido será o menor elemento da lista
    @param *l Um ponteiro para o início da lista
    @param data O número que será inserido na lista
    @return Um booleano indicando se o elemento a ser inserido será o menor item da lista    
*/
bool isSmaller(list *l, int data)
{
    list *i;
    bool test = true;
    for (i = l; i != NULL; i = i->next)
    {
        if (data >= i->data)
        {
            test = false;
            break;
        }
    }
    return test;
}

/*
    @description Insere o primeiro elemento na lista
    @param *element Ponteiro para o elemento a ser inserido
    @return A lista com o elemento inserido
*/
list *insertFirst(list *element)
{
    element->next = NULL;
    element->previous = NULL;
    return element;
}

/*
    @description Insere em ordem crescente o segundo elemento na lista
    @param *element Ponteiro para o elemento a ser inserido
    @param *l Um ponteiro para o início da lista
    @return A lista com o elemento inserido
*/
list *insertSecond(list *element, list *l)
{
    if (element->data > l->data)
    {
        l->next = element;
        element->previous = l;
        element->next = NULL;
        return l;
    }
    else
    {
        element->previous = NULL;
        element->next = l;
        l->previous = element;
        return element;
    }
}

/*
    @description Insere em ordem crescente o terceiro elemento ou posterioes na lista
    @param *element Ponteiro para o elemento a ser inserido
    @param *l Um ponteiro para o início da lista
    @return A lista com o elemento inserido
*/
list *insertThreeOrMore(list *element, list *l)
{
    if (isBigger(l, element->data))
    {
        list *final = lastElement(l);
        final->next = element;
        element->previous = final;
        element->next = NULL;
        return l;
    }
    else if (isSmaller(l, element->data))
    {
        element->previous = NULL;
        element->next = l;
        l->previous = element;
        return element;
    }
    else
    {
        list *previous = previousElement(l, element->data);
        element->next = previous->next;
        previous->next->previous = element;
        previous->next = element;
        element->previous = previous;
        return l;
    }
}

/*
    @description Localiza o último elemento da lista
    @param *l Um ponteiro para o início da lista
    @return O último elemento da lista
*/
list *lastElement(list *l)
{
    list *i;
    for (i = l; i != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            return i;
        }
    }
}

/*
    @description Localiza o elemento que deve corresponder ao anterior de um dado que será inserido na lista
    @param *l Um ponteiro para o início da lista
    @param data O dado que será inserido
    @return O elemento da lista que deve ocupar a posição anterior ao dado
*/
list *previousElement(list *l, int data)
{
    list *i;
    for (i = l->next; i != NULL; i = i->next)
    {
        if (i->previous->data <= data && i->data >= data)
        {
            return i->previous;
        }
    }
}

/*
    @description Remove o último elemento da lista
    @param *l Um ponteiro para o início da lista
    @return A lista com o último elemento removido
*/
list *removeLastElement(list *l)
{
    if (validate(l))
    {
        if (hasOneElement(l))
            l = cleanList(l);
        else
        {
            list *last = lastElement(l);
            last->previous->next = NULL;
            print(l);
        }
    }
    return l;
}

/*
    @description Remove o primeiro elemento da lista
    @param *l Um ponteiro para o início da lista
    @return A lista com o primeiro elemento removido
*/
list *removeFirstElement(list *l)
{
    if (validate(l))
    {
        if (hasOneElement(l))
            l = cleanList(l);
        else
        {
            l->next->previous = NULL;
            return l->next;
            print(l);
        }
    }
    return l;
}

/*
    @description Remove todos os elementos da lista
    @param *l Um ponteiro para o início da lista
    @return A lista vazia com um ponteiro apontando para NULL
*/
list *cleanList(list *l)
{
    if (validate(l))
    {
        l = initialize();
        printf("\nTodos os elementos da lista foram eliminados.\n");
        return l;
    }
}

/*
    @description Imprime no console os elementos da lista em ordem decrescente
    @param *l Um ponteiro para o início da lista
*/
void printDescending(list *l)
{
    if (validate(l))
    {
        list *i;
        printf("\nElementos da lista em ordem decrescente:\n\n");
        for (i = lastElement(l); i != NULL; i = i->previous)
        {
            printf("%d ", i->data);
        }
        printf("\n");
    }
}

/*
    @description Valida uma transação verificando se a lista está vazia. Caso esteja indica que ela não pode ser realizada
    @param *l Um ponteiro para o início da lista
    @return Um booleano indicando se a operanção pode ou não ser realizada
*/
bool validate(list *l)
{
    if (isEmpty(l))
    {
        printf("\nNão foi possível realizar a ação ! A Lista está vazia.\n");
        return false;
    }
    return true;
}

/*
    @description Imprime no console os elementos da lista em ordem crescente
    @param *l Um ponteiro para o início da lista
*/
void print(list *l)
{
    if (validate(l))
    {
        printf("\nNúmeros armazenados na lista: \n\n");
        list *i;
        for (i = l; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
        printf("\n");
    }
}

/*
    @description Adiciona um ou mais elementos a lista
    @param *l Um ponteiro para o início da lista
    @return A lista com os elementos inseridos
*/
list *input(list *l)
{
    char answer = 'n';
    int data;
    printf("\n");
    do
    {
        printf("Digite um número: ");
        scanf("%d", &data);
        l = insert(l, data);
        print(l);
        printf("\nDeseja digitar mais um número [S/n]? ");
        scanf(" %[^\n]s", &answer);
    } while (answer == 'S' || answer == 's');
    return l;
}

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
    list *l;
    l = initialize();
    char answer = 'n';
    int opcao;
    do
    {
        printf("\nMenu de opções:\n");
        printf("\n1 - Inserir um elemento\n");
        printf("2 - Remover em fila\n");
        printf("3 - Remover em pilha\n");
        printf("4 - Listar elementos em ordem crescente\n");
        printf("5 - Listar elementos em ordem decrescente\n");
        printf("6 - Esvaziar a lista\n\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            l = input(l);
            break;
        case 2:
            l = removeFirstElement(l);
            break;
        case 3:
            l = removeLastElement(l);
            break;
        case 4:
            print(l);
            break;
        case 5:
            printDescending(l);
            break;
        case 6:
            l = cleanList(l);
            break;
        default:
            printf("\nSeleção inválida !\n");
            break;
        }
        printf("\nDeseja realizar outra operação [S/n]? ");
        scanf(" %[^\n]s", &answer);
    } while (answer == 'S' || answer == 's');
    return 0;
}
