#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <vector>
#include <time.h>

using namespace std;

struct Line{
    float value;
    vector<float> color;
};

bool sortLine(const Line& l1, const Line& l2)
{
   return l1.value < l2.value;
}

vector<Line> _array(480, {0, {1, 0, 0}});

float w = 500, h = 500;
float LO = 0.0, HI = 480.0;

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
    
    srand((unsigned) time(NULL));
    for(int i=0; i<(int)_array.size(); i++){
        _array[i].value = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        _array[i].color = {1, 0, 0};
    }

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