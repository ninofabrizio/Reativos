Frogger:

O objetivo � controlar o ret�ngulo verde com as setas do teclado pelo cen�rio para levar ele at� o outro lado sem encostar
nos inimigos (ret�ngulos pretos).

Controles:
- Setas: movimentam o ret�ngulo verde pelo cen�rio, cada um na sua respectiva dire��o.
- R: reseta o jogo, colocando todos os ret�ngulos em suas posi��es de movimento iniciais e o ret�ngulo controlado volta a seu estado original.

Jogo ganho: Atravessar a linha de cima, o ret�ngulo controlado fica azul e o jogo para.

Jogo perdido: Ret�ngulo controlado encosta ou � encostado por inimigo, ele fica vermelho e o jogo para.

---------------

OBS.1: O programa inicialmente foi feito como arquivo .cpp para poder funcionar no VisualStudio (ele relatava in�meros erros sem sentido ao ser compilado como .c), mas foi totalmente feito em linguagem C logo n�o deve apresentar problemas tratando ele como tal para executar.

OBS.2: Foi criada uma fun��o para colocar todos os ret�ngulos em sua posi��o de in�cio (initialPos), mas seu uso resulta no ret�ngulo frog n�o ser desenhado. Ainda n�o se descobriu o motivo, a fun��o foi deixada comentada junto �s posi��es onde � chamada dentro da main. Assim, tratei da parte de posicionar tudo conforme o in�cio do jogo na pr�pria main.