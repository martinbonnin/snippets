	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"a=%u b=%u a-b=%u\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%ebx
	subl	$44, %esp
	movw	$5, 30(%esp)
	movw	$-1, 28(%esp)
	movzwl	28(%esp), %eax
	movzwl	30(%esp), %edx
	movl	%edx, %ecx
	subw	%ax, %cx
	movl	%ecx, %eax
	movzwl	%ax, %ebx
	movzwl	28(%esp), %ecx
	movzwl	30(%esp), %edx
	movl	$.LC0, %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	addl	$44, %esp
	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1 20100924 (Red Hat 4.5.1-4)"
	.section	.note.GNU-stack,"",@progbits
