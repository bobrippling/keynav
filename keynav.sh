#!/bin/sh

usage(){
	echo >&2 "Usage: $0 [-f]"
	echo >&2 "-f: fork to background"
	exit 1
}

if [ $# -eq 1 ]
then
	if [ "$1" != '-f' ]
	then usage
	fi

	nohup "$0" > /dev/null 2>&1 &
	exit 0

elif [ $# -ne 0 ]
then usage
fi

xtest(){
	xterm -e true
	return $?
}

kn=$(dirname $(readlink -f $0))/keynav

while xtest && test -f $kn
do
	$kn
	sleep 5
done

[ -f $kn ]
exit $?
