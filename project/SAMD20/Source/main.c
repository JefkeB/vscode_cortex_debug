#include <asf.h>

#include "main.h"


//
//
//
int main()
{
	system_init();

    volatile int teller = 0;
    while(1) 
    {
        teller++;
    }
}