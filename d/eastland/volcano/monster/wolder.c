#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The older", "����������" );
	add( "id", ({ "older" }) );
	set_short( "����������" );
	set_long(
          "һ������������ˣ��������ƣ�������������50��ǰ��ɽ�������Ҵ���֮һ��\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -10 );
	set_perm_stat( "str", 15 );
	set( "wealth/gold", 5 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",40);
        set("natural_defense_bonus",15);
        set_natural_weapon(15,5,5);

        ob1=new(OWEAPON"wstick");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );

        equip_armor(OARMOR"boots1");
        set("inquiry", ([
            "square":"@@ask_square",
            "rose": "@@ask_rose",
            "volcano":"@@ask_volcano",
            "fire" : "@@ask_fire",
            ]) );
}

void ask_square(object who)
{
  tell_object(who,
   "\n����˵����֪���ǲ��������ۻ軨�����������㳡�м�ľ޴�Ӫ��(fire)����Ϩ\n"
   "�𣬴��Ҵ���ȥ��ʱ�����ָֻ�ԭ״�ˣ�������������û����Ը�������ҵĻ���\n\n"
   );
   return;
}

void ask_fire(object who)
{
  tell_object(who,
   "\n����˵����Ӫ��ʵ�ں���֣�����������ʧ����\n"
  );
  return;
}

void ask_rose (object who)
{
  tell_object(who,
    "����˵�����Ǹ������ڷ����ˣ��һ�����ã���û��˵������õ��Ĵ��ڡ�\n"
  );
  return;
}

void ask_volcano(object who)
{
  tell_object(who,
     "����˵��������ɽʵ�������ǰ�����Ķ��Σ�50��ǰ�ı��������ǰ����弸��ȫ���ˣ�ֻ�������˻���������������һ���÷����������ɽ���������⣬ʵ���ǿ̲��ݻ���\n"
  );
  return;
}
