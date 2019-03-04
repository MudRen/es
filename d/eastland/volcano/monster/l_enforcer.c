#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The left_temple enforcer", "���ִ��" );
	add( "id", ({ "enforcer" }) );
	set_short( "���ִ��" );
	set_long(
                "һλ������ִ�£���������������ļ������顣\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "int", 23 );
	set( "wealth/gold", 15 );
        set( "hit_points", 200);
        set( "max_hp", 200);
        set("natural_armor_class",35);
        set("natural_defense_bonus",15);
        set_natural_weapon(10,3,7);
        wield_weapon(OWEAPON"whip1");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "tree": "@@ask_tree",
             "fruit": "@@ask_tree",
             "chilin":"@@ask_chilin",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\nִ��˵���Ҿ��ĺ������еĴ�˵Ӧ������ģ���Ҫ�ҵ����Ƿǳ����ѡ�\n"
       "����������˵���������ı��������������ǿ������������ʦ������Ҳ��\n"
       "�Կ��⣬��˵ֻҪ�����õ����ı��У��������ٻָ�����ǿ���������\n\n"
     ); 
}

void ask_tree(object who)
{
  tell_object(who,
    "\nִ��˵���ˡ���������������Ҫ�п鲼̯��(spread)�����������\n\n");
}

void ask_chilin(object who)
{
  tell_object(who,
    "\nִ��˵���ഫ�������ǻ��������֮һ��ȫ��ð�����������Ҳ���³��һ�\n\n");
}
