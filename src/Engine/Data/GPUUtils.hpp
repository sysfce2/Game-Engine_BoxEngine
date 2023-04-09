#pragma once
#include <BoxEngine.hpp>

namespace BoxEngine {
namespace GPU {

	/// <summary>
	/// Get the drawing type from string
	/// </summary>
	static DrawingType DrawingTypeFromString(std::string key)
	{
		if (key == "LINES")
			return DrawingType::LINES;
		else if (key == "LINE_ADJACENCY")
			return DrawingType::LINE_ADJACENCY;
		else if (key == "LINE_LOOP")
			return DrawingType::LINE_LOOP;
		else if (key == "LINE_STRIP")
			return DrawingType::LINE_STRIP;
		else if (key == "LINE_STRIP_ADJACENCY")
			return DrawingType::LINE_STRIP_ADJACENCY;
		else if (key == "POINTS")
			return DrawingType::POINTS;
		else if (key == "STREAM_CTRIANGLESOPY")
			return DrawingType::TRIANGLES;
		else if (key == "TRIANGLES_ADJACENCY")
			return DrawingType::TRIANGLES_ADJACENCY;
		else if (key == "TRIANGLE_FAN")
			return DrawingType::TRIANGLE_FAN;
		else if (key == "TRIANGLE_STRIP")
			return DrawingType::TRIANGLE_STRIP;
		else if (key == "TRIANGLE_STRIP_ADJACENCY")
			return DrawingType::TRIANGLE_STRIP_ADJACENCY;

		return DrawingType::TRIANGLES;
	}

	/// <summary>
	/// Get data use mode from string
	/// </summary>
	static DataUse DataUseFromString(std::string key)
	{
		if (key == "DYNAMIC_COPY")
			return DataUse::DYNAMIC_COPY;
		else if (key == "DYNAMIC_DRAW")
			return DataUse::DYNAMIC_DRAW;
		else if (key == "DYNAMIC_READ")
			return DataUse::DYNAMIC_READ;
		else if (key == "STATIC_COPY")
			return DataUse::STATIC_COPY;
		else if (key == "STATIC_DRAW")
			return DataUse::STATIC_DRAW;
		else if (key == "STATIC_READ")
			return DataUse::STATIC_READ;
		else if (key == "STREAM_COPY")
			return DataUse::STREAM_COPY;
		else if (key == "STREAM_DRAW")
			return DataUse::STREAM_DRAW;
		else if (key == "STREAM_READ")
			return DataUse::STREAM_READ;

		return DataUse::STATIC_DRAW;
	}

	/// <summary>
	/// Get depth testing mode from string
	/// </summary>
	static DepthTestingMode DepthTestingFromString(std::string key)
	{
		if (key == "ALWAYS")
			return DepthTestingMode::ALWAYS;
		else if (key == "GREATER_EQUAL")
			return DepthTestingMode::GEQUAL;
		else if (key == "GREATER")
			return DepthTestingMode::GREATER;
		else if (key == "LESS_EQUAL")
			return DepthTestingMode::LEQUAL;
		else if (key == "LESS")
			return DepthTestingMode::LESS;
		else if (key == "NEVER")
			return DepthTestingMode::NEVER;
		else if (key == "NOT_EQUAL")
			return DepthTestingMode::NOTEQUAL;

		return DepthTestingMode::NEVER;
	}

	/// <summary>
	/// Get culling face mode from string
	/// </summary>
	static CullingFaceMode CullingFaceFromString(std::string key)
	{
		if (key == "FRONT")
			return CullingFaceMode::FRONT;
		else if (key == "BACK")
			return CullingFaceMode::BACK;
		else if (key == "BOTH")
			return CullingFaceMode::BOTH;

		return CullingFaceMode::BACK;
	}

	/// <summary>
	/// Get polygon mode from string
	/// </summary>
	static PolygonMode PolygonModeFromString(std::string key)
	{
		if (key == "FILL")
			return PolygonMode::FILL;
		else if (key == "LINE")
			return PolygonMode::LINE;
		else if (key == "POINT")
			return PolygonMode::POINT;

		return PolygonMode::FILL;
	}

	/// <summary>
	/// Get magnification filter from string
	/// </summary>
	static MagnificationFilter MagnificationFilterFromString(std::string key)
	{
		if (key == "LINEAR")
			return MagnificationFilter::LINEAR;
		else if (key == "NEAREST")
			return MagnificationFilter::NEAREST;

		return MagnificationFilter::LINEAR;
	}

	/// <summary>
	/// Get minifying filter from string
	/// </summary>
	static MinifyingFilter MinifyingFilterFromString(std::string key)
	{
		if (key == "LINEAR_MIPMAP_LINEAR")
			return MinifyingFilter::LINEAR_MIPMAP_LINEAR;
		else if (key == "LINEAR_MIPMAP_NEAREST")
			return MinifyingFilter::LINEAR_MIPMAP_NEAREST;
		else if (key == "NEAREST_MIPMAP_LINEAR")
			return MinifyingFilter::NEAREST_MIPMAP_LINEAR;
		else if (key == "NEAREST_MIPMAP_NEAREST")
			return MinifyingFilter::NEAREST_MIPMAP_NEAREST;
		else if (key == "ONLY_LINEAR")
			return MinifyingFilter::ONLY_LINEAR;
		else if (key == "ONLY_NEAREST")
			return MinifyingFilter::ONLY_NEAREST;

		return MinifyingFilter::ONLY_NEAREST;
	}

	/// <summary>
	/// Get texture pixel format from string
	/// </summary>
	static TexturePixelFormat TexturePixelFormatFromString(std::string key)
	{
		if (key == "BYTE")
			return TexturePixelFormat::BYTE;
		else if (key == "FLOAT")
			return TexturePixelFormat::FLOAT;
		else if (key == "HALF_FLOAT")
			return TexturePixelFormat::HALF_FLOAT;
		else if (key == "INT")
			return TexturePixelFormat::INT;
		else if (key == "SHORT")
			return TexturePixelFormat::SHORT;
		else if (key == "UNSIGNED_BYTE")
			return TexturePixelFormat::UNSIGNED_BYTE;
		else if (key == "UNSIGNED_BYTE_2_3_3_REV")
			return TexturePixelFormat::UNSIGNED_BYTE_2_3_3_REV;
		else if (key == "UNSIGNED_BYTE_3_3_2")
			return TexturePixelFormat::UNSIGNED_BYTE_3_3_2;
		else if (key == "UNSIGNED_INT")
			return TexturePixelFormat::UNSIGNED_INT;
		else if (key == "UNSIGNED_INT_10_10_10_2")
			return TexturePixelFormat::UNSIGNED_INT_10_10_10_2;
		else if (key == "UNSIGNED_INT_2_10_10_10_REV")
			return TexturePixelFormat::UNSIGNED_INT_2_10_10_10_REV;
		else if (key == "UNSIGNED_INT_8_8_8_8")
			return TexturePixelFormat::UNSIGNED_INT_8_8_8_8;
		else if (key == "UNSIGNED_INT_8_8_8_8_REV")
			return TexturePixelFormat::UNSIGNED_INT_8_8_8_8_REV;
		else if (key == "UNSIGNED_SHORT")
			return TexturePixelFormat::UNSIGNED_SHORT;
		else if (key == "UNSIGNED_SHORT_1_5_5_5_REV")
			return TexturePixelFormat::UNSIGNED_SHORT_1_5_5_5_REV;
		else if (key == "UNSIGNED_SHORT_4_4_4_4")
			return TexturePixelFormat::UNSIGNED_SHORT_4_4_4_4;
		else if (key == "UNSIGNED_SHORT_4_4_4_4_REV")
			return TexturePixelFormat::UNSIGNED_SHORT_4_4_4_4_REV;
		else if (key == "UNSIGNED_SHORT_5_5_5_1")
			return TexturePixelFormat::UNSIGNED_SHORT_5_5_5_1;
		else if (key == "UNSIGNED_SHORT_5_6_5")
			return TexturePixelFormat::UNSIGNED_SHORT_5_6_5;
		else if (key == "UNSIGNED_SHORT_5_6_5_REV")
			return TexturePixelFormat::UNSIGNED_SHORT_5_6_5_REV;
		
		return TexturePixelFormat::BYTE;
	}

	/// <summary>
	/// Get texture internal pixel format from string
	/// </summary>
	static TextureInternalFormat TextureInternalFormatToString(std::string key)
	{
		if(key == "DEPTH_COMPONENT")
			return BoxEngine::GPU::TextureInternalFormat::DEPTH_COMPONENT;
		else if (key == "DEPTH_STENCIL")
			return BoxEngine::GPU::TextureInternalFormat::DEPTH_STENCIL;
		else if (key == "R")
			return BoxEngine::GPU::TextureInternalFormat::R;
		else if (key == "RG")
			return BoxEngine::GPU::TextureInternalFormat::RG;
		else if (key == "RGB")
			return BoxEngine::GPU::TextureInternalFormat::RGB;
		else if (key == "RGBA")
			return BoxEngine::GPU::TextureInternalFormat::RGBA;
		else if (key == "R8")
			return BoxEngine::GPU::TextureInternalFormat::R8;
		else if (key == "R8_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::R8_SNORM;
		else if (key == "R16")
			return BoxEngine::GPU::TextureInternalFormat::R16;
		else if (key == "R16_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::R16_SNORM;
		else if (key == "RG8")
			return BoxEngine::GPU::TextureInternalFormat::RG8;
		else if (key == "RG8_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::RG8_SNORM;
		else if (key == "RG16")
			return BoxEngine::GPU::TextureInternalFormat::RG16;
		else if (key == "RG16_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::RG16_SNORM;
		else if (key == "R3_G3_B2")
			return BoxEngine::GPU::TextureInternalFormat::R3_G3_B2;
		else if (key == "RGB4")
			return BoxEngine::GPU::TextureInternalFormat::RGB4;
		else if (key == "RGB5")
			return BoxEngine::GPU::TextureInternalFormat::RGB5;
		else if (key == "RGB8_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::RGB8_SNORM;
		else if (key == "RGB10")
			return BoxEngine::GPU::TextureInternalFormat::RGB10;
		else if (key == "RGB12")
			return BoxEngine::GPU::TextureInternalFormat::RGB12;
		else if (key == "RGB16_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::RGB16_SNORM;
		else if (key == "RGBA2")
			return BoxEngine::GPU::TextureInternalFormat::RGBA2;
		else if (key == "RGBA4")
			return BoxEngine::GPU::TextureInternalFormat::RGBA4;
		else if (key == "RGB5_A1")
			return BoxEngine::GPU::TextureInternalFormat::RGB5_A1;
		else if (key == "RGBA8")
			return BoxEngine::GPU::TextureInternalFormat::RGBA8;
		else if (key == "RGBA8_SNORM")
			return BoxEngine::GPU::TextureInternalFormat::RGBA8_SNORM;
		else if (key == "RGB10_A2")
			return BoxEngine::GPU::TextureInternalFormat::RGB10_A2;
		else if (key == "RGB10_A2UI")
			return BoxEngine::GPU::TextureInternalFormat::RGB10_A2UI;
		else if (key == "RGBA12")
			return BoxEngine::GPU::TextureInternalFormat::RGBA12;
		else if (key == "RGBA16")
			return BoxEngine::GPU::TextureInternalFormat::RGBA16;
		else if (key == "SRGB8")
			return BoxEngine::GPU::TextureInternalFormat::SRGB8;
		else if (key == "SRGB8_ALPHA8")
			return BoxEngine::GPU::TextureInternalFormat::SRGB8_ALPHA8;
		else if (key == "R16F")
			return BoxEngine::GPU::TextureInternalFormat::R16F;
		else if (key == "RG16F")
			return BoxEngine::GPU::TextureInternalFormat::RG16F;
		else if (key == "RGB16F")
			return BoxEngine::GPU::TextureInternalFormat::RGB16F;
		else if (key == "RGBA16F")
			return BoxEngine::GPU::TextureInternalFormat::RGBA16F;
		else if (key == "R32F")
			return BoxEngine::GPU::TextureInternalFormat::R32F;
		else if (key == "RG32F")
			return BoxEngine::GPU::TextureInternalFormat::RG32F;
		else if (key == "RGB32F")
			return BoxEngine::GPU::TextureInternalFormat::RGB32F;
		else if (key == "RGBA32F")
			return BoxEngine::GPU::TextureInternalFormat::RGBA32F;
		else if (key == "R11F_G11F_B10F")
			return BoxEngine::GPU::TextureInternalFormat::R11F_G11F_B10F;
		else if (key == "RGB9_E5")
			return BoxEngine::GPU::TextureInternalFormat::RGB9_E5;
		else if (key == "R8I")
			return BoxEngine::GPU::TextureInternalFormat::R8I;
		else if (key == "R8UI")
			return BoxEngine::GPU::TextureInternalFormat::R8UI;
		else if (key == "R16I")
			return BoxEngine::GPU::TextureInternalFormat::R16I;
		else if (key == "R16UI")
			return BoxEngine::GPU::TextureInternalFormat::R16UI;
		else if (key == "R32I")
			return BoxEngine::GPU::TextureInternalFormat::R32I;
		else if (key == "R32UI")
			return BoxEngine::GPU::TextureInternalFormat::R32UI;
		else if (key == "RG8I")
			return BoxEngine::GPU::TextureInternalFormat::RG8I;
		else if (key == "RG8UI")
			return BoxEngine::GPU::TextureInternalFormat::RG8UI;
		else if (key == "RG16I")
			return BoxEngine::GPU::TextureInternalFormat::RG16I;
		else if (key == "RG16UI")
			return BoxEngine::GPU::TextureInternalFormat::RG16UI;
		else if (key == "RG32I")
			return BoxEngine::GPU::TextureInternalFormat::RG32I;
		else if (key == "RG32UI")
			return BoxEngine::GPU::TextureInternalFormat::RG32UI;
		else if (key == "RGB8I")
			return BoxEngine::GPU::TextureInternalFormat::RGB8I;
		else if (key == "RGB8UI")
			return BoxEngine::GPU::TextureInternalFormat::RGB8UI;
		else if (key == "RGB16I")
			return BoxEngine::GPU::TextureInternalFormat::RGB16I;
		else if (key == "RGB16UI")
			return BoxEngine::GPU::TextureInternalFormat::RGB16UI;
		else if (key == "RGB32I")
			return BoxEngine::GPU::TextureInternalFormat::RGB32I;
		else if (key == "RGB32UI")
			return BoxEngine::GPU::TextureInternalFormat::RGB32UI;
		else if (key == "RGBA8I")
			return BoxEngine::GPU::TextureInternalFormat::RGBA8I;
		else if (key == "RGBA8UI")
			return BoxEngine::GPU::TextureInternalFormat::RGBA8UI;
		else if (key == "RGBA16I")
			return BoxEngine::GPU::TextureInternalFormat::RGBA16I;
		else if (key == "RGBA16UI")
			return BoxEngine::GPU::TextureInternalFormat::RGBA16UI;
		else if (key == "RGBA32I")
			return BoxEngine::GPU::TextureInternalFormat::RGBA32I;
		else if (key == "RGBA32UI")
			return BoxEngine::GPU::TextureInternalFormat::RGBA32UI;
		else if (key == "COMPRESSED_RED")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RED;
		else if (key == "COMPRESSED_RG")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RG;
		else if (key == "COMPRESSED_RGB")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RGB;
		else if (key == "COMPRESSED_RGBA")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RGBA;
		else if (key == "COMPRESSED_SRGB")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_SRGB;
		else if (key == "COMPRESSED_SRGB_ALPHA")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_SRGB_ALPHA;
		else if (key == "COMPRESSED_RED_RGTC1")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RED_RGTC1;
		else if (key == "COMPRESSED_SIGNED_RED_RGTC1")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_SIGNED_RED_RGTC1;
		else if (key == "COMPRESSED_RG_RGTC2")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_RG_RGTC2;
		else if (key == "COMPRESSED_SIGNED_RG_RGTC2")
			return BoxEngine::GPU::TextureInternalFormat::COMPRESSED_SIGNED_RG_RGTC2;

		return BoxEngine::GPU::TextureInternalFormat::R;
	}

	/// <summary>
	/// Get texture wrap from string
	/// </summary>
	static TextureWrap TextureWrapFromString(std::string key)
	{
		if (key == "REPEATED")
			return TextureWrap::REPEATED;
		else if (key == "CLAMP_TO_BORDER")
			return TextureWrap::CLAMP_TO_BORDER;
		else if (key == "CLAMP_TO_EDGE")
			return TextureWrap::CLAMP_TO_EDGE;
		else if (key == "MIRRORED_REPEAT")
			return TextureWrap::MIRRORED_REPEAT;
		else if (key == "MIRROR_CLAMP_TO_EDGE")
			return TextureWrap::MIRROR_CLAMP_TO_EDGE;

		return TextureWrap::REPEATED;
	}

	/// <summary>
	/// Get texture format from string
	/// </summary>
	static TextureFormat TextureFormatFromString(std::string key)
	{
		if (key == "BGR")
			return TextureFormat::BGR;
		else if (key == "BGRA")
			return TextureFormat::BGRA;
		else if (key == "BGRA_INTEGER")
			return TextureFormat::BGRA_INTEGER;
		else if (key == "BGR_INTEGER")
			return TextureFormat::BGR_INTEGER;
		else if (key == "DEPTH_COMPONENT")
			return TextureFormat::DEPTH_COMPONENT;
		else if (key == "DEPTH_STENCIL")
			return TextureFormat::DEPTH_STENCIL;
		else if (key == "R")
			return TextureFormat::R;
		else if (key == "BGRA")
			return TextureFormat::RED_INTEGER;
		else if (key == "BGRA")
			return TextureFormat::RG;
		else if (key == "BGRA")
			return TextureFormat::RGB;
		else if (key == "BGRA")
			return TextureFormat::RGBA;
		else if (key == "BGRA")
			return TextureFormat::RGBA_INTEGER;
		else if (key == "BGRA")
			return TextureFormat::RGB_INTEGER;
		else if (key == "BGRA")
			return TextureFormat::RG_INTEGER;
		else if (key == "BGRA")
			return TextureFormat::STENCIL_INDEX;

		return TextureFormat::R;
	}

	/// <summary>
	/// Get the vertex buffer type from string
	/// </summary>
	static VertexBufferType VertexBufferTypeFromString(std::string key)
	{
		if (key == "BYTE")
			return VertexBufferType::BYTE;
		else if (key == "DOUBLE")
			return VertexBufferType::DOUBLE;
		else if (key == "FLOAT")
			return VertexBufferType::FLOAT;
		else if (key == "HALF_FLOAT")
			return VertexBufferType::HALF_FLOAT;
		else if (key == "INT")
			return VertexBufferType::INT;
		else if (key == "INT_2_10_10_10_REV")
			return VertexBufferType::INT_2_10_10_10_REV;
		else if (key == "SHORT")
			return VertexBufferType::SHORT;
		else if (key == "UBYTE")
			return VertexBufferType::UBYTE;
		else if (key == "UINT")
			return VertexBufferType::UINT;
		else if (key == "UINT_2_10_10_10_REV")
			return VertexBufferType::UINT_2_10_10_10_REV;
		else if (key == "USHORT")
			return VertexBufferType::USHORT;
		
		return VertexBufferType::FLOAT;
	}

	/// <summary>
	/// Get the size of each vertex data type in bytes.
	/// </summary>
	static unsigned int GetSizeOfVertexBufferType(const VertexBufferType type)
	{
		switch (type)
		{
			case VertexBufferType::BYTE:
				return 1;
			case VertexBufferType::UBYTE:
				return 1;
			case VertexBufferType::SHORT:
				return 2;
			case VertexBufferType::USHORT:
				return 2;
			case VertexBufferType::INT:
				return 4;
			case VertexBufferType::UINT:
				return 4;
			case VertexBufferType::HALF_FLOAT:
				return 2;
			case VertexBufferType::FLOAT:
				return 4;
			case VertexBufferType::DOUBLE:
				return 8;
			case VertexBufferType::INT_2_10_10_10_REV:
				return 4;
			case VertexBufferType::UINT_2_10_10_10_REV:
				return 4;
			default:
				return 0;
		}
	}
}}