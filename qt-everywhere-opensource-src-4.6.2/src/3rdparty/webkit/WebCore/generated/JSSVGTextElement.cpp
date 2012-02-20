/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(SVG)

#include "JSSVGTextElement.h"

#include "JSSVGAnimatedTransformList.h"
#include "JSSVGElement.h"
#include "JSSVGMatrix.h"
#include "JSSVGRect.h"
#include "SVGElement.h"
#include "SVGTextElement.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGTextElement);

/* Hash table */

static const HashTableValue JSSVGTextElementTableValues[4] =
{
    { "transform", DontDelete|ReadOnly, (intptr_t)jsSVGTextElementTransform, (intptr_t)0 },
    { "nearestViewportElement", DontDelete|ReadOnly, (intptr_t)jsSVGTextElementNearestViewportElement, (intptr_t)0 },
    { "farthestViewportElement", DontDelete|ReadOnly, (intptr_t)jsSVGTextElementFarthestViewportElement, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSSVGTextElementTableValues, 0 };
#else
    { 8, 7, JSSVGTextElementTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSSVGTextElementPrototypeTableValues[5] =
{
    { "getBBox", DontDelete|Function, (intptr_t)jsSVGTextElementPrototypeFunctionGetBBox, (intptr_t)0 },
    { "getCTM", DontDelete|Function, (intptr_t)jsSVGTextElementPrototypeFunctionGetCTM, (intptr_t)0 },
    { "getScreenCTM", DontDelete|Function, (intptr_t)jsSVGTextElementPrototypeFunctionGetScreenCTM, (intptr_t)0 },
    { "getTransformToElement", DontDelete|Function, (intptr_t)jsSVGTextElementPrototypeFunctionGetTransformToElement, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSSVGTextElementPrototypeTableValues, 0 };
#else
    { 8, 7, JSSVGTextElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGTextElementPrototype::s_info = { "SVGTextElementPrototype", 0, &JSSVGTextElementPrototypeTable, 0 };

JSObject* JSSVGTextElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGTextElement>(exec, globalObject);
}

bool JSSVGTextElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGTextElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGTextElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGTextElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGTextElement::s_info = { "SVGTextElement", &JSSVGTextPositioningElement::s_info, &JSSVGTextElementTable, 0 };

JSSVGTextElement::JSSVGTextElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGTextElement> impl)
    : JSSVGTextPositioningElement(structure, globalObject, impl)
{
}

JSObject* JSSVGTextElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGTextElementPrototype(JSSVGTextElementPrototype::createStructure(JSSVGTextPositioningElementPrototype::self(exec, globalObject)));
}

bool JSSVGTextElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGTextElement, Base>(exec, &JSSVGTextElementTable, this, propertyName, slot);
}

bool JSSVGTextElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGTextElement, Base>(exec, &JSSVGTextElementTable, this, propertyName, descriptor);
}

JSValue jsSVGTextElementTransform(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    RefPtr<SVGAnimatedTransformList> obj = imp->transformAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGTextElementNearestViewportElement(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->nearestViewportElement()));
}

JSValue jsSVGTextElementFarthestViewportElement(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->farthestViewportElement()));
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetBBox(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatRect>::create(imp->getBBox()).get(), imp);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<TransformationMatrix>::create(imp->getCTM()).get(), imp);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetScreenCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<TransformationMatrix>::create(imp->getScreenCTM()).get(), imp);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetTransformToElement(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    SVGElement* element = toSVGElement(args.at(0));


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<TransformationMatrix>::create(imp->getTransformToElement(element, ec)).get(), imp);
    setDOMException(exec, ec);
    return result;
}


}

#endif // ENABLE(SVG)