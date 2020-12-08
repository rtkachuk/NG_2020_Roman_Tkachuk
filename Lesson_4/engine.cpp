// Привет! Приятно видеть, что студенты интересуются разработкой чего-то более
// интересного на С++ с использованием графики :)
// Я решил вам немного помочь в этом, и написал простейший движок на opengl,
// который поможет вам написать хоть что-то более интересное, чем
// скучные консольные приложения :)
//

// Здесь мы подключаем библиотеки, которые будем использовать в работе :)
// Если у вас Linux на базе Ubuntu - установите их с помощью:
//
// sudo apt-get update
// sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
//
// Если вы верный фанат Fedora или какого-либо другого RedHat-подобного дистрибутива,
// тогда используйте yum или dnf!
//
// sudo yum install freeglut-devel    <--- для yum (centos, etc)
// sudo dnf install freeglut-devel    <--- для dnf (fedora :3)
//
// Если же вы используете source-based дистрибутивы, тогда покажу вам на примере
// gentoo:
//
// sudo emerge freeglut
//
// Помните: в случае каких-либо проблем, можете писать мне в любое время суток :3
// Единственное: с 3 до 4 часов ночи я могу отвечать с большой задержкой :)

// Как компилять:
// g++ engine.cpp -lglut -lGLU -lGL -o game
// Запускать:
// ./game

// Вот и всё, не сложно :)

#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;

// Здесь интересная штука: вы можете менять размер окошка, в котором будете
// рисовать :)
// ВАЖНО: изменяйте его именно здесь, ибо в противном случае - некоторые функции
// поломаются :(

struct color {
  double R;
  double G;
  double B;
};

// Цвета! В формате RGB!
//
// RGB - от Red (красный), Green (зелёный), и Blue (синий)
//
// Собственно, три цифры подряд формируют особенный цвет. Каждая цифра - это значение с запятой: вы можете указать, сколько именно
// какого цвета будет в вашем новом цвете :)
// К примеру: что за цвет { 0.5, 0, 0.33 } ? Или может быть { 0.001, 0.33, 1 } ? Не проверишь - не узнаешь :)
//

static color red = { 1, 0, 0 };
static color blue = { 0, 0, 1 };
static color green = { 0, 1, 0 };
static color yellow = { 1, 1, 0 };
static color turquoise = { 0, 1, 1 };
static color white = { 1, 1, 1 };
static color black = {0, 0, 0};
static color orange = {1, 0.6, 0.21};

static int windowWidth=600; // ширина в пикселях
static int windowHeigth=600; // высота в пикселях

// Я оставлю здесь парочку переменных для примера с анимацией :)

int animationStartX=300;
int animationStartY=300;

// А здесь есть парочка переменных для кубика, который мы сможем двигать с помощью wasd!!!!!!

int controlledStartX=100;
int controlledStartY=400;

// Здесь есть набор функций, которые вы можете использовать для рисовашек :)
//

// Нарисовать квадрат. Цветной квадрат :)
// leftUpperX - левый верхний пиксель по X
// leftUpperY - левый верхний пиксель по Y
// rightBottomX - правый нижний пиксель по X
// rightBottomY - правый нижний пиксель по Y
// squareColor - цвет, обозначенный выше :)
void drawSquare (double leftUpperX, double leftUpperY, double rightBottomX, double rightBottomY, color squareColor);

// Нарисовать линию.
// startX - x начальной точки
// startY - y начальной точки
// endX - x конечной точки
// endY - y конечной точки
// lineColor - цвет линии :)
void drawLine (double startX, double startY, double endX, double endY, color lineColor);

// Вот функция, в которой вы можете рисовать всё, что угодно :)
// Помимо того кода, который мы разучиваем на занятиях - вы можете без каких-либо
// проблем использовать функции, описанные выше. Это разнообразит ваш опыт, и
// позволит учится писать куда более интересные и стоющие вещи :3
//

void userInput() {

  // Для примера я нарисую квадратик :)
  //

  drawSquare(50, 50, 100, 100, orange); // левый верхний угол

  // А вот десять квадратиков :)
  //

  for (int i=0; i<10; i++)
    drawSquare(0 + i*10, 110, 5 + i*10, 115, red);

  // рисуем линию :)

  drawLine (230, 400, 500, 500, black);

  // А здесь я нарисую квадратик, который будет бегать от нас :)

  drawSquare(animationStartX, animationStartY, animationStartX+50, animationStartY+50, blue);

  animationStartX++;

  if (animationStartX >= windowWidth - 50)
    animationStartX = 0;

  // А вот квадратик, который можно двигать с помощью wasd! попробуйте сами :)

  drawSquare(controlledStartX, controlledStartY, controlledStartX+50, controlledStartY+50, green);

  // А тут пример кру... Ой, его нет :-0
  // Боюсь, вам нужно сделать это самим. Думаю, вам хватит и функции drawLine для этого :)
  //
}

// Тут идут крайне интересные функции, которые позволяют вам запускать код по нажатию на определённую клавишу :-()
// Я для примера взял несколько классических кнопок, которые уже вы можете использовать в своих проектах :)

// Как они работают? Для вас я написал простой пример кубика, который мы можем двигать с помощью wasd. Для вас не будет большой проблемой
// понять: какая функция за какую кнопку отвечает :)

void returnClicked() {};   // Что будет, если мы нажмём Enter?
void spaceClicked() {};    // А если пробел?
void escapeClicked() {};   // А если Escape??????
void wClicked() { controlledStartY--; }; // Воу, если нажимаем w - мы куда-то двигаемся...
void sClicked() { controlledStartY++; }; // И если s тоже ....
void aClicked() { controlledStartX--; }; // .....
void dClicked() { controlledStartX++; }; // ;)


// Ниже вам ничего читать не обязательно, хотя если интересно - почему бы и нет :)
//

void handleKeypress(unsigned char key, int x, int y)
{

  // Здесь представлена самая интересная часть кода, которая учит наш код работать с разными клавишами!
  // Вы можете посмотреть: как я посоздавал функции, и как я их тут назначаю :)

  switch(key)
    {
    case 'a':
      aClicked();
      break;
    case 'd':
      dClicked();
      break;
    case 's':
      sClicked();
      break;
    case 'w':
      wClicked();
      break;
    case 13:
      returnClicked();
      break;
    case 32:
      spaceClicked();
      break;
    case 27:
      escapeClicked();
      break;
    default:
      cout << "Странно, я не знаю о такой кнопке: " << (int)key << endl;
    }
}

// Данная функция динамически переводит координаты по пикселям (скажем, я хоч
// нарисовать точку по X на 450. Но есть незадача: как по x, так и по y - opengl
// понимает значения от -1 до 1. Чтобы сделать задачу проще, и не мучить вас
// высчитыванием координат, я написал такую функцию.
//

double convertX(double xPos) {
  // Некоторые вещи я сразу же возведу в константы - так будет проще понимать.
  //

  static double oneHundredPercents = 100;
  static double valueForDataConvertion = 1;
  static double overallScreenSize = 2;
  // Сначала, нам нужно найти 1% от ширины экрана. Т.е. если ширина у нас
  // 600 пикселей, то 1% - это 6 пикселей.
  //
  double onePerCentOfWindowWidth = windowWidth / oneHundredPercents;
  // После этого, нам нужно высчитать: сколько процентов занимает наше число?
  // К примеру, если мы закинули сюда число 300 (тип, середина экрана), это значит,
  // что 300/6, и мы получим 50% - это как раз ровно половина экрана :)
  //
  double howManyPercentsInOurValue = double(xPos) / onePerCentOfWindowWidth;
  // Теперь высчитываем значение, которое сможет понять opengl! А это
  // (2 / 100) * 5 - 1. Сложно? Да. Откуда 2: это вся ширина экрана, которая
  // понятна opengl (от -1 до 1). Как только мы делим её на 100 - получаем 1% от
  // всей ширины, понятной opengl, т.е. 0.02. После этого умножаем на 50% - именно
  // столько мы указали в прошлом уравнении. Всё, что нам осталось - отнять 1, чтобы
  // диапазон от 0 до 2 превратить от -1 до 1. 50 * 0.02 получится 1. Если мы
  // отнимем от 1 единицу - получим 0. А 0 - это как раз середина между -1 и 1.
  // Если это непонятно - пишите, расскажу отдельно вам :)
  //
  double actualPos = (overallScreenSize / oneHundredPercents) * howManyPercentsInOurValue - valueForDataConvertion;
  return actualPos;
}

// То же самое, что и выше, но для Y. Можете посмотреть на код без комментариев :)
//

double convertY(double yPos) {
  static double oneHundredPercents = 100;
  static double valueForDataConvertion = 1;
  static double overallScreenSize = 2;
  double onePerCentOfWindowHeigth = windowHeigth / oneHundredPercents;
  double howManyPercentsInOurValue = double(yPos) / onePerCentOfWindowHeigth;
  double actualPos = (overallScreenSize / oneHundredPercents) * howManyPercentsInOurValue - valueForDataConvertion;
  return actualPos;
}

// Отрисовка нашего квадратика. Здесь нам нужно проявить небольшую изобретательность,
// так как сам квадратик мы рисуем по пикселям :)

void drawSquare(double leftUpperX, double leftUpperY, double rightBottomX, double rightBottomY, color squareColor) {
  glBegin(GL_POLYGON);
  glColor3f(squareColor.R, squareColor.G, squareColor.B); // цвет выбранный нами :) Цвета описаны выше.

  // Просим нашу функцию-переводчик перевести нам понятные пиксели, в понятные
  // для opengl значения. Проблем быть не должно :)
  //

  double actualLeftUpperX = convertX(leftUpperX);
  double actualLeftUpperY = convertY(windowHeigth-leftUpperY);
  double actualRightBottomX = convertX(rightBottomX);
  double actualRightBottomY = convertY(windowHeigth-rightBottomY);

  glVertex3f(actualLeftUpperX, actualLeftUpperY, 0.0);
  glVertex3f(actualRightBottomX, actualLeftUpperY, 0.0);
  glVertex3f(actualRightBottomX, actualRightBottomY, 0.0);
  glVertex3f(actualLeftUpperX, actualRightBottomY, 0.0);
  glEnd();
}

void drawLine (double startX, double startY, double endX, double endY, color lineColor) {
  glBegin(GL_LINES);
  glColor3f(lineColor.R, lineColor.G, lineColor.B); // цвет выбранный нами :) Цвета описаны выше.

  double actualStartX = convertX(startX);
  double actualEndX = convertX(endX);
  double actualStartY = (convertY(windowHeigth-startY));
  double actualEndY = (convertY(windowHeigth-endY));

  glVertex3f(actualStartX, actualStartY, 0.0);
  glVertex3f(actualEndX, actualEndY, 0.0);
  glEnd();
}

// Следующие три функции используются для того, чтобы отрисовать основное окно.
// мы их используем каждый раз, когда отрисовываем новый кадр :)
//

void preDisplay() {
  glLoadIdentity();
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);//RGBA
  glMatrixMode(GL_PROJECTION);
}

void postDisplay() {
  glFlush();
  glutPostRedisplay();
}

void display(void)
{
  preDisplay();
  userInput();
  postDisplay();
}

// Здесь лежат настройки нашего окошка :)
// К примеру, glutCreateWindow - это заголовок нашего окошка, а glutInitWindowSize
// хранит информацию о нашем экране :O, а именно - о размере :)
//

void init(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(windowWidth, windowHeigth);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Engine");
  glutDisplayFunc(display);
  glutKeyboardFunc(handleKeypress);
}

// О, а вот и наш main... он нам не нужен :3
//

int main(int argc, char** argv)
{
  init(argc, argv);
  glutMainLoop();
}
