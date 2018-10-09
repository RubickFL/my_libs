/*
	Library name: <cachelinesize.h>
	Author: Rub!ck


	Description:
	This lib has one function get_chache_line_size. The function recognizes and returns the processor cache size.
	This will help you with the optimization of embedded systems and games.
	Library works on WIN32, APPLE and linux OS. Just define OS name(#define linux/_WIN32/__APPLE__).
	The library itself will be adjusted to the desired OS.
	If the OS is not initialized, the library will abort the compilation and display an error message.
	Good luck, bro :)
*/



#ifndef GET_CACHE_LINE_SIZE_H_INCLUDED
#define GET_CACHE_LINE_SIZE_H_INCLUDED
#include <stddef.h>
size_t get_cache_line_size();




#ifdef __APPLE__
#include <sys/sysctl.h>
size_t get_cache_line_size()
{
    size_t line_size;
    sysctlbyname( "hw.cachelinesize", &line_size, sizeof(line_size), 0, 0 );
    return line_size;
}
#endif




#ifdef _WIN32
#include <stdlib.h>
#include <windows.h>
size_t get_cache_line_size()
{
    size_t line_size;
    DWORD buffer_size;
    DWORD i;
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION *buffer;

    GetLogicalProcessorInformation( 0, &buffer_size );
    buffer = ( SYSTEM_LOGICAL_PROCESSOR_INFORMATION * )malloc( buffer_size );
    GetLogicalProcessorInformation( &buffer[0], &buffer_size );

    for( i = 0; i != buffer_size / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION); ++i )
    {
        if( buffer[i].Relationship == RelationCache && buffer[i].Cache.Level == 1 )
	{
            line_size = buffer[i].Cache.LineSize;
            break;
        }
    }

    free( buffer );
    return line_size;
}
#endif




#ifdef linux
#include <stdio.h>
size_t get_cache_line_size()
{
    FILE *p;
    p = fopen( "/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r" );
    unsigned int i;
    if( p )
    {
        fscanf( p, "%d", &i );
        fclose( p );
    }
    return i;
}
#endif




#ifndef linux
#ifndef _WIN32
#ifndef __APPLE__
#error Unrecognized platform
#endif
#endif
#endif

#endif
