
#include "pch.h"
#include "FrameworkWindow.h"
#include <Windows.h>
#include <string>

#include "uframework.h"



FrameworkWindow window;

void initialize(char* title, int width, int height, bool fullscreen)
{
	window.initializeTitle(std::string(title));
	window.initializeSize(width, height);
	window.initializeScreenMode(fullscreen);
	window.launch();
	Sleep(1000);
}

void set_background_color(int red, int green, int blue)
{
	window.setBackgroundColor(red, green, blue);
}

bool is_window_closed()
{
	return window.isClosed();
}

bool create_sprite(char* name, int fps)
{
	return window.createSprite(std::string(name), fps );
}

bool add_frame_to_sprite(char* sprite_name, char* file_name)
{
	return window.addFrameToSprite(std::string(sprite_name), std::string(file_name));
}

void add_object(float x, float y, float width, float height, char* sprite_name)
{
	window.addObject(x, y, width, height, std::string(sprite_name));
}

bool add_indexed_object(char* index, float x, float y, float width, float height, char* sprite_name)
{
	return window.addIndexedObject(std::string(index), x, y, width, height, std::string(sprite_name));
}

void add_tagged_object(char* tag, float x, float y, float width, float height, char* sprite_name)
{
	return window.addTaggedObject(std::string(tag), x, y, width, height, std::string(sprite_name));
}

bool set_indexed_object_tag(char* index, char* tag)
{
	return window.setIndexedObjectTag(std::string(index), std::string(tag));
}

bool set_indexed_object_origin(char* name, float x, float y)
{
	return window.setIndexedObjectOrigin(std::string(name), x, y);
}

bool move_indexed_object_origin(char* name, float dx, float dy)
{
	return window.moveIndexedObjectOrigin(std::string(name), dx, dy);
}

bool set_indexed_object_sprite(char* name, char* sprite_name) 
{
	return window.setIndexedObjectSprite(std::string(name), std::string(sprite_name));
}

bool set_indexed_object_size(char* name, float width, float height)
{
	return window.setIndexedObjectSize(std::string(name), width, height);
}

void move_tagged_object_origin(char* name, float dx, float dy)
{
	window.moveTaggedObjectOrigin(std::string(name), dx, dy);
}

bool set_tagged_object_sprite(char* name, char* sprite_name)
{
	return window.setTaggedObjectSprite(std::string(name), std::string(sprite_name));
}

void set_tagged_object_size(char* name, float width, float height)
{
	window.setTaggedObjectSize(std::string(name), width, height);
}

bool pre_check_collition_with_index(char* index, float dx, float dy, char* another_index)
{
	return window.preObjectCollidesObject(index, dx, dy, another_index);
}

bool pre_check_collition_with_tag(char* index, float dx, float dy, char* tag)
{
	return window.preObjectCollidesTag(index, dx, dy, tag);
}

bool post_check_collition_with_index(char* index, char* another_index)
{
	return window.postObjectCollidesObject(index, another_index);
}

bool post_check_collition_with_tag(char* index, char* tag)
{
	return window.postObjectCollidesTag(index, tag);
}

bool is_key_pressed(char* key_name)
{
	return window.isKeyPressed(std::string(key_name));
}

bool is_gamepad_connected(int gamepad_id)
{
	return window.isGamepadConnected(gamepad_id);
}

bool is_gamepad_button_pressed(int gamepad_id, int button_id)
{
	return window.isGamepadButtonPressed(gamepad_id, button_id);
}

float get_gamepad_axis_value(int gamepad_id, int axis_id)
{
	return window.getGamepadAxisValue(gamepad_id, axis_id);
}

void erase_all()
{
	window.eraseAll();
}

bool erase_by_index(char* index)
{
	window.eraseByIndex(std::string(index));
}

bool erase_by_tag(char* tag)
{
	window.eraseByTag(std::string(tag));
}

mouse_location get_mouse_location()
{
	sf::Vector2i location = window.getMouseLocation();
	mouse_location mouse;
	mouse.x = location.x;
	mouse.y = location.y;

	return mouse;
}

bool is_mouse_button_pressed(char* name)
{
	return window.isMouseButtonPressed(std::string(name));
}

void print_log()
{
	window.printLog();
}

