#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "god wand", "������" );
    add( "id", ({ "wand" }) );
    set_short( "������" );
    set_long(@LONG
һ�滭�������������ӣ����������ģ��е����̿��
LONG
    );
    set( "unit", "��" );
    set( "type", "wand" );
    set( "weapon_class", 23 );
    set( "min_damage", 7 );
    set( "max_damage", 22 );
    set( "power_on", 1);
    set( "weight", 40 );
    set( "value", ({ 1500, "silver" }) );
    set( "hit_func", "wand_hit" );
    set( "charge_left", 10 );
    set( "max_charge", 10 );
    set( "special_damage_type", "evil" );
    set( "special_damage", 10 );
    set( "special_c_msg", set_color(" ����һ����ɫ��Ũ��! ","HIM") );
}
