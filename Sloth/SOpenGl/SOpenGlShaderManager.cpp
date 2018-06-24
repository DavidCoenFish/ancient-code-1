//file: Sloth/SOpenGl/SOpenGlShaderManager.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlShaderManager.h"

#include "Sloth/SOpenGl/SOpenGl.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

///////////////////////////////////////////////////////
// static public methods
/**/
static HVOID LocalVariableUpdate(
	SOpenGl& in_out_openGl,
	const HU32 in_programId,
	SMaterialStageShaderData& in_out_currentShaderData,
	const SMaterialStageShaderData& in_newShaderData,
	const SMaterialStageShaderData& in_stateShaderData //shader var from the openGl state
	)
{
	if( 0 == in_programId )
	{
		return;
	}

	//update variables
	TArrayString nameArray;
	in_newShaderData.DataNameListGet( nameArray );
	HCOMMON_FOR_EACH_CONST( dataName, nameArray, TArrayString )
	{
		SMaterialStageShaderDataVariant data = in_newShaderData.DataVariantGet( dataName );
		//overrite variable with openGl shaderVariables, nb lights, fog settings if found
		if( HTRUE == in_stateShaderData.DataVariantTest( dataName ) )
		{
			data = in_stateShaderData.DataVariantGet( dataName );
		}

		HBOOL uploadVariable = HTRUE;
		if( HTRUE == in_out_currentShaderData.DataVariantTest( dataName ) )
		{
			uploadVariable = ( data != in_out_currentShaderData.DataVariantGet( dataName ) );
		}

		if( HFALSE == uploadVariable )
		{
			continue;
		}

		in_out_currentShaderData.DataVariantSet( dataName, data );

		//upload variable
		const HSINT location = in_out_openGl.GlGetUniformLocationARB( in_programId, dataName );

		if( HTRUE == data.TypeTest< HBOOL >() )
		{
			const HBOOL dataValue = data.ValueGet< HBOOL >();
			if( HTRUE == dataValue )
			{
				in_out_openGl.GlUniform1iARB( location, 1 );
			}
			else
			{
				in_out_openGl.GlUniform1iARB( location, 1 );
			}
		}
		else if( HTRUE == data.TypeTest< HSINT >() )
		{
			const HSINT dataValue = data.ValueGet< HSINT >();
			in_out_openGl.GlUniform1iARB( location, dataValue );
		}
		else if( HTRUE == data.TypeTest< HREAL >() )
		{
			//const HREAL dataValue = data.ValueGet< HREAL >();
			//in_out_openGl.GlUniform1iARB( location, dataValue );
		}
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlShaderManager::SOpenGlShaderManager()
: m_treeShaders()
, m_shaderVariable()
, m_shaderVariableDirty( HFALSE )
, m_currentShader()
, m_currentShaderData()
//, m_currentShaderDataVertex()
//, m_currentShaderDataFragment()
{
	return;
}

/**/
SOpenGlShaderManager::~SOpenGlShaderManager()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL SOpenGlShaderManager::ShaderCreate(
	SOpenGl& in_out_openGl,
	const Hubris::HString& in_shaderName,
	const SMaterialStageShader& in_shader
	)
{
	if( m_treeShaders.End() !=  m_treeShaders.Find( in_shaderName ) )
	{
		//shader name already exsists
		return HFALSE;
	}

	SOpenGlShaderManagerData* pData = HNULL;
	HCOMMON_NEW_PARAM_2(
		pData,
		SOpenGlShaderManagerData,
		in_out_openGl,
		in_shader
		);

	if( HNULL == pData )
	{
		return HFALSE;
	}

	if( HFALSE == pData->ValidGet() )
	{
		return HFALSE;
	}

	m_treeShaders.Insert( in_shaderName, pData );

	return HTRUE;
}

/**/
Hubris::HVOID SOpenGlShaderManager::ShaderRelease(
	SOpenGl& HCOMMON_UNUSED_VAR( in_out_openGl ),
	const Hubris::HString& in_shaderName
	)
{
	const TTreeStringData::TIterator iterator = m_treeShaders.Find( in_shaderName );
	if( iterator == m_treeShaders.End() )
	{
		return;
	}

	m_treeShaders.Remove( iterator );

	return;
}

/**/
Hubris::HVOID SOpenGlShaderManager::ShaderReleaseAll(
	SOpenGl& HCOMMON_UNUSED_VAR( in_out_openGl )
	)
{
	m_treeShaders.Clear();
	return;
}

/**/
Hubris::HVOID SOpenGlShaderManager::ShaderSet(
	SOpenGl& in_out_openGl,
	const Hubris::HString& in_shaderName,
	const SMaterialStageShaderData& in_shaderData
	//const SMaterialStageShaderData& in_shaderDataVertex,
	//const SMaterialStageShaderData& in_shaderDataFragment
	)
{
SOpenGl::ErrorCheck();

	const TTreeStringData::TIterator iterator = m_treeShaders.Find( in_shaderName );

	//link shader program
	if( m_currentShader != in_shaderName )
	{
		if( HNULL != m_currentShader )
		{
			//unlink current shader
			in_out_openGl.GlUseProgramObjectARB( 0 );
		}
		m_currentShaderData.Clear();
		//m_currentShaderDataVertex.Clear();
		//m_currentShaderDataFragment.Clear();	
		m_currentShader = in_shaderName;

		if( iterator != m_treeShaders.End() )
		{
			in_out_openGl.GlUseProgramObjectARB( ( *iterator )->ProgramIdGet() );
		}
	}

	if( iterator == m_treeShaders.End() )
	{
		return;
	}

	LocalVariableUpdate(
		in_out_openGl,
		( *iterator )->ProgramIdGet(),
		m_currentShaderData,
		in_shaderData,
		m_shaderVariable
		);

SOpenGl::ErrorCheck();

	//LocalVariableUpdate(
	//	in_out_openGl,
	//	( *iterator )->ShaderIdVertexGet();
	//	m_currentShaderDataVertex,
	//	in_shaderDataVertex,
	//	m_shaderVariable
	//	);

	//LocalVariableUpdate(
	//	in_out_openGl,
	//	( *iterator )->ShaderIdFragmentGet();
	//	m_currentShaderDataFragment,
	//	in_shaderDataFragment,
	//	m_shaderVariable
	//	);

	return;
}

/**/
Hubris::HVOID SOpenGlShaderManager::ShaderVariableSet(
	SOpenGl& HCOMMON_UNUSED_VAR( in_out_openGl ),
	const Hubris::HString& in_variableName,
	SMaterialStageShaderDataVariant& in_variant
	)
{
	if( m_shaderVariable.DataVariantTest( in_variableName ) )
	{
		if( in_variant == m_shaderVariable.DataVariantGet( in_variableName ) )
		{
			return;
		}
	}

	m_shaderVariable.DataVariantSet( in_variableName, in_variant );
	//m_shaderVariableDirty = HTRUE;

	return;
}

/**/
