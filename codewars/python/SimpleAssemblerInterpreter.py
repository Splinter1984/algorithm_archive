Description:
This is the first part of this kata series. Second part is here.
We want to create a simple interpreter of assembler which will support the following instructions:
mov x y - copies y (either a constant value or the content of a register) into register x
inc x - increases the content of the register x by one
dec x - decreases the content of the register x by one
jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward, y can be a register or a constant), but only if x (a constant or a register) is not zero
Register names are alphabetical (letters only). Constants are always integers (positive or negative).
Note: the jnz instruction moves relative to itself. For example, an offset of -1 would continue at the previous instruction, while an offset of 2 would skip over the next instruction.
The function will take an input list with the sequence of the program instructions and will execute them. The program ends when there are no more instructions to execute, then it returns a dictionary with the contents of the registers.
Also, every inc/dec/jnz on a register will always be preceeded by a mov on the register first, so you don't need to worry about uninitialized registers.

def simple_assembler(program):
    reg, i = {}, 0
    while i < len(program):
        cmd, k, v = (program[i] +' 0').split()[:3]
        if cmd == 'inc': reg[k] += 1
        if cmd == 'dec': reg[k] -= 1
        if cmd == 'mov': reg[k] = reg[v] if v in reg else int(v)
        if cmd == 'jnz' and (reg[k] if k in reg else int(k)):
            i += int(v) - 1
        i += 1
    return reg
