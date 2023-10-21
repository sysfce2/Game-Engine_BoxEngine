#include <BoxEngine.hpp>
#include "Mesh.hpp"

namespace BoxEngine {
namespace Modules {
namespace Importer {

	glm::vec3 Mesh::GetMinBox() const
	{
		return this->minBox;
	}

	glm::vec3 Mesh::GetMaxBox() const
	{
		return this->maxBox;
	}

	void Mesh::SetMinBox(const glm::vec3 vec)
	{
		this->minBox = vec;
	}

	void Mesh::SetMaxBox(const glm::vec3 vec)
	{
		this->maxBox = vec;
	}

	void Mesh::SetMesh(GPU::VertexPtr mesh)
	{
		this->mesh = mesh;
	}

	GPU::VertexPtr Mesh::GetMesh() const
	{
		return this->mesh;
	}
	
	void Mesh::SetMaterialIndex(int index)
	{
		this->materialIndex = index;
	}

	int Mesh::GetMaterialIndex() const
	{
		return this->materialIndex;
	}

	void Mesh::SetName(const std::string& name)
	{
		this->name = name;
	}

	std::string Mesh::GetName() const
	{
		return this->name;
	}
}}}