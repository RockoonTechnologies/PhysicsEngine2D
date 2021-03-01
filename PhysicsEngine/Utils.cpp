#include "Utils.h"
#include <numbers>

# define PI 3.141592653589793238462643383279502884

namespace Phys {
	double Radians(double degrees) {
		double result = degrees * (PI / 180);
		return result;
	}
}