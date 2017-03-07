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
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPObject.h"
#include "ifcpp/model/IfcPPGlobal.h"
#include "IfcStructuralLoadStatic.h"
class IFCPP_EXPORT IfcForceMeasure;
class IFCPP_EXPORT IfcTorqueMeasure;
//ENTITY
class IFCPP_EXPORT IfcStructuralLoadSingleForce : public IfcStructuralLoadStatic
{ 
public:
	IfcStructuralLoadSingleForce();
	IfcStructuralLoadSingleForce( int id );
	~IfcStructuralLoadSingleForce();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcStructuralLoadSingleForce"; }


	// IfcStructuralLoad -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcLabel>			m_Name;						//optional

	// IfcStructuralLoadOrResult -----------------------------------------------------------

	// IfcStructuralLoadStatic -----------------------------------------------------------

	// IfcStructuralLoadSingleForce -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcForceMeasure>		m_ForceX;					//optional
	shared_ptr<IfcForceMeasure>		m_ForceY;					//optional
	shared_ptr<IfcForceMeasure>		m_ForceZ;					//optional
	shared_ptr<IfcTorqueMeasure>	m_MomentX;					//optional
	shared_ptr<IfcTorqueMeasure>	m_MomentY;					//optional
	shared_ptr<IfcTorqueMeasure>	m_MomentZ;					//optional
};

