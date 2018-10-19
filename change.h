#ifndef CHANGE_H_H
#define CHANGE_H_H
#include "student.h"
void menu2()
{

    printf("修改课程成绩---1\n");
    printf("修改个人信息---2\n");
    printf("修改课程信息---3\n");
    printf("修改学生奖惩信息---4\n");
    printf("返回主菜单---0\n");

}
void changemark()
{
    system("cls");
    int i,rm;
    if((fp4=fopen("mark.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
     for(i = 0; i< scorecount;i++)
    {
        fread(&a[i],sizeof(struct score),1,fp4);
    }
    printf("data is read\n");
    fclose(fp4);


    printf("请输入要修改的学生学号：(输入0结束)\n");
    long n;

    char p[50];
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    while(1)
    {
       scanf("%ld",&n);
    if(n==0)
        break;
    printf("请输入要修改的课程编号：");
    scanf("%s",p);
    printf("请输入修改后的成绩：");
    scanf("%d",&rm);

            for(i = 0; i < scorecount; ++i)
        {
            if(c[i].n==n&&(strcmp(c[i].subnum,p)==0))
                c[i].m=rm;

        }

    }
    fprintf(fp4,"%d",scorecount);
    for(i = 0 ; i < scorecount;i++)
        if(fwrite(&c[i],sizeof(struct score),1,fp4)!=1)
            printf("file write error\n");
    printf("data is saved\n");
    fclose(fp4);

}
void changebasic()
{
    system("cls");
    int dor,i;
     if((fp1=fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
     for(i = 0; i< stucount;i++)
    {
        fread(&a[i],sizeof(struct stu),1,fp1);
    }
    printf("data is read\n");
    fclose(fp1);

     if((fp1=fopen("basic.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    printf("修改学生宿舍号：\n");
    printf("输入学生学号 宿舍号");
    long n;
    scanf("%ld%d",&n,&dor);
    for(i = 0; i < stucount; i++)
    {
        if(n == a[i].num)
            a[i].dormitory=dor;
    }
    fprintf(fp1,"%d",stucount);
    for(i = 0 ; i < stucount;i++)
        if(fwrite(&a[i],sizeof(struct stu),1,fp1)!=1)
            printf("file write error\n");
    printf("data is saved\n");
    fclose(fp1);


}
void changesubject()
{
    system("cls");
    int i,c;
     if((fp2=fopen("subject.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp2,"%d",&subcount);
    for(i = 0 ;i < subcount;i++)
    {
        fread(&b[i],sizeof(struct sub),1,fp2);
    }
    fclose(fp2);
    char m[40];

     if((fp2=fopen("subject.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    while(1)
    {
        printf("请输入要修改的课程号：(输入0退出)");
        scanf("%s",m);
        if(strcmp(m,"0")==0)
            break;
        else
            for(i = 0 ; ;i++)
        {
            if(strcmp(m,b[i].num)==0)
            {
                printf("请选择要修改的内容：");
                printf("1---课程学分\n");
                printf("2---课程学期\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:printf("请输入修改后的学分：");scanf("%d",&b[i].credit);break;
                    case 2:printf("请输入修改后的课程学期：");scanf("%d",&b[i].term);break;
                }
                break;
            }
        }
    }
    fprintf(fp2,"%d",subcount);
     for(i = 0 ; i <subcount ;i++)
        if(fwrite(&b[i],sizeof(struct sub),1,fp2)!=1)
            printf("file write error\n");
    printf("data is saved\n");
    fclose(fp2);


}
void changereward()
{
    system("cls");
    int i,m,p;
    long n;
    if((fp3=fopen("behaviour.dat","rb+"))==NULL)
        printf("文件打开失败\n");
    fscanf(fp3,"%d",&becount);
    for(i = 0; i < becount;i++)
    {
        fread(&d[i],sizeof(struct be),1,fp3);
    }
    fclose(fp3);
    printf("请输入要改变奖罚分数的学生学号：(输入0退出)");
    while(1)
    {
        scanf("%ld",&n);
        if(n==0)
            break;
        for(i = 0; i < becount; i++)
        {
            if(d[i].num==n)
                break;
        }

        printf("1---奖励\n");
        printf("2---惩罚\n");
        printf("0---退出\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("请输入加分分数：");
            scanf("%d",&p);
            d[i].reward+=p;

        }
        else
            if(m==2)
        {
            printf("请输入减分分数：");
            scanf("%d",&p);
            d[i].punishment-=p;
        }

        else
            if(m==0)
            break;
        else
            printf("输入错误，请重新输入");


    }
     if((fp3=fopen("behaviour.dat","wb+"))==NULL)
        {
            printf("文件打开失败\n");
            exit(0);
        }
        fprintf(fp3,"%d",becount);
        for(i = 0; i < becount;i++)
        {
            fwrite(&d[i],sizeof(struct be),1,fp3);
        }
        fclose(fp3);

}
void change()
{
    system("cls");
    int choice;
    while(1)
    {
        menu2();
        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
        case 1:changemark();break;
        case 2:changebasic();break;
        case 3:changesubject();break;
        case 4:changereward();break;
        default:printf("输入错误，请重新输入\n");break;
        }
    }


}
#endif // CHANGE_H_H

