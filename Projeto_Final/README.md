#Projeto Final

## *Objetivo*

Usar um mix de concorrência síncrona/assíncrona com Path finding na linguagem Céu.
Inicialmente, era planejado usar um algoritmo em A* (A Star) para calcular o melhor percurso dentro de um mapa, mas acabei usando outro algoritmo que calcula todos os caminhos possíveis no mapa usando como lógica o BFS (Breadth-First Search).

## *O que foi usado/ Como funciona*

O CiB (Céu in a Box), versão 0.8, para compilar os arquivos na linguagem Céu e na linguagem C.

Algoritmo em linguagem C que calcula todos os percursos possíveis dentro de um mapa, seguindo a sequinte lógica:
- Em um mapa contendo os valores XX, XY, YX e YY, se quer calcular todos os percursos possíveis partindo da posição mapa[0][0].
- Só se pode andar entre casas que contenham uma letra X ou Y na mesma posição (ie, XX->XY pode, mas XY->YX não).
- É permitido "pular" uma casa vertical ou horizontalmente para ir a outra, obedecendo a regra acima.
- Não é permitido repetir casas previamente visitadas.

Mando o endereço de um vetor para a função principal do algoritmo para este preencher o vetor com os índices de cada casa "andada" em todos os caminhos descobertos.

Um arquivo com código em linguagem Céu se encarrega de chamar o algoritmo e traduzir as informações do vetor em um "percurso" que será feito por um retângulo desenhado usando SDL.

Um outro retângulo é desenhado (também usando SDL), representando um "pisca pisca" para simular a concorrência com o retângulo que vai percorrendo um mapa.

## *Problema*

Conforme o cálculo do mapa feito no algoritmo em C for demorando devido ao mapa ficar mais complexo, a mudança de cor do retângulo que "pisca" iria demorar mais.
Isto mostra que apesar de ambas as operações de percurso e de piscar serem paralelas, uma acaba dependendo que a outra termine sua execução.

## *Solução*

Fazer uso do bloco async da linguagem Céu para executar em uma thread separada a operação de cálculo feita ao chamar a função para determinar caminhos no mapa.
Possibilitando que o bloco que muda a cor do retângulo que pisca possa executar normalmente, mesmo o bloco paralelo a ela estar demorando.

## *Como executar*

Bastaria compilar o arquivo part1.ceu e rodar o executável gerado para o programa principal funcionar.
Porém, existe um problema no código que não pôde ser resolvido ao tentar se chamar a função nativa para se comunicar com a função contendo o algoritmo em C. Não achei uma solução sem comprometer muito o prazo de entrega do projeto.
Como referência, o erro é apontado na linha 74 do código. O resto do código foi testado e parece estar funcional.

## *Observações*

Optei por este algoritmo devido a que a maioria dos algoritmos confiáveis que encontrei, e que abosdassem o A*, eram feitos em C++ ou Java.
Tinha encontrado 2 algoritmos aparentemente bons em C, mas se tornaram um pouco mais complexos de entender para adaptar e usar, podendo me complicar mais no tempo disponível para realizar o projeto.
O algoritmo foi testado com main.c separadamente e funciona. Ele sofreu algumas alterações por mim para poder encaixar melhor na minha proposta.
Para complicar o cálculo do mapa, planejava aumentar a estrutura dentro do código em C que define o mapa para aumentar a quantidade de caminhos e alternativas para o algoritmo.
Foi deixado o part1.exe para mostrar como ficaria a interface principal do projeto.
