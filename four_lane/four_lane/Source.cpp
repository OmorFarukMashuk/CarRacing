#include <stdio.h>
#include <GL/glut.h>
float x=0, y=0;
float x11 = 30; 
float y11 = 600; 

float x22 = 300;
float y22 = 900;

float x33 = -240;
float y33 =900; 

float x44 = 570;
float y44 = 600; 
int score;
bool collision= false;

float h=0;
float m=0.5;
float n=0.6;
float o=0.7;

void drawcar(float p, float q){
	
	glPointSize(4.0);
 
    glBegin(GL_POLYGON);// main body
    glColor3f(.6, 0, 0);
    glVertex2f(330+p+4, 70+q-60+6 );
    glVertex2f(330+p, 70+q-60+30 );
    glVertex2f(330+p, 70+q-60+110 );
    glVertex2f(330+p+2, 70+q-60+160 );
    glVertex2f(330+p+30, 70+q-60+166 );
    glVertex2f(330+p+60, 70+q-60+160 );
    glVertex2f(330+p+60, 70+q-60+110 );
    glVertex2f(330+p+60, 70+q-60+30 );
    glVertex2f(330+p+56, 70+q-60+6 );
    glVertex2f(330+p+30, 70+q-60+2 );
    glEnd();
 
    glBegin(GL_POLYGON);// back
     
    //glColor3f(0.42, .45, .5);
    glColor3f(.6, 0, 0);
    glVertex2f(330+p+6, 70+q-60+10 );
    glColor3f(.4, 0, 0);
    glVertex2f(330+p+4, 70+q-60+16 );
    glVertex2f(330+p+4, 70+q-60+30 );
    glVertex2f(330+p+10, 70+q-60+26 );
    glColor3f(.2, 0, 0);
    glVertex2f(330+p+20, 70+q-60+24 );
    glVertex2f(330+p+40, 70+q-60+24 );
    glVertex2f(330+p+50, 70+q-60+26 );
    glColor3f(.2, 0, 0);
    glVertex2f(330+p+56, 70+q-60+30 );
    glVertex2f(330+p+56, 70+q-60+16 );
    glVertex2f(330+p+54, 70+q-60+10 );
    glVertex2f(330+p+30, 70+q-60+8 );
    glEnd();
 
    glBegin(GL_POLYGON);// back wind
     
    glColor3f(0, 0.2, .4);
    //glColor3f(0.878, .878, .878);
    glVertex2f(330+p+4, 70+q-60+36 );
    glVertex2f(330+p+10, 70+q-60+50 );
    glVertex2f(330+p+50, 70+q-60+50 );
    glVertex2f(330+p+56, 70+q-60+36 );
    glVertex2f(330+p+40, 70+q-60+32 );
    glVertex2f(330+p+20, 70+q-60+32);
    glEnd();
 
    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, .4); // left glass 1
    glVertex2f(330+p+2, 70+q-60+82 );
    glVertex2f(330+p+2, 70+q-60+110 );
    glVertex2f(330+p+8, 70+q-60+104 );
    glVertex2f(330+p+8, 70+q-60 +82);
    glEnd();
     
     
    glBegin(GL_POLYGON);// left glass 2
     
    glColor3f(0, 0.2, .4);
    glVertex2f(330+p+2, 70+q-60+50 );
    glVertex2f(330+p+2, 70+q-60+78 );
    glVertex2f(330+p+8, 70+q-60+78 );
    glVertex2f(330+p+8, 70+q-60+56 );
        glEnd();
 
     
 
    glBegin(GL_POLYGON); //front glass
    glColor3f(0, 0.2, .4);
    glVertex2f(330+p+10,70+q+106-60);
    glVertex2f(330+p+4,70+q+120-60);
    glVertex2f(330+p+10,70+q+124-60);
    glVertex2f(330+p+30,70+q+128-60);
    glVertex2f(330+p+50,70+q+124-60);
    glVertex2f(330+p+56,70+q+120-60);
    glVertex2f(330+p+50,70+q+106-60);
    glVertex2f(330+p+44,70+q+108-60);
    glVertex2f(330+p+30,70+q+110-60);
    glVertex2f(330+p+16,70+q+108-60);
    glEnd();
 
     
    glBegin(GL_POLYGON); //right glass 2
    glColor3f(0, 0.2, .4);
    glVertex2f(330+p+52,70+q+82-60);
    glVertex2f(330+p+52,70+q+104-60);
    glVertex2f(330+p+58,70+q+110-60);
    glVertex2f(330+p+58,70+q+82-60);
    glEnd();
     
    glBegin(GL_POLYGON); //right glass 1
    glColor3f(0, 0.2, .4);
    glVertex2f(330+p+52,70+q+56-60);
    glVertex2f(330+p+52,70+q+78-60);
    glVertex2f(330+p+58,70+q+78-60);
    glVertex2f(330+p+58,70+q+50-60);
    glEnd();
 
    glBegin(GL_POLYGON); //bonet
    glColor3f(.8, 0, 0);
    glVertex2f(330+p+4,70+q+120-60);
    glVertex2f(330+p+10,70+q+124-60);
    glVertex2f(330+p+30,70+q+128-60);
    glVertex2f(330+p+50,70+q+124-60);
    glVertex2f(330+p+56,70+q+120-60);
    glVertex2f(330+p+54,70+q+158-60);
    glVertex2f(330+p+30,70+q+162-60);
    glVertex2f(330+p+10,70+q+158-60);
    glEnd();
     
    glBegin(GL_POLYGON);//bonet line
    glColor3f(0.5, 0, 0);
    glVertex2f(330+p+10,70+q+124-60);
    //glColor3f(.6, 0, 0);
    glVertex2f(330+p+20,70+q+160-60);
    glColor3f(.4, 0, 0);
    glVertex2f(330+p+30,70+q+162-60);
    glColor3f(.2, 0, 0);
    glVertex2f(330+p+40,70+q+160-60);
    glColor3f(0, 0, 0);
    glVertex2f(330+p+50,70+q+124-60);
    //glColor3f(.1, 0, 0);
    glVertex2f(330+p+30,70+q+128-60);
 
    glEnd();
 
	glFlush();
 

}


void drawpccar(float p, float q){


	glPointSize(4.0);
	
    glBegin(GL_POLYGON);// main body
    glColor3f(0, 1, 1);
    glVertex2f(300+p+4, 70+q-60+6 );
    glVertex2f(300+p, 70+q-60+30 );
    glVertex2f(300+p, 70+q-60+110 );
    glVertex2f(300+p+2, 70+q-60+160 );
    glVertex2f(300+p+30, 70+q-60+166 );
    glVertex2f(300+p+60, 70+q-60+160 );
    glVertex2f(300+p+60, 70+q-60+110 );
    glVertex2f(300+p+60, 70+q-60+30 );
    glVertex2f(300+p+56, 70+q-60+6 );
    glVertex2f(300+p+30, 70+q-60+2 );
    glEnd();
 
    glBegin(GL_POLYGON);// back
     
    //glColor3f(0.42, .45, .5);
    glColor3f(.6, 0, 0);
    glVertex2f(300+p+6, 70+q-60+10 );
    glColor3f(.4, 0, 0);
    glVertex2f(300+p+4, 70+q-60+16 );
    glVertex2f(300+p+4, 70+q-60+30 );
    glVertex2f(300+p+10, 70+q-60+26 );
    glColor3f(.2, 0, 0);
    glVertex2f(300+p+20, 70+q-60+24 );
    glVertex2f(300+p+40, 70+q-60+24 );
    glVertex2f(300+p+50, 70+q-60+26 );
    glColor3f(.2, 0, 0);
    glVertex2f(300+p+56, 70+q-60+30 );
    glVertex2f(300+p+56, 70+q-60+16 );
    glVertex2f(300+p+54, 70+q-60+10 );
    glVertex2f(300+p+30, 70+q-60+8 );
    glEnd();
 
    glBegin(GL_POLYGON);// back wind
     
    glColor3f(0, 0.2, .4);
    //glColor3f(0.878, .878, .878);
    glVertex2f(300+p+4, 70+q-60+36 );
    glVertex2f(300+p+10, 70+q-60+50 );
    glVertex2f(300+p+50, 70+q-60+50 );
    glVertex2f(300+p+56, 70+q-60+36 );
    glVertex2f(300+p+40, 70+q-60+32 );
    glVertex2f(300+p+20, 70+q-60+32);
    glEnd();
 
    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, .4); // left glass 1
    glVertex2f(300+p+2, 70+q-60+82 );
    glVertex2f(300+p+2, 70+q-60+110 );
    glVertex2f(300+p+8, 70+q-60+104 );
    glVertex2f(300+p+8, 70+q-60 +82);
    glEnd();
     
     
    glBegin(GL_POLYGON);// left glass 2
     
    glColor3f(0, 0.2, .4);
    glVertex2f(300+p+2, 70+q-60+50 );
    glVertex2f(300+p+2, 70+q-60+78 );
    glVertex2f(300+p+8, 70+q-60+78 );
    glVertex2f(300+p+8, 70+q-60+56 );
        glEnd();
 
     
 
    glBegin(GL_POLYGON); //front glass
    glColor3f(0, 0.2, .4);
    glVertex2f(300+p+10,70+q+106-60);
    glVertex2f(300+p+4,70+q+120-60);
    glVertex2f(300+p+10,70+q+124-60);
    glVertex2f(300+p+30,70+q+128-60);
    glVertex2f(300+p+50,70+q+124-60);
    glVertex2f(300+p+56,70+q+120-60);
    glVertex2f(300+p+50,70+q+106-60);
    glVertex2f(300+p+44,70+q+108-60);
    glVertex2f(300+p+30,70+q+110-60);
    glVertex2f(300+p+16,70+q+108-60);
    glEnd();
 
     
    glBegin(GL_POLYGON); //right glass 2
    glColor3f(0, 0.2, .4);
    glVertex2f(300+p+52,70+q+82-60);
    glVertex2f(300+p+52,70+q+104-60);
    glVertex2f(300+p+58,70+q+110-60);
    glVertex2f(300+p+58,70+q+82-60);
    glEnd();
     
    glBegin(GL_POLYGON); //right glass 1
    glColor3f(0, 0.2, .4);
    glVertex2f(300+p+52,70+q+56-60);
    glVertex2f(300+p+52,70+q+78-60);
    glVertex2f(300+p+58,70+q+78-60);
    glVertex2f(300+p+58,70+q+50-60);
    glEnd();
 
    glBegin(GL_POLYGON); //bonet
    glColor3f(.8, 0, 0);
    glVertex2f(300+p+4,70+q+120-60);
    glVertex2f(300+p+10,70+q+124-60);
    glVertex2f(300+p+30,70+q+128-60);
    glVertex2f(300+p+50,70+q+124-60);
    glVertex2f(300+p+56,70+q+120-60);
    glVertex2f(300+p+54,70+q+158-60);
    glVertex2f(300+p+30,70+q+162-60);
    glVertex2f(300+p+10,70+q+158-60);
    glEnd();
     
    glBegin(GL_POLYGON);//bonet line
    glColor3f(0.5, 0, 0);
    glVertex2f(300+p+10,70+q+124-60);
    //glColor3f(.6, 0, 0);
    glVertex2f(300+p+20,70+q+160-60);
    glColor3f(.4, 0, 0);
    glVertex2f(300+p+30,70+q+162-60);
    glColor3f(.2, 0, 0);
    glVertex2f(300+p+40,70+q+160-60);
    glColor3f(0, 0, 0);
    glVertex2f(300+p+50,70+q+124-60);
    //glColor3f(.1, 0, 0);
    glVertex2f(300+p+30,70+q+128-60);
 
    glEnd();
	glFlush();
}
void drawroad(void){

	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.376, 0.376, 0.376);
	glPointSize(3.0);
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glVertex2f(1000,0);
    
    glEnd();

	


}
void drawDivider(float h)
{
    int divxmin = 485, divxmax = 515;
    int divy = 0, divymax = 0;
 
    for(int i =0; i <1000; i++)
    {
        glPointSize(4.0);
 
        glBegin(GL_POLYGON);// main body
        glColor3f(1, 1, 1);
		glVertex2f(divxmin, divy +10+h);
        glVertex2f(divxmax, divy +10+h);
        glVertex2f(divxmax, divy + 80+h);
        glVertex2f(divxmin, divy +80+h);
 
        glEnd();
 
        divy += 80;
    }
}
void drawDividerleft(float h)
{
    int divxmin = 235, divxmax = 265;
    int divy = 0, divymax = 0;
 
    for(int i =0; i <1000; i++)
    {
        glPointSize(4.0);
 
        glBegin(GL_POLYGON);// main body
        glColor3f(1, 1, 1);
        glVertex2f(divxmin, divy +10+h);
        glVertex2f(divxmax, divy +10+h);
        glVertex2f(divxmax, divy + 80+h);
        glVertex2f(divxmin, divy +80+h);
 
        glEnd();
 
        divy += 80;
    }
}
void drawDividerright(float h)
{
    int divxmin = 735, divxmax = 765;
    int divy = 0, divymax = 0;
 
    for(int i =0; i <1000; i++)
    {
        glPointSize(4.0);
 
        glBegin(GL_POLYGON);// main body
        glColor3f(1, 1, 1);
        glVertex2f(divxmin, divy +10+h);
        glVertex2f(divxmax, divy +10+h);
        glVertex2f(divxmax, divy + 80+h);
        glVertex2f(divxmin, divy +80+h);
 
        glEnd();
 
        divy += 80;
    }
}

void drawscore(int a){
	
	int i, j, k;
	i = a / 100;
	j = a / 10 - i * 10;
	k = a - j * 10 - i * 100;
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(780, 500, 0);
	glScaled(.3, .3, .3);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'c');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)':');
	glColor3f(0.0, 0.0, 0.0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)i + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)j + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)k + 48);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(780, 300, 0);
	glScaled(.06, .1, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(780, 250, 0);
	glScaled(.06, .1, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'u');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'i');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glPopMatrix();
}

void myDisplay()
{
	if (collision==false)
	{	
		
		if (score < 25)
		{
			h=h-m;
			y11 =y11- m;
			y22 =y22- m ;
			y33 =y33- m;
			y44 =y44- m ;			
			
		}
		if (score >= 25 && score < 50)
		{
			h=h-n;
			y11 =y11- n;
			y22 =y22- n;
			y33 =y33- n;
			y44 =y44- n ;	
		}
		if (score >= 50)
		{   h=h-o;
			y11 =y11- o;
			y22 =y22- o;
			y33 =y33- o;
			y44 =y44- o ;	

		}
		
		if (y11 <0)
		{
			score =score+ 5;
			y11 = 600;
		}
		if (y22 < 0)
		{
			score =score+ 5;
			y22 = 600;
		}
			if (y33 <0)
		{
			score =score+ 5;
			y33 = 600;
		}
		if (y44 < 0)
		{
			score =score+ 5;
			y44 = 600;
		}
			if(y11<70+166-60 && x<20 && x>-20) // middle left
				collision=true;
			if(y22<70+166-60 && x>250 && x<280) // middle right
				collision=true;
			if(y33<70+166-60 && x<-200) //left most
				collision=true;
			if(y44<70+166-60 && x>350) // right most
				collision=true;
			if(x<-280 || x>600)
				collision=true;
			if(y<0 || y>600)
				collision=true;
			



		
			/*if(x>270 || x<0) // side collision
				collision= true;*/
			glClear(GL_COLOR_BUFFER_BIT);
			drawroad();
			//drawdv(g,h);
			drawDivider(h);
			drawDividerleft(h);
			drawDividerright(h);
			drawscore(score);
			drawcar(x, y);
			drawpccar(x11, y11);
			drawpccar(x22, y22);
			drawpccar(x33, y33);
			drawpccar(x44, y44);
			glutSwapBuffers();
	
	}else{
	
		glClear(GL_COLOR_BUFFER_BIT);
		drawscore(score);


		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(500, 400, 0);
		glScaled(.3, .3, 3);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'G');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'M');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'V');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'R');
		glPopMatrix();
	
		glutSwapBuffers();
	}
	
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	 gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}
void keyboards(unsigned char keys, int x4, int y4)
{
	if (keys == 's')
	{
		glutIdleFunc(myDisplay);
	}
	if (keys == 'q')
	{
		exit(-1);
	}

	if (keys == '4')
		x =x- 270;
	if (keys == '6')
		x =x+ 270;
	if (keys == '8')
		y =y+ 25;
	if (keys == '2')
		y =y- 25;

	glutPostRedisplay();
}
void keyboards(int keys, int x4, int y4)
{

	if (keys ==GLUT_KEY_LEFT )
		x = x-270;
	if (keys == GLUT_KEY_RIGHT)
		x =x+ 270;
	if (keys ==GLUT_KEY_UP )
		y =y+ 25;
	if (keys == GLUT_KEY_DOWN)
		y =y- 25;

	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics final project");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboards);
	glutSpecialFunc(keyboards);
	myInit();
	glutMainLoop();
}
