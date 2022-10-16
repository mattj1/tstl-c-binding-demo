declare namespace rl {
	/** @customConstructor rl.Vector2:new */
	class Vector2 {
		constructor(args?: {x?: number, y?: number});
		x: number;
		y: number;
	}
	/** @customConstructor rl.Vector3:new */
	class Vector3 {
		constructor(args?: {x?: number, y?: number, z?: number});
		x: number;
		y: number;
		z: number;
	}
	/** @customConstructor rl.Color:new */
	class Color {
		constructor(args?: {r?: number, g?: number, b?: number, a?: number});
		r: number;
		g: number;
		b: number;
		a: number;
	}
	/** @customConstructor rl.Rectangle:new */
	class Rectangle {
		constructor(args?: {x?: number, y?: number, width?: number, height?: number});
		x: number;
		y: number;
		width: number;
		height: number;
	}
	/** @customConstructor rl.Camera2D:new */
	class Camera2D {
		constructor(args?: {offset?: Vector2, target?: Vector2, rotation?: number, zoom?: number});
		offset: Vector2;
		target: Vector2;
		rotation: number;
		zoom: number;
	}
	const LIGHTGRAY: Color;
	const BLUE: Color;
	const RAYWHITE: Color;
	enum KeyboardKey {
		KEY_NULL = 0,
		KEY_APOSTROPHE = 39,
		KEY_COMMA = 44,
		KEY_MINUS = 45,
		KEY_PERIOD = 46,
		KEY_SLASH = 47,
		KEY_ZERO = 48,
		KEY_ONE = 49,
		KEY_TWO = 50,
		KEY_THREE = 51,
		KEY_FOUR = 52,
		KEY_FIVE = 53,
		KEY_SIX = 54,
		KEY_SEVEN = 55,
		KEY_EIGHT = 56,
		KEY_NINE = 57,
		KEY_SEMICOLON = 59,
		KEY_EQUAL = 61,
		KEY_A = 65,
		KEY_B = 66,
		KEY_C = 67,
		KEY_D = 68,
		KEY_E = 69,
		KEY_F = 70,
		KEY_G = 71,
		KEY_H = 72,
		KEY_I = 73,
		KEY_J = 74,
		KEY_K = 75,
		KEY_L = 76,
		KEY_M = 77,
		KEY_N = 78,
		KEY_O = 79,
		KEY_P = 80,
		KEY_Q = 81,
		KEY_R = 82,
		KEY_S = 83,
		KEY_T = 84,
		KEY_U = 85,
		KEY_V = 86,
		KEY_W = 87,
		KEY_X = 88,
		KEY_Y = 89,
		KEY_Z = 90,
		KEY_LEFT_BRACKET = 91,
		KEY_BACKSLASH = 92,
		KEY_RIGHT_BRACKET = 93,
		KEY_GRAVE = 96,
		KEY_SPACE = 32,
		KEY_ESCAPE = 256,
		KEY_ENTER = 257,
		KEY_TAB = 258,
		KEY_BACKSPACE = 259,
		KEY_INSERT = 260,
		KEY_DELETE = 261,
		KEY_RIGHT = 262,
		KEY_LEFT = 263,
		KEY_DOWN = 264,
		KEY_UP = 265,
		KEY_PAGE_UP = 266,
		KEY_PAGE_DOWN = 267,
		KEY_HOME = 268,
		KEY_END = 269,
		KEY_CAPS_LOCK = 280,
		KEY_SCROLL_LOCK = 281,
		KEY_NUM_LOCK = 282,
		KEY_PRINT_SCREEN = 283,
		KEY_PAUSE = 284,
		KEY_F1 = 290,
		KEY_F2 = 291,
		KEY_F3 = 292,
		KEY_F4 = 293,
		KEY_F5 = 294,
		KEY_F6 = 295,
		KEY_F7 = 296,
		KEY_F8 = 297,
		KEY_F9 = 298,
		KEY_F10 = 299,
		KEY_F11 = 300,
		KEY_F12 = 301,
		KEY_LEFT_SHIFT = 340,
		KEY_LEFT_CONTROL = 341,
		KEY_LEFT_ALT = 342,
		KEY_LEFT_SUPER = 343,
		KEY_RIGHT_SHIFT = 344,
		KEY_RIGHT_CONTROL = 345,
		KEY_RIGHT_ALT = 346,
		KEY_RIGHT_SUPER = 347,
		KEY_KB_MENU = 348,
		KEY_KP_0 = 320,
		KEY_KP_1 = 321,
		KEY_KP_2 = 322,
		KEY_KP_3 = 323,
		KEY_KP_4 = 324,
		KEY_KP_5 = 325,
		KEY_KP_6 = 326,
		KEY_KP_7 = 327,
		KEY_KP_8 = 328,
		KEY_KP_9 = 329,
		KEY_KP_DECIMAL = 330,
		KEY_KP_DIVIDE = 331,
		KEY_KP_MULTIPLY = 332,
		KEY_KP_SUBTRACT = 333,
		KEY_KP_ADD = 334,
		KEY_KP_ENTER = 335,
		KEY_KP_EQUAL = 336,
		KEY_BACK = 4,
		KEY_MENU = 82,
		KEY_VOLUME_UP = 24,
		KEY_VOLUME_DOWN = 25,
	}
	enum MouseButton {
		MOUSE_BUTTON_LEFT = 0,
		MOUSE_BUTTON_RIGHT = 1,
		MOUSE_BUTTON_MIDDLE = 2,
		MOUSE_BUTTON_SIDE = 3,
		MOUSE_BUTTON_EXTRA = 4,
		MOUSE_BUTTON_FORWARD = 5,
		MOUSE_BUTTON_BACK = 6,
	}
	function IsKeyPressed(key: number): boolean;
	function IsKeyDown(key: number): boolean;
	function IsKeyReleased(key: number): boolean;
	function IsKeyUp(key: number): boolean;
	function SetExitKey(key: number): void;
	function GetKeyPressed(): number;
	function GetCharPressed(): number;
	function ClearBackground(color: Color): void;
	function BeginDrawing(): void;
	function EndDrawing(): void;
	function BeginMode2D(camera: Camera2D): void;
	function EndMode2D(): void;
	function IsMouseButtonPressed(button: number): boolean;
	function IsMouseButtonDown(button: number): boolean;
	function IsMouseButtonReleased(button: number): boolean;
	function IsMouseButtonUp(button: number): boolean;
	function GetMouseX(): number;
	function GetMouseY(): number;
	function GetMousePosition(): Vector2;
	function GetMouseDelta(): Vector2;
	function DrawPixel(posX: number, posY: number, color: Color): void;
	function DrawPixelV(position: Vector2, color: Color): void;
	function DrawLine(startPosX: number, startPosY: number, endPosX: number, endPosY: number, color: Color): void;
	function DrawLineV(startPos: Vector2, endPos: Vector2, color: Color): void;
	function DrawLineEx(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void;
	function DrawLineBezier(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void;
	function DrawLineBezierQuad(startPos: Vector2, endPos: Vector2, controlPos: Vector2, thick: number, color: Color): void;
	function DrawLineBezierCubic(startPos: Vector2, endPos: Vector2, startControlPos: Vector2, endControlPos: Vector2, thick: number, color: Color): void;
	function DrawLineStrip(points: Vector2, pointCount: number, color: Color): void;
	function DrawCircle(centerX: number, centerY: number, radius: number, color: Color): void;
	function DrawCircleSector(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
	function DrawCircleSectorLines(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
	function DrawCircleGradient(centerX: number, centerY: number, radius: number, color1: Color, color2: Color): void;
	function DrawCircleV(center: Vector2, radius: number, color: Color): void;
	function DrawCircleLines(centerX: number, centerY: number, radius: number, color: Color): void;
	function DrawEllipse(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void;
	function DrawEllipseLines(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void;
	function DrawRing(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
	function DrawRingLines(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
	function DrawRectangle(posX: number, posY: number, width: number, height: number, color: Color): void;
	function DrawRectangleV(position: Vector2, size: Vector2, color: Color): void;
	function DrawRectangleRec(rec: Rectangle, color: Color): void;
	function DrawRectanglePro(rec: Rectangle, origin: Vector2, rotation: number, color: Color): void;
	function DrawRectangleGradientV(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void;
	function DrawRectangleGradientH(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void;
	function DrawRectangleGradientEx(rec: Rectangle, col1: Color, col2: Color, col3: Color, col4: Color): void;
	function DrawRectangleLines(posX: number, posY: number, width: number, height: number, color: Color): void;
	function DrawRectangleLinesEx(rec: Rectangle, lineThick: number, color: Color): void;
	function DrawRectangleRounded(rec: Rectangle, roundness: number, segments: number, color: Color): void;
	function DrawRectangleRoundedLines(rec: Rectangle, roundness: number, segments: number, lineThick: number, color: Color): void;
	function DrawText(text: string, posX: number, posY: number, fontSize: number, color: Color): void;
	function CheckCollisionRecs(rec1: Rectangle, rec2: Rectangle): boolean;
	function CheckCollisionCircles(center1: Vector2, radius1: number, center2: Vector2, radius2: number): boolean;
	function CheckCollisionCircleRec(center: Vector2, radius: number, rec: Rectangle): boolean;
	function CheckCollisionPointRec(point: Vector2, rec: Rectangle): boolean;
	function CheckCollisionPointCircle(point: Vector2, center: Vector2, radius: number): boolean;
	function CheckCollisionPointTriangle(point: Vector2, p1: Vector2, p2: Vector2, p3: Vector2): boolean;
	function CheckCollisionLines(startPos1: Vector2, endPos1: Vector2, startPos2: Vector2, endPos2: Vector2, collisionPoint: Vector2): boolean;
	function CheckCollisionPointLine(point: Vector2, p1: Vector2, p2: Vector2, threshold: number): boolean;
	function GetCollisionRec(rec1: Rectangle, rec2: Rectangle): Rectangle;
	function ColorAlpha(color: Color, alpha: number): Color;
	function GetScreenToWorld2D(position: Vector2, camera: Camera2D): Vector2;
	function Vector2Distance(v1: Vector2, v2: Vector2): number;
	function Vector2DistanceSqr(v1: Vector2, v2: Vector2): number;
	function Vector2Add(v1: Vector2, v2: Vector2): Vector2;
	function Vector2Scale(v: Vector2, scale: number): Vector2;
}
