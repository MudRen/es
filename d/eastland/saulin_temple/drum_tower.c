#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short("��¥");
       set_long( @C_LONG_DESC
������ʯ������һ����¥��¥������һ��޹�(drum)�����Ĺ�����
�Ĺ�����ʾ��������ж�����ʷ�ˣ��ڹ�����һ֧�Ĵ���ƽʱֻ���ڰ����
��ר������(hit) ����ģ��������ν�� "ĺ��" ����˵��Щ�ùĵ�������
���ϳ��ڹ�\����Ϊ�޹�һ�죬������������ǿ�ȣ���Ĳ�����ͨ�����ܵ�
�˵ġ�������һ��ƫ�
C_LONG_DESC
       );
       set("light",1);
       set("item_desc",([ "drum" : @C_LONG
����һ��޹ģ����ǹ������һ���˸ߣ���������Ϲ���Ļ��������塢
��������û����ġ��������Ĺ�����涼�Ѿ������ˣ��������������Ȼ
���ֹ�����ʾ���˳�����������
C_LONG
       ]));
       set("exits",([
           "west" : SAULIN"side_temple2",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if( !str || str != "drum" )
       return notify_fail("��Ҫ��ʲ��?\n");

     if( (int)this_player()->query("force_points") < NEED_FP ) {    
       this_player()->receive_damage((int)this_player()->query("max_hp")/4);
       tell_object(this_player(), @C_LONG
  �������鳣�������������������ȥ����о���һ����������ɽ�������
  �ӹ�������ӿ�˹����������������������ķ����ѡ�
C_LONG
       );
       tell_object(this_player(),
         "( �� "+status_string()+" )\n");
     } else {
       tell_object(this_player(), @C_LONG
  �������鳣�������������������ȥ����о���һ����������ɽ�������
  �ӹ�������ӿ�˹�������Ͻ����������ֿ���
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
    return 1;
}       
