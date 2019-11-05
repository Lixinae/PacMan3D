#include <Utils.h>
#include <ConstantStrings.h>

using namespace std;

Utils::Orientation Utils::orientationFromString(string strOrientation) {
	if (strOrientation == "north") {
		return Utils::Orientation::NORTH;
	}
	if (strOrientation == "south") {
		return Utils::Orientation::SOUTH;
	}
	if (strOrientation == "east") {
		return Utils::Orientation::EAST;
	}
	if (strOrientation == "west") {
		return Utils::Orientation::WEST;
	}
	throw invalid_argument(strOrientation + " is not a valid string representation of orientation");
}

string Utils::orientationToString(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return "north";
		case Utils::Orientation::SOUTH:
			return "south";
		case Utils::Orientation::EAST:
			return "east";
		case Utils::Orientation::WEST:
			return "west";
	}
}

float Utils::degreesOfOrientation(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return 180;
		case Utils::Orientation::SOUTH:
			return 0;
		case Utils::Orientation::EAST:
			return 90;
		case Utils::Orientation::WEST:
			return -90;
	}
}

glm::vec3 Utils::vectorOfOrientation(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return glm::vec3(0, 0, -1);
		case Utils::Orientation::SOUTH:
			return glm::vec3(0, 0, 1);
		case Utils::Orientation::EAST:
			return glm::vec3(1, 0, 0);
		case Utils::Orientation::WEST:
			return glm::vec3(-1, 0, 0);
	}
}

Utils::Orientation Utils::randomOrientation(vector<Utils::Orientation> orientations) {
	return orientations[rand() % orientations.size()];
}

Utils::Orientation Utils::randomOrientation() {
	return randomOrientation({
			                         Utils::Orientation::NORTH,
			                         Utils::Orientation::SOUTH,
			                         Utils::Orientation::EAST,
			                         Utils::Orientation::WEST
	                         });
}

Utils::Orientation Utils::oppositeOrientation(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return Utils::Orientation::SOUTH;
		case Utils::Orientation::SOUTH:
			return Utils::Orientation::NORTH;
		case Utils::Orientation::EAST:
			return Utils::Orientation::WEST;
		case Utils::Orientation::WEST:
			return Utils::Orientation::EAST;
	}
}

Utils::Orientation Utils::relativeOrientation(Utils::Orientation viewOrientation, Utils::Orientation orientation) {
	vector<Utils::Orientation> orientations = {
			Utils::Orientation::NORTH,
			Utils::Orientation::WEST,
			Utils::Orientation::SOUTH,
			Utils::Orientation::EAST
	};
	int viewOrientationIndex, orientationIndex;
	switch (viewOrientation) {
		case Utils::Orientation::NORTH:
			viewOrientationIndex = 0;
			break;
		case Utils::Orientation::SOUTH:
			viewOrientationIndex = 2;
			break;
		case Utils::Orientation::EAST:
			viewOrientationIndex = 3;
			break;
		case Utils::Orientation::WEST:
			viewOrientationIndex = 1;
			break;
	}
	switch (orientation) {
		case Utils::Orientation::NORTH:
			orientationIndex = 0;
			break;
		case Utils::Orientation::SOUTH:
			orientationIndex = 2;
			break;
		case Utils::Orientation::EAST:
			orientationIndex = 3;
			break;
		case Utils::Orientation::WEST:
			orientationIndex = 1;
			break;
	}
	return orientations[(viewOrientationIndex + orientationIndex) % orientations.size()];
}

SDLKey Utils::stringToKey(string s) {
	if (s == "a") return SDLK_a;
	if (s == "b") return SDLK_b;
	if (s == "c") return SDLK_c;
	if (s == "d") return SDLK_d;
	if (s == "e") return SDLK_e;
	if (s == "f") return SDLK_f;
	if (s == "g") return SDLK_g;
	if (s == "h") return SDLK_h;
	if (s == "i") return SDLK_i;
	if (s == "j") return SDLK_j;
	if (s == "k") return SDLK_k;
	if (s == "l") return SDLK_l;
	if (s == "m") return SDLK_m;
	if (s == "n") return SDLK_n;
	if (s == "o") return SDLK_o;
	if (s == "p") return SDLK_p;
	if (s == "q") return SDLK_q;
	if (s == "r") return SDLK_r;
	if (s == "s") return SDLK_s;
	if (s == "t") return SDLK_t;
	if (s == "u") return SDLK_u;
	if (s == "v") return SDLK_v;
	if (s == "w") return SDLK_w;
	if (s == "x") return SDLK_x;
	if (s == "y") return SDLK_y;
	if (s == "z") return SDLK_z;
	if (s == "1") return SDLK_1;
	if (s == "2") return SDLK_2;
	if (s == "3") return SDLK_3;
	if (s == "4") return SDLK_4;
	if (s == "5") return SDLK_5;
	if (s == "6") return SDLK_6;
	if (s == "7") return SDLK_7;
	if (s == "8") return SDLK_8;
	if (s == "9") return SDLK_9;
	if (s == "0") return SDLK_0;
	if (s == "k+") return SDLK_KP_PLUS;
	if (s == "k-") return SDLK_KP_MINUS;
	if (s == "k*") return SDLK_KP_MULTIPLY;
	if (s == "k/") return SDLK_KP_DIVIDE;
	if (s == "kenter") return SDLK_KP_ENTER;
	if (s == "k.") return SDLK_KP_PERIOD;
	if (s == "insert") return SDLK_INSERT;
	if (s == "home") return SDLK_HOME;
	if (s == "pgup") return SDLK_PAGEUP;
	if (s == "pgdown") return SDLK_PAGEDOWN;
	if (s == "end") return SDLK_END;
	if (s == "delete") return SDLK_DELETE;
	if (s == "ralt") return SDLK_RALT;
	if (s == "rshift") return SDLK_RSHIFT;
	if (s == "rctrl") return SDLK_RCTRL;
	if (s == "lalt") return SDLK_LALT;
	if (s == "lshift") return SDLK_LSHIFT;
	if (s == "lctrl") return SDLK_LCTRL;
	if (s == "up") return SDLK_UP;
	if (s == "down") return SDLK_DOWN;
	if (s == "right") return SDLK_RIGHT;
	if (s == "left") return SDLK_LEFT;
	if (s == "`") return SDLK_BACKQUOTE;
	if (s == "[") return SDLK_LEFTBRACKET;
	if (s == "]") return SDLK_RIGHTBRACKET;
	if (s == "-") return SDLK_MINUS;
	if (s == "=") return SDLK_EQUALS;
	if (s == "backspace") return SDLK_BACKSPACE;
	if (s == "/") return SDLK_SLASH;
	if (s == "\\") return SDLK_BACKSLASH;
	if (s == ",") return SDLK_COMMA;
	if (s == ".") return SDLK_PERIOD;
	if (s == ";") return SDLK_SEMICOLON;
	if (s == "'") return SDLK_QUOTE;
	if (s == "f1") return SDLK_F1;
	if (s == "f2") return SDLK_F2;
	if (s == "f3") return SDLK_F3;
	if (s == "f4") return SDLK_F4;
	if (s == "f5") return SDLK_F5;
	if (s == "f6") return SDLK_F6;
	if (s == "f7") return SDLK_F7;
	if (s == "f8") return SDLK_F8;
	if (s == "f9") return SDLK_F9;
	if (s == "f10") return SDLK_F10;
	if (s == "f11") return SDLK_F11;
	if (s == "f12") return SDLK_F12;
	if (s == "esc") return SDLK_ESCAPE;
}

string Utils::keyToString(SDLKey key) {

	if (key == SDLK_a) return "a";
	if (key == SDLK_b) return "b";
	if (key == SDLK_c) return "c";
	if (key == SDLK_d) return "d";
	if (key == SDLK_e) return "e";
	if (key == SDLK_f) return "f";
	if (key == SDLK_g) return "g";
	if (key == SDLK_h) return "h";
	if (key == SDLK_i) return "i";
	if (key == SDLK_j) return "j";
	if (key == SDLK_k) return "k";
	if (key == SDLK_l) return "l";
	if (key == SDLK_m) return "m";
	if (key == SDLK_n) return "n";
	if (key == SDLK_o) return "o";
	if (key == SDLK_p) return "p";
	if (key == SDLK_q) return "q";
	if (key == SDLK_r) return "r";
	if (key == SDLK_s) return "s";
	if (key == SDLK_t) return "t";
	if (key == SDLK_u) return "u";
	if (key == SDLK_v) return "v";
	if (key == SDLK_w) return "w";
	if (key == SDLK_x) return "x";
	if (key == SDLK_y) return "y";
	if (key == SDLK_z) return "z";
	if (key == SDLK_1) return "1";
	if (key == SDLK_2) return "2";
	if (key == SDLK_3) return "3";
	if (key == SDLK_4) return "4";
	if (key == SDLK_5) return "5";
	if (key == SDLK_6) return "6";
	if (key == SDLK_7) return "7";
	if (key == SDLK_8) return "8";
	if (key == SDLK_9) return "9";
	if (key == SDLK_0) return "0";
	if (key == SDLK_KP_PLUS) return "k+";
	if (key == SDLK_KP_MINUS) return "k-";
	if (key == SDLK_KP_MULTIPLY) return "k*";
	if (key == SDLK_KP_DIVIDE) return "k/";
	if (key == SDLK_KP_ENTER) return "kenter";
	if (key == SDLK_KP_PERIOD) return "k.";
	if (key == SDLK_INSERT) return "insert";
	if (key == SDLK_HOME) return "home";
	if (key == SDLK_PAGEUP) return "pgup";
	if (key == SDLK_PAGEDOWN) return "pgdown";
	if (key == SDLK_END) return "end";
	if (key == SDLK_DELETE) return "delete";
	if (key == SDLK_RALT) return "ralt";
	if (key == SDLK_RSHIFT) return "rshift";
	if (key == SDLK_RCTRL) return "rctrl";
	if (key == SDLK_LALT) return "lalt";
	if (key == SDLK_LSHIFT) return "lshift";
	if (key == SDLK_LCTRL) return "lcrtrl";
	if (key == SDLK_UP) return "up";
	if (key == SDLK_DOWN) return "down";
	if (key == SDLK_RIGHT) return "right";
	if (key == SDLK_LEFT) return "left";
	if (key == SDLK_BACKQUOTE) return "`";
	if (key == SDLK_LEFTBRACKET) return "[";
	if (key == SDLK_RIGHTBRACKET) return "]";
	if (key == SDLK_MINUS) return "-";
	if (key == SDLK_EQUALS) return "=";
	if (key == SDLK_BACKSPACE) return "backspace";
	if (key == SDLK_SLASH) return "/";
	if (key == SDLK_BACKSLASH) return "\\";
	if (key == SDLK_COMMA) return ",";
	if (key == SDLK_PERIOD) return ".";
	if (key == SDLK_SEMICOLON) return ";";
	if (key == SDLK_QUOTE) return "'";
	if (key == SDLK_F1) return "f1";
	if (key == SDLK_F2) return "f2";
	if (key == SDLK_F3) return "f3";
	if (key == SDLK_F4) return "f4";
	if (key == SDLK_F5) return "f5";
	if (key == SDLK_F6) return "f6";
	if (key == SDLK_F7) return "f7";
	if (key == SDLK_F8) return "f8";
	if (key == SDLK_F9) return "f9";
	if (key == SDLK_F10) return "f10";
	if (key == SDLK_F11) return "f11";
	if (key == SDLK_F12) return "f12";
	if (key == SDLK_ESCAPE) return "esc";
}

string Utils::stringToUpper(string str) {
	struct convert {
		void operator()(char &c) { c = toupper((unsigned char) c); }
	};
	for_each(str.begin(), str.end(), convert());
	return str;
}
