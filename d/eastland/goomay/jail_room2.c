#include "goomay.h"
inherit DOORS;
inherit ROOM;
int move;

void create()
{
        ::create();
        set( "move", 0);
        move = 0;
        set_short("�η�" );
        set_long(
@LONG
�����ǲ����ǹط��˵ĵط������˰��ķ��˶����������򵥵���
�η���ֻ��һ�ŵ����̳ɵĴ����η��г����ù������������Ϣ��������
������ģ������ֲ������Ͽ��ȥ��
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        set( "c_item_desc", ([  "bed" : "@@msg_bed",
                                "hole"  : "@@msg_hole",  ]) );
      create_door("north","south",
            ([  "keyword" : ({"door"}),
                "name"    : "Iron door",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}

void init()
{
    add_action("to_move_bed", "move");
    add_action("to_enter_hole", "enter");
}

string msg_hole()
{
    if( !move )
      return ("���뿴ʲ�᣿\n");

    return ( 
      "����������ڵģ���֪���������ᣬҲ\��\����Խ�ȥ���Կ���\n");
}
string msg_bed()
{
    if( !move )
      return ("һ�ŵ��ݴ���\n");

    return (
      "һ�ŵ��ݴ������ڱ�����ԭ���ĵط�����¶��һ������\n");

}

int to_move_bed( string arg )
{
    string dir;
    if( !arg )
      return notify_fail("move what ?.\n");
    if( arg=="bed" ) {
	if (!move)
	{
        write(
          "��ѵ��ݴ�����һ�ƣ����׵ľͰ����ƿ���¶��һ��������Ķ���\n");
        move = 1;
        set( "move", 1);
		return 1;
	}
      else 
	{
        write(
          "��ѵ��ݴ��ƻ�ԭλ��\n");
        move = 0;
        set( "move", 0);
		return 1;
	}
      return 1;
    }
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" || !move )
      return notify_fail("Enter what?\n");
    if( move )
      this_player()->move_player(Goomay"tunnel1.c","SNEAK");
    return 1;
}

void reset()
{
    ::reset();
    set( "move", 0);
    move = 0;
}
