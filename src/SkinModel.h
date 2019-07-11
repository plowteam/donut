#pragma once

#include <GL/IndexBuffer.h>
#include <GL/ShaderProgram.h>
#include <GL/TextureBuffer.h>
#include <GL/VertexBuffer.h>
#include <P3D/Loaders/PolySkinLoader.h>
#include <P3D/Loaders/SkeletonLoader.h>
#include <P3D/P3DFile.h>
#include <P3D/PolySkin.h>
#include <P3D/Skeleton.h>
#include <ResourceManager.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace Donut
{

class SkinModel
{
	struct Vertex
	{
		glm::vec3 pos;
		glm::vec3 normal;
		glm::vec2 uv;
		glm::vec3 boneWeights;
		glm::ivec3 boneIndices;
	};

  public:
	SkinModel(const std::string& filename);

	void Draw(const ResourceManager&, glm::mat4& viewProj);

	P3D::P3DFile& GetP3DFile()
	{
		return *_p3dFile.get();
	}

  private:
	void createMesh();

	std::string _filename;
	std::unique_ptr<P3D::P3DFile> _p3dFile;
	std::unique_ptr<P3D::PolySkin> _polySkin;
	std::unique_ptr<P3D::Skeleton> _skeleton;

	std::unique_ptr<GL::ShaderProgram> _shader;
	GLuint _vertexArrayObject;
	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::IndexBuffer> _indexBuffer;

	std::unique_ptr<GL::TextureBuffer> _boneBuffer;
	std::vector<glm::mat4> _boneMatrices;
	std::vector<glm::mat4> _poseMatrices;
	std::vector<glm::mat4> _finalMatrices;
};

} // namespace Donut
