#ifndef CHANGE_H_H
#define CHANGE_H_H
#include "student.h"
void menu2()
{

    printf("�޸Ŀγ̳ɼ�---1\n");
    printf("�޸ĸ�����Ϣ---2\n");
    printf("�޸Ŀγ���Ϣ---3\n");
    printf("�޸�ѧ��������Ϣ---4\n");
    printf("�������˵�---0\n");

}
void changemark()
{
    system("cls");
    int i,rm;
    if((fp4=fopen("mark.dat","rb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
     for(i = 0; i< scorecount;i++)
    {
        fread(&a[i],sizeof(struct score),1,fp4);
    }
    printf("data is read\n");
    fclose(fp4);


    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�(����0����)\n");
    long n;

    char p[50];
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    while(1)
    {
       scanf("%ld",&n);
    if(n==0)
        break;
    printf("������Ҫ�޸ĵĿγ̱�ţ�");
    scanf("%s",p);
    printf("�������޸ĺ�ĳɼ���");
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
        printf("�ļ���ʧ��\n");
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
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("�޸�ѧ������ţ�\n");
    printf("����ѧ��ѧ�� �����");
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
        printf("�ļ���ʧ��\n");
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
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    while(1)
    {
        printf("������Ҫ�޸ĵĿγ̺ţ�(����0�˳�)");
        scanf("%s",m);
        if(strcmp(m,"0")==0)
            break;
        else
            for(i = 0 ; ;i++)
        {
            if(strcmp(m,b[i].num)==0)
            {
                printf("��ѡ��Ҫ�޸ĵ����ݣ�");
                printf("1---�γ�ѧ��\n");
                printf("2---�γ�ѧ��\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:printf("�������޸ĺ��ѧ�֣�");scanf("%d",&b[i].credit);break;
                    case 2:printf("�������޸ĺ�Ŀγ�ѧ�ڣ�");scanf("%d",&b[i].term);break;
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
        printf("�ļ���ʧ��\n");
    fscanf(fp3,"%d",&becount);
    for(i = 0; i < becount;i++)
    {
        fread(&d[i],sizeof(struct be),1,fp3);
    }
    fclose(fp3);
    printf("������Ҫ�ı佱��������ѧ��ѧ�ţ�(����0�˳�)");
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

        printf("1---����\n");
        printf("2---�ͷ�\n");
        printf("0---�˳�\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("������ӷַ�����");
            scanf("%d",&p);
            d[i].reward+=p;

        }
        else
            if(m==2)
        {
            printf("��������ַ�����");
            scanf("%d",&p);
            d[i].punishment-=p;
        }

        else
            if(m==0)
            break;
        else
            printf("�����������������");


    }
     if((fp3=fopen("behaviour.dat","wb+"))==NULL)
        {
            printf("�ļ���ʧ��\n");
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
        default:printf("�����������������\n");break;
        }
    }


}
#endif // CHANGE_H_H

