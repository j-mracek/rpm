/*
 * hmacsha256.h
 *
 * HMAC-SHA-256 message authentication code, header
 *
 * Copyright (c) 2000, 2001 Virtual Unlimited B.V.
 *
 * Author: Bob Deblier <bob@virtualunlimited.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef _HMACSHA256_H
#define _HMACSHA256_H

#include "hmac.h"
#include "sha256.h"

typedef struct
{
/*@unused@*/	byte kxi[64];
/*@unused@*/	byte kxo[64];
	sha256Param param;
} hmacsha256Param;

#ifdef __cplusplus
extern "C" {
#endif

extern BEEDLLAPI const keyedHashFunction hmacsha256;

BEEDLLAPI
int hmacsha256Setup (hmacsha256Param* sp, const uint32* key, int keybits)
	/*@modifies sp @*/;
BEEDLLAPI
int hmacsha256Reset (hmacsha256Param* sp)
	/*@modifies sp @*/;
BEEDLLAPI
int hmacsha256Update(hmacsha256Param* sp, const byte* data, int size)
	/*@modifies sp @*/;
BEEDLLAPI
int hmacsha256Digest(hmacsha256Param* sp, uint32* data)
	/*@modifies sp, data @*/;

#ifdef __cplusplus
}
#endif

#endif
