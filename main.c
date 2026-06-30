#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//A lib <time.h> serve pra gerar valores aleatórios com o srand()
int descarte[52];
int i=0;
int dealer=0;
int jogador=0;
int maoDealer[21];
int maoJogador[21];
int contDealer=0;
int contJogador=0;
int valor;
int con = 1;
char escolha[1];

void menuPlayer(){
    printf("=====21=====\n\n");
    printf("Dealer: ");
    for (i=0;i<contDealer-1;i++){
        printf("[%d] ", maoDealer[i]);
    }
    printf("[*]");
    printf("\n\n");


    printf("Player: ");
    for (i=0;i<contJogador;i++){
        printf("[%d] ", maoJogador[i]);
    }
    printf("- Total = %d", jogador);
    printf("\n\n");
}

void menuDealer(){
    printf("=====21=====\n\n");
    printf("Dealer: ");
    for (i=0;i<contDealer;i++){
        printf("[%d] ", maoDealer[i]);
    }
    printf("- Total = %d", dealer);
    printf("\n\n");


    printf("Player: ");
    for (i=0;i<contJogador;i++){
        printf("[%d] ", maoJogador[i]);
    }
    printf("- Total = %d", jogador);
    printf("\n\n");
}

void setPlay(){
    switch (escolha[0]){
        case 's':
            con = 2;
            break;
        case 'h':
            valor = 1 + rand() % 10;
            jogador += valor;
            descarte[i] = valor;
            maoJogador[contJogador] = valor;
            i++;
            contJogador++;
            
            break;
        case 'd':
            /* code */
            break;
        
        default:
            break;
    }
}

int main(){
    srand(time(NULL));
    
//Start
    while (1){
    //Gerar cartas aleatórias pro Dealer e Player
    //DEALER
        //printf("Dealer: ");
        valor = 1 + rand() % 10;
        dealer += valor;
        descarte[i] = valor;
        maoDealer[contDealer] = valor;
        i++;
        contDealer++;
        //printf("[%d] ", valor);
        valor = 1 + rand() % 10;
        dealer += valor;
        descarte[i] = valor;
        maoDealer[contDealer] = valor;
        i++;
        contDealer++;
        //printf("[%d]\n", valor);

    //PLAYER
        //printf("Jogador: ");
        valor = 1 + rand() % 10;
        jogador += valor;
        descarte[i] = valor;
        maoJogador[contJogador] = valor;
        i++;
        contJogador++;
        //printf("[%d] ", valor);
        valor = 1 + rand() % 10;
        jogador += valor;
        descarte[i] = valor;
        maoJogador[contJogador] = valor;
        i++;
        contJogador++;
        //printf("[%d]\n", valor);


    //Início da partida
        while(con){

        //Turno Player
            if (con==1){
            //Menu Player
                menuPlayer();
            //Final Menu Player

            //Verificar se player deu BJ
                if (jogador == 21){
                    printf("PLAYER - BLACKJACK!!\n");
                    break;
                }
            //Verificar se Player estorou
                if (jogador > 21){
                    printf("O Player estorou a rodada!\n");
                    break;
                }
            //Msg de escolha
                printf("\nStand - Hit - Double\n");
                scanf(" %c", &escolha[0]);
                getchar();

                
            //Fazer escolha - STAND / HIT / DOUBLE
                setPlay();
            //Final da escolha
                printf("\n\n\n\n\n");
            }
            
        //Turno Dealer
            if (con == 2){
            //Menu Dealer
                menuDealer();
            //Final Menu Dealer
            //Validar se Dealer BJ, se não BJ ou se perdeu pro Player
                if (dealer == 21){
                    printf("DEALER - BLACKJACK!!\n");
                    break;
                }
                if (dealer > 21){
                    printf("O Dealer estorou a rodada!\n");
                    printf("Player venceu!!!");
                    break;
                }

                if (dealer > jogador){
                    printf("Dealer - Venceu!\n");
                    break;
                }

                printf("Continuar...");
                getchar();
                printf("\n\n\n\n\n");
                
            //Puxar nova carta pro dealer(e colocar no descarte logo após)
                valor = 1 + rand() % 10;
                dealer += valor;
                descarte[i] = valor;
                maoDealer[contDealer] = valor;
                i++;
                contDealer++;
            }
        }
        break;
    }
    system("pause");
    return 0;
}