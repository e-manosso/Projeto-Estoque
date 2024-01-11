/*
Nome: Erik Luiz Manosso
Universidade Tecnológica Federal do Paraná
Turma: s11
Prof: Hilton
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cliente
{
       int cod_cliente1;
       int tel;
       char ende[50];
       char email[50];
};

struct notas
{
       int num_nf1;
       int cod_cliente2;
       int total_geral;
};

struct itens_notas
{
       int num_nf2;
       int cod_prod1;
       int quant;
       float preco_venda;
};

struct produtos
{
       int cod_prod2;
       char descri[150];
       int uni;
       float preco_uni;
       int quant_est;
};



void cad_cli(struct cliente*grupo,int*quant_cli)
{
     system("cls");
     int i=0,codi=1;
     for(i=0;i<5;i++)//cadastra apenas uma vez
     {
        grupo[i].cod_cliente1=codi;
        printf("Codigo do cliente eh: %i\n",codi);
        printf("Digite o telefone do cliente:\n");
        scanf("%i",&grupo[i].tel);
        printf("Digite o endereço do cliente:\nmax 50 caracteres\n");
        scanf("%s",&grupo[i].ende);
        printf("Digite o email do cliente:\nmax 50 caracteres\n");
        scanf("%s",&grupo[i].email);
        codi++;
        quant_cli++;
        system("cls");    
     }
     
}
void alt_cli(struct cliente*grupo,int *quant_cli)
{
     system("cls");
     int p,t;
     int e=0,o=0;
     
     if(*quant_cli!=0)
     {
        for(p=0;p<1;p++)
        {
           printf("Digite o codigo do cliente\n");
           scanf("%i",&e);
           for(t=0;t<5;t++)
           {             
              if(e==grupo[t].cod_cliente1)
              {
                    o++;
              }
           }
           if(o==1)
           {        
              printf("Qual o novo telefone?\n");
              scanf("%i",&grupo[p].tel);           
              printf("Qual o novo endereço?\n max 50 caracteres\n");
              scanf("%s",&grupo[p].ende);          
              printf("Qual o novo email?\n max 50 caracteres\n");
              scanf("%s",&grupo[p].email);
           }
           else
           {
               printf("Codigo invalido\n");
           }           
        }
     }
     else
     {
         printf("Nenhum cliente registrado!\n");
         printf("Registre um cliente pra alterar seus atributos\n");
     }
     system("pause");
     system("cls");
}

void del_cli(struct cliente*grupo,struct notas*tabela,int*quant_cli,int*quant_not)
{
     system("cls");
     int s,t,cd,cf,po,to=0,vd=0;
     
     printf("Digite o codigo do cliente:\n");
     scanf("%i",&s);
     for(t=0;t<5;t++)
     {
        if(s==grupo[t].cod_cliente1)
        {
           cd++;
           to=grupo[t].cod_cliente1;
        }
     }
     if(cd!=1)
     {
         printf("Codigo de Cliente Invalido\n");
     }
     else
     {
         for(po=0;po<10;po++)
         {
             if(to==tabela[po].cod_cliente2)
             {
                 vd++;
             }
         }
         if(vd>=1)
         {
             printf("Cliente ainda possui notas fiscais\n");
             printf("Impossivel deletar\n");
         }
         else
         {
             
         }
     }
     system("pause");
     system("cls");
}

void cad_prod(struct produtos*lista,int*quant_prod)
{
     system("cls");
     int q;
     int codi1=1;
     for(q=0;q<10;q++)
     {
          lista[q].cod_prod2=codi1;
          printf("O codigo do produto eh: %i\n",codi1);
          printf("Forneca uma breve descricao do produto.\nMax 150 caracteres.\n");
          scanf("%s",&lista[q].descri);
          fflush(stdin);
          printf("Quantas unidades?\n");
          scanf("%i",&lista[q].uni);
          printf("Qual o preco por unidade?\n");
          scanf("%f",&lista[q].preco_uni);
          printf("Qual a quantidade em estoque?\n");
          scanf("%i",&lista[q].quant_est);
          codi1++;
          quant_prod++;
          system("cls");
     }
}

void alt_prod(struct produtos*lista,int*quant_prod)
{
    system("cls");
    int z,x;
    int f=0,q=0;
    
    if(*quant_prod!=0)
    {
        for(z=0;z<1;z++)
        {
             printf("Digite o codigo do produto a ser alterado:\n");
             scanf("%i",&f);
             for(x=0;x<5;x++)
             {
                 if(f==lista[x].cod_prod2)
                 {
                     q++;
                 }
             }
             if(q==1)
             {
                  printf("Digite nova decricao:\nMax 150 caracteres\n");
                  scanf("%s",&lista[z].descri);
                  fflush(stdin);
                  printf("Digite a quatas unidaes tem o produto:\n");
                  scanf("%i",&lista[z].uni);
                  printf("Digite o novo preco do produto:\n");
                  scanf("%f",lista[z].preco_uni);
                  printf("Digite a nova quantidade:\n");
                  scanf("%i",&lista[z].quant_est);
             }
             else
             {
                  printf("Codigo Invalido\n");
             }
        }
    }
    else
    {
        printf("Nenhum produto foi registrado.\nRegistre algum produto para alteralo.\n");
    }
    system("pause");
    system("cls");
}

void del_prod(struct produtos*lista,struct itens_notas*col,int*quant_prod,int*quant_itnot)
{
     system("cls");
     int cp=0,re,dp=0,xa=0,ix,tr=0;
     
     printf("Digite o codigo do produto\n");
     scanf("%i",&cp);
     for(re=0;re<10;re++)
     {
        if(re==lista[re].cod_prod2)
        {
           dp++;
           xa=lista[re].cod_prod2;
        }
     }
     if(dp!=1)
     {
        printf("Codigo Invalido!!!\n");
     }
     else
     {
         for(ix=0;ix<30;ix++)
         {
            if(xa==col[ix].cod_prod1)
            {
                tr++;
            }
         }
         if(tr>=1)
         {
            printf("Produto ainda pertence ah uma nota fiscal\n");
            printf("Imposivel deletar\n");
         }
         else
         {
             
         }
     }
     system("pause");
     system("cls");     
}

void mov(struct cliente*grupo,struct notas*tabela,struct itens_notas*col,struct produtos*lista,int*quant_cli,int*quant_prod,int*quant_not,int*quant_itnot,float*max,float*min,int*maxn,int*minn)
{
     system("cls");
     int w,y,cont1=1,m,p,co=0,cc=0,np=0,ba,ce=0,le;
     int si,qp=0,result=0,totalp=0,tpl=0;
     
     
     if((*quant_cli!=0)&&(*quant_prod!=0))
     {
       printf("Quantas notas serao cadastradas?\n");
       printf("MAX 10 notas\n");
       scanf("%i",&w);
       if(w>10)
       {
             printf("ERRO\nMuitas notas para cadastrar\n");
       }
       else
       {
           for(y=0;y<w;y++)
           {
                tabela[y].num_nf1=cont1;
                printf("Para qual cliente sera emitida essa nota?\n");
                printf("Digite o codigo do cliente\n");
                scanf("%i",&m);
                for(p=0;p<5;p++)
                {
                     if(m==grupo[p].cod_cliente1)
                     {
                        co++;
                        cc=grupo[p].cod_cliente1;
                     }
                }
                if(co!=1)
                {
                   printf("Codigo Invalido!!!\n");
                   p--;
                }
                else
                {
                   cc=tabela[y].cod_cliente2; 
                   printf("Quantos produtos entraram nessa nota?\n");
                   printf("MAX 3 itens\n");
                   scanf("%i",&np);
                   while(np>3)
                   {
                       printf("Ultrapasso o limite de estoque\n");
                       printf("Digite novamente numero de produtos\nMAX 3 itens\n");
                       scanf("%i,&np");
                   }
                   for(ba=0;ba<np;ba++)
                   {
                         col[ba].num_nf2=cont1;
                         printf("Digite o codigo do produto\n");
                         scanf("%i",&ce);
                         for(le=0;le<10;le++)
                         {
                             if(ce==lista[le].cod_prod2)
                             {
                                 si++;
                             }
                         }
                         if(si!=1)
                         {
                            printf("Codigo Invalido!!!");
                            ba--;
                         }
                         else
                         {
                             printf("Qual a quantidade desejada do produto?\n");
                             scanf("%i",&qp);
                             while(qp>lista[ce].quant_est)
                             {                                 
                                 printf("Estoque atual eh de %i\n",lista[ce].quant_est);
                                 printf("Quantidade pedida supera o estoque\n");
                                 printf("Foneca nova quantidade\n");
                                 scanf("%i",&qp);
                             }                             
                             result=lista[ce].quant_est-qp;
                             lista[ce].quant_est=result;
                             col[ba].preco_venda=lista[ce].preco_uni;
                             printf("O preco pro unidade eh de %i\n",col[ba].preco_venda);
                             totalp=qp*col[ba].preco_venda;
                             printf("O total de dese produto eh %i $\n",totalp);
                             tpl=tpl+totalp;
                             *quant_itnot++;
                         }
                   }
                   tpl=tabela[y].total_geral;
                   printf("O total geral eh %i $",tabela[y].total_geral);
                   *quant_not++;
                   cont1++;
                   
                   if(tpl>*max)
                   {
                      *max=tpl;
                      *maxn=cc;
                   }
                   if(tpl<*min)
                   {
                      *min=tpl;
                      *minn=cc;
                   }
               }
          }
      }
     }
     else
     {
         if(*quant_cli==0)
         {
            printf("Nenhum Cliente Cadastrado\n");
         }
         if(*quant_prod==0)
         {
            printf("Nenhum Produto Cadastrado\n");
         }
         printf("Favor Realizar os cadastros primeiro\n");
     }
     system("pause");
     system("cls");
}

void consulta(float*max,float*min,int*maxn,int*minn)
{
     system("cls");
     int c=0;
     
     while(c!=6)
     {
        printf("----------\nConsultas\n----------\n");
        printf("1 - Verificar entre valores distintos\n");
        printf("2 - Verificar notas e itens de cliente distinto\n");
        printf("3 - Verificar notas e itens com valor total distinto\n");
        printf("4 - Verificar nota com maior valor total\n");
        printf("5 - Verificar nota com menor valor total\n");
        printf("6 - Voltar ao menu\n");
        scanf("%i",&c);
        switch(c)
        {
             case 1:
             {
                  
             }break;
             case 2:
             {
                  
             }break;
             case 3:
             {
                  
             }break;
             case 4:
             {
                  system("cls");
                  printf("A nota com o maior valor pertence ao cliente %i\n",*maxn);
                  printf("O valor da nota eh de: %i\n",*max);
                  system("pause");
                  system("cls");
             }break;
             case 5:
             {
                  system("cls");
                  printf("A nota com menor valor pertence ao cliente %i\n",*minn);
                  printf("O valor da nota eh de: %i\n",*min);
                  system("pause");
                  system("cls");
             }break;
             case 6:
             {
                  system("cls");
             }break;
             default:
             {
                  printf("Opcao Invalida!!!\n");  
             }
        }
     }     
}

void cad(struct cliente*grupo,struct notas*tabela,struct itens_notas*col,struct produtos*lista,int*quant_cli,int*quant_prod,int*quant_not,int*quant_itnot)
{
     system("cls");
     int b=0;     
     
     while(b!=7)
     {
          printf("----------\nCadastro\n----------\n");
          printf("1 - Incluir Clientes\n");
          printf("2 - Alterar Clientes\n");
          printf("3 - Excluir Clientes\n");
          printf("4 - Incluir Produto\n");
          printf("5 - Alterar Produto\n");
          printf("6 - Excluir Produto\n");
          printf("7 - Voltar ao menu\n");
          scanf("%i",&b);
          switch(b)
          {
               case 1:
               {
                    cad_cli(grupo,quant_cli);
               }break;
               case 2:
               {
                    alt_cli(grupo,quant_cli);
               }break;
               case 3:
               {
                    del_cli(grupo,tabela,quant_cli,quant_not);
               }break;
               case 4:
               {
                    cad_prod(lista,quant_prod);
               }break;
               case 5:
               {
                    alt_prod(lista,quant_prod);
               }break;
               case 6:
               {
                    del_prod(lista,col,quant_prod,quant_itnot);
               }break;
               case 7:
               {
                    system("cls");
               }break;
               default:
               {
                    printf("Opcao Invalida!!!\n");  
               }
          }
     }
}

int main()
{
    struct cliente*grupo;
    struct notas*tabela;
    struct itens_notas*col;
    struct produtos*lista;
    int a=0;
    int quant_cli=0;
    int quant_prod=0;
    int quant_not=0;
    int quant_itnot=0;
    int maxn=0,minn=0;
    float max=0,min=999999999;
    
    grupo=(struct cliente*)malloc(5*sizeof(struct cliente));
    if(!grupo)
    {
        printf("Erro na alocação de memoria");
        system("pause");
        exit(1);
    }
    
    tabela=(struct notas*)malloc(10*sizeof(struct notas));
    if(!tabela)
    {
        printf("Erro na alocação de memoria");
        system("pause");
        exit(1);
    }
    
    col=(struct itens_notas*)malloc(30*sizeof(struct itens_notas));
    if(!col)
    {
        printf("Erro na alocação de memoria");
        system("pause");
        exit(1);
    }
    
    lista=(struct produtos*)malloc(10*sizeof(struct produtos));
    if(!lista)
    {
        printf("Erro na alocação de memoria");
        system("pause");
        exit(1);
    }

    while(a!=4)
    {
       system("cls");
	   printf("----------\nEstoque\n----------\n\n");
       printf("Selecione sua opcao\n");
       printf("1 - Cadastro\n");
       printf("2 - Movimentacoes\n");
       printf("3 - Consultas\n");
       printf("4 - Sair do Programa\n");
       scanf("%i",&a);
       switch(a)
       {
           case 1:
           {
                cad(grupo,tabela,col,lista,&quant_cli,&quant_prod,&quant_not,&quant_itnot);
           }break;
           case 2:
           {
                mov(grupo,tabela,col,lista,&quant_cli,&quant_prod,&quant_not,&quant_itnot,&max,&min,&maxn,&minn);
           }break;
           case 3:
           {
                consulta(&max,&min,&maxn,&minn);
           }break;
           case 4:
           {
                exit(1);
           }break;
           default:
           {
               printf("Opcao Invalida!!!!");
			   system("pause");  
           }
       }
    }
    free(grupo);
    free(tabela);
    free(col);
    free(lista);
    system("pause");
    return 0;
}
