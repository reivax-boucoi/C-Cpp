#!/bin/sh
bindir=$(pwd)
cd /media/user/Data/Documents/C-Cpp/C/Terrain/ogl-master/tutorial10_transparency/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial10_transparency 
	else
		"/media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial10_transparency"  
	fi
else
	"/media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial10_transparency"  
fi
