#include "cpu/instr.h"

extern bool has_prefix;

make_instr_func(opcode_2_byte) {
    int len = 1;
    has_prefix = true;
    uint8_t op = instr_fetch(eip + 1, 1);
#ifdef NEMU_REF_INSTR
    len += __ref_opcode_2_byte_entry[op](eip + 1, op);
#else
    len += opcode_2_byte_entry[op](eip + 1, op);
#endif
    has_prefix = false;
    return len;
}
