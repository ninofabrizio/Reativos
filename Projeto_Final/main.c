# include "path.h"
#include <stdio.h>

#define size 3
#define NUM 1000
#define pathlen (size * size)

int main(void){

    int i, x = 0, y = 0, level = 0;

	int Path[pathlen]; // temporário, representa casas de cada caminho possível
	int paths[NUM]; // vetor com todos os caminhos, cada par de casas deste vetor representa os índices do mapa

	for(i = 0; i < NUM; i++)
		paths[i] = -1;

	sendInfos(Path, paths, size, pathlen);
    search_path(x, y, level);

	for(i = 0; i < NUM; i = i + 2) {

		if(paths[i] == -1)
			break;
		else if(i != 0 && i%16 == 0)
			printf("%d %d\n", paths[i], paths[i+1]);
        else
            printf("%d %d->", paths[i], paths[i+1]);
	}

	printf("\n");

    return 0;
}