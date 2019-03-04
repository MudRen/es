// googol.c
// A patrolling and talking monster.
// He uses the say command so that he may speak in different languages.
// If you just want a monster to speak in Common, you can use the
// chat_chance property instead, which is easier and faster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>

inherit MONSTER;

void create ()
{
	object bo;

	::create();
	set_level(19);
	set_name( "hong chigon", "���߹�" );
	add ("id", ({ "hong", "chigon", "beggar chief", "beggar", "chief" }) );
	set_short( "Hong Chigon the Beggar Chief", "��ָ��ؤ���߹�" );
	set_long(
		"Hong Chigon is the legendary beggar and he is the leader of the\n"
		"beggar's gang. He likes eating very much and is always looking for\n"
		"delicious foods.\n",
		"���߹��Ǵ�˵��ؤ����ϰ��������ǳ�ϲ���ԣ������ܱ�����Ѱ�Ҹ�����\n"
		"����ζ��\n"
	);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );

	set ("max_hp", 500);
	set ("hit_points", 500);

	set ("wealth", ([ "gold":300 ]) );

	set ("gender", "male");

	set ("natural_armor_class", 40);
	set ("natural_weapon_class1", 40);
	set ("natural_min_damage1", 25);
	set ("natural_max_damage1", 60);

	set ("chat_chance", 40);
	set ("att_chat_output", ({
		"Chigon cackles and says: Let's me teach you how to fight, Kids!\n",
		"���߹�������Ц: С�����ӣ����Ͻл���ָ���㼸�֡�\n",
		"Chigon turns around while striking you with palms.\n",
		"���߹�ת�������㣬���������Ƴ���˵��: ���нС�������β����\n",
		"Chigon mumbers: Hmmm... should I beat you so easily?\n",
		"���߹�������: ��... Ҫ����һ�вŲ���ʧ�ִ�����... ��\n",
		"Chigon smiles and says: Good, it would be a match if you fight with my children.\n",
		"���߹�˵��: ��������������Ϳ��Ժ���ͽ�������������档\n",
		"Chigon get a chicken from his bag, chews a piece of it and put the chicken in bag again.\n",
		"���߹����ݲ��ȵشӻ���ȡ��һ�����ȣ�ҧ��һ���ַŻػ��С�\n"
	}) );

	bo = new("/obj/example/weapon/bo");
	bo->move(this_object());
	wield_weapon(bo);
}

