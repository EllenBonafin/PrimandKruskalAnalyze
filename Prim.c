#define Graph Digraph // Custo: O(1) - Esta é uma operação de substituição de texto e não tem impacto no tempo de execução do algoritmo.


void GRAPHmstP1( Graph G, Vertex parent[]){   // Custo: O(1) - Declaração de uma função, custo constante.


   Vertex v0, w, frj[maxV]; link a;  // Custo: O(1) - Declaração de variáveis, custo constante.
   double price[maxV], c; // Custo: O(1) - Declaração de variáveis, custo constante.


   for (w = 0; w < G->V; w++){  // Custo: O(V) - Este loop executa V vezes, onde V é o número de vértices no grafo.
     
      parent[w] = -1, price[w] = INFINITO; // Custo: O(V) - Para cada vértice no grafo, atribui um valor a dois arrays (parent e price).
      v0 = 0; // Custo: O(1) - Atribuição de valor fixo à variável.
      parent[v0] = v0; // Custo: O(1) - Atribuição de valor fixo à variável.


      for (a = G->adj[v0]; a != NULL; a = a->next) { // Custo: O(E_0) - Este loop executa uma vez para cada aresta adjacente ao vértice v0, onde E_0 é o número de arestas adjacentes ao vértice v0.


         price[a->w] = a->cost; // Custo: O(E_0) - Atribui um valor a um array para cada aresta adjacente ao vértice v0.
         frj[a->w] = v0; // Custo: O(E_0) - Atribui um valor a um array para cada aresta adjacente ao vértice v0.
      }


      while (1) { // Custo: Não pode ser determinado diretamente, pois depende do número de iterações. Pode ser tratado como O(1) se o número de iterações for limitado.
         double minprice = INFINITO; // Custo: O(1) - Atribuição de valor fixo à variável.
         for (w = 0; w < G->V; w++){  // Custo: O(V) - Este loop executa V vezes, onde V é o número de vértices no grafo.


            if (parent[w] == -1 && minprice > price[w]) // Custo: O(V) - Cada condição dentro do loop é verificada uma vez para cada vértice.
               minprice = price[v0=w]; // Custo: O(V) - Esta linha é executada uma vez para cada vértice no pior caso.


            if (minprice == INFINITO) break; // Custo: O(1) - Condição de saída do loop.
               parent[v0] = frj[v0]; // Custo: O(1) - Atribuição de valor fixo à variável.


            for (a = G->adj[v0]; a != NULL; a = a->next) { // Custo: O(E_v0) - Este loop executa uma vez para cada aresta adjacente ao vértice v0, onde E_v0 é o número de arestas adjacentes ao vértice v0.
               w = a->w, c = a->cost; // Custo: O(E_v0) - Atribui um valor a duas variáveis para cada aresta adjacente ao vértice v0.


            if (parent[w] == -1 && price[w] > c) { // Custo: O(E_v0) - Cada condição dentro do loop é verificada uma vez para cada aresta adjacente ao vértice v0.
               price[w] = c; // Custo: O(E_v0) - Esta linha é executada uma vez para cada aresta adjacente ao vértice v0 no pior caso.
               frj[w] = v0; // Custo: O(E_v0) - Esta linha é executada uma vez para cada aresta adjacente ao vértice v0 no pior caso.
         }
      }
    }
}
