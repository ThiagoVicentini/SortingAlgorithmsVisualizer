#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

float w = 500, h = 500;

void init(){
    glClearColor(0, 0, 0, 1);
}

void reshape(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void display(){ 
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw

    glutSwapBuffers();
};

void keyboard(unsigned char key, int x, int y){
    // Manage key
    glutPostRedisplay();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("Sorting Visualizer");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}