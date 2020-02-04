//
// Created by User on 13-Jan.-2020.
//

#include "AtlasTextureTest.h"
#include "Entities/MeshRenderer.h"
#include "Geometry/Geometry.h"

void AtlasTextureTest::init(Viewport &viewport, Renderer &renderer, Window &window){
    Scene::init(viewport,renderer,window);

    unsigned char *textureColor = new unsigned char[4 * 4];
    spriteSheet.setCellSize(1, 1);
    textureColor[0] = 255;
    textureColor[1] = 0;
    textureColor[2] = 0;
    textureColor[3] = 255;

    textureColor[4] = 0;
    textureColor[5] = 255;
    textureColor[6] = 0;
    textureColor[7] = 255;

    textureColor[8] = 0;
    textureColor[9] = 0;
    textureColor[10] = 255;
    textureColor[11] = 255;

    textureColor[12] = 255;
    textureColor[13] = 255;
    textureColor[14] = 255;
    textureColor[15] = 255;
    spriteSheet.setTexturePixelData(textureColor, 2, 2, true);
    Geometry::make_quad(mesh);
    addEntity(new MeshRenderer(mesh, material));
}

