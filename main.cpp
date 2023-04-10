#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <time.h>
#define ESC 27
#define ROWS 14
#define COLS 14
#define RAIO 15
#define TAMX 500
#define TAMY 500

struct bola{
	int x;
	int y;
	int raio; 
	int passox;
	int passoy;
	int color;
};

int main() {
	
	int xT = 0;
	int pg = 1, i; 
	char tecla;
	srand(time(NULL));
	bola bolas[4];

	int left = 10;
    int right = TAMX - 10;
    int bottom = TAMY - 10;
	int j = 0;
	int tamanhoGridX = right/ROWS;
    int tamanhoGridY = bottom/COLS;
    
    
    for(i=0; i<=4; i++){
		bolas[i].x = 19 + (rand() % 450);
		bolas[i].y = 19 + (rand() % 450);
		bolas[i].raio = 18; 
		bolas[i].passox = 2;
		bolas[i].passoy = 1;
		bolas[i].color = RGB(rand(),rand(),rand());
	}
	tecla = 0; 

	int grid[ROWS][COLS] = {{1,3,0,0,0,0,1,3,0,0,0,0,1},
                            {2,0,0,0,0,0,0,0,0,0,0,0,2},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,0,1,0,1,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,1,0,0,0,1,0,0,0,1},
                            {2,0,0,0,0,0,0,0,0,0,0,0,2},
                            {0,0,0,0,1,0,1,0,1,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,3,0,0,0,0,1,3,0,0,0,0,1}};


 initwindow(TAMX, TAMY, "ExPgm02", 10, 10);

 while(true) {
 	if (pg == 1) pg = 2; else pg=1; 
 	setactivepage(pg);
 	
 		setbkcolor(RGB(50, 50, 50));
 		cleardevice();
 		
 		setfillstyle(1, RGB(50, 128, 80));
 			
 		
 	  //Desenhos feitos com matriz
    for(i = 0; i < ROWS; i++)
         {
            for(j = 0; j < COLS; j++)
            {
                if(grid[i][j] == 1)
                {
                    fillellipse(j*tamanhoGridX+40, i*tamanhoGridY+40, RAIO, RAIO);

                }
                if(grid[i][j] == 2)
                {
                	rectangle(j*tamanhoGridX+50, i*tamanhoGridY+190, j*tamanhoGridX+30, i*tamanhoGridY+30);
   	
                }
                if(grid[i][j] == 3)
                {
                	rectangle(j*tamanhoGridX+190, i*tamanhoGridY+50, j*tamanhoGridX+30, i*tamanhoGridY+30);
   	
                }
            }
         }
 	//rectangle(60, 230, 20, 60);
 	//rectangle(60, 460, 20, 120);
 	
  	setcolor(RGB(195, 128, 50));
    rectangle(10, 10, TAMX-10, TAMY-10);
    setcolor(RGB(255, 255, 0));
    
    
	for(i=0; i<=4; i++){
	setfillstyle(1, bolas[i].color);
    fillellipse(bolas[i].x, bolas[i].y, bolas[i].raio, bolas[i].raio);
	}

	//fillellipse(a.y, a.x, a.raio, a.raio);

    setvisualpage(pg);


    for(i=0; i<=4; i++){
    	bolas[i].x = bolas[i].x + bolas[i].passox; 
    if (bolas[i].x <= left+bolas[i].raio || bolas[i].x >= 490-bolas[i].raio)
      bolas[i].passox = -bolas[i].passox;

    bolas[i].y = bolas[i].y + bolas[i].passoy;
    if (bolas[i].y <= left+bolas[i].raio || bolas[i].y >= 490-bolas[i].raio)
      bolas[i].passoy = -bolas[i].passoy;
	}

    delay(10);
    

 	if (kbhit())
      tecla = getch();   
  }
 closegraph();

 return 0;
}
