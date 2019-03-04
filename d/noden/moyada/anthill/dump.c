// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;
int find;

void create()
{
	::create();
	set_short("������");
	set_long( @C_LONG_DESCRIPTION
�����ƺ�������Ѩ�ĵײ����������������ǵķ������й��(excreta)��
ʳ�����(dump)���ǳ�ζ�������ܼ��ˣ���ֻ�뾡����뿪���
C_LONG_DESCRIPTION
	);
	set( "objects", ([
	   "yellow slime"   : MOYADA"monster/yellow_slime",
	   "green slime"    : MOYADA"monster/green_slime",
	   "red slime"      : MOYADA"monster/red_slime",
	]) );
	set( "search_desc", ([
	  "dump" : "@@search_dump",
	]) );
	set( "item_desc", ([
	  "excreta" : "�������ϵ���й������ˡ�\n",
	  "dump" : "�����ǳ�ʣ��ʳ�����������Ϊ������˷ѡ�\n"+
	           "��ϸһ�����������ʲ�ᶫ����ɧ����\n",
	]) );
	reset();
}

void reset()
{
    ::reset();
    if( !present("metal slime", this_object()) ) find = 0;
}

int search_dump()
{
	object ob;

	if( find ) return 0;
   if( this_player() ) this_player()->set_explore("noden#10");
	ob = new( MOYADA"monster/metal_slime" );
	ob->move( this_object() );
	tell_room( environment(this_object()),
		"ͻȻһֻ����ʷ��ķ�������������˳�����������΢Ц��\n" );
	find = 1;
	call_out( "disappear", 200, ob );
	return 1;
}

void disappear(object ob)
{
	object *item;
	int i;

	if( !ob ) return;
	tell_room( environment(ob), 
		"����ǰ�Ľ���ʷ��ķͻȻ��ʧ�ˡ�\n" , ob
	);
	item = all_inventory(ob);
	for( i=0; i<sizeof(item); i++ ) item[i]->remove();
	ob->remove();
}

void init()
{
	add_action("to_climb", "climb");
}

int to_climb( string str )
{
	if( !str || str=="" )
		return notify_fail("��Ҫ���ĸ�����?\n");
	if( str != "up" )
		return notify_fail("�Ǹ�����ͨ��!\n");
	to_climb_up( this_player(), MOYADA"anthill/cellar3", 40 );
	return 1;
}
