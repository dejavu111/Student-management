#ifndef LOGGING_H_H
#define LOGGING_H_H
#include "student.h"
void menu1()
{
    printf("基本信息录入---1\n");
    printf("课程信息录入---2\n");
    printf("品行表现录入---3\n");
    printf("课程成绩录入---4\n");
    printf("奖罚信息录入---5\n");
    printf("返回主菜单---0\n");
}

void basic()
{
    int n,i;
    system("cls");
    if((fp1=fopen("basic.dat","wb+"))==NULL)
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

    int temp = stucount;

    printf("请输入录入人数：");
    scanf("%d",&n);
    printf("请输入基本信息：\n");
    printf("学号\t姓名 宿舍号 性别 年龄\n");
    for(i=temp;i<temp+n;++i)
    {
        scanf("%ld%s%d%s%d",&a[i].num,a[i].name,&a[i].dormitory,a[i].sex,&a[i].age);
        stucount++;

    }

    if((fp1=fopen("basic.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp1,"%d",stucount);

    for(i = 0 ; i < stucount;i++)
        {

            if(fwrite(&a[i],sizeof(struct stu),1,fp1)!=1)
            printf("file write error\n");
        }

    printf("data is saved\n");
    fclose(fp1);



    printf("--------------------------基本信息录入结束------------------------------------\n");
}
void subject()
{
    int n,i;
    system("cls");
    if((fp2=fopen("subject.dat","wb+"))==NULL)
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
    fclose(fp2);

    int temp = subcount;
    printf("请输入录入课程数：");

    scanf("%d",&n);
    printf("请输入课程信息：\n");

    for(i = temp; i < temp+n; ++i)
    {
        printf("课程号 课程类别 课程所在学期 课程名称 学分\n");
        scanf("%s%s%d%s%d",b[i].num,b[i].type,&b[i].term,b[i].name,&b[i].credit);
        subcount++;

    }
    if((fp2=fopen("subject.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp2,"%d",subcount);
    for(i = 0; i < subcount;i++)
        if(fwrite(&b[i],sizeof(struct sub),1,fp2)!=1)
            printf("file write error\n");
    printf("data is saved\n");
    fclose(fp2);

    printf("--------------------------课程信息录入结束------------------------------------\n");

}
void behaviour()
{
    system("cls");
    int i=0,k;
    printf("请输入录入学生个数：\n");
    scanf("%d",&k);
    printf("请输入品行分数：\n");
    printf("学号\t学期\t辅导员\t班主任\t班级评议\n");
    if((fp3=fopen("behaviour.dat","wb+"))==NULL)
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
    int temp = becount;
    for(i = temp; i < temp+k;i++)
    {
            scanf("%ld%d%d%d%d",&d[i].num,&d[i].term,&d[i].mark1,&d[i].mark2,&d[i].mark3);
            becount++;

    }
    if((fp3=fopen("behaviour.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp3,"%d",becount);
    for(i = 0; i < becount; i++)
    {
        if(fwrite(&d[i],sizeof(struct be),1,fp3)!=1)
            printf("file write error\n");
    }
    fclose(fp3);
    printf("--------------------------品性表现录入结束------------------------------------\n");

}
void mark()
{
    system("cls");
    int i,n;
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
    for(i = 0; i < scorecount; i++)
    {
        fread(&c[i],sizeof(struct score),1,fp4);

    }
    fclose(fp4);
    int temp = scorecount;
    printf("请输入录入成绩个数：");
    scanf("%d",&n);
    for(i = temp; i < temp+n; ++i)

    {
        scorecount++;
        printf("请输入课程编号/课程名称/课程学期/学生学号/姓名/成绩\n");
        scanf("%s%s%d%ld%s%d",c[i].subnum,c[i].subname,&c[i].term,&c[i].n,c[i].stuname,&c[i].m);
        if(c[i].m>=60)
            c[i].f=1;
        else
            c[i].f=0;

    }
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp4,"%d",scorecount);
    for(i = 0 ; i < scorecount;i++)
    {

         if(fwrite(&c[i],sizeof(struct score),1,fp4)!=1)
            printf("file write error\n");
    }

    printf("data is saved\n");
    fclose(fp4);
    printf("--------------------------课程成绩录入结束------------------------------------\n");

}

void reward()
{
    system("cls");
    printf("请输入奖罚学生学号：(输入0退出)");
    long n;
    int m;
    int p;
    int i;
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
            if(fwrite(&d[i],sizeof(struct be),1,fp3)!=1)
                printf("file write error\n");
        }
        fclose(fp3);

    printf("--------------------------奖罚表现录入结束------------------------------------\n");

}

void logging()
{
    system("cls");
    int choice;
    menu1();
    while(1)
    {

        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:basic();printf("请输入下一步操作\n");menu1();break;
            case 2:subject();printf("请输入下一步操作\n");menu1();break;
            case 3:behaviour();printf("请输入下一步操作\n");menu1();break;
            case 4:mark();printf("请输入下一步操作\n");menu1();break;
            case 5:reward();printf("请输入下一步操作\n");menu1();break;
            default:printf("输入错误，请重新输入\n");menu1();break;
        }

    }
}
#endif // LOGGING_H_H
