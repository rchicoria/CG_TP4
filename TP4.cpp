/*
Ricardo Pinto Lopes 2008114843
Rui Pedro da Cunha Santos Chicória 2008115099
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "anexo.h"

//--------------------------------- Definir cores
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  1.0, 0.5, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.92, 0.92, 0.92, 1.0
#define NIGHT     0.2, 0.2, 0.2, 1.0
#define PI		 3.14159
#define MAP      0
#define PERSPECTIVE    1 

//================================================================================
//===========================================================Variaveis e constantes

char     texto[30];

//------------------------------------------------------------ Sistema Coordenadas
GLfloat   xC=1.0, yC=1.0, zC=1.0;
GLint     wScreen=800, hScreen=600;

GLint    msec=10;

//------------------------------------------------------------ Observador
GLint    defineView=0;
GLint    defineProj=0;

GLfloat  raio   = 1;
GLfloat  angulo = 0;
GLfloat  inca   = 0.1;              //incremento do angulo do observador
GLfloat  incp   = 0.05;             //incremento da posicao do observador

GLfloat  obsP[] = {0, 0.01, raio};   //posicao inicial do observador
GLfloat  angRot = 0;                //angulo de rotacao do observador

//------------------------------------------------------------- Objectos
GLfloat  incar   = 0.5; //rotaçao dos objectos

GLfloat   buleP[]= {0, 0, 0}; //Posicao do bule
GLfloat   buleT = 0.1; //Tamanho do bule

GLfloat   torus1P[] = {0.3 ,0, 0.2}; //Posicao do torus1
GLfloat   torus1T[] = {0.05, 0.1, 100, 100}; //Tamanho do torus1
GLfloat   torus1R = 45; //Rotacao do torus1

GLfloat   torus2P[] = {-0.1 ,0, -0.25}; //Posicao do torus2
GLfloat   torus2T[] = {0.03, 0.05, 100, 100}; //Tamanho do torus2
GLfloat   torus2R = -30; //Rotacao do torus2

GLfloat   sphereP[] = {-0.2 ,0, 0.15}; //Posicao do sphere
GLfloat   sphereT[] = {0.05, 100, 100}; //Tamanho do sphere

GLfloat   cubeP[] = {0.2 ,0, -0.2}; //Posicao do cube
GLfloat   cubeT = 0.1; //Tamanho do cube
GLfloat   cube2R = 45; //Rotacao do cube

//------------------------------------------------------------- Luz
GLint   ctrlMateriais=1;      //controla a utilização dos materiais
GLint   ctrlLocal=1;       //controla a utilização de luz local
GLint   ctrlLant=0;       //controla a utilização de luz local

GLfloat   colorAmbient[4] = {0.1,0.1,0.1,1};

GLfloat localCor[4] ={0.1, 0.1, 0.1, 1.0};
GLfloat localPos[4] ={0, 1.0, 0, 1.0};
GLfloat localAttCon =1.0;
GLfloat localAttLin =0.05;
GLfloat localAttQua =0.0;

GLfloat CorDif[4] ={ 0.8,0.8,0.8, 1.0};
GLfloat concentracao = 0.1;
GLfloat ang = 15;

GLfloat angLant = 0;
GLfloat hLant = 0;
GLfloat hinc = 0.05;

//================================================================================
//=========================================================================== INIT

void init(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, localPos );
    glLightfv(GL_LIGHT0, GL_AMBIENT, localCor );
    glLightf (GL_LIGHT0, GL_CONSTANT_ATTENUATION, localAttCon);
    glLightf (GL_LIGHT0, GL_LINEAR_ATTENUATION, localAttLin) ;
    glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION,localAttQua) ;
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, CorDif );
    glLightf (GL_LIGHT1, GL_SPOT_EXPONENT , concentracao);
    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, ang);

}


void resizeWindow(GLsizei w, GLsizei h)
{
 	wScreen=w;
	hScreen=h;
	glutPostRedisplay();
}

void drawScene(int view){

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chaleira
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, rubyAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,rubyShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, rubySpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,rubyDiffuse);
    }
	glPushMatrix();
		glColor4f(VERDE);
		glTranslatef(buleP[0], buleP[1], buleP[2]);
		glRotatef(angRot,0,1,0);
		glutSolidTeapot(buleT);
	glPopMatrix();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Torus
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, emeraldAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,emeraldShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, emeraldSpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,emeraldDiffuse);
    }
	glPushMatrix();
		glColor4f(VERMELHO);
		glTranslatef(torus1P[0], torus1P[1], torus1P[2]);
        glRotatef(angRot,0,1,0);
		glRotatef(torus1R,1,0,0);
		glutSolidTorus(torus1T[0], torus1T[1], torus1T[2], torus1T[3]);
	glPopMatrix();
	
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, jadeAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,jadeShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, jadeSpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE, jadeDiffuse);
    }
	glPushMatrix();
		glColor4f(AZUL);
		glTranslatef(torus2P[0], torus2P[1], torus2P[2]);
        glRotatef(angRot,0,1,0);
		glRotatef(torus2R,1,0,0);
		glutSolidTorus(torus2T[0], torus2T[1], torus2T[2], torus2T[3]);
	glPopMatrix();
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sphere
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, pearlAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,pearlShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, pearlSpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE, pearlDiffuse);
    }
	glPushMatrix();
		glColor4f(AMARELO);
		glTranslatef(sphereP[0], sphereP[1], sphereP[2]);
        glRotatef(angRot,0,1,0);
		glutSolidSphere(sphereT[0], sphereT[1], sphereT[2]);
	glPopMatrix();
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Cube
	
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, brassAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,brassShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, brassSpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE, brassDiffuse);
    }
	glPushMatrix();
		glColor4f(LARANJA);
		glTranslatef(cubeP[0], cubeP[1], cubeP[2]);
        glRotatef(angRot,0,1,0);
        glRotatef(cube2R,1,0,0);
		glutSolidCube(cubeT);
	glPopMatrix();
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Position cone
	
	if(ctrlMateriais==0){
	    glMaterialfv(GL_FRONT,GL_AMBIENT, blackAmbient);
        glMaterialf(GL_FRONT,GL_SHININESS,blackShininess);
        glMaterialfv(GL_FRONT,GL_SPECULAR, blackSpecular);
        glMaterialfv(GL_FRONT,GL_DIFFUSE, blackDiffuse);
    }
	if(view==MAP){
	    glPushMatrix();
		    glColor4f(BLACK);
		    glTranslatef(obsP[0],obsP[1],obsP[2]);
		    glRotatef(180-angulo*57, 0,1,0);
		    glutSolidCone(0.03, 0.1, 20, 20);
	    glPopMatrix();
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixos
	glColor4f(BLACK);
	glBegin(GL_LINES);
		glVertex3i( -xC, 0, 0); 
		glVertex3i(xC, 0, 0); 
	glEnd();
	glBegin(GL_LINES);
		glVertex3i(0, -yC, 0); 
		glVertex3i(0, yC, 0); 
	glEnd();
	glBegin(GL_LINES);
		glVertex3i( 0, 0, -zC); 
		glVertex3i( 0, 0,zC); 
	glEnd();

}

void showLight(GLfloat lookLant[]){
    //---------------------------------------------------[ Luz]
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, colorAmbient);
	
	if(ctrlMateriais==1){
	    glEnable(GL_COLOR_MATERIAL);
	    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
	}
	else{
	    glDisable(GL_COLOR_MATERIAL);
    }
	
	if(ctrlLocal==1)
	    glEnable(GL_LIGHT0);
	else
	    glDisable(GL_LIGHT0);
	    
	if(ctrlLant==1){
	    glEnable(GL_LIGHT1);
	    GLfloat direccao[ ] = { lookLant[0], lookLant[1]-obsP[1], lookLant[2] ,0.0};
    
        GLfloat ponto[4] = {obsP[0], obsP[1], obsP[2], 1.0};
	
	    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direccao );
        glLightfv(GL_LIGHT1, GL_POSITION, ponto );
    }
	else
	    glDisable(GL_LIGHT1);
}

void desenhaTexto(char *string, GLfloat x, GLfloat y, GLfloat z) 
{  
	glRasterPos3f(x,y,z); 
	while(*string)
	  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++); 
}

void display(void){
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Apagar ]
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	if(colorAmbient[0]==0.5)
	    glClearColor(GRAY);
	else
	    glClearColor(NIGHT);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Look at do observador ]
	GLfloat obsL [] = {raio*cos(angulo-PI/2)+obsP[0], 0 ,raio*sin(angulo-PI/2)+obsP[2]};
	GLfloat lookLant[] = {raio*cos(angLant-PI/2), hLant ,raio*sin(angLant-PI/2)};
	    
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Janela Visualizacao ]
	glViewport (0,0,200, 200);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Projeccao]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glOrtho (-xC,xC,-yC,yC,-zC,zC);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Modelo+View(camera/observador) ]
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0.5, 0, 0,0,0, 0, 0, -1);
	
	showLight(lookLant);
	    //--------------------- Informacao
	glColor3f(0,0,0);
	int ctrlAmbiente=0;
	if(colorAmbient[0]==0.5)
	    ctrlAmbiente=1;
	else
	    ctrlAmbiente=0;
	sprintf(texto, "%d - Noite", ctrlAmbiente);
	desenhaTexto(texto,0.5,0,0.5);
	sprintf(texto, "%d - Tecto", ctrlLocal);
	desenhaTexto(texto,0.5,0,0.6);
	sprintf(texto, "%d - Foco", ctrlLant);
	desenhaTexto(texto,0.5,0,0.7);
	sprintf(texto, "%d - ColorM", ctrlMateriais);
	desenhaTexto(texto,0.5,0,0.8);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Objectos ]
	drawScene(MAP);
	glViewport (200,200,wScreen-200, hScreen-200);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Projeccao]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(104, wScreen/hScreen, 0.01, zC*2);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Modelo+View(camera/observador) ]
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], obsL[0], obsL[1], obsL[2], 0, 1, 0);
	
	showLight(lookLant);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Objectos ]
	drawScene(PERSPECTIVE);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
	glutSwapBuffers();
}

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y){	
	switch (key) {
	//--------------------------- Textura
	case 'n':
	case 'N':
	    if(colorAmbient[0]==0.5){
	        colorAmbient[0]=0.1;
	        colorAmbient[1]=0.1;
	        colorAmbient[2]=0.1;
	        colorAmbient[3]=1.0;
	    }
	    else{
	        colorAmbient[0]=0.5;
	        colorAmbient[1]=0.5;
	        colorAmbient[2]=0.5;
	        colorAmbient[3]=1;
	    }
	    break;
	case 'm':
	case 'M':
	    if(ctrlMateriais==1)
	        ctrlMateriais=0;
	    else
	        ctrlMateriais=1;
	    break;
    case 't':
    case 'T':
        ctrlLocal+=1;
        ctrlLocal%=2;
        break;
    case 'f':
    case 'F':
        ctrlLant+=1;
        ctrlLant%=2;
        break;
    case 'a':
    case 'A':
        angLant-=inca;
        break;
    case 'd':
    case 'D':
        angLant+=inca;
        break;
    case 'w':
    case 'W':
        hLant+=hinc;
        break;
    case 's':
    case 'S':
        hLant-=hinc;
        break;
    case 27:
        exit(0);
        break;
  }
  glutPostRedisplay();
}

void teclasNotAscii(int key, int x, int y){
   
	switch (key) {
	case GLUT_KEY_LEFT:
		angulo-=inca;
		angLant-=inca;
		break;
	
	case GLUT_KEY_RIGHT:
		angulo+=inca;
		angLant+=inca;
		break;
	
	case GLUT_KEY_UP:
		obsP[2]-=incp*cos(angulo);
		obsP[0]+=incp*sin(angulo);
		break;
	
	case GLUT_KEY_DOWN:
		obsP[2]+=incp*cos(angulo);
		obsP[0]-=incp*sin(angulo);
		break;
		
	default:
		break;
	}
	
	glutPostRedisplay();	
}

void Timer(int value) 
{
	angRot+=incar;
	glutPostRedisplay();
	glutTimerFunc(msec,Timer, 1);
}

//======================================================= MAIN
int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Trabalho Prático 4");
  
	init();
	
	glutSpecialFunc(teclasNotAscii);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
	glutReshapeFunc(resizeWindow);
	glutTimerFunc(msec,Timer, 1);

	glutMainLoop();

	return 0;
}
