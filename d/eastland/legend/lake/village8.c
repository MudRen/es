#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����");
        set_long( 
@LONG
�۵�һ�������ˮ��̽ͷ������������һ������������գ����ͱ������ˡ�
����ס�ֱߵ��ҿ飬���������Χ��̽��һ�£������������ס���ˮ����������
�Ϲ⻬Ǭ����������̦���������ǿڳ���ʹ�õ�ˮ�������븽����Ӧ�������̣�Ҳ
���о����ͻ��������ü���˳�����������
LONG);
    set( "light",1);
    ::reset();
}

void init()
{
   add_action("do_shout","shout");
}

int do_shout(string arg)
{
    
   object player,env;
  
   if ( !arg || arg!="����" && arg!="help" ) return 0;
   player=this_player();
   env=find_object_or_load(LAKE"village9");
   call_out("help1",3,player,env);
   return 0;
}
void help1(object player,object env)
{     
   if ( !present("woman",env) ) {
     tell_object(player,"�����һ�����\n��Ȼ����û���ˣ���������꡻��\n");
     return ;
   }
   tell_object(player,"\n����������һ��ɧ����������һ��������������\n");
   player->move_player(LAKE"village9","SNEAK");
   tell_object(player,"������һ����������������������\n");
   tell_room(env,@LONG

��������ϴ�·�������ɣ����˵����ô��ร�û�����ܵ�����~!@#$%^&*....��

LONG);
   return;
}     


