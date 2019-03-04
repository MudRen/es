#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The right_temple enforcer", "�ҵ�ִ��" );
	add( "id", ({ "enforcer" }) );
	set_short( "�ҵ�ִ��" );
	set_long(
                "һλ����ҵ�ִ�£�������������ҵ�ļ������顣\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 16 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "int", 21 );
        set_perm_stat( "pie", 25 );
	set( "wealth/gold", 14 );
        set( "hit_points", 180);
        set( "max_hp", 180);
        set("natural_armor_class",35);
        set("natural_defense_bonus",20);
        set_natural_weapon(10,2,5);
        wield_weapon(OWEAPON"whip2");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "fruit":"@@ask_tree",
             "tree": "@@ask_tree",
             "dragon":"@@ask_dragon",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n�Ҿ��ĺ������еĴ�˵�Ǽٵģ���Ҫȥ�����������Ļ���\n"
         "��ֻ��Ҫ��ȥ�������ˡ�\n\n"
     ); 
}

void ask_tree(object who)
{
  tell_object(who,
    "\n�����˲ι�����ҪС�����(hit)���ӡ�\n\n" );
}

void ask_dragon(object who)
{
  tell_object(who,
    "\nִ��˵���ഫ�����ǻ��������֮һ��ȫ��ð�����������Ҳ���³��һ�\n\n"  );
}
