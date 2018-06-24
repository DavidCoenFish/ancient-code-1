//file: Hubris/HubrisPreCompileHeader.h
#ifndef _HOPE_PRE_COMPILE_HEADER_H_
#define _HOPE_PRE_COMPILE_HEADER_H_

/*
	argh, i did try to work around the following (created a wrapper class for variant) 
	but in many instances (situations that wanted a template generated definition)
	it was incovienient not being able to use the templated variant class
	use HVariant (the class wrapper) but HVariant::TVariantImplementation is avaliable for use too
	-coen
*/
#pragma warning (disable:4503) // Disable warning: "decorated name length exceeded, name was truncated" not an inssue in release application (ok, it is going to mess with the debugger) -coen

//STL
#include< string >
#include< vector >
#include< map >
#include< utility >

//TinyXml
//DO NOT LET tinyxml.h into header space, includes windows.h, defines max as some macro?...
//#include< tinyxml.h >

#endif //_HOPE_PRE_COMPILE_HEADER_H_