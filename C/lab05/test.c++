#include <bits/stdc++.h>
using namespace std;

int numberOfBlocks(unsigned int addr_bits, unsigned int num_block_offset_bits){
    if(addr_bits <= 0) return -1;
    if(num_block_offset_bits <= 0) return -1;
    if(addr_bits < num_block_offset_bits) return -1;

    return ((addr_bits) /  (1 << num_block_offset_bits));

} // end numberOfBlocks function

int main(){

    cout << numberOfBlocks(256, 2) << '\n';
    
}