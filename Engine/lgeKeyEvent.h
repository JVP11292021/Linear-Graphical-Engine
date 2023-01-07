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

#ifndef __LGE_KEY_EVENT__
#define __LGE_KEY_EVENT__

#include "engine_setup.h"
#include "lgeEvents.h"

#include <sstream>

_LGE_BEGIN_NP_LGE_HID

class LGE_API KeyEvent : public lge::hid::Event {
public:
	LGE_CUDA_FUNC_DECL LGE_INLINE mINT getKeyCode() const { return this->keyCode; }

	LGE_EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput)

protected:
	mINT keyCode;

	 KeyEvent(mINT keyCode) 
		 : keyCode(keyCode)
	 {}
};


class LGE_API KeyPressedEvent : public KeyEvent {
private:
	mINT repeatCount;

public:
	KeyPressedEvent(mINT keyCode, mINT repeatCount) 
		: KeyEvent(keyCode), repeatCount(repeatCount)
	{}

	LGE_CUDA_FUNC_DECL LGE_INLINE mINT getRepeatCount() const { return this->repeatCount; }

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << this->keyCode << " (" << this->repeatCount << " repeats)";
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::keyPressed; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override {return getStaticType();}
	LGE_CUDA_FUNC_DECL istr getName() const override {return "KeyPressed";}


};

class LGE_API KeyReleasedEvent : public KeyEvent {
public:
	KeyReleasedEvent(mINT keyCode)
		: KeyEvent(keyCode)
	{}

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << this->keyCode ;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::keyRealeased; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "KeyReleased"; }

};

class LGE_API KeyTypedEvent : public KeyEvent {
public:
	KeyTypedEvent(mINT keyCode) 
		: KeyEvent(keyCode)
	{}

	LGE_CUDA_FUNC_DECL std::string toString() const override {
		std::stringstream ss;
		ss << "KeyTypedEvent: " << this->keyCode;
		return ss.str();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC EventType getStaticType() { return EventType::keyTyped; }
	LGE_CUDA_FUNC_DECL EventType getEventType() const override { return getStaticType(); }
	LGE_CUDA_FUNC_DECL istr getName() const override { return "KeyTyped"; }

};

_LGE_END_NP_LGE_HID

#endif