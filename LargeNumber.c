#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000  //定义最大位数

void init(int a[],int b[],int *L1,int *L2,char *op,int *err,char signal)  //读入两个整数及长度
{
    *err=0;
    int i,j;
    char p,q,r,s;
    for(i=0;i<=MAX;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    p=signal;
    if(p=='\n')  //判断是否为空行
    {
        *err=1;
        i=1;
    }
    else if(p=='-')
    {
        a[0]=1;
        p=getchar();
        while(p=='0')  //去掉输入前端的所有0
        {
            p=getchar();
            if(((p-'0')<0||(p-'0')>9)&&p!='\n')
                *err=1;
        }
        if(p=='\n')    //判断输入是否为0
        {
            a[1]=0;
            i=1;
        }
        else
        {
            if((p-'0')>=0&&(p-'0')<=9)  //判断是否为数字
                a[1]=p-'0';
            else
                *err=1;
            for(i=2;(p=getchar())!='\n';i++)
            {
                if(i>MAX)  //判断是否超过10万位
                {
                    *err=1;
                    return ;
                }
                if((p-'0')>=0&&(p-'0')<=9)
                    a[i]=p-'0';
                else
                    *err=1;
            }
        }
    }
    else if(p=='+')
    {
        a[0]=0;
        p=getchar();
        while(p=='0')
        {
            p=getchar();
            if(((p-'0')<0||(p-'0')>9)&&p!='\n')
                *err=1;
        }
        if(p=='\n')
        {
            a[1]=0;
            i=1;
        }
        else
        {
            if((p-'0')>=0&&(p-'0')<=9)
                a[1]=p-'0';
            else
                *err=1;
            for(i=2;(p=getchar())!='\n';i++)
            {
                if(i>MAX)
                {
                    *err=1;
                    return ;
                }
                if((p-'0')>=0&&(p-'0')<=9)
                    a[i]=p-'0';
                else
                    *err=1;
            }
        }
    }
    else
    {
        if((p-'0')>=0&&(p-'0')<=9)
            a[0]=0;
        else
            *err=1;
        while(p=='0')
        {
            p=getchar();
            if(((p-'0')<0||(p-'0')>9)&&p!='\n')
                *err=1;
        }
        if(p=='\n')
        {
            a[1]=0;
            i=1;
        }
        else
        {
            if((p-'0')>=0&&(p-'0')<=9)
                a[1]=p-'0';
            else
                *err=1;
            for(i=2;(p=getchar())!='\n';i++)
            {
                if(i>MAX)
                {
                    *err=1;
                    return ;
                }
                if((p-'0')>=0&&(p-'0')<=9)
                    a[i]=p-'0';
                else
                    *err=1;
            }
        }
    }
    *L1=i-1;  //得到数字的位数
    q=getchar();  //第二个数字基本同上
    if(q=='\n')
    {
        *err=1;
        j=1;
    }
    if(q=='-')
    {
        b[0]=1;
        q=getchar();
        while(q=='0')
        {
            q=getchar();
            if(((q-'0')<0||(q-'0')>9)&&q!='\n')
                *err=1;
        }
        if(q=='\n')
        {
            b[1]=0;
            j=1;
        }
        else
        {
            if((q-'0')>=0&&(q-'0')<=9)
                b[1]=q-'0';
            else
                *err=1;
            for(j=2;(q=getchar())!='\n';j++)
            {
                if(j>MAX)
                {
                    *err=1;
                    return ;
                }
                if((q-'0')>=0&&(q-'0')<=9)
                    b[j]=q-'0';
                else
                    *err=1;
            }
        }
    }
    else if(q=='+')
    {
        b[0]=0;
        q=getchar();
        while(q=='0')
        {
            q=getchar();
            if(((q-'0')<0||(q-'0')>9)&&q!='\n')
                *err=1;
        }
        if(q=='\n')
        {
            b[1]=0;
            j=1;
        }
        else
        {
            if((q-'0')>=0&&(q-'0')<=9)
                b[1]=q-'0';
            else
                *err=1;
            for(j=2;(q=getchar())!='\n';j++)
            {
                if(j>MAX)
                {
                    *err=1;
                    return ;
                }
                if((q-'0')>=0&&(q-'0')<=9)
                    b[j]=q-'0';
                else
                    *err=1;
            }
        }
    }
    else
    {
        if((q-'0')>=0&&(q-'0')<=9)
            b[0]=0;
        else
            *err=1;
        while(q=='0')
        {
            q=getchar();
            if(((q-'0')<0||(q-'0')>9)&&q!='\n')
                *err=1;
        }
        if(q=='\n')
        {
            b[1]=0;
            j=1;
        }
        else
        {
            if((q-'0')>=0&&(q-'0')<=9)
                b[1]=q-'0';
            else
                *err=1;
            for(j=2;(q=getchar())!='\n';j++)
            {
                if(j>MAX)
                {
                    *err=1;
                    return ;
                }
                if((q-'0')>=0&&(q-'0')<=9)
                    b[j]=q-'0';
                else
                    *err=1;
            }
        }
    }
    *L2=j-1;
    r=getchar();
    if(r=='\n')  //判断符号行是否为空行
    {
        *op=0;
        *err=1;
    }
    else if((r=='+'||r=='-'||r=='*'||r=='/')&&(s=getchar())=='\n')  //判断是否为符合条件的符号
        *op=r;
    else
    {
        *op=0;
        while(s!='\n')  //读完整行
            s=getchar();
        *err=1;
    }
}

int add(int a[],int b[],int c[],int L1,int L2)  //加法
{
    int d[MAX+2]={0};
    int i,j,k;
    for(i=1;i<=MAX;i++)
        c[i]=0;
    if(a[1]==0)
    {
        for(i=0;i<=L2;i++)
            c[i]=b[i];
        return i-1;
    }
    if(b[1]==0)
    {
        for(i=0;i<=L1;i++)
            c[i]=a[i];
        return i-1;
    }
    for(i=L1,j=L2,k=1;i>0&&j>0;i--,j--,k++)  //从最低位开始，对应位相加，如果进位，本位减10，高位加1
    {
        d[k]=a[i]+b[j]+d[k];
        if(d[k]>=10)
        {
            d[k+1]++;
            d[k]-=10;
        }
    }
    while(i>0)
    {
        d[k]=a[i]+d[k];
        if(d[k]>=10)
        {
            d[k+1]++;
            d[k]-=10;
        }
        k++;
        i--;
    }
    while(j>0)
    {
        d[k]=b[j]+d[k];
        if(d[k]>=10)
        {
            d[k+1]++;
            d[k]-=10;
        }
        k++;
        j--;
    }
    if(d[k]==0)  //确保最高位不是0
        k--;
    for(i=1;k>0;i++,k--)
        c[i]=d[k];    //反序保存
    return i-1;
}

int abscompare(int a[],int b[],int L1,int L2)  //比较两数绝对值大小
{
    int i;
    if(L1>L2)
        return 1;
    else if(L1<L2)
        return -1;
    else
        for(i=1;i<=L1;i++)
        {
            if(i==L1&&a[i]==b[i])
                return 0;
            if(a[i]>b[i])
                return 1;
            else if(a[i]<b[i])
                return -1;
            else
                continue;
        }
}

int absdiff(int a[],int b[],int c[],int L1,int L2)  //计算两个数中,大数和小数的绝对差
{
    int flag=abscompare(a,b,L1,L2);
    if(flag==0)
    {
        c[0]=0;
        c[1]=0;
        return 0;
    }
    int d[MAX+1]={0};
    int i,j,k;
    for(i=1;i<=MAX;i++)
        c[i]=0;
    if(a[1]==0)
    {
        for(i=0;i<=L2;i++)
            c[i]=b[i];
        return i-1;
    }
    if(b[1]==0)
    {
        for(i=0;i<=L1;i++)
            c[i]=a[i];
        return i-1;
    }
    for(i=L1,j=L2,k=1;i>0&&j>0;i--,j--,k++)  //从最低位开始，对应位相减，如果借位，本位加10，高位减1
    {
        d[k]=d[k]+(a[i]-b[j])*flag;
        if(d[k]<0)
        {
            d[k]+=10;
            d[k+1]--;
        }
    }
    while(i>0)
    {
        d[k]=d[k]+a[i];
        k++;
        i--;
    }
    while(j>0)
    {
        d[k]=d[k]+b[j];
        k++;
        j--;
    }
    while(d[k]==0)  //确保前端没有0
        k--;
    for(i=1;k>0;i++,k--)
        c[i]=d[k];
    return i-1;
}

int multi(int a[],int b[],int c[],int L1,int L2)  //乘法
{
    int d[MAX+1]={0},e[MAX+1]={0};
    int i,j,k,p,q,x,y;
    for(i=1;i<=2*MAX;i++)
        c[i]=0;
    y=0;
    for(i=L1,p=1;i>0;i--,p++)  //一个数的每一位乘以另一个数的每一位然后相加
    {
        for(q=1;q<=MAX;q++)
        {
            d[q]=0;
            e[q]=0;
        }
        for(j=L2,k=p;j>0;j--,k++)
        {
            d[k]=a[i]*b[j]+d[k];
            if(d[k]>=10)
            {
                d[k+1]+=d[k]/10;
                d[k]=d[k]%10;
            }
        }
        if(d[k]==0)
            k--;
        x=k;
        for(q=1;k>0;q++,k--)
            e[q]=d[k];
        y=add(c,e,d,y,x);
        for(q=1;q<=y;q++)
            c[q]=d[q];
    }
    return y;
}

void divi(int a[],int b[],int c[],int d[],int L1,int L2,int *L3,int *L4,int *err)  //两个正整数的除法
{
    int e[MAX]={0},f[MAX]={0};
    int i,j,k=1,Le;
    for(i=0;i<=MAX;i++)
    {
        c[i]=0;
        d[i]=0;
    }
    if(a[0]==1||b[0]==1||L2==0)  //判断输入是否满足除法条件
    {
        *err=1;
        return ;
    }
    int flag;
    flag=abscompare(a,b,L1,L2);
    if(flag==-1)
    {
        c[1]=0;
        *L3=0;
        for(i=1;i<=L1;i++)
            d[i]=a[i];
        *L4=L1;
    }
    else if(flag==0)
    {
        c[1]=1;
        *L3=1;
        d[1]=0;
        *L4=0;
    }
    else if(flag==1)  //模拟手算过程
    {
        for(i=1;i<=L2;i++)  //从最高位开始试商，因此不需要反序保存
            e[i]=a[i];
        i--;
        Le=L2;
        flag=abscompare(e,b,Le,L2);
        if(flag==-1)
        {
            i++;
            if(i<=L1)
            {
                e[i]=a[i];
                Le=L2+1;
            }
            while(i<=L1)
            {
                while(abscompare(e,b,Le,L2)>=0)
                {
                    Le=absdiff(e,b,d,Le,L2);
                    f[k]++;                    //商的每一位都是0~9尝试
                    for(j=1;j<=Le;j++)
                        e[j]=d[j];             //计算余数
                }
                i++;
                if(i<=L1)
                {
                    e[Le+1]=a[i];
                    Le++;
                }
                if(e[1]==0&&Le!=0)
                    Le=0;
                k++;
            }
            k--;
            for(i=1;i<=k;i++)
                c[i]=f[i];
            *L3=k;
            *L4=Le;                  //计算出商和余数的位数
        }
        else if(flag>=0)
        {
          while(i<=L1)
            {
                while(abscompare(e,b,Le,L2)>=0)
                {
                    Le=absdiff(e,b,d,Le,L2);
                    f[k]++;
                    for(j=1;j<=Le;j++)
                        e[j]=d[j];
                }
                i++;
                if(i<=L1)
                {
                    e[Le+1]=a[i];
                    Le++;
                }
                if(e[1]==0&&Le!=0)
                    Le=0;
                k++;
            }
            k--;
            for(i=1;i<=k;i++)
                c[i]=f[i];
            *L3=k;
            *L4=Le;
        }
    }
}

void printnum(int a[],int L)  //输出数字
{
    int i;
    if(L==0)
    {
        printf("0");
        return ;
    }
    if(a[0]==1)
        printf("-");
    for(i=1;i<=L;i++)
        printf("%d",a[i]);
}

void operation(char signal)  //计算函数
{
    int *a,*b,*c,*d,L1,L2,L3,L4,err;
    char op;
    if((a=(int *)malloc((MAX+1)*sizeof(int)))==NULL){    //分配内存
        printf("内存分配失败!\n");
        exit(1);
    }
    if((b=(int *)malloc((MAX+1)*sizeof(int)))==NULL){
        printf("内存分配失败!\n");
        exit(1);
    }
    if((c=(int *)malloc(2*(MAX+1)*sizeof(int)))==NULL){
        printf("内存分配失败!\n");
        exit(1);
    }
    if((d=(int *)malloc((MAX+1)*sizeof(int)))==NULL){
        printf("内存分配失败!\n");
        exit(1);
    }
    init(a,b,&L1,&L2,&op,&err,signal);   //初始化读入
    if(err==1)          //判断输入是否错误
    {
        printf("Error input!\n");
        return ;
    }
    if(op=='+')        //'+'情形下分为同号和异号计算
    {
        if(a[0]==b[0])
        {
            c[0]=a[0];
            L3=add(a,b,c,L1,L2);
        }
        else if(a[0]==0&&b[0]==1)
        {
            int flag=abscompare(a,b,L1,L2);
            if(flag==1||flag==0)
                c[0]=0;
            else if(flag==-1)
                c[0]=1;
            L3=absdiff(a,b,c,L1,L2);
        }
        else if(a[0]==1&&b[0]==0)
        {
            int flag=abscompare(a,b,L1,L2);
            if(flag==1)
                c[0]=1;
            else if(flag==-1||flag==0)
                c[0]=0;
            L3=absdiff(a,b,c,L1,L2);
        }
        printnum(c,L3);
        printf("\n");
    }
    else if(op=='-')  //'-'情形下分为四种情形:正减正，负减负，正减负，负减正
    {
        if(a[0]==0&&b[0]==0)
        {
            int flag=abscompare(a,b,L1,L2);
            if(flag==1||flag==0)
                c[0]=0;
            else if(flag==-1)
                c[0]=1;
            L3=absdiff(a,b,c,L1,L2);
        }
        else if(a[0]==1&&b[0]==1)
        {
            int flag=abscompare(a,b,L1,L2);
            if(flag==1)
                c[0]=1;
            else if(flag==-1||flag==0)
                c[0]=0;
            L3=absdiff(a,b,c,L1,L2);
        }
        else if(a[0]==0&&b[0]==1)
        {
            c[0]=0;
            L3=add(a,b,c,L1,L2);
        }
        else if(a[0]==1&&b[0]==0)
        {
            c[0]=1;
            L3=add(a,b,c,L1,L2);
        }
        printnum(c,L3);
        printf("\n");
    }
    else if(op=='*')  //'*'情形下先确定结果的符号
    {
        if(a[0]==b[0])
            c[0]=0;
        else if(a[0]!=b[0])
            c[0]=1;
        L3=multi(a,b,c,L1,L2);
        printnum(c,L3);
        printf("\n");
    }
    else if(op=='/')  //'/'情形下先判断输入是否满足除法条件，再计算
    {
        divi(a,b,c,d,L1,L2,&L3,&L4,&err);
        if(err==1)
        {
            printf("Error input!\n");
            return ;
        }
        printnum(c,L3);
        printf(" ");
        printnum(d,L4);
        printf("\n");
    }
    free(a); a=NULL;
    free(b); b=NULL;
    free(c); c=NULL;
    free(d); d=NULL;
}

int main()
{
    char signal;
    while((signal=getchar())!=EOF)  //signal为每三行中的第一个字符，判断程序是否结束
        operation(signal);
    return 0;
}
