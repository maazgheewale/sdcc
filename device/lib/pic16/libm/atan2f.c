/*-------------------------------------------------------------------------
   atan2f.c - Computes atan2(x) where x is a 32-bit float.

   Copyright (C) 2001, 2002, Jesus Calvino-Fraga <jesusc At ieee.org>

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2.1, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

#include <math.h>
#include <errno.h>

float atan2f(const float x, const float y)
{
    float r;

    if ((x==0.0) && (y==0.0))
    {
        errno=EDOM;
        return 0.0;
    }

    if(fabsf(y)>=fabsf(x))
    {
        r=atanf(x/y);
        if(y<0.0) r+=(x>=0?PI:-PI);
    }
    else
    {
        r=-atanf(y/x);
        r+=(x<0.0?-HALF_PI:HALF_PI);
    }
    return r;
}
