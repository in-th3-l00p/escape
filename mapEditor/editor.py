import pygame as pg
import struct

DEFAULT_CELL_THICKNESS = 1


class Editor:
    def __init__(self, size, surface):
        self.surface = surface
        self.map = [[0 for j in range(size[1])] for i in range(size[0])]
        self.cellSize = 30
        self.pos = [
            int(self.surface.get_width() / 2) - int(self.cellSize * len(self.map[0]) / 2),
            int(self.surface.get_height() / 2) - int(self.cellSize * len(self.map) / 2)
        ]

    def render(self):
        for y, vec in enumerate(self.map):
            for x, val in enumerate(vec):
                if val:  # filled if we have a wall or just outlined
                    pg.draw.rect(
                        self.surface, (255, 255, 255),
                        (
                            self.pos[0] + x * self.cellSize,
                            self.pos[1] + y * self.cellSize,
                            self.cellSize, self.cellSize
                        )
                    )
                else:
                    pg.draw.rect(
                        self.surface, (255, 255, 255),
                        (
                            self.pos[0] + x * self.cellSize,
                            self.pos[1] + y * self.cellSize,
                            self.cellSize, self.cellSize
                        ), DEFAULT_CELL_THICKNESS
                    )

    def draw_handler(self):
        mouse = {
            "press": pg.mouse.get_pressed(),
            "pos": pg.mouse.get_pos()
        }

        if (
                (mouse["press"][0] or mouse["press"][2]) and
                mouse["pos"][0] > self.pos[0] and
                mouse["pos"][1] > self.pos[1] and
                mouse["pos"][0] < self.pos[0] + self.cellSize * len(self.map[0]) and
                mouse["pos"][1] < self.pos[1] + self.cellSize * len(self.map)
        ):
            tool = mouse["press"][0] - mouse["press"][1]
            cell = (
                int((mouse["pos"][0] - self.pos[0]) / self.cellSize),
                int((mouse["pos"][1] - self.pos[1]) / self.cellSize),
            )
            self.map[cell[1]][cell[0]] = tool

    def update(self, zoom_direction=0, mouse_motion=(0, 0)):
        # handling mouse wheel
        if pg.key.get_pressed()[pg.K_LSHIFT]:
            self.cellSize += zoom_direction * 5
        else:
            self.cellSize += zoom_direction

        # handling canvas moving
        self.pos[0] += mouse_motion[0]
        self.pos[1] += mouse_motion[1]

        self.render()
        self.draw_handler()

    def serialize(self, savePath):
        with open(savePath, "wb") as file:
            # writing the size of the map
            file.write(struct.pack(">i", len(self.map[0])))
            file.write(struct.pack(">i", len(self.map)))

            # writing the map
            for vec in self.map:
                for val in vec:
                    file.write(struct.pack(">?", val))

            file.close()
