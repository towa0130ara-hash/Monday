#include "game.h"

void changeArray(int arr[], int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * number;
    }
}
