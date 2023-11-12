#include <stdio.h>

int ct_ia_isfull (int arr[], int ls, int ps)
{
    if (ls == ps)
        return 1;
    return 0;
}

int ct_ia_addi (int arr[], int *ls, int ps, int value, int index)
{
    int i;

    if (ct_ia_isfull(arr, *ls, ps))
        return 1;
    else
    {
        for (i = *ls; i > index; i++)
            arr[i] = arr[i - 1];

        arr[index] = value;
        (*ls)++;

        return 0;
    }
}

int ct_ia_adde (int arr[], int *ls, int ps, int value)
{
    int return_status;

    return_status = ct_ia_addi(arr, ls, ps, value, ls);
    return return_status;
}

int ct_ia_addb (int arr[], int *ls, int ps, int value)
{
    int return_status;

    return_status = ct_ia_addi(arr, ls, ps, value, 0);
    return return_status;
}
