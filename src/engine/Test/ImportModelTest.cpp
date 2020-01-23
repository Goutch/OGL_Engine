//
// Created by User on 15-Jan.-2020.
//

#include "Geometry/Geometry.h"
#include "ImportModelTest.h"
#include <Entities/FPSController.h>
#include <Entities/MeshRenderer.h>

void ImportModelTest::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    addEntity(new MeshRenderer(mesh,material));
    addEntity(new FPSController(camera));

}

