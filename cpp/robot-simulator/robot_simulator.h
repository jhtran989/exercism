#pragma once

#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

namespace robot_simulator {

// TODO: add your solution here

	enum class Bearing {
		NORTH,
		EAST,
		SOUTH,
		WEST,
	};

	const std::vector<std::pair<int, int>> directionDeltas{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	class Robot {
	private:
		std::pair<int, int> position;
		Bearing direction;

	public:
		Robot() {
			position = std::make_pair(0, 0);
			direction = Bearing::NORTH;
		}

		Robot(std::pair<int, int> position, Bearing direction) {
			this->position = position;
			this->direction = direction;
		}

		std::pair<int, int> get_position() const {
			return position;
		}

		Bearing get_bearing() const {
			return direction;
		}

		// need positive mod so added `+4`
		void turn_right() {
			int directionValue = static_cast<int>(direction);
			int newDirectionValue = (directionValue + 1 + 4) % 4;

			direction = static_cast<Bearing>(newDirectionValue);
		}

		void turn_left() {
			int directionValue = static_cast<int>(direction);
			int newDirectionValue = (directionValue - 1 + 4) % 4;

			direction = static_cast<Bearing>(newDirectionValue);
		}

		void advance() {
			int directionValue = static_cast<int>(direction);
			auto [xDelta, yDelta] = directionDeltas[directionValue];

			position.first += xDelta;
			position.second += yDelta;
		}

		void execute_sequence(std::string seq) {
			for (char c : seq) {
				switch (c) {
				case 'L':
					turn_left();
					break;
				case 'R':
					turn_right();
					break;
				case 'A':
					advance();
					break;
				default:
					throw std::domain_error("invalid sequence action: " + c);
				}
			}
		}
	};

}  // namespace robot_simulator
