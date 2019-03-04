#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "martialist", "����ʦ��" );
	add( "id", ({ "entertainer" }) );
	set_short("����ʦ��" );
	set_long(
		"��λ����ʦ��ԭ����һ���ھֵ���ʦ����Ϊ�ھֵ������Գ�����\n"
		"����ά��������ȭ�Ź�\������һ���Ǻ������ġ�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "dodge", 90 );
	set( "wealth/gold", 20 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 55, 25 );
	set( "natural_weapon_class2", 30 );
	set( "natural_min_damage2", 13 );
	set( "natural_max_damage2", 25 );
	set( "chat_chance", 20 );
	set( "chat_output", ({
		"����ʦ��˵��: С�ܲ���ѧǳ�����λ���Ķ��ָ�̡�\n",
		"����ʦ������һ����Ծ���Լ�Ĺ��߸ߣ�Ȼ��ƮȻ��ء�\n",
		"����ʦ������һ�ס��ڻ�ȭ����ȭ����磬���νý���\n",
		"����ʦ����������ש�飬Ȼ����һ����ָ��ש�鰴�£�����ʯשһ�����ѡ�\n"
	}) );
#include <replace_mob.h>
}
