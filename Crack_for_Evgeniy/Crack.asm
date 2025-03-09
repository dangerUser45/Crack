 .model tiny

 .code
 locals @@
 org 100h

;//////////////////////////////////////////////
    MAX_NUMBER_ENTER_SYM    equ     10d
;/////////////////////////////////////////////
    NEW_LINE macro
    push ax
        mov ah, 2
        mov dl, 13
        int 21h
        
        mov dl, 10
        int 21h
        pop ax
    endm
;/////////////////////////////////////////////

  Start: jmp MAIN

    MAIN:

    push cs
    pop ds

    mov byte ptr ds:[BUFFER], MAX_NUMBER_ENTER_SYM + 100
    mov bx, 252d

    cld

    lea dx, MESSAGE
    mov ah, 09h
    int 21h
    NEW_LINE

    jmp CYCLE
    BUFFER:   db 12d dup(90h)

    CYCLE: 
        mov ah, 0ah;----------|
        lea dx, BUFFER       ;|  Ввод пароля пользователем
        int 21h              ;|
        NEW_LINE;-------------|

        mov byte ptr ds:[BUFFER], MAX_NUMBER_ENTER_SYM

        mov cx, 9
        lea si, BUFFER + 2
        lea di, PASSWORD

        repe cmpsb
        jne @@WRONG_PASSWORD
        je  RIGHT_PASSWORD

        @@CHECK_BX_AND_MEMORY_VALUE:
            cmp bx, 0h
            jz @@CHECK_MEMORY_VALUE
            dec bx
            jmp CYCLE

            @@CHECK_MEMORY_VALUE:
                cmp byte ptr ds:[NUMBER_TRY_ENTER_PASSWORD], 0h
                push ax
                mov al, byte ptr ds:[NUMBER_TRY_ENTER_PASSWORD]
                dec al
                mov byte ptr ds:[NUMBER_TRY_ENTER_PASSWORD], al
                pop ax
                jnz CYCLE

            db 0e9h
            dw 1ch

    @@WRONG_PASSWORD:
        lea dx, MESS_WRONG_PSWRD
        mov ah, 09h
        int 21h
        NEW_LINE

        lea dx, MESSAGE
        mov ah, 09h
        int 21h

        jmp @@CHECK_BX_AND_MEMORY_VALUE

    RIGHT_PASSWORD:
        lea dx, MESS_RIGHT_PSWRD
        mov ah, 09h
        int 21h
        NEW_LINE
    @@TERMINATE_PROGRAMM:
        mov ax, 4c00h
        int 21h
;/////////////////////////////////////////////
 ;Hash_func proc


 ;endp
;/////////////////////////////////////////////
 ;BUFFER:   db 100d dup(0)
 MESSAGE:  db "Enter the password: $"
 PASSWORD: db "Sigma_boy$"
 MESS_WRONG_PSWRD: db "You enter wrong password$"
 MESS_RIGHT_PSWRD: db "Yes, right password! YOU ARE TRUE SIGMA BOY CHIKI RAU$"
 NUMBER_TRY_ENTER_PASSWORD: db 81d
;/////////////////////////////////////////////
 end    Start