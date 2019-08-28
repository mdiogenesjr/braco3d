// BracoMecanico3d.cpp - Marcos Diógenes

#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
#define deltaT 33

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;
GLfloat theta1 = 0.0;
GLfloat theta2 = 0.0;
GLfloat theta3 = 0.0;
GLfloat theta4 = 0.0;
GLfloat theta5 = 0.0;
float theta1Max;
float theta1Min;
float theta2Max;
float theta2Min;
float theta3Max;
float theta3Min;
float theta4Max;
float theta4Min;
float theta5Max;
float theta5Min;
float incremento1 = 2.0;
float incremento2 = 2.0;
float incremento3 = 2.0;
float incremento4 = 2.0;
float incremento5 = -2.0;

void EspecificaParametrosVisualizacao();
void GerenciaTeclado(unsigned char key, int x, int y);
void Desenha(void);
void SpecialKeys(int key, int x, int y);
void Inicializa (void);
void EspecificaParametrosVisualizacao(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void setTimer(int value);

// Programa Principal
int main(int argc, char ** argv)
{
    theta1Max = 360;
	theta1Min = 0;
	theta2Max = 90;
	theta2Min = 0;
	theta3Max = 45;
	theta3Min = 0;
	theta4Max = 90;
    theta4Min = 0;
    theta5Max = 0;
    theta5Min = -90;
   
	cout << "Digite o valor inicial de theta 1"<<endl;
    cin >> theta1Min;
	cout << "Digite o valor final de theta 1"<<endl;
    cin >> theta1Max;
    
    cout << "Digite o valor inicial de theta 2"<<endl;
    cin >> theta2Min;
	cout << "Digite o valor final de theta 2"<<endl;
    cin >> theta2Max;
    
    cout << "Digite o valor inicial de theta 3"<<endl;
    cin >> theta3Min;
	cout << "Digite o valor final de theta 3"<<endl;
    cin >> theta3Max;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(1024,768);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutTimerFunc(deltaT, setTimer, 1);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutMainLoop();
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            /*case 'Q': 
            case 'q':
                     theta1 = theta1 + 1.0;
                     break;
            case 'A': 
            case 'a':
                     theta1 = theta1 - 1.0;
                     break;
            case 'W':
            case 'w':
                     theta5 = theta5 + 1.0;
                     break;
            case 'S':
            case 's':
                     theta5 = theta5 - 1.0;
                     break;
            case 'E':
            case 'e':
                     theta4 = theta4 + 1.0;
                     break;
            case 'D':
            case 'd':
                     theta4 = theta4 - 1.0;
                     break;*/
            case 'Z':
            case 'z':
                     if (angle >= 10) angle -= 5;
                     break;
            case 'X':
            case 'x':
                     if (angle <= 130) angle += 5;
                     break;
    }
    glutPostRedisplay();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Ombro
	glColor3f(0.66f, 0.66f, 0.66f);
	glRotatef(theta1, 0.0, 1.0, 0.0);
	glutSolidSphere(15,20,10);
	//Biceps
	glColor3f(1.0f, 1.0f,0.0f);
	glTranslatef(20,0,0);
	glutSolidCube(15.0f);
	glTranslatef(15,0,0);
	glutSolidCube(15.0f);
	//Cotovelo
	glColor3f(0.66f, 0.66f, 0.66f);
	glTranslatef(13,0,0);
	glRotatef(theta2, 0.0, 0.0, 1.0);
	glutSolidSphere(7,20,10);
    //Antebraco 
	glColor3f(1.0f, 1.0f,0.0f);
	glTranslatef(7,0,0);
	glutSolidCube(15.0f);
	glTranslatef(15,0,0);
	glutSolidCube(15.0f);
	//Pulso
	glColor3f(0.66f, 0.66f,0.66f);
	glTranslatef(12,0,0);
	glRotatef(theta3, 0.0, 0.0, 1.0);
	glutSolidSphere(5,20,10);
	//Mão
	glColor3f(1.0f, 1.0f,0.0f);
	glTranslatef(5,0,0);
	glutSolidCube(10.0f);
	//Dedo1
	glPushMatrix();
	glColor3f(0.66f, 0.66f,0.66f);
	glTranslatef(6,3,0);
	//glutSolidCube(3.0f);
	glRotatef(theta4, 0.0, 0.0, 1.0);
	glutSolidSphere(2,20,10);
	glTranslatef(3,0,0);
	glutSolidCube(3.0f);
	glTranslatef(3,0,0);
	glutSolidCube(3.0f);
	glPopMatrix();
	//Base
	glColor3f(0.66f, 0.66f,0.66f);
	glTranslatef(6,0,0);
	glutSolidCube(3.0f);
	//Dedo2
	glColor3f(0.66f, 0.66f,0.66f);
	glTranslatef(0,-3,0);
	glRotatef(theta5, 0.0, 0.0, 1.0);
	//glutSolidCube(3.0f);
	glutSolidSphere(2,20,10);
	glTranslatef(3,0,0);
	glutSolidCube(3.0f);
	glTranslatef(3,0,0);
	glutSolidCube(3.0f);
	
	EspecificaParametrosVisualizacao();
	// Executa os comandos OpenGL
	glutSwapBuffers();
 }
 
 // Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void SpecialKeys(int key, int x, int y)
        {
		switch (key) {
			case GLUT_KEY_LEFT : 
								obsX -=10;
								break;
			case GLUT_KEY_RIGHT : 
								obsX +=10;
								break;
			case GLUT_KEY_UP : 
								obsY +=10;
								break;
			case GLUT_KEY_DOWN : 
								obsY -=10;
								break;

			case GLUT_KEY_HOME : 
								obsZ +=10;
								break;
			case GLUT_KEY_END : 
								obsZ -=10;
								break;
		}
		glLoadIdentity();
		gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
 	    glutPostRedisplay();
  }

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.5,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void setTimer(int value)
{   
	theta1 = theta1 + incremento1;
    if ((theta1>=theta1Max)||(theta1<=theta1Min)){
		incremento1 *= -1;
	}
    
    theta2 = theta2 + incremento2;
    if ((theta2>=theta2Max)||(theta2<=theta2Min)){
		incremento2 *= -1;
	}
    
    theta3 = theta3 + incremento3;
    if ((theta3>=theta3Max)||(theta3<=theta3Min)){
		incremento3 *= -1;
	}

	theta4 = theta4 + incremento4;
    if ((theta4>=theta4Max)||(theta4<=theta4Min)){
		incremento4 *= -1;
	}

	theta5 = theta5 + incremento5;
    if ((theta5>=theta5Max)||(theta5<=theta5Min)){
		incremento5 *= -1;
	}
	
	glutPostRedisplay();
	glutTimerFunc(deltaT, setTimer, 1);
}
