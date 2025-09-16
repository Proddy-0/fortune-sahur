#include <stdio.h>
#include <conio.c>
#include <windows.h>

int black = 0, blue = 1, green = 2, aqua = 3, red = 4, purple = 5, yellow = 6, white = 7, gray = 8, lightBlue = 9, lightGreen = 10, lightAqua = 11, lightRed = 12, lightPurple = 13, lightYellow = 14, brightWhite = 15;
void padrao(){
    textcolor(white);
    textbackground(black);
    printf("\n");
    fflush(stdin);
}
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
    padrao();
}
void Limao(){
    //Desenho tem 14 linhas e 14 colunas

    //1 linha
    Line(14,white);
    printf("\n");
    //2 linha
    Line(14,white);
    printf("\n");
    //3 linha
    Line(6,white);
    Line(3,black);
    Line(5,white);
    printf("\n");
    //4 linha
    Line(5,white);
    Line(1,black);
    Line(3,green);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //5 linha
    Line(4,white);
    Line(1,black);
    Line(2,lightYellow);
    Line(1,black);
    Line(2,green);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //6 linha
    Line(3,white);
    Line(1,black);
    Line(2,lightYellow);
    Line(1,white);
    Line(1,lightYellow);
    Line(1,black);
    Line(1,green);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //7 linha
    Line(2,white);
    Line(1,black);
    Line(1,yellow);
    Line(3,lightYellow);
    Line(1,white);
    Line(1,lightYellow);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //8 linha
    Line(2,white);
    Line(1,black);
    Line(1,yellow);
    Line(5,lightYellow);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //9 linha
    Line(2,white);
    Line(1,black);
    Line(1,yellow);
    Line(1,lightYellow);
    Line(1,white);
    Line(3,lightYellow);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //10 linha
    Line(3,white);
    Line(1,black);
    Line(1,yellow);
    Line(3,lightYellow);
    Line(1,black);
    Line(5,white);
    printf("\n");
    //11 linha
    Line(4,white);
    Line(1,black);
    Line(2,yellow);
    Line(1,black);
    Line(6,white);
    printf("\n");
    //12 linha
    Line(5,white);
    Line(2,black);
    Line(7,white);
    printf("\n");
    //13 linha
    Line(14,white);
    printf("\n");
    //14 linha
    Line(14,white);
    printf("\n");
    padrao();
}
void Laranja(){
    //Desenho tem 14 linhas e 14 colunas
    //1 linha
    Line(14,white);
    printf("\n");
    //2 linha
    Line(4,white);
    Line(3,black);
    Line(7,white);
    printf("\n");
    //3 linha
    Line(4,white);
    Line(1,black);
    Line(2,green);
    Line(1,black);
    Line(6,white);
    printf("\n");
    //4 linha
    Line(4,white);
    Line(1,black);
    Line(2,green);
    Line(1,black);
    Line(1,white);
    Line(3,black);
    Line(2,white);
    printf("\n");
    //5 linha
    Line(4,white);
    Line(2,black);
    Line(1,green);
    Line(1,black);
    Line(1,white);
    Line(1,black);
    Line(2,green);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //6 linha
    Line(4,white);
    Line(2,black);
    Line(1,green);
    Line(2,black);
    Line(3,green);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //7 linha
    Line(2,white);
    Line(2,black);
    Line(3,red);
    Line(1,black);
    Line(2,green);
    Line(2,black);
    Line(2,white);
    printf("\n");
    //8 linha
    Line(1,white);
    Line(1,black);
    Line(2,red);
    Line(2,white);
    Line(3,red);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //9 linha
    Line(1,white);
    Line(1,black);
    Line(1,red);
    Line(1,white);
    Line(6,red);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //10 linha
    Line(1,white);
    Line(1,black);
    Line(1,red);
    Line(1,white);
    Line(6,red);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //11 linha
    Line(1,white);
    Line(1,black);
    Line(8,red);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //12 linha
    Line(2,white);
    Line(1,black);
    Line(6,red);
    Line(1,black);
    Line(4,white);
    printf("\n");
    //13 linha
    Line(3,white);
    Line(6,black);
    Line(5,white);
    printf("\n");
    //14 linha
    Line(14,white);
    printf("\n");
    padrao();
}
void Bar(){
    //Desenho tem 14 linhas e 14 colunas
    //1 linha
    Line(14,white);
    printf("\n");
    //2 linha
    Line(14,white);
    printf("\n");
    //3 linha
    Line(1,white);
    Line(13,red);
    printf("\n");
    //4 linha
    Line(1,white);
    Line(2,red);
    Line(1,black);
    Line(3,red);
    Line(1,black);
    Line(3,red);
    Line(1,black);
    Line(2,red);
    printf("\n");
    //5 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //6 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //7 linha
    Line(1,white);
    Line(1,red);
    Line(2,black);
    Line(2,red);
    Line(3,black);
    Line(1,red);
    Line(2,black);
    Line(2,red);
    printf("\n");
    //8 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //9 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //10 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //11 linha
    Line(1,white);
    Line(1,red);
    Line(1,black);
    Line(1,black);
    Line(2,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);
    Line(1,red);
    Line(1,black);    
    Line(1,red);
    printf("\n");
    //12 linha
    Line(1,white);
    Line(13,red);
    printf("\n");
    //13 linha
    Line(14,white);
    printf("\n");
    //14 linha
    Line(14,white);
    printf("\n");
    padrao();         
}
void sete(){
    //Desenho tem 14 linhas e 14 colunas
    //1 linha
    Line(14,white);
    printf("\n");
    //2 linha
    Line(2,white);
    Line(2,red);
    Line(1,white);
    Line(3,red);
    Line(2,white);
    Line(2,red);
    Line(2,white);
    printf("\n");
    //3 linha
    Line(1,white);
    Line(12,red);
    Line(1,white);
    printf("\n");
    //4 linha
    Line(1,white);
    Line(12,red);
    Line(1,white);
    printf("\n");
    //5 linha
    Line(2,white);
    Line(2,red);
    Line(1,white);
    Line(7,red);
    Line(2,white);
    printf("\n");
    //6 linha
    Line(7,white);
    Line(4,red);
    Line(3,white);
    printf("\n");
    //7 linha
    Line(6,white);
    Line(4,red);
    Line(4,white);
    printf("\n");
    //8 linha
    Line(5,white);
    Line(4,red);
    Line(5,white);
    printf("\n");
    //9 linha
    Line(4,white);
    Line(4,red);
    Line(6,white);
    printf("\n");
    //10 linha
    Line(3,white);
    Line(4,red);
    Line(7,white);
    printf("\n");
    //11 linha
    Line(2,white);
    Line(4,red);
    Line(8,white);
    printf("\n");
    //12 linha
    Line(1,white);
    Line(4,red);
    Line(9,white);
    printf("\n");
    //13 linha
    Line(1,white);
    Line(4,red);
    Line(9,white);
    printf("\n");
    //14 linha
    Line(14,white);
    printf("\n");
    padrao();
}
void DIAMANTE(){
 //Desenho tem 14 linhas e 14 colunas
  //1 linha
    Line(5,white);
    Line(4,black);
    Line(5,white);
    printf("\n");
  //2 linha
    Line(4,white);
    Line(1,black);
    Line(4,white);
    Line(1,black);
    Line(4,white);
    printf("\n");
  //3 linha
    Line(3,white);
    Line(1,black);
    Line(1,white);
    Line(4,lightBlue);
    Line(1,blue);
    Line(1,black);
    Line(3,white);
    printf("\n");
  //4 linha
    Line(2,white);
    Line(1,black);
    Line(1,white);
    Line(3,lightBlue);
    Line(1,white);
    Line(2,lightBlue);
    Line(1,blue);
    Line(1,black);
    Line(2,white);
    printf("\n");
  //5 linha
    Line(2,white);
    Line(1,black);
    Line(1,white);
    Line(1,lightBlue);
    Line(1,white);
    Line(5,lightBlue);
    Line(1,black);
    Line(2,white);
    printf("\n");
    //6 linha
    Line(1,white);
    Line(1,black);
    Line(1,white);
    Line(1,lightBlue);
    Line(1,white);
    Line(6,lightBlue);
    Line(1,white);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //7 linha
    Line(1,white);
    Line(1,black);
    Line(1,white);
    Line(9,lightBlue);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //8 linha
    Line(1,white);
    Line(1,black);
    Line(1,white);
    Line(7,lightBlue);
    Line(2,blue);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //9 linha
    Line(1,white);
    Line(1,black);
    Line(1,white);
    Line(2,lightBlue);
    Line(4,blue);
    Line(3,lightBlue);
    Line(1,black);
    Line(1,white);
    printf("\n");
    //10 linha
    Line(2,white);
    Line(1,black);
    Line(1,lightBlue);
    Line(1,blue);
    Line(4,lightBlue);
    Line(1,blue);
    Line(1,lightBlue);
    Line(1,black);
    Line(2,white);
    printf("\n");
    //11 linha
    Line(2,white);
    Line(1,black);
    Line(1,lightBlue);
    Line(1,blue);
    Line(4,lightBlue);
    Line(1,blue);
    Line(1,lightBlue);
    Line(1,black);
    Line(2,white);
    printf("\n");    
    //12 linha
    Line(3,white);
    Line(1,black);
    Line(6,lightBlue);
    Line(1,black);
    Line(3,white);
    printf("\n");
    //13 linha
    Line(4,white);
    Line(6,black);
    Line(4,white);
    printf("\n");
    //14 linha
    Line(14,white);
    printf("\n");
    padrao();
}
void SAHUR(){
    //Desenho tem 14 linhas e 14 colunas
    //1 linha
    Line(14,white);
    printf("\n");
    //2 linha
    Line(6,white);
    Line(2,gray);
    Line(6,white);
    printf("\n");
    //3 linha
    Line(5,white);
    Line(4,gray);
    Line(5,white); 
    printf("\n");   
    //4 linha
    Line(4,white);
    Line(6,gray);
    Line(4,white); 
    printf("\n");   
    //5 linha
    Line(3,white);
    Line(8,gray);
    Line(3,white); 
    printf("\n");
    //6 linha
    Line(2,white);
    Line(10,gray);
    Line(2,white); 
    printf("\n");
    //7 linha
    Line(2,white);
    Line(1,gray);
    Line(1,black);
    Line(1,gray);
    Line(4,white);
    Line(1,gray);
    Line(1,black);
    Line(1,gray);
    Line(2,white);
    printf("\n");                  
    //8 linha
    Line(1,white);
    Line(3,gray);
    Line(6,white);
    Line(3,gray);
    Line(1,white);  
    printf("\n");
    //9 linha
    Line(1,white);
    Line(2,gray);
    Line(1,white);
    Line(6,red);
    Line(1,white);
    Line(2,gray);
    Line(1,white);
    printf("\n");
    //10 linha
    Line(2,gray);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(2,red);
    Line(1,white);
    Line(2,gray);
    printf("\n");
    //11 linha
    Line(1,gray);
    Line(1,white);
    Line(2,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(2,red);
    Line(1,white);
    Line(2,gray);
    printf("\n");
    //12 linha
    Line(1,gray);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(1,red);
    Line(1,white);
    Line(2,red);
    Line(1,white);
    Line(1,gray);
    printf("\n");
    //13 linha
    Line(1,gray);
    Line(1,white);
    Line(10,red);
    Line(1,white);
    Line(1,gray);
    printf("\n");
    //14 linha
    Line(1,gray);
    Line(12,white);
    Line(1,gray);
    printf("\n");
    padrao();
}
void Menu (){
    Line(25,blue);
    printf("\n");
    padrao();
    textcolor(lightYellow);
    printf("\t\t  FORTUNE SAHUR\t\t\n");
    Line(25,blue);
    printf("\n");
    padrao();
}
int main() { 
    padrao();
    clrscr();
    system("cls");
    
        /*Menu();
        padrao();
        Cereja();
        padrao();
        Limao();
        padrao();
        Laranja();
        padrao();
        Bar();
        padrao();
        sete();
        padrao();
        DIAMANTE();
        padrao();
        */
        SAHUR();
        padrao();
    return 0;
}   