#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Hell Minister", "冥界修道士" );
        set("id",({"minister","hell minister","hell"}));
        set_short( "冥界修道士" );
        set_long(@LONG
冥界修道士是为维持冥界的和平，在地狱中接受黑帝斯的训练的法
师，在地狱严苛的训练之下，他们不但精通数种威力相当大的法术，同
时更具有远比法师强壮的肉体，手中的幽冥权杖，则是冥帝所赐，做为
修道士们的信物
LONG
        );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "int", 25 );
        set_skill( "dodge" , 100 );
        set_skill( "parry" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 700 );
        set ("hit_points", 700 );
        set_natural_weapon( 35 , 15 , 30 );
        set_natural_armor( 40 , 30 );
        set( "aim_difficulty",
        ([ "critical":30,"weakest":70,"ganglion":10 ]) );
        set ("special_defense",
        ([ "monk": 20, "scholar": 20, "evil": 100 , "divine": -20,
                "fire": 80, "electric":60, "cold":60, "energy": 30]) );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1);
        set( "killer", 1);
	wield_weapon(WEAPON"wand");
        equip_armor(ARMOR"cloth03.c");
        equip_armor(ARMOR"god_4.c");
        set( "tactic_func","my_tactic");

}

int my_tactic()
{
        int dam;
        object victim;
        if (!victim = query_attacker()) return 0;
        if ( random(25) < 21) return 0;

        tell_object(victim,@C_LONG

修道士对你阴恻恻的一笑，举起手中的权杖，喃喃的念了几句咒语

突然你感到黑帝斯正冷冷的看著你，双手一挥，一阵黑雾将你团团围住，
这股似邪非邪，似善非善，忽冷忽热的感觉让你受到了前所未有的伤害

C_LONG
);
        tell_room(environment(victim),@LONG

修道士大喊：尊贵崇高的冥帝，我的主人....协助我打败我的敌人吧！

只见上空突然笼罩著一大片乌云，黑帝斯的声音幽幽的从四面八方传了过来：
谁胆敢与我的使者为敌....给你五秒钟 Quit 不然....你会後悔的

你感到一股无比强烈的杀气肆虐在整个战场上，修道士的敌人受到了超乎想像
的伤害。

LONG
);
        dam = 5 + random(5);
        victim->receive_special_damage( "evil", dam);
        victim->receive_special_damage( "divine", dam);
        victim->receive_special_damage( "fire", dam);
        victim->receive_special_damage( "cold", dam);
        victim->receive_special_damage( "electric", dam);
        victim->receive_special_damage( "energy", dam);
        victim->receive_special_damage( "acid", dam);
        victim->receive_damage(dam);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/minister",1);
        ::die();
        return;
}
