#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "game/eatable/Fruit.h"
#include "game/eatable/Poison.h"
#include "game/map/Wall.h"
#include "game/snake/SnakeHead.h"
#include "game/snake/SnakeTail.h"

bool gameOver;
const int width = 30;
const int height = 30;
int score;
Fruit *fruit;
Poison *poison;
Object *map[width][height];
SnakeTail *snakeTails[100];
SnakeHead *snakeHead;
int hx, hy;
int nTail = 3;
Direction dir;

using namespace std;

void setup();

void createMap();

void draw();

void input();

void logic();

void snakeMove(int beforeX, int beforeY, int newX, int newY, int prevHx, int prevHy);

void updateTail(int prevHx, int prevHy, bool eatFruit);

void deleteObject(int x, int y);

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(10000); // Delay for smoother movement
    }

    endwin(); // Terminate ncurses

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

    snakeHead = new SnakeHead(width / 2, height / 2);
    hx = snakeHead->getX();
    hy = snakeHead->getY();

    snakeTails[0] = new SnakeTail(hx, hy + 1);
    snakeTails[1] = new SnakeTail(hx, hy + 2);
    snakeTails[2] = new SnakeTail(hx, hy + 3);

    fruit = new Fruit(hx, hy, width, height, *snakeTails, nTail);
    poison = new Poison(hx, hy, width, height, *snakeTails, nTail);

    score = 0;

    createMap();


}

void draw() {
    clear();

    // Draw the top border
    // Draw the game field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printw("%c", map[i][j]->draw());
        }
        printw("\n");
    }

    // Draw the bottom border
    printw("\n");

    // Display the score
    printw("Score: %d\n", score);
    printw("Press 'x' to exit\n");

    refresh(); // Update the screen
}

void input() {
    keypad(stdscr, TRUE); // Enable keypad input
    halfdelay(1); // Set a maximum delay for getting input

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
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || j == 0 || j == width - 1 || i == height - 1) {
                map[i][j] = new Wall(j, i);
            } else if (i == hy && j == hx) {
                map[i][j] = snakeHead;
            } else if (i == fruit->getY() && j == fruit->getX())
                map[i][j] = fruit;
            else if (i == poison->getY() && j == poison->getX()) {
                map[i][j] = poison;
            } else {
                bool hasTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (snakeTails[k]->getX() == j && snakeTails[k]->getY() == i) {
                        map[i][j] = snakeTails[k];
                        hasTail = true;
                    }
                }
                if (!hasTail)
                    map[i][j] = new Object(j, i);
            }
        }
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
        deleteObject(beforeX, beforeY);

        eatFruit = true;
    } else if (tmpObject->getType() == POISON) {
        score -= 10;

        poison->newPosition(hx, hy, width, height, *snakeTails, nTail);
        map[poison->getY()][poison->getX()] = poison;
        deleteObject(beforeX, beforeY);

        deleteObject(snakeTails[nTail - 1]->getX(), snakeTails[nTail - 1]->getY());
        nTail--;

        if (nTail < 3) {
            gameOver = true;
        }
    } else if (tmpObject->getType() == WALL || tmpObject->getType() == SNAKE_TAIL) {
        gameOver = true;

    } else if (tmpObject->getType() == OBJECT) {
        map[beforeY][beforeX] = tmpObject;
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

    if(eatFruit){
        snakeTails[nTail] = new SnakeTail(x, y);
        map[y][x] = snakeTails[nTail];
        nTail++;
    }else{
        deleteObject(x, y);
    }
}

void deleteObject(int x, int y) {
    map[y][x] = new Object(x, y);
}
