	.file	"main.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Usage: usbreset device-filename\n"
.LC1:
	.string	"Error opening output file"
.LC2:
	.string	"Resetting USB device %s\n"
.LC3:
	.string	"Error in ioctl"
.LC4:
	.string	"Reset successful"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$2, -20(%rbp)
	je	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$32, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$1, %eax
	jmp	.L3
.L2:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jns	.L4
	movl	$.LC1, %edi
	call	perror
	movl	$1, %eax
	jmp	.L3
.L4:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-16(%rbp), %eax
	movl	$0, %edx
	movl	$21780, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	ioctl
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L5
	movl	$.LC3, %edi
	call	perror
	movl	$1, %eax
	jmp	.L3
.L5:
	movl	$.LC4, %edi
	call	puts
	movl	-16(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
