#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ƫ��");
    set_long(@LONG
�����ƫ�Ҳ�ǰ���ϼ�������޹��������˴���ֻ���������㣬�Ĵ�
�����һ����Ⱦ�����������㾪�ȵ��ǣ��ڴ˴��������κε�Ů����������
�����������ס�����֮��Ķ����ֱ����������ң���԰���ϼ�����к�
�ֵ�ӡ���أ�
LONG
             );
    set("exits",([
        "south":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "aiga":TMOB"aiga"]) );
    reset();
}

void init()
{
    add_action("prevent_quit","quit");
}

int prevent_quit()
{
   object who;
   who = this_player();
   
   if( !who->query_temp("luoky_killer") ) return 0; 
    tell_object(who,"����ϼ��Ц����ɱ���˼ҵĳ�����ӵ���ȥ��\n");
    tell_room( environment(who),
    who->query("c_name")+" ��Ȼ��η��Ǳ�ӣ���������ϼ��ֹ�ˣ���\n"
    ,who );
    return 1;
}
