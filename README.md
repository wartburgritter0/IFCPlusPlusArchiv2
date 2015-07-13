----------------------------------
Linuxbuild of IfcPlusPlus (Ifc++)
----------------------------------


branch master
=============
branch master has changes to compile on Debian Testing (Jessie) and Ubuntu Trusty Tahr (14.04)


branch fg
=============
clone of the active github-Repository of Fabian Gerold  https://github.com/ifcquery/ifcplusplus/


branch svn
=============
clone of the deprecated SVN-Repository of Fabian Gerold  http://ifcplusplus.googlecode.com/



IfcPLusPlus
============
open source software to view ifc-files on Linux
https://github.com/berndhahnebach/IfcPlusPlus

The Repository is based on the work done by Fabian Gerold 
http://www.ifcplusplus.com/

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

$ ./SimpleViewerExample


Yeah, it runs on Linux !!!

my mail: bernd at bimstatik dot org


Ubuntu Trusty Tahr
==================
Due to a bug in Ubuntu Standard QtGUI theme the "Choose File" Dialog does not work properly on Trusty Tahr.
Workaround (assumed you are in Directory Debug):
* start IfcPlusPlusViewer together with a ifc file from the shell
    * ./SimpleViewerExample pathtotheifcfile/theifcfile.ifc
    * ./SimpleViewerExample ../../IfcOpenHouse.ifc
* start IfcPlusPlusViewer with a different style
    * ./SimpleViewerExample -style=fusion
* change the GUI style of all Qt applications on Ubuntu
    * sudo apt-get install qt4-qtconfig
    * launch qtconfing-qt4
    * change Select GUI Style (Cleanlooks works for me.)
    * don't forget to save your changes


Qt4 vs. Qt5
===========
* OpenSceneGraph (OSG) library has to be compiled against the same Qt than SimpleViewerExample.
* Since on most Linux Distribution OSG is compiled against Qt4 it makes sence to use Qt4 on Linux system as long as the Distribution packages of OSG are used. 
* Confirmed for Debian Jessie and Ubuntu 14.04