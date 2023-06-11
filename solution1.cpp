#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

class Listy{

public:
    int* _v = NULL;
    int _l;

    Listy(int* v,int l){
    	_v = v;
        _l = l;
    }

    int get(int i){
        if(i >= _l){
            return -1;
        }
        return _v[i];
    }


};

	/*Given a sorted Listy,find the index of the element x,but you must build an algorithm with the assumption that you dont the size
	 * oh this Listy,the only thing you now is that if an element is out of bound the get method will return -1.
	 */

int binary_search(int* v,int n,int p);

int find_max(Listy l);

bool check_max(Listy l,int idx);

int main()
{
	//  || \

	//Just to simulate,you cant use the size of the array,you must asssume that you dont now it!
    int v[] = {3,5,7,8,9,10,14,100};
    Listy l = Listy(v,sizeof(v)/sizeof(int));

    /*find_max is a function that searchs the index of max value of a sroted array,so that you now the max index and apply binary search
     * this function time complexity depends os the differecne between the guess and the actual size of the array
     * if |guess - lenght| = 0 --> O(log(guess));if |guess - leght| >> 0(>> means much bigger) --> O(guess).The closer the guess
     * the closer to log.
     */



    int x = binary_search(l._v,find_max(l),14);
    printf("index: %d\n",x);



    return 0;
}

int binary_search(int* v,int n,int p){

	//standart binary search

	int low = 0;
	int high = n;
	int mid;

	while(low <= high){

		mid = (low+high)/2;

		if(v[mid] == p){
			return mid;
		}
		if(v[mid] <  p){
			low = mid+1;
		}
		if(v[mid] > p){
			high = mid-1;
		}
	}
	return -1;
}

bool check_max(Listy l,int idx){

	if(l.get(idx) != -1 && l.get(idx+1) == -1){
			return true;
	}
	return false;

}

int find_max(Listy l){

	if(l._v != NULL){

		int guess = 10;//the more you now about about what kind of system you are working the better the guess

		int low = 0;
		int mid;
		while(true){

			mid = (low+guess)/2;
			//printf("max: %d\n",mid);
			if(check_max(l,mid)){
				return mid;
			}
			if(check_max(l,guess)){
				return guess;
			}
			if(check_max(l,low)){
				return low;
			}
			else{
				if(l.get(guess) == -1){

					guess = mid;

				}
				if(l.get(guess) != -1){

					low = mid;
					guess += mid;

				}
			}


		}
	}
	return -1;
}
