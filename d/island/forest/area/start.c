#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@LONG
���Ǹ�ʮ���峺Ǭ���ĺ�(lake)�����ֽС�������������ΪֻҪ������
Щ����ߣ�����ͻ���˸�����Ĺ�â�����ϳ����������������ں����ϣ�ӳ
��΢������������ż����������ʹ���Ŀ���������磬����ʹ��������鳩
�죻��������ʱ���ԣ�Ļ�������������裬����Ӿ��Ҳ�޷���
LONG
            );
    set("light",1);
    set_outside("island");
    set("water_source",1);
    set("exits",([
        "west":"/d/island/11,7.island"]) );
    set("item_desc",([
         "lake":@LAKE
һ������������С���������룺�������ӾӦ����һ�����ܣ�
LAKE
             ]) );
    set("objects",(["indi":TMOB"indi"]) );
    reset();
}
void init()
{
    add_action("do_swim","swim");
}
int do_swim(string str)
{
    write(@ALONG
    ���Ȳ�������һ���Ӿ�������ͷ����ͻȻ������������һ��Ī������Ĺֵط�...
ALONG
         );      
      tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "���·���û�Ѿ���������ˬ��ȥ�ˣ��ж�û�ã�����ɶ��Ʀ��..\n"
      , this_player() );
      this_player()->move_player(AREA"in","SNEAK");
     tell_room( environment(this_player()),
     "�㿴��"+this_player()->query("c_name")+"�������һ��Ҳ������Ʈ�˹���...\n"
     ,this_player() );   
   return 1;
}                      
                      
    
