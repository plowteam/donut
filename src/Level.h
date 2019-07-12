#pragma once

#include <GL/IndexBuffer.h>
#include <GL/ShaderProgram.h>
#include <GL/TextureBuffer.h>
#include <GL/VertexBuffer.h>
#include <P3D/P3DFile.h>
#include <P3D/PolySkin.h>
#include <P3D/Skeleton.h>
#include <P3D/Shader.h>
#include <P3D/Animation.h>
#include <ResourceManager.h>
#include <StaticModel.h>
#include <glm/glm.hpp>
#include <map>
#include <string>
#include <vector>

namespace Donut
{

class Level
{
public:
	Level();

	void Draw(const ResourceManager&, glm::mat4& viewProj);
	void LoadP3D(const std::string& filename);

private:
	std::vector<std::unique_ptr<StaticModel>> _models;
	std::map<std::string, std::unique_ptr<P3D::Shader>> _shaders;
	std::map<std::string, std::unique_ptr<GL::Texture2D>> _textures;
	std::unique_ptr<GL::ShaderProgram> _worldShader;
};

} // namespace Donut
