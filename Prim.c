#define Graph Digraph
/* Recebe um grafo conexo G com custos arbitrários nas arestas e calcula uma MST de G. A função armazena a MST no vetor parent, tratando-a como uma árvore radicada com raiz 0. /
/ O grafo G e os custos são representados por listas de adjacência. A função supõe que a constante INFINITO é maior que o custo de qualquer aresta. Supõe também que o grafo tem no máximo maxV vértices. O código é uma versão melhorada do Programa 20.3 de Sedgewick. */

void GRAPHmstP1( Graph G, Vertex parent[]) 
{ 
  Vertex v0, w, frj[maxV]; link a; 
  double price[maxV], c;
  for (w = 0; w < G->V; w++) 
  parent[w] = -1, price[w] = INFINITO; 
  // Custo: O(V) onde V é o número de vértices no grafo

  v0 = 0;
  parent[v0] = v0;
    for (a = G->adj[v0]; a != NULL; a = a->next) {
      price[a->w] = a->cost; 
      frj[a->w] = v0; 
     } 
     //Custo: O(E_0), onde E_0 é o número de arestas adjacentes ao vértice v0.

    while (1) { 
      double minprice = INFINITO; 
        for (w = 0; w < G->V; w++) 
           if (parent[w] == -1 && minprice > price[w]) 
              minprice = price[v0=w]; 
               // Custo: O(V)
           if (minprice == INFINITO) break;
              parent[v0] = frj[v0]; 
          for (a = G->adj[v0]; a != NULL; a = a->next) {
              w = a->w, c = a->cost;
          if (parent[w] == -1 && price[w] > c) {
            price[w] = c; 
            frj[w] = v0; 
          }
       }
       // Custo: O(E_v0), onde E_v0 é o número de arestas adjacentes ao vértice v0 (G->adj[v0])
    }

    //O laço while continua até que todos os vértices sejam incluídos na MST.
    //Em cada iteração, o algoritmo percorre todos os vértices para encontrar o vértice com o menor preço que ainda não está na MST (for (w = 0; w < G->V; w++)).
    //Custo: O(V) por iteração.
    //Em cada iteração, o algoritmo atualiza os preços das arestas adjacentes ao novo vértice adicionado à MST (for (a = G->adj[v0]; a != NULL; a = a->next)).
    //Custo: O(E_v0) por iteração, onde E_v0 é o número de arestas adjacentes ao vértice v0.

}