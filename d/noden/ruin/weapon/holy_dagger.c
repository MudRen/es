// holy_dagger.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("holy_dagger", "神圣匕首");
    set_short("神圣匕首");
    add("id", ({ "dagger" }));
    set_long(@C_LONG
这是一把雕琢精美的匕首，匕身散发著圣洁的白色光芒。虽然这把匕首看起来
并不锋利，但是当你握著它时，你隐隐约约感受到一股神奇的力量。
C_LONG
    );
    set("unit", "把");
    set("type", "dagger");
    set("weapon_class", 40);
    set("min_damage", 25);
    set("max_damage", 40);
    set("weight", 30);
    set("hit_func", "holy_power");
}

int holy_power(object victim, int damage)
{
    object me;
    int my_ali, vic_ali, dam, my_sp;

    if (!victim) return 0;
    if (!(me = environment(this_object())) || !living(me)) return 0;
    if (random(10) > 3) return 0;
    
    my_sp = (int)me->query("spell_points");
    if (my_sp < 10) return 0;

    my_ali = (int)me->query("alignment");
    vic_ali = (int)victim->query("alignment");
    
    if (my_ali < vic_ali && my_ali < 400)
    {
        tell_object(me, "神圣匕首上发出一道波动，却伤到了你自己。\n\n");
        me->receive_special_damage("divine", random(40));
        victim->set("last_attacker", me);
        return 0;
    }
    else 
    {
	dam = (my_ali - vic_ali) / 1000;
     	if (dam >= 50) dam = 50;
	me->set("spell_points", my_sp - 10);
        victim->receive_special_damage("divine", dam);
        victim->set("last_attacker", me);
	tell_object(me, set_color("\n你的神圣匕首发出一道波动攻向敌人！\n\n", "HIY"));
        tell_room(environment(me), set_color("\n"+me->query("c_name")+"的神圣匕首发出一道波动攻向敌人！\n\n", "HIY"), me);

        return dam;
    }
    return 0;
} 
