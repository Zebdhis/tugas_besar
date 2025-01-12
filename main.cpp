#include <GL/glut.h>
#include <math.h>

float Xpos = 0.0, Ypos = 0.0, xpos = 0.0, ypos = 0.0;
float aspect;
float angle = 0.0;
float scaleFactor = 1.0f; // Faktor zoom
float scaleStep = 0.1f;
int windows[10];
int size = 0;
bool hidden = false;
bool rotationEnabled = false;
GLfloat light_position[4] = { 1.0f, 1.0f, 1.0f, 0.0f };


void addWindows(const char *title, void (displayCallback)(void));
void firstWindows();
void secondWindows();
void thirdWindows();
void hiddenCarte();
void inisialisasi();
void satu();

// Abizar
// Fungsi untuk menggambar silinder
void drawCylinder(GLfloat radius, GLfloat height) {
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    
    // Menggambar silinder
    gluCylinder(quadric, radius, radius, height, 32, 32);
    
    gluDeleteQuadric(quadric);
}

// ABIZAR
void drawCartesius(){
	glLineWidth(1.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	
	glVertex3f(-50.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	
	glVertex3f(0.0, -50.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	
	glVertex3f(0.0, 0.0, -50.0);
	glVertex3f(0.0, 0.0, 50.0);
	glEnd();
}

//ABIZAR
void Dumbell(){
	
	glColor3f(0.3, 0.3, 0.3); 
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -3.0f); // Pindah ke posisi pegangan
    drawCylinder(0.3f, 6.0f); // Radius dan tinggi pegangan
    glPopMatrix();
    
    // Gambar disk di kiri
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -1.2f); // Pindah ke kanan
    glutSolidTorus(0.5, 1.0, 30, 10);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -1.8f); // Pindah ke kanan
    glutSolidTorus(0.5, 0.8, 30, 10); // Gambar disk
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -2.1f); // Pindah ke kiri
    glutSolidTorus(0.6, 0.5, 30, 10); // Gambar disk
    glPopMatrix();

    // Gambar disk di kanan
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.2f); // Pindah ke kanan
    glutSolidTorus(0.5, 1.0, 30, 10);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.8f); // Pindah ke kanan
    glutSolidTorus(0.5, 0.8, 30, 10); // Gambar disk
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.1f); // Pindah ke kiri
    glutSolidTorus(0.6, 0.5, 30, 10); // Gambar disk
    glPopMatrix();
}

//ABIZAR
void drawMatras() {
	
	glColor3f(0.8f, 0.8f, 0.8f); 
  	glPushMatrix();
  	glScalef(18.0f, -0.5f, 18.0f);
 	glTranslatef(0.0f, 2.0f, 0.0f); 
  	glutSolidCube(1.0f); 
  	glPopMatrix(); 
  	
  	glColor3f(0.1f, 0.1f, 0.1f); 
  	glPushMatrix();
  	glScalef(4.0f, -0.1f, 10.0f);
 	glTranslatef(0.0f, 2.0f, 0.0f); 
  	glutSolidCube(1.0f); 
  	glPopMatrix(); 
	
	glEnd();
}

//ABIZAR
void thirdWindows(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	
	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(45.0f, 0.0f, 2.0f, 0.0f);
	glTranslatef(-7.0f, 0.0f, -3.0f);
	Dumbell();
    glPopMatrix();
    
    glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(45.0f, 0.0f, 2.0f, 0.0f);
	glTranslatef(-7.0f, 0.0f, -10.0f);
	Dumbell();
    glPopMatrix();
    
    // BARBEL BESAR
   	glPushMatrix();
	glScalef(0.7f, 0.7f, 0.7f);
	glRotatef(180.0f, 0.0f, 2.0f, 0.0f);
	glTranslatef(-1.5f, Ypos, -9.0f);
	
	glColor3f(0.3, 0.3, 0.3); 
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -3.2f); // Pindah ke posisi pegangan
    drawCylinder(0.3f, 10.0f); // Radius dan tinggi pegangan
    glPopMatrix();
    
    // Gambar disk di kiri
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -1.4f); // Pindah ke kanan
    glutSolidTorus(0.6, 1.0, 30, 10);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -2.0f); // Pindah ke kanan
    glutSolidTorus(0.6, 1.0, 30, 10); // Gambar disk
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -2.5f); // Pindah ke kiri
    glutSolidTorus(0.3, 0.4, 30, 10); // Gambar disk
    glPopMatrix();

    // Gambar disk di kanan
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 4.8f); // Pindah ke kanan
    glutSolidTorus(0.6, 1.0, 30, 10);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 5.6f); // Pindah ke kanan
    glutSolidTorus(0.6, 1.0, 30, 10);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 6.0f); // Pindah ke kiri
    glutSolidTorus(0.3, 0.4, 30, 10); // Gambar disk
    glPopMatrix();
    glPopMatrix();
    
    
    glRotatef(Xpos, 0.0, 1.0, 0.0);
    drawMatras();
    
	inisialisasi();
	hiddenCarte();
	glutSwapBuffers();
	glutPostRedisplay();
}


// NADHIEF
void secondWindows(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//
	satu();
	
	hiddenCarte();

    glPushMatrix();// menyimpan transformasi saat ini
	glColor3ub(128, 128, 128);//warna abu-abu
    glTranslatef(xpos, 2.8f, 0.0f);// Menggeser sistem koordinat
    if (rotationEnabled) {
        glRotatef(angle, 0, 1, 1);
    }
    glutSolidSphere(5, 20, 20);
    glPopMatrix();
    
    
  	glPushMatrix();
  	glColor3ub(34, 139, 34);//warna hijau
  	glScalef(18.0f, -0.5f, 18.0f);//mengubah skala(ukuran)
 	glTranslatef(0.0f, 2.0f, 0.0f);
	if (rotationEnabled) {
        glRotatef(angle, 0, 1, 0);
    }
  	glutSolidCube(1.5f); 
  	glPopMatrix(); 

    glutSwapBuffers();
    glutPostRedisplay();
    
    angle += 0.1;
}

//DESTIAN
void drawHighJumpPole() {
    GLUquadric* quadric = gluNewQuadric();  // Membuat objek kuadrik

    // Tiang lompat tinggi (batang tongkat)
    glColor3f(0.0f, 0.0f, 1.0f);  // Warna biru
    glPushMatrix();
    glTranslatef(3.0f, 1.0f, -4.0f);  // Posisi dasar tiang
    glScalef(0.5f, 0.5f, 3.0f);  // Membuat bentuk tiang (tinggi dan bulat)
    gluCylinder(quadric, 0.5f, 0.5f, 6.0f, 32, 32);  // Membuat silinder (tiang lompat tinggi)
    glPopMatrix();

    

    gluDeleteQuadric(quadric);  // Menghapus objek kuadrik
}

//DESTIAN
void firstWindows(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	hiddenCarte();
	glPushMatrix();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	inisialisasi();
	glScalef(scaleFactor, scaleFactor, 1.0f);
	glTranslatef(0.0f, 1.0f, ypos);  // Geser tiang lompat tinggi
    drawHighJumpPole();  // Menggambar tongkat lompat tinggi
    
	glPopMatrix();
	glutSwapBuffers();
	glutPostRedisplay();
}


void reshape(int w, int h){
		if (h == 0)
			h = 1;
		aspect = (float)w / (float)h;
	
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70.0, aspect, 1.0, 100.0);
		gluLookAt(10.0, 10.0, 17.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}

//Nadhief
void satu(){
	GLfloat light_ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[4] = { 4.5f, 10.0f, 5.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);//cahaya sekitar
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);//cahaya menyebar
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);//cahaya pantulan
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//posisi cahaya
	glEnable(GL_LIGHT0);// Mengaktifkan sumber cahaya GL_LIGHT0
	glEnable(GL_LIGHTING); // Mengaktifkan sistem pencahayaan global
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.1, 0.1, 0.1, 1.0);
}

//DESTIAN
void inisialisasi(){
	GLfloat light_ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.1, 0.1, 0.1, 1.0);
}

//ABIZAR
void addWindows(const char *title, void (displayCallback)(void))
{
	windows[size++] = glutCreateWindow(title);
	glutDisplayFunc(displayCallback);
}


//ABIZAR
void hiddenCarte()
{
if(hidden)
 {
 drawCartesius();
 }
}

//ABIZAR
void myKeyboard(unsigned char key , int x, int y){
	switch (key){
	case 'q':
		for (int i = 0; i < size; i++)
		{
			glutDestroyWindow(windows[i]);
		}
		break;
	case 'h':
		hidden = !hidden;
		break;
	case 'a':
		Xpos += 0.01;
		break;
	case 'd':
		Xpos -= 0.01;
		break;
	case 'w':
		Ypos += 1.0;
		break;
	case 's':
		Ypos -= 1.0;
		break;
	}
}
//Nadhief
void mykeyboard(unsigned char key , int x,int y){
	switch (key){
	case 'q':
		for (int i = 0; i < size; i++)
		{
			glutDestroyWindow(windows[i]);
		}
		break;
	case 'j':
		xpos -= 1.0;
		break;
	case 'l':
		xpos += 1.0;
		break;
	case 'k': // Hentikan atau lanjutkan rotasi
        rotationEnabled = !rotationEnabled;
        break;
    case 'i':
    	hidden = !hidden;
    	break;
	}
}

//DESTIAN
void keyboard(unsigned char key , int x,int y){
	switch (key){
	case 'q':
		for (int i = 0; i < size; i++)
		{
			glutDestroyWindow(windows[i]);
		}
		break;
	case '=': // Zoom in
        scaleFactor += scaleStep;
        break;
    case '-': // Zoom out
        scaleFactor -= scaleStep;
        if (scaleFactor < 0.1f) scaleFactor = 0.1f; // Hindari nilai negatif atau terlalu kecil
        break;
    case 'o':
		ypos -= 1.0;
		break;
	case 'p':
		ypos += 1.0;
		break;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	//ABIZAR
	glutInitWindowSize(500,400);
	glutInitWindowPosition(440, 150);
	addWindows("Abizar Algifari", thirdWindows);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(myKeyboard);
	//Nadhief	
	glutInitWindowSize(400,400);
	glutInitWindowPosition(30, 150);
	addWindows(" Muhammad Nadhief R F", secondWindows);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(mykeyboard);
	//DESTIAN
	glutInitWindowSize(400,400);
	glutInitWindowPosition(950, 150);
	addWindows("Destian", firstWindows);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}
