#include "iigima.h"
inherit ROOM;

void create()
{
        ::create();
        set_short( "pool","Сˮ��");
        set_long(
@C_LONG
����һ���徻��Сˮ�أ��ڰ������û��ˮ�������е�����ˮ��
���������Сˮ������Ӧ����Ϊ��������Ȼӿ���Ŀ�Ȫ�����ֲ��ܵ�
��������ĸ��ţ������峺��Ȫˮ�����㲻���ڿ���������
C_LONG
        );

        set( "light",0 );
        set( "water_source",1 );
        set( "exits", ([
                     "east":  DROW"r15",
        ]) );
        set("objects", ([
                "child#1": DRO"child",
                "child#2": DRO"child",
        ]) );
        set("c_item_desc",(["pool":
@C_LONG
�����Ȫ�Ǻڰ�������Ψһˮ�����㿴�˿��������������ӡ�
C_LONG
           ]));         
        reset();
}
void init()
{
   add_action("do_drink","drink");
}

int do_drink(string str)
{
   if( !str || str!="water")
      return notify_fail("�����ʲ�᣿\n");

   tell_object( this_player(),"���Ȳ������ĸϿ�ȼ���������Ȫˮ....\n");
   tell_room(environment(this_player()),
    
this_player()->query("c_name")+"����С���Ƶ�ſ��ȥ��ˮ��\n"
   ,this_player() );

   if( (string)this_player()->query("class") != "knight")
       return notify_fail("����˼��ڣ��о��ڽ�����ùζ������\n");
   tell_object(this_player(),"����Ȫˮ�ᣬ��ľ����ƺ�����˲��٣�\n");
   tell_room( environment(this_player() ),
      "������ˮ���������ϵĻҳ���վ��������\n"
      ,this_player() );
   return 1;
}
