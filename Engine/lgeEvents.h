//		*****************************************************************************************
//		* This source code is from the Github repo: Linear Graphical Engine (LGE)				*
//		*	Created by: JVP11292021 (J. van Polanen)											*
//		*	Started on: 06-01-2023																*
//		*																						*
//		* Copyright (c) Jessy van Polanen														*
//		*																						*
//		* NOTICE:																				*
//		*	This notice must remain at the top of each file, any alterations to this notice		*
//		*	strictly breaks the license the user aggreed upon when using this software.			*
//		*****************************************************************************************

#ifndef __LGE_EVENTS__
#define __LGE_EVENTS__

#include "engine_setup.h"
#include "lgeCodes.h"

#include <string>
#include <functional>

_LGE_BEGIN_NP_LGE_HID

LGE_API enum class EventType {
	none = 0,
	winClose, winResize, winFocus, winLostFocus, winMoved,
	appTick, appUpdate, appRender,
	keyPressed, keyRealeased, keyTyped,
	mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
};

LGE_API enum EventCategory {
	none = 0,
	eventCategoryApplication		= lgeBIT(0),
	eventCategoryInput				= lgeBIT(1),
	eventCategoryKeyboard			= lgeBIT(2),
	eventCategoryMouse				= lgeBIT(3),
	eventCategoryMouseButton		= lgeBIT(4),
};


class LGE_API Event {
private:
	friend class EventDispatcher;

public:
	mBOOL handled = LGE_FALSE;

	virtual ~Event() = default;

	LGE_CUDA_FUNC_DECL virtual EventType getEventType() const = 0;
	LGE_CUDA_FUNC_DECL virtual istr getName() const = 0;
	LGE_CUDA_FUNC_DECL virtual mINT getCategoryFlags() const = 0;
	LGE_CUDA_FUNC_DECL virtual std::string toString() const { return this->getName(); } // DEBUG only

	LGE_CUDA_FUNC_DECL LGE_INLINE mBOOL isInCategory(EventCategory category) { return this->getCategoryFlags() & category; }
	LGE_CUDA_FUNC_DECL LGE_INLINE mBOOL isHandled() const { return this->handled; }
};

class LGE_API EventDispatcher {
private:
	Event& event;

	template <typename T>
	using EventFn = std::function<bool(T&)>;

public:

	EventDispatcher(Event& event) 
#ifdef LGE_HAS_INITIALIZER_LIST
		: event(event)
#endif
	{
#ifndef LGE_HAS_INITIALIZER_LIST
		this->event = event;
#endif
	}

	template <typename T>
	LGE_CUDA_FUNC_DECL mBOOL dispatch(EventFn<T> func) {
		if (this->event.getEventType() == T::getStaticType()) {
			this->event.handled = func(*(T*)&this->event);
			return LGE_TRUE;
		}
		return LGE_FALSE;
	}
};

LGE_CUDA_FUNC_DECL LGE_INLINE std::ostream& operator << (std::ostream& os, const Event& e) {
	return os << e.toString();
}


_LGE_END_NP_LGE_HID

// Macro for simplifying the abstract method implementations
#define LGE_EVENT_CLASS_TYPE(type)  LGE_CUDA_FUNC_DECL LGE_STATIC lge::hid::EventType getStaticType() {return lge::hid::EventType::##type;}\
									LGE_CUDA_FUNC_DECL virtual lge::hid::EventType getEventType() const override {return getStaticType();}\
									LGE_CUDA_FUNC_DECL virtual lge::istr getName() const override {return #type;}

#define LGE_EVENT_CLASS_CATEGORY(category) LGE_CUDA_FUNC_DECL virtual lge::hid::mINT getCategoryFlags() const override {return category;}

#ifdef _WINDOWS_
#	undef _WINDOWS_
#endif

#endif