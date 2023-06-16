#include <iostream>
#include<random>
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
const int maxLength = 23;
SnakeTail *snakeTails[maxLength];
SnakeHead *snakeHead;
bool passingGate = false;
int timeAfterPassingGate = 0;
Gate *gates[2];
int nGate = 0;
Wall *walls[300];
int nWall = 0;
int hx, hy;
int nTail = 0;
Direction dir;
int inputDelay = 1;
int gameTime = 0, fruitTime = 0, poisonTime = 0, gateTime = 100;
const int maxEatableTime = 50;
int chosenLevel = 0;
Object *blanks[width * height];
int nBlank = 0;

bool missionMode = false;

int fruitEatCnt = 0;
int poisonEatCnt = 0;
int gateUseCnt = 0;
const int targetUseGateCnt = 3;
const int maxPoisonEatCnt = 5;

using namespace std;

void displayMission();

void displayScore();

int createGate1(int wallNum);

void createGate2(int wallNum);

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

void newFruit();

void newPoison();

int getBlankIndexForEatable();

bool isWin();

void initArrays();

void initGameValues();

int main() {
    setup();
    chooseMap();

    createLevel:
    createMap();

    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(10000); // Delay for smoother movement
    }

    if (isWin() && missionMode && chosenLevel++ < 4) {
        initGameValues();
        initArrays();

        goto createLevel;
    }

    endwin();

    cout << "Game Over!" << endl;
    if (isWin()) {
        cout << "You win!" << endl;
    }
    cout << "Your score: " << score << endl;

    return 0;
}

void initGameValues() {
    gameOver = false;
    dir = STOP;

    gateUseCnt = 0;
    poisonEatCnt = 0;
    fruitEatCnt = 0;

    timeAfterPassingGate = 0;
    fruitTime = 0;
    poisonTime = 0;
    gateTime = 100;

    nTail = 0;
    nWall = 0;
    nBlank = 0;
    nGate = 0;
}

void initArrays() {
    for (int i = 0; i < 300; i++) {
        walls[i] = new Wall();
    }
    for (int i = 0; i < maxLength; i++) {
        snakeTails[i] = new SnakeTail();
    }
    for (int i = 0; i < 2; i++) {
        gates[i] = new Gate();
    }
}

bool isWin() {
    return fruitEatCnt >= maxLength - 3 && gateUseCnt >= targetUseGateCnt;
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

    displayScore();
    displayMission();
    printw("Press 'x' to exit\n");

    refresh();
}

void displayScore() {
    printw("Score Board\n");
    printw("Score: %d\n", score);
    printw("Fruit Eat Count: %d\n", fruitEatCnt);
    printw("Poison Eat Count: %d\n", poisonEatCnt);
    printw("Gate Use Count : %d\n", gateUseCnt);
    printw("Game Time: %d\n\n", gameTime / 10);
}

void displayMission() {
    printw("Mission\n");

    printw("Eat %d fruits (", maxLength - 3);
    if (fruitEatCnt >= maxLength - 3) {
        printw("v");
    }
    printw(")\n");

    printw("Eat poisons less then %d (v)\n", maxPoisonEatCnt);

    printw("Use %d gates (", targetUseGateCnt);
    if (gateUseCnt >= targetUseGateCnt) {
        printw("v");
    }
    printw(")\n");
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
        newFruit();
        score -= 3;
        fruitTime = 0;
    }

    if (poisonTime > maxEatableTime) {
        deleteObject(poison->getX(), poison->getY());
        newPoison();
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
        case 5:
            file.open("game/map/map1.txt", std::ios::in);
            break;
        case 2:
            file.open("game/map/map2.txt", std::ios::in);
            break;
        case 3:
            file.open("game/map/map3.txt", std::ios::in);
            break;
        case 4:
            file.open("game/map/map4.txt", std::ios::in);
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
                blanks[nBlank] = new Object(j, i);
                map[i][j] = blanks[nBlank++];

            } else if (ch == '@') {
                map[i][j] = new ImmuneWall(j, i);

            } else if (ch == '#') {
                walls[nWall] = new Wall(j, i);
                map[i][j] = walls[nWall];
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
        fruitEatCnt++;

        newFruit();

        eatFruit = true;
        fruitTime = 0;

    } else if (tmpObject->getType() == POISON) {
        score -= 10;

        newPoison();

        deleteObject(snakeTails[nTail - 1]->getX(), snakeTails[nTail - 1]->getY());
        nTail--;

        if (nTail < 2 || ++poisonEatCnt >= maxPoisonEatCnt) {
            gameOver = true;
        }

        poisonTime = 0;

    } else if (tmpObject->getType() == GATE) {
        passingGate = true;
        map[tmpObject->getY()][tmpObject->getX()] = tmpObject;
        Gate outGate = Gate::findOtherGate(*gates, tmpObject);

        snakeHead->moveToGate(outGate, hx, hy);
        findGateOutDirectionAndMove(outGate);

        gateUseCnt++;

    } else if (tmpObject->getType() == WALL || tmpObject->getType() == SNAKE_TAIL ||
               tmpObject->getType() == IMMUNE_WALL) {
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

        ++nTail;
        if (fruitEatCnt >= maxLength - 3) {
            gameOver = true;
        }
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
        printw("4. Map 4\n\n");
        printw("5. Mission Mode (All Maps) \n\n");
        printw("Press 'x' to exit\n");
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
        case '4':
            return 4;
        case '5':
            missionMode = true;
            return 1;
        case 'x':
            gameOver = true;
            return 6;
        default:
            return 0;
    }
}

void createGate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nWall - 1);

    int gate1WallNum = createGate1(dist(gen));
    int gate2WallNum = 0;

    do {
        gate2WallNum = dist(gen);
    } while (gate1WallNum == gate2WallNum);

    createGate2(gate2WallNum);

    gateTime = 0;
    passingGate = false;
    nGate = 2;
}

int createGate1(int wallNum) {
    Gate *gate0 = new Gate(walls[wallNum]->getX(), walls[wallNum]->getY());
    gates[0] = gate0;
    map[gates[0]->getY()][gates[0]->getX()] = gates[0];

    return wallNum;
}

void createGate2(int wallNum) {
    Gate *gate1 = new Gate(walls[wallNum]->getX(), walls[wallNum]->getY());
    gates[1] = gate1;
    map[gates[1]->getY()][gates[1]->getX()] = gates[1];
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

void newFruit() {
    int randIndex = getBlankIndexForEatable();

    fruit->newPosition(blanks[randIndex]->getX(), blanks[randIndex]->getY());
    map[fruit->getY()][fruit->getX()] = fruit;
}

void newPoison() {
    int randIndex = getBlankIndexForEatable();

    poison->newPosition(blanks[randIndex]->getX(), blanks[randIndex]->getY());
    map[poison->getY()][poison->getX()] = poison;
}

int getBlankIndexForEatable() {
    bool onTail;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nBlank - 1);

    int randIndex;

    do {
        onTail = false;
        randIndex = dist(gen);

        for (int i = 0; i < nTail; i++) {
            if (snakeTails[i]->getX() == blanks[randIndex]->getX() &&
                snakeTails[i]->getY() == blanks[randIndex]->getY()) {
                onTail = true;
                break;
            }

            if (nTail == 0) {
                break;
            }
        }
    } while ((blanks[randIndex]->getX() == hx && blanks[randIndex]->getY() == hy) || onTail);

    return randIndex;
}