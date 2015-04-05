#include <SDL2/SDL.h>
#include <assert.h>

int main (int argc, char *args[]) {

    /* INITIALIZATION */

	// Tempo total de execução da library
	unsigned int now;

	// Última vez que retângulos se mexeram
	unsigned int r1Then;
	unsigned int r2Then;

	// Movimento dos retângulos
	unsigned int r1Mov = 0;
    unsigned int r2Mov = 0;

	// Parâmetro de loop
	bool running = true;

	// Evento
	SDL_Event e;

	SDL_MouseButtonEvent *me;

    int err = SDL_Init(SDL_INIT_EVERYTHING);
    assert(err == 0);

    SDL_Window *window = SDL_CreateWindow("Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    assert(window != NULL);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    assert(renderer != NULL);

    /* EXECUTION */

	SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderFillRect(renderer, NULL);

    SDL_Rect r1 = { 0, 0, 25, 25 };
    SDL_Rect r2 = { 200, 200, 50, 50 };

	SDL_SetRenderDrawColor(renderer, 0xFF,0x00,0x00,0x00);
    SDL_RenderFillRect(renderer, &r2);

	SDL_SetRenderDrawColor(renderer, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(renderer, &r1);

    SDL_RenderPresent(renderer);

	r1Then = r2Then = SDL_GetTicks();

	// Executa ações até a janela ser fechada
    while(running) {

		SDL_WaitEventTimeout(&e, 100);

		// Tratador de eventos
		switch(e.type) {

			// Tratando click
			case SDL_MOUSEBUTTONDOWN:
				me = (SDL_MouseButtonEvent *) &e;

				if(me->x >= r1.x && me->y >= r1.y && me->x <= r1.x + r1.w && me->y <= r1.y + r1.h)
					r1Mov = -1;
				
				if(me->x >= r2.x && me->y >= r2.y && me->x <= r2.x + r2.w && me->y <= r2.y + r2.h)
					r2Mov = -1;

				break;

			// Tratando saída de janela
			case SDL_QUIT:
				running = false;
				break;
		}

		now = SDL_GetTicks();

		if(now - r1Then > 150 && r1Mov != -1) {
			
			if(r1Mov == 0) {

				r1.x += 5;
				if(r1.x == 50 + 200)
					r1Mov = 1;
			}

			else if(r1Mov == 1) {

				r1.y += 5;
				if(r1.y == 50 + 200)
					r1Mov = 2;
			}
			
			else if(r1Mov == 2) {

				r1.x -= 5;
				if(r1.x == 50)
					r1Mov = 3;
			}
			
			else {

				r1.y -= 5;
				if(r1.y == 50)
					r1Mov = 0;
			}

			r1Then = now;
		}
		
		if(now - r2Then > 50 && r2Mov != -1) {
			
			if(r2Mov == 0) {

				r2.x += 5;
				if(r2.x == 200 + 100)
					r2Mov = 1;
			}

			else if(r2Mov == 1) {

				r2.y += 5;
				if(r2.y == 200 + 100)
					r2Mov = 2;
			}
			
			else if(r2Mov == 2) {

				r2.x -= 5;
				if(r2.x == 200)
					r2Mov = 3;
			}
			
			else {

				r2.y -= 5;
				if(r2.y == 200)
					r2Mov = 0;
			}

			r2Then = now;
		}
		
		SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x00);
		SDL_RenderFillRect(renderer, NULL);

		SDL_SetRenderDrawColor(renderer, 0xFF,0x00,0x00,0x00);
		SDL_RenderFillRect(renderer, &r2);

		SDL_SetRenderDrawColor(renderer, 0x00,0x00,0xFF,0x00);
		SDL_RenderFillRect(renderer, &r1);

	    SDL_RenderPresent(renderer);

	}

    /* FINALIZATION */

    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}