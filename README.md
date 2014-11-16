----------------------------------
Linuxbuild of IfcPlusPlus (Ifc++)
----------------------------------


branch master
=============
branch master should allways compile on up to date Debian Jessie



branch svn
=============
clone of the original SVN-Repository of Fabian Gerold  http://ifcplusplus.googlecode.com/

It has Linux support since the SVN was reinitialised at June, 3. 2014




IfcPLusPlus
============
open source software to view ifc-files on Linux
https://github.com/berndhahnebach/IfcPlusPlus

The Repository is based on the work done by Fabian Gerold 
http://code.google.com/p/ifcplusplus/

The original cmake files where taken form Sylvian Marie from VTREEM
https://github.com/VTREEM/IFCPlusPlus/

Find a forum thread about this Linux build at
http://www.forum.freecadweb.org/viewtopic.php?f=23&t=5101


Packagelist
===========
Tested on Debian Jessie

$ apt-get install cmake git 

$ apt-get install libboost-dev libopenscenegraph-dev libqt4-dev


Internal Carve of IfcPlusPlus is used.


IfcPLusPlus
===========
get source code of branch readme and build the source

$ git clone git://github.com/berndhahnebach/IfcPlusPlus/  ifcplusplus-code

$ cd ifcplusplus-code

$ mkdir build

$ cd build

$ cmake ../

$ make

$ cd Release

$ ./IfcPlusPlusViewer


Yeah, it runs on Linux !!!

my mail: bernd at bimstatik dot org
