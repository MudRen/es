
// storeroom.c
// This is a little room to serve as local storage for shops. All shops must
// have one to receive items sold at that shop. It doesn't come stocked, if
// you want local shops to keep an inventory on hand you have to clone those
// objects in the shop code and move them to the shop's storeroom.
// Created by Mobydick@TMI-2, 8-25-92

#include <mudlib.h>

inherit ROOM;

void create()
{
	object *room;
	int i;
	string shop;
	
	::create();
	set_short( "�ֿ�" );
	set_long( 
		"������һ��ֿ⣬�����������Ķ������������\n"
	);
	set( "light", 1);
	set( "linked_shop", previous_object() ); 
	set( "exits", ([ "shop": base_name(previous_object()) ]) );
}

// We don't want this to clean_up or the shop will get an error if it tries
// to reference it. The clean_up procedure in the shop will destroy the
// associated storeroom, so this should not be a leak.
int clean_up()
{
	return 0;
}

