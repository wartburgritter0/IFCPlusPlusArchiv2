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
#include "IfcConstraint.h"
class IFCPP_EXPORT IfcBenchmarkEnum;
class IFCPP_EXPORT IfcLabel;
class IFCPP_EXPORT IfcMetricValueSelect;
class IFCPP_EXPORT IfcReference;
//ENTITY
class IFCPP_EXPORT IfcMetric : public IfcConstraint
{ 
public:
	IfcMetric();
	IfcMetric( int id );
	~IfcMetric();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcMetric"; }


	// IfcConstraint -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcLabel>										m_Name;
	//  shared_ptr<IfcText>											m_Description;				//optional
	//  shared_ptr<IfcConstraintEnum>								m_ConstraintGrade;
	//  shared_ptr<IfcLabel>										m_ConstraintSource;			//optional
	//  shared_ptr<IfcActorSelect>									m_CreatingActor;			//optional
	//  shared_ptr<IfcDateTime>										m_CreationTime;				//optional
	//  shared_ptr<IfcLabel>										m_UserDefinedGrade;			//optional
	// inverse attributes:
	//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
	//  std::vector<weak_ptr<IfcResourceConstraintRelationship> >	m_PropertiesForConstraint_inverse;

	// IfcMetric -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcBenchmarkEnum>								m_Benchmark;
	shared_ptr<IfcLabel>										m_ValueSource;				//optional
	shared_ptr<IfcMetricValueSelect>							m_DataValue;				//optional
	shared_ptr<IfcReference>									m_ReferencePath;			//optional
};

