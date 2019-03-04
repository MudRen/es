#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ͥԺ" );
	set_long(
	"����һ��СС��ͥԺ���������ҵ��ţ�Ũ����ɡ��ľҶ֮���в���ҡҷ��\n"
	"ȴ�Ե���ظ�Ϊ�ž����쳾�е����ַ��������Ѿ�δ��ͥԺ��������һ��С\n"
	"С�Ľ�����������һ�����µ�������ͤ(shed)��\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc",(["shed":
        "����һ�����ɵ�С��ͤ����ȫ�������Ƴɣ�ͤ����һ�����������ˣ���\n"
        "��ͷ��֪�ڹۿ�ʲ��? Ҳ��\����Խ�ȥ(enter)����....\n"
        ]));
        set( "exits", ([
                "north"  : TROOM"bed6",
                "east" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "shed")
    return notify_fail(
    "����Ҫ��ȥ�Ƕ�?\n");
    write (
    "��˳��СС�Ľ��ݣ�������������ͤ\n");
    tell_room(this_object(),
	"�㿴��"+this_player()->query("c_name")+"�Ų��߽�����ͤ�ڡ�\n",
    this_player());
    this_player()->move_player(TROOM"shed","SNEAK");
   return 1;
}
int clean_up() { return 0; }    
