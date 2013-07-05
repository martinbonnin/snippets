	.file	1 "main.c"
	.section .mdebug.abi32
	.previous
	.text
	.align	2
	.globl	function1
	.ent	function1
	.type	function1, @function
function1:
$LFB2:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	srl	$2,$4,31
	addu	$2,$4,$2
	sra	$2,$2,1
	j	$31
	mul	$2,$4,$2

	.set	macro
	.set	reorder
$LFE2:
	.end	function1
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"%d\n\000"
	.text
	.align	2
	.globl	function2
	.ent	function2
	.type	function2, @function
function2:
$LFB3:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	lui	$4,%hi($LC0)
	addiu	$4,$4,%lo($LC0)
	j	printf
	li	$5,5			# 0x5

	.set	macro
	.set	reorder
$LFE3:
	.end	function2
	.section	.eh_frame,"a",@progbits
$Lframe1:
	.4byte	$LECIE1-$LSCIE1
$LSCIE1:
	.4byte	0x0
	.byte	0x1
	.ascii	"\000"
	.uleb128 0x1
	.sleb128 4
	.byte	0x1f
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x0
	.align	2
$LECIE1:
$LSFDE1:
	.4byte	$LEFDE1-$LASFDE1
$LASFDE1:
	.4byte	$LASFDE1-$Lframe1
	.4byte	$LFB2
	.4byte	$LFE2-$LFB2
	.align	2
$LEFDE1:
$LSFDE3:
	.4byte	$LEFDE3-$LASFDE3
$LASFDE3:
	.4byte	$LASFDE3-$Lframe1
	.4byte	$LFB3
	.4byte	$LFE3-$LFB3
	.align	2
$LEFDE3:
	.align	0
	.ident	"GCC: (GNU) 3.4.6 (Gentoo 3.4.6-r2 p1.6, ssp-3.4.6-1.0, pie-8.7.10)"
