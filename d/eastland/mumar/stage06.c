#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("����¥");
  set_long( @CLong
���߽���һ�伫Ϊ�����ķ��䣬���ܵ�ǽ�Ϲ�����������ʯ�ĵ���������������
һ��������ͷ�Ļ�Ƥ��һ�Ŵ�������η����ڱ��ߵĴ�ǰ���ΰ��������һֻ������
����Զ�����߸ߵ��컨���Ϲ���һյ�����ƣ������������䡣�����и����ӣ�����ͨ
��¥�¡�
CLong
);
set("light",1);
set( "pre_exit_func", ([ "east" : "check_button" ]) );
set("exits",([
               "east":MUMAR"stage07",
               "down":MUMAR"stage02"
             ]));
set("objects",([
               "general":MOB"lee"]) );
reset();
}
int check_button()
{
  if( wizardp(this_player()) || this_player()->query_temp("give_button") ) return 0;
  else {
        tell_object(this_player(),
                    "��֪������ʲ�ᱣȫ����ƣ�����������߲���ȥ��\n" );
        return 1;
       }
}
