#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("Ϫ��ɳ��");
	set_long( @LONG
������֮����һϪ�����ɳ����ǰ��Ϫˮ�����Ӷ����������϶�ȥ����Ϫ����
������ǧ��ߵ�ɽ�壬����в������������ߣ����������Խ��������Ϫ���Ϸ�
��ʱ������ɹ���ʱ��ͣ��ɽ���Ͽ�֦�����Ը߸裬��������������ɽ���໥����
���������п��ʯ����ʯһ����³�������̦��������Щ��Ǭ�˵�����������Ǹ�
���̾���ĵط���
LONG
	);
        set("light",1);
	set( "exits", ([ 
          "southwest" : SAREA"bottom2"
        ]) );
        set("objects", ([
             "fisher" : SMOB"fisher1"
        ]) );
	reset();
}
void init()
{
    add_action("do_up","����纣��������ϵϵ��æ��");
}
int do_up(string arg)
{
    object player;
    player=this_player();
    write("\n��Ȼ������ŵ��¹���һ�����㴵����ȥ�����������Ҷ���\n\n");
    tell_room(this_object(),sprintf(
      "\n��Ȼһ�����ķ��%s���ϴ�ȥ��\n",player->query("c_name")),player);
    player->move_player(SAREA"stone1","SNEAK");
    return 1;
}
