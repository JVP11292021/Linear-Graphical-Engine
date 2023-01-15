/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#ifndef __LGE_APPLICATION_EVENT__
#define __LGE_APPLICATION_EVENT__

#include "engine_setup.h"
#include "lgeEvents.h"

_LGE_BEGIN_NP_LGE_HID

class LGE_API WindowResizeEvent : public Event {
private:
	dim dimension;

public:
	WindowResizeEvent(mDWORD width, mDWORD height)
		: dimension({width, height, 0})
	{}

	WindowResizeEvent(dim d)
		: dimension(d)
	{}

	LGE_CUDA_FUNC_DECL LGE_INLINE mINT getWidth() const { return this->dimension.x; }
	LGE_CUDA_FUNC_DECL LGE_INLINE mINT getHeight() const { return this->dimension.y; }

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "WindowResizeEvent: " << "Width: " << this->dimension.x << " Height: " << this->dimension.y;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::winResize; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "WindowResizeEvent"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryApplication)
};

class LGE_API WindowCloseEvent : public Event {
public:
	WindowCloseEvent() {}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::winClose; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "WindowCloseEvent"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryApplication)
};

class LGE_API AppTickEvent : public Event {
public:
	AppTickEvent() {}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::appTick; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "AppTickEvent"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryApplication)
};

class LGE_API AppUpdateEvent : public Event {
public:
	AppUpdateEvent() {}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::appUpdate; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "AppTickEvent"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryApplication)
};

class LGE_API AppRenderEvent : public Event {
public:
	AppRenderEvent() {}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::appRender; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "AppRenderEvent"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryApplication)
};

_LGE_END_NP_LGE_HID

#endif