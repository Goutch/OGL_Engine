#include <Ressources/VAO.h>
#include "Entities/MeshRenderer.h"
#include "Chunk.h"
class Voxel;

class ChunkManager;

#include <future>
#include <Math/BoundingBox.h>


class ChunkRenderer : public Entity {
    enum Side{
        up,
        down,
        left,
        right,
        front,
        back
    };

    Camera** pCamera;

    Chunk *current_chunk;
    ChunkManager *chunkManager;

    Mesh mesh;
    bool empty=false;
    const EntityMaterial* material;
    std::vector<unsigned int> indicies;
    std::vector<vec3> vertex_positions;
    std::vector<unsigned int> vertex_uv_index;
    std::vector<unsigned int> vertex_occlusion;
    std::vector<Color> vertex_colors;

    Mesh transparent_mesh;
    bool transparent_empty=false;
    std::vector<unsigned int> transparent_indicies;
    std::vector<vec3> transparent_vertex_positions;
    std::vector<Color> transparent_vertex_colors;
    const EntityMaterial* transparent_material;

    Chunk* chunk_up;
    Chunk* chunk_down;
    Chunk* chunk_left;
    Chunk* chunk_right;
    Chunk* chunk_front;
    Chunk* chunk_back;

    std::mutex mesh_mutex;
public:

    ChunkRenderer(const EntityMaterial &solid_material,const EntityMaterial &transparent_material, ChunkManager &chunkManager);

    bool isLoading();
    Chunk &getChunk() const;

    void rebuild();
    void onBuildFinish();

    void init(Scene &scene) override;
    vec3 getChunkCenter() const;

    void draw(const Scene &scene) const override;
    float getDistanceToCamera() const;
    void createVoxel(int x, int y, int z, const Voxel &voxel);
    void createSide(int x,int y,int z,const Voxel& voxel, Side side);
    std::size_t operator<(const ChunkRenderer &other) const;

    void setChunk(ChunkPosition chunk);
};
