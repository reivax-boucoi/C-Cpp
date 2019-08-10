#!/bin/sh
bindir=$(pwd)
cd /media/user/Data/Documents/C-Cpp/C/Terrain/ogl-master/tutorial08_basic_shading/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial08_basic_shading 
	else
		"/media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial08_basic_shading"  
	fi
else
	"/media/user/Data/Documents/C-Cpp/C/Terrain/build-ogl-master-Desktop-Default/tutorial08_basic_shading"  
fi