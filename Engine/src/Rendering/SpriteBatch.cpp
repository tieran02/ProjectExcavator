//
// Created by tieran on 06/08/17.
//
#include "Rendering/SpriteBatch.h"
#include "Core/Vertex.h"
#include "Assets/Shader.h"
#include "Assets/AssetManager.h"
#include <algorithm>

const Vertex vertices[6] = {
        Vertex(Vector3(-1.0f,1.0f,0.0f), Vector2(0.0f,1.0f), Vector4(1,1,1,1)), 
        Vertex(Vector3(1.0f,-1.0f,0.0f), Vector2(1.0f,0.0f), Vector4(1,1,1,1)),
        Vertex(Vector3(-1.0f,-1.0f,0.0f), Vector2(0.0f,0.0f), Vector4(1,1,1,1)),

        Vertex(Vector3(-1.0f,1.0f,0.0f), Vector2(0.0f,1.0f), Vector4(1,1,1,1)),
        Vertex(Vector3(1.0f,1.0f,0.0f), Vector2(1.0f,1.0f), Vector4(1,1,1,1)),
        Vertex(Vector3(1.0f,-1.0f,0.0f), Vector2(1.0f,0.0f), Vector4(1,1,1,1))
};


SpriteBatch::SpriteBatch() : m_vbo(0), m_vao(0), m_sortType()
{
}

SpriteBatch::~SpriteBatch() {

}

void SpriteBatch::Init() {
    createVAO();
}

void SpriteBatch::Begin(SpriteSortType sortType) {
    m_sortType = sortType;
	//Clear any previous data from vectors
	m_batches.clear();
	m_sprites.clear();
	m_spritePointers.clear();
}

void SpriteBatch::End() {
	//create pointes to sprites in m_spritePointers vector
	m_spritePointers.resize(m_sprites.size());
	for (unsigned int i = 0; i < m_sprites.size(); i++)
	{
		m_spritePointers[i] = &m_sprites[i];
	}
    sortSprites();
	createRenderBatches();
}

void SpriteBatch::Draw(Sprite* sprite, float depth, Transform* transform, Color color)
{
    m_sprites.emplace_back(sprite, depth,transform,color);
}


void SpriteBatch::Render() {
	//Bind vao
	Shader* shader = static_cast<Shader*>(AssetManager::Instance()->Get("sprite_shader"));
	if (shader != nullptr) {
		glBindVertexArray(m_vao);

		for (unsigned int i = 0; i < m_batches.size(); i++)
		{
			//Bind texture and shader
			m_batches[i].Texture->Bind();
			shader->Bind();
			//Draw batch
			glDrawArrays(GL_TRIANGLES, m_batches[i].Offset, m_batches[i].VertexCount);
		}
		//unbind vao
		glBindVertexArray(0);
	}
}

void SpriteBatch::createVAO() {
	//Create VAO
    if(m_vao == 0)
        glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
	//Create VBO
    if(m_vbo == 0)
        glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,UV));
    glEnableVertexAttribArray(1);
	// color attribute
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
	glEnableVertexAttribArray(2);
	//unbind vao
    glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches() {
    if(m_spritePointers.empty()){
        return;
    }
	std::vector<Vertex> verts;
	verts.resize(m_spritePointers.size() * 6); //allocate memery for verts

	int offset = 0;
	int currentVert = 0;

    m_batches.emplace_back(offset,6,m_spritePointers[0]->Sprite->GetTexture()); // emplace firse sprite
	Matrix4 transform = m_spritePointers[0]->Transform->TransformMatrix();

	Vector2 size = (Vector2(m_spritePointers[0]->Sprite->Width(), m_spritePointers[0]->Sprite->Height()) / m_spritePointers[0]->Sprite->PixlesPerUnit()) ;
	Vector2* uv = m_spritePointers[0]->Sprite->Region()->TextureCoords();

	verts[currentVert++] = Vertex((transform * Vector4(vertices[0].Pos.x / 2 * size.x, vertices[0].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[0], m_spritePointers[0]->Color.Normilized().Vec4());
	verts[currentVert++] = Vertex((transform * Vector4(vertices[1].Pos.x / 2 * size.x, vertices[1].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[2], m_spritePointers[0]->Color.Normilized().Vec4());
	verts[currentVert++] = Vertex((transform * Vector4(vertices[2].Pos.x / 2 * size.x, vertices[2].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[3], m_spritePointers[0]->Color.Normilized().Vec4());
	verts[currentVert++] = Vertex((transform * Vector4(vertices[3].Pos.x / 2 * size.x, vertices[3].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[0], m_spritePointers[0]->Color.Normilized().Vec4());
	verts[currentVert++] = Vertex((transform * Vector4(vertices[4].Pos.x / 2 * size.x, vertices[4].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[1], m_spritePointers[0]->Color.Normilized().Vec4());
	verts[currentVert++] = Vertex((transform * Vector4(vertices[5].Pos.x / 2 * size.x, vertices[5].Pos.y / 2 * size.y, m_spritePointers[0]->Depth, 1)).XYZ(), uv[2], m_spritePointers[0]->Color.Normilized().Vec4());
	offset += 6;

	for (unsigned int i = 1; i < m_spritePointers.size(); i++)
	{	
		transform = m_spritePointers[i]->Transform->TransformMatrix();
		size = (Vector2(m_spritePointers[i]->Sprite->Width(), m_spritePointers[i]->Sprite->Height()) / m_spritePointers[i]->Sprite->PixlesPerUnit());
		uv = m_spritePointers[i]->Sprite->Region()->TextureCoords();

		if(m_spritePointers[i]->Sprite->GetTexture()->GetTextureID() != m_spritePointers[i-1]->Sprite->GetTexture()->GetTextureID())
		{
			m_batches.emplace_back(offset, 6, m_spritePointers[i]->Sprite->GetTexture()); // if texture is differnt
		}
		else
		{
			m_batches.back().VertexCount += 6;
		}
		verts[currentVert++] = Vertex((transform * Vector4(vertices[0].Pos.x / 2 * size.x, vertices[0].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[0], m_spritePointers[i]->Color.Normilized().Vec4());
		verts[currentVert++] = Vertex((transform * Vector4(vertices[1].Pos.x / 2 * size.x, vertices[1].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[2], m_spritePointers[i]->Color.Normilized().Vec4());
		verts[currentVert++] = Vertex((transform * Vector4(vertices[2].Pos.x / 2 * size.x, vertices[2].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[3], m_spritePointers[i]->Color.Normilized().Vec4());
		verts[currentVert++] = Vertex((transform * Vector4(vertices[3].Pos.x / 2 * size.x, vertices[3].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[0], m_spritePointers[i]->Color.Normilized().Vec4());
		verts[currentVert++] = Vertex((transform * Vector4(vertices[4].Pos.x / 2 * size.x, vertices[4].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[1], m_spritePointers[i]->Color.Normilized().Vec4());
		verts[currentVert++] = Vertex((transform * Vector4(vertices[5].Pos.x / 2 * size.x, vertices[5].Pos.y / 2 * size.y, m_spritePointers[i]->Depth, 1)).XYZ(), uv[2], m_spritePointers[i]->Color.Normilized().Vec4());
		offset += 6;

	}

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW); //orphan buffer
	glBufferSubData(GL_ARRAY_BUFFER, 0, verts.size() * sizeof(Vertex), verts.data()); //upload data
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteBatch::sortSprites() {
    switch(m_sortType) {
        case SpriteSortType::BACK_FRONT:
            std::sort(m_spritePointers.begin(), m_spritePointers.end(),compareBackToBack);
            break;
        case SpriteSortType::FRONT_BACK:
            std::sort(m_spritePointers.begin(), m_spritePointers.end(),compareFrontToBack);
            break;
        case SpriteSortType::TEXTURE:
            std::sort(m_spritePointers.begin(), m_spritePointers.end(),compareTexture);
            break;
    }
}

bool SpriteBatch::compareFrontToBack(glyph *a, glyph *b) {
    return (a->Depth < b->Depth );
}

bool SpriteBatch::compareBackToBack(glyph *a, glyph *b) {
    return (a->Depth > b->Depth );}

bool SpriteBatch::compareTexture(glyph *a, glyph *b) {
    return (a->Sprite->GetTexture()->GetTextureID() < b->Sprite->GetTexture()->GetTextureID() );
}
