 #include<stdio.h>  
 #include<stdlib.h>  
 int main(){  
     int i,j,l,n,k,sum=0,flat=1,c=-1;
     char *a;
     scanf("%d",&n);
     a=(char *)malloc(n*sizeof(char));
     scanf("%s",a);
     j=n-1;  
     //����̰�ĵ�˼�룬��ÿ���������ַ��ҵ�����������ͬ��Ȼ�󽻻�����ȷ��λ��ʱ����Ľ�������   
     for(i=0;i<j;i++){
         for(k=j;k>=i;k--){
             if(k==i){//˵��û���ҵ���a[i]��ͬ���ַ�   
                 if(n%2==0||c!=-1){//���nΪż������a[i]����Ψһһ����������ͬ�ַ�   
                     flat=0;
                     break;
                 }
                 c=1;//nΪ����������һ���������ַ�a[i]�Ƶ��м�λ������Ľ�������   
                 sum=sum+n/2-i;
                 break;
             }
             if(a[k]==a[i]){
                 for(l=k;l<j;l++){  
                     a[l]=a[l+1];  
                 }  
                 a[j]=a[i];  
                 sum=sum+j-k;  
                 j--;  
                 break;  
             }  
         }  
         if(flat==0){
             break;
         } 
     }  
     if(flat==0)
         printf("Impossible");
     else if(sum==0)
         printf("0");
     else 
         printf("%d\n",sum);
     return 0;  
}