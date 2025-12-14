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
.data
		temp sdword ?
		buffer byte 256 dup(0)
		mainq dword 0
.code

;----------- MAIN ------------
main PROC
push LTRL1

pop ebx
mov mainq, ebx


push mainq
call outlich

push 0
call ExitProcess
main ENDP
end main
