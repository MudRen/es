#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short( "��¥" );
       set_long( @C_LONG_DESC
������ʯ������һ����¥��¥������һ�ھ���(bell)����ڵ��������ɫ��ͭ��
��ʹ��������Եú����쳣������������һ����ľ��ƽʱֻ���賿����ר����ײ(hit)
����ӣ�������ν�� "����" �����������Ҳ�������ض����ź��ټ�ɮ�ڻ򴫵ݽ���
��Ϣ����˵ײ�ӵ�ɮ�˶�������һ�����ֵ��Σ���Ϊ����һ�죬������������ǿ�ȣ�
����ʹһ����ͨ��ŻѪ������������һ��ƫ�
C_LONG_DESC
               );
       set("light",1);
       set("item_desc",([
         "bell" : @C_LONG
    ����һ�ڴ�ͭ�ӣ����ı�����������\�����������Ļ��ƣ������õ���������
���ֽ�����������ɵģ��������ı��涼�Ѿ������ˣ���Ȼ��������Ҳ�����ˣ�
��������Ȼ�����ĺܺá���Ȼ���˳�������������
C_LONG
]));

       set("exits",([
         "east" : SAULIN"side_temple1",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if(!str || str != "bell")
       return notify_fail("��Ҫ��ʲ��?\n" );
     if( (int)this_player()->query("force_points") < NEED_FP ) {
       this_player()->receive_damage((int)this_player()->query("max_hp")/8);
       tell_object( this_player(), @C_LONG
  �������ľ������������ײ����ȥ����о���һ����������ɽ�������
  ���ӿ�����ӿ�˹����������������������ķ����ѡ�
C_LONG
);
       tell_object(this_player(),
         "( ��" + status_string() + " )\n");
     } else {
       tell_object( this_player(), @C_LONG
  �������ľ������������ײx2����ȥ����о���һ����������ɽ�������
  ���ӿ�����ӿ�˹�������Ͻ����������ֿ���
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
        this_player()->set_explore("eastland#28");
     return 1;
}       
