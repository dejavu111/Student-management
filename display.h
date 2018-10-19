#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "student.h"
void menu3()
{
    printf("显示课程成绩---1\n");
    printf("显示个人信息---2\n");
    printf("显示课程信息---3\n");
    printf("显示学生奖惩信息---4\n");
    printf("返回主菜单---0\n");
}
void displaymark()
{
    system("cls");
    int i;
     if((fp4=fopen("mark.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
    for(i = 0; i < scorecount; i++)
    {
        fread(&c[i],sizeof(struct score),1,fp4);

    }
    printf("data is read\n");
    fclose(fp4);
    printf("学生学号/学生姓名/课程名称/课程编号/学期/分数\n");
    for(i = 0; i < scorecount;i++)

        printf("%ld %s %s %s %d %d\n",c[i].n,c[i].stuname,c[i].subname,c[i].subnum,c[i].term,c[i].m);




}
void displaybasic()
{
    system("cls");
    int i;
    if((fp1 = fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);

    for(i = 0; i< stucount;i++)
    {
        fread(&a[i],sizeof(struct stu),1,fp1);
        printf("%ld %s %d %s %d\n",a[i].num,a[i].name,a[i].dormitory,a[i].sex,a[i].age);
    }
    printf("data is read\n");
    fclose(fp1);
}
void displaysubject()
{
    system("cls");
    int i;
    if((fp2 = fopen("subject.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp2,"%d",&subcount);

    for(i = 0; i < subcount;i++)
    {
        fread(&b[i],sizeof(struct sub),1,fp2);
    }
    printf("data is read\n");
    printf("课程编号/课程类别/学期/课程名称/课程学分\n");
    for(i = 0; i < subcount ;i++)
    {
       printf("%s  %s  %d  %s  %d\n",b[i].num,b[i].type,b[i].term,b[i].name,b[i].credit);
    }
    fclose(fp2);
}

void displayreward()
{
    system("cls");
    int i,t;
    printf("请输入学期：\n");
    scanf("%d",&t);
    if((fp3=fopen("behaviour.dat","rb+"))==NULL)
        {
            printf("文件打开失败\n");
            exit(0);
        }
    fscanf(fp3,"%d",&becount);

    for(i = 0; i < becount;i++)
    {
        fread(&d[i],sizeof(struct be),1,fp3);
    }
    fclose(fp3);
    printf("学号/品行分数（辅导员/班主任/班级评议）/奖励分数/惩罚分数\n");
    for(i = 0; i < becount;i++)
    {

            printf("%ld %d %d %d %d %d\n",d[i].num,d[i].mark1,d[i].mark2,d[i].mark3,d[i].reward,d[i].punishment);
    }


}
void display()
{
    system("cls");
    int choice;
    while(1)
    {
        menu3();
        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:displaymark();break;
            case 2:displaybasic();break;
            case 3:displaysubject();break;
            case 4:displayreward();break;

        }
    }
}

#endif // DISPLAY_H_INCLUDED
