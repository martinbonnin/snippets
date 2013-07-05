#!/usr/bin/perl

package Test;

use Moose;

my $a="18";
my $b="16";

has 'message'     => (isa => 'HashRef', is => 'ro', default => sub{return {$a => {$b => "hello"}}});

# the one below works fine
#has 'message'     => (isa => 'HashRef', is => 'ro', default => sub{{"18" => {"16" => "hello"}}});

sub show {
    my $self = shift;
    print("Test: " . $self->message->{$a}->{$b} . "\n");
}

my $o = Test->new();
$o->show();

