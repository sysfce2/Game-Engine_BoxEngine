function end_frame.start()
   local this = engine.current()
   local size_editor = engine.window.get_editor_window_size();

   -- coordinates to draw in editor
   this.camera_editor_id = engine.cam2d.create({ left = 0, right = size_editor.x, top = size_editor.y, bottom = 0})
   engine.script.set_persist_script_data('camera_editor_id', false)
end

function end_frame.update()
   local this = engine.current()
   local begin_frame_go = engine.data(this.begin_id, 'begin_frame')
   local size_editor = engine.window.get_editor_window_size();
  
   engine.cam2d.set_current(this.camera_editor_id)
   engine.cam2d.update(this.camera_editor_id, {left = 0, right = size_editor.x, top = size_editor.y, bottom = 0})

   engine.framebuffer.active_none()
   engine.framebuffer.set_viewport({x = 0, y = 0, z = size_editor.x, w = size_editor.y})

   engine.draw2d.frame(begin_frame_go.texture_id)
end

function end_frame.destroy()
   local this = engine.current()
   engine.cam2d.destroy(this.camera_editor_id)
end
