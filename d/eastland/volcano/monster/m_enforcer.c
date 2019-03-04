#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The middle_temple enforcer", "����ִ��" );
	add( "id", ({ "enforcer" }) );
	set_short( "����ִ��" );
	set_long(
                "һλ�������ִ�¡�\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 17 );
        set_perm_stat( "dex", 17 );
        set_perm_stat( "int", 22 );
        set_perm_stat( "pie", 25 );
	set( "wealth/gold", 16 );
        set( "hit_points", 210);
        set( "max_hp", 210);
        set("natural_armor_class",35);
        set("natural_defense_bonus",20);
        set_natural_weapon(10,2,5);
        wield_weapon(OWEAPON"whip3");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "god" : "@@ask_god",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\nִ��˵���� ! ��Ҳ���������������𣬼�������ĺ������еĴ�˵����ģ�\n"
         "��ȥ�Ұɡ�����������Ǽٵģ��Ͱ��������Ļ��������߷�ɡ�\n\n"
     ); 
}

void ask_god(object who)
{
  tell_object(who,
     "\n�������������������ǻ��񣬻����ƹ�������ɽ��ÿ���л�ɽ����ʱ�����ǻ���\n�������ˣ��������Ǳ����������ϣ������ҪǨŭ����ǡ�\n\n"
  );
}
