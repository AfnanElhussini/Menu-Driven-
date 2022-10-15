#include <stdio.h>
#include <String.h>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#define HOME 71
#define UP 72
#define DOWN 80
#define END 79
#define ESC 27
#define Enter 13
void SubMenu();
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void textattr(int i)
{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);

}

    int main(){
    int i=0;
    int pos=0;
    char ch;
    int flag=0;


do{
char menu[3][10]={"New","Display","Exit"};
    for(i=0; i<3; i++){
    if(i==pos)
        textattr(0x09);
         gotoxy(10, 5+i);
        _cprintf("%s\n",menu[i]);
        textattr(0x07);
    }
      ch = getch();
      switch(ch){
      case -32:

      ch= getch();
      switch(ch){
      case HOME:
          // new highlight
      pos=0;
      break;
      case UP:
      pos--;
      //return
     if(pos<0)
        pos=2;
    break;

     case END:
    pos=2;
    break;
    //Down
  case DOWN:
   pos++;
   if(pos>2)
   pos=0;
   break;
    }
    break;
  case Enter:
      if(pos==2)
        flag=1;
      switch(pos){
      case 0:

          gotoxy(10,7+i);
           SubMenu();
       // printf("%s",menu[0]);
        break;
      case 1:
          gotoxy(10,7+i);
        printf("%s", menu[1]);
        break;
      case 2:
          gotoxy(10,8+i);
        printf("%s", menu[2]);
        break;
      }
    break;
    case ESC:
      flag=1;
      break;
  }
 } while(flag==0);
return 0;
}
void SubMenu()
{
    int flag=0 ;
    int pos=0 ;
    int i=0;
    char ch ;
    char  subMenu[3][20]={"New","Open","close"};
    do{

    for(i=0; i<3; i++){
    if(i==pos)
        textattr(0x09);
         gotoxy(18, 5+i);
        _cprintf("%s\n",subMenu[i]);
        textattr(0x07);
    }
      ch = getch();
      switch(ch){
      case -32:

      ch= getch();
      switch(ch){
      case HOME:
          // new highlight
      pos=0;
      break;
      case UP:
      pos--;
      //return as circle
     if(pos<0)
        pos=2;
    break;
// End of program
     case END:
         //go to Exit
    pos=2;
    break;
    //Down
  case DOWN:
   pos++;
   if(pos>2)
   pos=0;
   break;
    }
    break;
  case Enter:
      if(pos==2)
        flag=1;
      switch(pos){
      case 0:
         // submenu();
     /*    for(i=0;i<3;i++){
           gotoxy(18,5+i);
           printf("%s",subMenu[i]);
           if(i==pos){
            textattr(0x02);
            gotoxy(18,5+i);
            _cprintf("%s",subMenu[i]);
            textattr(0x07);
           }
         }
      case -32:
        ch=getch();
        switch(ch){

        case Home:
            pos=0;
            break;
        case UP:
            gotoxy(18,5+i);
            pos--;
            //return
            if(pos<0)
                pos=2;
            break;
        case END:
            pos=2;
            break;
            //Down
        case DOWN:
            pos++;
            if(pos>2)
                pos=0;
                break;


        }*/
        break;
      case 1:
          gotoxy(18,6);
        printf("%s", subMenu[1]);
        break;
      case 2:
          gotoxy(18,7);
        printf("%s", subMenu[2]);
        break;
      }
    break;
    case ESC:
      flag=1;
      break;
  }
 } while(flag==0);

}
