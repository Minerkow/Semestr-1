
	.file	"func1.c"
	.intel_syntax noprefix
	.text
	.globl	function
	.type	function, @function
function:
.LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 16
	mov	DWORD PTR [ebp-8], -1
	mov	DWORD PTR [ebp-4], 1
	jmp	.L2
.L4:
	mov	eax, DWORD PTR [ebp-4]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	cmp	eax, DWORD PTR [ebp-8]
	jl	.L3
	mov	eax, DWORD PTR [ebp-4]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-8], eax
.L3:
	add	DWORD PTR [ebp-8], 2
	add	DWORD PTR [ebp-4], 1
.L2:
	mov	eax, DWORD PTR [ebp-4]
	cmp	eax, DWORD PTR [ebp+8]
	jl	.L4
	mov	eax, DWORD PTR [ebp-8]
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	function, .-function
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-7)"
	.section	.note.GNU-stack,"",@progbits
