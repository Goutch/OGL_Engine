
#include "engine/core/Engine.h"
#include "Test/PerformanceTest.h"
#include "Test/TextureCreationTest.h"
#include "Test/AtlasTextureTest.h"
#include <Test/ImportModelTest.h>
#include <Test/PrimitivesTest.h>
#include <Test/TextTest.h>
#include <Editor/Editor.h>
#include "Test/FullSceneTest.h"
#include "Test/TextTest.h"
int main() {
    Engine engine=Engine();
    auto s=TextTest();
   // auto e=Editor(s);

    engine.start(s);
    return 0;
}
