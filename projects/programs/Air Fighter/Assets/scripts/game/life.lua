function life.start()
    local this = engine.current()
    local path = engine.dir.get_assets_path() .. '/images/life.png'

    this.texture = engine.texture.create({
        minifying_filter = engine.enums.minifying_filter.linear_mipmap_linear,
        magnification_filter = engine.enums.magnification_filter.linear,
        texture_wrap_t = engine.enums.texture_wrap.clamp_to_edge,
        texture_wrap_s = engine.enums.texture_wrap.clamp_to_edge,
        ansiotropic_filter = 8,
        border_color = { x = 0, y = 0, z = 0 },
        image_path = path
    })

    local cam2d = engine.cam2d.get(engine.cam2d.get_current())
    this.max_x = cam2d.right;
    this.max_y = cam2d.top;

    -- intial position
    this.x = math.random() * this.max_x;
    this.y = this.max_y + 100;

    this.size_x = 35
    this.size_y = 35
end

function life.update()
    local this = engine.current()

    this.y = this.y - (engine.get_frametime() * 0.2)

    engine.draw2d.texture({
        position = { x = this.x, y = this.y },
        size = { x = this.size_x, y = this.size_y },
        texture_id = this.texture,
    })

    -- if cross all the screen on Y exis then destroy it
    if (this.y < -100) then
        engine.go.destroy(engine.go.current())
    end

    life.collide()
end

function life.collide()
    local this = engine.current()

    -- collision of life and fighter
    local fighter_go = engine.data(this.fighter_id, 'fighter')

    if (fighter_go == nil) then
        return
    end

    -- calculate bouding box on x axis
    local max_x = fighter_go.x + fighter_go.size_x / 2
    local min_x = fighter_go.x - fighter_go.size_x / 2

    if (this.x > min_x and this.x < max_x) then
        -- calculate enemy bouding box on y axis
        local max_y = fighter_go.y + fighter_go.size_y / 2
        local min_y = fighter_go.y - fighter_go.size_y / 2

        if (this.y > min_y and this.y < max_y) then
            fighter_go.life = fighter_go.life + 1
            engine.go.destroy(engine.go.current())
        end
    end
end

function life.destroy()
    local this = engine.current()
    engine.texture.destroy(this.texture)
end
