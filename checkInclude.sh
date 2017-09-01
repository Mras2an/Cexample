#!/bin/bash
# prune include files one at a time, recompile, and put them back if it doesn't compile
# arguments are list of files to check

noir='\e[0;30m'
gris='\e[1;30m'
rougefonce='\e[0;31m'
rose='\e[1;31m'
vertfonce='\e[0;32m'
vertclair='\e[1;32m'
orange='\e[0;33m'
jaune='\e[1;33m'
bleufonce='\e[0;34m'
bleuclair='\e[1;34m'
violetfonce='\e[0;35m'
violetclair='\e[1;35m'
cyanfonce='\e[0;36m'
cyanclair='\e[1;36m'
grisclair='\e[0;37m'
blanc='\e[1;37m'

neutre='\e[0;m'

removeinclude() {
    file=$1
    header=$2
    perl -i -p -e 's+([ \t]*#include[ \t][ \t]*[\"\<]'$2'[\"\>])+//REMOVEINCLUDE $1+' $1
}
replaceinclude() {
   file=$1
   perl -i -p -e 's+//REMOVEINCLUDE ++' $1
}


# multi name
#files=$(find . -name *.c -o -name *.h)

# only c file
files=$(find . -name *.c)

for file in $files
do
    includes=`grep "^[ \t]*#include" $file | awk '{print $2;}' | sed 's/[\"\<\>]//g'`
    echo ""
    echo $file":"
    #echo $includes
    for i in $includes
    do
        touch $file # just to be sure it recompiles
        removeinclude $file $i
        if make -j 4 >/dev/null  2>&1;
        then
            grep -v REMOVEINCLUDE $file > tmp && mv tmp $file
            echo -e "${rougefonce}removed $i from $file ${neutre}"
        else
            replaceinclude $file
            echo -e "${vertfonce} $i was needed in $file ${neutre}"
        fi
    done
done
