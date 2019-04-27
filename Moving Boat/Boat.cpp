#include<graphics.h>				// for various graphics related functions

#define GETMAXX 1000				// screen max x axis (top left=0 to top right=1000)
#define GETMAXY 500					// screen max x axis (top left=0 to bottom left=500)

int stars[101][2];					// saving co-ordinates(x,y) of 101 stars
int ctr=1;							// used to flip dimness/brightness of stars

void drawStars()					// method to draw Stars
{
	int x,y, color;					
	
	for(int i=0;i<=100;i++){		// for each of 101 stars
  		if(ctr%2==0)
	  		color=(i%2==0)?7:8;		// if previous color of stars is grey then now white else grey
	  	else
	  		color=(i%2==0)?8:7;		  	
  		
  		x=stars[i][0];				// x-co ordinate of star's saved middle point
  		y=stars[i][1];				// y-co ordinate of star's saved middle point
  		
  		/*	generating surrounding points, a stars made of 7 points	*/
  		putpixel(x, y,color);		// middle point
		putpixel(x-1,y,color);		//instant left of middle
		putpixel(x+1,y,color);		//instant right of middle
		putpixel(x,y-1,color);		//instant up of middle
		putpixel(x,y+1,color);		//instant down of middle
		
		putpixel(x-2,y,color);		//next left of middle
		putpixel(x+2,y,color);		//next left of middle
		putpixel(x,y-2,color);		//next left of middle
		putpixel(x,y+2,color);		//next left of middle							
	  }
	  
	  ctr=(ctr+1)%100;
}

void bFill(int x, int y)				// boundry fill function, will needed for moon
{
    if( getpixel(x,y)!=WHITE ){			// we have boundry of moon as white
        
        putpixel(x,y,WHITE);			// filling moon from white color
  
        bFill(x-1, y);                	//left
        
        bFill(x, y-1);                	//up
        
        bFill(x, y+1);                	//down
        
        bFill(x+1, y);                	//right
    }
}


void drawWaterAndMoon()
{	
										// drawing moon	
	arc(428,198,81,279,50);
  	arc(447,198,103,257,50);
  	
  	bFill(389,200);						// filling color of moon  	
										// drawing sea/river 
	setcolor(LIGHTBLUE);    
    setlinestyle(SOLID_LINE, 1, 1);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    rectangle(0, getmaxy() / 2 + 156, getmaxx(), getmaxy());
    floodfill(getmaxx() - 10, getmaxy() - 10, LIGHTBLUE);	
}

void drawBoatAndStars(int x, int y, int manColor, int boatColor){
										/* drawing boat */
    setlinestyle(SOLID_LINE, 1, 1);
    setcolor(boatColor);
    setfillstyle(SOLID_FILL, boatColor);
    sector(x, y, 180, 360, 50, 10);

    									/* body and leg of stic man */
    setcolor(manColor);
    setlinestyle(SOLID_LINE, 1, 3);
    line(x + 40, y - 15, x + 40, y - 40);
    line(x + 40, y - 15, x + 45, y - 10);
    line(x + 45, y - 10, x + 45, y);
    line(x + 40, y - 15, x + 37, y);
    
    									/* head, hands of stick man */
    circle(x + 40, y - 45, 5);
    line(x + 40, y - 35, x + 52, y - 30);
    line(x + 40, y - 35, x + 37, y - 32);
    line(x + 37, y - 32, x + 49, y - 25);
    line(x + 60, y - 45, x + 27, y + 10);	
    
    if(manColor!=BLACK)					// Black color will used to hide previous drawn boat and boat, so drawing stars is unnecessary
    	drawStars();
}

int main()
{
	initwindow(GETMAXX,GETMAXY);	
	
	int x, y;
	
	srand(-11);							// Seed of random numbers, used to decide co-ordinates of stars
	 
	for(int i=0; i<=100; i++) 					// giving stars their positions
    {									
		x=rand()%getmaxx();
	  	y=rand()%getmaxy()-getmaxy() / 2 + 140;		// extra calculation to ensure that stars never fall in river

	  	stars[i][0]=x;
	  	stars[i][1]=y;
	}
	  	
	x=50, y=GETMAXY/2+ 140 ;					// to show complete boat initially, x= boat width, y to make boat touched with river
	
	drawWaterAndMoon();							// drawing water and moon
	
	while(x<GETMAXX )							//giving the water, a current on layer
		drawBoatAndStars(x+=15,y,BLACK,BLACK );	
	
	x=50;
	
	while(x<GETMAXX-70)
    {					//let the boat approach the right bank
    	drawBoatAndStars(x,y,BLACK,BLACK);				// erasing drawn boat
		drawBoatAndStars(x+=6,y,DARKGRAY,BROWN);		// drawing boat
		delay(50);										// waiting for 50ms		
	}
	delay(1000);						//let the boat rest for 400ms
	
	while(x>50)
    {						//get the boat back to left bank
    	drawBoatAndStars(x,y,BLACK,BLACK);				// erasing drawn boat
		drawBoatAndStars(x-=6,y,DARKGRAY,BROWN);		// drawing boat
		delay(50);										// waiting for 50ms
	}
        /* deallocate memory allocated for graphic screen */
        getch();
        closegraph();
	return 0;
}
