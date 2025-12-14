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
		LTRL1 sdword 12
		LTRL2 sdword 10
		LTRL3 sdword 1
		LTRL4 sdword 3
		LTRL5 sdword 2
		LTRL6 sdword 4
		LTRL7 byte 'c', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		squarel dword 0
		mainx dword 0
		mainy dword 0
		mainp dword 0
		mainc dword 0
		squareb dword ?
.code

;----------- square ------------
square PROC,
	squarex : sdword, squarez : sdword  
; --- save registers ---
push ebx
push edx
; ----------------------
push LTRL1

pop ebx
mov squarel, ebx

; --- restore registers ---
pop edx
pop ebx
; -------------------------
mov eax, LTRL1
ret
square ENDP
;------------------------------


;----------- MAIN ------------
main PROC
push LTRL1

pop ebx
mov mainx, ebx


push LTRL1
push LTRL1
call square
push eax

pop ebx
mov mainy, ebx

push LTRL2

pop ebx
mov mainp, ebx

push LTRL1

pop ebx
mov mainc, ebx

push mainc
push LTRL3
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov mainc, ebx

mov edx, mainc
cmp edx, LTRL4

jl right1
jge wrong1
right1:

push LTRL5
call outlich

jmp next1
wrong1:

push LTRL6
call outlich

next1:
mov squareb, offset LTRL7
push 0
call ExitProcess
main ENDP
end main
