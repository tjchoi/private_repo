#!/bin/sh
# written by inode

usage(){
echo "Usage: cleanup.sh"
echo "Description: A Bash script remove all CVS and .git directories recursively"
}

if [ $# -ne 0 ]; then
	usage
	exit 1
fi

for i in `find . -name "CVS" -type d -print`; do
	rm -fr $i
done

for i in `find . -name ".git" -type d -print`; do
	rm -fr $i
done

for i in `find . -name ".subversion" -type d -print`; do
	rm -fr $i
done
