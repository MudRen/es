#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(6);
	ob->set_name("lizardman hunter", "����������");
	ob->add( "id", ({ "hunter" }) );
   ob->set_short("����������");
	ob->set_long(
		"���������ȫ����������������ɫ��Ƭ��������������һ����ͷ���Ե����ӡ�\n"
	);
	ob->set( "unit", "��" );
	ob->set_perm_stat("str", 10);
	ob->set_perm_stat("dex", 10);
	ob->set( "time_to_heal", 4 );
	ob->set_skill( "thrusting", 40 );
	ob->set_skill( "dodge", 40 );
	ob->set( "race", "lizardman" );
	ob->set( "gender", "male" );
	ob->set( "wealth/silver", 60 );
	ob->set( "natural_armor_class", 40 );
	ob->set( "alignment", -500 );

	ob->wield_weapon("/d/noden/item/stone_spear");

	ob->equip_armor("/d/noden/item/snake_skin");
}
