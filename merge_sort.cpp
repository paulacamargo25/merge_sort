#include <iostream>

using namespace std;

int *merge(int *puntero1, int *puntero2,int tam1, int tam2)
{
    int *ptr_final=new int[tam1+tam2];
    int p1=0;
    int p2=0;
    int p3=0;
    while (tam1>0 and tam2>0)
    {
        if (*(puntero1+p1)<=*(puntero2+p2))
        {
            *(ptr_final+p3)=*(puntero1+p1);
            p3+=1;
            p1+=1;
            tam1-=1;
        }

        else
        {
            *(ptr_final+p3)=*(puntero2+p2);
            p3+=1;
            p2+=1;
            tam2-=1;

        }
    }

    while (tam1>0)
    {
        *(ptr_final+p3)=*(puntero1+p1);
        p1+=1;
        p3+=1;
        tam1-=1;
    }

    while (tam2>0)
    {
        *(ptr_final+p3)=*(puntero2+p2);
        p2+=1;
        p3+=1;
        tam2-=1;
    }
    return ptr_final;
}

int* merge_sort(int *puntero_lista,int tam)
{
    if (tam<=1)
    {
        int *punt_lista2=new int[1];
        *(punt_lista2)=*(puntero_lista);
         //cout<<"uno: "<<*(punt_lista2)<<endl;
        return  punt_lista2;
    }
    else
    {
        int *resultado=new int[tam];
        int medio=tam/2;
        int *left=new int[medio];
        int *right=new int[tam-medio];
        int i=0;
        for (int j=0;i<medio;i++,j++)
        {
            *(left+i)=*(puntero_lista+i);
        }
        for(int k=0;i<tam;k++,i++)
        {
            *(right+k)=*(puntero_lista+i);
        }
        left=merge_sort(left,medio);
        right=merge_sort(right,tam-medio);
        /*if (*(left+medio-1)<=*(right))
        {
            int r=0;
            for (int i=0;i<medio;i++,r++)
            {
                *(resultado+r)=*(left+i);
            }
            for(int k=0;r<tam;k++,r++)
            {
                *(resultado+r)=*(right+k);
            }
            return resultado;
        }*/

        resultado=merge(left,right,medio,tam-medio);
        /*for (int i=0;i<tam;i++)
        {
            cout<<*(resultado+i)<<endl;
        }*/
        return resultado;
    }


}

int main()
{
    int tam;
    cin>>tam;
    int lista[tam];
    int temp;
    srand(time(NULL));

    for(int i=0;i<tam;i++)
    {
        temp=rand()%tam;
        lista[i]=temp;
    }
    cout<<"Lista: "<<endl;
    for(int i=0;i<tam;i++)
    {
       cout<<lista[i]<<endl;
    }


    int *ptr_lista=lista;

    //int* listafinal=merge(puntero_lista2,puntero_lista3,4,4);
    int *listafinal=merge_sort(ptr_lista,tam);
    cout<<"\nLista ordenada: "<<endl;
    for (int i=0;i<tam;i++)
    {
        cout<<*(listafinal+i)<<endl;
    }
}
