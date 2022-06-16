from editor import Editor
import pygame as pg
import tkinter as tk  # for save file dialogs
from tkinter import filedialog

DEFAULT_SIZE = (800, 800)
DEFAULT_WINDOW_TITLE = "escape map editor"


class Application:
    def __init__(self, map_size=(16, 16)):
        pg.init()

        self.window = pg.display.set_mode(DEFAULT_SIZE, pg.RESIZABLE)
        pg.display.set_caption(DEFAULT_WINDOW_TITLE)

        self.running = True
        self.editor = Editor(map_size, self.window)

        self.pressed = False  # tracking if the mouse button is held
        self.last_mouse_pos = (0, 0)

    def run(self):
        while self.running:
            # used by the editor
            zoom = 0
            mouse_motion = (0, 0)

            # event driven programming
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    self.running = False
                    break
                elif event.type == pg.MOUSEWHEEL:
                    zoom = event.y
                elif event.type == pg.MOUSEBUTTONDOWN:
                    if event.button != 2:  # only the middle button
                        continue
                    self.pressed = True
                    self.last_mouse_pos = event.pos
                elif event.type == pg.MOUSEBUTTONUP:
                    if event.button != 2:
                        continue
                    self.pressed = False
                elif event.type == pg.MOUSEMOTION:
                    if self.pressed:
                        mouse_motion = (
                            event.pos[0] - self.last_mouse_pos[0],
                            event.pos[1] - self.last_mouse_pos[1]
                        )
                        self.last_mouse_pos = event.pos

            # testing serialization
            keys = pg.key.get_pressed()
            if keys[pg.K_s]:
                root = tk.Tk()
                root.withdraw()
                path = filedialog.asksaveasfile()
                if path != ():
                    self.editor.serialize(path.name)

            self.window.fill((0, 0, 0))
            self.editor.update(zoom_direction=zoom, mouse_motion=mouse_motion)
            pg.display.update()

    def quit(self):
        pg.quit()

