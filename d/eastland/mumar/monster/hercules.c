#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(15);
        set_name( "Hercules", "力士" );
        add ("id", ({ "hercules", "yang" }) );
        set_short( "力士" );
        set_long(
    "牧马关的力士们在战争中通常是担任前锋的职务，往往造成敌人的重大损失。\n");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 10 );
        set_perm_stat( "int", 15 );
        set ("wealth", ([ "gold": 50 ]) );
        set_natural_weapon(10,14,17);
        set_natural_armor(75,35);
    set ("weight", 300);
    set( "pursuing",1 );
    set ("chat_chance", 10);
    set( "att_chat_output", ({
        "力士边挥舞大□头边狂笑著：看我把你打成肉饼！\n"
        }));
    set("c_death_msg","%s 庞大的身躯晃了一晃，噗通一声倒在你身上，差点把你压昏..\n");
    set_skill("blunt",60);
    set_skill("parry",70);
    wield_weapon(OBJS"hammer1");
}
