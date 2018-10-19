#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include "student.h"
void menu4()
{
    printf("按学生总分排序---1\n");
    printf("按学生不及格门次排序---2\n");
    printf("按课程不及格人数排序---3\n");
    printf("按学生奖励分数排序---4\n");
    printf("按学生惩罚分数排序---5\n");
    printf("返回主菜单---0\n");
}
void studenttotalpoint()
{
    system("cls");
    int i,j;
    if((fp4=fopen("mark.dat","rb+"))==NULL)
       {
           printf("文件打开失败\n");exit(0);
       }

    fscanf(fp4,"%d",&scorecount);
    for(i = 0; i < scorecount; i++)
    {
        fread(&c[i],sizeof(struct score),1,fp4);
    }
    printf("data is read\n");
    fclose(fp4);

    if((fp1 = fopen("basic.dat","rb+"))==NULL)
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

    for(i = 0; i < stucount;i++)
       {
           a[i].totalpoint=0;
           a[i].scholarship = 0;
       }
    printf("请输入学期：");
    int t;
    scanf("%d",&t);
    for(i = 0; i < stucount;i++)
    {
        for(j = 0; j < scorecount;j++)
            if(a[i].num==c[j].n&&c[j].term==t)
            a[i].totalpoint+=c[j].m;
    }
    stu temp;
    for(i = 0; i < stucount; i++)
        for(j = i+1; j <stucount ; j++)
    {
        if(a[i].totalpoint<a[j].totalpoint)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }
    printf("名次/姓名/学号/总分\n");
    for(i = 0; i < stucount;i++)
    {
        a[i].markplacing = i+1;
         printf("%d %ld %s %d\n",i+1,a[i].num,a[i].name,a[i].totalpoint);

    }
    if((fp1 = fopen("basic.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp1,"%d",stucount);
    for(i = 0; i< stucount;i++)
    {
        fwrite(&a[i],sizeof(struct stu),1,fp1);
    }
    printf("data is save\n");
    fclose(fp1);



}
void studentfailnumber()
{
    system("cls");
    int i,j;
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

    if((fp1 = fopen("basic.dat","rb+"))==NULL)
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
    for(i = 0; i < stucount;i++)
        a[i].failcount=0;
    printf("请输入学期：");
    int t;
    scanf("%d",&t);
    for(i = 0;i < stucount;i++ )
    {
        for(j = 0; j < scorecount;j++)
        if(a[i].num==c[j].n&&c[j].term==t)
            if(c[i].f==0)
            a[i].failcount++;
    }
    stu temp;
    for(i = 0; i < stucount; i++)
        for(j = i+1; j <stucount ; j++)
    {
        if(a[i].failcount<a[j].failcount)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }
    printf("学号/姓名/不及格科数\n");
    for(i = 0; i < stucount;i++)
        printf("%ld %s %d\n",a[i].num,a[i].name,a[i].failcount);
    if((fp1 = fopen("basic.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp1,"%d",stucount);
    for(i = 0; i< stucount;i++)
    {
        fwrite(&a[i],sizeof(struct stu),1,fp1);
    }
    printf("data is save\n");
    fclose(fp1);

}

void subjectfailnumber()
{
    system("cls");
    int i,j;
    if((fp2=fopen("subject.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp2,"%d",&subcount);
    for(i = 0; i < subcount; i++)
    {
        fread(&b[i],sizeof(struct sub),1,fp2);
    }
    printf("data is read\n");
    fclose(fp2);

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
    printf("请输入学期：");
    int t;
    scanf("%d",&t);
    for(i = 0; i < subcount;i++)
        b[i].failcount = 0;
    for(i = 0;i < subcount;i++)
    {
        for(j = 0; j < scorecount;j++)
        {
            if((strcmp(b[i].num,c[i].subnum)==0)&&t == b[i].term)
                if(c[i].f==0)
                    b[i].failcount++;
        }
    }
    sub temp;
    for(i = 0; i<subcount;i++)
        for(j = i+1;j < subcount;j++)
        if(b[i].failcount<b[j].failcount)
        {
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    printf("课程编号/课程名称/不及格人数\n");
    for(i = 0; i < subcount; i++)
        if(b[i].term == t)
        printf("%s %s %d\n",b[i].num,b[i].name,b[i].failcount);

    if((fp2=fopen("subject.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp2,"%d",subcount);
    for(i = 0; i < subcount; i++)
    {
        fwrite(&b[i],sizeof(struct sub),1,fp2);
    }
    printf("data is saved\n");
    fclose(fp2);
}
void onreward()
{
    system("cls");
    int i,j;
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
    be temp;
    for(i = 0; i < becount;i++)
        for(j = i+1;j< becount;j++)
        if(d[i].reward<d[j].reward)
    {
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
    }
    printf("学号/奖励分数\n");
    for(i = 0; i < becount;i++)
    {
        printf("%ld %d\n",d[i].num,d[i].reward);
    }
}

void onpunishment()
{
    system("cls");
    int i,j;
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
    be temp;
    for(i = 0; i < becount;i++)
        for(j = i+1;j< becount;j++)
        if(d[i].punishment<d[j].punishment)
    {
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
    }
    printf("学号/惩罚分数\n");
    for(i = 0; i < becount;i++)
    {
        printf("%ld %d\n",d[i].num,d[i].punishment);
    }
}
void onbehaviour()
{
    system("cls");
    int i,j;
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
    be temp;
    for(i = 0; i < becount;i++)
        for(j = i+1;j< becount;j++)
        if((d[i].mark1+d[i].mark2+d[i].mark3)<(d[j].mark1+d[j].mark2+d[j].mark3))
    {
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
    }
    for(i = 0; i < becount;i++)
        d[i].behaviourplacing=i+1;

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
void order()
{
    system("cls");
    menu4();
    int choice;
    while(1)
    {
        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:studenttotalpoint();menu4();break;
            case 2:studentfailnumber();menu4();break;
            case 3:subjectfailnumber();menu4();break;
            case 4:onreward();menu4();break;
            case 5:onpunishment();menu4();break;
        }
    }
}


#endif // ORDER_H_INCLUDED
