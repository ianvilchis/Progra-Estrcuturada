#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lee y valida un numero entero desde teclado.
   Retorna: el entero ingresado por el usuario. */
int LeerEntero();

/* Inicializa ambos tableros en 0 y muestra el titulo del juego.
   Parametros: N-filas, M-columnas, Tablero1 y Tablero2 a inicializar. */
void Inicializacion(int N, int M, char Tablero1[N][M], char Tablero2[N][M]);

/* Muestra el tablero propio del jugador con la ubicacion de sus barcos.
   Parametros: Jugador-nombre, N-filas, M-columnas, Tablero a mostrar. */
void MostrarTablero(char Jugador[], int N, int M, char Tablero[N][M]);

/* Muestra el tablero de disparos ocultando los barcos no descubiertos.
   Parametros: Jugador1-atacante, Jugador2-defensor, N-filas, M-columnas, Tablero del defensor. */
void TableroDeDisparos(char Jugador1[], char Jugador2[], int N, int M, char Tablero[N][M]);

/* Solicita y coloca una fragata en el tablero.
   Parametros: Jugador-nombre, N-filas, M-columnas, Tablero, NoF-numero de fragata. */
void fragata(char Jugador[], int N, int M, char Tablero[N][M], int NoF);

/* Solicita y coloca un buque  en el tablero.
   Parametros: Jugador-nombre, N-filas, M-columnas, Tablero, NoF-numero de buque. */
void Buque(char Jugador[], int N, int M, char Tablero[N][M], int NoF);

/* Hace la colocacion de todos los barcos de un jugador (2 fragatas y 2 buques).
   Parametros: Jugador-nombre, N-filas, M-columnas, Tablero del jugador. */
void PonerBarco(char Jugador[], int N, int M, char Tablero[N][M]);

/* Gestiona el turno de disparo de un jugador, con turno extra si hay impacto.
   Parametros: Jugador1-atacante, Jugador2-defensor, impactos-contador por referencia,
   N-filas, M-columnas, Tablero del defensor. */
void Disparos(char Jugador1[], char Jugador2[], int *impactos, int N, int M, char Tablero[N][M]);

/* Muestra la pantalla de victoria con el nombre del ganador y el eliminado.
   Parametros: Jugador1-ganador, Jugador2-perdedor. */
void Ganador(char Jugador1[], char Jugador2[]);

int LeerEntero()
{
    int valor = 0;
    while (scanf("%d", &valor) != 1)
    {
        printf("Entrada invalida, ingresa un numero entero: ");
        while (getchar() != '\n') {}
    }
    return valor;
}

void Inicializacion(int N, int M, char Tablero1[N][M], char Tablero2[N][M])
{
    int i = 0, j = 0;
    printf("              |    |    |                         \n");
    printf("             )_)  )_)  )_)                        \n");
    printf("            )___))___))___)\\                     \n");
    printf("           )____)____)_____)\\\\                  \n");
    printf("         _____|____|____|____\\\\\\__             \n");
    printf("~~~~~~~~~\\                   /~~~~~~~~~~~~       \n");
    printf("  ~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~  ~~~~~          \n");
    printf("     ~~~~      ~~~~     ~~~    ~~                 \n");
    printf("                                                  \n");
    printf("   ____       _______ _______ _      ____        \n");
    printf("  |  _ \\   /\\|__   __|__   __| |    |  __|       \n");
    printf("  | |_) | /  \\  | |     | |  | |    | |__        \n");
    printf("  |  _ < / /\\ \\ | |     | |  | |    |  __|       \n");
    printf("  | |_) / ____ \\| |     | |  | |____| |__        \n");
    printf("  |____/_/    \\_|_|     |_|  |______|____|       \n");
    printf("                                                  \n");
    printf("--------------------------------------------------\n");

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            Tablero1[i][j]='0';
        }
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            Tablero2[i][j]='0';
        }
    }

}

void MostrarTablero(char Jugador[],int N, int M, char Tablero[N][M])
{
    int i = 0, j = 0;
    printf("\n=====================");
    printf("\n      Tablero ");
    printf("\n=====================\n");

    printf("      ");
    for (j = 0; j < M; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("   %d| ", i);
        for (j = 0; j < M; j++)
        {
            if(Tablero[i][j] == '0')
            {
                printf("~ ");
            }
            else
            {
                printf("%c ", Tablero[i][j]);
            }
        }
        printf("\n");
    }
}


void TableroDeDisparos(char Jugador1[], char Jugador2[], int N, int M, char Tablero[N][M])
{
    int i = 0, j = 0;
    int ContadorDeBarcos = 0;
    int FragatasHundidas = 0;
    int BuquesHundidos   = 0;

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(Tablero[i][j] == '3') FragatasHundidas++;
            if(Tablero[i][j] == '5') BuquesHundidos++;
        }
    }
    ContadorDeBarcos = FragatasHundidas + (BuquesHundidos / 2);

    printf("\n=============================");
    printf("\n %s Dispara a %s:\n", Jugador1, Jugador2);
    printf(" Barcos encontrados: %d\n", ContadorDeBarcos);
    printf("=============================\n");
    printf("         ");
    for (j = 0; j < M; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("      %d| ", i);
        for (j = 0; j < M; j++)
        {
            if (Tablero[i][j] == '0' || Tablero[i][j] == '1' || Tablero[i][j] == '4')
            {
                printf("~ ");
            }
            else if(Tablero[i][j] == '2')
            {
                printf("0 ");
            }
            else if(Tablero[i][j] == '3' || Tablero[i][j] == '5')
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void fragata(char Jugador[], int N, int M, char Tablero[N][M], int NoF)
{
    int XB1 = 0, YB1 = 0;
    MostrarTablero(Jugador, N, M, Tablero);

    printf("\nAhora coloca tu %d Fragata (ocupa 1 casilla).", NoF);
    do
    {
        do
        {
            printf("\nCasilla 1 - Fila (0-4): ");
            XB1=LeerEntero();
            if (XB1 < 0 || XB1 > 4)
            {
                printf("Fuera de rango!!!");
            }
        }
        while (XB1 < 0 || XB1 > 4);
        do
        {
            printf("Casilla 1 - Columna (0-4): ");
            YB1=LeerEntero();
            if (YB1 < 0 || YB1 > 4)
            {
                printf("Fuera de rango!!!\n");
            }
        }
        while (YB1 < 0 || YB1 > 4);
        if(Tablero[XB1][YB1] != '0')
        {
            printf("Casilla ocupada!!! Empieza de nuevo.\n");
        }
    }
    while(Tablero[XB1][YB1] != '0');

    Tablero[XB1][YB1] = '1';
    while (getchar() != '\n');

}

void Buque(char Jugador[], int N, int M, char Tablero[N][M], int NoF)
{
    int XB2 = 0, YB2 = 0, XB22 = 0, YB22 = 0;
    MostrarTablero(Jugador, N, M, Tablero);

    printf("\nAhora coloca tu %d Buque (ocupa 2 casillas).", NoF);
    printf("\nRecuerda: las 2 casillas deben estar juntas.\n");

    do
    {
        do
        {
            printf("\nCasilla 1 - Fila (0-4): ");
            XB2=LeerEntero();
            if (XB2 < 0 || XB2 > 4)
            {
                printf("Fuera de rango!!!\n");
            }
        }
        while (XB2 < 0 || XB2 > 4);

        do
        {
            printf("Casilla 1 - Columna (0-4): ");
            YB2=LeerEntero();
            if (YB2 < 0 || YB2 > 4)
            {
                printf("Fuera de rango!!!\n");
            }
        }
        while (YB2 < 0 || YB2 > 4);

        do
        {
            printf("\nCasilla 2 - Fila (0-4): ");
            XB22=LeerEntero();
            if (XB22 < 0 || XB22 > 4)
            {
                printf("Fuera de rango!!!\n");
            }
        }
        while (XB22 < 0 || XB22 > 4);

        do
        {
            printf("Casilla 2 - Columna (0-4): ");
            YB22=LeerEntero();
            if (YB22 < 0 || YB22 > 4)
            {
                printf("Fuera de rango!!!\n");
            }
        }
        while (YB22 < 0 || YB22 > 4);

        if (Tablero[XB2][YB2] != '0' || Tablero[XB22][YB22] != '0')
        {
            printf("Casilla ocupada!!! Empieza de nuevo.\n");
        }
        else if (!(XB2 == XB22 && (YB22 == YB2 + 1 || YB22 == YB2 - 1)) && !(YB2 == YB22 && (XB22 == XB2 + 1 || XB22 == XB2 - 1)))
        {
            printf("Las casillas no son adyacentes!!! Empieza de nuevo.\n");
        }
    }
    while (Tablero[XB2][YB2] != '0' || Tablero[XB22][YB22] != '0' || (!(XB2 == XB22 && (YB22 == YB2 + 1 || YB22 == YB2 - 1)) && !(YB2 == YB22 && (XB22 == XB2 + 1 || XB22 == XB2 - 1))));

    Tablero[XB2][YB2]   = '4';
    Tablero[XB22][YB22] = '4';
    while (getchar() != '\n');
}

void PonerBarco(char Jugador[], int N, int M, char Tablero[N][M])
{
    fragata(Jugador, N, M, Tablero, 1);
    fragata(Jugador, N, M, Tablero, 2);

    Buque(Jugador, N, M, Tablero, 1);
    Buque(Jugador, N, M, Tablero, 2);

    MostrarTablero(Jugador, N, M, Tablero);
}

void Disparos(char Jugador1[], char Jugador2[], int *impactos, int N, int M, char Tablero[N][M])
{
    int TurnoExtra = 0;
    int DIS1 = 0, DIS2 = 0;
    do
    {
        TurnoExtra=0;
        TableroDeDisparos(Jugador1, Jugador2, N, M, Tablero);
        printf("\n%s Ahora haras tu disparo:", Jugador1);

        do
        {

            do
            {
                printf("\nCasilla - Fila (0-4): ");
                DIS1=LeerEntero();
                if (DIS1 < 0 || DIS1 > 4)
                {
                    printf("Fuera de rango!!!");
                }
            }
            while (DIS1 < 0 || DIS1 > 4);
            do
            {
                printf("\nCasilla - Columna (0-4): ");
                DIS2=LeerEntero();
                if (DIS2 < 0 || DIS2 > 4)
                {
                    printf("Fuera de rango!!!");
                }
            }
            while (DIS2 < 0 || DIS2 > 4);
            if(Tablero[DIS1][DIS2]== '2'||Tablero[DIS1][DIS2]== '3' || Tablero[DIS1][DIS2]=='5')
            {
                printf("Cordenada repetida!!!");
            }
        }
        while(DIS1<0||DIS2<0||DIS1>4||DIS2>4||Tablero[DIS1][DIS2]== '2'||Tablero[DIS1][DIS2]== '3' || Tablero[DIS1][DIS2]=='5');
        while(getchar() != '\n');

        system("cls");

        if(Tablero[DIS1][DIS2]=='0')
        {
            Tablero[DIS1][DIS2]='2';
            TableroDeDisparos(Jugador1, Jugador2, N, M, Tablero);
        }
        else if(Tablero[DIS1][DIS2]=='1')
        {
            Tablero[DIS1][DIS2]='3';
            TableroDeDisparos(Jugador1, Jugador2, N, M, Tablero);
            printf("\n=============================\n");
            printf(" %s Impactaste a una fragata!!!", Jugador1);
            printf("\n=============================");
            (*impactos)++;
            if(*impactos >= 6)
            {
                TurnoExtra = 0;
            }
            else
            {
                TurnoExtra = 1;
            }
        }

        else if(Tablero[DIS1][DIS2]=='4')
        {
            Tablero[DIS1][DIS2]='5';
            TableroDeDisparos(Jugador1, Jugador2, N, M, Tablero);
            printf("\n=============================\n");
            printf(" %s Impactaste a un Buque!!!", Jugador1);
            printf("\n=============================");
            (*impactos)++;
            if(*impactos >= 6)
            {
                TurnoExtra = 0;
            }
            else
            {
                TurnoExtra = 1;
            }
        }

        if(Tablero[DIS1][DIS2]=='2')
        {
            printf("\nDisparo fallido, fin del turno de %s\n", Jugador1);
        }
        else if(Tablero[DIS1][DIS2]=='3' || Tablero[DIS1][DIS2]=='5')
        {
            if(*impactos < 6)
            {
                printf("\nDisparo exitoso, el turno de %s continua\n", Jugador1);
            }
            else
            {
                printf("\nUltimo impacto! %s ha ganado!\n", Jugador1);
            }
        }

        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");

    }
    while(TurnoExtra==1);

    if(*impactos<6)
    {
        printf("\nPresiona ENTER y pase el teclado a %s", Jugador2);
        getchar();
        system("cls");
    }
}

void Ganador(char Jugador1[], char Jugador2[])
{
    printf("\n\n");
    printf("          _ ._  _ , _ ._ \n");
    printf("        (_ ' ( `  )_  .__) \n");
    printf("      ( (  (    )   `)  ) _) \n");
    printf("     (__ (_   (_ . _) _) ,__) \n");
    printf("           `~~`\\ ' /`~~` \n");
    printf("                |  | \n");
    printf("              __|_ |__ \n");
    printf("             /         \\ \n");
    printf("            |___VICTORIA_| \n");
    printf("\n   Has ganado %s!!!\n", Jugador1);
    printf("\n   HAS ELIMINADO A %s! \n", Jugador2);

}


int main()
{
    /* Dimensiones del tablero de juego. */
    int N = 5;
    int M = 5;

    /* Arreglo con los nombres de ambos jugadores. */
    char Jugadores[2][100];

    /* Tableros de juego de cada jugador. */
    char Tablero1[N][M];
    char Tablero2[N][M];

    /* Contadores de impactos acumulados por cada jugador. */
    int impactos1 = 0;
    int impactos2 = 0;

    /* Inicializa tableros y muestra el titulo del juego. */
    Inicializacion(N, M, Tablero1, Tablero2);

    /* Captura los nombres de los jugadores. */
    printf("\nIngrese el nombre del jugador 1: ");
    fgets(Jugadores[0], sizeof(Jugadores[0]), stdin);
    Jugadores[0][strcspn(Jugadores[0], "\n")] = 0;
    printf("Ingrese el nombre del jugador 2: ");
    fgets(Jugadores[1], sizeof(Jugadores[1]), stdin);
    Jugadores[1][strcspn(Jugadores[1], "\n")] = 0;
    printf("\n--------------------------------------------------\n");
    printf("\nPresiona ENTER para iniciar la batalla...");
    getchar();
    system("cls");

    /* Fase de preparacion: cada jugador coloca sus barcos. */
    printf("\n=====================");
    printf("\n  Turno de %s:", Jugadores[0]);
    PonerBarco(Jugadores[0], N, M, Tablero1);

    printf("\nPresiona ENTER y pase el teclado a %s", Jugadores[1]);
    getchar();
    system("cls");

    printf("\n=====================");
    printf("\n  Turno de %s:", Jugadores[1]);
    PonerBarco(Jugadores[1], N, M, Tablero2);

    printf("\nPresiona ENTER para iniciar el juego");
    getchar();
    system("cls");

    /* Fase de combate: los jugadores se turnan hasta que uno alcance 6 impactos. */
    do
    {
        Disparos(Jugadores[0], Jugadores[1], &impactos1, N, M, Tablero2);

        if(impactos1 < 6)
        {
            Disparos(Jugadores[1], Jugadores[0], &impactos2, N, M, Tablero1);
        }
    }
    while(impactos1 < 6 && impactos2 < 6);

    /* Muestra al jugador ganador segun quien alcanzo los 6 impactos. */
    printf("\nPresione ENTER para descubrir el ganador");
    getchar();
    system("cls");

    if(impactos1 == 6)
    {
        Ganador(Jugadores[0], Jugadores[1]);
    }
    else
    {
        Ganador(Jugadores[1], Jugadores[0]);
    }

    printf("\n\nPresione ENTER para salir del programa...");
    getchar();
    return 0;
}
