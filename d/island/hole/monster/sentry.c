#include <../hole.h>

inherit ENEMY ;
void create()
{
        ::create();
        set_level(16);
        set_name( "Lizardman Sentry", "蜥蜴人哨兵" );
        add("id",({"lizardman","guard","sentry"}) );
        set_short( "蜥蜴人哨兵" );
        set_long(@LONG
你看到的是一位身材魁梧的蜥蜴人，它的职责就是防
止敌人潜入。它现正和同伴商量著下哨後要去哪儿玩乐。
LONG
        );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "alignment",400 );
        set( "max_hp",550 );
        set( "hit_points",550 );
        set( "wealth/silver",150 );
        set( "special_defense",([ "none": 25,"all": 22 ]) );
        set( "aim_difficulty",(["critical":30,"vascular":80]) );
        set_perm_stat( "str",20 );
        set_perm_stat( "dex",20 );
        set_natural_armor( 40,25 );
        set_natural_weapon( 20,13,14 );
        set_skill( "parry",90 );
        set_skill( "longblade",90 );
        set_skill( "thrusting",90 );
        equip_armor( HARMOR"plate4" );
        equip_armor( HARMOR"arms2" );
        wield_weapon( HWEAPON"spear1" );
}

