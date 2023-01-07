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

#ifndef __LGE_MOUSE_EVENT__
#define __LGE_MOUSE_EVENT__

#include "engine_setup.h"
#include "lgeEvents.h"

#include <sstream>

_LGE_BEGIN_NP_LGE_HID

class LGE_API MouseMovedEvent : public Event {
private:
	pos position;

public:
	MouseMovedEvent(mFLOAT x, mFLOAT y) 
		: position({x, y, 0.0F})
	{}

	MouseMovedEvent(pos p)
		: position(p)
	{}

	LGE_CUDA_FUNC_DECL LGE_INLINE mFLOAT getX() const { return position.x; }
	LGE_CUDA_FUNC_DECL LGE_INLINE mFLOAT getY() const { return position.y; }

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "MouseMovedEvent: " << "X: " << this->position.x << " Y: " << this->position.y;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::mouseMoved; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "MouseMoved"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryMouse | EventCategory::eventCategoryInput)

};

class LGE_API MouseScrollEvent : public Event {
private:
	mFLOAT xOffset;
	mFLOAT yOffset;

public:
	MouseScrollEvent(mFLOAT xOffset, mFLOAT yOffset)
		: xOffset(xOffset), yOffset(yOffset)
	{}

	LGE_CUDA_FUNC_DECL LGE_INLINE mFLOAT getXOffset() const { return this->xOffset; }
	LGE_CUDA_FUNC_DECL LGE_INLINE mFLOAT getYOffset() const { return this->yOffset; }

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "MouseScrollEvent: " << "X: " << this->xOffset << " Y: " << this->yOffset;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::mouseScrolled; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "MouseScrolled"; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryMouse | EventCategory::eventCategoryInput)
};

class LGE_API MouseButtonEvent : public Event {
public:
	LGE_CUDA_FUNC_DECL LGE_INLINE mINT getMouseBtn() const { return this->button; }

	LGE_EVENT_CLASS_CATEGORY(EventCategory::eventCategoryMouse | EventCategory::eventCategoryInput)

protected:
	mINT button;

	MouseButtonEvent(mINT btn)
		: button(btn)
	{}
};

class LGE_API MouseButtonPressedEvent : public MouseButtonEvent {
public:
	MouseButtonPressedEvent(mINT btn) 
		: MouseButtonEvent(btn)
	{}

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "MousePressedEvent: " << "Button: " << this->button;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::mouseButtonPressed; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "MouseButtonPressed"; }

};


class LGE_API MouseButtonReleasedEvent : public MouseButtonEvent {
public:
	MouseButtonReleasedEvent(mINT btn)
		: MouseButtonEvent(btn)
	{}

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << "Button: " << this->button;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::mouseButtonReleased; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "MouseButtonReleasedEvent"; }

};


_LGE_END_NP_LGE_HID

#endif