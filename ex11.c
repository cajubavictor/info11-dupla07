/*JOGO DO NIM
 * Autores:Juliane Rocha e Victor Cajuba
 * Data:29-04-2016*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int jogo,cent,dez,unid,jogada,teste1,teste2,teste3;

    scanf("%d",&jogo);

    cent=jogo/100;/*separa a centena*/
    dez=(jogo-(cent*100))/10;/*separa a dezena dos tres numeros da jogo*/
    unid=(jogo-((cent*100)+(dez*10)));/*separa a unidade dos tres numeros da jogo*/

    while(cent>3 && dez>5 && unid>7) /* cria um laco para caso o usuario digite uma jogada em que a centena >3 a dez>5 e a unid>7 e pede pra o usuario
                                        digitar a jogo de novo*/
    {                                  
        scanf("%d",&jogo);
        
        cent=jogo/100;
        dez=(jogo-(cent*100))/10;
        unid=(jogo-((cent*100)+(dez*10)));
    }
    
    jogada=cent^dez^unid; /* essa linha tranforma os numeros da cent,dez e unid em binario e faz a soma deles*/
    
    if(jogada==0)/* o usuario joga uma nim perfeita
                    a intensao do jogo agora e enrolar a partida*/
    {
        if((cent==1 && dez==0 && unid==0)||(cent==0 && dez==1 && unid==0)||(cent==0 && dez==0 && unid==1))
            printf("000\n"); /* caso em que o computador perde*/

        if(cent>dez && cent>unid)
        {
            cent = cent - 1;
            printf("%d%d%d\n",cent,dez,unid);
        }

        if(dez>cent && dez>unid)
        {
            dez = dez - 1;
            printf("%d%d%d\n",cent,dez,unid);
        }

        if(unid>cent && unid>dez)
        {
            unid = unid - 1;
            printf("%d%d%d", cent,dez,unid);
        }    
    } 

    return 0;
}   
