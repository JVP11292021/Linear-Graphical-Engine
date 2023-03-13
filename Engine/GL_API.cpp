/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#include "GL_API.h"

#include <iostream>
#include <fstream>

_LGE_BEGIN_NP_LGE_GFX

// =====================================================================
// Gl renderer API class
// =====================================================================

LGE_CUDA_FUNC_DECL void GlRenderAPI::setClearColor(const lmm::vec4& color) {
	__glDebug(glClearColor(color.r, color.g, color.b, color.a));
}

LGE_CUDA_FUNC_DECL void GlRenderAPI::clear() {
	__glDebug(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

LGE_CUDA_FUNC_DECL void GlRenderAPI::draw(VertexArray* VAO) {
	__glDebug(glDrawElements(GL_TRIANGLES, VAO->getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr));
}

// =====================================================================
// GlTexture2D class
// =====================================================================

LGE_CUDA_FUNC_DECL void GlTexture2D::destroy() {
	__glDebug(glDeleteTextures(1, &this->ID));
	this->ID = 0;
}

GlTexture2D::GlTexture2D(const std::string& path) 
#ifdef	LGE_HAS_INITIALIZER_LIST
	: localBuffer(nullptr), width(0), height(0), bbp(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->localBuffer = nullptr;
	this->width = 0;
	this->height = 0;
	this->bbp = 0;
#endif

	this->ID = 0;
	this->path = path;
	
	//stbi_set_flip_vertically_on_load(1);
	//this->localBuffer = stbi_load(this->path.c_str(), &this->width, &this->height, &this->bbp, 4);

	__glDebug(glGenTextures(1, &this->ID));
	__glDebug(glBindTexture(GL_TEXTURE_2D, this->ID));

	__glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	__glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	__glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	__glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	__glDebug(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->localBuffer));
	__glDebug(glBindTexture(GL_TEXTURE_2D, 0));

	if (this->localBuffer)
		free(this->localBuffer);
}

GlTexture2D::~GlTexture2D() {
	this->destroy();
}

GlTexture2D::GlTexture2D(GlTexture2D&& tex) noexcept
#ifdef	LGE_HAS_INITIALIZER_LIST
	: localBuffer(tex.localBuffer), width(tex.width), height(tex.height), bbp(tex.bbp)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->localBuffer = tex.localBuffer;
	this->width = tex.width;
	this->height = tex.height;
	this->bbp = tex.bbp;
#endif

	this->ID = tex.ID;
	this->path = tex.path;

	tex.ID = NULL;
}

LGE_CUDA_FUNC_DECL GlTexture2D& GlTexture2D::operator = (GlTexture2D&& tex) noexcept {
	if (this != &tex) {
		this->destroy();
		
		this->localBuffer = tex.localBuffer;
		this->width = tex.width;
		this->height = tex.height;
		this->bbp = tex.bbp;
		this->ID = tex.ID;
		this->path = tex.path;

		tex.ID = NULL;
	}

	return *this;
}

LGE_CUDA_FUNC_DECL void GlTexture2D::bind(uint32 slot) const {
	__glDebug(glActiveTexture(GL_TEXTURE0 + slot));
	__glDebug(glBindTexture(GL_TEXTURE_2D, this->ID));
}

LGE_CUDA_FUNC_DECL void GlTexture2D::unbind() const {
	__glDebug(glBindTexture(GL_TEXTURE_2D, 0));
}

// =====================================================================
// GlVertexBuffer class
// =====================================================================

LGE_CUDA_FUNC_DECL void GlVertexBuffer::destroy() {
	__glDebug(glDeleteBuffers(1, &this->ID));
	this->ID = 0;
}

GlVertexBuffer::GlVertexBuffer(const void* data, uint32 size, int32 dMethod) {
	__glDebug(glGenBuffers(1, &this->ID));
	__glDebug(glBindBuffer(GL_ARRAY_BUFFER, this->ID));
	__glDebug(glBufferData(GL_ARRAY_BUFFER, size, data, dMethod));
}

GlVertexBuffer::~GlVertexBuffer() {
	this->destroy();
}

GlVertexBuffer::GlVertexBuffer(GlVertexBuffer&& buffer) noexcept {
	this->ID = buffer.ID;
	this->layout = buffer.layout;
}

LGE_CUDA_FUNC_DECL GlVertexBuffer& GlVertexBuffer::operator = (GlVertexBuffer&& buffer) noexcept {
	if (this != &buffer) {
		this->destroy();

		this->ID = buffer.ID;
		this->layout = buffer.layout;
	}

	return *this;
}

LGE_CUDA_FUNC_DECL void GlVertexBuffer::bind() const {
	__glDebug(glBindBuffer(GL_ARRAY_BUFFER, this->ID));
}

LGE_CUDA_FUNC_DECL void GlVertexBuffer::unbind() const {
	__glDebug(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

LGE_CUDA_FUNC_DECL void GlVertexBuffer::setLayout(const VertexBufferLayout<LGE_VBL_BUFFER>& layout) {
	this->layout = layout;
}

LGE_CUDA_FUNC_DECL const VertexBufferLayout<LGE_VBL_BUFFER>& GlVertexBuffer::getLayout() const {
	return this->layout;
}

// =====================================================================
// GlIndexBuffer class
// =====================================================================

LGE_CUDA_FUNC_DECL void GlIndexBuffer::destroy() {
	__glDebug(glDeleteBuffers(1, &this->ID));
	this->ID = 0;
}

GlIndexBuffer::GlIndexBuffer(const void* data, uint32 count, int32 dMethod) {
	this->count = count;
	__glDebug(glGenBuffers(1, &this->ID));
	__glDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID));
	__glDebug(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), data, dMethod));
}

GlIndexBuffer::~GlIndexBuffer() {
	this->destroy();
}

GlIndexBuffer::GlIndexBuffer(GlIndexBuffer&& buffer) noexcept {
	this->ID = buffer.ID;
	this->count = buffer.count;

	buffer.ID = NULL;
}

LGE_CUDA_FUNC_DECL GlIndexBuffer& GlIndexBuffer::operator = (GlIndexBuffer&& buffer) noexcept {
	if (this != &buffer) {
		this->destroy();

		this->ID = buffer.ID;
		this->count = buffer.count;

		buffer.ID = NULL;
	}

	return *this;
}

LGE_CUDA_FUNC_DECL void GlIndexBuffer::bind() const {
	__glDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID));
}

LGE_CUDA_FUNC_DECL void GlIndexBuffer::unbind() const {
	__glDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

// =====================================================================
// GlVertexArray class
// =====================================================================

LGE_CUDA_FUNC_DECL void GlVertexArray::destroy() {
	__glDebug(glDeleteVertexArrays(1, &this->ID));
	this->ID = 0;
}

GlVertexArray::GlVertexArray() {
	__glDebug(glGenVertexArrays(1, &this->ID));
}

GlVertexArray::~GlVertexArray() {
	this->destroy();
}

GlVertexArray::GlVertexArray(GlVertexArray&& arr) noexcept {
	this->ID = arr.ID;
	this->index_buffer = arr.index_buffer;
	this->vertex_buffers = arr.vertex_buffers;

	arr.ID = 0;
}

LGE_CUDA_FUNC_DECL GlVertexArray& GlVertexArray::operator = (GlVertexArray&& arr) noexcept {
	if (this != &arr) {
		this->destroy();

		this->ID = arr.ID;
		this->index_buffer = arr.index_buffer;
		this->vertex_buffers = arr.vertex_buffers;

		arr.ID = 0;
	}

	return *this;
}

LGE_CUDA_FUNC_DECL void GlVertexArray::bind() const {
	__glDebug(glBindVertexArray(this->ID));
}

LGE_CUDA_FUNC_DECL void GlVertexArray::unbind() const {
	__glDebug(glBindVertexArray(0));
}

LGE_CUDA_FUNC_DECL void GlVertexArray::addVertexBuffer(const VertexBuffer* VBO) {
	__glDebug(glBindVertexArray(this->ID));
	VBO->bind();

	const LGE_AUTO& layout = VBO->getLayout();
	for (uint32 i = 0; i < layout.getLen(); i++) {
		__glDebug(glEnableVertexAttribArray(i));
		__glDebug(glVertexAttribPointer(i, 
			glComponentCount(layout[i].type),
			glShaderTypeToOpenGl(layout[i].type),
			layout[i].normalized ? LGE_TRUE : LGE_FALSE,
			layout.getStride(),
			(const void*)layout[i].offset)
		);
	}

	this->vertex_buffers.append(VBO);
}

LGE_CUDA_FUNC_DECL void GlVertexArray::setIndexBuffer(const IndexBuffer* IBO) {
	__glDebug(glBindVertexArray(this->ID));
	IBO->bind();

	this->index_buffer = IBO;
}

// =====================================================================
// Gl Shader 
// =====================================================================

LGE_CUDA_FUNC_DECL core::Tuple<std::string> GlShader::parse(std::string& path) {
	std::ifstream stream(path);

	std::string line;
	//std::stringstream ss[3];
	glShaderType type = glShaderType::NONE;
	std::string shaders[3];

	while (getline(stream, line)) {
		if (line.find("#type") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = glShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = glShaderType::FRAGMENT;
			else if (line.find("geometry") != std::string::npos)
				type = glShaderType::GEOMETRY;
		}
		else {
			//ss[(int)type] << line << '\n';
			shaders[(int8)type].append(line.append("\n"));
		}
	}

	return core::Tuple<std::string>{shaders[0], shaders[1], shaders[2]};
}

LGE_CUDA_FUNC_DECL uint32 GlShader::compile(uint32 type, istr source) {
	uint32 ssource = glCreateShader(type);
	__glDebug(glShaderSource(ssource, 1, &source, nullptr));
	__glDebug(glCompileShader(ssource));

	int32 result;
	__glDebug(glGetShaderiv(ssource, GL_COMPILE_STATUS, &result));
	if (!result) {
		int32 length;
		__glDebug(glGetShaderiv(ssource, GL_INFO_LOG_LENGTH, &length));
		str message = (str)alloca(length * sizeof(char));
		__glDebug(glGetShaderInfoLog(ssource, length, &length, message));

		std::cout << "LGE::GlShader failed to compile ";
		switch (type) {
		case GL_VERTEX_SHADER:
			std::cout << "vertex GlShader!" << "\n";
			break;
		case GL_FRAGMENT_SHADER:
			std::cout << "fragment GlShader!" << "\n";
			break;
		case GL_GEOMETRY_SHADER:
			std::cout << "geometry GlShader!" << "\n";
			break;
		}

		std::cout << message << "\n";
		__glDebug(glDeleteShader(ssource));
		return 0;
	}

	return ssource;
}

LGE_CUDA_FUNC_DECL uint32 GlShader::create(istr vertex, istr fragment, istr geometry) {
	uint32 program = glCreateProgram();
	uint32 vs = this->compile(GL_VERTEX_SHADER, vertex);
	uint32 fs = this->compile(GL_FRAGMENT_SHADER, fragment);
	uint32 gs = NULL;

	__glDebug(glAttachShader(program, vs));
	__glDebug(glAttachShader(program, fs));
	if (geometry != nullptr) {
		gs = this->compile(GL_GEOMETRY_SHADER, geometry);
		__glDebug(glAttachShader(program, gs));
	}

	__glDebug(glLinkProgram(program));
	__glDebug(glValidateProgram(program));

	__glDebug(glDeleteShader(vs));
	__glDebug(glDeleteShader(fs));

	if (geometry != nullptr)
		__glDebug(glDeleteShader(gs));

	return program;
}

LGE_CUDA_FUNC_DECL int32 GlShader::uniformLocation(istr name) {
	if (this->cache.find(name) != this->cache.end())
		return this->cache[name];

	uint32 location = glGetUniformLocation(this->ID, name);
	if (location == -1)
		std::cout << "LGE::Warning: Uniform '" << name << "' doesn't exist" << "\n";

	this->cache[name] = location;
	return location;
}

LGE_CUDA_FUNC_DECL void GlShader::destroy() {
	__glDebug(glDeleteProgram(this->ID));
	this->ID = 0;
}

GlShader::GlShader(std::string& shaderPath) {
	core::Tuple<std::string> shaders = this->parse(shaderPath);
	this->ID = this->create(shaders[0].c_str(), shaders[1].c_str(), (shaders[2].empty() ? nullptr : shaders[2].c_str()));

	//std::cout << "VERTEX" << std::endl;
	//std::cout << shaders[0] << std::endl;
	//std::cout << "FRAGMENT" << std::endl;
	//std::cout << shaders[1] << std::endl;
	//std::cout << "GEOMETRY" << std::endl;
	//std::cout << shaders[2] << std::endl;

}

GlShader::GlShader(istr vertex, istr fragment, istr geometry) {
	this->ID = this->create(vertex, fragment, geometry);
}

GlShader::~GlShader() {
	this->destroy();
}

GlShader::GlShader(GlShader&& shader) noexcept {
	this->ID = shader.ID;
	this->cache = shader.cache;

	shader.ID = NULL;
}

LGE_CUDA_FUNC_DECL GlShader& GlShader::operator = (GlShader&& shader) noexcept {
	if (this != &shader) {
		this->destroy();

		this->ID = shader.ID;
		this->cache = shader.cache;

		shader.ID = NULL;
	}

	return *this;
}

LGE_CUDA_FUNC_DECL void GlShader::bind() const {
	__glDebug(glUseProgram(this->ID));
}

LGE_CUDA_FUNC_DECL void GlShader::unbind() const {
	__glDebug(glUseProgram(0));
}

LGE_CUDA_FUNC_DECL void GlShader::setBool(const std::string& name, bool value) {
	__glDebug(glUniform1i(this->uniformLocation(name.c_str()), (int32)value));
}

LGE_CUDA_FUNC_DECL void GlShader::setInt(const std::string& name, int32 value) {
	__glDebug(glUniform1i(this->uniformLocation(name.c_str()), value));
}

LGE_CUDA_FUNC_DECL void GlShader::setFloat(const std::string& name, f32 value) {
	__glDebug(glUniform1f(this->uniformLocation(name.c_str()), value));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec2(const std::string& name, const lmm::vec2& value) {
	__glDebug(glUniform2f(this->uniformLocation(name.c_str()), value.x, value.y));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec2(const std::string& name, f32 x, f32 y) {
	__glDebug(glUniform2f(this->uniformLocation(name.c_str()), x, y));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec3(const std::string& name, const lmm::vec3& value) {
	__glDebug(glUniform3f(this->uniformLocation(name.c_str()), value.x, value.y, value.z));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec3(const std::string& name, f32 x, f32 y, f32 z) {
	__glDebug(glUniform3f(this->uniformLocation(name.c_str()), x, y, z));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec4(const std::string& name, const lmm::vec4& value) {
	__glDebug(glUniform4f(this->uniformLocation(name.c_str()), value.x, value.y, value.z, value.w));
}

LGE_CUDA_FUNC_DECL void GlShader::setVec4(const std::string& name, f32 x, f32 y, f32 z, f32 w) {
	__glDebug(glUniform4f(this->uniformLocation(name.c_str()), x, y, z, w));
}

LGE_CUDA_FUNC_DECL void GlShader::setMat2(const std::string& name, const lmm::mat2f& mat) {
	__glDebug(glUniformMatrix2fv(this->uniformLocation(name.c_str()), 1, GL_FALSE, lmm::value_ptr(mat)));
}

LGE_CUDA_FUNC_DECL void GlShader::setMat3(const std::string& name, const lmm::mat3f& mat) {
	__glDebug(glUniformMatrix3fv(this->uniformLocation(name.c_str()), 1, GL_FALSE, lmm::value_ptr(mat)));
}

LGE_CUDA_FUNC_DECL void GlShader::setMat4(const std::string& name, const lmm::mat4f& mat) {
	__glDebug(glUniformMatrix4fv(this->uniformLocation(name.c_str()), 1, GL_FALSE, lmm::value_ptr(mat)));
}

// =====================================================================
// OpenGL helper functions
// =====================================================================

LGE_CUDA_FUNC_DECL LGE_API int32 glGetSizeofType(uint32 glType) {
	switch (glType) {
		case GL_HALF_FLOAT:			return 2;
		case GL_FLOAT:				return 4;
		case GL_DOUBLE:				return 8;
		case GL_UNSIGNED_INT:		return 4;
		case GL_INT:				return 4;
		case GL_UNSIGNED_BYTE:		return 1;
		case GL_BYTE:				return 1;
		case GL_SHORT:				return 2;
		case GL_UNSIGNED_SHORT:		return 2;
		case GL_BOOL:				return 1;
	}

	lgeASSERT(LGE_FALSE);
	return -1;
}

LGE_CUDA_FUNC_DECL LGE_API void glClearError() {
	while (glGetError() != GL_NO_ERROR);
}

LGE_CUDA_FUNC_DECL LGE_API bool glLogCall(istr function, istr file, int32 line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << "Error code = [" << error << "] Message= " << glGetErrorString(error) << ") Thrown in function: " << function << " :" << file << ":" << line << "\n";
		return LGE_FALSE;
	}
	return LGE_TRUE;
}

LGE_CUDA_FUNC_DECL LGE_API int32 glShaderTypeSize(glShaderDataTypes type) {
	switch (type) {
		case glShaderDataTypes::Bool:		return 1;
		case glShaderDataTypes::Int8:		return 1;
		case glShaderDataTypes::Int32:		return 4;
		case glShaderDataTypes::Int64:		return 8;
		case glShaderDataTypes::Float8:		return 1;
		case glShaderDataTypes::Float32:	return 4;
		case glShaderDataTypes::Float64:	return 8;
		case glShaderDataTypes::mat2:		return 2 * 2 * sizeof(float);
		case glShaderDataTypes::mat3:		return 3 * 3 * sizeof(float);
		case glShaderDataTypes::mat4:		return 4 * 4 * sizeof(float);
		case glShaderDataTypes::vec2:		return 2 * sizeof(float);
		case glShaderDataTypes::vec3:		return 3 * sizeof(float);
		case glShaderDataTypes::vec4:		return 4 * sizeof(float);
	}

	lgeASSERT(LGE_FALSE);
	return -1;
}

LGE_CUDA_FUNC_DECL LGE_API int32 glComponentCount(glShaderDataTypes type) {
	switch (type) {
		case glShaderDataTypes::Bool:		return 1;
		case glShaderDataTypes::Int8:		return 1;
		case glShaderDataTypes::Int32:		return 1;
		case glShaderDataTypes::Int64:		return 1;
		case glShaderDataTypes::Float8:		return 1;
		case glShaderDataTypes::Float32:	return 1;
		case glShaderDataTypes::Float64:	return 1;
		case glShaderDataTypes::mat2:		return 2 * 2;
		case glShaderDataTypes::mat3:		return 3 * 3;
		case glShaderDataTypes::mat4:		return 4 * 4;
		case glShaderDataTypes::vec2:		return 2;
		case glShaderDataTypes::vec3:		return 3;
		case glShaderDataTypes::vec4:		return 4;
	}

	lgeASSERT(LGE_FALSE);
	return -1;
}

LGE_CUDA_FUNC_DECL LGE_API GLenum glShaderTypeToOpenGl(glShaderDataTypes type) {
	switch (type) {
	case glShaderDataTypes::Bool:		return GL_BOOL;
	case glShaderDataTypes::Int8:		return GL_INT;
	case glShaderDataTypes::Int32:		return GL_INT;
	case glShaderDataTypes::Int64:		return GL_INT;
	case glShaderDataTypes::Float8:		return GL_FLOAT;
	case glShaderDataTypes::Float32:	return GL_FLOAT;
	case glShaderDataTypes::Float64:	return GL_FLOAT;
	case glShaderDataTypes::mat2:		return GL_FLOAT;
	case glShaderDataTypes::mat3:		return GL_FLOAT;
	case glShaderDataTypes::mat4:		return GL_FLOAT;
	case glShaderDataTypes::vec2:		return GL_FLOAT;
	case glShaderDataTypes::vec3:		return GL_FLOAT;
	case glShaderDataTypes::vec4:		return GL_FLOAT;
	}

	lgeASSERT(LGE_FALSE);
	return -1;
}

LGE_CUDA_FUNC_DECL LGE_API istr glGetErrorString(GLenum error) {
	switch (error) {
		case GL_NO_ERROR:						return "No Error";
		case GL_INVALID_ENUM:					return "Invalid Enum";
		case GL_INVALID_VALUE:					return "Invalid Value";
		case GL_INVALID_OPERATION:				return "Invalid Operation";
		case GL_INVALID_FRAMEBUFFER_OPERATION:	return "Invalid Framebuffer Operation";
		case GL_OUT_OF_MEMORY:					return "Out of Memory";
		case GL_STACK_UNDERFLOW:				return "Stack Underflow";
		case GL_STACK_OVERFLOW:					return "Stack Overflow";
		//case GL_CONTEXT_LOST:					  return "Context Lost";
		default:								return "Unknown Error";
	}
}


_LGE_END_NP_LGE_GFX