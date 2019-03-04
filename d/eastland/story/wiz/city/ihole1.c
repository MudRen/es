#include "../../story.h"

inherit ROOM;
int mob=1;
int ice_wall=0;
void create()
{
        ::create();
	set_short("��Ѩ");
	set_long( @LONG
����վ��һ�����ܶ��Ǳ��ڵĶ�Ѩ������������ı�ԭ��Ҫ��ů�Ķ��ˡ�
�ϱߵĶ����Ǵ�С��һ�ı�׶���е�ҵ�����������γɱ��������еı������м��
��춵��������±��������е�����ʯ���鶴��ֻ������ʯ���ʻ��ɱ�˪���ڵ���
����Щ����ֵֹĹκۣ��ǹκۺ����Ƕ�����㼣��
LONG
	);
        set("pre_exit_func", ([
          "north":"can_pass"
        ]) );
        set( "exits", ([ 
           "out" : SCITY"ice2",
        ]) );
	reset();
}
int can_pass()
{
    object guard;
    if ( !guard=present("ice-monster",this_object()) ) return 0;
    write("ѩɽ������ס�����ȥ·��\n");
    return 1;
}
void init()
{
   add_action("do_search","search");
   add_action("do_hack","hack");
}
int do_hack(string arg)
{
   object ice;
   if (!ice_wall) return 0;
   if( !arg || arg!="ice_wall" )
      return notify_fail( "����Ҫ����ʲ�ᶫ��?\n" );
   if ( this_player()->query_perm_stat("str") < 15 )
      return notify_fail( "�������������������\n" );
   write("��Ѿ���ţ����֮��������һ��..\n");
   tell_room(this_object(),"\n��Ȼ�����Ʊ���ĳ�һֻ����������\n\n");
   mob=0;
   ice_wall=0;
   set("exits/north",SCITY"ihole2");
   ice=new(SWMOB"icewoman1");
   ice->move(this_object());
   return 1;
}
int do_search(string arg)
{
   if ( !mob ) return 0;
   write("�㷢����һ�����(ice_wall)�������������޷���������(hack ice_wall)�ġ�\n");   
   ice_wall=1;
   return 1;
}
void reset()
{
   object ob,atk;
   int i;
   mob=1;
   ice_wall=0;
   delete("exits/north");
   if ( atk=present("ice-monster",this_object()) ) atk->remove();
   ::reset();
}
