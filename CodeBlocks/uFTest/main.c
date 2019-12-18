#include <stdio.h>
#include <windows.h>
#include "uframework.h"

void load_sprites()
{
    create_sprite("s_wall", 1);
    add_frame_to_sprite("s_wall", "assets/walls/platformPack_tile040.png");

    create_sprite("s_player_idle", 1);
    add_frame_to_sprite("s_player_idle", "assets/player/platformChar_idle.png");

    create_sprite("s_player_walk", 10);
    add_frame_to_sprite("s_player_walk", "assets/player/platformChar_walk1.png");
    add_frame_to_sprite("s_player_walk", "assets/player/platformChar_walk2.png");

}

void create_walls()
{

    int i;
    for( i = 860 - 128; i > -64 ; i -= 64 )
    {
        //add_tagged_object("wall", 0, i, 64, 64, "s_wall");
    }
    for( i = 0; i < 1700; i += 64 )
    {
        add_tagged_object("wall", i, 860-64, 64, 64, "s_wall");
    }
    int j = i;
    for( i = 860 - 128; i > -64 ; i -= 64 )
    {
        //add_tagged_object("wall", j-64, i, 64, 64, "s_wall");
    }

    add_tagged_object("wall", 100, 860-64*4, 64, 64, "s_wall");
    add_tagged_object("wall", 164, 860-64*4, 64, 64, "s_wall");
    add_tagged_object("wall", 228, 860-64*4, 64, 64, "s_wall");

}



int main()
{
    load_sprites();
    create_walls();

    add_indexed_object("o_player", 100, 500, 96, 96, "s_player_idle");


    initialize("uF::Test", 1700, 860, false);

    //print_log();


    float speed = 0;
    float gravity = 0.5;


    while(!is_window_closed())
    {
        //print_log();

        speed += gravity;



        bool k_left = is_key_pressed("left");
        bool k_right = is_key_pressed("right");
        bool k_space = is_key_pressed("space");

        int move = 0;
        if( k_left )
        {
            move -= 1;
            set_indexed_object_sprite("o_player", "s_player_walk");
        }
        else if(k_right)
        {
            move += 1;
            set_indexed_object_sprite("o_player", "s_player_walk");
        }
        else
        {
            set_indexed_object_sprite("o_player", "s_player_idle");
        }

        move_indexed_object_origin("o_player", move*10, 0);

        if( !pre_check_collition_with_tag("o_player", 0, speed, "wall") )
        //if( !post_check_collition_with_tag("o_player", "wall") )
        {
            move_indexed_object_origin("o_player", 0, speed);

        }
        else
        {
            while(!pre_check_collition_with_tag("o_player", 0, 1, "wall"))
            {
                move_indexed_object_origin("o_player", 0, 1);
            }

            speed = 0;
        }

        if(k_space)
        {
            speed = -8;
            move_indexed_object_origin("o_player", 0, -1);
        }


        Sleep(20);
    }
    return 0;
}
