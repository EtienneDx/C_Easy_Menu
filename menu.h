#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_choice
{
    void (*fct)();
    char* text;
} choice;

typedef struct t_menu
{
    choice* choices;
    int choices_count;
    char* header;
    char* exit_text;
    char repeat;
    char free_when_done;
} menu;

menu* create_menu(char* header, char* exit_text);

void add_choice(menu* m, char* text, void(*action)());

void display_menu(menu* m);

void free_menu(menu* m);

#endif
