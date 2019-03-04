#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "dog beater bo", "�򹷰�" );
	add ("id", ({ "dog beater", "bo" }) );
	set_short( "Dog Beater Bo", "�򹷰�" );
	set_long(
		"This is the legendary weapon of beggar's gang. It looks thin\n"
		"and light, but it is certainly a powerful weapon if you have\n"
		"learned skill of dog beating.\n",
		"����ؤ������֮���򹷰����������������͵�һ��ϸ�������ȴ��\n"
		"����ʮ��ǿ���������������л���ѧ���򹷰����Ļ���\n"
	);
	set_c_verbs( ({
		"%s��ǰһ̽������%s", "����%s��б��%s", "%s����%s",
		"���%s��ȴͻȻһ������%s" 
	}) );
	set ("type", "thrusting");
	set ("weapon_class", 40);
	set ("min_damage", 13);
	set ("max_damage", 40);
	set ("weight", 30);
	set ("value", ({ 400, "gold" }) );
}
