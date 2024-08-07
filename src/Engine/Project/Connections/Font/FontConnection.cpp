#include <BoxEngine.hpp>
#include "FontConnection.hpp"

namespace BoxEngine {
namespace Engine {
namespace Project {
namespace Connection {

	std::weak_ptr<FontConnection> FontConnection::current;

	FontConnection::FontConnection(lua_State* state)
	{
		this->state = state;
	}

	void FontConnection::Bind()
	{
		lua_newtable(this->state);
		
		LuaUtils::RegTable(this->state, "create", Create);
		LuaUtils::RegTable(this->state, "destroy", Destroy);

		LuaUtils::RegTable(this->state, "get_position", GetPosition);
		LuaUtils::RegTable(this->state, "set_position", SetPosition);

		LuaUtils::RegTable(this->state, "get_scale", GetScale);
		LuaUtils::RegTable(this->state, "set_scale", SetScale);

		LuaUtils::RegTable(this->state, "set_color", SetColor);
		LuaUtils::RegTable(this->state, "get_color", GetColor);

		LuaUtils::RegTable(this->state, "set_text", SetText);
		LuaUtils::RegTable(this->state, "get_text", GetText);

		LuaUtils::RegTable(this->state, "get_text_size", GetTextSize);

		LuaUtils::RegTable(this->state, "draw", Draw);

		lua_setglobal(this->state, "_font_");
	}

	void FontConnection::SetCurrentGo(GameObjectPtr go)
	{
		this->currentGo = go;
	}

	FontConnectionPtr FontConnection::Get()
	{
		return current.lock();
	}

	void FontConnection::Set(FontConnectionPtr instance)
	{
		current = instance;
	}
	
	int FontConnection::Create(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 3)
			return luaL_error(L, "expecting 3 arguments in function call");

		std::string fontPath = "";
		int width, height;

		if (lua_isstring(L, 1))
			fontPath = lua_tostring(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a string");

		if (lua_isnumber(L, 2))
			width = lua_tonumber(L, 2);
		else return luaL_error(L, "argument 2 is expected to be a number");

		if (lua_isnumber(L, 3))
			height = lua_tonumber(L, 3);
		else return luaL_error(L, "argument 3 is expected to be a number");

		Font::FontPtr font = nullptr;
		auto instance = FontConnection::Get();

		try
		{
			font = Font::FontPtr(new Font::Font(fontPath, width, height));

			instance->fonts[++instance->currentId] = font;
			lua_pushnumber(L, instance->currentId);
			return 1;
		}
		catch (std::exception)
		{
			lua_pushnil(L);
			font = nullptr;
			instance = nullptr;
			return 1;
		}

		lua_pushnil(L);
		return 1;
	}

	int FontConnection::Destroy(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 argument in function call");

		if (lua_isnumber(L, 1))
		{
			auto instance = FontConnection::Get();
			lua_pushboolean(L, instance->fonts.erase(lua_tonumber(L, 1)));
		}
		else return luaL_error(L, "argument 1 is expected to be a number");

		return 1;
	}

	int FontConnection::SetPosition(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 2)
			return luaL_error(L, "expecting 2 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		glm::vec2 vec;
		if (lua_istable(L, 2))
		{
			if (!LuaUtils::GetTable(L, -1, "x", vec.x))
				return luaL_error(L, "argument x is expected to be a number");

			if (!LuaUtils::GetTable(L, -2, "y", vec.y))
				return luaL_error(L, "argument y is expected to be a number");
		}
		else return luaL_error(L, "argument 2 is expected to be a table with vec2 format");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font != nullptr)
			font->SetPosition(vec);

		lua_pushboolean(L, font != nullptr);

		return 1;
	}

	int FontConnection::GetPosition(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font == nullptr)
		{
			lua_pushnil(L);
			return 1;
		}

		auto vec = font->GetPosition();

		lua_newtable(L);

		lua_pushstring(L, "x");
		lua_pushnumber(L, vec.x);
		lua_settable(L, -3);

		lua_pushstring(L, "y");
		lua_pushnumber(L, vec.y);
		lua_settable(L, -3);

		return 1;
	}

	int FontConnection::SetScale(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 2)
			return luaL_error(L, "expecting 2 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		glm::vec2 vec;
		if (lua_istable(L, 2))
		{
			if (!LuaUtils::GetTable(L, -1, "x", vec.x))
				return luaL_error(L, "argument x is expected to be a number");

			if (!LuaUtils::GetTable(L, -2, "y", vec.y))
				return luaL_error(L, "argument y is expected to be a number");
		}
		else return luaL_error(L, "argument 2 is expected to be a table with vec2 format");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font != nullptr)
			font->SetScale(vec);

		lua_pushboolean(L, font != nullptr);

		return 1;
	}

	int FontConnection::GetScale(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font == nullptr)
		{
			lua_pushnil(L);
			return 1;
		}

		auto vec = font->GetScale();

		lua_newtable(L);

		lua_pushstring(L, "x");
		lua_pushnumber(L, vec.x);
		lua_settable(L, -3);

		lua_pushstring(L, "y");
		lua_pushnumber(L, vec.y);
		lua_settable(L, -3);

		return 1;
	}

	int FontConnection::SetColor(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 2)
			return luaL_error(L, "expecting 2 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		glm::vec3 vec;
		if (lua_istable(L, 2))
		{
			if (!LuaUtils::GetTable(L, -1, "x", vec.x))
				return luaL_error(L, "argument x is expected to be a number");

			if (!LuaUtils::GetTable(L, -2, "y", vec.y))
				return luaL_error(L, "argument y is expected to be a number");

			if (!LuaUtils::GetTable(L, -3, "z", vec.z))
				return luaL_error(L, "argument z is expected to be a number");
		}
		else return luaL_error(L, "argument 3 is expected to be a table with vec3 format");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font != nullptr)
			font->SetColor(vec);

		lua_pushboolean(L, font != nullptr);

		return 1;
	}

	int FontConnection::GetColor(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font == nullptr)
		{
			lua_pushnil(L);
			return 1;
		}

		auto vec = font->GetColor();

		lua_newtable(L);

		lua_pushstring(L, "x");
		lua_pushnumber(L, vec.x);
		lua_settable(L, -3);

		lua_pushstring(L, "y");
		lua_pushnumber(L, vec.y);
		lua_settable(L, -3);

		lua_pushstring(L, "z");
		lua_pushnumber(L, vec.z);
		lua_settable(L, -3);

		return 1;
	}

	int FontConnection::SetText(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 2)
			return luaL_error(L, "expecting 2 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		std::string text = "";
		if (lua_isstring(L, 2))
			text = lua_tostring(L, 2);
		else return luaL_error(L, "argument 2 is expected to be a string");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font != nullptr)
			font->SetText(text);

		lua_pushboolean(L, font != nullptr);

		return 1;
	}

	int FontConnection::GetText(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font == nullptr)
		{
			lua_pushnil(L);
			return 1;
		}

		auto text = font->GetText();
		lua_pushstring(L, text.c_str());

		return 1;
	}

	int FontConnection::GetTextSize(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 arguments in function call");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font == nullptr)
		{
			lua_pushnil(L);
			return 1;
		}

		auto vec = font->GetTextSize();

		lua_newtable(L);

		lua_pushstring(L, "x");
		lua_pushnumber(L, vec.x);
		lua_settable(L, -3);

		lua_pushstring(L, "y");
		lua_pushnumber(L, vec.y);
		lua_settable(L, -3);

		return 1;
	}

	int FontConnection::Draw(lua_State* L)
	{
		auto top = lua_gettop(L);

		if (top != 1)
			return luaL_error(L, "expecting 1 argument in function call");

		if (!HaveFramebuffer())
			return luaL_error(L, "no current framebuffer to draw");

		int id = 0;
		if (lua_isnumber(L, 1))
			id = lua_tonumber(L, 1);
		else return luaL_error(L, "argument 1 is expected to be a number");

		auto instance = FontConnection::Get();
		auto font = instance->fonts[id];

		if (font != nullptr)
			font->Draw();

		lua_pushboolean(L, font != nullptr);
		return 1;
	}

	bool FontConnection::HaveFramebuffer()
	{
		return GPU::Framebuffer::GetCurrendUsedId() != 0;
	}
}}}}