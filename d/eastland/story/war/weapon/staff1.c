#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "wind wand", "ħ����" );
    add( "id", ({ "wand" }) );
    set_short( "ħ����" );
    set_long(@LONG
һ�Ѱ����Ƴɵ��������Ͽ̽����ƶ䣬ǰ�˷ֿ����档
LONG
    );
    set( "unit", "��" );
    setup_weapon("wand",30,10,20 );
    set( "power_on", 1);
    set( "weight", 50 );
    set( "value", ({ 2000, "silver" }) );
    set( "hit_func", "wand_hit" );
    set( "charge_left", 10 );
    set( "max_charge", 10 );
    set( "special_damage_type", "evil" );
    set( "special_damage", 30 );
    set( "special_c_msg", " ������ɫ����! ");
}
