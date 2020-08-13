#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void test()
{
    printf("test\n");
}

void test2()
{
    printf("test2\n");
}

int main()
{
    menu* m = create_menu("Faites votre choix:", "Quitter");
    add_choice(m, "test", &test);
    add_choice(m, "test2", &test2);
    display_menu(m);
    return 0;
}
