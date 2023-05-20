// PID: 730478505
// I pledge the COMP 211 honor code.

#include "bit_utils.h"

char* itob(int num, int size){
    char *string;
    string = (char*)malloc(size);
    //creates and allocates char array in heap
    string[size] = '\0';
    //ensures correct string length

    bool is_positive = num > 0;
    //checks sign of number

    int result[size];
    for(int i = 0; i < size; ++i)result[i] = 0;
    int i = 0;

    while(num != 0){
        //formats integer into binary representation
        if((num % 2 == 1) || (num % 2 == -1))result[i] = 1;
        else result[i] = 0;
        num /= 2;
        ++i;
    }

    int ans[size];
    for(int i = 0; i < size; ++i)ans[i] = result[size - 1 - i];
    //reverses binary representation to match true form
    
        if(is_positive){
            for(int i = 0; i < size; ++i){
                string[i] = ans[i] == 0 ? '0' : '1';
                //converts binary to string representation
            }
        }
    
        else{
            for(int i = 0; i < size; ++i)ans[i] ^= 1;
            //takes complement of all binary values

            for(int i = size - 1; i >= 0; --i){
                //adds one to complement
                ans[i] ^= 1;
                if(ans[i] == 1) break;
            }
            
            for(int i = 0; i < size; ++i){
                string[i] = ans[i] == 0 ? '0' : '1';
                //converts binary to string representation
            }
        }
        return string;
}

int mask_bits(int num, int mask){
    return num & mask; 
}

int set_bits(int num, int bits){
    return num | bits;
}

int inverse_bits(int num, int bits){
    return num ^ bits;
}

int bit_select(int num, int startbit, int endbit){
    unsigned int shift = startbit - endbit;
    //gets num of bits to select
    unsigned int u_num = (unsigned int) num;
    
    unsigned int mask = (1 << (shift + 1)) - 1;
    // creates mask including both startbit and endbit
    
    mask = mask << (unsigned int)endbit;
    //puts mask in correct location
    
    return (u_num & mask) >> endbit;
    //right shifts to correct bit locations
}