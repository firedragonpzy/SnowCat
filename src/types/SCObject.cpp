//
//  SCObject.cpp
//  SnowCat
//
//  Created by Moky on 13-8-7.
//  Copyright (c) 2013 Slanissue Inc. All rights reserved.
//

#include "SCString.h"
#include "SCAutoreleasePool.h"

#include "SCObject.h"

NAMESPACE_BEGIN(SC_NAMESPACE)

const char * Object::description(void) const
{
	String * string = new String();
	SCAssert(string, "Not enough memory");
	StringUtils::stringWithFormat(*string, "<%s: 0x%08X | REF=%u>", this->className(), this, m_uiRefrence);
	string->autorelease();
	return string->c_str();
}

Object * Object::copy(void) const
{
	SCAssert(false, "Implement me!");
	return NULL;
}

void Object::retain(void)
{
	SCAssert(m_uiRefrence > 0, "reference count should greater than 0");
	++m_uiRefrence;
}

void Object::release(void)
{
	SCAssert(m_uiRefrence > 0, "reference count should greater than 0");
	--m_uiRefrence;
	if (m_uiRefrence == 0)
	{
		delete this;
	}
}

Object * Object::autorelease(void)
{
	PoolManager::sharedManager()->addObject(this);
	return this;
}

NAMESPACE_END
