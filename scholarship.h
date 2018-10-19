#ifndef SCHOLARSHIP_H_INCLUDED
#define SCHOLARSHIP_H_INCLUDED
void menu5()
{
   printf("显示学校奖学金---1\n");
    printf("显示国家奖学金---2\n");
    printf("返回主菜单---0\n");
}
void common()
{
     system("cls");
    int i;
    if((fp3 = fopen("behaviour.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp3,"%d",&becount);
    for(i = 0;i < becount;i++)
    {
        fread(&d[i],sizeof(struct be),1,fp3);
    }
    fclose(fp3);

    if((fp1 = fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
    for(i = 0; i < stucount;i++)
    {
        fread(&a[i],sizeof(struct stu),1,fp1);
    }
    fclose(fp1);
    for(i = 0; i < stucount;i++)
    {
        if((a[i].markplacing<(stucount*0.05))&&(d[i].behaviourplacing<(stucount*0.7))&&a[i].failcount==0&&d[i].punishment>-1)
            {
                a[i].scholarship=3;
                d[i].reward+=3;
            }
        else
        if((a[i].markplacing>(stucount*0.05))&&(a[i].markplacing<(stucount*0.15))&&(d[i].behaviourplacing<(stucount*0.7))&&a[i].failcount==0&&d[i].punishment>-1)
        {
            a[i].scholarship = 2;
            d[i].reward+=2;
        }
        else
            if((a[i].markplacing>(stucount*0.15))&&(a[i].markplacing<(stucount*0.35))&&(d[i].behaviourplacing<(stucount*0.7))&&a[i].failcount==0&&d[i].punishment>-1)
            {
                a[i].scholarship = 1;
                d[i].reward+=1;
            }
        else
            a[i].scholarship = 0;
    }
if((fp1=fopen("basic.dat","wb+"))==NULL)
{
    printf("文件打开失败\n");
    exit(0);
}
fprintf(fp1,"%d",stucount);
for(i = 0; i < stucount;i++)
    fwrite(&a[i],sizeof(struct stu),1,fp1);
printf("data is saved\n");
fclose(fp1);

if((fp3=fopen("behaviour.dat","wb+"))==NULL)
{
    printf("文件打开失败\n");
    exit(0);
}
fprintf(fp3,"%d",becount);
for(i = 0; i < becount;i++)
    fwrite(&d[i],sizeof(struct be),1,fp3);
printf("data is saved\n");
fclose(fp3);
}
void special()
{
     system("cls");
    int i,j;
    if((fp1 = fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
    for(i = 0; i < stucount;i++)
        fread(&a[i],sizeof(struct stu),1,fp1);
    printf("data is read\n");
    fclose(fp1);

    if((fp4 = fopen("mark.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
    for(i = 0;i < scorecount;i++)
    {
        fread(&c[i],sizeof(struct score),1,fp4);
    }
    printf("data is read\n");
    fclose(fp4);
    for(i = 0; i < stucount;i++)
        a[i].flag = 1;
    for(i = 0; i < stucount;i++)
    {
        if(a[i].failcount>0||a[i].markplacing>stucount*0.04)
            a[i].flag = 0;

       else
            for(j = 0; j < scorecount;j++)
        {
            if(a[i].num==c[j].n&&c[j].m<90)
            {
                a[i].flag = 0;
                break;
            }

        }
    }

    if((fp1=fopen("basic.dat","wb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp1,"%d",stucount);
    for(i = 0; i < stucount;i++)
    {
        fwrite(&a[i],sizeof(struct stu),1,fp1);
    }
    printf("data is saved\n");
    fclose(fp1);



}
void displaycommon()
{
    int i;
    if((fp1 = fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
    for(i = 0; i < stucount;i++)
        fread(&a[i],sizeof(struct stu),1,fp1);
    printf("data is read\n");
    fclose(fp1);
    printf("学号/姓名/成绩排名/奖项\n");
    for(i = 0; i < stucount; i++)
    {
        if(a[i].scholarship == 1)
            printf("%ld %s %d 三等奖学金\n",a[i].num,a[i].name,a[i].markplacing);
        else if(a[i].scholarship == 2)
            printf("%ld %s %d 二等奖学金\n",a[i].num,a[i].name,a[i].markplacing);
        else if(a[i].scholarship == 3)
            printf("%ld %s %d 一等奖学金\n",a[i].num,a[i].name,a[i].markplacing);
    }
}
void displayspecial()
{
     int i;
    if((fp1 = fopen("basic.dat","rb+"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
    for(i = 0; i < stucount;i++)
        fread(&a[i],sizeof(struct stu),1,fp1);
    printf("data is read\n");
    fclose(fp1);
    printf("学号/姓名\n");
    for(i = 0; i < stucount;i++)
        if(a[i].flag == 1)
        printf("%ld %s\n",a[i].num,a[i].name);
}
void scholarship()
{
    system("cls");
    common();
    special();
    menu5();

    int choice;
    while(1)
    {
        scanf("%d",&choice);
        if(choice==0)
            break;
    switch(choice)
    {
        case 1:displaycommon();menu5();break;
        case 2:displayspecial();menu5();break;
    }
    }

}
#endif // SCHOLARSHIP_H_INCLUDED
