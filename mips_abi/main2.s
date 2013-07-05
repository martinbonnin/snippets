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
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, extra= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	srl	$3,$4,31
	addu	$3,$4,$3
	sra	$3,$3,1
	mult	$4,$3
	mflo	$2
	#nop
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
	li	$4,4			# 0x4
	sw	$31,28($sp)
	sw	$28,24($sp)
	la	$25,function1
	jal	$31,$25
	move	$5,$2
	la	$4,$LC0
	la	$25,printf
	jal	$31,$25
	lw	$31,28($sp)
	#nop
	.set	noreorder
	.set	nomacro
	j	$31
	addu	$sp,$sp,32
	.set	macro
	.set	reorder

	.end	function2
	.ident	"GCC: (GNU) 3.3.5  (Gentoo Linux 3.3.5-r1, ssp-3.3.2-3, pie-8.7.7)"
