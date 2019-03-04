
#include <../iigima.h>
inherit MONSTER;

void create()
{
       ::create();
       set_level(19);
       set_name("dynasty ghost","古代幻灵");
       set_short("dynasty ghost","古代幻灵");
       add("id",({"ghost"}));
       set_long(@C_LONG
这是由司娜可女神封印的上古朝代的幽灵，虽然它看来
并不是凶狠的恶灵，但邪恶的司娜可女神在冥界中仍招
唤它过来，意图占领这神宫。
C_LONG
       set("unit","位");
       set_natural_weapon(45,26,47);
       set_natural_armor(22,25,14);
       set("max_hp",1080);
       set("hit_points",1080);
       set("alignment",-1600);
       set("tactic","assault");
       set_perm_stat("str",25);
       set_perm_stat("dex",25);
       set_skill("block",100);
       set_skill("dodge",100);
       set("unbleeding",1);
       set("tactic_func","my_tactic");
       set("special_defense",(["all":45,"none":20]));
}
int my_tactic
{
       object *victim;
       if(!(victim=query_attackers())) return 0;
       if(random(20)<5){
        tell_room(environment(this_object()),
        "幻灵口中念著一阵咒语，千万只恶魔冲向你的四周，狂乱飞舞！！\n"
        ,this_object());
        victim->receive_special_damage("mental",140);
        return 1;
        } else return 0;
}


