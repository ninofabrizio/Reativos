#include <SDL2/SDL.h>
#include <assert.h>

#define NUMMINIONS 3

// Desenha tudo
void drawAll (SDL_Renderer *renderer, SDL_Rect frog, SDL_Rect *enem, int mov) {

	SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderFillRect(renderer, NULL);

	SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0x00);
	SDL_RenderDrawLine(renderer, 0, 408, 640, 408);
	SDL_RenderDrawLine(renderer, 0, 68, 640, 68);

	for(int i = 0; i < NUMMINIONS; i++)
		SDL_RenderFillRect(renderer, &enem[i]);

	if(mov == 0)
		SDL_SetRenderDrawColor(renderer, 0x00,0xFF,0x00,0x00);
	else if(mov == -1)
		SDL_SetRenderDrawColor(renderer, 0xFF,0x00,0x00,0x00);
	else
		SDL_SetRenderDrawColor(renderer, 0x00,0x00,0xFF,0x00);

	SDL_RenderFillRect(renderer, &frog);

    SDL_RenderPresent(renderer);

}

// Vê se sapo tocou/foi tocado por inimigo
int verifyDeath (SDL_Rect frog, SDL_Rect *enem) {

	for(int i = 0; i < NUMMINIONS; i++)
		if(frog.y > enem[i].y && (frog.y + frog.h < enem[i].y + enem[i].h))
			if((frog.x <= enem[i].x && enem[i].x <= frog.x + frog.w) || 
			   (frog.x >= enem[i].x && frog.x + frog.w <= enem[i].x + enem[i].w) || 
			   (frog.x <= enem[i].x + enem[i].w && enem[i].x + enem[i].w <= frog.x + frog.w))
				return -1;
	return 0;
}

int main (int argc, char *args[]) {

    /* INITIALIZATION */

	// Tempo total de execução da library
	unsigned int now;

	// Última vez que inimigos se mexeram
	unsigned int enemThen[NUMMINIONS];

	// Movimento do sapo
	unsigned int frogMov = 0;

	// Parâmetro de loop
	bool running = true;

	// Eventos
	SDL_Event e;
	SDL_KeyboardEvent *ke;

    int i, err = SDL_Init(SDL_INIT_EVERYTHING);
    assert(err == 0);

    SDL_Window *window = SDL_CreateWindow("F R O G G E R", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 476, SDL_WINDOW_SHOWN);
    assert(window != NULL);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    assert(renderer != NULL);

    /* EXECUTION */

    SDL_Rect frog = { 333, 429, 26, 26 };

	SDL_Rect enem[NUMMINIONS];
	for(i = 0; i < NUMMINIONS; i++) {
		enem[i].h = 60;
		enem[i].w = 100;
		enem[i].x = 0;
		enem[i].y = 344 - (68 * 2 * i);
	}

	drawAll(renderer, frog, enem, frogMov);

	enemThen[0] = SDL_GetTicks();
	for(i = 1; i < NUMMINIONS; i++)
		enemThen[i] = enemThen[i-1];

	// Executa ações até a janela ser fechada
    while(running) {

		SDL_WaitEventTimeout(&e, 50);

		// Tratador de eventos
		switch(e.type) {

			// Tratando botão apertado
			case SDL_KEYDOWN:
				ke = (SDL_KeyboardEvent *) &e;

				switch(ke->keysym.sym){
                    case SDLK_LEFT:
						if(frog.x - 32 > 0 && frogMov == 0) {
							frog.x -= 32;
							frogMov = verifyDeath(frog, enem);
						}
                        break;
                    case SDLK_RIGHT:
						if(frog.x + 32 + frog.w < 640 && frogMov == 0) {
							frog.x += 32;
							frogMov = verifyDeath(frog, enem);
						}
                        break;
                    case SDLK_UP:
						if(frog.y - 68 > 0 && frogMov == 0) {
							frog.y -= 68;
							frogMov = verifyDeath(frog, enem);
							if(frog.y <= 68)
								frogMov = 1;
						}
                        break;
                    case SDLK_DOWN:
						if(frog.y + 68 + frog.h < 476 && frogMov == 0) {
							frog.y += 68;
							frogMov = verifyDeath(frog, enem);
						}
                        break;
                    default:
                        break;
				}
				break;

			// Tratando saída de janela
			case SDL_QUIT:
				running = false;
				break;
		}

		now = SDL_GetTicks();

		for(i = 0; i < NUMMINIONS; i++) {

			if(now - enemThen[i] > (100 - (25 * i)) && frogMov == 0) {

				enem[i].x += 1 + (6 * i);
				if(enem[i].x + enem[i].w > 640)
					enem[i].x = 0;

				frogMov = verifyDeath(frog, enem);

				enemThen[i] = now;
			}
		}

		drawAll(renderer, frog, enem, frogMov);
	}

    /* FINALIZATION */

    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}