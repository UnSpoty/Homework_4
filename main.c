#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 // hardcode is bad. lets make macro

//Написать программу абонентский справочник. Список абонентов представляет собой статический массив (100 элементов) из структур следующего в виде:

//struct abonent{
//char name[10];
//char second name[10];
//char tel[10];
//};
//При запуске на экран выводится текстовое меню:
//1) Добавить абонента
//2) Удалить абонента
//3) Поиск абонентов по имени
//4) Вывод всех записей
//5) Выход
//
//и пользователю предлагается ввести пункт меня с клавиатуры. Добавление
//абонента в массив реализуется простым заполнением свободной структуры,
//при выходе за 100 абонентов уведомить пользователя о переполнении
//справочника и не позволять больше добавлять абонентов. При удалении
//структура заполняется нулями. При поиске пользователь вводит с клавиатуры
//имя абонентов и на экран выводится список всех абонентов с таким же именем.
//Программа продолжает выполняться пока пользователь не введет пункт 5.

//--------------------------------------------------------------------------------main.h//
// this part mast be in .h file but who cares?
struct subscriber {
    char name[10];
    char second_name[10];
    char tel[10];
    } ;

struct subscriber subscriberBook[SIZE];

void menu_draw();
void subscriber_add();
void subscriber_del();
void subscriber_draw(const struct subscriber *member);
void print_members(); 
void subscriber_found();

//--------------------------------------------------------------------------------init array//

void init_subscriberBook() // Filling subscriberBook '\0'
{
    for (unsigned int i = 0; i < SIZE; i++)
        {
            subscriberBook[i].name[0] = subscriberBook[i].second_name[0]= subscriberBook[i].tel[0] = '\0';
        }
}

//--------------------------------------------------------------------------------Menu//

void menu_draw()
{
    unsigned int task_num;

    printf("\nPlease, select task from 1..5\n");

   //task list
   printf("1.Add new subscriber.\n");
   printf("2.Delete subscriber.\n");
   printf("3.Find subscriber by name.\n");
   printf("4.Draw all subscriber.\n");
   printf("5.Exit.\n");

   scanf("%u", &task_num);

  switch(task_num)
  {
    case 1:
        subscriber_add();
    break;
    case 2:
        subscriber_del();
    break; 
    case 3:
        subscriber_found();
    break;
    case 4:
        print_members();
    break;
    case 5:
        exit(0);
    break;

   default:
    printf("Selected task %u does not exist\n", task_num);
    menu_draw(); // re-call menu func.
  }
}

//--------------------------------------------------------------------------------Task1//

void subscriber_add()
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        if(*subscriberBook[i].name == '\0')
        {
        scanf("%s %s %s", subscriberBook[i].name, subscriberBook[i].second_name, subscriberBook[i].tel );
        }
        else
        {
        printf("ARRAY OVERFLOW. (LIMIT %d)", SIZE);
        break;
        }
    }

    menu_draw();
}

//--------------------------------------------------------------------------------Tesk2//

void subscriber_del()
{
    unsigned int id;

    printf("Plase, enter the subscriber ID you want to DELETE\n");
    scanf("%d", &id);

    if(id >= SIZE)
    {
        printf("Out of size. ID: %d cant be > than SIZE: %d\n", id, SIZE);
        menu_draw();
    }
    if (subscriberBook[id].name[0] == '\0')
    {
        printf("User is empty. Nothing to delete.\n");
        menu_draw();
    }

    subscriberBook[id].name[0] = subscriberBook[id].second_name[0] = subscriberBook[id].tel[0] = '\0';

    menu_draw();
}

//--------------------------------------------------------------------------------Task3//

void subscriber_found()
{
    char we_found[10];

    printf("Plase, enter the subscriber NAME you want to FOUND.\n");
    scanf("%s", we_found);

    for(unsigned int i = 0 ; i < SIZE; i++)
    {
        if(subscriberBook[i].name[0] != '\0' && strcmp(subscriberBook[i].name, we_found) == 0)
        {
            printf("%d",i);
            subscriber_draw(&subscriberBook[i]);
        }
    }

    menu_draw();
}

//--------------------------------------------------------------------------------Task4//

void subscriber_draw(const struct subscriber *member)
{
    printf("%s ,  %s, %s\n", member->name ,member->second_name, member->tel);
}


void print_members()
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        if(*subscriberBook[i].name != '\0')
        {
            printf("%d",i);
            subscriber_draw(&subscriberBook[i]);
        }

    }
    menu_draw();
}


//--------------------------------------------------------------------------------Main//

int main()
{
    init_subscriberBook();

    menu_draw(); // call menu
    return 0;
}
