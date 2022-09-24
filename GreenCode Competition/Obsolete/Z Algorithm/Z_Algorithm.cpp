#include <iostream>

using namespace std;

int main(){
	int length;
	cin >> length;
	char word[length];
	cin >> word;

	int solution[length];

	for(int i = 0; i < length; i++){
		int num = 0;
		bool done = false;
		char temp[length - i];
		//putting the "substring" into a temporary char array
		for(int index = 0; index < (length - i); index++){
			temp[index] = word[index + i];
		}
		//actually finding the solution
		for(int index = 0; index < (length - i) && !done; index++){
			if(temp[index] != word[index]){
				done = true;
			}else{
				num++;
			}
		}
		solution[i] = num;
	}

	for(int i = 0; i < length; i++){
		cout << solution[i] << " ";
	}

	return 0;
}

/*
PARALLEL VERSION BELOW
*/
//#include <iostream>
//
//using namespace std;
//
//int main(){
//	int length;
//	cin >> length;
//	char word[length];
//	cin >> word;
//    int i;
//	int solution[length];
//    #pragma omp parallel for private(i) shared(length)
//	for(i = 0; i < length; i++){
//		int num = 0;
//		bool done = false;
//		char temp[length - i];
//		putting the "substring" into a different char array
//		for(int index = 0; index < (length - i); index++){
//			temp[index] = word[index + i];
//		}
//		actually finding the solution
//		for(int index = 0; index < (length - i) && !done; index++){
//			if(temp[index] != word[index]){
//				done = true;
//			}else{
//				num++;
//			}
//		}
//		solution[i] = num;
//	}
//
//	for(int i = 0; i < length; i++){
//		cout << solution[i] << " ";
//	}
//
//	return 0;
//}
//
