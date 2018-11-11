#ifndef HEAP_HPP
#define HEAP_HPP

#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

// property data[i] >= data[2*i] && data[i] >= data[2*i+1]

struct heap {
    vector<double> data;

    // set size =1
    heap(){
        data.resize(1);
        data[0] = -INFINITY;
    }

    heap(int size){
        data.resize(size);
        for( double& val: data){
            val = -INFINITY;
        }
    }

    size_t size(){
        return data.size();
    }

    // restores order to the heap
    void fix(){

    }

    void resize(int size){
        data.resize(size);
    }

    // reset values to -INFINITY
    void reset(){
        for(double& val: data){
            val = -INFINITY;
        }
    }

    void findSpot(double input, int i){
        while( i < data.size()){
            if(data[2*i] == -INFINITY){
                data[2*i] = input;
                i = data.size();

            } else if(data[2*i+1] == -INFINITY){
                data[2*i+1] = input;
                i = data.size();
            }
            ++i;
        }
    }

    // insert the element, starting from the end working your way up
    void insert(double input){
        // find a spot witout nill
        int i = data.size();
        while(i > 0 && data[i-1] == -INFINITY){ 
           --i;
        }

       if(i ==0 ){
           data[0] = input;
       }
       
       while(i > 0){
            if(data[i/2] > input){
               i = i/2;
            }
            else if(data[i] <= input){
                double tmp = data[i];
                data[i] = input;

                if(data[i] == -INFINITY){
                    findSpot(tmp, i);
                }
                i =0; // reset to get out
                
            }
       }
    }

    void print(){
        int i = 0;
        while(data[i] != -INFINITY){
            cout << "Element " << i << " = " << data[i] << "\n";
            ++i;
        }
    }

    double operator[](int dex){
        return data[dex];
    }
};

#endif