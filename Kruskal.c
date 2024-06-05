#include<stdio.h>


int visited[10]={0}; // Declaração e inicialização de um array de inteiros com 10 elementos. Custo: O(1)


void kruskal(int w[10][10],int n) // Declaração da função kruskal(). Custo: O(1)
{
    int min,sum=0,ne=0,i,j,u,v,a,b; // Declaração de variáveis inteiras. Custo: O(1)


    while(ne<n-1) // Laço while que executa até que o número de arestas seja n - 1. Custo: O(n)
    {
        min=999; // Atribuição de um valor fixo a min. Custo: O(1)
       
        for(i=1;i<=n;i++) // Laço for que percorre os vértices. Custo: O(n)
            for(j=1;j<=n;j++) // Laço for interno que percorre os vértices novamente. Custo: O(n^2)
                if(w[i][j]<min) // Verifica se o peso de uma aresta é menor que min. Custo: O(1)
                {
                    min=w[i][j]; // Atualiza min se o peso da aresta for menor. Custo: O(1)
                    u=a=i; // Atualiza os vértices u e a. Custo: O(1)
                    v=b=j; // Atualiza os vértices v e b. Custo: O(1)
                }


        while(visited[u]) // Laço while que percorre a árvore para encontrar o vértice u. Custo: O(n)
            u=visited[u]; // Atualiza u para o próximo vértice visitado. Custo: O(1)
       
        while(visited[v]) // Laço while que percorre a árvore para encontrar o vértice v. Custo: O(n)
            v=visited[v]; // Atualiza v para o próximo vértice visitado. Custo: O(1)
       
        if(u!=v) // Verifica se os vértices u e v são diferentes. Custo: O(1)
        {
            ne++; // Incrementa o número de arestas. Custo: O(1)
            sum+=min; // Soma o peso da aresta mínima. Custo: O(1)
            printf("\nEdge ( %d , %d ) --> %d",a,b,min); // Imprime a aresta mínima. Custo: O(1)
            visited[v]=u; // Atualiza a árvore de visitados. Custo: O(1)
        }
       
        w[a][b]=w[b][a]=999; // Atualiza o peso da aresta removida. Custo: O(1)
    }


    printf("\nCost of minimum spanning tree : %d\n",sum); // Imprime o custo total da árvore. Custo: O(1)
}


int main()
{
    int w[10][10],n,i,j; // Declaração de variáveis inteiras e matriz. Custo: O(1)


    printf("\nProgram to implement Kruskal's Algorithm : \n"); // Imprime uma mensagem. Custo: O(1)
    printf("\nEnter no. of vertices : "); // Imprime uma mensagem. Custo: O(1)
    scanf("%d",&n); // Lê o número de vértices. Custo: O(1)


    printf("\nEnter the adjacency matrix : \n"); // Imprime uma mensagem. Custo: O(1)
    for(i=1;i<=n;i++) // Laço for que percorre os vértices. Custo: O(n)
        for(j=1;j<=n;j++) // Laço for interno que percorre os vértices novamente. Custo: O(n^2)
            scanf("%d",&w[i][j]); // Lê o peso das arestas. Custo: O(1)
   
    for(i=1;i<=n;i++) // Laço for que percorre os vértices. Custo: O(n)
        for(j=1;j<=n;j++) // Laço for interno que percorre os vértices novamente. Custo: O(n^2)
            if(w[i][j]==0) // Verifica se o peso é zero. Custo: O(1)
                w[i][j]=999; // Atualiza o peso para um valor grande. Custo: O(1)


    kruskal(w,n); // Chama a função kruskal(). Custo: O(n^2)
   
    return 0; // Custo: O(1)
}
