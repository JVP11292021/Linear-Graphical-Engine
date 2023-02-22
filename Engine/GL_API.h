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

#ifndef __LGE_GL_API__
#define __LGE_GL_API__

#include "engine_setup.h"
#include "lgeCollections.h"

#include "lgeShader.hpp"
#include "lgeBuffers.hpp"
#include "lgeTexture.hpp"
#include "lgeVertexArray.hpp"
#include "lgeRenderAPI.hpp"

#include <glad/glad.h>
#include <unordered_map>
#include <string>
#include <../lmm/lmm.h>
#include <stb/stb_image.h>

#if LGE_BUILD == LGE_DEBUG_BUILD
#	define __glDebug(x) lge::gfx::glClearError(); x; lgeASSERT(lge::gfx::glLogCall(#x, __FILE__, __LINE__))
#else
#	define __glDebug(x) x
#endif

_LGE_BEGIN_NP_LGE_GFX

/*
Typetraits for basic OpenGL types.
Making use of template meta-programming.
*/

template <typename T>
LGE_API
struct gl_trait 
	final {
public:
	typedef T basic_type;
};


template<>
LGE_API
struct gl_trait<GLbyte> 
	final {
public:
	enum { type = GL_BYTE };
	enum { count = 1 };
	enum { stride = sizeof(int8) };
	typedef GLbyte basic_type;
};

template<>
LGE_API
struct gl_trait<GLshort> 
	final {
public:
	enum { type = GL_SHORT };
	enum { count = 2 };
	enum { stride = sizeof(int16) };
	typedef GLshort basic_type;
};

template<>
LGE_API
struct gl_trait<GLushort> 
	final {
public:
	enum { type = GL_UNSIGNED_SHORT };
	enum { count = 2 };
	enum { stride = sizeof(uint16) };
	typedef GLushort basic_type;
};

template<>
LGE_API
struct gl_trait<GLint> 
	final {
public:
	enum { type = GL_INT };
	enum { count = 4 };
	enum { stride = sizeof(int32) };
	typedef GLint basic_type;
};

template<>
LGE_API
struct gl_trait<GLuint> 
	final {
public:
	enum { type = GL_UNSIGNED_INT };
	enum { count = 4 };
	enum { stride = sizeof(uint32) };
	typedef GLuint basic_type;
};

template<>
LGE_API
struct gl_trait<GLfloat> 
	final {
public:
	enum { type = GL_FLOAT };
	enum { count = 4 };
	enum { stride = sizeof(f32) };
	typedef GLfloat basic_type;
};

template<>
LGE_API
struct gl_trait<GLdouble> 
	final {
public:
	enum { type = GL_DOUBLE };
	enum { count = 8 };
	enum { stride = sizeof(f64) };
	typedef GLdouble basic_type;
};

// =====================================================================
// Gl renderer API class
// =====================================================================

class LGE_API GlRenderAPI : public RenderAPI {
public:
	LGE_CUDA_FUNC_DECL void setClearColor(const lmm::vec4&) override;
	LGE_CUDA_FUNC_DECL void clear() override;

	LGE_CUDA_FUNC_DECL void draw(VertexArray*) override;
};

// =====================================================================
// GlTexture2D class(es)
// =====================================================================

class LGE_API GlTexture2D : public Texture2D {
private:
	LGE_CUDA_FUNC_DECL void destroy();
private:
	uint32 ID;
	uint8* localBuffer;
	int32 width, height, bbp;

public:
	GlTexture2D(const std::string&);
	~GlTexture2D();

	LGE_CLS_NON_COPIABLE(GlTexture2D)
	LGE_CLS_CTOR_MOVE(GlTexture2D)

	LGE_CUDA_FUNC_DECL void bind(uint32 = 0) const override;
	LGE_CUDA_FUNC_DECL void unbind() const override;

	LGE_CUDA_FUNC_DECL LGE_INLINE int32 getWidth() const override { return this->width; }
	LGE_CUDA_FUNC_DECL LGE_INLINE int32 getHeight() const override { return this->height; }
	LGE_CUDA_FUNC_DECL LGE_INLINE int32 getBBP() const { return this->bbp; }

};

// =====================================================================
// GlVertexBuffer class
// =====================================================================

class LGE_API GlVertexBuffer : public VertexBuffer {
private:
	LGE_CUDA_FUNC_DECL void destroy();
public:
	GlVertexBuffer(const void*, uint32, int32 = GL_STATIC_DRAW);
	~GlVertexBuffer();

	LGE_CLS_NON_COPIABLE(GlVertexBuffer)
	LGE_CLS_CTOR_MOVE(GlVertexBuffer)

	LGE_CUDA_FUNC_DECL void bind() const override;
	LGE_CUDA_FUNC_DECL void unbind() const override;

	LGE_CUDA_FUNC_DECL void setLayout(const VertexBufferLayout<LGE_VBL_BUFFER>&) override;
	LGE_CUDA_FUNC_DECL const VertexBufferLayout<LGE_VBL_BUFFER>& getLayout() const override;

};

// =====================================================================
// GlIndexBuffer class
// =====================================================================

class LGE_API GlIndexBuffer : public IndexBuffer {
private:
	LGE_CUDA_FUNC_DECL void destroy();
public:
	GlIndexBuffer(const void*, uint32, int32 = GL_STATIC_DRAW);
	~GlIndexBuffer();

	LGE_CLS_NON_COPIABLE(GlIndexBuffer)
	LGE_CLS_CTOR_MOVE(GlIndexBuffer)

	LGE_CUDA_FUNC_DECL void bind() const override;
	LGE_CUDA_FUNC_DECL void unbind() const override;

};

// =====================================================================
// GlVertexArray class
// =====================================================================

class LGE_API GlVertexArray : public VertexArray {
private:
	LGE_CUDA_FUNC_DECL void destroy();
private:
	core::List<const VertexBuffer*> vertex_buffers;
	const IndexBuffer* index_buffer;

public:
	GlVertexArray();
	~GlVertexArray();

	LGE_CLS_NON_COPIABLE(GlVertexArray)
	LGE_CLS_CTOR_MOVE(GlVertexArray)

	//LGE_CUDA_FUNC_DECL void addBuffer(const GlVertexBuffer&, const VertexBufferLayout&);

	LGE_CUDA_FUNC_DECL void bind() const override;
	LGE_CUDA_FUNC_DECL void unbind() const override;

	LGE_CUDA_FUNC_DECL void addVertexBuffer(const VertexBuffer*);
	LGE_CUDA_FUNC_DECL void setIndexBuffer(const IndexBuffer*);

	LGE_CUDA_FUNC_DECL const IndexBuffer& getIndexBuffer() const override {
		return *this->index_buffer;
	}
};

// =====================================================================
// GL Shader 
// =====================================================================

LGE_API enum class glShaderDataTypes {
	None = -1,
	Float8, Float32, Float64, 
	vec2, vec3, vec4, 
	Int8, Int32, Int64, 
	Bool,
	mat2, mat3, mat4
};

LGE_API typedef enum class __GL_ST__ {
	NONE = -1,
	VERTEX = 0,
	FRAGMENT = 1,
	GEOMETRY = 2
}
glShaderType;

class LGE_API GlShader : public Shader {
private:
	LGE_CUDA_FUNC_DECL core::Tuple<std::string> parse(std::string&);
	LGE_CUDA_FUNC_DECL uint32 compile(uint32, istr);
	LGE_CUDA_FUNC_DECL uint32 create(istr, istr, istr = nullptr);
	LGE_CUDA_FUNC_DECL int32 uniformLocation(istr);
	LGE_CUDA_FUNC_DECL void destroy();
private:
	std::unordered_map<std::string, int32> cache;

public:

	GlShader(std::string&);
	GlShader(istr, istr, istr = nullptr);
	~GlShader();

	LGE_CLS_NON_COPIABLE(GlShader)
	LGE_CLS_CTOR_MOVE(GlShader)

	LGE_CUDA_FUNC_DECL void bind() const override;
	LGE_CUDA_FUNC_DECL void unbind() const override;

	LGE_CUDA_FUNC_DECL void setBool(const std::string&, bool) override;
	LGE_CUDA_FUNC_DECL void setInt(const std::string&, int32) override;
	LGE_CUDA_FUNC_DECL void setFloat(const std::string&, f32) override;
	LGE_CUDA_FUNC_DECL void setVec2(const std::string&, const lmm::vec2&) override;
	LGE_CUDA_FUNC_DECL void setVec2(const std::string&, f32 x, f32 y) override;
	LGE_CUDA_FUNC_DECL void setVec3(const std::string&, const lmm::vec3&) override;
	LGE_CUDA_FUNC_DECL void setVec3(const std::string&, f32 x, f32 y, f32 z) override;
	LGE_CUDA_FUNC_DECL void setVec4(const std::string&, const lmm::vec4&) override;
	LGE_CUDA_FUNC_DECL void setVec4(const std::string&, f32 x, f32 y, f32 z, f32 w) override;
	LGE_CUDA_FUNC_DECL void setMat2(const std::string&, const lmm::mat2f&) override;
	LGE_CUDA_FUNC_DECL void setMat3(const std::string&, const lmm::mat3f&) override;
	LGE_CUDA_FUNC_DECL void setMat4(const std::string&, const lmm::mat4f&) override;
};

// =====================================================================
// OpenGL helper functions
// =====================================================================

LGE_CUDA_FUNC_DECL LGE_API int32 glGetSizeofType(uint32);
LGE_CUDA_FUNC_DECL LGE_API void glClearError();
LGE_CUDA_FUNC_DECL LGE_API bool glLogCall(istr, istr, int32);
LGE_CUDA_FUNC_DECL LGE_API int32 glShaderTypeSize(glShaderDataTypes);
LGE_CUDA_FUNC_DECL LGE_API int32 glComponentCount(glShaderDataTypes);
LGE_CUDA_FUNC_DECL LGE_API GLenum glShaderTypeToOpenGl(glShaderDataTypes);
LGE_CUDA_FUNC_DECL LGE_API istr glGetErrorString(GLenum);
_LGE_END_NP_LGE_GFX

#endif