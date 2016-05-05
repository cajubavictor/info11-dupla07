/*JOGO DO NIM
 * Autores:Juliane Rocha e Victor Cajuba
 * Data:29-04-2016*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int jogo,cent,dez,unid,x,y,teste1,teste2,teste3,jogada;

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
    if (((cent==1)&&(dez==0)&&(unid==0))||(((cent==0)&&(((dez==1)))&&((unid==0)))||(((cent==0))&&((dez==0))&&(unid==1))))  
    {
        printf("000\n");
    }
    else
    {
        jogada=cent^dez^unid; /* essa linha tranforma os numeros da cent,dez e unid em binario e faz a soma deles*/
    
        if(jogada==0)/* o usuario joga uma nim perfeita a intensao do jogo agora e enrolar a partida*/
        {
            if((cent==1 && dez==0 && unid==0)||(cent==0 && dez==1 && unid==0)||(cent==0 && dez==0 && unid==1))
                printf("000\n"); /* caso em que o computador perde*/
                                /* a partir da proxima sequencia de ifs verifica qual o numero da jogada e maior e retira 1 dele*/
            if(cent>dez && cent>unid)
            {
                cent = cent - 1;
                printf("%d%d%d\n",cent,dez,unid);
            }
            if(dez>=cent && dez>unid)
            {
                dez = dez - 1;
                printf("%d%d%d\n",cent,dez,unid);
            }

            if(unid>=cent && unid>=dez)
            {
                unid = unid - 1;
                printf("%d%d%d\n", cent,dez,unid);
            }    
        } 
        if(jogada!=0)//dar nim perfeita
        {
            
            if((cent==0&&dez==0&&unid!=0))
                printf("001\n");
            if((cent==0&&dez!=0&&unid==0))
                printf("010\n");
            if((cent!=0&&dez==0&&unid==0))
                printf("100\n");
            if((cent!=0&&dez!=0&&unid==0)||(cent!=0&&dez==0&&unid!=0)||(cent==0&&dez!=0&&unid!=0)||(cent!=0&&dez!=0&&unid!=0))
            { 
                if(cent+dez+unid==3)
                {    
                    if((((cent==0)&&(dez==1))&&((unid==2))||((cent==2))&&((dez==1)&&(unid==0))))
                        printf("010\n");
                    if(((cent==1&&dez==2&&unid==0))||(((cent==1))&&((dez==0))&&(unid==2)))
                        printf("100\n");
                    if(((cent==0)&&(dez==2)&&(unid==1))||(((cent==2)&&((dez==0))&&(unid==1))))
                        printf("001\n");
                    if(((cent==1)&&(dez==1))&&(unid==1))
                        printf("101\n");
                }
                else
                {
                    for(x=1;x<=unid;x++)
                    {
                        y=unid-x;
                        teste1=cent^dez^y;
                        if(teste1==0)
                        break;
                    }
                    if (teste1==0)
                        printf("%d%d%d\n",cent,dez,y);
                    else
                    {    
                        for(x=1;x<=dez;x++)
                        {
                            y=dez-x;
                            teste2=cent^y^unid;
                            if(teste2==0)
                            break;
                        }    
                        if (teste2==0)
                            printf("%d%d%d\n",cent,y,unid);
                        else    
                        {    
                            for(x=1;x<=cent;x++)
                            {
                                y=cent-x;
                                teste3=y^dez^unid;
                                if(teste3==0)
                                    printf("%d%d%d\n",y,dez,unid);
                            } 
                        }
                    }
                } 
            }
        }            
    }     
            return 0;
}  
         
