#include <iostream>
#include <ncurses.h>
#include <unistd.h>

bool gameover;
const int width = 30;
const int height = 30;
int x, y, fruitX, fruitY, poisonX, poisonY, score;
int tailX[100], tailY[100];
int nTail = 3;
enum Direction {
    STOP = 0, LEFT, RIGHT, UP, DOWN
};
Direction dir;

using namespace std;

void setup();

void draw();

void input();

void logic();


int main() {
    setup();

    while (!gameover) {
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

    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    poisonX = rand() % width;
    poisonY = rand() % height;
    score = 0;

    tailX[0] = x;
    tailY[0] = y+1;
    tailX[1] = x;
    tailY[1] = y+2;
    tailX[2] = x;
    tailY[2] = y+3;
}

void draw() {
    clear();

    // Draw the top border
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    // Draw the game field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printw("#"); // Draw the left border
            if (i == y && j == x)
                printw("O"); // Draw the snake's head
            else if (i == fruitY && j == fruitX)
                printw("F"); // Draw the fruit
            else if (i == poisonY && j == poisonX)
                printw("P"); // Draw the fruit
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printw("o"); // Draw the snake's tail
                        printTail = true;
                    }
                }
                if (!printTail)
                    printw(" ");
            }
            if (j == width - 1)
                printw("#"); // Draw the right border
        }
        printw("\n");
    }

    // Draw the bottom border
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    // Display the score
    printw("Score: %d\n", score);

    refresh(); // Update the screen
}

void input() {
    keypad(stdscr, TRUE); // Enable keypad input
    halfdelay(1); // Set a maximum delay for getting input

    int key = getch();
    switch (key) {
        case KEY_LEFT:
            if (dir == RIGHT) {
                gameover = true;
            } else {
                dir = LEFT;
            }
            break;
        case KEY_RIGHT:
            if (dir == LEFT) {
                gameover = true;
            } else {
                dir = RIGHT;
            }
            break;
        case KEY_UP:
            if (dir == DOWN) {
                gameover = true;
            } else {
                dir = UP;
            }
            break;
        case KEY_DOWN:
            if (dir == UP) {
                gameover = true;
            } else {
                dir = DOWN;
            }
            break;
        case 'x':
            gameover = true;
            break;
    }
}

void logic() {
    if (dir == STOP)
        return;

    // Update the tail position
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Update the head position
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case STOP:
            break;
    }

    // Check for collision with borders
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameover = true;

    // Check for collision with tail
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y){
            gameover = true;
        }
    }

    // Check for collision with fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    if (x == poisonX && y == poisonY) {
        score -= 10;
        poisonX = rand() % width;
        poisonY = rand() % height;
        nTail--;
        if (nTail < 3) {
            gameover = true;
        }
    }
}