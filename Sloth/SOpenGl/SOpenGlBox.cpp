//file: Sloth/SOpenGl/SOpenGlBox.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlBox.h"

#include "Sloth/SOpenGl/SOpenGl.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// local static variables
/**/
static const GLfloat s_boxArrayVertexNormal[] = 
{
	-0.577350269F, -0.577350269F, -0.577350269F,
	-0.577350269F,  0.577350269F, -0.577350269F,
	 0.577350269F,  0.577350269F, -0.577350269F,
	 0.577350269F, -0.577350269F, -0.577350269F,
	-0.577350269F, -0.577350269F,  0.577350269F,
	-0.577350269F,  0.577350269F,  0.577350269F,
	 0.577350269F,  0.577350269F,  0.577350269F,
	 0.577350269F, -0.577350269F,  0.577350269F
};

static const GLint s_boxArrayVertexSize = HCOMMON_ARRAY_SIZE( s_boxArrayVertexNormal );
static const GLushort s_boxArrayVertexIndex[] =
{
	 0,  1,  3,  2,
	 0,  3,  4,  7,
	 3,  2,  7,  6,
	 2,  1,  6,  5,
	 1,  0,  5,  4,
	 4,  7,  5,  6
};
static const GLint s_boxArrayVertexIndexSize = HCOMMON_ARRAY_SIZE( s_boxArrayVertexIndex );

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID SOpenGlBox::DrawBox(
	const Pride::PBoundsR3& in_bounds
	)
{
	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_NORMAL_ARRAY );

	const HVectorR3 vectorMin = in_bounds.VectorMinimumGet();
	const HVectorR3 vectorMax = in_bounds.VectorMaximumGet();
	GLfloat arrayVertexPosition[] =
	{
		vectorMin[ 0 ], vectorMin[ 1 ], vectorMin[ 2 ],
		vectorMin[ 0 ], vectorMax[ 1 ], vectorMin[ 2 ],
		vectorMax[ 0 ], vectorMax[ 1 ], vectorMin[ 2 ],
		vectorMax[ 0 ], vectorMin[ 1 ], vectorMin[ 2 ],
		vectorMin[ 0 ], vectorMin[ 1 ], vectorMax[ 2 ],
		vectorMin[ 0 ], vectorMax[ 1 ], vectorMax[ 2 ],
		vectorMax[ 0 ], vectorMax[ 1 ], vectorMax[ 2 ],
		vectorMax[ 0 ], vectorMin[ 1 ], vectorMax[ 2 ]
	};

	glVertexPointer( 3, GL_FLOAT, 0, arrayVertexPosition );
	glNormalPointer( GL_FLOAT, 0, s_boxArrayVertexNormal );
	for( HSINT index = 0; index < 6; ++index )
	{
		glDrawElements( 
			GL_TRIANGLE_STRIP, 
			4,
			GL_UNSIGNED_SHORT, 
			&s_boxArrayVertexIndex[ index * 4 ]
			);
	}

	glPopClientAttrib();

	return;
}

/**/