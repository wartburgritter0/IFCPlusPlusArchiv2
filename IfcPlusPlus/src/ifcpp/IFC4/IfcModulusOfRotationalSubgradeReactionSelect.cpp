/* -*-c++-*- IFC++ www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <map>
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "include/IfcBoolean.h"
#include "include/IfcModulusOfRotationalSubgradeReactionMeasure.h"
#include "include/IfcModulusOfRotationalSubgradeReactionSelect.h"

// TYPE IfcModulusOfRotationalSubgradeReactionSelect = SELECT	(IfcBoolean	,IfcModulusOfRotationalSubgradeReactionMeasure);
shared_ptr<IfcModulusOfRotationalSubgradeReactionSelect> IfcModulusOfRotationalSubgradeReactionSelect::createObjectFromSTEP( const std::wstring& arg, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	// read TYPE
	if( arg.size() == 0 ){ return shared_ptr<IfcModulusOfRotationalSubgradeReactionSelect>(); }
	if( arg.compare(L"$")==0 )
	{
		return shared_ptr<IfcModulusOfRotationalSubgradeReactionSelect>();
	}
	if( arg.compare(L"*")==0 )
	{
		return shared_ptr<IfcModulusOfRotationalSubgradeReactionSelect>();
	}
	shared_ptr<IfcModulusOfRotationalSubgradeReactionSelect> result_object;
	readSelectType( arg, result_object, map );
	return result_object;
}
