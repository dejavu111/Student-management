#include <stdlib.h>
#include "logging.h"
#include "change.h"
#include "display.h"
#include "order.h"
#include "scholarship.h"

int main()
{
    menu();
    int choice;
    while(1)
    {
        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
    {
        case 1:logging();menu();break;
        case 2:change();menu();break;
        case 3:display();menu();break;
        case 4:order();menu();break;
        case 5:scholarship();menu();break;
        default:printf("输入错误，请重新输入\n");break;

    }

    }
    return 0;
}
