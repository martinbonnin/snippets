#!/usr/bin/perl
use strict;
$::toto = 42;
sub test {
	print "toto is $::toto";
}

test();
