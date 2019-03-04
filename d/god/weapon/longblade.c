#include <mudlib.h>

inherit WEAPON;

string C_NAME="ħ��֮��";

void create()
{
        seteuid(getuid());
        set_name( "sword of demogorgod", C_NAME );
        add( "id", ({ "sword", "demogorgod" }) );
        set_short( "����֮(����)����" );
        set_long(
       "��������ɱ��а�������,�������������ɵ�һ�ѽ���\n"
       "�������ر�Ĺ�������\n"
        );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weapon_class", 10 );
        set( "min_damage", 35 );
        set( "max_damage", 65 );
        set( "extra_skills", ([ "parry":20 ]) );
        set( "weight", 180 );
        set( "hit_func", "weapon_hit" );
        set( "value", ({ 7200, "silver" }) );
}

int weapon_hit(object victim, int damage)
{
        if( (string)victim->query("race")!="dragon" ) return 0;
        victim->receive_special_damage( "magic", damage );

        return damage;
}
