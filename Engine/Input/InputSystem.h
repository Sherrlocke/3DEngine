#pragma once
#include "Framework/System.h"
#include "Math/MathTypes.h"
#include <vector>
#include <SDL.h>
#include <array>

namespace nc {
	class InputSystem : public System {
	
	public:
		enum class eKeyState {
			IDLE,
			PRESSED,
			HELD,
			RELEASE
		};

		enum class eMouseButton {
			Left,
			Middle, 
			Right
		};

		virtual void Startup() override;
		virtual void Shutdown() override;
		virtual void Update(float dt) override;

		eKeyState GetKeyState(int id);
		bool IsKeyDown(int id);
		bool IsPreviousKeyDown(int id);

		const glm::vec3& GetMousePosition() const { return mousePosition; }
		bool IsButtonDown(int id) { return mouseButtonState[id]; }
		bool IsPreviousButtonDown(int id) { return prevMouseButtonState[id]; }
		eKeyState GetButtonState(int id);

	private:
		std::vector<Uint8>keyboardState;
		std::vector<Uint8>prevKeyboardState;
		int numKeys;

		glm::vec3 mousePosition;
		std::array<Uint8, 3> mouseButtonState;
		std::array<Uint8, 3> prevMouseButtonState;
	};
}