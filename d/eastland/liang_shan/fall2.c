#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����" );
	set_long(
	"�����ڰ���У���ͣ������׹�䣬�����¿�ȥ���ޱߵĺڰ��������\n"
	"�ſ���������ӭ�����������ʶ���������˵��������һ�����ҵĽ���\n"
	);
        set( "no_monster",1);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"jail1"
        ]) );
}
int recover(object player)
{
write ("\n����춻ظ���־���ſ��۾� ...\n\n");
player->set_temp("block_command",0);
player->move_player( TROOM"jail1","SNEAK");
tell_room(TROOM"jail1",
"�㿴��һ���˴�������������˵��������ò������į��.......\n",player);
return 1;
}
int check_fall()
{
write(
"\n�㲻ͣ������ڵĿռ���ȥ��ͻȻ����һ�����죬������䵽�˵��档�޴��\n"
"ײ������ʹ���������ˣ���ʹ��̱���ڵأ��޷�����......\n\n");
this_player()->set_temp("block_command",1);
call_out("recover",40,this_player());
this_player()->add("hit_points",-(int)this_player()->query("hit_points")/3);
return 1;
}
int clean_up() { return 0; }