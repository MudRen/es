#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "Ʈѩ����" );
	set_long(
		"����һ���¸ǺõĹ����ң���Ŀǰ�յ�����û���κζ�����Ҳ�����һ��\n"
	"Ҫ���ľ����������һЩ������\n"
	);
        set( "light",1 );
	set( "exits", ([
		"adv" : "/d/adventurer/hall/adv_guild",
		"scholar" : "/d/scholar/scholar/scholar_guild",
	]) );
        set( "objects", ([
          "icy" : "/u/s/snow/obj/icy.c",
          "shoe" : "/u/s/snow/obj/shoe.c",
          "dress" : "/u/s/snow/obj/dress.c"
        ]) );
        reset();
}
void init()
{
        add_action("to_rest","rest");
}
int to_rest()
{
	object me;
	me = this_player();
	me->set("max_hp",3000);
	me->set("hit_points",3000);
	me->set("spell_points",320);
	me->set("force_points",3000);
	me->set("talk_points",600);
        write ("һ�ɺ���Χ������,����û����泩.\n");
	return 1;
}                                        
