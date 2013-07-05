	.file	1 "main.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.text
	.align	2
	.globl	function1
	.ent	function1
	.type	function1, @function
function1:
	.frame	$sp,24,$31		# vars= 8, regs= 1/0, args= 0, extra= 8
	.mask	0x10000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	subu	$sp,$sp,24
	.cprestore 0
	sw	$28,16($sp)
	sw	$4,24($sp)
	li	$2,3			# 0x3
	sw	$2,8($sp)
	lw	$3,24($sp)
	sra	$2,$3,31
	srl	$2,$2,31
	addu	$2,$3,$2
	sra	$2,$2,1
	sw	$2,8($sp)
	lw	$3,24($sp)
	lw	$2,8($sp)
	mult	$3,$2
	mflo	$2
	addu	$sp,$sp,24
	j	$31
	.end	function1
	.rdata
	.align	2
$LC0:
	.ascii	"%d\n\000"
	.text
	.align	2
	.globl	function2
	.ent	function2
	.type	function2, @function
function2:
	.frame	$sp,32,$31		# vars= 0, regs= 2/0, args= 16, extra= 8
	.mask	0x90000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	subu	$sp,$sp,32
	.cprestore 16
	sw	$31,28($sp)
	sw	$28,24($sp)
	sw	$4,32($sp)
	li	$4,4			# 0x4
	la	$25,function1
	jal	$31,$25
	la	$4,$LC0
	move	$5,$2
	la	$25,printf
	jal	$31,$25
	lw	$31,28($sp)
	addu	$sp,$sp,32
	j	$31
	.end	function2
	.ident	"GCC: (GNU) 3.3.5  (Gentoo Linux 3.3.5-r1, ssp-3.3.2-3, pie-8.7.7)"
