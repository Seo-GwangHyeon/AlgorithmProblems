#include <iostream>

using namespace std;

int Sumcount(int *array, int fir, int last);
int findFirst(int *arr, int fir, int last);
int findLast(int *arr, int fir, int last);


int main()
{
  int count =0;
  int array[100000]={0}; //수열을 저장하는 배열 
  int *Maxsum; //결과를 담는 배열

  cin>> count;

  Maxsum = new int[count];

  for(int i=0; i<count;i++)
  {
    int length =0;
    cin>> length;
    for(int j =0; j<length; j++)
    {
      cin>>array[j]; 
      //배열에 숫자를 넣는다.
    }
    //여기서 최대합을 찾아줘야한다
    Maxsum[i]=Sumcount(array, 0, length);
  } 
  
  // 생각한 알고리즘
  //  우선 가장 중요한 키워드는 재귀 함수이다
  //  앞에서 뒤로가며 음수를 체크해 음수가 나오면
  // 입력한 첫위치부터 음수까지 더해 +- 판별 그리고 
  // +이면 첫위치 그대로 -면 첫위치를 -다음위치로
  // 그리고 마지막위치에서도 똑같이 마지막위치를 재설정한다
  // 그리고 음수를 재귀함수를 사용하면 
  // 최대 값이 나올것이다.
  


  //출력부
  for(int i=0; i<count; i++)
  {
    cout<< Maxsum[i]<<endl; 
  }

  delete Maxsum;
  
}

int Sumcount(int *array, int fir, int last)
{
  int F=findFirst(array, fir, last) ;
  int L=findLast(array,fir, last);    
  int sum=0;
  for(int i=F; i<L+1;i++)
     sum+=array[i];
  return sum;
}

int findFirst(int *arr, int fir, int last)
{
  for(int i=fir;i<last;i++)
  {
    if(arr[i]<0)
    {
       int sum =0;
       for(int j=fir; j<i+1; j++)
       {
         sum +=arr[j]; 
       }
       if(sum<0)
         findFirst(arr, i, last); 
       else if(sum>0)
         return i;
    }
  } 
  return fir;
}
int findLast(int *arr,int fir , int last)
{
  for(int i=last-1;i>fir-1;i--)
  {
    if(arr[i]<0)
    {
       int sum =0;
       for(int j=last; j>i-1; j--)
       {
         sum +=arr[j]; 
       }
       if(sum<0)
         findLast(arr, fir, i); 
       else if(sum>0)
         return i;
    }
  } 
  return last;
}
