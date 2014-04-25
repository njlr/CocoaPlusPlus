//
//  Data.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN





/*!
 Wraps `NSArray`.
 */
class
Data : protected Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
};










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END