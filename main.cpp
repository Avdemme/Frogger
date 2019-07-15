#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "string.h"
#include <cmath>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <fcntl.h>


using namespace std;




char getch() {
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror ("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror ("tcsetattr ~ICANON");
  return (buf);
}


int kbhit(void){
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO );
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0 );
  fcntl (STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  
  ch = getchar();
  
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  
  if ( ch != EOF ){
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}



double rand_uniform ( ) {

  return (double)rand() / (double)RAND_MAX;

}

void ClearTheScreen ( ) {
  
  printf("\033[%d;%dH",1,1);
  return;

}
  
int ROW = 20;
int COL = 20;

int main ( int argc, char** argv ) {


  double grid[ROW][COL];
  
  for ( int i=0; i < ROW; i++){
    for ( int j = 0; j < COL ; j++ ) {
      grid[i][j] = 0;
    }
  }


  grid[2][0] = 2; grid[2][1]=2; grid[2][2]=2;grid[2][3]=2; grid[2][6] =2; grid[2][9] = 2; grid[2][10] = 2; grid[2][13] = 2; grid[2][16]=2; grid[2][17] = 2; grid[2][18] = 2; grid[2][19] = 2;
 grid[3][0] = 2; grid[3][1] = 2; grid[3][2] = 2; grid[3][3] = 2; grid[3][4] = 2; grid[3][8] = 2; grid[3][9] = 2; grid [3][10] = 2; grid[3][11]=2; grid[3][15] = 2; grid[3][16] = 2; grid[3][17] = 2; grid[3][18] = 2; grid[3][19] = 2;
 grid[4][0] = 2; grid[4][1] = 2; grid[4][2] = 2; grid[4][3] = 2; grid[4][7] = 2; grid[4][8] = 2; grid[4][9] = 2; grid[4][10] = 2; grid[4][14] = 2; grid[4][15] = 2; grid[4][16] = 2; grid[4][17] = 2; grid[4][18] = 2; grid[4][19] = 2;
 grid[5][0] = 2; grid[5][1] = 2; grid[5][2] = 2; grid[5][3] = 2; grid[5][5] = 2; grid[5][8] = 2; grid[5][9] = 2; grid[5][10] = 2; grid[5][11] =2; grid[5][12] = 2; grid[5][16] = 2; grid[5][17] = 2; grid[5][18] = 2; grid[5][19] = 2;
 grid[6][0] = 2; grid[6][1] = 2; grid[6][2] = 2; grid[6][6] = 2; grid[6][7] = 2; grid[6][8] = 2; grid[6][9] = 2; grid[6][10] = 2; grid[6][11] = 2; grid[6][15] = 2; grid[6][16] = 2; grid[6][17] = 2; grid[6][18] = 2; grid[6][19]=2;

  grid[8][2] = 1; grid[8][3] = 1; grid[8][5] = 1; grid[8][6] = 1; grid[8][8] = 1; grid[8][9] = 1; grid[8][11] = 1; grid[8][12]; grid[8][14] = 1; grid[8][15] = 1; grid[8][17] = 1; grid[8][18] = 1;

  grid[10][1] = 1; grid[10][2] = 1; grid[10][5]=1; grid[10][6]=1;  grid[10][9]=1; grid[10][10]=1; grid[10][13]=1; grid[10][14] = 1; grid[10][17]=1; grid[10][18]=1;
  grid[11][1] = 1; grid[11][2] = 1; grid[11][5]=1; grid[11][6]=1;  grid[11][9]=1; grid[11][10]=1; grid[11][13]=1; grid[11][14] = 1; grid[11][17]=1; grid[11][18]=1;

 grid[13][1] = 1; grid[13][2] = 1; grid[13][3] = 1; grid[13][4]=1; grid[13][7]=1; grid[13][8]=1; grid[13][9]=1; grid[13][10]=1; grid[13][13] =1; grid[13][14]=1; grid[13][15]=1; grid[13][16]=1; 
  grid[14][1] = 1; grid[14][2] = 1; grid[14][3] = 1; grid[14][4]=1; grid[14][7]=1; grid[14][8]=1; grid[14][9]=1; grid[14][10]=1; grid[14][13] =1; grid[14][14]=1; grid[14][15]=1; grid[14][16]=1;

  grid[16][1] = 1; grid[16][2]=1; grid[16][3]=1; grid[16][7]=1;grid[16][8]=1;grid[16][9]=1;grid[16][13]=1;grid[16][14]=1;grid[16][15]=1;


   double next[ROW][COL];
  for ( int i = 0; i < ROW; i++ ) {
    for ( int j = 0; j < COL; j++ ) {
      next[i][j]= grid[i][j];
    }
  }

  double delay;
  double diff;

  cout << "difficulty (1,2,3,4)" << endl;
  cin >> diff;

  if ( diff == 1 ){
    delay = 0.15;
  }

  else if ( diff == 2 ){
    delay = 0.12;
  }

  else if ( diff == 3 ) {
    delay = 0.07;
  }
  else if ( diff == 4 ) {
    delay = 0.01;
  }

  char slow[9]; sprintf(slow, "sleep %lf", delay);
  double counters = 0;


  char cha;
  int x;
  int y;
  double pos[2] = {0., -9.};
  
  x = int(floor(pos[0]+0.5))+int(floor(double(COL)/2.));
  y =-int(floor(pos[1]+0.5))+int(floor(double(ROW)/2.));

  x = 10;
  y = 19;

  bool frog[ROW][COL];

  
  bool start = true;
  bool alive = true;
  for ( int i = 0; i < ROW ; i++ ) {
    for (int j = 0; j < COL; j++ ) {
      frog[i][j] = false;
    }
  }
  frog[19][10] = true;

  int gen = 0;

  cout << "press anything to start " << endl;

 
      
  while ( alive ) {

    

    cha = 'e';

    while(kbhit())
    
    cha = getchar();
     

   

    if ( cha == 'w' ) pos[1]++;
    if ( cha == 's' ) pos[1]--;
    if ( cha == 'a' ) pos[0]--;
    if ( cha == 'd' ) pos[0]++;
        
      start = true;
      frog[y][x] = false;

      x = int(floor(pos[0]+0.5))+int(floor(double(COL)/2.));
      y =-int(floor(pos[1]+0.5))+int(floor(double(ROW)/2.));

    frog[y][x] = true;

    if ( y == 0) {
      alive = false;
    }

    if ( y > 19 ) { 
      alive = false;
    }

    if ( x <  0 ) {
      alive = false;
    }
    
    if ( x > 19 ) {
      alive = false;
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if ( grid[i][j] == 1 && frog[i][j] ){
	  alive = false;
	}
      }
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if ( grid[i][j] == 2 && frog[i][j] ){
	  alive = false;
	}
      }
    }


    
    system(slow);
    
    ClearTheScreen();
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
        if ( frog[i][j] ) {
	  cout << "f";	 
	}
	else if ( grid[i][j] == 0 ) cout << " ";
	else if ( grid[i][j] == 1 ) cout << "c";
	else if ( grid[i][j] == 2 ) cout << "w";
	
        else cout << " ";
      }
      cout << endl;
      
      
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if (grid[i][j] == 0 && j < (COL-1) && gen == 9 ) {
	  next[i][j+1] = 0;
	}
	if (grid[i][j] == 1 && j < (COL - 1) && gen == 9 ) {
	  next[i][j+1] = 1;
	}
	if (grid[i][j] == 2 && j < (COL - 1) && gen == 9 ) {
	  next[i][j+1] = 2;
	}
	
	if (grid[i][j] == 0 && j == (COL-1) && gen == 9) {
	  next[i][0] = 0;
	}
	if (grid[i][j] == 1 && j == (COL - 1) && gen == 9) {
	  next[i][0] = 1;
	}
	if (grid[i][j] == 2 && j == (COL - 1) && gen == 9) {
	  next[i][0] = 2;
	}
      }
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for (int j = 0; j < COL; j++ ) {
	grid[i][j] = next[i][j];
      }
    }

    gen++;

    if ( gen == 10 ){
      gen = 0;
    }
    
    
    
  }

  if ( y > 19 ) {
    cout << "died" << endl;
  }

  else if ( y == 0 ) {
    cout << "you safely made it across! Good Job! " << endl;
  }

  else if ( x < 0 ) {
    cout << "you died" << endl;
  }
  else if ( x > 0 ) {
    cout << "you died" << endl;
  }

  else if ( y < 7 ) {
    cout << "you died" << endl;
  }
  
  else if ( y > 7 ) {
    cout << " you died " << endl;
  }
 


 
  return 1;
  
}


    
