#include <iostream>
#include <lge.h>

class SandBox : public lge::Application {
public:
	SandBox() {
		
	}

	~SandBox() {
		
	}
}; 

lge::Application* lge::createApplication() {
	return new SandBox();
} 
