section .text
bits 64
default rel

global x64SAXPYfunction

x64SAXPYfunction:
    push rbp
    mov rbp, rsp
    add rbp, 16
    xor rbx, rbx                   ; counter rbx = i
   
L1:
    movss xmm1, [rbp + 32]         ; xmm1 takes a
    movss xmm2, [rdx + rbx]        ; xmm2 takes x[i]
    movss xmm3, [r8 + rbx]         ; xmm3 takes y[i]

    mulss   xmm2, xmm1             ; xmm2 = a * x[i]
    addss   xmm2, xmm3             ; xmm2 = (a * x[i]) + y[i]
    movss   [r9 + rbx], xmm2       ; store result at z[i]
 
    add rbx, 4                     ; increment counter
    loop L1                        ; loop until rcx is zero  
    
    pop rbp
    ret
