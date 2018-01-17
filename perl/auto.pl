#!/usr/bin/perl

$way = `aclocal`;
print $way;

$way = `autoheader`;
print $way;

$way = `autoconf`;
print $way;

$way = `automake --foreign --add-missing --copy`;
print $way;

$way = `./configure`;
print $way;
