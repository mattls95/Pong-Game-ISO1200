#The MIPS interrupt system must be enabled with the ei instruction before it will accept any interrupts.
enable_interrupt:
ei
jr $ra
nop