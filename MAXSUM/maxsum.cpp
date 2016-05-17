#include <iostream>

using namespace std;

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
  } 
  //여기서 최대합을 찾아줘야한다

  //출력부
  for(int i=0; i<count; i++)
  {
    cout<< Maxsum[i]<<endl; 
  }

  delete Maxsum;
  
}

