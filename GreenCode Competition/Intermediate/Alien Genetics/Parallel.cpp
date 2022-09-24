 #include <iostream>
 #include <omp.h>
 #include <stdio.h>
 using namespace std;

 int main(){
 	int cases, len, guess;
 	cin >> cases;
 	while(cases--){
 	    cin >> len;
 	    string s;
 	    cin >> s;
 	    volatile bool checker = true;
 	    omp_set_num_threads(2);
 	    int ray[] = {0,0};
 	    #pragma omp parallel for private(guess, checker) shared(len)
 	    for(guess = 1; guess <= len; guess++){
 	        if(checker) continue;
 		    bool good = true;

 		    for(int i = 0; i + guess <= len; i++){
 			    for(int j = 0; j < i; j++){
 				    if(s.substr(i, guess) == s.substr(j, guess)){
 					    good = false;
 				    }
 			    }
 		    }
 		    if(good){
 			    ray[omp_get_thread_num()] = guess;
 			    checker = false;
 		    }
 	    }
 	    cout << min(ray[0], ray[1]) << endl;
 	}
 	
 }