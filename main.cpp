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
float offset = 10;

void normalize(float &x1, float &y1, float &x2, float &y2){
    x1 = 2*x1 / w - 1;
    y1 = 2*y1 / h - 1;

    x2 = 2*x2 / w - 1;
    y2 = 2*y2 / h - 1;

    float scale = 9.9;
    x1 *= scale;
    y1 *= scale;
    x2 *= scale;
    y2 *= scale;
}

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

void showArray(){
    float x1, y1, x2, y2;
    for(int i=0; i<(int)_array.size(); i++){
        x1 = i + offset;
        y1 = 0;
        x2 = i + offset;
        y2 = _array[i].value;
        normalize(x1, y1, x2, y2);

        float r = _array[i].color[0];
        float g = _array[i].color[1];
        float b = _array[i].color[2];
        glColor3f(r, g, b);
        glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        glEnd();
    }
}

void display(){ 
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    showArray();

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