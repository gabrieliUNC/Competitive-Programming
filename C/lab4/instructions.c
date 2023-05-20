// PID: 730478505
// I pledge the COMP 211 honor code.
#include <stdint.h>
#include <stdlib.h>

#include "instructions.h"
#include "bit_utils.h"

// ------------------------------------
// Function implementation that determines whether you are
// working with an R type or I type instruction
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      instruction_type: R_TYPE or I_TYPE (see instructions.h)
//
instruction_type get_type_of_instruction(uint32_t instruct){
    int bits = bit_select(instruct, OPCODE_START_BIT, OPCODE_END_BIT);
    if(bits == R_TYPE_OPCODE) return R_TYPE;
    return I_TYPE;
} // end get_type_of_instruction() function

// ------------------------------------
// Function implementation that creates an R-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an r_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: rs, rt, rd, shamt, func
//
r_instruction *create_r_instruction(uint32_t instruct){
    r_instruction *r = (r_instruction*)malloc(32 * sizeof(int));
    r->rs = bit_select(instruct, RS_START_BIT, RS_END_BIT);
    r->rt = bit_select(instruct, RT_START_BIT, RT_END_BIT);
    r->rd = bit_select(instruct, RD_START_BIT, RD_END_BIT);
    r->shamt = bit_select(instruct, SHAMT_START_BIT, SHAMT_END_BIT);
    r->func = bit_select(instruct, FUNC_START_BIT, FUNC_END_BIT);
    
    return r;
} // end create_r_instruction() function

// ------------------------------------
// Function implementation that creates an I-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an i_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: opcode, rs, rt, immediate
//
i_instruction *create_i_instruction(uint32_t instruct){
    i_instruction *i = (i_instruction*)malloc(32 * sizeof(int));
    i->opcode = bit_select(instruct, OPCODE_START_BIT, OPCODE_END_BIT);
    i->rs = bit_select(instruct, RS_START_BIT, RS_END_BIT);
    i->rt = bit_select(instruct, RT_START_BIT, RT_END_BIT);
    i->immediate = bit_select(instruct, IMMEDIATE_START_BIT, IMMEDIATE_END_BIT);

    return i;
} // end create_i_instruction() function


int main(){
    return 0;
}