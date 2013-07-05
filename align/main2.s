	.file	"main2.c"
	.section	.rodata
	.type	pattern, @object
	.size	pattern, 5
pattern:
	.byte	0
	.byte	1
	.byte	2
	.byte	4
	.byte	8
.LC0:
	.string	"toto is     0x%08x\n"
.LC1:
	.string	"toto is now 0x%08x\n"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$48, %rsp
.LCFI2:
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$pattern+1, -16(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	xorl	%eax, -4(%rbp)
	movl	-4(%rbp), %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
	.ident	"GCC: (GNU) 4.3.2 20081105 (Red Hat 4.3.2-7)"
	.section	.note.GNU-stack,"",@progbits
