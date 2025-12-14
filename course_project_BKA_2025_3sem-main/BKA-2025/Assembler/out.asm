.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
ExitProcess PROTO:DWORD 
.stack 4096


 outlich PROTO : DWORD

 outrad PROTO : DWORD

 mypow PROTO : DWORD, : DWORD, : DWORD

 myabs PROTO : DWORD, : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 byte 'Hello, World!', 0
		LTRL2 byte '=== Test Program ===', 0
		LTRL3 byte '1. Byte type (1 byte, -128..127):', 0
		LTRL4 sdword 10
		LTRL5 sdword 5
		LTRL6 byte 'a = ', 0
		LTRL7 byte 'b = ', 0
		LTRL8 byte '2. Arithmetic operations:', 0
		LTRL9 byte 'a + b = ', 0
		LTRL10 byte 'a - b = ', 0
		LTRL11 byte 'a * b = ', 0
		LTRL12 byte 'a / b = ', 0
		LTRL13 byte 'a % b = ', 0
		LTRL14 byte '3. Binary literal (0b1010 = 10):', 0
		LTRL15 byte '0b1010 = ', 0
		LTRL16 byte '4. Character type:', 0
		LTRL17 byte 'A', 0
		LTRL18 byte 'char ch = ', 0
		LTRL19 byte '5. Math functions:', 0
		LTRL20 sdword -5
		LTRL21 byte 'myabs(-5) = ', 0
		LTRL22 sdword 2
		LTRL23 sdword 3
		LTRL24 byte 'mypow(2, 3) = ', 0
		LTRL25 byte '6. Do-while loop (count from 1 to 5):', 0
		LTRL26 sdword 1
		LTRL27 byte ' ', 0
		LTRL28 sdword 6
		LTRL29 byte '7. If-else condition:', 0
		LTRL30 sdword 20
		LTRL31 byte 'x < y is true', 0
		LTRL32 byte 'x < y is false', 0
		LTRL33 byte '8. Function call:', 0
		LTRL34 sdword 4
		LTRL35 byte 'square(4) = ', 0
		LTRL36 byte '=== End of Test ===', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		squareresult dword 0
		maina dword 0
		mainb dword 0
		mainsum dword 0
		maindiff dword 0
		mainprod dword 0
		mainquot dword 0
		mainrem dword 0
		mainbin dword 0
		mainch dword ?
		mainneg dword 0
		mainabsval dword 0
		mainbase dword 0
		mainexp dword 0
		mainpowval dword 0
		maini dword 0
		mainx dword 0
		mainy dword 0
		hellosq dword 0
.code

;----------- square ------------
square PROC,
	squarex : sdword  
; --- save registers ---
push ebx
push edx
; ----------------------
push squarex
push squarex
pop ebx
pop eax
imul eax, ebx
push eax

pop ebx
mov squareresult, ebx

; --- restore registers ---
pop edx
pop ebx
; -------------------------
mov eax, squareresult
ret
square ENDP
;------------------------------


;----------- hello ------------
hello PROC 
	
; --- save registers ---
push ebx
push edx
; ----------------------

push offset LTRL1
call outrad

push offset newline
call outrad

; --- restore registers ---
pop edx
pop ebx
; -------------------------
ret
hello ENDP
;------------------------------


;----------- MAIN ------------
main PROC

push offset LTRL2
call outrad

push offset newline
call outrad


push offset LTRL3
call outrad

push offset newline
call outrad

push LTRL4

pop ebx
mov maina, ebx

push LTRL5

pop ebx
mov mainb, ebx


push offset LTRL6
call outrad


push maina
call outlich

push offset newline
call outrad


push offset LTRL7
call outrad


push mainb
call outlich

push offset newline
call outrad


push offset LTRL8
call outrad

push offset newline
call outrad

push maina
push mainb
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov mainsum, ebx


push offset LTRL9
call outrad


push mainsum
call outlich

push offset newline
call outrad

push maina
push mainb
pop ebx
pop eax
sub eax, ebx
jnc bk
neg eax
bk: 
push eax

pop ebx
mov maindiff, ebx


push offset LTRL10
call outrad


push maindiff
call outlich

push offset newline
call outrad

push maina
push mainb
pop ebx
pop eax
imul eax, ebx
push eax

pop ebx
mov mainprod, ebx


push offset LTRL11
call outrad


push mainprod
call outlich

push offset newline
call outrad

push maina
push mainb
pop ebx
pop eax
cdq
idiv ebx
push eax

pop ebx
mov mainquot, ebx


push offset LTRL12
call outrad


push mainquot
call outlich

push offset newline
call outrad

push maina
push mainb
pop ebx
pop eax
cdq
mov edx,0
idiv ebx
push edx

pop ebx
mov mainrem, ebx


push offset LTRL13
call outrad


push mainrem
call outlich

push offset newline
call outrad


push offset LTRL14
call outrad

push offset newline
call outrad

push LTRL4

pop ebx
mov mainbin, ebx


push offset LTRL15
call outrad


push mainbin
call outlich

push offset newline
call outrad


push offset LTRL16
call outrad

push offset newline
call outrad

mov mainch, offset LTRL17

push offset LTRL18
call outrad


push mainch
call outrad

push offset newline
call outrad


push offset LTRL19
call outrad

push offset newline
call outrad

push LTRL20

pop ebx
mov mainneg, ebx


push mainneg
push offset buffer
call myabs
push eax

pop ebx
mov mainabsval, ebx


push offset LTRL21
call outrad


push mainabsval
call outlich

push offset newline
call outrad

push LTRL22

pop ebx
mov mainbase, ebx

push LTRL23

pop ebx
mov mainexp, ebx


push mainexp
push mainbase
push offset buffer
call mypow
push eax

pop ebx
mov mainpowval, ebx


push offset LTRL24
call outrad


push mainpowval
call outlich

push offset newline
call outrad


push offset LTRL25
call outrad

push offset newline
call outrad

push LTRL26

pop ebx
mov maini, ebx

dowhile1:

push maini
call outlich


push offset LTRL27
call outrad

push maini
push LTRL26
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov maini, ebx

mov edx, maini
cmp edx, LTRL28
jl dowhile1
dowhilenext1:
push offset newline
call outrad


push offset LTRL29
call outrad

push offset newline
call outrad

push LTRL4

pop ebx
mov mainx, ebx

push LTRL30

pop ebx
mov mainy, ebx

mov edx, mainx
cmp edx, mainy

jl right2
jge wrong2
right2:

push offset LTRL31
call outrad

jmp next2
wrong2:

push offset LTRL32
call outrad

next2:
push offset newline
call outrad


push offset LTRL33
call outrad

push offset newline
call outrad


push LTRL34
call square
push eax

pop ebx
mov hellosq, ebx


push offset LTRL35
call outrad


push hellosq
call outlich

push offset newline
call outrad


call hello


push offset LTRL36
call outrad

push offset newline
call outrad

push 0
call ExitProcess
main ENDP
end main
