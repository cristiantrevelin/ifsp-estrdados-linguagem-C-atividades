#include <stdio.h>
#include "fd_int/fd_int_iu.h"

void main ()
{
    FDI Fila;

    fdi_init(&Fila);
    fdiiu_executar_menu(&Fila);
}
