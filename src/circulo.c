#include <stdio.h>
#include <math.h>

// Center of the cicle = (15, 15)
int xc = pontoX, yc = pontoY;


char imagem[dimX][dimY];

void plot_pixel(int x, int y){
  desenho[x][y]='*';
}

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
  plot_pixel(xc+x, yc+y);
  plot_pixel(xc+x, yc-y);
  plot_pixel(xc+y, yc+x);
  plot_pixel(xc+y, yc-x);
  plot_pixel(xc-x, yc-y);
  plot_pixel(xc-y, yc-x);
  plot_pixel(xc-x, yc+y);
  plot_pixel(xc-y, yc+x);
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
}


int main(int argc, char **argv)
{
  // preenche a matriz desenho com .
  // so para garantir o conteudo
  for (int i = 0; i < dimX; ++i){
    for (int j = 0; j < dimY; ++j){
      desenho[i][j]='.';
    }
  }


  // imprime o resultado
  for (int i = 0; i < dimX; ++i){
    for (int j = 0; j < dimY; ++j){
      if (desenho[i][j]=='*'){ 
        
      } else {
             

    }
    printf("\n");
  }

  return 0;
}