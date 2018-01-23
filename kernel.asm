;;kernel.asm
; I hate assembly so I stole this from other people, sorry mom
; There was no licensce from whoever I copied this off, so you deserve it
; But the C is all mine
bits 32
section .text
        align 4
        dd 0x1BADB002
        dd 0x00
        dd - (0x1BADB002 + 0x00)

global start
extern kmain

start:
  cli
  mov esp, stack_space
  call kmain
  hlt

section .bss
resb 8192
stack_space:
