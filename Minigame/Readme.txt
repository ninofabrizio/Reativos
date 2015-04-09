Frogger:

O objetivo é controlar o retângulo verde com as setas do teclado pelo cenário para levar ele até o outro lado sem encostar
nos inimigos (retângulos pretos).

Controles:
- Setas: movimentam o retângulo verde pelo cenário, cada um na sua respectiva direção.
- R: reseta o jogo, colocando todos os retângulos em suas posições de movimento iniciais e o retângulo controlado volta a seu estado original.

Jogo ganho: Atravessar a linha de cima, o retângulo controlado fica azul e o jogo para.

Jogo perdido: Retângulo controlado encosta ou é encostado por inimigo, ele fica vermelho e o jogo para.

---------------

OBS.1: O programa inicialmente foi feito como arquivo .cpp para poder funcionar no VisualStudio (ele relatava inúmeros erros sem sentido ao ser compilado como .c), mas foi totalmente feito em linguagem C logo não deve apresentar problemas tratando ele como tal para executar.

OBS.2: Foi criada uma função para colocar todos os retângulos em sua posição de início (initialPos), mas seu uso resulta no retângulo frog não ser desenhado. Ainda não se descobriu o motivo, a função foi deixada comentada junto às posições onde é chamada dentro da main. Assim, tratei da parte de posicionar tudo conforme o início do jogo na própria main.