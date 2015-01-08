----------------------------------
Linuxbuild of IfcPlusPlus (Ifc++)
----------------------------------


branch master
=============
branch master has changes to compile on Debian Testing (Jessie) and Ubuntu Trusty Tahr (14.04)



branch svn
=============
clone of the original SVN-Repository of Fabian Gerold  http://ifcplusplus.googlecode.com/



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
Internal Carve of IfcPlusPlus is used.

Debian Jessie

$ apt-get install cmake git 

$ apt-get install libboost-dev libopenscenegraph-dev libqt4-dev


Ubuntu Trusty Tahr

$ sudo apt-get install cmake git build-essential

$ sudo apt-get install libboost-dev libopenscenegraph-dev libqt4-dev

The "Choose File" Dialog does not work properly on Trusty Tahr.
As a workaround one could open IfcPlusPlusViewer together with a ifc file from the shell. 


IfcPLusPlus
===========
get source code of master branch and build the source

$ git clone git://github.com/berndhahnebach/IfcPlusPlus/  ifcplusplus-code

$ cd ifcplusplus-code

$ mkdir build

$ cd build

$ cmake ../

$ make

$ cd Debug

$ ./IfcPlusPlusViewer


Yeah, it runs on Linux !!!

my mail: bernd at bimstatik dot org
