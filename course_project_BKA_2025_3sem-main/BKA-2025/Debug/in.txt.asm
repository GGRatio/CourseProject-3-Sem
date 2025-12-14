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
		LTRL1 byte 'sdd', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		mainx dword ?
.code

;----------- MAIN ------------
main PROC
mov mainx, offset LTRL1

push mainx
call outrad

push 0
call ExitProcess
main ENDP
end main
