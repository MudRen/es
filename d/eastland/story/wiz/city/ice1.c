#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ԭ");
	set_long( @LONG
��ĿԶ����Ƭ�������ģ�����������ͨ�徧Ө�������κγ�ɳ�ı�ԭ������Ƭ
�Ử����ĵ����ϣ�����������಻֪����������ÿ���ߡ��˱�����߶��һ��
�������ϣ�ȫ������һƬ���£�����ȴ����֦��Ҷ��������Ρ������Ա߻��и�
ʮ�߿��С����(pool)��
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice1",
            "west" : SCITY"ice1",
        ]) );
	set("c_item_desc", ([
	   "pool":"һ��ֱ��Լʮ�ߵ�С���ӣ���ˮ����ɫ�������Ӿ����������Ǳ��(dive pool)ȥ������\n" 
        ]) );
	reset();
}
void init()
{
    add_action("do_dive","dive");
}
int do_dive(string arg)
{
   string name;
   object player;
   if ( !arg || arg !="pool" ) return 0;
   player=this_player();
   name=this_player()->query("c_name");
   write("��˫����ǰһ�죬����һ�ţ�����С���Ӷ�ȥ��\n");
   tell_room(environment(player),sprintf(
     "%s��С����Ǳ��ȥ�£�\n",name),player);
   tell_object(player,@LONG


��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����
��Ȼ���ص���һ��ǿ������а������ĵط�����



LONG   
   );
   player->move_player(SAREA"rest1.c","SNEAK");
   tell_object(player,"��������ʱ�Ѿ���һ����ͤ���ˡ�\n\n");
   tell_room(environment(player),sprintf("%s���Աߵ�����������������\n",name),player);   
   return 1;
}
