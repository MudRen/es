
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("����");
        set_long( @C_LONG_DESCRIPTION
�����������ں�������Ϸ��ĵ�����˴��ֽ���һƬ�����͵ĵ��ݣ���һ����
������Ĵ�ҡҷ�������˿�����һƬ��Ţ�����ڴ˴���Ҫ���С�����⽦��������š
�������������һ��С��(hole)��
C_LONG_DESCRIPTION
        );
        set("layuter_hole",1);
    set("item_desc",([
        "hole":"����һ��������խ�Ķ�Ѩ���ɴ���ȥ����һƬ��ڣ��������\��������ȥ(climb down)��\n"]));
        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield"
           ]) );
        set("objects",([
            "fox1":"/d/eastland/haiwei/monster/fox",
            "fox2":"/d/eastland/haiwei/monster/fox"]));   
        reset();
}

void init()
{
 add_action("do_climb","climb");   
}

int do_climb(string arg)
{
  if (!arg || arg!="down") return 0;
     write("�ⶴ̫�������޷�����ȥ����Ҳ��\��ҪĳЩ��Ʒ���п�������ȥ��\n");
     return 1;
    
 }
