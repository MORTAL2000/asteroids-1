#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <string>
#include "interleavedbuffer.h"

/*
 * A lightweight model class, stores the vao, vbo and ebo
 */
class Model {
	std::shared_ptr<GLuint> vao;
	InterleavedBuffer<Layout::ALIGNED, glm::vec3, glm::vec3, glm::vec3> vbo;
	InterleavedBuffer<Layout::ALIGNED, GLushort> ebo;
	size_t n_elems;

public:
	/*
	 * Load the model from an obj file
	 */
	Model(const std::string &file);
	void bind();
	size_t elems();

private:
	void load(const std::string &file);
};

#endif
