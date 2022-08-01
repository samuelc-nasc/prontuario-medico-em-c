#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declarando uma estrutura do tipo C;
typedef struct{
    int id;
    char nome[50];
    float altura;
    int idade;
    float peso;
}C;

//declarando um novo tipo C chamado Paciente;
typedef struct{
    int id;
    char nome[50];
    float altura;
    int idade;
    float peso;
}Paciente;

int menu(){
    int opc=0;;
    printf("1 - Inicializar lista \n");
    printf("2 - Imprimir um paciente \n");
    printf("3 - Inserir um paciente \n");
    printf("4 - Editar um paciente \n");
    printf("5 - Media da idade dos pacientes \n");
    printf("6 - Paciente mais pesado \n");
    printf("7 - Imprimir a lista de pacientes \n");
    printf("8 - Sair \n");
    printf("Opcao = ");scanf("%d", &opc);
    return opc;
}
int inicializar(Paciente lista[],int tam){
    int inicializou = 0;
    for(int i=0;i<tam;i++){
        lista[i].id = -1;
        inicializou = 1;
    }
    return inicializou;
}

Paciente lerPaciente(){
    Paciente c;
    printf("Id = ");scanf("%d", &c.id);
    printf("Nome = ");scanf(" %[^\n]s", c.nome);
    printf("Altura = ");scanf("%f", &c.altura);
    printf("Idade = ");scanf("%d", &c.idade);
    printf("Peso = ");scanf("%f", &c.peso);
    return c;
}

void impimirPaciente(Paciente p){
    printf("\n---------------------------\n");
    printf("Id = %d \n", p.id);
    printf("Nome = %s \n", p.nome);
    printf("Altura = %2.f \n", p.altura);
    printf("Idade = %d \n", p.idade);
    printf("Peso = %.2f \n", p.peso);
}

int imprimirUmPaciente(Paciente* lista, int tam, int identificador){
    int encontrado = 0;
        for(int i=0;i<tam;i++){
            if(lista[i].id==identificador){
                impimirPaciente(lista[i]);
                encontrado = 1;
                break;
            }
        }
    return encontrado;
}

int inserirPaciente(Paciente* lista, int tam){
    int inseriu = 0;
    for(int i=0;i<tam;i++){
        if(lista[i].id==-1){
            lista[i] = lerPaciente();
            inseriu=1;
            break;
        }
    }
    return inseriu;
}

int editarPacientePorNome(Paciente* lista, int tam, char nomeRecebido[]){
    int editado = 0;
    for(int i=0;i<tam;i++){
        if(strcmp(lista[i].nome,nomeRecebido)==0){
            lista[i] = lerPaciente();
            editado = 1;
            break;
        }
    }
    return editado;
}

float mediaDasIdades(Paciente* lista, int tam){
    int div = 0;
    float soma = 0.0;
    for(int i=0;i<tam;i++){
        if(lista[i].id!=-1){
            soma+=lista[i].idade;
            div++;
        }
    }
    float media = soma/div;
    return media;
}

int pacienteMaisPesado(Paciente* lista, int tam){
    Paciente maior = lista[0];
    int verificador = 0;
    for(int i=0;i<tam;i++){
        if(lista[i].id!=-1){
            if(lista[i].peso > maior.peso){
                maior = lista[i];
            }
            verificador = 1;
        }
    }
    if(verificador==1)impimirPaciente(maior);
    return verificador;
}

int printarLista(Paciente* lista, int tam){
    int printou = 0;
    for(int i=0;i<tam;i++){
        if(lista[i].id!=-1){
            impimirPaciente(lista[i]);
            printou = 1;
        }
    }
    return printou;
}

int main(){
    int tam;
    printf("Qual a quantidade de paciente?\n");
    printf("Quantidade = ");scanf("%d",&tam);
    Paciente lista[tam];
    int opc;
    do{
        printf("\n-----------------------LISTA DE PACIENTES---------------------\n\n");
        opc = menu();
        if(opc==1){
            printf("\nIninializando lista...\n");
            int inicializou = inicializar(lista, tam);
                if(inicializou==1)printf("\nLista inicializada com sucesso!\n\n");
                else printf("\nLista nao foi inicializada!\n\n");
        }else if(opc==2){
                printf("\n-----------------IMPRIMINDO UM PACIENTE-------------\n");
                int id;
                printf("Qual a id do paciente que deseja imprimir?\n");
                scanf("%d", &id);
                printf("\n---------------PACIENTES---------------\n");
                int encontrou = imprimirUmPaciente(lista, tam, id);
                    if(encontrou==1)printf("\nPaciente encontrado!\n\n");
                    else printf("\nPaciente nao encontrado!\n\n");
        }else if(opc==3){
            printf("\n----------------INSERINDO PACIENTE-------------------\n");
            int inseriu = inserirPaciente(lista, tam);
                if(inseriu==1)printf("\nPaciente inserido com sucesso!\n\n");
                else printf("\nA lista esta cheia!\n\n");
        }else if(opc==4){
            printf("\n---------------EDITAR PACIENTE--------------------\n");
            char nomePaciente[50];
            printf("Digite o nome do paciente que deseja editar:\n");
            scanf(" %[^\n]s", nomePaciente);
            int editou = editarPacientePorNome(lista, tam, nomePaciente);
                if(editou==1)printf("\nPaciente editado com sucesso!\n\n");
                else printf("\nPaciente nao encontrado!\n\n");
        }else if(opc==5){
            printf("\n------------------------MEDIA DA IDADE DOS PACINETES-------------------\n");
            float media = mediaDasIdades(lista, tam);
            if(media>0.0)printf("Media das idades dos pacientes = %.2f \n\n", media);
        }else if(opc==6){
            printf("\n---------------------PACIENTE MAIS PESADO---------------------\n");
            int informou = pacienteMaisPesado(lista, tam);
                if(informou==1)printf("\nPaciente impresso com sucesso!\n\n");
                else printf("\nNao ha pacientes para ser impresso!\n\n");
        }else if(opc==7){
            printf("\n--------------------LISTA DE PACIENTES------------------------\n");
            int mostrou = printarLista(lista, tam);
                if(mostrou==1)printf("\nLista impressa com sucesso!\n\n");
                else printf("\nNao ha lista para imprimir!\n\n");
        }
    }while(opc!=8);
    return 0;
}