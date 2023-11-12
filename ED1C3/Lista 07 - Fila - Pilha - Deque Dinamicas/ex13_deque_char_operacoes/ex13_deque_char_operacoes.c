#include "dd_char/dd_char_iu.h"

void main ()
{
    DDC *Deque = (DDC *) malloc(sizeof(DDC));
    ddc_init(Deque);

    ddciu_executar_menu(Deque);
}
