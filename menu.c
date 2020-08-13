#include "menu.h"

menu* create_menu(char* header, char* exit_text)
{
    menu* m = (menu*)malloc(sizeof(menu));
    m->choices = NULL;
    m->choices_count = 0;
    m->repeat = 1;
    m->free_when_done = 1;
    m->header = (char*)malloc((strlen(header) + 1) * sizeof(char));
    strcpy(m->header, header);
    m->exit_text = (char*)malloc((strlen(exit_text) + 1) * sizeof(char));
    strcpy(m->exit_text, exit_text);
    return m;
}

void add_choice(menu* m, char* text, void(*action)())
{
    m->choices_count++;
    choice* n = realloc(m->choices, m->choices_count * sizeof(choice));
    if(n == NULL)
    {
        printf("An allocation error occurred while adding the choice '%s'", text);
        exit(EXIT_FAILURE);
    }
    m->choices = n;
    choice *c = &m->choices[m->choices_count - 1];
    c->fct = action;
    c->text = (char*)malloc((strlen(text) + 1) * sizeof(char));;
    strcpy(c->text, text);
}

void display_menu(menu* m)
{
    int c = 0;
    do
    {
        printf("%s\n0. %s\n", m->header, m->exit_text);
        for(int i = 0; i < m->choices_count; i++)
        {
            printf("%d. %s\n", i + 1, m->choices[i].text);
        }
        scanf("%d", &c);
        if(c > 0 && c <= m->choices_count)
        {
            m->choices[c - 1].fct();
        }
    } while(c != 0 && m->repeat);
    if(m->free_when_done)
    {
        free_menu(m);
    }
}

void free_menu(menu* m)
{
    for(int i = 0; i < m->choices_count; i++)
    {
        free(m->choices[i].text);
    }
    free(m->choices);
    free(m->header);
    free(m);
}
