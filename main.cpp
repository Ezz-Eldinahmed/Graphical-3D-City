#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <windows.h>  // for MS Windows
#include<glut.h>
using namespace std;

static int slices = 16;
static int stacks = 16;

float xr = 0, yr = 0;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    const double b = t*0.9;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20,20,-20,20,-50,50);


    if(xr>=45){
        xr--;
    }
    else if(xr<-30){
        xr++;
    }

    //السماء
    glPushMatrix();
    glColor3d(0,0.8,0.9);
    glTranslated(0,15,-40);
    glScaled(2,1,1);
    glutSolidCube(20);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0,0.9,0);
    glTranslated(0,-10,-40);
    glScaled(2,1.5,1);
    glutSolidCube(20);
    glPopMatrix();

    // رصيف
    glPushMatrix();
    glColor3d(1,0.4,0.2);
    glTranslated(0,-12.5,-20);
    glRotated(-10,1,1,0);
    glScaled(3,2,0.2);
    glutSolidCube(6);
    glPopMatrix();

    //مبني
    glPushMatrix();
    glColor3d(0.1,0.9,1);
    glRotated(-30,1,0,0);
    glRotated(30,0,0,1);
    glScaled(1,1,2);
    glTranslated(-4,-16,1);
    glutSolidCube(5);

    glPopMatrix();

    // town
    //مبني
    glPushMatrix();
    glColor3d(0.3,0.4,1);
    glRotated(-30,1,0,0);
    glTranslated(15,-16,0);
    glScaled(2,2,5);
    glutSolidCube(2);
    glPopMatrix();

        //مبني
    glPushMatrix();
    glColor3d(0.3,0.8,1);
    glRotated(-30,1,0,0);
    glTranslated(15,-10,0);
    glScaled(2,2,5);
    glutSolidCube(2);
    glPopMatrix();

            //مبني
    glPushMatrix();
    glColor3d(0.8,0.8,1);
    glRotated(-30,1,0,0);
    glTranslated(15,7,0);
    glScaled(2,2,5);
    glutSolidCube(2);
    glPopMatrix();

    //مبني
    glPushMatrix();
    glColor3d(1,0,0.3);
    glRotated(-30,1,0,0);
    glTranslated(-6.5,8.3,0);
    glRotated(40,0,0,1);
    glScaled(2,2,8);
    glutSolidCube(2);
    glPopMatrix();

        //مبني
    glPushMatrix();
    glColor3d(1,0.8,0.3);
    glRotated(-30,1,0,0);
    glRotated(-40,0,0,1);
    glTranslated(-4.5,7.5,0);
    glScaled(2,2,8);
    glutSolidCube(2);
    glPopMatrix();

    //مبني
    glPushMatrix();
    glColor3d(0.3,0.8,0.3);
    glRotated(-30,1,0,0);
    glRotated(-10,0,0,1);
    glTranslated(8,10,0);
    glScaled(2.5,2,8);
    glutSolidCube(2);
    glPopMatrix();

        //مبني
    glPushMatrix();
    glColor3d(0.2,0,0.3);
    glRotated(-30,1,0,0);
    glTranslated(-15.5,7,0);
    glScaled(4,2,8);
    glutSolidCube(2);
    glPopMatrix();


    //مبني
    glPushMatrix();
    glColor3d(1,0,0);
    glRotated(-30,1,0,0);
    glRotated(30,0,0,1);
    glScaled(2,2,4);
    glTranslated(-12,-3,0);
    glutSolidCube(2);
    glPopMatrix();

        //مبني
    glPushMatrix();
    glColor3d(1,1,0);
    glScaled(2,2,4);
    glTranslated(-9,-5,0);
    glRotated(-30,1,0,0);
    glRotated(30,0,0,1);
    glutSolidCube(2);
    glPopMatrix();

    //مبني
    glPushMatrix();
    glColor3d(0.7,1,1);
    glRotated(-30,1,0,0);
    glRotated(30,0,0,1);
    glScaled(2,2,6);
    glTranslated(-9,-3,0);
    glutSolidCube(2);
    glPopMatrix();

    //القطار عربيه اولي
    glColor3d(0,0.1,0.51);
    glPushMatrix();
    glTranslated(-7+xr,-5,0);
    glRotated(-20,0,1,0);
    glScaled(4,1.5,1.2);
    glutSolidCube(2);
    glPopMatrix();

    //تانيه عربيه اولي
    glColor3d(0,0.1,0.51);
    glPushMatrix();
    glTranslated(-16+xr,-5,0);
    glRotated(-20,0,1,0);
    glScaled(4,1.5,1.2);
    glutSolidCube(2);
    glPopMatrix();

    // wheels القطار
    glColor3d(0.8,0.2,0);
    glPushMatrix();
    glTranslated(-9.5+xr,-6.3,0);
    glRotated(-50,0,1,0);
    glRotated(a,0,0,1);
    glRotated(-13,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    // wheels القطار
    glColor3d(0.8,0.2,0);
    glPushMatrix();
    glTranslated(-13+xr,-6.3,5);
    glRotated(-50,0,1,0);
    glRotated(a,0,0,1);
    glRotated(-7,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    // wheels القطار
    glColor3d(0.8,0.2,0);
    glPushMatrix();
    glTranslated(-19+xr,-6.3,5);
    glRotated(-50,0,1,0);
    glRotated(a,0,0,1);
    glRotated(-10,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    // wheels القطار
    glColor3d(0.8,0.2,0);
    glPushMatrix();
    glTranslated(-5+xr,-6.3,5);
    glRotated(-50,0,1,0);
    glRotated(a,0,0,1);
    glRotated(-10,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //شبباك القطر
    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-4.6+xr,-4,5);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    //شبباك القطر
    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-18.5+xr,-4.5,5);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    //شبباك القطر
    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-14+xr,-4.5,5);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    //شبباك القطر
    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-9+xr,-4.5,5);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    //شبباك القطر
    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-3.3+xr,-4,5);
    glRotated(-90,0,1,0);
    glutSolidCube(1);
    glPopMatrix();

    //نور القطر
    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-3+xr,-5.2,5);
    glutSolidCube(0.3);
    glPopMatrix();

    //paaap1
    glColor3d(0.4,0.4,0.4);
    glPushMatrix();
    glTranslated(-16.2+xr,-4.8,5);
    glScaled(1,2.2,0.1);
    glutSolidCube(1);
    glPopMatrix();

    //paaap
    glColor3d(0.4,0.4,0.4);
    glPushMatrix();
    glTranslated(-6.5+xr,-4.8,5);
    glScaled(1,2.2,0.1);
    glutSolidCube(1);
    glPopMatrix();

    // s2af1
    glColor3d(1,0.1,0.2);
    glPushMatrix();
    glTranslated(-6.5+xr,-3.5,6);
    glRotated(80,1,0,0);
    glScaled(3.5,1,0.2);
    glutSolidCube(1);
    glPopMatrix();

    // s2af2
    glColor3d(1,0.1,0.2);
    glPushMatrix();
    glTranslated(-16.4+xr,-3.5,6);
    glRotated(80,1,0,0);
    glScaled(3.5,1,0.2);
    glutSolidCube(1);
    glPopMatrix();

    //بشر
    for(int i=0; i<7; i++)
    {
        glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-2.5-i,-14+i,-1);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glutSolidCone(0.1,0.5,slices,stacks);
        glPopMatrix();
        //بشر

        glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-7+i,-17+i,-1);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glutSolidCone(0.1,0.5,slices,stacks);

        glPopMatrix();
    }
    for(int i=0; i<3; i++)
    {
        //بشر
        glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-6+i,-12+i,-1);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glutSolidCone(0.1,0.5,slices,stacks);
        glPopMatrix();

        //بشر
        glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-7+i,-10+i,-1);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glutSolidCone(0.1,0.5,slices,stacks);
        glPopMatrix();

        //بشر
        glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-1+i,-9+i,-1);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glutSolidCone(0.1,0.5,slices,stacks);
        glPopMatrix();
    }

    //tree1
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(5.5,3.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(5.5,2.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

        //tree2
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(-2.5,3.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(-2.5,2.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

    //tree3
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(19,3.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(19,2.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

    //tree4
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(-10,3.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(-10,2.5,-1);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

        //tree5
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(-10,-8,5);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(-10,-9,16);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

    //tree6
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(19,-8,5);
    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glutSolidCone(1,3,slices,stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.8,0.4,0);
    glTranslated(19,-9,16);

    glRotated(90,0,0,1);
    glRotated(45,0,1,0);
    glRotated(15,1,0,0);
    glScaled(5,0.5,1);
    glutSolidCube(0.3);
    glPopMatrix();

    //قضبان
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(-10,-3,-2);
    glScaled(150,0.4,1);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(-10,-2,-2);
    glScaled(150,0.4,1);
    glutSolidCube(0.5);
    glPopMatrix();

    //قضبان
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(-9,-5,-2);
    glScaled(150,0.4,1);
    glutSolidCube(0.5);
    glPopMatrix();

    //قضبان
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(-9,-6,-2);
    glScaled(150,0.4,1);
    glutSolidCube(0.5);
    glPopMatrix();

    //street
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(-9,0,-7);
    glScaled(150,3,1);
    glutSolidCube(1);
    glPopMatrix();

    for(int i=-10;i<35;i+=2){
    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-12+i,0,-5);
    glScaled(3,1,1);
    glutSolidCube(0.5);
    glPopMatrix();
    }

        //street
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(11,-15,-5);
    glScaled(3,27,1);
    glutSolidCube(1);
    glPopMatrix();

    for(int i=0;i<19;i+=2){
    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(11,-19.5+i,-2);
    glScaled(1,3,1);
    glutSolidCube(0.5);
        glPopMatrix();
    }
    //plane
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(-10+b,17-b,30);
    glScaled(8,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(-13.6+b,17-b,30);
    glRotated(90,0,0,1);
    glScaled(0.4,0.6,1);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(-6+b,17-b,32);
    glRotated(90,0,1,0);
    glScaled(2,0.5,0.5);
    glutSolidCone(1,2,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(-10+b,17-b,30);
    glRotated(90,0,1,0);
    glRotated(5,0,1,0);
    glutSolidCone(5,2,50,50);
    glPopMatrix();

    //car
    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(-15+b,0,6);
    glRotated(30,0,1,0);
    glRotated(-20,0,1,0);
    glRotated(20,1,0,0);
    glScaled(4,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(-15+b,1,6);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-15.8+b,-0.4,10);
    glRotated(a,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-13.8+b,-0.4,10);
    glRotated(a,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //car
    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(-7+b,0,6);
    glRotated(40,0,1,0);
    glRotated(-20,0,1,0);
    glRotated(20,1,0,0);
    glScaled(4,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-7+b,0.8,8);
    glScaled(1.5,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(-7+b,1,6);
    glScaled(2,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-7.8+b,-0.4,10);
    glRotated(a,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(-5.8+b,-0.4,10);
    glRotated(a,0,0,1);
    glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(-15+b,0.8,8);
    glScaled(1.5,1,1);
    glutSolidCube(1);
    glPopMatrix();

//    //sun
//    glPushMatrix();
//    glColor3d(1,0.4,0);
//    glTranslated(-10,18,-30);
//    glutSolidSphere(1,50,50);
//    glPopMatrix();

        //car
    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(10,-8-b,4);
    glRotated(30,1,0,0);
    glRotated(-90,1,0,0);
    glRotated(-90,0,0,1);
    glScaled(1,0.6,1);
    glutSolidCube(2);
    glPopMatrix();

    glColor3d(0.9,1,0);
    glPushMatrix();
    glTranslated(10,-8.3-b,10);
    glRotated(40,1,0,0);
    glRotated(-90,1,0,0);
    glRotated(-90,0,0,1);
    glScaled(0.3,1,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(10,-9.5-b,9);
    glRotated(40,1,0,0);
    glRotated(-90,1,0,0);
    glRotated(-90,0,0,1);
    glScaled(1,0.6,0.5);
    glutSolidCube(2);
    glPopMatrix();

    glutSwapBuffers();

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case '+':
        slices++;
        stacks++;
        break;

    case '-':
        if (slices>3 && stacks>3)
        {
            slices--;
            stacks--;
        }
        break;
    }

    glutPostRedisplay();
}

void specialkey(int key,int x,int y)
{

    switch(key)
    {

    case GLUT_KEY_UP:
        yr++;
        cout<<y<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        yr--;
        cout<<y<<endl;
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
        xr--;
        cout<<x<<endl;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        xr++;
        cout<<x<<endl;
        glutPostRedisplay();
        break;
    }
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutSpecialFunc(specialkey);

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
