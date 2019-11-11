#include <stdio.h>
#include <stdlib.h>

#define DIMX         (500)
#define DIMY         (400)

void original( int x, int y, char color[] )
{
    color[0] = x + 2 * y % 256;  /* red */
    color[1] = x - y % 256;      /* green */
    color[2] = (x + y) % 256;    /* blue */
}


int main( int argc, char ** argv )
{
    int x = 0;
    int y = 0;
    FILE * fp = NULL;
    char color[3] = { 0, 0, 0 }; /* r, g, b */
    void (*getcolor)( int, int, char[] );

    
    getcolor = original;

    /* Abre arquivo para gravacao */
    fp = fopen( argv[2], "wb" );

    

    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf( fp, "P6\n" );
    fprintf( fp, "%d %d\n", DIMX, DIMY );
    fprintf( fp, "255\n" );

    /* Gera imagem */

    /* Para cada linha... */
    for ( y = 0; y < DIMY; ++y )
    {
        /* Para cada coluna... */
        for ( x = 0; x < DIMX; ++x )
        {
            /* calcula cor a partir da coordenadas */
            getcolor( x, y, color );

            /* Grava pixel RGB no arquivo */
            fwrite( color, sizeof(char), sizeof(color), fp );
        }
    }

    /* fecha arquivo */
    fclose(fp);

    /* Sucesso */
    return EXIT_SUCCESS;
}