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

void gradatePolygon(point2D_t p[],color_t col[],int n){
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++) {
		setColor(col[i]);
		glVertex2f(p[i].x,p[i].y);
	}
	glEnd();
}

void userdraw() {
    // membuat langit
    point2D_t kotak[4]={{-256,256},{256,256},{256,-256},{-256,-256}};
	color_t col[4]={{133, 193, 233},{ 52, 152, 219 },{ 40, 116, 166 },{ 52, 152, 219 }};
	gradatePolygon(kotak,col,4);
/*
   // matahari
    point2D_t suns[97];
    color_t csuns={0.7,0.5,0};
    //setColor(0,0,0);
    createCircle(suns,97,90);
    drawPolygon(suns,90);
    fillPolygon(suns,csuns,90);*/
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
