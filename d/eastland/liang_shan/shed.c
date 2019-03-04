#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��ͤ" );
	set_long(
	"����һ�����ɵ���ͤ����ȫ�������Ƴɣ���Ȼ����˵����������������\n"
	"��װ��ȴ��������Ȼ��Ϊһ�壬��ͤ�������һ������(chess)����ɱ����\n"
	"���ң�һ��������ʿ��ר�ĵ��о���֣���ȫûע�⵽��ĵ�����\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc", (["chess":
        "�㿴��һ����ʯ���Ƶ�Χ�����̣�������һ��δ����������֣���ĺ�����\n"
        "��ʹ����ϸ�Ŀ���(behold)����֡�\n"
        ]));
        set( "exits", ([
                "out" : TROOM"yard2",
        ]) );
        set( "objects",([
                "wuyong" : TMONSTER"wuyong",
        ]));        
        reset();
}
void init()
{
    add_action("do_behold","behold");
}
int recover(object player)
{
player->set_temp("block_command",0);
write (
"�����þúþã���ò����׻ָ���־��������������������ϴ�֣�ȥ����ʦȥ��:D\n");
return 1;
}  
int do_behold(string arg)
{
if (!arg ||arg !="chess")
return notify_fail(
"��ʲ��?\n");
write (
"����ϸ�Ŀ�������֣�ֻ�������л�����н٣����۸��ӣ���֪ʤ�ܹ�춺η�?\n"
"�㿴���ۻ����ң��亹ֱ��...................\n\n\n"
"������������һ����ɱ����ҵ����Թ���ͻȻ��һ���������ڵء�\n");
this_player()->set_temp("block_command",1);
this_player()->set_explore("eastland#24");
call_out("recover",40,this_player());
return 1;
}
int clean_up() { return 0; }
