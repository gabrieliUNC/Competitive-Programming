// PID: 730478505
// I pledge the COMP 211 honor code.

// -----------------------------------
// COMP 211 - Systems Fundamentals
// Fall 2021
// cache.c source file
// 
// Lab 05
//
// -----------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "cache.h"
#include "memory.h"

#define BLOCK_OFFSET_START 1
#define BLOCK_OFFSET_END 0
#define LINE_START 4
#define LINE_END 2
#define TAG_START 7
#define TAG_END 5
#define TAG_END_FA 2
#define BLOCK_NUMBER 4
#define LAST_LINE 7


int initializeCache(unsigned int number_of_lines){
    unsigned int line;
    int ret_val;

    ret_val = OK;

    // Allocate memory for the cache (array of cache lines).
    cache = malloc(sizeof(cache_line*) * number_of_lines);

    // For each cache line, allocate memory and initialize the cache line.
    if(cache != NULL){
        for (line=0; line<number_of_lines; line++){
            cache[line] = (cache_line*) malloc(sizeof(cache_line));
            cache[line]->tag = EMPTY;
            cache[line]->hit_count = ZERO;
        }
    }else
        ret_val = FAIL;

    return ret_val;

} // end initializeCache function


int cread(unsigned int cmf, unsigned int* hex_addr, unsigned int* found, unsigned int* replace){
    // retVal is either FAIL or the value of the requested hexadecimal address.
    // open_line indicates a line that is open, and thus usable.
    // replace_line indicates the cache line that should be replaced (in the direct mapping case).
    // min_hit_cnt is used in the fully associative case, and used to keep track of the LFU cache line.

    int ret_val = FAIL;
    int line, open_line, replace_line, min_hit_cnt;

    open_line = EMPTY;
    min_hit_cnt = (int)1E10;

    // tag is the tag bits
    // block_offset is the number of bits into a block the location is (Hint: Need to initialize).
    unsigned int tag, block_offset;

    // Variables to be passed by reference. - we want to indicate to the driver class whether we found the item we wanted in the cache and whether we had to overwrite and replace something
    (*found) = MISS;
    (*replace) = NO;

    if((cmf == DM) && ((*hex_addr) < exp2(addr_bits))){
        // TODO: PART 1 - DIRECT MAPPING ALGORITHM
        // FILL IN HERE

        block_offset = bit_select(*hex_addr, BLOCK_OFFSET_START, BLOCK_OFFSET_END);
        line = bit_select(*hex_addr, LINE_START, LINE_END);
        tag = bit_select(*hex_addr, TAG_START, TAG_END);


        if(cache[line]->tag == (int) tag){
             cache[line]->hit_count++;
             *found = HIT;
        }
        else if(cache[line]->tag == EMPTY){

            cache[line]->tag = tag;
            cache[line]->hit_count = HIT;

            unsigned int beg = (*hex_addr >> NUM_BLOCK_OFFSET_BITS) << NUM_BLOCK_OFFSET_BITS;

            for(int i = 0; i < BLOCK_NUMBER; ++i){
                cache[line]->block[i] = phy_memory[beg + i];
            }
            
        }
        else{
            *replace = YES;

            cache[line]->tag = tag;
            cache[line]->hit_count = HIT;

            unsigned int beg = (*hex_addr >> NUM_BLOCK_OFFSET_BITS) << NUM_BLOCK_OFFSET_BITS;

            for(int i = 0; i < BLOCK_NUMBER; ++i){
                cache[line]->block[i] = phy_memory[beg + i];
            }
        }

        ret_val = cache[line]->block[block_offset];
        

    }else if((cmf == FA) && ((*hex_addr) < exp2(addr_bits))){
        // TODO: PART 2 - FULLY ASSOCIATIVE ALGORITHM
        // FILL IN HERE

        block_offset = bit_select(*hex_addr, BLOCK_OFFSET_START, BLOCK_OFFSET_END);
        tag = bit_select(*hex_addr, TAG_START, TAG_END_FA);

        int min_hit_cnt_index = 0;


        for(int curr_line = 0; curr_line < NUM_OF_LINES; ++curr_line){
            cache_line *start = cache[curr_line];

            if(min_hit_cnt > start->hit_count){
                min_hit_cnt = start->hit_count;
                min_hit_cnt_index = curr_line;
            }

            if(start->tag == (int) tag){
                start->hit_count++;
                *found = HIT;
                break;
            }

            else if(start->tag == EMPTY){
                start->tag = tag;
                start->hit_count = HIT;

                unsigned int beg = (*hex_addr >> NUM_BLOCK_OFFSET_BITS) << NUM_BLOCK_OFFSET_BITS;

                for(int i = 0; i < BLOCK_NUMBER; ++i){
                    start->block[i] = phy_memory[beg + i];
                }
                break;
            }

            else if (curr_line == LAST_LINE){
                *replace = YES;

                cache[min_hit_cnt_index]->tag = tag;
                cache[min_hit_cnt_index]->hit_count = HIT;

                unsigned int beg = (*hex_addr >> NUM_BLOCK_OFFSET_BITS) << NUM_BLOCK_OFFSET_BITS;

                for(int i = 0; i < BLOCK_NUMBER; ++i){
                    cache[min_hit_cnt_index]->block[i] = phy_memory[beg + i];
            }
        }


        }

        ret_val = phy_memory[*hex_addr];
        

    }

    // Print out the state of the cache after the mapping algorithm has been applied.
    cprint();

    return ret_val;

} // end cread function

void cprint() {
    unsigned int line;

    printf("\n---------------------------------------------\n");
    printf("line\ttag\tnum of hits\n");
    printf("---------------------------------------------\n");

    for(line = 0; line < NUM_OF_LINES; line++){ 
        if(cache[line]->tag == EMPTY){
            printf("%d\t%d\t%d\n", line, cache[line]->tag, cache[line]->hit_count);
        }else{
            printf("%d\t%02X\t%d\n", line, cache[line]->tag, cache[line]->hit_count);
        }
    }

} // end cprint function