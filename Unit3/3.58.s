	.file	"3.58.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB23:
	.cfi_startproc
	subq	%rdx, %rsi
	movq	%rsi, %rax
	salq	$63, %rax
	sarq	$63, %rax
	imulq	%rsi, %rdi
	xorq	%rdi, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	decode2, .-decode2
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
