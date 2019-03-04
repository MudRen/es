#include <mudlib.h>

inherit ARMOR;
mapping origin_sp;
void create()
{
	set_name( "wonderful hat", "����˼���ñ��" );
	add( "id", ({ "hat", }) );
	set_short( "a wonderful hat", "����˼���ñ��");
	set_long( @LONG
	This hat is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	����ħ��ʿ���޵۴��Ĳ���˼��֮ñ�ӣ���Ҫ����ֻ������ͨ�Ĳ�֯�ɣ�������ӵ��
����������֮��ķ���������˵���ֿܵ�����ħ����
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 15 );
	set( "type", "head" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "none": 6 ]) );
	set( "extra_skills", ([ "runes": 10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 3000, "silver" }) );
	set( "equip_func", "heal_sp" );
	set( "unequip_func", "stop_heal_sp" );
	set( "extra_look", 
	     "$N������ñ����ɢ����һ�ɲ���˼��Ĺ�â��\n" );
}

void heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, 
      "һ�ɲ���˼��Ĺ�â��ñ��ɢ������Χ���㡣\n" );
    origin_sp=player->query("conditions/_heal_sp");
    player->set("conditions/_heal_sp" , ({ 10, 5 }));
}

void stop_heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, 
      "�����ϲ���˼��Ĺ�â��ʧ�ˡ�\n" );
    player->set("conditions/_heal_sp", origin_sp);
}
