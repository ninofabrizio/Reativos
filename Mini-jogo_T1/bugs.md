# Bugs
1 - Inimigos que acabam de ser criados assim que jogador passa da linha de chegada continuam se movimentando e isso permite que outros sejam criados quando estes passam do limite da tela. Aparentemente só vale quando jogador ganha o jogo, não quando colide com alguém.
------------------
Corregidos:
1 - Fiz um par/or contendo a criação de inimigos e o await do evento winner, assim o inimigo que apareceria após o jogador cruzar a linha de chegada não chega a ser criado. Fiz um par/and paralelo a esse contendo o tratador de colisão para não fazer com que o jogo perca a instância atual no par/or interno. O restart é dado quando ocorrer o click de mouse no par/or englobando tudo isso.