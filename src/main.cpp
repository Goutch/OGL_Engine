
#include "engine/Core/Engine.h"

#include <Test/PrimitivesTest.h>
#include <Test/TextTest.h>
#include <Editor/Editor.h>

#include "Test/SpacialSceneTest.h"
#include "Test/ApplicationDrawing2D.h"
#include "Test/LAB4.h"
#include <Test/LSystem.h>
#include <Test/ImguiTest.h>
#include <Test/LAB5.h>

int main() {
    Engine engine=Engine();
    //engine.run<LAB5>();
    engine.runInEditor<ApplicationDrawing2D>();
    return 0;
}
