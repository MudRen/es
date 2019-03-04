#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ׯ��·");
	set_long(@LONG
��������һ���������ס�Ĵ�ׯ��·�ϣ�������һ���ŵ�С�ݣ��ϱ��Ǵ���Ⱥ
����������������һ��Ƭ������Եø������������֣�����һ����Ȼ��ס����
�����ڵ�·����ֲ����������������ϵĹ�ʵƽʱ��������ʳ�����ʵ�е�Һ֭
Ҳ������������Ϊ����ˮԴ����������ûʲ���Ŀռ䣬С�����Ƕ����ܵ���
��Ĳ�ԭȥ���棬�������Ƕ�����Ϊ�ǣ��������ﱻ�˷��֡������������������
��ס�ĵط���������·��������ʯ�񣬵���������崫˵�е�Ӣ�ۣ����������Ĥ
��(worship)��������������������������������ʯ���Ի��п��ɫ��ʯ(stone)��

LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house3",
                "west" : SAREA"house4",
               "north" : SAREA"village1",
        ]) );
        set("objects", ([
               "stone" : SITEM"statue1"
        ]) );
        set( "c_item_desc", ([
               "stone" : @LONG
һ����������ɫ�Ĵ�ʯ����ɫ������������ƽ�����磬�����б�����(touch)�ĺۼ���
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
   write("\n��������һ������ɫ�Ĵ�ʯ��ֻ��һ����ɫ�Ĺ��߹ᴩ������ӣ�\n\n\n
");
   this_player()->move_player("/d/eastland/8,5.east",({
      "%s�����ӱ�һ����ɫ�Ĺ��߹ᴩ��\n",
      "%s����һ����ɫ����������.\n"}),"");
   write("\n�ڻƹ�֮�ᣬ�㱻�����˶�����½��\n");
   return 1;
}
int do_worship()
{
     tell_object(this_player(),
        "��˫�ֺ�ʲ������������Ĥ�ݣ���о���ȫ���ƺ�������������\n");
     this_player()->save_me();
        "/adm/daemons/backup"->user_backup(this_player());
     return 1;
}