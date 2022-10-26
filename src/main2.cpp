#include <string>
#include <raylib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "rlgl.h"
#include "raymath.h"

#include <cassert>
#include "common.h"
#include "art.h"


static Camera3D camera;

Vector3 fwd;
Vector3 right;
Vector3 up;

static void UpdateDrawFrame() {

    float a = Vector3Angle(up, Vector3{0, 1, 0});

    Vector2 d = GetMouseDelta();
    if(d.y != 0) {
        fwd = Vector3RotateByAxisAngle(fwd, right, -d.y * DEG2RAD);
        up = Vector3RotateByAxisAngle(up, right, -d.y * DEG2RAD);
//        up = Vector3CrossProduct(fwd, right);
    }

    if(d.x != 0) {
        fwd = Vector3RotateByAxisAngle(fwd, up, -d.x * DEG2RAD);
        right = Vector3RotateByAxisAngle(right, up, -d.x * DEG2RAD);
//        right = Vector3CrossProduct(fwd, up);
    }

    if(IsKeyDown(KEY_W)) {
        Vector3 vel = fwd;
        camera.position = Vector3Add(camera.position, vel);
    }

    if(IsKeyDown(KEY_S)) {
        Vector3 vel = Vector3Negate(fwd);
        camera.position = Vector3Add(camera.position, vel);
    }
    BeginDrawing();

    rlSetMatrixModelview(MatrixIdentity());
    rlSetMatrixProjection(MatrixOrtho(0.0, 800.0, 600.0, 0.0, 0.01, 100.0));


    ClearBackground(RAYWHITE);
    DrawText("Press arrow keys to move", 190, 200, 20, LIGHTGRAY);
    DrawText(TextFormat("Angle to up: %f\n", a), 190, 230, 20, LIGHTGRAY);
    rlDrawRenderBatchActive();
//

    camera.target = Vector3Add(camera.position, fwd); //  Vector3{0, 0, 0};
//    camera.up = Vector3CrossProduct(camera.position, camera.target);
    camera.up = up;

    camera.fovy = 45.0f;


//    Matrix matrix = GetCameraMatrix(camera);

    Matrix matrix = MatrixLookAt(camera.position, camera.target, camera.up);

    rlSetMatrixModelview(matrix);
    rlSetMatrixProjection(MatrixPerspective(45.0f * DEG2RAD, 800.0f / 600.0f, 0.01, 1000.0));

//    rlSetMatrixProjection(MatrixIdentity());

//    BeginMode3D(camera);
    DrawGrid(100, 10);
    CreateL
    DrawSphereEx(Vector3{20, 20, 20}, 10, 20, 20, BLUE);
    rlPushMatrix();
//    rlRotatef(90 , 1, 0, 0);
//    DrawGrid(100, 10);

    rlPopMatrix();
//    EndMode3D();
    EndDrawing();
}

void main2() {
    camera.position = Vector3{50, 50, 50};
    fwd = Vector3{0, 0, -1};
    right = Vector3{1, 0, 0};
    up = Vector3{0, 1, 0};
    InitWindow(800, 600, "raylib [core] example - basic window");

    SetTargetFPS(60);

    HideCursor();
    DisableCursor();
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
}