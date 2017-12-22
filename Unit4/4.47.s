	.file	"4.47.c"
	.text
	.globl	bubble_p
	.type	bubble_p, @function
bubble_p:
.LFB23:
	.cfi_startproc
	leaq	-1(%rsi), %r9
	jmp	.L2
.L4:
	leaq	8(%rdi,%rax,8), %rsi
	movq	(%rsi), %rcx
	leaq	(%rdi,%rax,8), %rdx
	movq	(%rdx), %r8
	cmpq	%r8, %rcx
	jge	.L3
	movq	%r8, (%rsi)
	movq	%rcx, (%rdx)
.L3:
	addq	$1, %rax
	jmp	.L5
.L6:
	movl	$0, %eax
.L5:
	cmpq	%r9, %rax
	jl	.L4
	subq	$1, %r9
.L2:
	testq	%r9, %r9
	jg	.L6
	rep ret
	.cfi_endproc
.LFE23:
	.size	bubble_p, .-bubble_p
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$64, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	$1, (%rsp)
	movq	$8, 8(%rsp)
	movq	$2, 16(%rsp)
	movq	$5, 24(%rsp)
	movq	$9, 32(%rsp)
	movq	$3, 40(%rsp)
	movq	$4, 48(%rsp)
	movl	$7, %esi
	movq	%rsp, %rdi
	call	bubble_p
	movl	$0, %ebx
	jmp	.L8
.L9:
	movslq	%ebx, %rax
	movq	(%rsp,%rax,8), %rdx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
.L8:
	cmpl	$6, %ebx
	jle	.L9
	movl	$0, %eax
	movq	56(%rsp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail
.L10:
	addq	$64, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
