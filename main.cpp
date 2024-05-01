// JAI KESAVA


#include<bits/stdc++.h>

using namespace std;
//#define endl "\n" /*for interactive problems remove this line*/
/*
-for ordered set problems policy based data sucture header
//PBDS

*/






typedef  long long  ll;
ll mod = pow(10,9)+7;



vector<int> construct(int x1,int y1,int x2, int y2){
    
   int cd= ((x2-x1)*y1- (y2-y1)*x1);
   
   vector<int> coeff; // a , b, c

   coeff.push_back(y2-y1);
   coeff.push_back(x1-x2);
   coeff.push_back(cd);

  return coeff;

}

int check(int a,int b,int c, vector<array<int,2>> &cord)
{
  for(int i=0;i<cord.size();i++)
  {
    int x= cord[i][0];
    int y= cord[i][1];

    if(a*x+b*y+c==0)
      continue;

     if(a*x+b*y+c>0)
      return 1;
    else
      return -1;
  }


}



int main()
{  
   
   
   int n;
   cin>>n;

   vector<array<int,2>> cord(n);

   for(int i=0;i<n;i++)
   {
    cin>>cord[i][0]>>cord[i][1];
   }


   vector<vector<int>> lines(n);

   for(int i=1;i<n;i++)
   {
    lines[i-1]= construct(cord[i-1][0],cord[i-1][1],cord[i][0],cord[i][1]); 
   }

   lines[n-1]= construct(cord[n-1][0],cord[n-1][1],cord[0][0],cord[0][1]);
   




   int px, py;

   cin>>px>>py;

   for(int i=0;i<lines.size();i++)
   {
     int a = lines[i][0];
       int b= lines[i][1];
       int c= lines[i][2];
     
      

       int cur= a*px+b*py+c;
       if(cur<0)
        cur=-1;
      else if(cur>0)
        cur=1;

      

       if((cur==0) || check(a,b,c,cord)==cur)
       {
         
       } 
       else
       {
        cout<<"Outside"<<endl;
        return 0;
       }


     
   }


   cout<<"Inside"<<endl;













 
   

   
 
  
    




}