#include "cpu/instr.h"

// NOT inverts the operand; every 1 becomes a 0, and vice versa.
static void instr_execute_1op() {
    operand_read(&opr_src);
    opr_src.val = ~opr_src.val;
    operand_write(&opr_src);
}

make_instr_impl_1op(not, rm, b)
make_instr_impl_1op(not, rm, v)
