//
//  View.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"
#include "DraggingDestination.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
View : public Foundation::Object
{
public:
	static auto	view() -> View;
	
public:
	using	Object::Object;
	
public:
	auto	frame() const -> Rect;
	auto	setFrame(Rect) -> void;
	
	auto	addSubview(View) -> void;
	auto	removeFromSuperview() -> void;
	
	auto	wantsLayer() const -> bool;
	auto	setWantsLayer(bool) -> void;
	
	auto	layer() const -> CoreAnimation::Layer;
	auto	setLayer(CoreAnimation::Layer) -> void;
	
	/*!
	 See `Pasteboard::Type` for generic UTIs.
	 */
	auto	registerForDraggedTypes(vec<Foundation::String> const& UTIs) -> void;
	auto	unregisterDraggedTypes() -> void;
	
};




/*!
 If you want to override some methods of a view, you should use this class.
 */
class
OverridableView : public View
{
public:
	struct
	Behaviors : DraggingDestination
	{
		virtual auto	didMoveToSuperview() -> void	{}
	};
	
public:
	OverridableView(uptr<Behaviors>&& overridings);
};









EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END