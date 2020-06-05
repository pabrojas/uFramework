#pragma once

#include <stdbool.h>

#ifdef MICROFRAMEWORK_EXPORTS
#define MICROFRAMEWORK_API __declspec(dllexport)
#else
#define MICROFRAMEWORK_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	struct mouse {
		int x;
		int y;
	};
	typedef struct mouse mouse_location;

	//Microframework window functions
	MICROFRAMEWORK_API void initialize(char* title, int width, int height, bool fullscreen);
	MICROFRAMEWORK_API void set_background_color(int red, int green, int blue);
	MICROFRAMEWORK_API bool is_window_closed();
	
	//Sprite functions 
	MICROFRAMEWORK_API bool create_sprite(char* name, int fps);
	MICROFRAMEWORK_API bool add_frame_to_sprite(char* sprite_name, char* file_name);

	//Adding objects functions
	MICROFRAMEWORK_API void add_object(float x, float y, float width, float height, char* sprite_name);
	MICROFRAMEWORK_API bool add_indexed_object(char* index, float x, float y, float width, float height, char* sprite_name);
	MICROFRAMEWORK_API void add_tagged_object(char* tag, float x, float y, float width, float height, char* sprite_name);

	//Erasing object functions
	MICROFRAMEWORK_API void erase_all();
	MICROFRAMEWORK_API bool erase_by_index(char* index);
	MICROFRAMEWORK_API bool erase_by_tag(char* tag);


	//Setting indexed objects functions
	MICROFRAMEWORK_API bool set_indexed_object_tag(char* index, char* tag);
	MICROFRAMEWORK_API bool set_indexed_object_origin(char* index, float x, float y);
	MICROFRAMEWORK_API bool move_indexed_object_origin(char* index, float dx, float dy);
	MICROFRAMEWORK_API bool set_indexed_object_sprite(char* index, char* sprite_name);
	MICROFRAMEWORK_API bool set_indexed_object_size(char* index, float width, float height);

	//Setting tagged objects functions
	MICROFRAMEWORK_API void move_tagged_object_origin(char* tag, float dx, float dy);
	MICROFRAMEWORK_API bool set_tagged_object_sprite(char* tag, char* sprite_name);
	MICROFRAMEWORK_API void set_tagged_object_size(char* tag, float width, float height);

	//Checking collitions
	MICROFRAMEWORK_API bool pre_check_collition_with_index(char* index, float dx, float dy, char* another_index);
	MICROFRAMEWORK_API bool pre_check_collition_with_tag(char* index, float dx, float dy, char* tag);
	MICROFRAMEWORK_API bool post_check_collition_with_index(char* index, char* another_index);
	MICROFRAMEWORK_API bool post_check_collition_with_tag(char* index, char* tag);
	
	//Keyboard functions
	MICROFRAMEWORK_API bool is_key_pressed(char* key_name);

	//Gamepad functions
	MICROFRAMEWORK_API bool is_gamepad_connected(int gamepad_id);
	MICROFRAMEWORK_API bool is_gamepad_button_pressed(int gamepad_id, int button_id);
	MICROFRAMEWORK_API float get_gamepad_axis_value(int gamepad_id, int axis_id);

	//Mouse event functions
	MICROFRAMEWORK_API mouse_location get_mouse_location();
	MICROFRAMEWORK_API bool is_mouse_button_pressed(char* name);

	//Log 
	MICROFRAMEWORK_API void print_log();

#ifdef __cplusplus
}
#endif
