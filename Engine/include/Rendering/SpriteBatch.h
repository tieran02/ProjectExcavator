#pragma once

#include <glad/glad.h>
#include <vector>
#include <Rendering/Texture2D.h>
#include <Rendering/Sprite.h>
#include <Core/Components/Transform.h>



enum class SpriteSortType{
    FRONT_BACK,
    BACK_FRONT,
    TEXTURE
};

class RenderBatch{
public:
    RenderBatch(GLuint offset, GLuint vertexCount, Texture2D* texture) : Offset(offset), VertexCount(vertexCount),
		Texture(texture){}
    GLuint Offset;
    GLuint VertexCount;
    Texture2D* Texture;
};

class SpriteBatch {
public:
    SpriteBatch();
    ~SpriteBatch();

    void Init();

    void Begin(SpriteSortType sortType = SpriteSortType::TEXTURE);
    void End();

	void Draw(Sprite* sprite, float depth, Transform* transform);

    void Render();
private:

	struct glyph
	{
		glyph(Sprite* sprite, float depth, Transform* transform) : Sprite(sprite), Depth(depth), Transform(transform){}
		Sprite* Sprite;
		float Depth;
		Transform* Transform;
	};

    GLuint m_vbo;
    GLuint m_vao;

    SpriteSortType m_sortType;
	std::vector<glyph*> m_spritePointers; //sorting
    std::vector<glyph> m_sprites; //values
    std::vector<RenderBatch> m_batches;

    void createRenderBatches();
    void createVAO();
    void sortSprites();

    static bool compareFrontToBack(glyph* a, glyph* b);
    static bool compareBackToBack(glyph* a, glyph* b);
    static bool compareTexture(glyph* a, glyph* b);
};
