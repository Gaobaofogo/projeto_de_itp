#include <stdio.h>
#include <stdlib.h>

#define dimx (600)//definição do tamhanho da imagem
#define dimy (400)

void cor( int x, int y, char cores[] )//aqui é feito a alteração das cores
{
    cores[0] = y*x   % 256;  
    cores[1] = (x*x)+(y*y)  % 256;      
    cores[2] = (x + y) % 256;    
}


int main( int argc, char ** argv )
{
    int x = 0;
    int y = 0;
    FILE * fp = NULL;
    char cores[3] = { 0, 0, 0 }; // r, g, b 
    void (*getcolor)( int, int, char[] );

    
    getcolor = cor;

    
    fp = fopen( argv[2], "wb" ); //abertura do arquivo

    

                                            //---------
    fprintf( fp, "P6\n" );               
    fprintf( fp, "%d %d\n", dimx, dimy ); //gravação do cabeçalho do arquivo ppm
    fprintf( fp, "255\n" );              
                                            //---------

    

  
    for ( y = 0; y < dimy; y++ ) // for para gerar e andar pela imagem
    {
        
        for ( x = 0; x < dimx; x++ )
        {
            getcolor( x, y, cores );//utliza as cores para calcular as cores

            fwrite( cores, sizeof(char), sizeof(cores), fp );//grava o pixel (rgb) no arquivo
        }
    }

    
    fclose(fp);

}