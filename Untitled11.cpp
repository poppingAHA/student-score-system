#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 10
struct student{
    int num;  //ѧ��
    char name[30];   //����
    int score[M];   //�ɼ�
    char course[M][20];//�γ�����
    int total; //�ܷ�
};
int k=0,count=0;
void main(){
    struct student stu[N];
    int n,x;
    void myinput(struct student stu[]);
    void mydelete(struct student stu[],int x);
    void myamend(struct student stu[],int x);
    void myall(struct student stu[]);
    void mysort(struct student stu[]);
    int mylookup(struct student stu[],int x);
    void mysort2(struct student stu[]);
    void mysave(struct student stu[]);
    void myread(struct student stu[]);
    void mycourse(struct student stu[]);
    while(1){
        printf("------------���˵�------------\n");
        printf("1.ѧ���ɼ�����\n");
        printf("2.ѧ���ɼ�ɾ��\n");
        printf("3.ѧ���ɼ��޸�\n");
        printf("4.��ӡ�������ѧ��\n");
        printf("5.��ѧ��������ʾ\n");
        printf("6.��ѧ�Ų�ѯ\n");
        printf("7.���ܷ�������ʾ\n");
        printf("8.���ݱ���\n");
        printf("9.���ݶ�ȡ\n");
        printf("10.�γ��Զ���\n");
        printf("0.�˳�ϵͳ\n");
        printf("------------------------------\n");
        printf("��ѡ��");
        scanf("%d",&n);
        switch(n){
            case 1:
                myinput(stu);
                break;
            case 2:
                mydelete(stu,x);
                break;
            case 3:
                myamend(stu,x);
                break;
            case 4:
                myall(stu);
                break;
            case 5:
                mysort(stu);
                break;
            case 6:
                printf("��������ҵ�ѧ��ѧ�ţ�");
                int i,j;
                i=mylookup(stu,x);
                if(i!=-1){
                    printf("���ҳɹ�����ѧ����Ϣ���£�\n");
                    printf("ѧ�ţ�%d ������%s\n",stu[i].num,stu[i].name);
                    for(j=0;j<count;j++){
                        printf("��%d�ſγ�:%d\t",j+1,stu[i].score[j]);
                    }
                    printf("\n");
                }else{
                    printf("���Ҳ��ɹ�����ȷ�����������Ƿ���ȷ��\n");
                }
                break;
            case 7:
                mysort2(stu);
                break;
            case 8:
                mysave(stu);
                break;
            case 9:
                myread(stu);
                break;
            case 10:
                mycourse(stu);
                break;
            case 0:
                exit(0);
        }
    }
}
void myinput(struct student stu[]){
    int i;
    printf("������γ�������\n");
    scanf("%d",&count);
    for(i=0;i<count;i++){
        printf("������γ����ƣ�\n");
        scanf("%s",&stu[i].course);
    }
    printf("������ѧ�ţ�");
    scanf("%d",&stu[k].num);
    getchar();
    printf("������������");
    gets(stu[k].name);
    for(i=0;i<count;i++){
        printf("������%s�γ̵ĳɼ���",stu[i].course);
        scanf("%d",&stu[k].score[i]);
    }
    k++;
}
void mydelete(struct student stu[],int x){
    int i,indext;
    int mylookup(struct student stu[],int x);
    printf("������Ҫɾ����ѧ����ѧ�ţ�\n");
    indext=mylookup(stu,x);
    if(indext!=-1){
        for(i=indext;i<k;i++){
            stu[i]=stu[i+1];
        }
        k--;
        printf("ɾ���ɹ���\n");
    }else{
        printf("ɾ��ʧ�ܣ��Ҳ�����ѧ������Ϣ��\n");
    }
}
void myamend(struct student stu[],int x){
    int i,indext;
    int mylookup(struct student stu[],int x);
    printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
    indext=mylookup(stu,x);
    if(indext!=-1){
        printf("����������ѧ������Ϣ��\n������ѧ��ѧ�ţ�");
        scanf("%d",&stu[indext].num);
        getchar();
        printf("������ѧ��������");
        gets(stu[indext].name);
        printf("������ѧ���ɼ����Կո������");
        for(i=0;i<count;i++){
            scanf("%d",&stu[indext].score[i]);
        }
        printf("�޸ĳɹ���\n");
    }else{
        printf("�޸�ʧ�ܣ��Ҳ�����ѧ������Ϣ��\n");
    }
}
void myall(struct student stu[]){
    int i,j;
    printf("ѧ��\t����\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}
void mysort(struct student stu[]){
    int i,j;
    struct student t;
    for(i=0;i<k-1;i++){
        for(j=0;j<k-i-1;j++){
            if(stu[j].num>stu[j+1].num){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    printf("ѧ��\t����\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}
int mylookup(struct student stu[],int x){
    int i,indext=-1;
    scanf("%d",&x);
    for(i=0;i<N;i++){
       if(stu[i].num == x){
        indext=i;
        break;
       }
    }
    return indext;
}
void mysort2(struct student stu[]){
    int i,j,a;
    struct student t;
    for(i=0;i<k;i++){
        for(j=0;j<count;j++){
            stu[i].total+=stu[i].score[j];
        }
    }
    for(i=0;i<k-1;i++){
        for(j=0;j<k-i-1;j++){
            if(stu[j].total<stu[j+1].total){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    printf("ѧ��\t����\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("�ܷ�\t����\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("%d\t%d\t",stu[i].total,i+1);
        printf("\n");
    }
}
void mysave(struct student stu[]){
    FILE *fp;
    fp=fopen("output.txt","w");
    int i,j;
    for(i=0;i<k;i++){
        fprintf(fp,"%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            fprintf(fp,"%d\t",stu[i].score[j]);
        }
    }
    printf("���ݱ���ɹ���\n");
    fclose(fp);
}
void myread(struct student stu[]){
    FILE *fp;
    fp=fopen("output.txt","r");
    int i,j;
    if (!fp){
        printf("Cannot open such a file\n");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp,"%d\t%s\t",&stu[i].num,&stu[i].name);
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(i=0;i<k;i++){
            for(j=0;j<count;j++){
                fscanf(fp,"%d\t",&stu[i].score[j]);
                printf("%d\t",stu[i].score[j]);
            }
        }
        k++;
        i++;
    }
    fclose(fp);
    printf("\n���ݶ�ȡ�ɹ���\n");
}
void mycourse(struct student stu[]){
    int count,i,j;
    char c[M][20];
    printf("����γ�����<%d:\n",M);
    scanf("%d",&count);
    getchar();
    for(i=0;i<count;i++){
        printf("�����%d�ſγ̵����ƣ�\n",i+1);
        gets(c[i]);
    }
    for(i=0;i<N;i++){
        printf("����ѧ�ţ�\n");
        scanf("%d",&stu[i].num);
        getchar();
        printf("����������\n");
        scanf("%s",&stu[i].name);
        for(j=0;j<count;j++){
            strcpy(stu[i].course[j],c[j]);
        }
        for(j=0;j<count;j++){
            printf("������%s�ĳɼ�:",stu[i].course[j]);
            scanf("%d",&stu[i].score[j]);
        }
    }
    printf("ѧ��\t����\t");
    for(j=0;j<count;j++){
        printf("%s\t",stu[0].course[j]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%4d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++)
            printf("%4d\t",stu[i].score[j]);
        printf("\n");
    }
}
