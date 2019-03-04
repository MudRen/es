#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("guardian of auction Co.", "������˾����");
        add ("id", ({ "guard","guardian","troll" }) );
	set_short( "������˾����");
	set_long(@LONG
�㿴��һ���Ӵ�Ĺֺ�����Ҫ���ɣ������Ǵ�˵�еĹ������ˡ�������˾�ص�
ʹ��ǿ���ħ����ħ������ٻ�������Ϊ������˾�ػ��Ӵ�ĲƸ���ͷ�Լ򵥵���
ʮ�־���������ǧ��Ҫ�������⣬��Ϊ��ֻҪ����һ���ƣ��Ϳ��ܰ����⡣
LONG
	);
	set( "unit", "��" );
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
	tell_object(killer,"���������ᣬ��Ͽ��������������Ǯ ....\n"
		"��õ��� "+money+" ö���ҡ�\n");
}
