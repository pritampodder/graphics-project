#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    initwindow(500,500);
    int r;
    const int x=getmaxx()/2;		// defining x-axis of center
    const int y=getmaxy()/2;		// defining y-axis of center
    
    outtextxy(10, 20, "Enlarging Circle");	//mesage
    for(r=20;r<160;r++)					// from 20 so 1st circle should visible, 160, since color limit is 0 to 15, 159/10=15
    {             
        delay(100);				// made some animation
    	setcolor(r/10);			// creating different colours
     	circle(x,y,r);     		// drawing circles
    }
    	    
	setcolor(BLACK);			
    outtextxy(10, 20, "Enlarging Circle");	// erasing message with black color
    setcolor(WHITE);						
    outtextxy(10, 20, "Waiting...");		//message
    char s[2];								// counter init
    s[1]='\0';
    for(int i=57;i>=48;i--){    			// count don
    	s[0]=i;
    	setcolor(14);
    	outtextxy(95, 20,s);    		
    	delay(300);
    	setcolor(BLACK);
    	outtextxy(105,20,s);    	
	}
	setcolor(BLACK);
    outtextxy(10, 20, "Waiting...");			// erasing
       
    setcolor(11);
    outtextxy(10,20, "Reducing Circle");		// message
    setcolor(BLACK);							// erasing circles
    for(r=160;r>=20;r--)
    {             
     delay(100);          
     circle(x,y,r);     	
    }
    setcolor(11);						
    outtextxy(10,20, "Press any key to exit...");		// message
    
    while(!kbhit());        					//waiting
 	return 0;   					//out
}    


