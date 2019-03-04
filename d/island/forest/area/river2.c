#include "../tsunami.h"
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����������С���п���ֻ����һ�ж���Ǭ������������ͷ���ϵĹ�͸��
���ˣ�ӳ�ڵ��µ�ɳ���ϣ�ʹ�˸о��ݷ�����춳���֮�⣬����һ��δ��̽
����������һ�㡣�����������ľ��أ����㼸������Ҫ�����ˣ��ס�������
���ֵֹ�Ү��
LONG
            );
    set("exits",([
        "up":AREA"upriver2",
        "north":AREA"river"]) );

    set_outside("island");
    set("underwater",1);
    set("objects",([
        "turtle":TMOB"turtle" ]) );
    reset();
}

void init()
{
UNDERWATER->apply_effect(this_player(),3,2);
add_action("do_search","search");
}

int do_search(string str)
{
   if( !str || str != "here"){
   write("��Ҫ��ʲ����??\n");
   return 1;
   }
   write(@ALONG
   ��������������֮��ʱ��ͻȻһ�����н�����һ��С����...
ALONG
        );   
   tell_room( environment(this_player()),
   this_player()->query("c_name")+
     "�����﷭����ȥ��ͻȻ�䣬����һ����Ͱ����С�����а���������...\n",
     this_player() );
   this_player()->move_player("/d/island/8,8.island","SNEAK");
   tell_room( environment(this_player() ),
   "������ϴ��ʱ��ͻȻ"+this_player()->query("c_name")+"����������˳���...\n"
   ,this_player() );
 return 1;
}    