-- print("rl_test---")
-- print("rl", rl)
-- r = rl.Vector2:new()
-- print(r.x)
-- r.x = 1234
-- print(r.x)
-- --
-- r2 = rl.MakeAVector2()
-- print(r2.x)
--
-- r3 = rl.MakeAVector2()
-- print(r3.x)
print(rl)
print(rl["@"])
--
-- v = rl.Vector2:new()
-- v.x = 100
-- print(v.x)

camera = rl.Camera2D:new({
    offset=rl.Vector2:new({x=111, y=222})
    })
camera.offset.x = 123
print(camera.offset.x)
print(camera.offset.y)

-- print(rl.RAYWHITE)
-- print(rl.RAYWHITE.r)
-- print(rl.RAYWHITE.a)