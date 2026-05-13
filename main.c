#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int descarte[52];
    int i=0;
    int dealer=0;
    int jogador=0;
    int maoDealer[21];
    int maoJogador[21];
    int contDealer=0;
    int contJogador=0;

    while (1){
        printf("====BLACKJACK 21====\n\n");
        //DEALER
        //printf("Dealer: ");
        int valor = 1 + rand() % 10;
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



        int con = 1;
        while(con){


            


            
            
            //Turno Player
            if (con==1){
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

                if (jogador == 21){
                    printf("PLAYER - BLACKJACK!!");
                    break;
                }
                if (jogador > 21){
                    printf("O Player estorou a rodada!");
                    break;
                }

                char escolha[1];
                printf("\nStand - Hit - Double\n");
                scanf(" %c", &escolha[0]);
                getchar();
                
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
                printf("\n\n\n\n\n");
            }
            
            //Turno Dealer
            if (con == 2){
                
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

                if (dealer == 21){
                    printf("DEALER - BLACKJACK!!");
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
                
                int valor = 1 + rand() % 10;
                dealer += valor;
                descarte[i] = valor;
                maoDealer[contDealer] = valor;
                i++;
                contDealer++;
            }
        }
        break;
    }
    return 0;
}