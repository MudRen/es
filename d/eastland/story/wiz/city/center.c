#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("������");
	set_long( @LONG
��վ��֮���ǡ����̹��������ĵ㣬�������������ģ����������ϻ��������
��֮���������ڳ����ĵ��Ա߻�����һ���߰˳ߵĽ��������ǵ�������
������һ����֪���Ǿ����м�֮�֣����򲻻��������ϸ�塣�����ǻʹ��������
�߱����ǳ�������Ҫ�ĵ�·��������Ϊʲ�ᣬ�������������·�Ի���һ���ɫ��
ʯ(stone)��
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"ne1",
            "west" : SCITY"nw1",
           "north" : SCITY"palace1"
        ]) );
        set( "c_item_desc", ([
                  "stone" : @LONG
һ����������ɫ�Ĵ�ʯ��ʯͷ��д����ɫ����ڰ�����˼�������б�����(touch)�ĺۼ���
LONG
        ]) );
	reset();
}
void init()
{
   add_action("do_worship","worship");
   add_action("do_touch","touch");
}
int do_touch(string arg)
{
   if ( !arg || arg !="stone" )
       return notify_fail("��Ҫ��ʲ�ᶫ����\n");
   write("\n��������һ������ɫ�Ĵ�ʯ��ֻ��һ����ɫ�Ĺ��߹ᴩ������ӣ�\n\n\n");
   this_player()->move_player("/d/deathland/city/c1",({
       "%s�����ӱ�һ����ɫ�Ĺ��߹ᴩ��\n",
       "%s����һ����ɫ����������.\n"}),"");
   write("\n�ںڹ�֮�ᣬ�㱻�����˺ڰ���½��\n");
   return 1;
}
int do_worship()
{
    tell_object(this_player(),
       "��˫�ֺ�ʲ�����ڵ���������ϵ�Ĥ�ݣ�ϣ�������ܹ�����ơ�\n");
    this_player()->save_me();
       "/adm/daemons/backup"->user_backup(this_player());
    return 1;
}