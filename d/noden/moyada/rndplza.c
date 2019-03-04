//#pragma save_binary

#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
    object *obs, ob;
	::create();
	set_short("Բ�ι㳡");
	set_long( @LONG_DESCRIPTION
������վ��Ħ�Ǵ����������Բ�ι㳡������Ħ�Ǵ���������ĵط���
����Կ����ܶ��ħ������Ȥ���˾ۼ����������̸����һЩ�й��ħ��
�Ļ��⡪�����ġ�����ȵȡ�����ɫ֮����(silver tower)���ڹ㳡������
�룬����һ����ɫ��Բ�ν�����㿴����һ���ܴ�����ſɹ����롣
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"south" : MOYADA"mainrd7.c", 
		"west"  : MOYADA"mainrd6.c", 
		"north" : MOYADA"mainrd5.c", 
		"east"  : MOYADA"mainrd8.c",
	]) );
	set( "item_desc", ([
      "tower" : "һ����ɫ��Բ�ν����Ҳ������Խ�ȥ(enter)������\n",
	]) );
	reset();
}

void reset()
{
    object ob;
    if( !present("vendor", this_object()) ) {
      ob = new( "/obj/vendor" );
      ob->set("no_attack", 0);
      ob->set_natural_weapon(20, 10, 20);
      ob->set_natural_armor(40, 10);
      ob->set("max_hp", 200);
      ob->set("hit_points", 200);
      ob->set("exp_reward", 300);
      ob->set("wealth", ([ "silver" : 20 ]) );
      ob->move( this_object() );
    }
    ::reset();
}

void init()
{
    add_action("to_enter","enter");
}

int to_enter( string arg )
{
    object player;
    player = this_player();
    
    if( !arg || arg != "tower" )
      return notify_fail("Enter what?\n");
    tell_room( this_object(), 
      sprintf("%s�߽����ڡ�\n", player->query("c_name") ), player );
    player->move_player("/d/mage/tower/mage_guild","SNEAK");
    tell_room( environment(player), 
      sprintf("%s(%s)���˽�����\n", player->query("c_name"),player->query("name") ), player );
    return 1;
}
