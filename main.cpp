#include <iostream>
#include <unistd.h>
#include <fstream>
#include "game/eatable/Fruit.h"
#include "game/eatable/Poison.h"
#include "game/map/Wall.h"
#include "game/snake/SnakeHead.h"
#include "game/snake/SnakeTail.h"
#include "game/map/ImmuneWall.h"
#include "game/map/Gate.h"

bool gameOver;
const int width = 30;
const int height = 30;
int score;
Fruit *fruit;
Poison *poison;
Object *map[width][height];
SnakeTail *snakeTails[100];
SnakeHead *snakeHead;
bool passingGate = false;
int timeAfterPassingGate = 0;
Gate *gates[2];
int nGate = 0;
Wall walls[300];
int nWall = 0;
int hx, hy;
int nTail = 0;
Direction dir;
int inputDelay = 1;
int gameTime = 0, fruitTime = 0, poisonTime = 0, gateTime = 100;
int maxEatableTime = 50;
int chosenLevel = 0;

using namespace std;

void setup();

void createMap();

void draw();

void input();

void logic();

void snakeMove(int beforeX, int beforeY, int newX, int newY, int prevHx, int prevHy);

void updateTail(int prevHx, int prevHy, bool eatFruit);

void deleteObject(int x, int y);

void chooseMap();

int chooseMapInput();

void createGate();

void gateToWall();

void findGateOutDirectionAndMove(Gate gate);

int main() {
    setup();
    chooseMap();
    createMap();

    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(10000); // Delay for smoother movement
    }

    endwin();

    cout << "Game Over!" << endl;
    cout << "Your score: " << score << endl;

    return 0;
}

void setup() {
    initscr(); // Initialize ncurses
    clear();
    noecho(); // Don't display input characters
    cbreak(); // Disable line buffering, react immediately to input
    curs_set(0); // Hide the cursor

    gameOver = false;
    dir = STOP;

    score = 0;

}

void draw() {
    start_color();

    assume_default_colors(COLOR_WHITE, COLOR_WHITE);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_YELLOW, COLOR_YELLOW);

    clear();
    printw("Level %d\n", chosenLevel);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printw("%c", map[i][j]->draw());
        }
        printw("\n");
    }

    attroff(COLOR_PAIR(0));
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
    attroff(COLOR_PAIR(6));

    // Draw the bottom border
    printw("\n");

    // Display the score
    printw("Score: %d\n", score);
    printw("Press 'x' to exit\n");
    printw("gameTime: %d\n", gameTime);

    refresh();
}

void input() {
    keypad(stdscr, TRUE);
    halfdelay(inputDelay);

    int key = getch();
    switch (key) {
        case KEY_LEFT:
            if (dir == RIGHT) {
                gameOver = true;
            } else {
                dir = LEFT;
            }
            break;
        case KEY_RIGHT:
            if (dir == LEFT) {
                gameOver = true;
            } else {
                dir = RIGHT;
            }
            break;
        case KEY_UP:
            if (dir == DOWN) {
                gameOver = true;
            } else {
                dir = UP;
            }
            break;
        case KEY_DOWN:
            if (dir == UP) {
                gameOver = true;
            } else {
                dir = DOWN;
            }
            break;
        case 'x':
            gameOver = true;
            break;
    }
}

void logic() {
    if (dir == STOP)
        return;

    gameTime++;
    fruitTime++;
    poisonTime++;
    gateTime++;

    if (passingGate) {
        timeAfterPassingGate++;
        if (timeAfterPassingGate > nTail) {
            passingGate = false;
            timeAfterPassingGate = 0;
            gateTime = 101;
        }
    }

    if (fruitTime > maxEatableTime) {
        deleteObject(fruit->getX(), fruit->getY());
        fruit->newPosition(hx, hy, width, height, *snakeTails, nTail);
        map[fruit->getY()][fruit->getX()] = fruit;
        score -= 5;
        fruitTime = 0;
    }

    if (poisonTime > maxEatableTime) {
        deleteObject(poison->getX(), poison->getY());
        poison->newPosition(hx, hy, width, height, *snakeTails, nTail);
        map[poison->getY()][poison->getX()] = poison;
        poisonTime = 0;
    }

    if (gateTime > 100 && !passingGate) {
        gateToWall();
        createGate();
    }

    int prevHx = hx;
    int prevHy = hy;
    switch (dir) {
        case LEFT:
            snakeHead->moveLeft(hx);
            snakeMove(prevHx, prevHy, hx, hy, prevHx, prevHy);
            break;
        case RIGHT:
            snakeHead->moveRight(hx);
            snakeMove(prevHx, prevHy, hx, hy, prevHx, prevHy);
            break;
        case UP:
            snakeHead->moveUp(hy);
            snakeMove(prevHx, prevHy, hx, hy, prevHx, prevHy);
            break;
        case DOWN:
            snakeHead->moveDown(hy);
            snakeMove(prevHx, prevHy, hx, hy, prevHx, prevHy);
            break;
        case STOP:
            break;
    }

}

void createMap() {
    fstream file;
    switch (chosenLevel) {
        case 1:
            file.open("game/map/map1.txt", std::ios::in);
            break;
        case 2:
            file.open("game/map/map2.txt", std::ios::in);
            break;
        case 3:
            file.open("game/map/map3.txt", std::ios::in);
            break;
    }

    int i = 0, j = 0;

    if (file.is_open()) {
        char ch;
        while (file.get(ch)) {
            printw("%c", ch);
            if (j == width) {
                j = 0;
                i++;
            }

            if (i == height) {
                break;
            }

            if (ch == '\n') {
                continue;
            }

            if (ch == ' ') {
                map[i][j] = new Object(j, i);

            } else if (ch == '@') {
                map[i][j] = new ImmuneWall(j, i);

            } else if (ch == '#') {
                walls[nWall] = *new Wall(j, i);
                map[i][j] = new Wall(j, i);
                nWall++;

            } else if (ch == 'F') {
                fruit = new Fruit(j, i);
                map[i][j] = fruit;

            } else if (ch == 'P') {
                poison = new Poison(j, i);
                map[i][j] = poison;

            } else if (ch == 'O') {
                snakeHead = new SnakeHead(j, i);
                map[i][j] = snakeHead;
                hx = snakeHead->getX();
                hy = snakeHead->getY();

            } else if (ch == 'o') {
                snakeTails[nTail] = new SnakeTail(j, i);
                map[i][j] = snakeTails[nTail];
                nTail++;
            }
            j++;
        }

        file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

void snakeMove(int beforeX, int beforeY, int newX, int newY, int prevHx, int prevHy) {
    bool eatFruit = false;
    Object *tmpObject = map[newY][newX];
    map[newY][newX] = map[beforeY][beforeX];

    if (tmpObject->getType() == FRUIT) {
        score += 10;
        fruit->newPosition(hx, hy, width, height, *snakeTails, nTail);
        map[fruit->getY()][fruit->getX()] = fruit;

        eatFruit = true;
        fruitTime = 0;

    } else if (tmpObject->getType() == POISON) {
        score -= 10;

        poison->newPosition(hx, hy, width, height, *snakeTails, nTail);
        map[poison->getY()][poison->getX()] = poison;

        deleteObject(snakeTails[nTail - 1]->getX(), snakeTails[nTail - 1]->getY());
        nTail--;

        if (nTail < 3) {
            gameOver = true;
        }

        poisonTime = 0;

    } else if (tmpObject->getType() == GATE) {
        passingGate = true;
        map[tmpObject->getY()][tmpObject->getX()] = tmpObject;
        Gate outGate = Gate::findOtherGate(*gates, tmpObject);

        snakeHead->moveToGate(outGate, hx, hy);
        findGateOutDirectionAndMove(outGate);

    } else if (tmpObject->getType() == WALL || tmpObject->getType() == SNAKE_TAIL) {
        gameOver = true;

    } else if (tmpObject->getType() == OBJECT) {
    }

    updateTail(prevHx, prevHy, eatFruit);
}

void updateTail(int prevHx, int prevHy, bool eatFruit) {
    int y = snakeTails[0]->getY();
    int x = snakeTails[0]->getX();

    snakeTails[0]->setPosition(prevHx, prevHy);
    map[prevHy][prevHx] = snakeTails[0];

    for (int i = 1; i < nTail; i++) {
        int tmpY = snakeTails[i]->getY();
        int tmpX = snakeTails[i]->getX();

        snakeTails[i]->setPosition(x, y);
        map[y][x] = snakeTails[i];

        y = tmpY;
        x = tmpX;
    }

    if (eatFruit) {
        snakeTails[nTail] = new SnakeTail(x, y);
        map[y][x] = snakeTails[nTail];
        nTail++;
    } else {
        deleteObject(x, y);
    }
}

void deleteObject(int x, int y) {
    map[y][x] = new Object(x, y);
}

void chooseMap() {
    while (!chosenLevel) {
        clear();
        printw("Choose map: \n\n");
        printw("1. Map 1\n");
        printw("2. Map 2\n");
        printw("3. Map 3\n");
        chosenLevel = chooseMapInput();
        usleep(10000); // Delay for smoother movement
        refresh();
    }
}

int chooseMapInput() {
    keypad(stdscr, TRUE);
    halfdelay(inputDelay);

    int key = getch();
    switch (key) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case 'x':
            gameOver = true;
            return 4;
        default:
            return 0;
    }
}

void createGate() {
    Gate *gate0 = new Gate(walls, nWall);
    gates[0] = gate0;
    map[gates[0]->getY()][gates[0]->getX()] = gate0;

    Gate *gate1 = new Gate(walls, nWall);
    gates[1] = gate1;
    map[gates[1]->getY()][gates[1]->getX()] = gate1;

    gateTime = 0;
    passingGate = false;
    nGate = 2;
}

void gateToWall() {
    if (nGate < 2) {
        return;
    }

    map[gates[0]->getY()][gates[0]->getX()] = new Wall(gates[0]->getX(), gates[0]->getY());
    map[gates[1]->getY()][gates[1]->getX()] = new Wall(gates[1]->getX(), gates[1]->getY());
    nGate = 0;
}

void findGateOutDirectionAndMove(Gate gate) {
    if (dir == UP) {
        if (gate.getY() - 1 >= 0 && !map[gate.getY() - 1][gate.getX()]->isWall()) {

        } else if (gate.getX() + 1 < width && !map[gate.getY()][gate.getX() + 1]->isWall()) {
            dir = RIGHT;
        } else if (gate.getX() - 1 >= 0 && !map[gate.getY()][gate.getX() - 1]->isWall()) {
            dir = LEFT;
        } else if (gate.getY() + 1 < height && !map[gate.getY() + 1][gate.getX()]->isWall()) {
            dir = DOWN;
        } else {
            gameOver = true;
        }

    } else if (dir == RIGHT) {
        if (gate.getX() + 1 < width && !map[gate.getY()][gate.getX() + 1]->isWall()) {

        } else if (gate.getY() + 1 < height && !map[gate.getY() + 1][gate.getX()]->isWall()) {
            dir = DOWN;
        } else if (gate.getY() - 1 >= 0 && !map[gate.getY() - 1][gate.getX()]->isWall()) {
            dir = UP;
        } else if (gate.getX() - 1 >= 0 && !map[gate.getY()][gate.getX() - 1]->isWall()) {
            dir = LEFT;
        } else {
            gameOver = true;
        }

    } else if (dir == DOWN) {
        if (gate.getY() + 1 < height && !map[gate.getY() + 1][gate.getX()]->isWall()) {

        } else if (gate.getX() - 1 >= 0 && !map[gate.getY()][gate.getX() - 1]->isWall()) {
            dir = LEFT;
        } else if (gate.getX() + 1 < width && !map[gate.getY()][gate.getX() + 1]->isWall()) {
            dir = RIGHT;
        } else if (gate.getY() - 1 >= 0 && !map[gate.getY() - 1][gate.getX()]->isWall()) {
            dir = UP;
        } else {
            gameOver = true;
        }

    } else if (dir == LEFT) {
        if (gate.getX() - 1 >= 0 && !map[gate.getY()][gate.getX() - 1]->isWall()) {

        } else if (gate.getY() - 1 >= 0 && !map[gate.getY() - 1][gate.getX()]->isWall()) {
            dir = UP;
        } else if (gate.getY() + 1 < height && !map[gate.getY() + 1][gate.getX()]->isWall()) {
            dir = DOWN;
        } else if (gate.getX() + 1 < width && !map[gate.getY()][gate.getX() + 1]->isWall()) {
            dir = RIGHT;
        } else {
            gameOver = true;
        }
    }

    switch (dir) {
        case LEFT:
            snakeHead->moveLeft(hx);
            break;
        case RIGHT:
            snakeHead->moveRight(hx);
            break;
        case UP:
            snakeHead->moveUp(hy);
            break;
        case DOWN:
            snakeHead->moveDown(hy);
            break;
    }

    map[hy][hx] = snakeHead;
}
