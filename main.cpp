#include<GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void ice();
void display1();
void display2();
void display3();
void display4();
void plane();
void ship();
void water();
void initRain();
GLint a=0,b=0,c=0,d=130,e=-100,f=-5,g=0,h=0,x=100,i=0,w=0,out=0;
GLfloat theta=0.0;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;


#define RAINSIZE 50
int counter = 0;
time_t t;
int flag = 0;
int p=0;
float rotationAngle = 0;
void *currentfont;

void setFont(void *font)
{
    currentfont=font;
}


void drawstring(float xy,float yz,float zx,char *string)
{
    char *cc;
    glRasterPos3f(xy,yz,zx);

    for(cc=string;*cc!='\0';cc++)
    {    glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*cc);
    }
}

void title()        // to draw the starting screen
{

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(400.0,600.0,1.0,"* * BLACK PEARL * *");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0.5,1.0,0.5);
    drawstring(410.0,530.0,1.0,"SUBMITTED   BY");

    setFont(GLUT_BITMAP_HELVETICA_18);

    glColor3f(0.6,1.0,1.0);
    drawstring(300.0,490.0,1.0,"Name:RISHAB JAIN                     USN:1BY19CS115");

    glColor3f(0.6,1.0,1.0);
    drawstring(300.0,450.0,1.0,"Name:S N SHASHANK                USN:1BY19CS128");

    glColor3f(0.6,1.0,1.0);
    drawstring(300.0,410.0,1.0,"Name:SAKSHAM BEJWANI        USN:1BY19CS132");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0.5,1.0,0.5);
    drawstring(380.0,350.0,1.0,"UNDER THE GUIDANCE OF");

    glColor3f(1.0,1.0,0.5);
    drawstring(300.0,300.0,1.0,"Mr. MUNESHWARA M S");

        setFont(GLUT_BITMAP_HELVETICA_12);


    glColor3f(0.0,1.0,1.0);
    drawstring(300.0,280.0,1.0,"Asst. Prof., Dept of CS&E");

    glColor3f(0.0,1.0,1.0);
    drawstring(300.0,260.0,1.0,"BMS INSTITUTE OF TECHNOLOGY");


    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1.0,1.0,0.5);
    drawstring(600.0,300.0,1.0,"Ms. CHETHANA C");

    setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(0.0,1.0,1.0);
    drawstring(600.0,280.0,1.0,"Asst. Prof., Dept of CS&E");

    glColor3f(0.0,1.0,1.0);
    drawstring(600.0,260.0,1.0,"BMS INSTITUTE OF TECHNOLOGY");


    glFlush();
}

void form2(){

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(400.0,600.0,1.0,"NAVIGATION OPTIONS");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,550.0,1.0,"-->Introduction");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,400.0,1.0,"-->Instructions");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,350.0,1.0,"-->Demo");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,300.0,1.0,"-->Exit");
    glFlush();
     glutPostRedisplay();
     glutSwapBuffers();
}

void intro(){

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(400.0,600.0,1.0,"INTRODUCTION");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,5500.0,1.0,"-->This project is to demostrate virtual animation of a sailing ship");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,500.0,1.0,"-->Includes portraiting simulations of differnent weather conditions which includes day, night and rain effects.");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,450.0,1.0,"We provide mouse and keyboard click triggered events for transition between multiple menu driven options");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,400.0,1.0,"we also added an option where the users can backtrack their transition");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,350.0,1.0,"more info about transition is given in instructions menu");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(25.0,50.0,1.0,"press ------> BACKSPACE to go previous page");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(350.0,250.0,1.0,"press ------> ENTER to go next slide");
    setFont(GLUT_BITMAP_HELVETICA_18);


    glColor3f(0.4,0.2,0.1);
    drawstring(700.0,50.0,1.0,"press ------> ESC to go home slide");
    glFlush();
     glutPostRedisplay();
     glutSwapBuffers();
}

void ins(){
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(400.0,600.0,1.0,"INSTRUCTION");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,550.0,1.0,"-->press ENTER key to move towards next slide");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,500.0,1.0,"-->press BLACKSPACE to backstack slides");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,450.0,1.0,"-->press ESC to traverse to home slide.");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,400.0,1.0,"-->Right click to view menu entries");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);


    glColor3f(0.4,0.2,0.1);
    drawstring(100.0,350.0,1.0,"press ------> ENTER to go next slide");
    glFlush();
     glutPostRedisplay();
     glutSwapBuffers();
}


struct drop {
    float x = 400;
    float y = 400;
    float inc = 0.01;
    float radius = 5;
    float scale = 1.0;
    float rotationAngle = 0;
    float rotationInc = 1;
};

drop rain[RAINSIZE];

void initRain() {
    srand((unsigned)time(&t));
    for (int i = 0; i < RAINSIZE; i++) {
        rain[i].x = rand() % 1024;
        rain[i].y = rand() % 768;
        rain[i].inc = 1.5 + (float)(rand() % 100) / 1000.0;
        rain[i].radius = (float)(rand() % 8);
        rain[i].scale = (float)(rand() % 20000) / 1000.0;
        rain[i].rotationAngle = (float)(rand() % 3000) / 1000.0;
        rain[i].rotationInc = (float)(rand() % 100) / 1000.0;
        if ((rand() % 100) > 50) {
            rain[i].rotationInc = -rain[i].rotationInc;
        }
    }
}

void drawParticleShape(int i) {
    glBegin(GL_POINTS);
    glVertex2d(rain[i].x, rain[i].y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(rain[i].x, rain[i].y);
    glVertex2d(rain[i].x, rain[i].y + rain[i].radius * 2);
    glEnd();
}

void drawDrop(int i) {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    drawParticleShape(i);
    rain[i].y -= rain[i].inc;
    if (rain[i].y < 0) {
        rain[i].y = 768;
    }
}

void drawRain() {
    for (int i = 0; i < RAINSIZE; i++) {
        drawDrop(i);
    }
}

float elapsedTime = 0, base_time = 0, fps = 0, frames;

void calcFPS() {
    elapsedTime = glutGet(GLUT_ELAPSED_TIME);
    if ((elapsedTime - base_time) > 1000.0) {
        fps = frames * 1000.0 / (elapsedTime - base_time);
        //printf("fps: %f", fps);
        base_time = elapsedTime;
        frames = 0;
    }
    frames++;
}


/*void circle(GLfloat p,GLfloat q,GLdouble r)
{
    GLfloat p1,q1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
        GLfloat pi=3.1416;
        GLfloat aa=(i*2*pi)/25;
        GLfloat p1=p+((r-.07) * cos(aa));
        GLfloat q1=q+((r) * sin(aa));
        glVertex2f(p1,q1);
    }
    glEnd();
}*/

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * 3.142) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(500+rad * cos(theta),500+rad * sin(theta));
        }
    }
    glEnd();
}

void sun(){
    glColor3f(1.000,0.843,0.000);
    circle(30);
}

void moon(){
    glColor3f(1.000,1.000,1.000);
    circle(30);
}


void light()
{

    GLfloat mat_ambient[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_diffuse[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={50.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_ambient);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_ambient);

}

void update(int value)
{
    //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);
    a+=20.0;
    w-=50;
    if(a>1000){
        a = 0;
    }
    if(w<=-80){
        w=0;
    }


        if(a==100||a==120||a==250||a==500||b==100||b==150||b==600||b==620||c==120||c==150||c==170)
        {

            //glEnable(GL_LIGHTING);
            //glEnable(GL_LIGHT0);
            //light();
            glColor3f(1.0,1.0,1.0);

            glBegin(GL_POLYGON);
                glVertex2f(200.0,700.0);
                glVertex2f(220.0,700.0);
                glVertex2f(420.0,550.0);
                glVertex2f(600.0,450.0);
            glEnd();

            glFlush();
        }
        glutPostRedisplay();

        glutTimerFunc(200,update,0);
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
        if(out==0)
        title();
        else if(out==1)
            form2();
        else if(out==2)
            intro();
        else if(out==3)
            ins();
        else if(out==4){
    display1();
    moon();
    if(flag == 1){
        glClearColor(0.1f,0.1f,0.1f,0.1f);
        drawRain();
        calcFPS();
        counter++;
    }
    if(flag == 2){
        glClearColor(1.0f,1.0f,1.0f,1.0f);
        sun();
      }
    }

    glFlush();

    glutPostRedisplay();
}

void display1()
{
    glPushMatrix();
    glTranslated(a,70,0.0);

    //    cloud_model_one();
    ship();
    glPopMatrix();
    water();

}





void water()
{
        glPushMatrix();
        //glPushMatrix();
        glTranslated(w,0,0.0);
        glColor3f(0.1,0.5,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,100);
        glVertex2f(10,96);
        glVertex2f(25,98);
        glVertex2f(39,94);
        glVertex2f(50,92);
        glVertex2f(70,98);
        glVertex2f(85,95);
        glVertex2f(95,96);
        glVertex2f(110,99);
        glVertex2f(128,97);
        glVertex2f(139,95);
        glVertex2f(145,97);
        glVertex2f(155,99);
        glVertex2f(172,95);
        glVertex2f(195,96);
        glVertex2f(212,95);
        glVertex2f(254,92);
        glVertex2f(284,96);
        glVertex2f(344,98);
        glVertex2f(360,93);
        glVertex2f(390,94);
        glVertex2f(410,99);
        glVertex2f(450,94);
        glVertex2f(485,100);
        glVertex2f(502,92);
        glVertex2f(552,92);
        glVertex2f(592,96);
        glVertex2f(630,105);
        glVertex2f(680,93);
        glVertex2f(720,97);
        glVertex2f(750,93);
        glVertex2f(800,95);
        glVertex2f(850,97);
        glVertex2f(880,108);
        glVertex2f(900,96);
        glVertex2f(920,93);
        glVertex2f(950,99);
        glVertex2f(980,92);
        glVertex2f(1000,99);
        glVertex2f(1000,0);
        glVertex2f(1600,10);
        glVertex2f(3000,280);
        glEnd();
        glPopMatrix();
}

/* TO DRAW SHIP */
void ship()
{

    glScaled(20,20,0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(3.5,5.5);
        glVertex2f(3.5,8.5);
        glVertex2f(19.5,8.5);
        glVertex2f(19.5,5.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(1,5.5);
        glVertex2f(4,1);
        glVertex2f(19,1);
        glVertex2f(21.5,5.5);
    glEnd();
    glColor3f(0.7,0.4,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(4,5.5);
        glVertex2f(4,8);
        glVertex2f(5,8);
        glVertex2f(5,5.5);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
        glVertex2f(7,7.5);
        glVertex2f(7,8);
        glVertex2f(10,8);
        glVertex2f(10,7.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(11.5,7.5);
        glVertex2f(11.5,8);
        glVertex2f(15,8);
        glVertex2f(15,7.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(16,7.5);
        glVertex2f(16,8);
        glVertex2f(19,8);
        glVertex2f(19,7.5);
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(4.5,8.5);
        glVertex2f(4.5,10);
        glVertex2f(18.5,10);
        glVertex2f(18.5,8.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.5,10);
        glVertex2f(5.5,12.9);
        glVertex2f(7,12.9);
        glVertex2f(7,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(5.5,12.9);
        glVertex2f(5.5,13.5);
        glVertex2f(7,13.5);
        glVertex2f(7,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(8.5,10);
        glVertex2f(8.5,12.9);
        glVertex2f(10,12.9);
        glVertex2f(10,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(8.5,12.9);
        glVertex2f(8.5,13.5);
        glVertex2f(10,13.5);
        glVertex2f(10,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(11.5,10);
        glVertex2f(11.5,12.9);
        glVertex2f(13,12.9);
        glVertex2f(13,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(11.5,12.9);
        glVertex2f(11.5,13.5);
        glVertex2f(13,13.5);
        glVertex2f(13,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(14.5,10);
        glVertex2f(14.5,12.9);
        glVertex2f(16,12.9);
        glVertex2f(16,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(14.5,12.9);
        glVertex2f(14.5,13.5);
        glVertex2f(16,13.5);
        glVertex2f(16,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.5,5.5);
        glVertex2f(1.5,6.5);
        glVertex2f(2,6.2);
        glVertex2f(3,6.2);
        glVertex2f(3.5,6.5);
        glVertex2f(3.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.5,5.5);
        glVertex2f(3.5,6.5);
        glVertex2f(4,6.2);
        glVertex2f(5,6.2);
        glVertex2f(5.5,6.5);
        glVertex2f(5.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(5.5,5.5);
        glVertex2f(5.5,6.5);
        glVertex2f(6,6.2);
        glVertex2f(7,6.2);
        glVertex2f(7.5,6.5);
        glVertex2f(7.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(7.5,5.5);
        glVertex2f(7.5,6.5);
        glVertex2f(8,6.2);
        glVertex2f(9,6.2);
        glVertex2f(9.5,6.5);
        glVertex2f(9.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(9.5,5.5);
        glVertex2f(9.5,6.5);
        glVertex2f(10,6.2);
        glVertex2f(11,6.2);
        glVertex2f(11.5,6.5);
        glVertex2f(11.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11.5,5.5);
        glVertex2f(11.5,6.5);
        glVertex2f(12,6.2);
        glVertex2f(13,6.2);
        glVertex2f(13.5,6.5);
        glVertex2f(13.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13.5,5.5);
        glVertex2f(13.5,6.5);
        glVertex2f(14,6.2);
        glVertex2f(15,6.2);
        glVertex2f(15.5,6.5);
        glVertex2f(15.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(15.5,5.5);
        glVertex2f(15.5,6.5);
        glVertex2f(16,6.2);
        glVertex2f(17,6.2);
        glVertex2f(17.5,6.5);
        glVertex2f(17.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(17.5,5.5);
        glVertex2f(17.5,6.5);
        glVertex2f(18,6.2);
        glVertex2f(19,6.2);
        glVertex2f(19.5,6.5);
        glVertex2f(19.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(19.5,5.5);
        glVertex2f(19.5,6.5);
        glVertex2f(20,6.2);
        glVertex2f(20.5,6.2);
        glVertex2f(21,6.5);
        glVertex2f(21,5.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(4.5,3.5);
        glVertex2f(4.5,4.5);
        glVertex2f(5.5,4.5);
        glVertex2f(5.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,3.5);
        glVertex2f(7,4.5);
        glVertex2f(8,4.5);
        glVertex2f(8,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(9.5,3.5);
        glVertex2f(9.5,4.5);
        glVertex2f(10.5,4.5);
        glVertex2f(10.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(12,3.5);
        glVertex2f(12,4.5);
        glVertex2f(13,4.5);
        glVertex2f(13,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(14.5,3.5);
        glVertex2f(14.5,4.5);
        glVertex2f(15.5,4.5);
        glVertex2f(15.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(17,3.5);
        glVertex2f(17,4.5);
        glVertex2f(18,4.5);
        glVertex2f(18,3.5);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(5,10);
        glVertex2f(5,11);
        glVertex2f(5.5,10.8);
        glVertex2f(6.5,10.8);
        glVertex2f(7,11);
        glVertex2f(7,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,10);
        glVertex2f(7,11);
        glVertex2f(7.5,10.8);
        glVertex2f(8.5,10.8);
        glVertex2f(9,11);
        glVertex2f(9,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(9,10);
        glVertex2f(9,11);
        glVertex2f(9.5,10.8);
        glVertex2f(10.5,10.8);
        glVertex2f(11,11);
        glVertex2f(11,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(11,10);
        glVertex2f(11,11);
        glVertex2f(11.5,10.8);
        glVertex2f(12.5,10.8);
        glVertex2f(13,11);
        glVertex2f(13,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(13,10);
        glVertex2f(13,11);
        glVertex2f(13.5,10.8);
        glVertex2f(14.5,10.8);
        glVertex2f(15,11);
        glVertex2f(15,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(15,10);
        glVertex2f(15,11);
        glVertex2f(15.5,10.8);
        glVertex2f(16.5,10.8);
        glVertex2f(17,11);
        glVertex2f(17,10);
    glEnd();
}

void keyboard(unsigned char action,int x,int y)
{
    switch(action)
    {   case 8: out--;
        if(out<0){
            out = 0;
        }
        break;
        case 13:out++;
            if(out==5){
               out=0;
            }
                break;
        case 27:out = 0;
        break;

    }
}





void myinit()
{
    glClearColor(0.1f,0.1f,0.1f,0.1f);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,999.0,0.0,799.0);

}

void menu (int option)
{
 if(option==1)
 flag=1; // rotate around origin
 if(option==2)
 flag=2; // rotate around customer's coordinates

}

void myReshape(int w, int h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w<=h){
     glOrtho (-2, 2, -2*(GLfloat)h/(GLfloat)w, 2*(GLfloat)h / (GLfloat)w, -10, 10);
 }

 else{
     glOrtho (-2*(GLfloat)w/(GLfloat)h, 2*(GLfloat)w / (GLfloat)h, -2, 2, -10, 10);
    glMatrixMode(GL_MODELVIEW);
 }

}

int main(int argc, char *argv[])
{
    srand(1);
    initRain();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1024.0,768.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("titanic ship");
   // glutReshapeFunc(myReshape);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    myinit();
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu);
    glutAddMenuEntry("Rainy Night",1);
    glutAddMenuEntry("Day light",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutTimerFunc(100,update,0);
    glutMainLoop();

}
