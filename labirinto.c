//*****************************************************
// UNIVASF- Universidade Federal do Vale do São Francisco
// Disciplina: Computação Gráfica
// Docente: Jorge Cavalcanti
// Discentes: Djeysi Kathleen Alves, Victor Gabriel Ferreira Barbosa.
// Semestre: 2018.2
//
// labirinto:
//*****************************************************

#define nCores 3

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#define xStep 1 //incremento no eixo x
#define yStep 1 //incremento no eixo y
#define maxY 125 //valor máximo do eixo Y
#define maxX 105 //valor máximo do eixo X
#define nlinhas 29
int vidas = 4;
// Variáveis que guardam a translação que será aplicada 
// sobre a casinha
int Tx=0;
int Ty=0;
int acabou = 0;

// Variáveis que guardam os valores mínimos de x e y da 
// casinha
GLfloat minX;
GLfloat minY;

// Variáveis que guardam a largura e altura da janela
GLfloat windowXmin, windowXmax;
GLfloat windowYmin, windowYmax;

//Variáveis que guardam os vértices do triangulo
int x1,x2,x3,x4;

int y4,y2,y3,y5;

struct cor
{
   float r;
   float g;
   float b;
};

struct objeto
{
   float x1,x2,y1,y2;
};

struct cor fundo;
struct cor paredes;
struct cor objeto;
struct cor coresParedes[nCores];
struct cor coresFundo[nCores];
struct cor coresObjeto[nCores];
struct objeto linhas[nlinhas], tri;
int i = 0;


void Inicializa (void)
{
   
   //1 mudança
   
   coresParedes[0].r = 0;
   coresParedes[0].g = 0; //parede preto.
   coresParedes[0].b = 0;

   coresFundo[0].r = 1; 
   coresFundo[0].g = 1; //fundo branco.
   coresFundo[0].b = 1;

   coresObjeto[0].r = 1;
   coresObjeto[0].g = 0;//objeto vermelho
   coresObjeto[0].b = 0;

   // 2 mudança

   coresParedes[1].r = 1;
   coresParedes[1].g = 1;//parede branca
   coresParedes[1].b = 1;

   coresFundo[1].r = 0;
   coresFundo[1].g = 0; //fundo  preto
   coresFundo[1].b = 0;

   coresObjeto[1].r = 1;
   coresObjeto[1].g = 1; //objeto amarelo
   coresObjeto[1].b = 0;

   // 3 mudança
   coresParedes[2].r = 1;
   coresParedes[2].g = 0;//parede magenta
   coresParedes[2].b = 1;

   coresFundo[2].r = 0;
   coresFundo[2].g = 1; //fundo ciano 
   coresFundo[2].b = 1;

   coresObjeto[2].r = 0.5;
   coresObjeto[2].g = 0.5; //objeto cinza
   coresObjeto[2].b = 0.5;

   paredes = coresParedes[i];
   fundo = coresFundo[i];
   objeto = coresObjeto[i];

   linhas[0].x1 = 0;
   linhas[0].x2 = 0;
   linhas[0].y1 = 0;
   linhas[0].y2 = 30;
   
   linhas[1].x1 = 0;
   linhas[1].x2 = 0;
   linhas[1].y1 = 45;
   linhas[1].y2 = 105;

   linhas[2].x1 = 15;
   linhas[2].x2 = 15;
   linhas[2].y1 = 30;
   linhas[2].y2 = 45;

   linhas[3].x1 = 15;
   linhas[3].x2 = 15;
   linhas[3].y1 = 60;
   linhas[3].y2 = 90;

   linhas[4].x1 = 30;
   linhas[4].x2 = 30;
   linhas[4].y1 = 15;
   linhas[4].y2 = 75;

   linhas[5].x1 = 45;
   linhas[5].x2 = 45;
   linhas[5].y1 = 15;
   linhas[5].y2 = 60;
   
   linhas[6].x1 = 45;
   linhas[6].x2 = 45;
   linhas[6].y1 = 75;
   linhas[6].y2 = 90;
   
   linhas[7].x1 = 60;
   linhas[7].x2 = 60;
   linhas[7].y1 = 15;
   linhas[7].y2 = 30;
   
   linhas[8].x1 = 60;
   linhas[8].x2 = 60;
   linhas[8].y1 = 60;
   linhas[8].y2 = 105;
   
   linhas[9].x1 = 75;
   linhas[9].x2 = 75;
   linhas[9].y1 = 0;
   linhas[9].y2 = 15;

   linhas[10].x1 = 90;
   linhas[10].x2 = 90;
   linhas[10].y1 = 15;
   linhas[10].y2 = 30;

   linhas[11].x1 = 90;
   linhas[11].x2 = 90;
   linhas[11].y1 = 45;
   linhas[11].y2 = 90;
 
   linhas[12].x1 = 105;
   linhas[12].x2 = 105;
   linhas[12].y1 = 0;
   linhas[12].y2 = 45;
   
   linhas[13].x1 = 105;
   linhas[13].x2 = 105;
   linhas[13].y1 = 60;
   linhas[13].y2 = 105;

//////////////////////////////////////////////////

   linhas[14].x1 = 0;
   linhas[14].x2 = 15;
   linhas[14].y1 = 30;
   linhas[14].y2 = 30;

   linhas[15].x1 = 0;
   linhas[15].x2 = 15;
   linhas[15].y1 = 60;
   linhas[15].y2 = 60;
   
   linhas[16].x1 = 15;
   linhas[16].x2 = 30;
   linhas[16].y1 = 15;
   linhas[16].y2 = 15;
   
   linhas[17].x1 = 15;
   linhas[17].x2 = 30;
   linhas[17].y1 = 45;
   linhas[17].y2 = 45;
   
   linhas[18].x1 = 15;
   linhas[18].x2 = 30;
   linhas[18].y1 = 90;
   linhas[18].y2 = 90;
   
   linhas[19].x1 = 30;
   linhas[19].x2 = 45;
   linhas[19].y1 = 75;
   linhas[19].y2 = 75;
   
   linhas[20].x1 = 45;
   linhas[20].x2 = 60;
   linhas[20].y1 = 15;
   linhas[20].y2 = 15;
   
   linhas[21].x1 = 45;
   linhas[21].x2 = 60;
   linhas[21].y1 = 60;
   linhas[21].y2 = 60;

   linhas[22].x1 = 60;
   linhas[22].x2 = 90;
   linhas[22].y1 = 30;
   linhas[22].y2 = 30;

   linhas[23].x1 = 60;
   linhas[23].x2 = 105;
   linhas[23].y1 = 45;
   linhas[23].y2 = 45;

   linhas[24].x1 = 60;
   linhas[24].x2 = 75;
   linhas[24].y1 = 60;
   linhas[24].y2 = 60;

   linhas[25].x1 = 60;
   linhas[25].x2 = 75;
   linhas[25].y1 = 90;
   linhas[25].y2 = 90;
   
   linhas[26].x1 = 75;
   linhas[26].x2 = 90;
   linhas[26].y1 = 75;
   linhas[26].y2 = 75;
   
   linhas[27].x1 = 0;
   linhas[27].x2 = 105;
   linhas[27].y1 = 0;
   linhas[27].y2 = 0;
   
   linhas[28].x1 = 0;
   linhas[28].x2 = 105;
   linhas[28].y1 = 105;
   linhas[28].y2 = 105;
   
   
   // Define a cor de fundo da janela de visualização como branco

   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
   x1 = 0;
   x2 = 10;
   x3 =10;
   x4 = 0;
   y4 = 30;
   y2 = 30;
   y3 = 40;
   y5 = 40;

   glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);


   // Define a janela de visualização 2D
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0.0,maxX,0.0,maxY);
   glMatrixMode(GL_MODELVIEW); //para n manipular a matriz de projeção
}


void desenhaObjeto(){
   
   glColor3f(objeto.r,objeto.g,objeto.b);
   
   glBegin(GL_QUADS);
   glVertex2f(x1 + Tx, y4 + Ty);
   glVertex2f(x2 + Tx, y2 + Ty);
   glVertex2f(x3 + Tx, y3 + Ty);
   glVertex2f(x4 + Tx, y5 + Ty);
   glEnd();

}

void detectaColisao(struct objeto tri, struct objeto linha){
   if(((linha.x2 -1) == tri.x1) || ((linha.x1 -1) == tri.x2)){
      if((tri.y1 >= (linha.y1 -1)) && (tri.y2 <= (linha.y2)-1) ){
         Tx = Ty= 0;
         vidas--;
      }
   }else{
    if(((linha.y2 -1) == tri.y2) || ((linha.y1 -1) == tri.y1))
        if(((linha.x1 -1) <= tri.x2) && ((linha.x2 -1) >= tri.x1)){
            Tx = Ty= 0;
            vidas--;
        }
   }

}

void desenhaVidas(){
   
   glColor3f(objeto.r,objeto.g,objeto.b);

   //if(vidas == 0)
      //vidas =4;

   if(vidas >=1){
      glBegin(GL_QUADS);
      glVertex2f(5 , 110);
      glVertex2f(15, 110);
      glVertex2f(15, 120);
      glVertex2f(5, 120);
      glEnd();
   }

   if(vidas >= 2){
      glBegin(GL_QUADS);
      glVertex2f(20 , 110);
      glVertex2f(30, 110);
      glVertex2f(30, 120);
      glVertex2f(20, 120);
      glEnd();
   }

   if(vidas >= 3){
      glBegin(GL_QUADS);
      glVertex2f(35 , 110);
      glVertex2f(45, 110);
      glVertex2f(45, 120);
      glVertex2f(35, 120);
      glEnd();
   }

   if(vidas == 4){
      glBegin(GL_QUADS);
      glVertex2f(50 , 110);
      glVertex2f(60, 110);
      glVertex2f(60, 120);
      glVertex2f(50, 120);
      glEnd();
   }
}

void DesenhaTextoStroke(char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,*string++); 
}

void DesenhaTexto(char *p) 
{
	// Exibe caractere a caractere
        while (*p != '\0') {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
        }
}

   // Função callback chamada para fazer o desenho
void Desenha(void)
{
     
   // Muda para o sistema de coordenadas do modelo
   glMatrixMode(GL_MODELVIEW);
   // Inicializa a matriz de transformação corrente
   glLoadIdentity();
 
   glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);

   //Limpa a janela de visualização com a cor de fundo especificada
   glClear(GL_COLOR_BUFFER_BIT);
   
   
   // Define a cor de desenho: preto
   glColor3f(paredes.r,paredes.g,paredes.b);
 
   //CASO PERDEU:
   
   
   if(vidas <= 0){
      glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);
      glColor3f(objeto.r, objeto.g, objeto.b);
      glTranslatef(0,60,0);
      glScalef(0.1, 0.1, 0.1);
      DesenhaTextoStroke("GAME OVER!");
      
      
      vidas = 4;
      acabou = 1;
      glutSwapBuffers();
      return;
   }   
   
   if((tri.x1 > 105)&&(tri.x2>105) && !acabou){
      glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);
      glColor3f(objeto.r, objeto.g, objeto.b);
      glTranslatef(0,60,0);
      glScalef(0.1, 0.1, 0.1);
      DesenhaTextoStroke("VICTORY! :)");
      vidas = 4;
      acabou = 1;
      Tx = 0;
      Ty = 0;
      tri.y1 = y3;
      tri.x1 =  x1;
      tri.x2 = x2;
      tri.y2 = y4;
       
      glutSwapBuffers();
      return;
   }
   
   //Desenhando as linhas do labirinto na cor corrente.
   
   glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2f(0, 0);
   glVertex2f(105, 0);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(0, 105);
   glVertex2f(105, 105);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(0, 0);
   glVertex2f(0, 30);
   glVertex2f(15,30);
   glVertex2f(15,45);
   glVertex2f(30,45);
   glVertex2f(30,75);
   glVertex2f(45,75);
   glVertex2f(45,90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(0, 45);
   glVertex2f(0, 105);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(0, 60);
   glVertex2f(15, 60);
   glVertex2f(15, 90);
   glVertex2f(30, 90);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(30, 45);
   glVertex2f(30, 15);
   glVertex2f(15, 15);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(75, 0);
   glVertex2f(75, 15);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(105, 105);
   glVertex2f(105, 60);
   glEnd();
      
   glBegin(GL_LINE_STRIP);
   glVertex2f(105, 0);
   glVertex2f(105, 45);
   glVertex2f(60, 45);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(90, 45);
   glVertex2f(90, 90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(90, 75);
   glVertex2f(75, 75);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(60, 90);
   glVertex2f(75, 90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(60, 60);
   glVertex2f(75, 60);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(90, 15);
   glVertex2f(90, 30);
   glVertex2f(60,30);
   glVertex2f(60,15);
   glVertex2f(45,15);
   glVertex2f(45,60);
   glVertex2f(60,60);
   glVertex2f(60,105);
   glEnd();
   
   //Desenhando um triangulo vermelho de acordo com as transformações:
   
   glPushMatrix();  
   
   glTranslatef(1,1,0.0f);
  
   desenhaObjeto();
   
   desenhaVidas();
   
   glutSwapBuffers();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && !acabou){
         paredes = coresParedes[i];
         fundo = coresFundo[i];
         objeto = coresObjeto[i];
         i++;
         if(i >= nCores)
            i = 0;
         glutPostRedisplay();
    }
    
}


// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
   int i;
   
    if(acabou == 1){
        if(key != GLUT_KEY_HOME){
            return;
        }else{
             acabou = 0;
        }
    }
   
   if(key == GLUT_KEY_UP) {
      Ty+= yStep;
   }
    
   if(key == GLUT_KEY_DOWN) {
      Ty -= yStep;
   }
    
   if(key == GLUT_KEY_RIGHT) {
      Tx += xStep;
   }
   
   if(key == GLUT_KEY_LEFT) {
      Tx -= xStep;
   }
   
   //encapsulando o objeto com uma lógica bizarra oriental:
   
   tri.y1 = y3 + Ty;
   tri.x1 =  x1 + Tx;
   tri.x2 = x2 + Tx;
   tri.y2 = y4 + Ty;
   
  
   
   for(i = 0; i < nlinhas; i++)
   {
      detectaColisao(tri,linhas[i]);
      if(Tx == 0 && Ty == 0)
          break;
   }
   
    glutPostRedisplay();
  
}
   
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) 
	{
		gluOrtho2D (0.0f, 105.0f, 0.0f*altura/largura, 125.0f*altura/largura);
		windowXmin = 0.0f;
		windowXmax =  105.0f;
		windowYmin = 0.0f*altura/largura;
		windowYmax = 125.0f*altura/largura;
	}
	else
	{ 
		gluOrtho2D (0.0f*largura/altura, 105.0f*largura/altura, 0.0f, 125.0f);
		windowXmin = 0.0f*largura/altura;
		windowXmax =  105.0f*largura/altura;
		windowYmin = 0.0f;
		windowYmax =  125.0f;
	}
}

void Teclado (unsigned char key, int x, int y)
{
   if (key == 27)
   exit(0);
}


// Programa Principal
int main(int argc, char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowPosition(5,5); // Especifica a posição inicial da janela GLUT
   glutInitWindowSize(400,400); // Especifica o tamanho inicial em pixels da janela GLUT
   glutCreateWindow("labirinto Impossível");
   glutDisplayFunc(Desenha);
   glutReshapeFunc(AlteraTamanhoJanela); // Registra a função callback de redimensionamento da janela de visualização
   glutKeyboardFunc (Teclado);
   glutSpecialFunc(TeclasEspeciais);

   // Registra a função callback que será chamada a cada intervalo de tempo
   // glutTimerFunc(150, TeclasEspeciais, 1);
   
   glutMouseFunc (GerenciaMouse);
   Inicializa();
   glutMainLoop();
   
}
  
