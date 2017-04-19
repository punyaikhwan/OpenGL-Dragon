#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <math.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

typedef struct {
	float x,y;
} point2D_t;

typedef struct {
	float v[3];
} vector2D_t;

typedef struct {
	float m[3][3];
} matrix2D_t;

typedef struct {
	float r,g,b;
} color_t;

void setColor(color_t col){
	//glColor3f(col.r,col.g,col.b);
	glColor3ub(col.r,col.g,col.b);
}

void drawPolygon(point2D_t p[],int n){
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}

void fillPolygon(point2D_t p[], color_t col,int n){
	glBegin(GL_POLYGON);
	setColor(col);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}

static void createCircle(point2D_t p[],float r,int n){
	float a=6.28/n;
	for(int i=0;i<n;i++){
		p[i].x=r*cos(i*a);
		p[i].y=r*sin(i*a);
	}
}

static void createCircle(point2D_t p[], point2D_t p0, float r,int n){
	float a=6.28/n;
	for(int i=0;i<n;i++){
		p[i].x=p0.x+r*cos(i*a);
		p[i].y=p0.y+r*sin(i*a);
	}
}

void gradatePolygon(point2D_t p[],color_t col[],int n){
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++) {
		setColor(col[i]);
		glVertex2f(p[i].x,p[i].y);
	}
	glEnd();
}

void awan(int x, int y, int r) {
    /* mo bikin awan*/
    point2D_t suns[97];
    point2D_t position;

    // lingkaran 1
    position.x = x;//-50;
    position.y = y;//70;
    color_t csuns={ 244, 246, 247 };
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 2
    position.x = x+10;//-40;
    position.y = y+5;//75;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 3
    position.x = x+10;//-30;
    position.y = y;//70;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 4
    position.x = x+30;//-20;
    position.y = y+10;//80;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 5
    position.x = x+40;//-10;
    position.y = y-10;//60;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 6
    position.x = x+55;//5;
    position.y = y;//70;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 7
    position.x = x+15;//-35;
    position.y = y-10;//60;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    //lingkaran 8
    position.x = x+60;//10;
    position.y = y-10;//60;
    createCircle(suns,position,r,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);
}

void tree(int mirror, int kali) {
    // batang
    point2D_t gunung1[7]={{-180,-256},{-175,-206},{-200,-170},{-175,-195},
                        {-160,-180},{-155,-180},{-140,-256}};
    color_t colGunung1[7]={{110, 44, 0},{110, 44, 200},{ 135, 54, 0 },{ 160, 64, 0 },
                    {135, 54, 0}, {135, 54, 0}, {110, 44, 0}
    };
    if (mirror==2) {
        int i;
        for (i=0;i<7;i++) {
            gunung1[i].x *= -1;
        }
    }
    gradatePolygon(gunung1,colGunung1,7);

    /* mo bikin daun*/
    point2D_t suns[97];
    point2D_t position;

    // lingkaran 1
    position.x = -200*kali;//-50;
    position.y = -170;//70;
    color_t csuns={20, 90, 50};
    createCircle(suns,position,40,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    // lingkaran 2
    position.x = -180*kali;//-50;
    position.y = -140;//70;
    createCircle(suns,position,45,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    // lingkaran 3
    position.x = -150*kali;//-50;
    position.y = -170;//70;
    createCircle(suns,position,30,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    // lingkaran 4
    position.x = -130*kali;//-50;
    position.y = -160;//70;
    createCircle(suns,position,35,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);

    // lingkaran 5
    position.x = -150*kali;//-50;
    position.y = -170;//70;
    createCircle(suns,position,45,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);
}

static void createShine(point2D_t p[],float r,int n){
 float a=6.28/n;
 for(int i=0;i<n;i++){
        if (i%2==0){
            p[i].x=r*cos(i*a);
            p[i].y=r*sin(i*a);
        } else {
            p[i].x=0.9*r*cos(i*a);
            p[i].y=0.9*r*sin(i*a);
        }
 }
}

void shine(int mirrorX, int mirrorY) {
    point2D_t gunung1[4]={{0,0},{-256*mirrorY,10*mirrorX},{-256*mirrorY,40*mirrorX}};
    color_t colGunung1[4]={{ 174, 214, 241 },{133, 193, 233},
                { 214, 234, 248 }};
    gradatePolygon(gunung1,colGunung1,3);

    for(int i=0;i<4;i++) {
        if (mirrorX==1) {
            gunung1[1].y += 50;
            gunung1[2].y += 50;// + (i*10);
        } else {
            gunung1[1].y -= 50;
            gunung1[2].y -= 50;// + (i*10);
        }
        gradatePolygon(gunung1,colGunung1,3);
    }

    point2D_t gunung2[4]={{0,0},{-10*mirrorY,256*mirrorX},{-40*mirrorY,256*mirrorX}};
    gradatePolygon(gunung2,colGunung1,3);

    for(int i=0;i<4;i++) {
        if (mirrorY==1) {
            gunung2[1].x -= 50;
            gunung2[2].x -= 50 ;
        } else {
            gunung2[1].x += 50;
            gunung2[2].x += 50 ;
        }
        gradatePolygon(gunung2,colGunung1,3);
    }
}

void userdraw() {
    int numSegments;
    // membuat langit
    point2D_t kotak[4]={{-256,256},{256,256},{256,-256},{-256,-256}};
	color_t col[4]={{133, 193, 233},{ 52, 152, 219 },{ 40, 116, 166 },{ 52, 152, 219 }};
	gradatePolygon(kotak,col,4);

	// bikin shine
	shine(1,1);
    shine(1,-1);
    shine(-1,1);
    shine(-1,-1);

    // matahari
    point2D_t suns[97];
    point2D_t suns2[97];
    color_t csuns={241, 196, 15};
    color_t csuns2={ 192, 57, 43 };
    //setColor(0,0,0);
    createShine(suns2,110,97);
    createCircle(suns,97,90);

    drawPolygon(suns,90);
    drawPolygon(suns2,90);
    fillPolygon(suns2,csuns2,90);
    fillPolygon(suns,csuns,90);




   // Membuat bukit 1 kanan
    point2D_t gunung1[4]={{-100,-256},{130,-120},{256,-230},{256,-256}};
    color_t colGunung1[4]={{39, 174, 96},{35, 155, 86},{25, 111, 61},{35,155,86}};
    gradatePolygon(gunung1,colGunung1,4);

    // Membuat bukit 2 kiri
    point2D_t gunung2[3]={{-256,-256},{-120,-120},{20,-256}};
    color_t colGunung2[3]={{39, 174, 96},{35, 155, 86},{25, 111, 61}};
    gradatePolygon(gunung2,colGunung2,3);

    // Membuat bukit 3 kiri
    point2D_t gunung3[4]={{-120,-256},{100,-160},{130,-156},{256,-256}};
    color_t colGunung3[4]={{ 40, 180, 99 },{35, 155, 86},{ 40, 180, 99 },{35,255,86}};
    gradatePolygon(gunung3,colGunung3,4);

    //bikin awan 1
    awan(-50,70,15);

    //bikin awan 2
    awan(-200,120,18);

    //bikin awan 3
    awan(200,70,20);
    awan(160,70,15);

    //bikin awan 4
    awan(40,-40,21);

    // bikin pohon kiri
    tree(1,1);
    tree(2,-1);


}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
}

int main ( int argc, char** argv )
{

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    SDL_Surface* screen = SDL_SetVideoMode(512, 512, 16, SDL_OPENGL);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    glClearColor(0,0,0,0);
    gluOrtho2D(-256,256,-256,256);

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // DRAWING ENDS HERE
        display();
        SDL_GL_SwapBuffers( );
        // finally, update the screen :)
       // SDL_Flip(screen);
    } // end main loop


    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
