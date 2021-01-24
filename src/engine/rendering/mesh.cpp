#include "mesh.h"

engine::Mesh::Mesh(VertexArray* vao, Shader* shader) : m_vao(vao), m_shader(shader) { }
engine::Mesh::~Mesh() { }
