#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("green hood", "����ץ��ͷ��");
        add( "id", ({ "hood" }) );
        set_short("����ץ��ͷ��");
        set_long(
                "����һ�������͵�ͷ������㲻����Ļ����⵹�ǷǷ��ķ��ߣ� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "fire":4, "cold":-5, "mental":2 ]) );
        set( "weight", 50 );
		set( "equip_func","equip_hood");
        set( "value", ({ 466, "gold" }) );
        set( "extra_look", "$N����һ�������͵�ͷ������ʮ�ֿɰ���\n" );

}
void equip_hood()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"С�����������һ�������͵�ͷ��.......\n"
    ,({holder}));
    tell_object(holder,
    "��С������������ⶥ�����͵�ͷ��.........\n");
	return ;
}


