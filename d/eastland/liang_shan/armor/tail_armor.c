#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ancient tail armor", "���β��" );
	add( "id", ({ "tail","armor" }) );
	set_short( "���β��" );
	set_long(
		"����һ�׷�����ֹ����β�ף��ഫ�ǹ�ʱ��ȴ�ս�Ƶ�ʱ����\n"
	        "��������ӵ�зǷ��ķ��������ƺ�����������Ϊ��֪��������\n"
	);
	set( "unit", "��" );
	set( "type", "tail" );
        set("material","leather");
	set( "weight", 120 );
	set("armor_class",10);
	set("defense_block",4);
	set( "value", ({ 320, "gold" }) );
}
int stop_equip()
{
   object holder;	
	holder=this_player();
       if ((int)holder->query("alignment")>-1200)
        {
        tell_room( environment(holder), 
         holder->query("c_cap_name")+"��Ҫ�������β�ף���β��ͻȻ�������������ܿ��ơ�\n"
		, ({holder}) );
        tell_object( holder,
         "����Ҫ�������β�ף���β�׷���ǿ���а����ʹ���޷���Ը��\n");
		return 1;
	}
        return 0;
}
