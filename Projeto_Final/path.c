#include "path.h"

typedef struct data {

  const char *element;
  int  visited;

} Data;

Data Board[3][3] = {
	{{ "XY", 0 }, { "YX", 0 },{ "XX", 0 }},
	{{ "XX", 0 }, { "YY", 0 },{ "XY", 0 }},
	{{ "YX", 0 }, { "XY", 0 },{ "XX", 0 }}
};

int *Path;
int *paths;
int Size;
int PathLen;

void sendInfos(int *p, int *pts, int size, int pathlen) {

	Path = p;
	Size = size;
	PathLen = pathlen;
	paths = pts;

	Board[0][0].visited = 1;
}

Data * pos(int *x, int *y, int Size, Data Board[][3]){

    if(*x < 0)     *x += Size;
    if(*x >= Size) *x -= Size;
    if(*y < 0)     *y += Size;
    if(*y >= Size) *y -= Size;

    return &Board[*y][*x];
}

//subroutine
//origin(x,y) -> neighbor(wx,wy)
void neighbor(int x, int y, int wx, int wy, int level){

    Data *wk;
    wk = pos(&wx, &wy, Size, Board);

    if(wk->visited == 0 && (Board[y][x].element[0] == Board[wy][wx].element[0] || Board[y][x].element[1] == Board[wy][wx].element[1])){

        wk->visited = 1;
        search_path(wx, wy, level + 1);
        wk->visited = 0;
    }
}

void search_path(int x, int y, int level){

    Path[level] = Size * y + x;
	
    if(level == PathLen - 1){

        int i, j = 0;

		while(paths[j] != -1)
			j = j + 18;

        for(i = 0 ; i < PathLen; ++i, j = j + 2){

            int x = Path[i] % Size;
            int y = Path[i] / Size;

			paths[j] = y;
			paths[j+1] = x;
        }
    }
	else {

        neighbor(x, y, x - 1, y, level);//origin -> left
        neighbor(x, y, x + 1, y, level);//origin -> right
        neighbor(x, y, x, y - 1, level);//origin -> up
        neighbor(x, y, x, y + 1, level);//origin -> down
    }
}