
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(11);
        set_name( "Bodyguard", "��Ժ��ʦ" );
        add ("id",({ "bodyguard","guard"}));
        set_short( "��Ժ��ʦ");
        set("unit","λ");
        set_long(
@C_LONG
����һ�����ļ�Ϊ���µ������ˣ�����ϸϸ��Ƭ�����Ϸ���������͹⣬
�����Ǵ�ܸ��֣�����ʮ�ָ���ְ��û����ò�Ҫ������
C_LONG
);
        set ("gender", "male");
        set ("race", "lizardman");
        set_perm_stat( "str", 20 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed", 75 );
        set( "max_hp", 400 );
        set( "hit_points", 400 );
        set( "wealth/gold",20);
        set( "natural_armor_class", 45 );
        set( "natural_defense_bonus", 20 );
        set( "natural_weapon_class1", 19 );
        set( "natural_min_damage1", 5 );
        set( "natural_max_damage1", 10 );
        set( "special_defense", ([ "all": 30,"none":20]) );
        set( "alignment", 500 );
#include <replace_mob.h>
}
