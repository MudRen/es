#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("guardian of auction Co.", "拍卖公司守卫");
        add ("id", ({ "guard","guardian","troll" }) );
	set_short( "拍卖公司守卫");
	set_long(@LONG
你看到一个庞大的怪汉，不要怀疑，他就是传说中的怪力巨人。拍卖公司特地
使用强大的魔法从魔界把他召唤出来，为拍卖公司守护庞大的财富，头脑简单的他
十分尽责，所以你千万不要打歪主意，因为他只要随手一巴掌，就可能把你打扁。
LONG
	);
	set( "unit", "个" );
	set( "alignment", -600 );
	set_perm_stat( "str",30);
	set_perm_stat( "dex", 24 );
        set_perm_stat( "int", 22 );
        set_perm_stat( "con", 30 );
	set_perm_stat( "pie",21);
        set_perm_stat( "kar", 18);
	set( "max_hp",1200);
	set( "hit_points",1200);
	set_natural_weapon( 100, 40,80 );
        set_natural_armor( 70, 50 );

}

void die()
{
	object killer ;
	int money ;
	killer = this_object()->query("last_attacker");
	money = environment(this_object())->query("money");
        if (killer)
	killer->add("wealth/silver",money);
	environment(this_object())->delete("money");
	::die(1);
	tell_object(killer,"打死守卫後，你赶快搜括保险箱里的钱 ....\n"
		"你得到了 "+money+" 枚银币。\n");
}
