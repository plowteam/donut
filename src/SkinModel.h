#pragma once

#include <GL/ShaderProgram.h>
#include <GL/IndexBuffer.h>
#include <GL/VertexBuffer.h>
#include <P3D/P3DFile.h>
#include <P3D/PolySkin.h>
#include <P3D/Loaders/PolySkinLoader.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>

namespace Donut {

class SkinModel {
	struct Vertex {
        glm::vec3 pos;
        glm::vec3 normal;
	};

public:
    SkinModel(const std::string& filename);

	void Draw(glm::mat4& viewProj);

	P3D::P3DFile& GetP3DFile() {
        return *_p3dFile.get();
    }
private:
    void createMesh();

    std::string _filename;
    std::unique_ptr<P3D::P3DFile> _p3dFile;
    std::unique_ptr<P3D::PolySkin> _polySkin;

	std::unique_ptr<GL::ShaderProgram> _shader;
    GLuint _vertexArrayObject;
    std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
    std::unique_ptr<GL::IndexBuffer> _indexBuffer;
};

} // namespace Donut
