#include <stdio.h>
#include <conio.c>
#include <windows.h>

int black = 0, blue = 1, green = 2, aqua = 3, red = 4, purple = 5, yellow = 6, white = 7, gray = 8, lightBlue = 9, lightGreen = 10, lightAqua = 11, lightRed = 12, lightPurple = 13, lightYellow = 14, brightWhite = 15;

void setcolor(int color) {
    textcolor(color);
    textbackground(color);
    printf("  ");
}
void Line(int value, int color) {
    for (int i = 1; i <= value; i++) {
        setcolor(color);
    }
}
void Cereja(){
 //Desenho tem 14 linhas e 14 colunas

    //1 linha
    Line(1,white);
    Line(2,black);
    Line(11,white);
    printf("\n");
    //2 linha
    Line(1,black);
    Line(2,green);
    Line(2,black);
    Line(9,white);
    printf("\n");
    //3 linha
    Line(1,black);
    Line(4,green);
    Line(2,black);
    Line(7,white);
    printf("\n");
    //4 linha
    Line(1,white);
    Line(2,black);
    Line(1,green);
    Line(1,black);
    Line(2,green);
    Line(1,black);
    Line(6,white);
    printf("\n");
    //5 linha
    Line(2,white);
    Line(1,black);
    Line(1,green);
    Line(3,black);
    Line(1,green);
    Line(4,black);
    Line(2,white);
    printf("\n");
    //6 linha
    Line(3,white);
    Line(1,black);
    Line(1,green);
    Line(1,black);
    Line(1,white);
    Line(1,black);
    Line(4,red);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //7 linha
    Line(3,white);
    Line(2,black);
    Line(1,green);
    Line(1,black);
    Line(6,red);
    Line(1,black);
    printf("\n");
    //8 linha
    Line(2,white);
    Line(1,black);
    Line(4,red);
    Line(1,black);
    Line(5,red);
    Line(1,black);
    printf("\n");
    //9 linha
    Line(1,white);
    Line(1,black);
    Line(6,red);
    Line(1,black);
    Line(2,red);
    Line(1,white);
    Line(1,red);
    Line(1,black);
    printf("\n");
    //10 linha
    Line(1,white);
    Line(1,black);
    Line(6,red);
    Line(1,black);
    Line(2,white);
    Line(2,red);
    Line(1,black);
    printf("\n");
    //11 linha
    Line(1,white);
    Line(1,black);
    Line(4,red);
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(3,red);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //12 linha
    Line(1,white);
    Line(1,black);
    Line(2,red);
    Line(2,white);
    Line(2,red);
    Line(4,black);
    Line(2,white);
    printf("\n");
    //13 linha
    Line(2,white);
    Line(1,black);
    Line(4,red);
    Line(1,black);
    Line(6,white);
    printf("\n");
    //14 linha
    Line(3,white);
    Line(4,black);
    Line(7,white);
    printf("\n");

}
void padrao(){
    textcolor(white);
    textbackground(black);
    printf("  ");
}
int main() { 
    textcolor(white);
    textbackground(black);
    clrscr();
    system("cls");

    Cereja();
    padrao();

    return 0;
}   