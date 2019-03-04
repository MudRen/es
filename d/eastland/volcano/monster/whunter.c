#include "../oldcat.h" 

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(14);
	set_name( "The hunter", "��������ͷ��" );
	add( "id", ({ "hunter" }) );
	set_short( "��������ͷ��" );
	set_long(
          "����һ���������ˣ������ҵ�ÿ����ݻ�������ļ�Ʒ��\n"
	);
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 20 );
	set_skill( "axe",80);
	set_skill( "parry", 80 );
	set_skill( "dodge", 80 );
	
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", -500 );
	set( "natural_armor_class", 45 );
	set( "natural_defense_bonus", 30 );
	set( "wealth/gold", 15 );
        set( "killer",1);
        set( "chat_chance", 15);
        set( "att_chat_output",({
             "��ͷ������˵���Բ��������������ͷҲ�ǲ����ѵġ�\n"
             }) );
//        set( "moving",1);
//        set( "speed", 30);

        ob1=new(OWEAPON"waxe");
        ob1->move( this_object() );
	wield_weapon(ob1);
        equip_armor(OARMOR"mail3");
}
