#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ʯ��·" );
	set_long(
	"���ǵ㽫̨���һ��ʯ��·��������������������˵Сȴ���ܹ�����\n"
	"���У�·�ľ�ͷ����Ȼ�����Ժ껪���Ĵ�Ժ��ǧ�����ߣ��ƻ�Ի͡��ſ�(gate)\n"
	"�׾�����ֻ������ʯʨ�ӣ��㲻֪���ǲ��Ǹý�ȥ(enter)��\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "south"  : TROOM"plate",    
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "gate")
    return notify_fail(
    "����Ҫ��ȥ�Ƕ�?\n");
    write (
    "��˫���ƿ��Ű壬�����˽�ȥ...\n");
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_cap_name")+ "���߽������ڡ�\n" ,
    this_player());
    this_player()->move_player(TROOM"chuyi_hall","SNEAK");
return 1;
}
int clean_up() { return 0; }    