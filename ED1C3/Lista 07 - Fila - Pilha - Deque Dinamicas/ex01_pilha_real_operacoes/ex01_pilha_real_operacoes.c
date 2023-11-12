#include <stdio.h>
#include "pd_float/pd_float_iu.h"

void main ()
{
    PDF_NODE *Pilha;

    pdf_init(&Pilha);
    pdfiu_executar_menu(&Pilha);
}
