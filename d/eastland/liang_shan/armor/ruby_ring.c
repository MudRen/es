#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("ruby ring","�챦ʯ��ָ");
        add("id",({"ring"}) );
         set_short( "ruby ring","�챦ʯ��ָ");
	set_long(
"�����ɺ챦ʯ���Ƴɵ��������ӣ�������ֵ����....\n"
);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","element");
	set( "defense_bonus", 5 );
	set( "equip_func","equip_ring");
	set( "value", ({ 880, "silver" }) );
        set("extra_skills",(["dodge":-5,"unarmed":-10]));
}
void equip_ring()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"����һֻ�����ĺ챦ʯ��ָ....\n"
    ,({holder}));
    tell_object(holder,
    "��С����������Ϻ챦ʯ��ָ....\n");
return ;
}