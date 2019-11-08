#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define DIMX         (500)
#define DIMY         (400)


void red( int x, int y, char color[] )
{
    color[0] = x % 256; /* red */
    color[1] = 0;       /* green */
    color[2] = 0;       /* blue */
}


void green( int x, int y, char color[] )
{
    color[0] = 0;       /* red */
    color[1] = x % 256; /* green */
    color[2] = 0;       /* blue */
}


void blue( int x, int y, char color[] )
{
    color[0] = 0;       /* red */
    color[1] = 0;       /* green */
    color[2] = x % 256; /* blue */
}


void gray( int x, int y, char color[] )
{
    color[0] = x % 256; /* red */
    color[1] = x % 256; /* green */
    color[2] = x % 256; /* blue */
}


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

    /* Verifica argumentos */
    if( argc != 3 )
    {
        fprintf( stderr, "Erro de sintaxe: %s [-original|-gray|-red|-green-|-blue] ARQUIVO_SAIDA\n", argv[0] );
        return EXIT_FAILURE;
    }

    /* Tipo de gradiente */
    if( !strcmp(argv[1],"-gray") )
        getcolor = gray;
    else if( !strcmp(argv[1],"-red") )
        getcolor = red;
    else if( !strcmp(argv[1],"-green") )
        getcolor = green;
    else if( !strcmp(argv[1],"-blue") )
        getcolor = blue;
    else if( !strcmp(argv[1],"-original") )
        getcolor = original;
    else
        getcolor = original;

    /* Abre arquivo para gravacao */
    fp = fopen( argv[2], "wb" );

    /* Verifica se o arquivo foi aberto com sucesso */
    if(!fp)
    {
        fprintf( stderr, "Erro abrindo arquivo '%s' para gravacao: %s\n", argv[2], strerror(errno) );
        return EXIT_FAILURE;
    }

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

/* fim-de-arquivo */