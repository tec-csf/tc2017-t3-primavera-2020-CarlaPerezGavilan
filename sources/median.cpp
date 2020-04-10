
#include <vector>
#include <cstdlib>
#include <iostream>


using namespace std; 
  
template <class T>
class Media{
    public: 


T twoArrayMedian(T arr_a[], T arr_b[], int n)
{
       if(n<=0){
           return -1;
       }

       if(n==1){
           return (arr_a[0]+arr_b[0])/2;
       }

        if(n==2){
            return (max(arr_a[0],arr_b[0])+min(arr_a[1], arr_b[1]))/2;
        }

       int median_a = getMedian(arr_a, n);
       int median_b = getMedian(arr_b, n);

       if(median_a==median_b){
           return median_b;
       }

    if(median_a>median_b){
        if(n%2==0){
        return twoArrayMedian(arr_a + n / 2 - 1,  
                             arr_b, n - n / 2 + 1); 

        }else{
        return twoArrayMedian(arr_a + n / 2,  
                         arr_b, n - n / 2);
        }
    }

     if(n%2==0){
            return twoArrayMedian(arr_b + n / 2 - 1,  
                         arr_a, n - n / 2 + 1);
        }else{
            return twoArrayMedian(arr_b + n / 2,  
                     arr_a, n - n / 2);
        }

}

//function that gets median of vectorn
int getMedian(int sort_vect[], int n)
{
    if(n%2==0){
        return (sort_vect[n/2]+sort_vect[n/2+1])/2;
    }else{
        return sort_vect[n/2];
    }
}



};



int main() 
{ 
    Media<int> m;
    int size=5;
    int a[] = {1, 12, 15, 26, 38}; 
    int b[] = {2, 13, 17, 30, 45}; 
    cout<<"this is result= "<< m.twoArrayMedian(a, b, size)<<endl;
    return 0; 
} 
  

